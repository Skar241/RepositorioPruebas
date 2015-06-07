#include "Elementos.h"

void Oficina::Init(){
	text1.LoadTGA("Oficina/sueloMa.tga");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadTGA("Oficina/techo.tga");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("Oficina/ventana.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("Oficina/puerta.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("Oficina/chapa.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	rotPuerta=0;
	rotPerilla=0;

	mesBla.Init();
	elem.Init();
	escr.Init();
	est.Init();
	jar.Init();

}

void Oficina::piso(){
	glPushMatrix();
		glTranslatef(0.0,-4.0,-8.0);//piso
		glPushMatrix();
			glScalef(80,0.1,46);
			glDisable(GL_LIGHTING);
			toFloor.prisma2(text1.GLindex, 0);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//techo
			glTranslatef(0,20,0);
			glScalef(80,0.1,46);
			glDisable(GL_LIGHTING);
			toFloor.prisma2(text2.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();//puerta
			glDisable(GL_LIGHTING);
			
			
			glTranslatef(7,7.5,3);
			glRotatef(rotPuerta,0,1,0);
			glTranslatef(3.5,0,0);
			puerta();
			//glTranslatef(10.5,7.5,3);
			puerta();
			
			glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix();//muro A
			//glTranslatef(-16,0,3);
			glDisable(GL_LIGHTING);
			
			glEnable(GL_ALPHA_TEST);//habilita transparencia
			glAlphaFunc(GL_GREATER,0.1);//tolerancia de que será transparente y que no
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_DST_COLOR);//translucido
			glBindTexture(GL_TEXTURE_2D,text3.GLindex);
			
			glBegin(GL_QUADS);
				glNormal3f(0,0,1);
				glTexCoord2f(0,0); glVertex3f(-40,0,3);
				glTexCoord2f(5,0); glVertex3f(7,0,3);
				glTexCoord2f(5,1); glVertex3f(7,20,3);
				glTexCoord2f(0,1); glVertex3f(-40,20,3);

			glEnd();
			glDisable(GL_ALPHA_TEST);
			glDisable(GL_BLEND);
			glEnable(GL_LIGHTING);
		glPopMatrix();
			
		glPushMatrix();//muro Arriba
			//glTranslatef(-16,0,3);
			glDisable(GL_LIGHTING);
			
			glEnable(GL_ALPHA_TEST);//habilita transparencia
			glAlphaFunc(GL_GREATER,0.1);//tolerancia de que será transparente y que no
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_DST_COLOR);//translucido
			glBindTexture(GL_TEXTURE_2D,text3.GLindex);
			
	
			glBegin(GL_QUADS);
				glNormal3f(0,0,1);
				glTexCoord2f(0,0); glVertex3f(7,15,3);
				glTexCoord2f(1,0); glVertex3f(14,15,3);
				glTexCoord2f(1,1); glVertex3f(14,20,3);
				glTexCoord2f(0,1); glVertex3f(7,20,3);

			glEnd();
			glDisable(GL_ALPHA_TEST);
			glDisable(GL_BLEND);
			glEnable(GL_LIGHTING);
		glPopMatrix();

		
		glPushMatrix();//muro B
			glDisable(GL_LIGHTING);
			
			glEnable(GL_ALPHA_TEST);//habilita transparencia
			glAlphaFunc(GL_GREATER,0.1);//tolerancia de que será transparente y que no
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_DST_COLOR);//translucido
			glBindTexture(GL_TEXTURE_2D,text3.GLindex);
			
			glBegin(GL_QUADS);
				glNormal3f(0,0,1);
				glTexCoord2f(0,0); glVertex3f(14,0,3);
				glTexCoord2f(3,0); glVertex3f(40,0,3);
				glTexCoord2f(3,1); glVertex3f(40,20,3);
				glTexCoord2f(0,1); glVertex3f(14,20,3);

			glEnd();
			glDisable(GL_ALPHA_TEST);
			glDisable(GL_BLEND);
			glEnable(GL_LIGHTING);
		glPopMatrix();
	glPopMatrix();
}

void Oficina::sillasSalajuntas(){
	glPushMatrix();
		glTranslatef(3,2.2,-3);
		glScalef(1,0.8,1);
		elem.sillaBlanca();
	glPopMatrix();
		
	glPushMatrix();
		glTranslatef(3,2.2,3);
		glRotatef(180,0,1,0);
		glScalef(1,0.8,1);
		elem.sillaBlanca();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-3,2.2,3);
		glRotatef(180,0,1,0);
		glScalef(1,0.8,1);
		elem.sillaBlanca();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-3,2.2,-3);
		glScalef(1,0.8,1);
		elem.sillaBlanca();
	glPopMatrix();

}

