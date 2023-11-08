#include <math.h>
#include <iostream>
#include <cstring>

using namespace std;
#include "Dimension.h"
#include "ImageNG.h"
//#include "MyQT.h"




///////////// constructeur par default //////////////
Dimension::Dimension()
{
	setLargeur(0);
	setHauteur(0);
}

std::ostream& operator<<(std::ostream& os, const Dimension& d1)
{
	os << d1.getLargeur()<<"x"	<< d1.getHauteur(); 
	return os;	
}

std::istream& operator>>(std::istream& is, Dimension& d1)
{
	cout << "Entrez la largeur :" << endl;
	cin >> d1.largeur;

	cout << "Entrez la hauteur :" << endl; 
	cin >> d1.hauteur;

	return is;	
}



///////////// constructeur initialisation //////////////
Dimension::Dimension(int l, int h)
{
	setLargeur(l);
	setHauteur(h);
}
/*
///////////// constructeur initialisation + DIMENSION//////////////
Dimension::Dimension(int l, int h, Dimension d1)
{
	setLargeur(l);
	setHauteur(h);
	setDimension(d1);
}
*/

///////////// constructeur copie //////////////
Dimension::Dimension(const Dimension& p)
{
	setLargeur(p.largeur);
	setHauteur(p.hauteur);
}


/////////// Destructeur ////////////////////
Dimension::~Dimension()
{
	cout << "D" << endl;
}

int Dimension::getLargeur()const{return largeur;}
int Dimension::getHauteur()const{return hauteur;}

void Dimension::setLargeur(int l){

	largeur=l;
}

void Dimension::setHauteur(int h){

	hauteur=h;
}
void Dimension::Affiche()
{
	cout << "largeur :" << getLargeur() << endl;
	cout << "hauteur :" << getHauteur() << endl;
}
Dimension Dimension::VGA{640,480};
Dimension Dimension::HD{1280,720};
Dimension Dimension::FULL_HD{1920,1080};
/*
Dimension d(Dimension::HD);
Dimension::Dimension(const Dimension& p)
*/
int Dimension::operator==(const Dimension& d)
{
    return compD(d) == 0;
}

int Dimension::operator!=(const Dimension& d)
{
    return compD(d) != 0;
}


int Dimension::compD(const Dimension& d)
{
	if((largeur == d.largeur) && (hauteur == d.hauteur))
		return 0;		
	return 1;
}



