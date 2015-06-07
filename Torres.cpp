#include "Elementos.h"
//completar edificio
void Torres::Init(){
	Fachada.LoadTGA("construccion/edificio/fVent.tga");
	Fachada.BuildGLTexture();
	Fachada.ReleaseImage();

	Concreto.LoadTGA("construccion/edificio/Fachada.tga");
	Concreto.BuildGLTexture();
	Concreto.ReleaseImage();

	DoorI.LoadTGA("construccion/edificio/doorI.tga");
	DoorI.BuildGLTexture();
	DoorI.ReleaseImage();

	DoorD.LoadTGA("construccion/edificio/doorD.tga");
	DoorD.BuildGLTexture();
	DoorD.ReleaseImage();

	bordeBase.LoadTGA("construccion/jardineras/Piedraborde.tga");
	bordeBase.BuildGLTexture();
	bordeBase.ReleaseImage();

	Escalones.LoadTGA("construccion/estantes/sombraEst.tga");
	Escalones.BuildGLTexture();
	Escalones.ReleaseImage();

	supDoor.LoadTGA("construccion/edificio/supDoor.tga");
	supDoor.BuildGLTexture();
	supDoor.ReleaseImage();

	FacInf.LoadTGA("construccion/edificio/venInf.tga");
	FacInf.BuildGLTexture();
	FacInf.ReleaseImage();

	Ventana.LoadTGA("construccion/edificio/cristal.tga");
	Ventana.BuildGLTexture();
	Ventana.ReleaseImage();

	Pint.LoadTGA("construccion/edificio/blanca.tga");
	Pint.BuildGLTexture();
	Pint.ReleaseImage();

	Lluvia.LoadTGA("construccion/lluvia.tga");
	Lluvia.BuildGLTexture();
	Lluvia.ReleaseImage();
}
//altura, largo profundidad
void Torres::crearTorre(float altura, float largo,float profundidad){//centro en  el medio de la torre
	float htmp= altura/5;//porque se crearán con 5 prismas
	glTranslatef(0,-2*htmp,0);//con esto bajamos el centro de la figura, para le usuario la figura tiene su centro en el origen
	glPushMatrix();
		glTranslatef(0,htmp/2-0.5,0);
		poligono.prismaEdif(1,largo,profundidad,bordeBase.GLindex);//base del edificio
		glPopMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);//habilita transparencia
	glAlphaFunc(GL_GREATER,0.1);//tolerancia de que será transparente y que no
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_DST_COLOR);
	for (int i =0;i<5;i++){
		glTranslatef(0,htmp,0);
		poligono.prisma2t(htmp,largo,profundidad,Concreto.GLindex, Fachada.GLindex);//altura, largo, profundidad, textura
	}
	//glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glPushMatrix();//borde lateral izq
		glTranslatef(-(largo/2)+.5,(htmp/2)+0.5,0);
		poligono.prismaEdif(1,1,profundidad, Concreto.GLindex);//altura, largo profundidad
		glPopMatrix();
		
	glPushMatrix();//borde lateral der
		glTranslatef((largo/2)-.5,(htmp/2)+0.5,0);
		poligono.prismaEdif(1,1,profundidad, Concreto.GLindex);
		glPopMatrix();
			
	glPushMatrix();//borde trasero
		glTranslatef(0,(htmp/2)+0.5,-(profundidad/2)+.5);
		poligono.prismaEdif(1,largo,1, Concreto.GLindex);
		glPopMatrix();
				
	glPushMatrix();//borde delantero
		glTranslatef(0,(htmp/2)+0.5,(profundidad/2)-.5);
		poligono.prismaEdif(1,largo,1, Concreto.GLindex);
		glPopMatrix();
}

void Torres::uneTorres(){
	
	glTranslatef(0,4.75,0);
	poligono.prismaEdif(0.5,10,5,Concreto.GLindex);//parte superior de la union
	glPushMatrix();
		glTranslatef(0,-1.3,-2.25);
		poligono.prismaEdif(2.5,10,0.5,supDoor.GLindex);//parte sobre la puerta
		glPushMatrix();
			glTranslatef(-3.5,-4.75,0);
			poligono.prismaEdif(7,3,0.5,FacInf.GLindex);//borde derecho
				glTranslatef(2.5,0,0);
				poligono.prismaEdif(7,2,0.5,DoorD.GLindex);//puerta derecha
			glPopMatrix();
		glPushMatrix();
			glTranslatef(3.5,-4.75,0);
			poligono.prismaEdif(7,3,0.5,FacInf.GLindex);//borde izquierdo
				glTranslatef(-2.5,0,0);
				poligono.prismaEdif(7,2,0.5,DoorI.GLindex);//puerta izq
			glPopMatrix();
		glPopMatrix();

	glTranslatef(0,-10,0);
	poligono.prismaEdif(1,10,5,bordeBase.GLindex);//base
	
}

