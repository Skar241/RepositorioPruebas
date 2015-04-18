//#include <windows.h>  //Solo para Windows
//#include <gl/gl.h>     // The GL Header File
//#include <stdio.h>
//#include <string.h>
#include "Main.h"
//#include "gl.h"

class CTexture
{
public:
	char* name;
	unsigned char*  imageData;
	int		bpp;			// Image Color Depth In Bits Per Pixel
	int		width;			// Image Width
	int		height;		    // Image Height
	unsigned int    GLindex;

	bool LoadTGA(char* filename);		// Loads A TGA File Into Memory
	bool LoadBMP(char* filename);
	void BuildGLTexture();
	void ReleaseImage();
};



class MacEscritorio{//definicion de la calse MacEscritorio
	public:
		CTexture t_gris;//atributos publicos
		CTexture t_escudo;
		CTexture t_manzana;
		CTexture t_display;

		void Init(GLvoid);//definición de los métodos, así podremos usarlos en cada cpp que incluyamos la librería 
		void respaldo(GLuint textura);//texture.h
		void desktop(GLuint textura1);
		void prisma (GLuint textura1, GLuint textura2);
		void setMac();
};
