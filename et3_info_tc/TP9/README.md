# pgm 1.1!

pgm est une application permettant de manipuler des fichiers .pgm avec plusieurs opérations.

On peut recevoir une aide en exécutant l'application avec l'option suivante : `--help`

Ex: `./pgm --help`

|      Opérations      |        Commandes        |                 Variables                   |
|----------------------|-------------------------|---------------------------------------------|
| Adapter le contraste | `-ac, --adapt-contrast` | `[VALUE] [FILE] (entrée) ([FILE] (sortie))` |
| Noir et blanc        | `-bw, --black-n-white`  | `[FILE] (entrée) ([FILE] (sortie))`         |
| Closing              | `-cl, --closing`        | `[FILE] (entrée) ([FILE] (sortie))`         |
| Copie                | `-cp, --copy`           | `[FILE] (entrée) ([FILE] (sortie))`         |
| Dilatation           | `-d,  --dilation`       | `[FILE] (entrée) ([FILE] (sortie))`         |
| Erosion              | `-e,  --erosion`        | `[FILE] (entrée) ([FILE] (sortie))`         |
| Histogramme          | `-h,  --histogram`      | `[FILE] (entrée) ([FILE] (sortie))`         |
| Opening              | `-o,  --opening`        | `[FILE] (entrée) ([FILE] (sortie))`         |

Par défaut les images seront stockées dans un dossier (out) à la racine de l’exécutable.
Si une sortie est précisée l'image sera stockée à la destination indiquée sous réserve de la validité de la sortie fournie.
Dans le cas où la sortie spécifiée nécessite de créer de nouveaux dossiers, ils seront créés automatiquement.

Compilation
------
Pour compiler il faut utiliser le Makefile: `make`

`make clean` supprime les .o et le binaire (ne fonctionne que sous Linux).

Le Makefile compile tout le contenu du dossier src.
Il prend en compte quel est le système d'exploitation pour changer la cible: `pgm | pgm.exe | pgm.app`

L'application est compilable sur toute plateforme: Windows, Unix (Linus, OS X (à vérifier)).

Documentation
-------
Il y a une [documentation][doxygen_doc] générée sous Doxygen dans le dossier [doxy][doxygen_path].


Ce qu'il y a à dire sur les questions
--------- 
Pour diriger le programme cela marche en ligne de commande. Il faut passer en argument ce que l'on veut faire (cf. ci-dessus).

Pour la partie image il était nécessaire de créer un constructeur et destructeur de image_t.
Un copy_image au cas où..
Pour l'histogramme il y a le constructeur, destructeur et le write.

Pour le noir et blanc, on calcul l'histogramme au préalable pour établir s comme la valeur de gris la plus représentée.
On determine en fonction de se qui est blanc ou noir.

Chaque fonction qui modifie une image le fait par paramètre et renvoie tout de même le pointeur de l'image.
Cela permet de faire des `if(!adapt-contrast(image)) { /* erreur */ }` pour détecter plus facilement les erreurs via pointeurs null.


Ce dont nous sommes fière du - au +
----------
 - La bonne compilation du code + les fonctions bonus.
 - Le Makefile qui est suffisament généralisé pour compiler tout ce qu'il y a dans src/ (hors library).
 - Ce Doxyfile + l'utilisation du Markdown pour le README.
 - L'esthétique de mon application qui a pour but d'imiter le princie des commandes sous bash.
 - La possibilité de choisir le fichier de sortie + la création de dossier dans le cas où il est inexistant.

Difficulté
-------
 
Pas de difficulté apparente.
 
Fichiers
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
[Lucas David][@lucas] : ET3 INFO

[Robin Matha][@robin]: ET3 PSO

[doxygen_doc]:doxy/html/index.html
[doxygen_path]:doxy/
[@lucas]:mailto:lucas.david@u-psud.fr
[@robin]:mailto:robin.matha@u-psud.fr

