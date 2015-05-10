#include "Elementos.h"
//falta agregar sombra en orden correcto
void Estantes::Init(){
	Exterior.LoadTGA("construccion/estantes/estExt.tga");
	Exterior.BuildGLTexture();
	Exterior.ReleaseImage();

	Interior.LoadTGA("construccion/estantes/sombraEst.tga");
	Interior.BuildGLTexture();
	Interior.ReleaseImage();

	PuertaI.LoadTGA("construccion/estantes/puertax-.tga");
	PuertaI.BuildGLTexture();
	PuertaI.ReleaseImage();

	PuertaD.LoadTGA("construccion/estantes/puertax+.tga");
	PuertaD.BuildGLTexture();
	PuertaD.ReleaseImage();

	madera.LoadTGA("construccion/estantes/libmadera.tga");
	madera.BuildGLTexture();
	madera.ReleaseImage();

	maderaclara.LoadTGA("construccion/estantes/maderaclara.tga");
	maderaclara.BuildGLTexture();
	maderaclara.ReleaseImage();

}
//tex1 Front
//text2 Right
//text3 Back
//tex4 Left
//text5 Bottom
//text6 Top
void Estantes::creaEstante1(){
		glPushMatrix(); 
			//glRotatef(movEst,0,0,1);
			glPushMatrix();
				//glColor3f(0, 0, 1);
				glScalef(8.0,4,1.0);  
				poligono.prismaEst(Interior.GLindex, Exterior.GLindex,Exterior.GLindex, Exterior.GLindex,Exterior.GLindex, Exterior.GLindex);//parte trasera
				glPopMatrix();

			glPushMatrix();
				glTranslatef(0.0,2.25,1.5);
			
				glPushMatrix();
					//glColor3f(0,1,1);
					glScalef(8.0,0.5,4.0);//glScalef(8.0,4.0,0.5);
					poligono.prismaEst(Exterior.GLindex, Exterior.GLindex,Exterior.GLindex, Exterior.GLindex,Interior.GLindex, Exterior.GLindex);//parte arriba del estante(y+)
					glPopMatrix();

				glTranslatef(4.25,-2.25,0.0);
				glPushMatrix();
					glPushMatrix();
						//glColor3f(0,1,0);
						glScalef(0.5,5.0,4.0);
						poligono.prismaEst(Exterior.GLindex, Exterior.GLindex,Exterior.GLindex, Interior.GLindex,Exterior.GLindex, Exterior.GLindex);//lado der estante (x+)
						glPopMatrix();
					glTranslatef(-0.25,0,1.88);//para que gire entorno al borde del estante
					//glRotatef(movDoorD,0,1,0);
					glTranslatef(-2,0,0);//para construir la puerta
					//glColor3f(1,0,1);
					glScalef(4,4,0.25);
					poligono.prismaEst(PuertaI.GLindex,0,0,0,0,0);// Exterior.GLindex,Interior.GLindex, Exterior.GLindex,Exterior.GLindex, Exterior.GLindex);;	//puerta der 	
					glPopMatrix();

				glTranslatef(-4.25,-2.25,0.0);

				glPushMatrix();
					//glColor3f(1,1,0);
					glScalef(8.0,0.5,4.0);
					poligono.prismaEst(Exterior.GLindex, Exterior.GLindex,Exterior.GLindex, Exterior.GLindex,Exterior.GLindex, Interior.GLindex);//parte baja del estante (y-)
					glPopMatrix();

				glTranslatef(-4.25,2.25,0.0);
				glPushMatrix();
					//glColor3f(1,0,0);
					glScalef(0.5,5.0,4.0);
					poligono.prismaEst(Exterior.GLindex, Interior.GLindex,Exterior.GLindex, Exterior.GLindex,Exterior.GLindex, Exterior.GLindex);//parte izq del estante (x-)
					glPopMatrix();
				
				glTranslatef(0.25,0,1.88);//para que gire entorno al borde del estante
				//glRotatef(movDoorI,0,1,0);
				glTranslatef(2,0,0);//para construir la puerta
				//glColor3f(1,0,1);
				
				glScalef(4,4,0.25);
				glDisable(GL_LIGHTING);
				poligono.prismaEst(PuertaD.GLindex, 0,0,0,0,0);//Exterior.GLindex,Exterior.GLindex, Exterior.GLindex,Exterior.GLindex, Exterior.GLindex);	//puerta izquierda 
				glPopMatrix();

				//maderas intermedias
				glPushMatrix();
					glTranslatef(0.0,0.75,1.5);
					//glColor3f(1,1,1);
					glScalef(8.0,0.25,3.0);
					poligono.prismaEst(Exterior.GLindex, Exterior.GLindex,Exterior.GLindex, Exterior.GLindex,Interior.GLindex, Interior.GLindex);//superior
					glPopMatrix();

				glPushMatrix();
					glTranslatef(0.0,-0.75,1.5);
					glScalef(8.0,0.25,3.0);
					poligono.prismaEst(Exterior.GLindex, Exterior.GLindex,Exterior.GLindex, Exterior.GLindex,Interior.GLindex, Interior.GLindex);//inferior
					glPopMatrix();

		glPopMatrix();
}

