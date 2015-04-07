#include "texture.h"//librería donde están las definiciones de los métodos y la otra librería necesaria para 
//ejecutar sentencias
//como en C
//int funcion();//en lugar de escribir la definicion aquí, la escribimos en el texture.h para que podamos usar este .cpp en otros

//main(){
//....
//}

//int funcion(){
//...
//}

void MacEscritorio::Init(GLvoid){//<tipo de dato> <clase a la que pertenece>::<definición de la función>
	//como la definición de la clase y de los métodos la hicimos en texture.h, debemos enlazar la definición de clase y método con el
	//código que tenemos aquí por eso usamos ese formato
	t_escudo.LoadTGA("texturas/mac_escudo.tga");
	t_escudo.BuildGLTexture();
	t_escudo.ReleaseImage();

	t_gris.LoadTGA("texturas/mac_gris.tga");
	t_gris.BuildGLTexture();
	t_gris.ReleaseImage();

	t_manzana.LoadTGA("texturas/manzana.tga");
	t_manzana.BuildGLTexture();
	t_manzana.ReleaseImage();

	t_display.LoadTGA("texturas/display.tga");
	t_display.BuildGLTexture();
	t_display.ReleaseImage();

}

void MacEscritorio::prisma (GLuint textura1, GLuint textura2)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};
		
		   // choose the texture to use.
		//glBindTexture(GL_TEXTURE_2D, 0);   // choose the texture to use.
		glBindTexture(GL_TEXTURE_2D, textura1);
		glBegin(GL_POLYGON);	//Front
			//glColor3f(0.0,0.0,1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
		glEnd();
	
		glBindTexture(GL_TEXTURE_2D, textura2);
		glBegin(GL_POLYGON);	//Right
			//glColor3f(0.0,0.0,1.0);
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			//glColor3f(0.0,1.0,0.0);
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			//glColor3f(1.0,1.0,1.0);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			//glColor3f(0.4,0.2,0.6);
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		   // choose the texture to use.
		glBegin(GL_POLYGON);  //Top
			//glColor3f(0.8,0.2,0.4);
			glColor3f(1.0,1.0,1.0);
			/*glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);*/
			glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
		glEnd();
}
void MacEscritorio::desktop(GLuint textura1){
	GLfloat vertex [4][3]={{0.5,-0.5,-0.251},
							{-0.5,-0.5,-0.251},
							{-0.5,0.5,-0.251},
							{0.5,0.5,-0.251},
							};
	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);  //Display
			//glColor3f(0.0,0.0,0.0);
			glNormal3f( 0.0f,-1.0f, 0.0f);
			 glTexCoord2f(0.0, 0.0f);glVertex3fv(vertex[0]);
			 glTexCoord2f(1.0, 0.0f);glVertex3fv(vertex[1]);
			 glTexCoord2f(1.0, 1.0f);glVertex3fv(vertex[2]);
			 glTexCoord2f(0.0, 1.0f);glVertex3fv(vertex[3]);
	glEnd();
}

void MacEscritorio::respaldo(GLuint textura){
	glPushMatrix();
		glScalef(3.0,0.1,1);
		prisma(textura,textura);
	glPopMatrix();
	glTranslatef(0,0.01,-0.5);
	glRotatef(25,1,0,0);
	glPushMatrix();
		glScalef(3.0,0.1,0.1);
		prisma(textura,textura);
	glPopMatrix();
	glTranslatef(0,0.01,-0.05);
	glRotatef(25,1,0,0);
	glPushMatrix();
		glScalef(3.0,0.1,0.1);
		prisma(textura,textura);
	glPopMatrix();
	glTranslatef(0,0.01,-0.05);
	glRotatef(25,1,0,0);
	glPushMatrix();
		glScalef(3.0,0.1,0.1);
		prisma(textura,textura);
	glPopMatrix();
	glTranslatef(0,0.01,-0.05);
	glRotatef(25,1,0,0);
	glPushMatrix();
		glScalef(3.0,0.1,0.1);
		prisma(textura,textura);
	glPopMatrix();
	glTranslatef(0,0.01,-0.05);
	glRotatef(25,1,0,0);
	glPushMatrix();
		glScalef(3.0,0.1,0.1);
		prisma(textura,textura);
	glPopMatrix();
	glTranslatef(0,0.0,-0.375);
	glPushMatrix();
		glScalef(3.0,0.1,0.75);
		prisma(textura,textura);
	glPopMatrix();

}
void MacEscritorio::setMac(){
	//Init();
	glPushMatrix();//mandamos el respaldo
		glScalef(0.75,3,3);
		respaldo(t_gris.GLindex);
	glPopMatrix();
	glPushMatrix();
		glRotatef(180,0,1,0);
		glRotatef(25,1,0,0);
		glTranslatef(0,3.0,-0.9);
		glPushMatrix();
			glScalef(6.0,4.0,0.5);//mandamos el monitor
			prisma(t_escudo.GLindex, t_gris.GLindex);

		glPopMatrix();

		glPushMatrix();
			glTranslatef(0,0.25,0);
			glScalef(6,3.5,1);//mandamos el display
			desktop(t_display.GLindex);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0,-1.75,0);
			glScalef(0.5,0.5,1);//mandamos la manzana
			desktop(t_manzana.GLindex);
		glPopMatrix();
	glPopMatrix();

}