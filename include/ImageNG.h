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


//		GET

		
		static int 	getL_MAX();
		static int 	getH_MAX(); 	

		int 		getId()const;
		char* 		getNom() const ;
		Dimension 	getDimension() const;

	    int 		getLuminance()const;
	    int 		getMinimum()const;
	    int 		getMaximum()const;
	    float		getContraste()const;
		int 		getPixel(int ,int )const;



// 		SET


		void setL_MAX(int);
		void setH_MAX(int);

		void setId(int);
		void setNom(const char *);
		void setDimension(Dimension);

		void 	setBackground(int );
	    void 	setPixel(int , int, int );
//		CONSTRUCTEUR 


		~ImageNG();
		ImageNG();
		ImageNG(int,const char *);
		ImageNG(int,const char *, Dimension);
		ImageNG(const ImageNG& );
	    ImageNG(const char* fichier);


//		OPERATEUR 

	    
	    ImageNG& operator=(const ImageNG&);

	    ImageNG operator+(int);
	    ImageNG operator-(int);


		ImageNG operator++();
		ImageNG operator++(int);


		ImageNG operator--();
		ImageNG operator--(int);

	    ImageNG operator-(const ImageNG&);

		bool operator==(const ImageNG& );
		bool operator>(const ImageNG& );
		bool operator<(const ImageNG& );

//		FRIEND

	    friend ImageNG operator+(int, ImageNG);
	    friend ImageNG operator-(int, ImageNG);
		friend std::ostream& operator<<(std::ostream& os, const ImageNG& i1);



		void Affiche();
		void 	Dessine();
	    void 	importFromFile(const char* fichier);
	    void 	exportToFile(const char* fichier, const char* format);
	    








	};
	#endif