void Estantes::creaEstante2(){

	glPushMatrix(); 
			//glRotatef(movEst,0,0,1);
			glPushMatrix();
				//glColor3f(0, 0, 1);
				glScalef(8.0,4,1.0);  
				poligono.prismaEst(Interior.GLindex, Exterior.GLindex,Exterior.GLindex, Exterior.GLindex,Exterior.GLindex, Exterior.GLindex);//parte trasera
				glPopMatrix();

			glPushMatrix();
				glTranslatef(0.0,2.25,1.5);
			
				glPushMatrix();
					//glColor3f(0,1,1);
					glScalef(8.0,0.5,4.0);//glScalef(8.0,4.0,0.5);
					poligono.prismaEst(Exterior.GLindex, Exterior.GLindex,Exterior.GLindex, Exterior.GLindex,Interior.GLindex, Exterior.GLindex);//parte arriba del estante(y+)
					glPopMatrix();

				glTranslatef(4.25,-2.25,0.0);
				glPushMatrix();
					glPushMatrix();
						//glColor3f(0,1,0);
						glScalef(0.5,5.0,4.0);
						poligono.prismaEst(Exterior.GLindex, Exterior.GLindex,Exterior.GLindex,Interior.GLindex,Exterior.GLindex, Exterior.GLindex);//lado der estante (x+)
						glPopMatrix();
					glTranslatef(-0.25,0,1.88);//para que gire entorno al borde del estante
					//glRotatef(movDoorD,0,1,0);
					glTranslatef(-2,0,0);//para construir la puerta
					//glColor3f(1,0,1);
					glScalef(4,4,0.25);
					poligono.prismaEst(Exterior.GLindex, Exterior.GLindex,Interior.GLindex, Exterior.GLindex,Exterior.GLindex, Exterior.GLindex);;	//puerta der 	
					glPopMatrix();

				glTranslatef(-4.25,-2.25,0.0);

				glPushMatrix();
					//glColor3f(1,1,0);
					glScalef(8.0,0.5,4.0);
					poligono.prismaEst(Exterior.GLindex, Exterior.GLindex,Exterior.GLindex, Exterior.GLindex,Exterior.GLindex, Interior.GLindex);//parte baja del estante (y-)
					glPopMatrix();

				glTranslatef(-4.25,2.25,0.0);
				glPushMatrix();
					//glColor3f(1,0,0);
					glScalef(0.5,5.0,4.0);
					poligono.prismaEst(Exterior.GLindex, Interior.GLindex,Exterior.GLindex, Exterior.GLindex,Exterior.GLindex, Exterior.GLindex);//parte izq del estante (x-)
					glPopMatrix();
				
				glTranslatef(0.25,0,1.88);//para que gire entorno al borde del estante
			//	glRotatef(movDoorI,0,1,0);
				glTranslatef(2,0,0);//para construir la puerta
				//glColor3f(1,0,1);
				
				glScalef(4,4,0.25);
				poligono.prismaEst(Exterior.GLindex, Exterior.GLindex,Interior.GLindex, Exterior.GLindex,Exterior.GLindex, Exterior.GLindex);	//puerta izquierda 
				glPopMatrix();

				//maderas intermedias
				glPushMatrix();
					glTranslatef(0.0,0.75,1.5);
					//glColor3f(1,1,1);
					glScalef(8.0,0.25,3.0);
					poligono.prismaEst(Exterior.GLindex, Exterior.GLindex,Exterior.GLindex, Exterior.GLindex,Interior.GLindex, Interior.GLindex);//superior
					glPopMatrix();

				glPushMatrix();
					glTranslatef(0.0,-0.75,1.5);
					glScalef(8.0,0.25,3.0);
					poligono.prismaEst(Exterior.GLindex, Exterior.GLindex,Exterior.GLindex, Exterior.GLindex,Interior.GLindex, Interior.GLindex);//inferior
					glPopMatrix();

		glPopMatrix();


}

void Estantes::creaLibrero(){
	glColor3f(0.3,0.3,0.3);
	glPushMatrix();
		glScalef(12,21,1);
		poligono.prismaEst(Interior.GLindex, madera.GLindex, madera.GLindex,madera.GLindex, madera.GLindex,maderaclara.GLindex);//parte trasera
		glPopMatrix();
	glTranslatef(0,-10,2.5);
	for(int i = 0; i<6;i++){
	glPushMatrix();
		glPushMatrix();
			glScalef(12,1,4);
			poligono.prismaEst(madera.GLindex, madera.GLindex, madera.GLindex,madera.GLindex, maderaclara.GLindex,maderaclara.GLindex);//primer madera (abajo)
			glPopMatrix();
		if(i<5){//para que nos genere i-1 niveles de cilindros, i = num de tarimas
			glPushMatrix();
					glTranslatef(-5.5,0.5,1.5);
					poligono.cilindro(0.5,3,10,madera.GLindex);
					glPopMatrix();
			glPushMatrix();
					glTranslatef(5.5,0.5,1.5);
					poligono.cilindro(0.5,3,10,madera.GLindex);
					glPopMatrix();
		}
		glPopMatrix();
		
	glTranslatef(0,4,0);
	}
	glColor3f(1,1,1);
}