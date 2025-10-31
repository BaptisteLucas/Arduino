// =============================================
// My_library.cpp - Implémentation de la librairie
// =============================================
#include "My_library.h" // Inclure le fichier d'en-tête de la librairie


// Constructeur
// renommer MaLibrairie avec le nom de votre librairie défini dans My_library.h
// remplacer _maVariable par d'éventuelles variables qui doivent communiquer avec le programme principal (conserver la syntaxe)
// _maVariable(0) initialise la variable à 0
MaLibrairie::MaLibrairie() : _maVariable(0), _estInitialise(false) {
    // constructeur
}

// Méthode d'initialisation de la librairie
bool MaLibrairie::begin() {
    //par exemple initialisation de capteurs, communication, etc.
    
    //si tout est ok, on met _estInitialise à true
    _estInitialise = true;
    return _estInitialise;
}

// Exemple de méthode publique
// renommer faireQuelqueChose et parametre selon votre besoin (paramètre est une variable d'entrée)
// cette méthode peut être appelée depuis le programme principal (elle est publique)
void MaLibrairie::faireQuelqueChose(int parametre) {
    _maVariable += parametre;
}

// Exemple de getter
// Permet de lire la valeur de _maVariable depuis le programme principal à tout moment
int MaLibrairie::lireValeur() {
    return _maVariable;
}

