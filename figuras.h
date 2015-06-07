//#include <windows.h>  //Solo para Windows
//#include <GL/gl.h>     // The GL Header File
//#include <stdio.h>

//#include <math.h>
#include "Main.h"


class CFiguras
{
	public:

	float text_der;
	float text_izq;
	

	void esfera(GLfloat radio, int meridianos, int paralelos, GLuint text); //Funcíon creacion esfera
	//void cilindro(float radio, float altura, int resolucion, GLuint text);	//Funcíon creacion cilindro
	void cono(float altura, float radio, int resolucion, GLuint text);		//Funcíon creacion cono
	void prisma_anun (GLuint text, GLuint text2);							//Funcíon creacion movimiento
	void prisma (float altura, float largo, float profundidad, GLuint text);//Funcíon creacion prisma
	void prisma2 (GLuint text, GLuint text2);
	void prisma2 (GLuint text);
	void skybox(float altura, float largo, float profundidad, GLuint text);	//Funcion creacion cielo
	void prisma (GLuint textura2);
	void cilindro(float radio, float altura, int resolucion, GLuint text);
	//void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos, GLuint text );
	void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos);

		
	//**********+//fucion  para construir las jardineras
	void triangulo (float altura, float largo, float profundidad, GLuint pasto,GLuint borde);
	void prisma2t (float altura, float largo, float profundidad, GLuint pasto, GLuint borde);//Funcíon creacion prisma
	void prismaEdif (float altura, float largo, float profundidad, GLuint fachada); //Funcion creacion prisma
	void prismaEst( GLuint textura1,GLuint textura2,GLuint textura3,GLuint textura4,GLuint textura5,GLuint textura6);
	void skybox(float altura, float largo, float profundidad, GLuint horizonte, GLuint suelo);

};
