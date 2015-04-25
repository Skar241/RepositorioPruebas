#include "Elementos.h"

//CTexture text1;
//CFiguras toMesa;

void MesaBlanca::Init(){
	text1.LoadTGA("mesaB/tabla.tga");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadTGA("mesaB/gris.tga");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("mesaB/madera.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();
}

void MesaBlanca::tabla(){
	glPushMatrix();
		glScalef(13,1,18);
		toMesa.prisma2(text1.GLindex,text2.GLindex);
	glPopMatrix();
}

void MesaBlanca::pata1(){
	glPushMatrix();
		toMesa.cilindro(0.2,4,14,text2.GLindex);
		toMesa.esfera(0.2,14,14,0);
		glPushMatrix();
			glRotatef(-90,0,0,1);
			toMesa.cilindro(0.2,1,14,text2.GLindex);
		glPopMatrix();
		glPushMatrix();
			glRotatef(115,0,0,1);
			toMesa.cilindro(0.2,2,14,text2.GLindex);
		glPopMatrix();
		glTranslatef(-1.8,-1.6,0);
		toMesa.cono(1,0.4,14,text2.GLindex);
		glTranslatef(0,0.7,0);
		toMesa.esfera(0.2,14,14,text2.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1,0,0);
		toMesa.cilindro(0.2,4,14,text2.GLindex);
		toMesa.esfera(0.2,14,14,text2.GLindex);
		glPushMatrix();
			glRotatef(-100,0,0,1);
			toMesa.cilindro(0.2,5.5,14,text2.GLindex);
		glPopMatrix();
		glTranslatef(3*1.8,-1.6,0);
		toMesa.cono(1,0.4,14,text2.GLindex);
		glTranslatef(0,0.7,0);
		toMesa.esfera(0.2,14,14,text2.GLindex);
	glPopMatrix();
	
}

void MesaBlanca::pata(){
	glPushMatrix();
		toMesa.cilindro(0.2,4,14,text2.GLindex);
		toMesa.esfera(0.2,14,14,0);
		glPushMatrix();
			glRotatef(-90,0,0,1);
			toMesa.cilindro(0.2,3,14,text2.GLindex);
		glPopMatrix();
		glPushMatrix();
			glRotatef(115,0,0,1);
			toMesa.cilindro(0.2,2,14,text2.GLindex);
		glPopMatrix();
		glTranslatef(-1.8,-1.6,0);
		toMesa.cono(1,0.4,14,text2.GLindex);
		glTranslatef(0,0.7,0);
		toMesa.esfera(0.2,14,14,text2.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(3,0,0);
		toMesa.cilindro(0.2,4,14,text2.GLindex);
		toMesa.esfera(0.2,14,14,text2.GLindex);
		glPushMatrix();
			glRotatef(-115,0,0,1);
			toMesa.cilindro(0.2,2,14,text2.GLindex);
		glPopMatrix();
		glTranslatef(1.8,-1.6,0);
		toMesa.cono(1,0.4,14,text2.GLindex);
		glTranslatef(0,0.7,0);
		toMesa.esfera(0.2,14,14,text2.GLindex);
	glPopMatrix();
	
}

void MesaBlanca::setMesa1(){
	glDisable(GL_LIGHTING);
	glPushMatrix();
		glTranslatef(0,4.5,0);
		tabla();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-2,0,6.5);
		pata();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-2,0,-6.5);
		pata();
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void MesaBlanca::setMesa(){
	glDisable(GL_LIGHTING);
	glPushMatrix();
		glTranslatef(0,4.5,0);
		tabla();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-2,0,6.5);
		pata1();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-2,0,-6.5);
		pata1();
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void MesaBlanca::setMesaJuntas(){
	glDisable(GL_LIGHTING);
	glPushMatrix();
		glTranslatef(0,3,0);
		glScalef(10,0.6,5);
		toMesa.prisma2(text3.GLindex,text3.GLindex);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,2.6,2);
		glScalef(9.5,0.2,0.5);
		toMesa.prisma(text2.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0,2.6,-2);
		glScalef(9.5,0.2,0.5);
		toMesa.prisma(text2.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(4.5,2.6,0);
		glScalef(0.5,0.2,3.5);
		toMesa.prisma(text2.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-4.5,2.6,0);
		glScalef(0.5,0.2,3.5);
		toMesa.prisma(text2.GLindex);	
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(4.5,-0.5,2.0);
		toMesa.cilindro(0.1,3,14,text2.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-4.5,-0.5,2.0);
		toMesa.cilindro(0.1,3,14,text2.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(4.5,-0.5,-2.0);
		toMesa.cilindro(0.1,3,14,text2.GLindex);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-4.5,-0.5,-2.0);
		toMesa.cilindro(0.1,3,14,text2.GLindex);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}