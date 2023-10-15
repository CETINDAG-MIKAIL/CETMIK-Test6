#ifndef IMAGENG_H
#define IMAGENG_H

#include "Dimension.h"

class ImageNG
{
private:
    char* nom;
    int id;
    Dimension dimension;

public:
    
	ImageNG();
	ImageNG(int i, const char* n);
	ImageNG(int i, const char* n, const Dimension& d);
	ImageNG(const ImageNG & i);
	~ImageNG();
	void setId(int i); 
	void setNom(const char* n);
	int getId() const;
	const char* getNom() const ;  
	void Affiche() const;
    const Dimension& getDimension() const;
    void setDimension(const Dimension& d);
 	 
 	const L_MAX;
	const H_MAX; 
    static int matrice[L_MAX][H_MAX];

    void setPixel(int x,int y, int val);
    void getPixel(x, y);
    void setBackground(int val);
};

#endif