void Torres::escaleras(){
	glTranslatef(0,-1.5,0);//centro inicia en y/2 y x,z del centro del escalon más grande
	poligono.prismaEdif(1,10,8,Escalones.GLindex);
	glTranslatef(0,1,1);
	poligono.prismaEdif(1,10,6,Escalones.GLindex);
	glTranslatef(0,1,1);
	poligono.prismaEdif(1,10,4,Escalones.GLindex);
	glTranslatef(0,1,1);
	poligono.prismaEdif(1,10,2,Escalones.GLindex);
}

void Torres::creaEdificio(){
	uneTorres();
	glPushMatrix();
		glTranslatef(-10,15.5,-2.5);
		crearTorre(50,10,10);//torre izq x-
		glPopMatrix();
	glPushMatrix();
		glTranslatef(10,15.5,-2.5);
		crearTorre(50,10,10);//torre der x+
		glPopMatrix();
	glPushMatrix();
		glTranslatef(0,0,-5);
		glScalef(1,0.25,0.6);
		escaleras();
		glPopMatrix();
	
}

void Torres::parteTrasera(){
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);//habilita transparencia
	glAlphaFunc(GL_GREATER,0.1);//tolerancia de que será transparente y que no
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_DST_COLOR);
	glBindTexture(GL_TEXTURE_2D,Ventana.GLindex);
	glColor3f(0.8,0.8,0.8);
	glBegin(GL_QUADS);//parte superior
			//glNormal3f(0,0,1);
			glTexCoord2f(0,1); glVertex3f(-20,10,-20);
			glTexCoord2f(0,0); glVertex3f(-20,10,20);
			glTexCoord2f(1,0); glVertex3f(20,10,20);
			glTexCoord2f(1,1); glVertex3f(20,10,-20);
		glEnd();
		glColor3f(1,1,1);
		glBegin(GL_QUADS);//lateral x-
			//glNormal3f(0,0,1);
			glTexCoord2f(0,1); glVertex3f(-20,10,-20);
			glTexCoord2f(0,0); glVertex3f(-20,0,-20);
			glTexCoord2f(1,0); glVertex3f(-20,0,20);
			glTexCoord2f(1,1); glVertex3f(-20,10,20);
		glEnd();

		glBegin(GL_QUADS);//frontal supDoor
			//glNormal3f(0,0,1);
			glTexCoord2f(0,1); glVertex3f(-20,10,20);
			glTexCoord2f(0,0); glVertex3f(-20,7,20);
			glTexCoord2f(1,0); glVertex3f(20,7,20);
			glTexCoord2f(1,1); glVertex3f(20,10,20);
		glEnd();

		glBegin(GL_QUADS);//frontal latDoor x-
			//glNormal3f(0,0,1);
			glTexCoord2f(0,1); glVertex3f(-20,7,20);
			glTexCoord2f(0,0); glVertex3f(-20,0,20);
			glTexCoord2f(1,0); glVertex3f(-5,0,20);
			glTexCoord2f(1,1); glVertex3f(-5,7,20);
		glEnd();

		glBegin(GL_QUADS);//frontal latDoor x+
			//glNormal3f(0,0,1);
			glTexCoord2f(0,1); glVertex3f(5,7,20);
			glTexCoord2f(0,0); glVertex3f(5,0,20);
			glTexCoord2f(1,0); glVertex3f(20,0,20);
			glTexCoord2f(1,1); glVertex3f(20,7,20);
		glEnd();

		glBegin(GL_QUADS);//lateral x+
			//glNormal3f(0,0,1);
			glTexCoord2f(0,1); glVertex3f(20,10,20);
			glTexCoord2f(0,0); glVertex3f(20,0,20);
			glTexCoord2f(1,0); glVertex3f(20,0,-20);
			glTexCoord2f(1,1); glVertex3f(20,10,-20);
		glEnd();

		glDisable(GL_BLEND);
		glDisable(GL_ALPHA_TEST);

			glBindTexture(GL_TEXTURE_2D,DoorI.GLindex);
		glBegin(GL_QUADS);//frontal Door x-
			//glNormal3f(0,0,1);
			glTexCoord2f(0,1); glVertex3f(-5,7,20);
			glTexCoord2f(0,0); glVertex3f(-5,0,20);
			glTexCoord2f(1,0); glVertex3f(0,0,20);
			glTexCoord2f(1,1); glVertex3f(0,7,20);
		glEnd();
		glBindTexture(GL_TEXTURE_2D,DoorD.GLindex);
		glBegin(GL_QUADS);//frontal Door x+
			//glNormal3f(0,0,1);
			glTexCoord2f(0,1); glVertex3f(0,7,20);
			glTexCoord2f(0,0); glVertex3f(0,0,20);
			glTexCoord2f(1,0); glVertex3f(5,0,20);
			glTexCoord2f(1,1); glVertex3f(5,7,20);
		glEnd();
		glBindTexture(GL_TEXTURE_2D,Escalones.GLindex);
		glBegin(GL_QUADS);//parte inferior
			//glNormal3f(0,0,1);
			glTexCoord2f(0,1); glVertex3f(-20,0,-20);
			glTexCoord2f(0,0); glVertex3f(-20,0,20);
			glTexCoord2f(1,0); glVertex3f(20,0,20);
			glTexCoord2f(1,1); glVertex3f(20,0,-20);
		glEnd();

		glPopMatrix();
}