void Oficina::mesa1Godinez(){

	glPushMatrix();//primer mesa blanca sala godinez
	glTranslatef(-43,-2,9.5);
	glPushMatrix();
		glScalef(0.55,0.95,0.65);
		mesBla.setMesa();
	glPopMatrix();

	glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(0,5,-2.5);
		glRotatef(80,0,1,0);
		glScalef(0.8,0.8,0.8);
		escr.setMac();
		glEnable(GL_LIGHTING);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(5,2,0);
		glRotatef(-90,0,1,0);
		elem.sillaAzul();
	glPopMatrix();
	glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(18,0.9,0);
		glRotatef(-90,0,1,0);
		est.creaEstante1();
		glEnable(GL_LIGHTING);
	glPopMatrix();
glPopMatrix();

}
void Oficina::mesa2Godinez(){

	//segunda mesa blanca sala godinez
glPushMatrix();
	glTranslatef(-9,-2.6,9);
	glPushMatrix();
		glScalef(1,0.9,0.6);
		mesBla.divisor(1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-7,2.5,0);
		glRotatef(90,0,1,0);
		elem.sillaAzul();
	glPopMatrix();
		
	glPushMatrix();
		glTranslatef(7,2.5,0);
		glRotatef(-90,0,1,0);
		elem.sillaAzul();
	glPopMatrix();
	
	glPushMatrix();///mac///////////
		glDisable(GL_LIGHTING);
		glTranslatef(-3,4.5,2);
		glRotatef(-100,0,1,0);
		glScalef(0.8,0.8,0.8);
		escr.setMac();
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();///mac///////////
		glDisable(GL_LIGHTING);
		glTranslatef(3,4.5,-2);
		glRotatef(80,0,1,0);
		glScalef(0.8,0.8,0.8);
		escr.setMac();
		glEnable(GL_LIGHTING);
	glPopMatrix();
		

	glPushMatrix();
		glDisable(GL_LIGHTING);
		glTranslatef(20,1.1,0);
		glRotatef(-90,0,1,0);
		est.creaEstante1();
		
		glEnable(GL_LIGHTING);
	glPopMatrix();
glPopMatrix();

}
void Oficina::mesa3Godinez(){

//tercera mesa blanca sala godinez
	glPushMatrix();
		glTranslatef(27.2,-2.6,9);
		glPushMatrix();
			glScalef(1,0.9,0.6);
			mesBla.divisor(1);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-7,2.5,0);
			glRotatef(90,0,1,0);
			elem.sillaAzul();
		glPopMatrix();
		glPushMatrix();///macbook///////////
			glDisable(GL_LIGHTING);
			glTranslatef(-3,5.7,2);
			glRotatef(80,0,1,0);
			glScalef(1.9,1.7,1.9);
			escr.setMacBook();
			glEnable(GL_LIGHTING);
		glPopMatrix();
		
		glPushMatrix();///mac///////////
			glDisable(GL_LIGHTING);
			glTranslatef(3,4.5,-2);
			glRotatef(80,0,1,0);
			glScalef(0.8,0.8,0.8);
			escr.setMac();
			glEnable(GL_LIGHTING);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(7,2.5,0);
			glRotatef(-90,0,1,0);
			elem.sillaAzul();
		glPopMatrix();
	
		glPushMatrix();
		glDisable(GL_LIGHTING);
			glTranslatef(20,1.1,0);
			glRotatef(-90,0,1,0);
			est.creaEstante1();
			///plantita
			glTranslatef(-2,2,2);
			glScalef(0.1,0.1,0.1);
			jar.Maceta();
			glEnable(GL_LIGHTING);
		glPopMatrix();
	glPopMatrix();
	

}

void Oficina::setOffice(){
	
	//mesa1Godinez();
	//mesa2Godinez();
	//mesa3Godinez();
///////////////fin sala godinez
/////////sala juntas 

	glPushMatrix();///sala de juntas
		glTranslatef(-22,-3,-18.5);
		glPushMatrix();
			glScalef(1.2,1.6,1.4);
			mesBla.setMesaJuntas();
		glPopMatrix();
		 ////sillas, las comentamos porque al momento de ejecutar, todo se alenta
		//sillasSalajuntas();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-10,-3,-18.5);
		glPushMatrix();
			glRotatef(180,0,1,0);
			glScalef(1.2,1.6,1.4);
			mesBla.setMesaJuntas();
		glPopMatrix();
		 ////sillas
		//sillasSalajuntas();
	glPopMatrix();
	
	glPushMatrix();///sala del mero mero
		glTranslatef(-2,0,3);
		glPushMatrix();
			glTranslatef(33,-8.3,-27.2);
			glPushMatrix();
				glScalef(1,2.7,1.1);
				mesBla.setEscritorio();
			glPopMatrix();
			glRotatef(-90,0,1,0);
			glTranslatef(9,13,-15);
			glScalef(1,0.8,1);
			est.creaLibrero();		
		glPopMatrix();

	
		glPushMatrix();
			glTranslatef(25,-3,-23.3);
			glRotatef(90,0,1,0);
			glScalef(1.5,1.6,1.2);
			mesBla.setMesaJuntas();
			glPushMatrix();
				glTranslatef(-1,2,3);
				glRotatef(180,0,1,0);
				glScalef(0.8,0.6,0.8);
				elem.sillaBlanca();
			glPopMatrix();
			glPushMatrix();
				glDisable(GL_LIGHTING);
				glTranslatef(2,3.30,1.4);
				elem.setLampara();
				glTranslatef(-4,0.9,-1);
				glRotatef(180,0,1,0);
				glScalef(1.8,1.6,1.8);
				escr.setMacBook();
				glEnable(GL_LIGHTING);
			glPopMatrix();
		glPopMatrix();

		

	glPopMatrix();
	
	glPushMatrix();
		glScalef(1.2,1,1);
		piso();
	glPopMatrix();
}

void Oficina::puerta(){
	glPushMatrix();
		toFloor.prisma(15,7,0.5,text4.GLindex);
		glRotatef(90,1,0,0);
		glTranslatef(2.5,0,0);
		toFloor.cilindro(0.25,0.3,14,text5.GLindex);
		glTranslatef(0,0.3,0);
		toFloor.cilindro(0.1,0.3,14,text5.GLindex);
		glTranslatef(0,0.3,0);
		glRotatef(rotPerilla,0,1,0);
		toFloor.esfera(0.1,14,14,text5.GLindex);
		glRotatef(90,0,0,1);
		toFloor.cilindro(0.15,0.9,14,text5.GLindex);

	glPopMatrix();
}