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

}

void MesaBlanca::tabla(){
	glPushMatrix();
		glScalef(5,1,3);
		toMesa.prisma2(text1.GLindex,text2.GLindex);
	glPopMatrix();
}

void MesaBlanca::pata(){
	glPushMatrix();
		toMesa.cilindro(0.2,4,14,0);
		toMesa.esfera(0.2,14,14,0);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(1,0,0);
		toMesa.cilindro(0.2,4,14,0);
		toMesa.esfera(0.2,14,14,0);
	glPopMatrix();
}

void MesaBlanca::setMesa(){
	glDisable(GL_LIGHTING);
	//tabla();
	pata();
	glEnable(GL_LIGHTING);
}