void Torres::vestibulo(){
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);//habilita transparencia
	glAlphaFunc(GL_GREATER,0.1);//tolerancia de que será transparente y que no
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_DST_COLOR);
	glBindTexture(GL_TEXTURE_2D,Pint.GLindex);
//	glColor3f(0.1,0.1,0.1);
	glBegin(GL_QUADS);//parte superior
			//glNormal3f(0,0,1);
			glTexCoord2f(0,1); glVertex3f(10,-20,-20);
			glTexCoord2f(0,0); glVertex3f(10,-20,20);
			glTexCoord2f(1,0); glVertex3f(10,20,20);
			glTexCoord2f(1,1); glVertex3f(10,20,-20);
		glEnd();

	glDisable(GL_ALPHA_TEST);
	//glDisable(GL_BLEND);
}
void Torres::lluvia(){
	glPushMatrix();
		glDisable(GL_LIGHTING);
		glEnable(GL_ALPHA_TEST);//habilita transparencia
		glAlphaFunc(GL_GREATER,0.1);//tolerancia de que será transparente y que no
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_DST_COLOR);
		glBindTexture(GL_TEXTURE_2D,Lluvia.GLindex);
		//glColor3f(0.8,0.8,0.8);
		//glBegin(GL_QUADS);//parte trasera del poligono
 			//glNormal3f(0,0,1);
 			//	glTexCoord2f(0+offset,0+offset); glVertex3f(20,0,-20);
 			//	glTexCoord2f(0+offset,1+offset); glVertex3f(-20,10,-20);
 			//	glTexCoord2f(1+offset,0+offset); glVertex3f(20,10,-20);
 			//	glTexCoord2f(1+offset,1+offset); glVertex3f(20,0,-20);
		//	glEnd();
 		glColor3f(1,1,1);
		//	glBegin(GL_QUADS);//lateral x
 				//glNormal3f(0,0,1);
			//	glTexCoord2f(0-offset,1-offset); glVertex3f(-20,10,-20);
			//	glTexCoord2f(0-offset,0-offset); glVertex3f(-20,0,-20);
			//	glTexCoord2f(1-offset,0-offset); glVertex3f(-20,0,20);
			//	glTexCoord2f(1-offset,1-offset); glVertex3f(-20,10,20);
		//	glEnd();

		//	glBegin(GL_QUADS);//lateral x+
 			//glNormal3f(0,0,1);
			//	glTexCoord2f(0-offset,1-offset); glVertex3f(20,10,20);
			//	glTexCoord2f(0-offset,0-offset); glVertex3f(20,0,20);
			//	glTexCoord2f(1-offset,0-offset); glVertex3f(20,0,-20);
			//	glTexCoord2f(1-offset,1-offset); glVertex3f(20,10,-20);
		//	glEnd();

 		glBegin(GL_QUADS);//frontal
 			//glNormal3f(0,0,1);
 			glTexCoord2f(0-offset,1-offset); glVertex3f(-20,20,20);
 			glTexCoord2f(0-offset,0-offset); glVertex3f(-20,0,20);
 			glTexCoord2f(1-offset,0-offset); glVertex3f(20,0,20);
 			glTexCoord2f(1-offset,1-offset); glVertex3f(20,20,20);
 		glEnd();

 		glDisable(GL_BLEND);
 		glDisable(GL_ALPHA_TEST);
  
 	glPopMatrix();
}