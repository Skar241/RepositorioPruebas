#include "Elementos.h"

void Elementos::Init(){
	rotateL=-0;

	text1.LoadTGA("Lampara/metLam.tga");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadTGA("Lampara/amarillo.tga");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("Oficina/azul.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("Oficina/negro.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("mesaB/blanco.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

}
//CFiguras figLamp;

void Elementos::setRotateLamp(int rot){
	rotateL+=rot;
}

int Elementos::getRotateLamp(){
	return rotateL;
}

void Elementos::setLampara(){
	glPushMatrix();
		figLamp.cono(0.3,0.6,14,text1.GLindex);
		glTranslatef(0,0.3,0);
		glRotatef(0-rotateL,0,0,1);///primer eje////////////////////
		figLamp.esfera(0.07,14,14,text1.GLindex);
		figLamp.cilindro(0.05,1,14,text1.GLindex);
		glTranslatef(0,1,0);
		glRotatef(0+rotateL,0,0,1);
		figLamp.esfera(0.07,14,14,text1.GLindex);
		figLamp.cilindro(0.05,1,14,text1.GLindex);
		glTranslatef(0,1,0);
		glRotatef(70+rotateL,0,0,1);
		figLamp.esfera(0.07,14,14,text1.GLindex);
		figLamp.cilindro(0.05,0.15,14,text1.GLindex);
		glTranslatef(0,0.15,0);
		figLamp.cilindro(0.15,0.3,14,text1.GLindex);
		glTranslatef(0,0.7,0);
		glRotatef(180,0,0,1);
		figLamp.cono(0.6,0.4,14,text1.GLindex);
		glTranslatef(0,0.2,0);
		figLamp.esfera(0.14,14,14,text2.GLindex);
	glPopMatrix();
}

void Elementos::silla(GLuint text3,GLuint text4){
	glPushMatrix();
	glScalef(1,3,3);
		glDisable(GL_LIGHTING);
		glPushMatrix();//////respAsien
		glPushMatrix();//asiento
			glScalef(3.0,0.1,1.3);
			figLamp.prisma2(text3,text4);
		glPopMatrix();
		glTranslatef(0,0.01,-0.69);
		glRotatef(25,1,0,0);
		glPushMatrix();
			glScalef(1.0,0.1,0.1);
			figLamp.prisma2(text4,text4);
		glPopMatrix();
		glTranslatef(0,0.01,-0.05);
		glRotatef(25,1,0,0);
		glPushMatrix();
			glScalef(1.0,0.1,0.1);
			figLamp.prisma2(text4,text4);
		glPopMatrix();
		glTranslatef(0,0.01,-0.05);
		glRotatef(25,1,0,0);
		glPushMatrix();
			glScalef(1.0,0.1,0.1);
			figLamp.prisma2(text4,text4);
		glPopMatrix();
		glTranslatef(0,0.01,-0.05);
		glRotatef(25,1,0,0);
		glPushMatrix();
			glScalef(1.0,0.1,0.1);
			figLamp.prisma2(text4,text4);
		glPopMatrix();
		glTranslatef(0,0.01,-0.05);

		glTranslatef(0,0.0,-0.375);
		glPushMatrix();
			glScalef(1,0.1,0.75);
			figLamp.prisma2(text4,text4);
		glPopMatrix();
		glPushMatrix();//respaldo
			glTranslatef(0,0,-0.5);
			glRotatef(-20,1,0,0);
			glScalef(3,0.2,1.3);
			figLamp.prisma2(text3,text4);
		glPopMatrix();

		glPopMatrix();
		glPushMatrix();
			glScalef(3,1,1);
			glPushMatrix();///cilindro base-asiento
				glTranslatef(0,-0.61,0);
				figLamp.cilindro(0.1,0.6,14,text4);
			glPopMatrix();
			glPushMatrix();//esfera base
				glTranslatef(0,-0.61,0);
				figLamp.esfera(0.1,14,14,text4);
			glPopMatrix();

			for(int pat=0;pat<4;pat++){
			glPushMatrix();//cilindros base
				glTranslatef(0,-0.67,0);
				glRotatef(90,1,0,0);
				glRotatef(90*pat,0,0,1);
				glRotatef(30,1,0,0);
				figLamp.cilindro(0.09,0.7,14,text4);
				glTranslatef(0,0.7,0);
				glRotatef(-120,1,0,0);
				glTranslatef(0,-0.18,0);
				figLamp.cono(0.2,0.11,14,text4);
				//glTranslatef(0,-0.2,0);
				figLamp.esfera(0.1,14,14,text4);
			glPopMatrix();

			}
		glPopMatrix();
		glEnable(GL_LIGHTING);
	glPopMatrix();
}

void Elementos::sillaAzul(){
	silla(text3.GLindex,text4.GLindex);
}

void Elementos::sillaBlanca(){
	silla(text5.GLindex,text1.GLindex);
}
