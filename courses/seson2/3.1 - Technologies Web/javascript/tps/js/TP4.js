function VerifierNombre()
{

var max= document.getElementById('valueField').value;
var min= 1;


document.getElementById('result').innerHTML = Math.floor(Math.random() * (max - min + 1)) + min;

document.getElementById('maxValue').innerHTML = max;


}
