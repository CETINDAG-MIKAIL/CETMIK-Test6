#include <math.h>
#include <iostream>
#include <cstring>
#include "Dimension.h"

// Initialisation des constantes statiques
Dimension Dimension::VGA = Dimension(640, 480);
Dimension Dimension::HD = Dimension(1280, 720);
Dimension Dimension::FULL_HD = Dimension(1920, 1080);

// Constructeur avec paramètres
Dimension::Dimension(int largeur, int hauteur) : largeur(largeur), hauteur(hauteur) {}

// Fonction pour afficher les dimensions
void Dimension::Affiche()  const{
    std::cout << "Largeur : " << largeur << " Hauteur : " << hauteur << std::endl;
}
void Dimension::setLargeur(int l){largeur=l;}
void Dimension::setHauteur(int h){hauteur=h;}