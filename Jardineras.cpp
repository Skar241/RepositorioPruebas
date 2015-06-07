#include "Elementos.h"
//falta poner arboles donde va, todo lo demás ya está :3

void Jardineras::Init(){//init debe contener texturas que se utilizaran
	
	text0.LoadTGA("construccion/jardineras/pasto01.tga");
	text0.BuildGLTexture();
	text0.ReleaseImage();

	text1.LoadTGA("construccion/jardineras/Piedraborde.tga");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadTGA("construccion/jardineras/pino.tga");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("construccion/jardineras/arbol.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("construccion/jardineras/maceta.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

}

void Jardineras::JardineraBase(float altura, float largo, float profundidad ){
	
	poligono.triangulo(altura,largo,profundidad/3,text0.GLindex,text1.GLindex);//(altura (y), largo (x), profundida (z),pasto, borde)
	glTranslatef(0,0,profundidad/2);
	poligono.prisma2t(altura,largo,(2*profundidad)/3,text0.GLindex,text1.GLindex);
}

void Jardineras::JardineraArbol(){
	poligono.triangulo(1,5,10,text0.GLindex,text1.GLindex);
	glTranslatef(0,0,15);
	poligono.prisma2t(1,5,20,text0.GLindex,text1.GLindex);
	glTranslatef(0,-0.5,10);
	poligono.cilindro(2.5,1,20,text0.GLindex);//radio altura resolucion,textura
}

void Jardineras::JardineraPino(){//se creará por puntos

	GLfloat vSup[12][3]={
		{3,2,-2},
		{3,2,2},
		{-4,2,2},
		{-4.5,2,1},
		{-4.3,2,-0.5},
		{-3.4,2,-2},
		{-3,2,-2.7},
		{-2.5,2,-2},
		{-1,2,-1.6},
		{0,2,-1.5},
		{1,2,-1.3},
		{2.5,2,-1.3}
	}; 

	GLfloat vInf[12][3]={
		{3,1,-2},
		{3,1,2},
		{-4,1,2},
		{-4.5,1,1},
		{-4.3,1,-0.5},
		{-3.4,1,-2},
		{-3,1,-2.7},
		{-2.5,1,-2},
		{-1,1,-1.6},
		{0,1,-1.5},
		{1,1,-1.3},
		{2.5,1,-1.3}
	}; 

		glBindTexture(GL_TEXTURE_2D, text0.GLindex);
		glBegin(GL_POLYGON);
			glNormal3f(0,1,0);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vSup[2]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vSup[1]);
			glTexCoord2f(1.0f, 0.9f); glVertex3fv(vSup[0]);
			glTexCoord2f(0.9f, 0.8f); glVertex3fv(vSup[11]);
			glTexCoord2f(0.8f, 0.7f); glVertex3fv(vSup[10]);
			glTexCoord2f(0.7f, 0.6f); glVertex3fv(vSup[9]);
			glTexCoord2f(0.6f, 0.7f); glVertex3fv(vSup[8]);
			glTexCoord2f(0.5f, 0.8); glVertex3fv(vSup[7]);
			glTexCoord2f(0.4f, 1.0f); glVertex3fv(vSup[6]);
			glTexCoord2f(0.3f, 0.9f); glVertex3fv(vSup[5]);
			glTexCoord2f(0.2f, 0.7f); glVertex3fv(vSup[4]);
			glTexCoord2f(0.1f, 0.4f); glVertex3fv(vSup[3]);

		glEnd();

		glBegin(GL_POLYGON);
			glNormal3f(0,1,0);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vInf[2]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vInf[1]);
			glTexCoord2f(1.0f, 0.9f); glVertex3fv(vInf[0]);
			glTexCoord2f(0.9f, 0.8f); glVertex3fv(vInf[11]);
			glTexCoord2f(0.8f, 0.7f); glVertex3fv(vInf[10]);
			glTexCoord2f(0.7f, 0.6f); glVertex3fv(vInf[9]);
			glTexCoord2f(0.6f, 0.7f); glVertex3fv(vInf[8]);
			glTexCoord2f(0.5f, 0.8f); glVertex3fv(vInf[7]);
			glTexCoord2f(0.4f, 1.0f); glVertex3fv(vInf[6]);
			glTexCoord2f(0.3f, 0.9f); glVertex3fv(vInf[5]);
			glTexCoord2f(0.2f, 0.7f); glVertex3fv(vInf[4]);
			glTexCoord2f(0.1f, 0.4f); glVertex3fv(vInf[3]);
		glEnd();

		//bordes
		glBindTexture(GL_TEXTURE_2D, text1.GLindex);
		glBegin(GL_POLYGON);
			glNormal3f(1,0,0);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vSup[0]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vSup[1]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vInf[1]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vInf[0]);
		glEnd();

		glBegin(GL_POLYGON);
			//glNormal3f(-1,0,1);// checar normales
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vSup[11]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vSup[0]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vInf[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vInf[11]);
		glEnd();

		glBegin(GL_POLYGON);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vSup[10]);
			glTexCoord2f(1.0f,1.0f); glVertex3fv(vSup[11]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vInf[11]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vInf[10]);
		glEnd();

		glBegin(GL_POLYGON);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vSup[9]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vSup[10]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vInf[10]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vInf[9]);
		glEnd();

		glBegin(GL_POLYGON);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vSup[8]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vSup[9]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vInf[9]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vInf[8]);
		glEnd();

		glBegin(GL_POLYGON);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vSup[7]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vSup[8]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vInf[8]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vInf[7]);
		glEnd();

		glBegin(GL_POLYGON);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vSup[6]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vSup[7]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vInf[7]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vInf[6]);
		glEnd();

		glBegin(GL_POLYGON);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vSup[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vSup[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vInf[6]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vInf[5]);
		glEnd();

		glBegin(GL_POLYGON);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vSup[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vSup[5]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vInf[5]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vInf[4]);
		glEnd();

		glBegin(GL_POLYGON);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vSup[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vSup[4]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vInf[4]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vInf[3]);
		glEnd();

		glBegin(GL_POLYGON);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vSup[2]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vSup[3]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vInf[3]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vInf[2]);
		glEnd();

		glBegin(GL_POLYGON);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vSup[2]);
			glTexCoord2f(1.0f, 1.0f);glVertex3fv(vSup[1]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vInf[1]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vInf[2]);
		glEnd();


}

