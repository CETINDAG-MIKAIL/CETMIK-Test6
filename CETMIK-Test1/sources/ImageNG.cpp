#include <math.h>
#include <iostream>
#include <cstring>
#include "ImageNG.h"

ImageNG::ImageNG() {                    
    nom = NULL;
    setNom("default");
    setId(1);
}

ImageNG::ImageNG(int i, const char* n) {
    nom=NULL;
    setNom(n);
    setId(i);
}

ImageNG::ImageNG(const ImageNG & i) {                    
    nom = NULL;
    setNom(i.nom);
    setId(i.id);
}

ImageNG::~ImageNG() {                   //destructeur
    if(nom) delete nom;
}

void ImageNG::setId(int i) {
    if (i < 0) return;
    id = i;
}

void ImageNG ::setNom(const char* n) {
    if (nom != NULL) delete nom;
    nom = new char[strlen(n) + 1];      
    strcpy(nom, n);
}



int ImageNG :: getId() const {
    return id;
}

const char* ImageNG::getNom() const {   
    return nom;                         
}


void ImageNG::Affiche() const {
    std::cout << "Id = " << getId() << ", Nom = " << getNom() << std::endl;
}