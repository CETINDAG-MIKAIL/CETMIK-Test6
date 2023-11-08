#include <math.h>
#include <iostream>
#include <cstring>

using namespace std;
#include "ImageNG.h"
#include "MyQT.h"
//#include "Dimension.h"



///////////// constructeur par default ///////////////
ImageNG::ImageNG()
{
	setId(0);
	nom = NULL;
	setNom("default");
	setDimension(Dimension(0,0));
	for(int i=0;i<getL_MAX();i++)
	{
		for(int j=0; j<getH_MAX();j++)
		{
			matrice[i][j]=0;
		}
	}

}
/////////// constructeur d'initialisation //////////
ImageNG::ImageNG(int nombre, const char *n)
{
	setId(nombre);
	nom = NULL;
	setNom(n);	
}
/////////// constructeur d'initialisation + dimension//////////
ImageNG::ImageNG(int nombre, const char *n, Dimension d1)
{

	setId(nombre);
	nom = NULL;
	setNom(n);	
	setDimension(d1);
}
//////// constructeur de copie //////////////:
ImageNG::ImageNG(const ImageNG& p)
{

	setId(p.getId());
	nom = NULL;
	setNom(p.getNom());	
	setDimension(p.getDimension());

	for(int i=0;i<dimension.getLargeur();i++)
	{
		for(int j=0; j<dimension.getHauteur();j++)
		{
			matrice[i][j]=p.matrice[i][j];
		}
	}
	
}
ImageNG::ImageNG(const char* fichier) {
	setId(1);
	nom = NULL;
	setNom(fichier);	
    MyQT::ImportFromFile(*this, fichier);
}

ImageNG& ImageNG::operator=(const ImageNG& p)
{

    if (this == &p) {
        return *this; // Renvoyez l'objet actuel sans rien faire
    }

    setId(p.id);
    setNom(p.nom);
    setDimension(p.dimension);

    // Copiez les données de la matrice
    for (int i = 0; i < dimension.getLargeur(); i++) {
        for (int j = 0; j < dimension.getHauteur(); j++) {
            matrice[i][j] = p.matrice[i][j];
        }
    }

    return *this;
}

ImageNG ImageNG::operator+(int add)
{
	if(add > 0)
	{
		ImageNG p2(*this);
		for (int i = 0; i < dimension.getLargeur(); i++) {
	        for (int j = 0; j < dimension.getHauteur(); j++) {
	            if((p2.matrice[i][j]+add) < 255)
	            {
	            	p2.matrice[i][j]+=add;	
	            }
	            else
	            {
	            	p2.matrice[i][j]=255;	
	            }
	        }
	    }
		return p2;	
	}
	return *this;
}
ImageNG ImageNG::operator-(int add)
{
	if(add > 0)
	{
		ImageNG p2(*this);
		for (int i = 0; i < dimension.getLargeur(); i++) {
	        for (int j = 0; j < dimension.getHauteur(); j++) {
	            if((p2.matrice[i][j]-add) > 0)
	            {
	            	p2.matrice[i][j]-=add;	
	            }
	            else
	            {
	            	p2.matrice[i][j]=0;	
	            }
	        }
	    }
		return p2;	
	}
	return *this;
}
ImageNG operator+(int add,ImageNG i1)
{
	if(add > 0)
		return i1 + add;
	return i1;
	
}
ImageNG ImageNG::operator++()
{
	(*this) = (*this) + 20;
	return (*this);
}
ImageNG ImageNG::operator++(int)
{
	ImageNG i2(*this);
	(*this) = (*this) + 20;
	return i2;
}
ImageNG ImageNG::operator--()
{
	(*this) = (*this) - 20;
	return (*this);
}
ImageNG ImageNG::operator--(int)
{
	ImageNG i2(*this);
	(*this) = (*this) - 20;
	return i2;
}
ImageNG operator-(int add,ImageNG i1)
{
	if(add < 0)
		return i1 + add;
	return i1;
	
}
ImageNG ImageNG::operator-(const ImageNG& i1)
{
	ImageNG i2(*this);

	for (int i = 0; i < dimension.getLargeur(); i++) {
        for (int j = 0; j < dimension.getHauteur(); j++) {
            i2.matrice[i][j] -= i1.matrice[i][j];
            if(i2.matrice[i][j]<0)
            	i2.matrice[i][j]=0;
        }
    }
    return i2;
}
bool ImageNG::operator==(const ImageNG& d)
{
    return compI(d, "==");
}
bool ImageNG::operator<(const ImageNG& d)
{
    return compI(d, "<");
}

bool ImageNG::operator>(const ImageNG& d)
{
    return compI(d, "<");
}