void Jardineras::Pino(){

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);//habilita transparencia
	glAlphaFunc(GL_GREATER,0.1);//tolerancia de que será transparente y que no
	glBindTexture(GL_TEXTURE_2D,text2.GLindex);
	
		glBegin(GL_QUADS);
			glNormal3f(0,0,1);
			glTexCoord2f(0,0); glVertex3f(-20,0,0);
			glTexCoord2f(1,0); glVertex3f(20,0,0);
			glTexCoord2f(1,1); glVertex3f(20,40,0);
			glTexCoord2f(0,1); glVertex3f(-20,40,0);

		glEnd();
		glPopMatrix();

	glPushMatrix();
		glRotatef(30,0,1,0);
		glBegin(GL_QUADS);
			glNormal3f(0,0,1);
			glTexCoord2f(0 ,0); glVertex3f(-20,0,0);
			glTexCoord2f(1,0); glVertex3f(20,0,0);
			glTexCoord2f(1,1); glVertex3f(20,40,0);
			glTexCoord2f(0,1); glVertex3f(-20,40,0);

		glEnd();
		glPopMatrix();

		glPushMatrix();
			glRotatef(60,0,1,0);
			glBegin(GL_QUADS);
				glNormal3f(0,0,1);
				glTexCoord2f(0 ,0); glVertex3f(-20,0,0);
				glTexCoord2f(1,0); glVertex3f(20,0,0);
				glTexCoord2f(1,1); glVertex3f(20,40,0);
				glTexCoord2f(0,1); glVertex3f(-20,40,0);

		glEnd();
			glPopMatrix();

		glPushMatrix();
			glRotatef(95,0,1,0);
			glBegin(GL_QUADS);
				glNormal3f(0,0,1);
				glTexCoord2f(0,0); glVertex3f(-20,0,0);
				glTexCoord2f(1,0); glVertex3f(20,0,0);
				glTexCoord2f(1,1); glVertex3f(20,40,0);
				glTexCoord2f(0,1); glVertex3f(-20,40,0);
			glEnd();
			glPopMatrix();

		glPushMatrix();
			glRotatef(120,0,1,0);
			glBegin(GL_QUADS);
				glNormal3f(0,0,1);
				glTexCoord2f(0 ,0); glVertex3f(-20,0,0);
				glTexCoord2f(1,0); glVertex3f(20,0,0);
				glTexCoord2f(1,1); glVertex3f(20,40,0);
				glTexCoord2f(0,1); glVertex3f(-20,40,0);
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glRotatef(150,0,1,0);
			glBegin(GL_QUADS);
				glNormal3f(0,0,1);
				glTexCoord2f(0 ,0); glVertex3f(-20,0,0);
				glTexCoord2f(1,0); glVertex3f(20,0,0);
				glTexCoord2f(1,1); glVertex3f(20,40,0);
				glTexCoord2f(0,1); glVertex3f(-20,40,0);
			glEnd();
			glPopMatrix();
	glDisable(GL_ALPHA_TEST);
}

