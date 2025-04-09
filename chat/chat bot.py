import time
import re
import PyPDF2
from flask import Flask, request, jsonify, render_template
from openai import OpenAI

app = Flask(__name__)

# Load PDF once and store its text as permanent data (System data)
def extract_text_from_pdf(pdf_path):
    text = ""
    try:
        with open(pdf_path, "rb") as file:
            reader = PyPDF2.PdfReader(file)
            for page in reader.pages:
                text += page.extract_text() + "\n"
    except Exception as e:
        print(f"Error reading PDF: {e}")
        text = "Error loading document."
    return text

# The document content is stored permanently as system content
pdf_text = extract_text_from_pdf("gg.pdf")

# OpenRouter AI client setup
client = OpenAI(
    base_url="https://openrouter.ai/api/v1",
    api_key="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"
)

# Function to extract topics from AI response
def extract_topics(response_text):
    topics = re.findall(r"::(.*?)::", response_text)  # Extract topics
    response_cleaned = re.sub(r"::.*?::", "", response_text).strip()  # Remove topics from response
    return response_cleaned, topics

# Function to query OpenRouter with retry logic
def query_openrouter(question, max_retries=5, delay=2):
    retries = 0
    while retries < max_retries:
        try:
            response = client.chat.completions.create(
                model="google/gemma-3-27b-it:free",
                messages=[
                    {"role": "system", "content": 
                        "You are a kind, objective AI that answers so much briefly and shortly about only ESI RABAT based on the provided document like it is your knowledge. "
                        "don t answer to anything that s outside the document you have"
                        "Never mention you have document.act like it is your own knowledge. "
                        "peek big topics that disscussed in your knowledge "
                        " At the end of each response, suggest 3 important from your big topics related to the question  in ::topic:: format.if there is something related else return no topics"},
                    {"role": "system", "content": f"Document Content:\n{pdf_text}"},
                    {"role": "user", "content": f"Question: {question}"}
                ]
            )
            response_text = response.choices[0].message.content.strip()
            
            # Extract topics and clean response
            response_cleaned, topics = extract_topics(response_text)

            # Ensure response is valid
            if response_cleaned:
                return response_cleaned, topics if topics else None  # Return None if no topics
            
        except Exception as e:
            print(f"Error querying OpenRouter: {e}")

        # Retry if no valid response
        time.sleep(delay)
        retries += 1

    # If no valid response after retries, return fallback message
    return "I'm having trouble responding right now. Please try again.", None

@app.route("/")
def home():
    return render_template("index.html")

@app.route("/ask", methods=["POST"])
def ask():
    user_message = request.json.get("message")
    response_text, topics = query_openrouter(user_message)
    
    # Only include topics if they exist
    response_data = {"response": response_text}
    if topics:
        response_data["topics"] = topics

    return jsonify(response_data)

if __name__ == "__main__":
    app.run(debug=True)
