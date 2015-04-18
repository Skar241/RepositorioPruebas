#include "texture.h"
#include "figuras.h"

class MacEscritorio{//definicion de la calse MacEscritorio
	public:
		CTexture t_gris;//atributos publicos
		CTexture t_escudo;
		CTexture t_manzana;
		CTexture t_display;

		void Init(GLvoid);//definici�n de los m�todos, as� podremos usarlos en cada cpp que incluyamos la librer�a 
		void respaldo(GLuint textura);//texture.h
		void desktop(GLuint textura1);
		void prisma (GLuint textura1, GLuint textura2);
		void setMac();
};

class MesaBlanca{
	public:
		CTexture text1;
		CTexture text2;
		CFiguras toMesa;

		void Init();
		void tabla();
		void pata();
		void setMesa();
};