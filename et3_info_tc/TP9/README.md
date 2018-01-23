# pgm 1.1!

pgm est une application permettant de manipuler des fichiers .pgm avec plusieurs opérations.

On peut recevoir une aide en exécutant l'application avec l'option suivante :
`$ ./pgm --help`

|      Opérations      |        Commande         |         Variables                           |
|----------------------|-------------------------|---------------------------------------------|
| Adapter le contraste | `-ac, --adapt-contrast` | `[VALUE] [FILE] (entrée) ([FILE] (sortie))` |
| Noir et blanc        | `-bw, --black-n-white`  | `[FILE] (entrée) ([FILE] (sortie))`         |
| Closing              | `-cl, --closing`        | `[FILE] (entrée) ([FILE] (sortie))`         |
| Copie                | `-cp, --copy`           | `[FILE] (entrée) ([FILE] (sortie))`         |
| Dilatation           | `-d,  --dilation`       | `[FILE] (entrée) ([FILE] (sortie))`         |
| Erosion              | `-e,  --erosion`        | `[FILE] (entrée) ([FILE] (sortie))`         |
| Histogramme          | `-h,  --histogram`      | `[FILE] (entrée) ([FILE] (sortie))`         |
| Opening              | `-o,  --opening`        | `[FILE] (entrée) ([FILE] (sortie))`         |

Par défaut les images seront stockés dans un dossier (out/) à la racine de l’exécutable.
Si une sortie est précisé l'image sera stocké à la destination indiqué sous réserve de la validité de la sortie fourni.
Dans le cas ou la sortie spécifié nécessite de créer de nouveaux dossiers, ils seront créés automatiquement.

Compilation
------
Pour compiler la seul chose à faire est d'exécuter la commande suivante: `make`

Le Makefile compile tout le contenu du dossier src.
Il prend en compte quel est le système d'exploitation pour changer la cible: `pgm | pgm.exe | pgm.app`

L'application est compilable sur toute plateforme: Windows, Unix (Linus, OS X (à vérifier)).

Documentation
-------
Il y a une [documentation][doxygen_doc] généré sous Doxygen dans le dossier [doxy][doxygen_path].

Erreur dans les fichiers .pgm
--------
Si le fichier comporte une erreur dans la majorité des cas l'application indique que le fichier est corrompu.
Dans certain cas, l'application va indiqué à l'utilisateur qu'il va essayer tant bien que mal de "deviner" où est l'erreur dans l'image et ainsi la corrigé.

Fichier
------
Les sources et headers sont stockés dans le dossier src.
Les objects dans le dossier obj.

|    Sources    |    Headers    |      
|---------------|---------------|
| main.c        |               |
| image.c       | image.h       | 
| histogram.c   | histogram.h   | 
| utility.c     | utility.h     | 


Auteurs
-------
[Lucas David][@lucas] : ET3 Info

[Robin Matha][@robin]: ET3 PSO

[doxygen_doc]:doxy/html/index.html
[doxygen_path]:doxy/
[@lucas]:mailto:lucas.david@u-psud.fr
[@robin]:mailto:robin.matha@u-psud.fr