bool ImageNG::compI(const ImageNG& i1, const char* op)
{
	for (int i = 0; i < dimension.getLargeur(); i++) {
        for (int j = 0; j < dimension.getHauteur(); j++) {
       
            if(strcmp(op, "==") == 0&& matrice[i][j] != i1.matrice[i][j])
            	return false;
        	else if((strcmp(op, "<") == 0 && matrice[i][j] >= i1.matrice[i][j]))
        		return false;
        	else if((strcmp(op, ">") == 0 && matrice[i][j] <= i1.matrice[i][j]))
        		return false;
        }

    }
    return true;
	
}

int ImageNG::getLuminance()const
{
	int somme=0,cpt=0;

	for (int i = 0; i < dimension.getLargeur(); i++) {
        for (int j = 0; j < dimension.getHauteur(); j++) {
            somme += matrice[i][j];
            cpt++;
        }
    }
    return somme/(int)cpt;	
}
int ImageNG::getMinimum()const
{
	int valMin=256;
	for (int i = 0; i < dimension.getLargeur(); i++) {
        for (int j = 0; j < dimension.getHauteur(); j++) {
        	if(valMin > matrice[i][j])
        	{
        		valMin = matrice[i][j];
        	}
        }
    }
    return valMin;
}
int ImageNG::getMaximum()const
{
	int valMax=0;
	for (int i = 0; i < dimension.getLargeur(); i++) {
        for (int j = 0; j < dimension.getHauteur(); j++) {
        	if(valMax < matrice[i][j])
        	{
        		valMax = matrice[i][j];
        	}
        }
    }
    return valMax;
}
float ImageNG::getContraste()const
{
	if (getMaximum() == 0 && getMinimum() == 0) 
	    return 0.0;

	float contraste=0;
	
	contraste = (getMaximum()- getMinimum()) /(float) (getMaximum() + getMinimum());

	return (float)contraste; 

}
std::ostream& operator<<(std::ostream& os,const ImageNG &i1){

	os << "Id: " << i1.id << "||" << "Nom: " << i1.nom << "||" << "Largeur: " << i1.getDimension().getLargeur() << "||" << "Hauteur: " << i1.getDimension().getHauteur()<< "||" << "Luminance: " << i1.getLuminance() << "||" << "Contraste: " << i1.getContraste() << endl;
	return os;
}





void ImageNG::Affiche()
{
	cout << "id = " << getId() << endl;
	if (nom == NULL) cout << "pointeur null" << endl;
	cout << "nom = " << getNom() << endl;
 	cout << "Dimension = " << dimension.getLargeur() << " x " << dimension.getHauteur() << endl;
}


int ImageNG::getId() const
{
	return id;
}
char* ImageNG::getNom()const
{
	return nom;
}
Dimension ImageNG::getDimension()const
{
	return dimension;
}




void ImageNG::setId(int nombre){id=nombre;}


void ImageNG::setNom(const char *n){ 

	if (nom) delete nom;
	nom = new char[strlen(n)+1];
	strcpy(nom,n);
}
void ImageNG::setDimension(Dimension d1) {

        dimension = d1;

/*
    if (d1.getLargeur() > 500 || d1.getHauteur() > 500) 
    {
        dimension = Dimension(500, 500);
    } 
    else
    {
        dimension = d1;
    }
    /*
    for (int i = 501; i < dimension.getLargeur(); i++) {
        for (int j = 501; j < dimension.getHauteur(); j++) {
            matrice[i][j] = 0;
        }
    }*/
}

ImageNG::~ImageNG()
{
	cout << "D" << endl << endl;
	if(nom) delete nom;

    for (int i = 0; i < getL_MAX(); i++) {
        for (int j = 0; j < getH_MAX(); j++) {
            matrice[i][j] = 0;
        }
    }

}
int ImageNG::getL_MAX(){return 500;};
int ImageNG::getH_MAX(){return 500;};

void ImageNG::setPixel(int x, int y, int val)
{
	matrice[x][y]=val;
}
int ImageNG::getPixel(int x,int y)const
{
	int val = matrice[x][y];
	return val;
}
void ImageNG::setBackground(int val)
{
	for(int i=0;i<getL_MAX();i++)
	{
		for(int j=0;j<getH_MAX();j++)
		{
			matrice[i][j]=val;
		}	
	}
}
void ImageNG::Dessine() {
    MyQT::ViewImage(*this);
}

void ImageNG::importFromFile(const char* fichier) {
    MyQT::ImportFromFile(*this, fichier);
}

void ImageNG::exportToFile(const char* fichier, const char* format) {
    MyQT::ExportToFile(*this, fichier, format);
}
