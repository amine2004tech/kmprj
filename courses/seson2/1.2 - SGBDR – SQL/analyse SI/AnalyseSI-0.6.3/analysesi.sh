#! /bin/sh
#
# Script de lancement d'AnalyseSI
# Dreux Loic / Jousse Vincent (c) 2005
#

ANALYSE_JAR="lib/analysesi-0.6.3.jar"
CONFFILE="~/.analyse/variables.conf"

# Prise en compte du jar eventuellement passe en param
if [ $# -gt 0 ] 
    then
    ANALYSE_JAR=$1
fi

JAVA_PATH=`which java`
JAVA_FOUND=$?

# Chargement des valeurs du fichier de conf
if [ -f $CONFFILE ]
    then
    . $CONFFILE
    JAVA_FOUND=0
fi

# On verifie si le path JAVA a ete trouve dans le fichier de conf ou avec which
if [ $JAVA_FOUND -ne 0 ]
    then
    echo "Java non trouve..."
    echo "Veuillez saisir le chemin de l'executable java :"
    read JAVA_PATH
    if ! [ -x $JAVA_PATH ]
	then
	echo "Attention, l'executable java que vous avez fourni n'est pas valide, verifiez bien le chemin."
    fi

    # Creation du repertoire pour la conf
    if ! [ -d ~/.analyse ]
	then
	echo "Creation d'un repertoire .analyse dans votre repertoire personnel."
	echo
	mkdir -p ~/.analyse
    fi
    echo "JAVA_PATH="$JAVA_PATH > $CONFFILE
fi


echo "Lancement d'AnalyseSI ..."

$JAVA_PATH -jar $ANALYSE_JAR