#include "Elementos.h"


CFiguras figLamp;

void Elementos::setLampara(){
	glPushMatrix();
		glRotatef(-65,0,0,1);
		figLamp.cono(0.5,0.2,18,0);
		glTranslatef(0,0.29,0);
		figLamp.cilindro(0.09,0.2,18,0);
		glTranslatef(0,0.23,0);
		figLamp.esfera(0.05,18,18,0);
		glTranslatef(1,0.1,0);
		figLamp.prisma(0.1,0.6,0.1,0);
	glPopMatrix();
}