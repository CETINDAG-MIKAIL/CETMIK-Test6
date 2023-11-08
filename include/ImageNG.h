	#ifndef IMAGENG_H
	#define IMAGENG_H
//#include <iostream>
	#include "Dimension.h"

	class ImageNG
	{
		private : 

			int id;
			char* nom;
			Dimension dimension;
			int matrice[500][500];
			bool compI(const ImageNG& , const char* );


		public :

		bool operator==(const ImageNG& );
		bool operator>(const ImageNG& );
		bool operator<(const ImageNG& );

		static int getL_MAX();
		static int getH_MAX(); 	

		void setL_MAX(int);
		void setH_MAX(int);

		int getId()const;
		char* getNom() const ;
		Dimension getDimension() const;


		void setId(int);
		void setNom(const char *);
		void setDimension(Dimension);


		void Affiche();

		~ImageNG();
		ImageNG();
		ImageNG(int,const char *);
		ImageNG(int,const char *, Dimension);
		ImageNG(const ImageNG& );
	    ImageNG(const char* fichier);
	    int getLuminance()const;
	    int getMinimum()const;
	    int getMaximum()const;
	    float getContraste()const;



	    ImageNG& operator=(const ImageNG&);
	    ImageNG operator+(int);
	    ImageNG operator-(int);

	    ImageNG operator-(const ImageNG&);


		ImageNG operator++();
		ImageNG operator++(int);


		ImageNG operator--();
		ImageNG operator--(int);


	    //friend ImageNG operator+( ImageNG , int);
	    friend ImageNG operator+(int, ImageNG);
	    friend ImageNG operator-(int, ImageNG);




		void 	Dessine();
	    void 	importFromFile(const char* fichier);
	    void 	exportToFile(const char* fichier, const char* format);
	    void setBackground(int );
	    void setPixel(int , int, int );
	    int getPixel(int ,int )const;

		friend std::ostream& operator<<(std::ostream& os, const ImageNG& i1);







	};
	#endif