# *robot-simu* - Simulateur d'un robot

## Introdution

Simulation d'un robot du type WifiBot que l'on peut déplacer sur une carte
virtuelle.

## Fonctionnalités

Plusieurs fonctionnalités sont prévus - les actionneurs et capteurs de la
première version restent simples et de nouvelles possibilités pourongt être
ajoutés par la suite.

### Actionneurs

Déplacement du robot à l'aide de moteurs DC.

### Capteurs

- Capteurs Odométrique
- Capteurs Infrarouge

### Interface

La partie pilotage du robot pourra se faire par connection TCP/IP mais il pourra
égualement être instancier en C++ (et en python).
Il est prévu de développer une interface graphique pour la partie serveur (le
robot) en utilisant la bibliothèque Qt.
Le serveur (robot) pourra néanmoins être compilé sans autres dépendances que la
bibliothèque standard c/c++.

## Êtat actuel du projet

Aucune fonctionnalitée de développée actuellement

## TODO
- [] API robot simple
- [] Modélisation moteur DC et déplacement
