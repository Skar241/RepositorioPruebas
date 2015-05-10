#include "texture.h"
#include "figuras.h"

class MacEscritorio{//definicion de la calse MacEscritorio
	public:
		CTexture t_gris;//atributos publicos
		CTexture t_escudo;
		CTexture t_manzana;
		CTexture t_display;
		CTexture t_tecla;

		CFiguras toMac;

		void Init(GLvoid);//definición de los métodos, así podremos usarlos en cada cpp que incluyamos la librería 
		void respaldo(GLuint textura);//texture.h
		void desktop(GLuint textura1);
		void prisma (GLuint textura1, GLuint textura2);
		void setMac();
		void setMacBook();
};

class MesaBlanca{
	public:
		CTexture text1;
		CTexture text2;
		CTexture text3;
		CFiguras toMesa;

		void Init();
		void tabla();
		void pata();
		void pata1();
		void setMesa();
		void setMesa1();
		void setMesaJuntas();
		void setEscritorio();
		void divisor(int op);
};
class Elementos{
	public:
		CTexture text1;
		CTexture text2;
		CTexture text3;
		CTexture text4;
		CTexture text5;
		int rotateL;
		CFiguras figLamp;
		void Init();
		void setRotateLamp(int rot);
		int getRotateLamp();
		void setLampara();
		void silla(GLuint text3,GLuint text4);
		void sillaAzul();
		void sillaBlanca();
};

class Jardineras {
	public: //atributos
		CFiguras poligono;
		CTexture text0;//pasto
		CTexture text1;//borde
		CTexture text2;//pino
		CTexture text3;//arbol
		CTexture text4;//maceta


//métodos

		void Init();
		void JardineraBase(float altura, float largo, float profundidad );
		void JardineraArbol();
		void JardineraPino();
		void Pino();
		void Arbol();
		void Maceta();
		void setJardineraArbolDer();
		void setJardineraArbolIzq();
		void setJardineraPinoDer();
		void setJardineraPinoIzq();
		void jardinerasFrontales();

};

class Torres {
	public:
		CFiguras poligono;
		CTexture Fachada;
		CTexture DoorI;
		CTexture DoorD;
		CTexture Escalera;
		CTexture bordeBase;
		CTexture Escalones;
		CTexture Concreto;
		CTexture FacInf;
		CTexture supDoor;
		CTexture Ventana;
		CTexture Pint;

	//metodos
		void Init();
		void crearTorre(float altura, float largo, float profundidad);
		void uneTorres();
		void escaleras();
		void creaEdificio();
		void parteTrasera();
		void vestibulo();
};

class Estantes{
public:
	CFiguras poligono;
	CTexture Exterior;
	CTexture Interior;
	CTexture PuertaD;
	CTexture PuertaI;
	CTexture madera;
	CTexture maderaclara;


	//metodos
	void Init();
	void creaEstante1();
	void creaEstante2();
	void creaLibrero();
};

class Oficina{
	public:
		CFiguras toFloor;
		CTexture text1;
		CTexture text2;
		CTexture text3;
		CTexture text4;
		CTexture text5;
		MesaBlanca mesBla;
		Elementos elem;
		MacEscritorio escr;
		Estantes est;
		Jardineras jar;

		int rotPuerta;
		int rotPerilla;
		
		void Init();
		void piso();
		void setOffice();
		void puerta();
		void sillasSalajuntas();
		void mesa1Godinez();
		void mesa2Godinez();
		void mesa3Godinez();
};

