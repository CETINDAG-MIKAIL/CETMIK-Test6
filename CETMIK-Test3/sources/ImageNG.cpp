#include "ImageNG.h"
#include <iostream>
#include <cstring>

ImageNG::ImageNG() : nom(nullptr), id(0) {
    setNom("default");
    setDimension(Dimension());
}

ImageNG::ImageNG(int i, const char* n) : nom(nullptr), id(i) {
    setNom(n);
    setDimension(Dimension());
}

ImageNG::ImageNG(int i, const char* n, const Dimension& d) : nom(nullptr), id(i), dimension(d) {
    setNom(n);
}

ImageNG::ImageNG(const ImageNG& i) : nom(nullptr), id(i.id), dimension(i.dimension) {
    setNom(i.nom);
}

ImageNG::~ImageNG() {
    if (nom) delete[] nom;
}

void ImageNG::setId(int i) {
    if (i >= 0) {
        id = i;
    }
}

void ImageNG::setNom(const char* n) {
    if (n != nullptr) {
        if (nom != nullptr) {
            delete[] nom;
            nom = nullptr;
        }
        nom = new char[strlen(n) + 1];
        strcpy(nom, n);
    }
}

int ImageNG::getId() const {
    return id;
}

const char* ImageNG::getNom() const {
    return nom;
}

const Dimension& ImageNG::getDimension() const {
    return dimension;
}

void ImageNG::Affiche() const {
    std::cout << "Id = " << getId() << ", Nom = " << (getNom() ? getNom() : "N/A") << std::endl;
}

void ImageNG::setDimension(const Dimension& d) {
    dimension = d;
}

ImageNG::ImageNG(const L_MAX, const H_MAX) : L_MAX(500), H_MAX(500) {
}