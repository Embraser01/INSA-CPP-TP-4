# Analyse de Log Apache

## Presentation
  Ce programme analyse un fichier log d'un serveur Apache afin d'en sortir un top 10 des pages les plus visitées ou encore un graph.
  Auteurs :
*    BOURVON Tristan
*    FERNANDES Marc-Antoine

## Mise en ligne

### Dépendance

-  GraphViz (pour la génération de la photo du graph)


### Téléchargement et installation des dépendances

Installer GraphViz
```bash
sudo apt-get install graphviz
```

### Compilation

```bash
make
```

### Utilisation

```bash
./app.out [-e] [-g fichier_graphe] [-t heure] fichier_log
```

-   -g fichier_graphe : demande la production d’un fichier GraphViz correspondant au graphe analysé.
-   -e : exclut tous les documents image, css ou javascript.
-   -t heure : ne prend en compte que les hits entre heure et heure+1 (exclu).
-   fichier_log : fichier Apache log à lire et à analyser.

### Génération du Graph

```bash
dot -Tpng -o graph.png graph.dot
```