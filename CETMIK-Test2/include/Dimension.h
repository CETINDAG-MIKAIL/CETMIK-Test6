#ifndef DIMENSION_H
#define DIMENSION_H


class Dimension {
private:
    int largeur;
    int hauteur;

public:
    // Constructeurs
    Dimension(int largeur, int hauteur);
    Dimension() : largeur(400), hauteur(300) {}

    // Accesseurs
    int getLargeur() const { return largeur; }
    int getHauteur() const { return hauteur; }


    void setLargeur(int Largeur);
    void setHauteur(int Hauteur);

    // Variables membres statiques
    static  Dimension VGA;
    static  Dimension HD;
    static  Dimension FULL_HD;


    void Affiche() const;
};

#endif