void Jardineras::Arbol(){
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);//habilita transparencia
	glAlphaFunc(GL_GREATER,0.1);//tolerancia de que será transparente y que no
	glBindTexture(GL_TEXTURE_2D,text3.GLindex);
	
		glBegin(GL_QUADS);
			glNormal3f(0,0,1);
			glTexCoord2f(0,0); glVertex3f(-20,0,0);
			glTexCoord2f(1,0); glVertex3f(20,0,0);
			glTexCoord2f(1,1); glVertex3f(20,40,0);
			glTexCoord2f(0,1); glVertex3f(-20,40,0);

		glEnd();
		glPopMatrix();

	glPushMatrix();
		glRotatef(30,0,1,0);
		glBegin(GL_QUADS);
			glNormal3f(0,0,1);
			glTexCoord2f(0 ,0); glVertex3f(-20,0,0);
			glTexCoord2f(1,0); glVertex3f(20,0,0);
			glTexCoord2f(1,1); glVertex3f(20,40,0);
			glTexCoord2f(0,1); glVertex3f(-20,40,0);

		glEnd();
		glPopMatrix();

		glPushMatrix();
			glRotatef(60,0,1,0);
			glBegin(GL_QUADS);
				glNormal3f(0,0,1);
				glTexCoord2f(0 ,0); glVertex3f(-20,0,0);
				glTexCoord2f(1,0); glVertex3f(20,0,0);
				glTexCoord2f(1,1); glVertex3f(20,40,0);
				glTexCoord2f(0,1); glVertex3f(-20,40,0);

		glEnd();
			glPopMatrix();

		glPushMatrix();
			glRotatef(95,0,1,0);
			glBegin(GL_QUADS);
				glNormal3f(0,0,1);
				glTexCoord2f(0,0); glVertex3f(-20,0,0);
				glTexCoord2f(1,0); glVertex3f(20,0,0);
				glTexCoord2f(1,1); glVertex3f(20,40,0);
				glTexCoord2f(0,1); glVertex3f(-20,40,0);
			glEnd();
			glPopMatrix();

		glPushMatrix();
			glRotatef(120,0,1,0);
			glBegin(GL_QUADS);
				glNormal3f(0,0,1);
				glTexCoord2f(0 ,0); glVertex3f(-20,0,0);
				glTexCoord2f(1,0); glVertex3f(20,0,0);
				glTexCoord2f(1,1); glVertex3f(20,40,0);
				glTexCoord2f(0,1); glVertex3f(-20,40,0);
			glEnd();
			glPopMatrix();

			glPushMatrix();
			glRotatef(150,0,1,0);
			glBegin(GL_QUADS);
				glNormal3f(0,0,1);
				glTexCoord2f(0 ,0); glVertex3f(-20,0,0);
				glTexCoord2f(1,0); glVertex3f(20,0,0);
				glTexCoord2f(1,1); glVertex3f(20,40,0);
				glTexCoord2f(0,1); glVertex3f(-20,40,0);
			glEnd();
			glPopMatrix();
	glDisable(GL_ALPHA_TEST);
}

