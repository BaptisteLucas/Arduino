Template de code Arduino pour structurer des différentes fonctionnalités d'un projet.

Template.ino : programme principal. C'est lui qui se charge au démarrage et qui instancie les différentes librairies.

Chaque librairie sera codée en cpp dans le dossier Library selon selon les différents modules à intégrer au projet.
Pour chaque cpp ajouté, il faudra y associer un fichier .h qui permet de déclarer le contenu de la librairie au compilateur.

Parce qu'Arduino est un peu capricieux, il est nécessaire d'ajouter dans le fichier compile_all.cpp le chemin vers la librairie ajoutée afin que le compilateur la compile

