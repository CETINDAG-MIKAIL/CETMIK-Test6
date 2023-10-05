/*

	le fichier qui contient uniquement les prototypes des fonctions

*/
#ifndef ImageNG_h
#define ImageNG_h

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