/*

	le fichier qui contient uniquement les prototypes des fonctions

*/
#ifndef IMAGENG_H
#define IMAGENG_H

class ImageNG
{
	private : 

	char *nom;
	int id;

	public :

	ImageNG();
	ImageNG(int i, const char* n);
	ImageNG(const ImageNG & i);
	~ImageNG();
	void setId(int i); 
	void setNom(const char* n);
	int getId() const;
	const char* getNom() const ;  
	void Affiche() const;


};
#endif