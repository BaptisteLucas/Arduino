#ifndef MALIBRAIRIE_H  // Evite les inclusions multiples
#define MALIBRAIRIE_H  // renommer MALIBRAIRIE avec le nom de votre librairie (conserver la syntaxe)

class MaLibrairie { // renommer MaLibrairie avec le nom de votre librairie (conserver la syntaxe)
public:
    // Constructeur
    // renommer MaLibrairie avec le nom de votre librairie (conserver la syntaxe)
    MaLibrairie();          
    
    // Méthode d'initialisation de la librairie
    bool begin();            
    
    // Exemple de méthode publique
    // renommer faireQuelqueChose et parametre selon votre besoin (paramètre est une variable d'entrée)
    // cette méthode peut être appelée depuis le programme principal (elle est publique)
    void faireQuelqueChose(int parametre);

    int lireValeur();         // getter

private:
    int _maVariable;
    bool _estInitialise;
};

#endif