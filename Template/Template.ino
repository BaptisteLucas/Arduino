// Déclarer ici les différentes librairies utilisées dans le projet (hors arduino)
#include "Library/My_Library.h"  // chemin relatif vers la librairie à ajouter

// Définition des constantes
#define delayTime 500 //500ms

// Instanciation des objets des librairies utilisées
// Malibrairie correspond dans My_library.h à la ligne "class MaLibrairie {"
MaLibrairie maLib; // Ici on crée la variable maLib de type MaLibrairie

void setup() {
  // Initialisation de l'Arduino (entrées/sorties, communication série, etc.) et des librairies utilisées
  // pinMode(xxx, OUTPUT);
  Serial.begin(115200); // configuration du port série à 115200 bauds

  if (!maLib.begin()) { // Appel de la méthode begin() de la librairie maLib
    // Si elle retourne false, on affiche un message d'erreur et on stoppe le programme
    Serial.println("Erreur : Impossible d'initialiser MaLibrairie !");
    while (1);  // Boucle infinie en cas d'erreur
  }

}

// Definition des variables globales
// int yyy;

// Programme principal
void loop()
{
  
  maLib.faireQuelqueChose(1);  // Appel de la méthode faireQuelqueChose de la librairie maLib avec 1 comme paramètre

  Serial.println(maLib.lireValeur()); // afficher la valeur retournée par la méthode lireValeur de la librairie maLib
 
  // utilisation de delay pour temporiser le programme principal
  delay(delayTime);
}

