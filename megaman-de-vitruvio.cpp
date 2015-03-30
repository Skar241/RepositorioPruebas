/*******************************************************************************
* Tarea #3 Dibujo
* Escrito y compilado en Visual studio 2013 
* 22/03/2015
*
* Díaz Ramírez Oscar Antonio
* Rosales Peréz Iván
*
* Grupo: 4
********************************************************************************/

//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>
#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;


void InitGL()     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);				// Blanco de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}


///// entre más grande le des el valor en grosor más delgado queda el circulo
void circulo(int vertices,float grosor){
	float ang=(360/vertices);
	ang=ang*(3.141592654/180);
	int n=2;
	int i;
	//glLineWidth(5.0);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	for(i=0;i<vertices;i++){
			glBegin(GL_POLYGON);
				glVertex3f(cos(float(i*ang)),sin(float(i*ang)),-0.3);
				glVertex3f(cos(float((i+1)*ang)),sin(float((i+1)*ang)),-0.3);
				glVertex3f(grosor*cos(float((i+1)*ang)),grosor*sin(float((i+1)*ang)),-0.3);
				glVertex3f(grosor*cos(float(i*ang)),grosor*sin(float(i*ang)),-0.3);
			glEnd();
	}
}


void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	//glTranslatef(0,0,2.0);
	//glPointSize(10.0);
	glLineWidth(5.0);
	//glBegin(GL_POINTS);
	//glBegin(GL_LINE_STRIP);
	
	//Contornos 
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-13.0, -8.0, -0.2);
		glVertex3f(18.0, -8.0, -0.2);
		glVertex3f(18.0, -3.0, -0.2);
		glVertex3f(-13.0, -3.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(18.0, -3.0, -0.2);
		glVertex3f(25.0, -3.0, -0.2);
		glVertex3f(25.0, 4.0, -0.2);
		glVertex3f(18.0, 4.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-13.0, 4.0, -0.2);
		glVertex3f(18.0, 4.0, -0.2);
		glVertex3f(18.0, 10.0, -0.2);
		glVertex3f(-13.0, 10.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-19.0, -3.0, -0.2);
		glVertex3f(-13.0, -3.0, -0.2);
		glVertex3f(-13.0, 4.0, -0.2);
		glVertex3f(-19.0, 4.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-30.0, 4.0, -0.2);
		glVertex3f(-19.0, 4.0, -0.2);
		glVertex3f(-19.0, 10.0, -0.2);
		glVertex3f(-24.0, 10.0, -0.2);
		glVertex3f(-24.0, 22.0, -0.2);
		glVertex3f(-30.0, 22.0, -0.2);
	glEnd();
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-43.0, 4.0, -0.2);
		glVertex3f(-30.0, 4.0, -0.2);
		glVertex3f(-30.0, 10.0, -0.2);
		glVertex3f(-37.0, 10.0, -0.2);
		glVertex3f(-37.0, 16.0, -0.2);
		glVertex3f(-43.0, 16.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-50.0, 16.0, -0.2);
		glVertex3f(-43.0, 16.0, -0.2);
		glVertex3f(-43.0, 23.0, -0.2);
		glVertex3f(-50.0, 23.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-55.0, 23.0, -0.2);
		glVertex3f(-50.0, 23.0, -0.2);
		glVertex3f(-50.0, 29.0, -0.2);
		glVertex3f(-55.0, 29.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-61.0, 29.0, -0.2);
		glVertex3f(-55.0, 29.0, -0.2);
		glVertex3f(-55.0, 35.0, -0.2);
		glVertex3f(-61.0, 35.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-67.0, 35.0, -0.2);
		glVertex3f(-61.0, 35.0, -0.2);
		glVertex3f(-61.0, 41.0, -0.2);
		glVertex3f(-67.0, 41.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-73.0, 41.0, -0.2);
		glVertex3f(-67.0, 41.0, -0.2);
		glVertex3f(-67.0, 54.0, -0.2);
		glVertex3f(-73.0, 54.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-67.0, 54.0, -0.2);
		glVertex3f(-61.0, 54.0, -0.2);
		glVertex3f(-61.0, 59.0, -0.2);
		glVertex3f(-67.0, 59.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-61.0, 59.0, -0.2);
		glVertex3f(-49.0, 59.0, -0.2);
		glVertex3f(-49.0, 65.0, -0.2);
		glVertex3f(-61.0, 65.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-49.0, 54.0, -0.2);
		glVertex3f(-42.0, 54.0, -0.2);
		glVertex3f(-42.0, 59.0, -0.2);
		glVertex3f(-49.0, 59.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-49.0, 35.0, -0.2);
		glVertex3f(-43.0, 35.0, -0.2);
		glVertex3f(-43.0, 47.0, -0.2);
		glVertex3f(-49.0, 47.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-43.0, 41.0, -0.2);
		glVertex3f(-37.0, 41.0, -0.2);
		glVertex3f(-37.0, 54.0, -0.2);
		glVertex3f(-43.0, 54.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-37.0, 22.0, -0.2);
		glVertex3f(-30.0, 22.0, -0.2);
		glVertex3f(-30.0, 41.0, -0.2);
		glVertex3f(-37.0, 41.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-30.0, 41.0, -0.2);
		glVertex3f(-24.0, 41.0, -0.2);
		glVertex3f(-24.0, 53.0, -0.2);
		glVertex3f(-30.0, 53.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-24.0, 53.0, -0.2);
		glVertex3f(-18.0, 53.0, -0.2);
		glVertex3f(-18.0, 59.0, -0.2);
		glVertex3f(-24.0, 59.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-18.0, 59.0, -0.2);
		glVertex3f(-12.0, 59.0, -0.2);
		glVertex3f(-12.0, 65.0, -0.2);
		glVertex3f(-18.0, 65.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-12.0, 53.0, -0.2);
		glVertex3f(-5.0, 53.0, -0.2);
		glVertex3f(-5.0, 71.0, -0.2);
		glVertex3f(-12.0, 71.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-5.0, 47.0, -0.2);
		glVertex3f(13.0, 47.0, -0.2);
		glVertex3f(13.0, 53.0, -0.2);
		glVertex3f(-5.0, 53.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-5.0, 64.0, -0.2);
		glVertex3f(13.0, 64.0, -0.2);
		glVertex3f(13.0, 71.0, -0.2);
		glVertex3f(-5.0, 71.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(13.0, 53.0, -0.2);
		glVertex3f(20.0, 53.0, -0.2);
		glVertex3f(20.0, 71.0, -0.2);
		glVertex3f(13.0, 71.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(20.0, 59.0, -0.2);
		glVertex3f(25.0, 59.0, -0.2);
		glVertex3f(25.0, 65.0, -0.2);
		glVertex3f(20.0, 65.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(25.0, 53.0, -0.2);
		glVertex3f(31.0, 53.0, -0.2);
		glVertex3f(31.0, 59.0, -0.2);
		glVertex3f(25.0, 59.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(31.0, 40.0, -0.2);
		glVertex3f(37.0, 40.0, -0.2);
		glVertex3f(37.0, 53.0, -0.2);
		glVertex3f(31.0, 53.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(37.0, 22.0, -0.2);
		glVertex3f(43.0, 22.0, -0.2);
		glVertex3f(43.0, 40.0, -0.2);
		glVertex3f(37.0, 40.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(43.0, 40.0, -0.2);
		glVertex3f(49.0, 40.0, -0.2);
		glVertex3f(49.0, 52.0, -0.2);
		glVertex3f(43.0, 52.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(25.0, 4.0, -0.2);
		glVertex3f(31.0, 4.0, -0.2);
		glVertex3f(31.0, 10.0, -0.2);
		glVertex3f(25.0, 10.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(31.0, 4.0, -0.2);
		glVertex3f(37.0, 4.0, -0.2);
		glVertex3f(37.0, 22.0, -0.2);
		glVertex3f(31.0, 22.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(37.0, 4.0, -0.2);
		glVertex3f(49.0, 4.0, -0.2);
		glVertex3f(49.0, 10.0, -0.2);
		glVertex3f(37.0, 10.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(43.0, 10.0, -0.2);
		glVertex3f(49.0, 10.0, -0.2);
		glVertex3f(49.0, 15.0, -0.2);
		glVertex3f(43.0, 15.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(49.0, 46.0, -0.2);
		glVertex3f(55.0, 46.0, -0.2);
		glVertex3f(55.0, 58.0, -0.2);
		glVertex3f(49.0, 58.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(55.0, 58.0, -0.2);
		glVertex3f(68.0, 58.0, -0.2);
		glVertex3f(68.0, 65.0, -0.2);
		glVertex3f(55.0, 65.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(68.0, 52.0, -0.2);
		glVertex3f(74.0, 52.0, -0.2);
		glVertex3f(74.0, 58.0, -0.2);
		glVertex3f(68.0, 58.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(74.0, 40.0, -0.2);
		glVertex3f(79.0, 40.0, -0.2);
		glVertex3f(79.0, 52.0, -0.2);
		glVertex3f(74.0, 52.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(68.0, 33.0, -0.2);
		glVertex3f(74.0, 33.0, -0.2);
		glVertex3f(74.0, 40.0, -0.2);
		glVertex3f(68.0, 40.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(62.0, 27.0, -0.2);
		glVertex3f(68.0, 27.0, -0.2);
		glVertex3f(68.0, 33.0, -0.2);
		glVertex3f(62.0, 33.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(55.0, 22.0, -0.2);
		glVertex3f(62.0, 22.0, -0.2);
		glVertex3f(62.0, 27.0, -0.2);
		glVertex3f(55.0, 27.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(49.0, 15.0, -0.2);
		glVertex3f(55.0, 15.0, -0.2);
		glVertex3f(55.0, 22.0, -0.2);
		glVertex3f(49.0, 22.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(43.0, -3.0, -0.2);
		glVertex3f(60.0, -3.0, -0.2);
		glVertex3f(60.0, 4.0, -0.2);
		glVertex3f(43.0, 4.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(60.0, 4.0, -0.2);
		glVertex3f(80.0, 4.0, -0.2);
		glVertex3f(80.0, 10.0, -0.2);
		glVertex3f(60.0, 10.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(80.0, -16.0, -0.2);
		glVertex3f(85.0, -16.0, -0.2);
		glVertex3f(85.0, 4.0, -0.2);
		glVertex3f(80.0, 4.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(24.0, -21.0, -0.2);
		glVertex3f(80.0, -21.0, -0.2);
		glVertex3f(80.0, -15.0, -0.2);
		glVertex3f(24.0, -15.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(60.0, -15.0, -0.2);
		glVertex3f(67.0, -15.0, -0.2);
		glVertex3f(67.0, -3.0, -0.2);
		glVertex3f(60.0, -3.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(24.0, -58.0, -0.2);
		glVertex3f(30.0, -58.0, -0.2);
		glVertex3f(30.0, -21.0, -0.2);
		glVertex3f(24.0, -21.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(30.0, -33.0, -0.2);
		glVertex3f(36.0, -33.0, -0.2);
		glVertex3f(36.0, -27.0, -0.2);
		glVertex3f(30.0, -27.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(30.0, -64.0, -0.2);
		glVertex3f(36.0, -64.0, -0.2);
		glVertex3f(36.0, -58.0, -0.2);
		glVertex3f(30.0, -58.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(36.0, -40.0, -0.2);
		glVertex3f(42.0, -40.0, -0.2);
		glVertex3f(42.0, -33.0, -0.2);
		glVertex3f(36.0, -33.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(42.0, -52.0, -0.2);
		glVertex3f(49.0, -52.0, -0.2);
		glVertex3f(49.0, -40.0, -0.2);
		glVertex3f(42.0, -40.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(49.0, -46.0, -0.2);
		glVertex3f(60.0, -46.0, -0.2);
		glVertex3f(60.0, -40.0, -0.2);
		glVertex3f(49.0, -40.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(60.0, -64.0, -0.2);
		glVertex3f(67.0, -64.0, -0.2);
		glVertex3f(67.0, -46.0, -0.2);
		glVertex3f(60.0, -46.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(55.0, -64.0, -0.2);
		glVertex3f(60.0, -64.0, -0.2);
		glVertex3f(60.0, -58.0, -0.2);
		glVertex3f(55.0, -58.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(36.0, -70.0, -0.2);
		glVertex3f(60.0, -70.0, -0.2);
		glVertex3f(60.0, -64.0, -0.2);
		glVertex3f(36.0, -64.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(36.0, -77.0, -0.2);
		glVertex3f(42.0, -77.0, -0.2);
		glVertex3f(42.0, -70.0, -0.2);
		glVertex3f(36.0, -70.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-37.0, -82.0, -0.2);
		glVertex3f(42.0, -82.0, -0.2);
		glVertex3f(42.0, -77.0, -0.2);
		glVertex3f(-37.0, -77.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, -77.0, -0.2);
		glVertex3f(5.0, -77.0, -0.2);
		glVertex3f(5.0, -46.0, -0.2);
		glVertex3f(0.0, -46.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-37.0, -77.0, -0.2);
		glVertex3f(-31.0, -77.0, -0.2);
		glVertex3f(-31.0, -64.0, -0.2);
		glVertex3f(-37.0, -64.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-31.0, -64.0, -0.2);
		glVertex3f(-25.0, -64.0, -0.2);
		glVertex3f(-25.0, -58.0, -0.2);
		glVertex3f(-31.0, -58.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-55.0, -70.0, -0.2);
		glVertex3f(-37.0, -70.0, -0.2);
		glVertex3f(-37.0, -64.0, -0.2);
		glVertex3f(-55.0, -64.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-62.0, -64.0, -0.2);
		glVertex3f(-55.0, -64.0, -0.2);
		glVertex3f(-55.0, -45.0, -0.2);
		glVertex3f(-62.0, -45.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-55.0, -45.0, -0.2);
		glVertex3f(-37.0, -45.0, -0.2);
		glVertex3f(-37.0, -39.0, -0.2);
		glVertex3f(-55.0, -39.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-44.0, -51.0, -0.2);
		glVertex3f(-37.0, -51.0, -0.2);
		glVertex3f(-37.0, -45.0, -0.2);
		glVertex3f(-44.0, -45.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-37.0, -39.0, -0.2);
		glVertex3f(-31.0, -39.0, -0.2);
		glVertex3f(-31.0, -33.0, -0.2);
		glVertex3f(-37.0, -33.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-31.0, -33.0, -0.2);
		glVertex3f(-25.0, -33.0, -0.2);
		glVertex3f(-25.0, -27.0, -0.2);
		glVertex3f(-31.0, -27.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-25.0, -58.0, -0.2);
		glVertex3f(-19.0, -58.0, -0.2);
		glVertex3f(-19.0, -8.0, -0.2);
		glVertex3f(-25.0, -8.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-74.0, -20.0, -0.2);
		glVertex3f(-25.0, -20.0, -0.2);
		glVertex3f(-25.0, -15.0, -0.2);
		glVertex3f(-74.0, -15.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-61.0, -15.0, -0.2);
		glVertex3f(-55.0, -15.0, -0.2);
		glVertex3f(-55.0, -2.0, -0.2);
		glVertex3f(-61.0, -2.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-80.0, -15.0, -0.2);
		glVertex3f(-74.0, -15.0, -0.2);
		glVertex3f(-74.0, 4.0, -0.2);
		glVertex3f(-80.0, 4.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-74.0, 4.0, -0.2);
		glVertex3f(-55.0, 4.0, -0.2);
		glVertex3f(-55.0, 10.0, -0.2);
		glVertex3f(-74.0, 10.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-55.0, -2.0, -0.2);
		glVertex3f(-43.0, -2.0, -0.2);
		glVertex3f(-43.0, 4.0, -0.2);
		glVertex3f(-55.0, 4.0, -0.2);
	glEnd();
	
	//Casco
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(-5.0, 53.0, -0.2);
		glVertex3f(13.0, 53.0, -0.2);
		glVertex3f(13.0, 64.0, -0.2);
		glVertex3f(-5.0, 64.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(-30.0, 22.0, -0.2);
		glVertex3f(-24.0, 22.0, -0.2);
		glVertex3f(-24.0, 41.0, -0.2);
		glVertex3f(-30.0, 41.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(31.0, 22.0, -0.2);
		glVertex3f(37.0, 22.0, -0.2);
		glVertex3f(37.0, 41.0, -0.2);
		glVertex3f(31.0, 41.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(-24.0, 34.0, -0.2);
		glVertex3f(-5.0, 34.0, -0.2);
		glVertex3f(-5.0, 53.0, -0.2);
		glVertex3f(-24.0, 53.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(-5.0, 28.0, -0.2);
		glVertex3f(13.0, 28.0, -0.2);
		glVertex3f(13.0, 47.0, -0.2);
		glVertex3f(-5.0, 47.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(13.0, 34.0, -0.2);
		glVertex3f(31.0, 34.0, -0.2);
		glVertex3f(31.0, 53.0, -0.2);
		glVertex3f(13.0, 53.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(-18.0, 53.0, -0.2);
		glVertex3f(-12.0, 53.0, -0.2);
		glVertex3f(-12.0, 59.0, -0.2);
		glVertex3f(-18.0, 59.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(20.0, 53.0, -0.2);
		glVertex3f(25.0, 53.0, -0.2);
		glVertex3f(25.0, 59.0, -0.2);
		glVertex3f(20.0, 59.0, -0.2);
	glEnd();

	//Cara
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.65);
		glVertex3f(-13.0, -3.0, -0.4);
		glVertex3f(18.0, -3.0, -0.4);
		glVertex3f(18.0, 4.0, -0.4);
		glVertex3f(-13.0, 4.0, -0.4);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.65);
		glVertex3f(-25.0, 10.0, -0.4);
		glVertex3f(-13.0, 10.0, -0.4);
		glVertex3f(-13.0, 34.0, -0.4);
		glVertex3f(-25.0, 34.0, -0.4);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.65);
		glVertex3f(-19.0, 4.0, -0.4);
		glVertex3f(-13.0, 4.0, -0.4);
		glVertex3f(-13.0, 10.0, -0.4);
		glVertex3f(-19.0, 10.0, -0.4);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.65);
		glVertex3f(-13.0, 28.0, -0.4);
		glVertex3f(-5.0, 28.0, -0.4);
		glVertex3f(-5.0, 34.0, -0.4);
		glVertex3f(-13.0, 34.0, -0.4);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.65);
		glVertex3f(18.0, 10.0, -0.4);
		glVertex3f(31.0, 10.0, -0.4);
		glVertex3f(31.0, 34.0, -0.4);
		glVertex3f(18.0, 34.0, -0.4);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.65);
		glVertex3f(18.0, 4.0, -0.4);
		glVertex3f(25.0, 4.0, -0.4);
		glVertex3f(25.0, 10.0, -0.4);
		glVertex3f(18.0, 10.0, -0.4);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.65);
		glVertex3f(14.0, 28.0, -0.4);
		glVertex3f(19.0, 28.0, -0.4);
		glVertex3f(19.0, 34.0, -0.4);
		glVertex3f(14.0, 34.0, -0.4);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.65);
		glVertex3f(-13.0, 10.0, -0.4);
		glVertex3f(18.0, 10.0, -0.4);
		glVertex3f(18.0, 16.0, -0.4);
		glVertex3f(-13.0, 16.0, -0.4);
	glEnd();
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.65);
		glVertex3f(0.0, 16.0, -0.4);
		glVertex3f(6.0, 16.0, -0.4);
		glVertex3f(6.0, 28.0, -0.4);
		glVertex3f(0.0, 28.0, -0.4);
	glEnd();
		
	//Ojos
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(-13.0, 16.0, -0.2);
		glVertex3f(0.0, 16.0, -0.2);
		glVertex3f(0.0, 28.0, -0.2);
		glVertex3f(-13.0, 28.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
		glVertex3f(6.0, 16.0, -0.2);
		glVertex3f(19.0, 16.0, -0.2);
		glVertex3f(19.0, 28.0, -0.2);
		glVertex3f(6.0, 28.0, -0.2);
	glEnd();

	//Mano Izquierda Arriba
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(-61.0, 35.0, -0.2);
		glVertex3f(-49.0, 35.0, -0.2);
		glVertex3f(-49.0, 59.0, -0.2);
		glVertex3f(-61.0, 59.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(-67.0, 41.0, -0.2);
		glVertex3f(-61.0, 41.0, -0.2);
		glVertex3f(-61.0, 54.0, -0.2);
		glVertex3f(-67.0, 54.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(-49.0, 47.0, -0.2);
		glVertex3f(-42.0, 47.0, -0.2);
		glVertex3f(-42.0, 54.0, -0.2);
		glVertex3f(-49.0, 54.0, -0.2);
	glEnd();

	//Brazo Izquiedo Arriba
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(-37.0, 10.0, -0.2);
		glVertex3f(-30.0, 10.0, -0.2);
		glVertex3f(-30.0, 22.0, -0.2);
		glVertex3f(-37.0, 22.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(-43.0, 16.0, -0.2);
		glVertex3f(-37.0, 16.0, -0.2);
		glVertex3f(-37.0, 41.0, -0.2);
		glVertex3f(-43.0, 41.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(-50.0, 23.0, -0.2);
		glVertex3f(-43.0, 23.0, -0.2);
		glVertex3f(-43.0, 35.0, -0.2);
		glVertex3f(-50.0, 35.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(-55.0, 29.0, -0.2);
		glVertex3f(-50.0, 29.0, -0.2);
		glVertex3f(-50.0, 35.0, -0.2);
		glVertex3f(-55.0, 35.0, -0.2);
	glEnd();

	//Mano Derecha Arriba
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(49.0, 33.0, -0.2);
		glVertex3f(68.0, 33.0, -0.2);
		glVertex3f(68.0, 46.0, -0.2);
		glVertex3f(49.0, 46.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(55.0, 46.0, -0.2);
		glVertex3f(68.0, 46.0, -0.2);
		glVertex3f(68.0, 58.0, -0.2);
		glVertex3f(55.0, 58.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(68.0, 40.0, -0.2);
		glVertex3f(74.0, 40.0, -0.2);
		glVertex3f(74.0, 52.0, -0.2);
		glVertex3f(68.0, 52.0, -0.2);
	glEnd();

	//Brazo Derecho Arriba
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(37.0, 10.0, -0.2);
		glVertex3f(43.0, 10.0, -0.2);
		glVertex3f(43.0, 22.0, -0.2);
		glVertex3f(37.0, 22.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(43.0, 15.0, -0.2);
		glVertex3f(49.0, 15.0, -0.2);
		glVertex3f(49.0, 40.0, -0.2);
		glVertex3f(43.0, 40.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(49.0, 21.0, -0.2);
		glVertex3f(55.0, 21.0, -0.2);
		glVertex3f(55.0, 33.0, -0.2);
		glVertex3f(49.0, 33.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(55.0, 27.0, -0.2);
		glVertex3f(62.0, 27.0, -0.2);
		glVertex3f(62.0, 33.0, -0.2);
		glVertex3f(55.0, 33.0, -0.2);
	glEnd();

	//Pierna Izquierda Arriba
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(-55.0, -64.0, -0.2);
		glVertex3f(-31.0, -64.0, -0.2);
		glVertex3f(-31.0, -51.0, -0.2);
		glVertex3f(-55.0, -51.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(-55.0, -51.0, -0.2);
		glVertex3f(-44.0, -51.0, -0.2);
		glVertex3f(-44.0, -45.0, -0.2);
		glVertex3f(-55.0, -45.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(-37.0, -51.0, -0.2);
		glVertex3f(-31.0, -51.0, -0.2);
		glVertex3f(-31.0, -39.0, -0.2);
		glVertex3f(-37.0, -39.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(-31.0, -58.0, -0.2);
		glVertex3f(-25.0, -58.0, -0.2);
		glVertex3f(-25.0, -46.0, -0.2);
		glVertex3f(-31.0, -46.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(-31.0, -46.0, -0.2);
		glVertex3f(-25.0, -46.0, -0.2);
		glVertex3f(-25.0, -33.0, -0.2);
		glVertex3f(-31.0, -33.0, -0.2);
	glEnd();

	//Pierna Derecha Arriba
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(30.0, -58.0, -0.2);
		glVertex3f(36.0, -58.0, -0.2);
		glVertex3f(36.0, -46.0, -0.2);
		glVertex3f(30.0, -46.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(36.0, -64.0, -0.2);
		glVertex3f(42.0, -64.0, -0.2);
		glVertex3f(42.0, -40.0, -0.2);
		glVertex3f(36.0, -40.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(42.0, -64.0, -0.2);
		glVertex3f(49.0, -64.0, -0.2);
		glVertex3f(49.0, -52.0, -0.2);
		glVertex3f(42.0, -52.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(49.0, -64.0, -0.2);
		glVertex3f(55.0, -64.0, -0.2);
		glVertex3f(55.0, -46.0, -0.2);
		glVertex3f(49.0, -46.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(55.0, -58.0, -0.2);
		glVertex3f(60.0, -58.0, -0.2);
		glVertex3f(60.0, -46.0, -0.2);
		glVertex3f(55.0, -46.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(30.0, -46.0, -0.2);
		glVertex3f(36.0, -46.0, -0.2);
		glVertex3f(36.0, -33.0, -0.2);
		glVertex3f(30.0, -33.0, -0.2);
	glEnd();

	//Mano Izquierda
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(-74.0, -15.0, -0.2);
		glVertex3f(-61.0, -15.0, -0.2);
		glVertex3f(-61.0, 4.0, -0.2);
		glVertex3f(-74.0, 4.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(-61.0, -2.0, -0.2);
		glVertex3f(-55.0, -2.0, -0.2);
		glVertex3f(-55.0, 4.0, -0.2);
		glVertex3f(-61.0, 4.0, -0.2);
	glEnd();

	//Mano Izquierda
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(67.0, -15.0, -0.2);
		glVertex3f(80.0, -15.0, -0.2);
		glVertex3f(80.0, 4.0, -0.2);
		glVertex3f(67.0, 4.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
	glVertex3f(60.0, -3.0, -0.2);
	glVertex3f(67.0, -3.0, -0.2);
	glVertex3f(67.0, 4.0, -0.2);
	glVertex3f(60.0, 4.0, -0.2);
	glEnd();

	//Brazos y pecho
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(-55.0, -15.0, -0.2);
		glVertex3f(-25.0, -15.0, -0.2);
		glVertex3f(-25.0, -2.0, -0.2);
		glVertex3f(-55.0, -2.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(-43.0, -3.0, -0.2);
		glVertex3f(-19.0, -3.0, -0.2);
		glVertex3f(-19.0, 4.0, -0.2);
		glVertex3f(-43.0, 4.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(-25.0, -8.0, -0.2);
		glVertex3f(-13.0, -8.0, -0.2);
		glVertex3f(-13.0, -3.0, -0.2);
		glVertex3f(-25.0, -3.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(-19.0, -27.0, -0.2);
		glVertex3f(24.0, -27.0, -0.2);
		glVertex3f(24.0, -8.0, -0.2);
		glVertex3f(-19.0, -8.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(18.0, -8.0, -0.2);
		glVertex3f(24.0, -8.0, -0.2);
		glVertex3f(24.0, -3.0, -0.2);
		glVertex3f(18.0, -3.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(24.0, -15.0, -0.2);
		glVertex3f(60.0, -15.0, -0.2);
		glVertex3f(60.0, -3.0, -0.2);
		glVertex3f(24.0, -3.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(25.0, -3.0, -0.2);
		glVertex3f(43.0, -3.0, -0.2);
		glVertex3f(43.0, 4.0, -0.2);
		glVertex3f(25.0, 4.0, -0.2);
	glEnd();

	//Piernas
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(-19.0, -40.0, -0.2);
		glVertex3f(24.0, -40.0, -0.2);
		glVertex3f(24.0, -27.0, -0.2);
		glVertex3f(-19.0, -27.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(-13.0, -46.0, -0.2);
		glVertex3f(18.0, -46.0, -0.2);
		glVertex3f(18.0, -40.0, -0.2);
		glVertex3f(-13.0, -40.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(-19.0, -52.0, -0.2);
		glVertex3f(0.0, -52.0, -0.2);
		glVertex3f(0.0, -46.0, -0.2);
		glVertex3f(-19.0, -46.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(-19.0, -46.0, -0.2);
		glVertex3f(-13.0, -46.0, -0.2);
		glVertex3f(-13.0, -40.0, -0.2);
		glVertex3f(-19.0, -40.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(-12.0, -58.0, -0.2);
		glVertex3f(0.0, -58.0, -0.2);
		glVertex3f(0.0, -52.0, -0.2);
		glVertex3f(-12.0, -52.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(5.0, -52.0, -0.2);
		glVertex3f(24.0, -52.0, -0.2);
		glVertex3f(24.0, -46.0, -0.2);
		glVertex3f(5.0, -46.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(18.0, -46.0, -0.2);
		glVertex3f(24.0, -46.0, -0.2);
		glVertex3f(24.0, -40.0, -0.2);
		glVertex3f(18.0, -40.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.65, 1.0);
		glVertex3f(5.0, -58.0, -0.2);
		glVertex3f(12.0, -58.0, -0.2);
		glVertex3f(12.0, -52.0, -0.2);
		glVertex3f(5.0, -52.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(-31.0, -77.0, -0.2);
		glVertex3f(0.0, -77.0, -0.2);
		glVertex3f(0.0, -64.0, -0.2);
		glVertex3f(-31.0, -64.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(-25.0, -64.0, -0.2);
		glVertex3f(0.0, -64.0, -0.2);
		glVertex3f(0.0, -58.0, -0.2);
		glVertex3f(-25.0, -58.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(-19.0, -58.0, -0.2);
		glVertex3f(-7.0, -58.0, -0.2);
		glVertex3f(-7.0, -52.0, -0.2);
		glVertex3f(-19.0, -52.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(5.0, -77.0, -0.2);
		glVertex3f(36.0, -77.0, -0.2);
		glVertex3f(36.0, -64.0, -0.2);
		glVertex3f(5.0, -64.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(5.0, -64.0, -0.2);
		glVertex3f(30.0, -64.0, -0.2);
		glVertex3f(30.0, -58.0, -0.2);
		glVertex3f(5.0, -58.0, -0.2);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.3, 0.8);
		glVertex3f(12.0, -58.0, -0.2);
		glVertex3f(24.0, -58.0, -0.2);
		glVertex3f(24.0, -52.0, -0.2);
		glVertex3f(12.0, -52.0, -0.2);
	glEnd();
	
	glPushMatrix();
		glColor3f(1.0,0,0);
		glTranslatef(3.5,0,0);
		glScalef(93,93,1);
		circulo(30,0.98);

	glPopMatrix();

	glPushMatrix();
		glColor3f(1.0,0,0);
		glTranslatef(3.5,-3.0,0);
		glRotatef(45,0,0,1.0);
		glScalef(107,107,1);
		circulo(4,0.98);
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();
	//glFlush();
	// Swap The Buffers
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	glOrtho(-150, 150, -150, 150, 0.1, 3);
	//glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {

	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	//glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(1000, 1000);	// Tamaño de la Ventana
	glutInitWindowPosition(500, 130);	//Posicion de la Ventana
	glutCreateWindow("Practica 3"); // Nombre de la Ventana
	//glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	//glutSpecialFunc     ( arrow_keys );	//Otras
	//glutIdleFunc		  ( display );	//Hace animacíon
	glutMainLoop();          // 

	return 0;
}