void Jardineras::Maceta(){
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);//habilita transparencia
	glAlphaFunc(GL_GREATER,0.1);//tolerancia de que será transparente y que no
	glBindTexture(GL_TEXTURE_2D,text4.GLindex);
	
	glPushMatrix();
		glBegin(GL_QUADS);
			glNormal3f(0,0,1);
			glTexCoord2f(0 ,0); glVertex3f(-20,0,0);
			glTexCoord2f(1,0); glVertex3f(20,0,0);
			glTexCoord2f(1,1); glVertex3f(20,40,0);
			glTexCoord2f(0,1); glVertex3f(-20,40,0);

		glEnd();
	glPopMatrix();

	glPushMatrix();
		glRotatef(30,0,1,0);
		glBegin(GL_QUADS);
			glNormal3f(0,0,1);
			glTexCoord2f(0 ,0); glVertex3f(-20,0,0);
			glTexCoord2f(1,0); glVertex3f(20,0,0);
			glTexCoord2f(1,1); glVertex3f(20,40,0);
			glTexCoord2f(0,1); glVertex3f(-20,40,0);

		glEnd();
	glPopMatrix();

	glPushMatrix();
		glRotatef(60,0,1,0);
		glBegin(GL_QUADS);
			glNormal3f(0,0,1);
			glTexCoord2f(0 ,0); glVertex3f(-20,0,0);
			glTexCoord2f(1,0); glVertex3f(20,0,0);
			glTexCoord2f(1,1); glVertex3f(20,40,0);
			glTexCoord2f(0,1); glVertex3f(-20,40,0);

		glEnd();
	glPopMatrix();

	glPushMatrix();
		glRotatef(93,0,1,0);
		glBegin(GL_QUADS);
			glNormal3f(0,0,1);
			glTexCoord2f(0 ,0); glVertex3f(-20,0,0);
			glTexCoord2f(1,0); glVertex3f(20,0,0);
			glTexCoord2f(1,1); glVertex3f(20,40,0);
			glTexCoord2f(0,1); glVertex3f(-20,40,0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glRotatef(120,0,1,0);
			glBegin(GL_QUADS);
				glNormal3f(0,0,1);
				glTexCoord2f(0 ,0); glVertex3f(-20,0,0);
				glTexCoord2f(1,0); glVertex3f(20,0,0);
				glTexCoord2f(1,1); glVertex3f(20,40,0);
				glTexCoord2f(0,1); glVertex3f(-20,40,0);

			glEnd();
	glPopMatrix();

	glPushMatrix();
		glRotatef(150,0,1,0);
		glBegin(GL_QUADS);
			glNormal3f(0,0,1);
			glTexCoord2f(0 ,0); glVertex3f(-20,0,0);
			glTexCoord2f(1,0); glVertex3f(20,0,0);
			glTexCoord2f(1,1); glVertex3f(20,40,0);
			glTexCoord2f(0,1); glVertex3f(-20,40,0);

		glEnd();
	glPopMatrix();
	glDisable(GL_ALPHA_TEST);

}

void Jardineras::setJardineraArbolDer(){
	JardineraArbol();
	glTranslatef(0,0.5,-5);
	glScalef(0.3,0.8,0.3);
	Arbol();

}

void Jardineras::setJardineraArbolIzq(){
	glPushMatrix();
		glRotatef(180,0,0,1);
		JardineraArbol();
		glPopMatrix();
	glTranslatef(0,0.5,20);
	glScalef(0.3,0.8,0.3);
	Arbol();

}

void Jardineras::setJardineraPinoDer(){
	glPushMatrix();
		glScalef(3,1,3);
		JardineraPino();
		glPopMatrix();
	glTranslatef(-4.5,0.5,1.8);
	glScalef(0.5,1,0.5);
	Pino();
}

void Jardineras::setJardineraPinoIzq(){
	glPushMatrix();
		glRotatef(180,0,0,1);
		glScalef(3,1,3);
		JardineraPino();
		glPopMatrix();
	glTranslatef(4.5,-1.5,1.8);
	glScalef(0.5,1,0.5);
	Pino();
}

void Jardineras::jardinerasFrontales(){
	int h= 1;
	int r=1;
	int res= 10;
	float ang=89.2/res;
	ang=ang*(3.141592654/180);
	int i;
	//float ctext_s = 1/resolucion;
	//float ctext_t = 0.0;
	//glBindTexture(GL_TEXTURE_2D, text); 
	//base
	for(i=0;i<=res;i++){
		glBegin(GL_POLYGON);
			glVertex3f(r*cos(float(i*ang)),0,r*sin(float(i*ang)));
			glVertex3f(0,0,0);
			glVertex3f(r*cos(float((i+1)*ang)),0,r*sin(float((i+1)*ang)));
		glEnd();
	}
	//superior
	for(i=0;i<=res;i++){
		glBegin(GL_POLYGON);
			glVertex3f(r*cos(float(i*ang)),h,r*sin(float(i*ang)));
			glVertex3f(0,h,0);
			glVertex3f(r*cos(float((i+1)*ang)),h,r*sin(float((i+1)*ang)));
		glEnd();
	}
	//caras
	glBegin(GL_POLYGON);
		glVertex3f(0,1,1);
		glVertex3f(0,0,1);
		glVertex3f(0,0,0);
		glVertex3f(0,1,0);
		glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(0,1,0);
		glVertex3f(0,0,0);
		glVertex3f(1,0,0);
		glVertex3f(1,1,0);
		glEnd();
	for(i=0;i<=res;i++){
		glBegin(GL_POLYGON);
			glVertex3f(r*cos(float((i+1)*ang)),0,r*sin(float((i+1)*ang)));
			glVertex3f(r*cos(float(i*ang)),0,r*sin(float(i*ang)));
			glVertex3f(r*cos(float(i*ang)),h,r*sin(float(i*ang)));
			glVertex3f(r*cos(float((i+1)*ang)),h,r*sin(float((i+1)*ang)));
		glEnd();
	}

	
}