//Semestre 2015 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//

#include "Elementos.h"
#include "Camera.h"
#include "Audio.h"
#include "cmodel/CModel.h"

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

#define MAX_FRAMES 5
int i_max_steps = 90;//indica cuadros intermedios
int i_curr_steps = 0;

CCamera objCamera; 

Elementos silla;
Oficina of;

CModel kit;
CModel llanta;

int flg;

///para kit//////////////////////////7
float posX =12;
float posY = -13.0;
float posZ =10.5;

float angRotTires = 0.0;
float angRotKit=0.0;
float rotTires = 0.0;

typedef struct _frame{
	float posX ;
	float incX;
	float posY;
	float incY;
	float posZ;
	float incZ;

	float angRotTires;
	float angRotTiresInc;

	float angRotKit;
	float angRotKitInc;

	float rotTires;
	float rotTiresInc;

}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex=0;			//introducir datos
bool play=false;
int playIndex=0;

int w = 500, h = 500;
int frame=0,time,timebase=0;
char s[30];

///////////////////////////////////////////
Jardineras jardin;
Torres torre;

int flgL;
int flgP;

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 
//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
/// transiciones/////////////////////////////////77
int horas=0;

bool noche = false;
bool tarde = false;
bool amanecer = false;
bool dia = true;
bool lluvioso = false;
///////////////////////////////////////////
int font=(int)GLUT_BITMAP_HELVETICA_18;

//Otras opciones son:
/*GLUT_BITMAP_8_BY_13
GLUT_BITMAP_9_BY_15
GLUT_BITMAP_TIMES_ROMAN_10
GLUT_BITMAP_TIMES_ROMAN_24
GLUT_BITMAP_HELVETICA_10
GLUT_BITMAP_HELVETICA_12
GLUT_BITMAP_HELVETICA_18*/



GLUquadricObj *quadratic;				// Storage For Our Quadratic Objects ( NEW )


//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = {18};

GLfloat m_dif2[] = { 0.8f, 0.2f, 0.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec2[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb2[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s2[] = {22};

CTexture cielo;
CTexture suelo;
CTexture Ddia;
CTexture Nnoche;
CTexture Ttarde;
CTexture Aamanecer;
CTexture Lluvioso;

CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;

float colorR = 0.0;
float colorG = 0.0;
float colorB = 0.0;

bool g_fanimacion = false;

void framesKit(){
	///frame 1
	FrameIndex=0;
	KeyFrame[FrameIndex].posX=12;
	KeyFrame[FrameIndex].posY=-13;
	KeyFrame[FrameIndex].posZ=10.5;
	KeyFrame[FrameIndex].angRotKit=0;
	KeyFrame[FrameIndex].angRotTires=0;
	KeyFrame[FrameIndex].rotTires=0;
	FrameIndex++;
	///frame 2
	KeyFrame[FrameIndex].posX=14;
	KeyFrame[FrameIndex].posY=-7;
	KeyFrame[FrameIndex].posZ=10.5;
	KeyFrame[FrameIndex].angRotKit=0;
	KeyFrame[FrameIndex].angRotTires=90;
	KeyFrame[FrameIndex].rotTires=270;
	FrameIndex++;
	// frame 3
	KeyFrame[FrameIndex].posX=30;
	KeyFrame[FrameIndex].posY=7;
	KeyFrame[FrameIndex].posZ=0.5;
	KeyFrame[FrameIndex].angRotKit=0;
	KeyFrame[FrameIndex].angRotTires=90;
	KeyFrame[FrameIndex].rotTires=180;
	FrameIndex++;
	// frame 4
	KeyFrame[FrameIndex].posX=39;
	KeyFrame[FrameIndex].posY=-7;
	KeyFrame[FrameIndex].posZ=10.5;
	KeyFrame[FrameIndex].angRotKit=0;
	KeyFrame[FrameIndex].angRotTires=90;
	KeyFrame[FrameIndex].rotTires=270;
	FrameIndex++;
	// frame 5
	flg=1;
	KeyFrame[FrameIndex].posX=39;
	KeyFrame[FrameIndex].posY=-7;
	KeyFrame[FrameIndex].posZ=10.5;
	KeyFrame[FrameIndex].angRotKit=0;
	KeyFrame[FrameIndex].angRotTires=90;
	KeyFrame[FrameIndex].rotTires=180;
	FrameIndex++;
	//frame 6
	KeyFrame[FrameIndex].posX=39;
	KeyFrame[FrameIndex].posY=-13;
	KeyFrame[FrameIndex].posZ=10.5;
	KeyFrame[FrameIndex].angRotKit=0;
	KeyFrame[FrameIndex].angRotTires=0;
	KeyFrame[FrameIndex].rotTires=270;
	FrameIndex++;
	flg=0;
}

void InitGL ( )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	//Para construir la figura comentar esto
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);

	//glEnable ( GL_COLOR_MATERIAL );
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//glPolygonMode(GL_BACK, GL_LINE);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
    //glBlendFunc(GL_SRC_ALPHA,GL_ONE);			// Set The Blending Function For Translucency
    //glColor4f(1.0f, 1.0f, 1.0f, 0.5); 
    
	///////////////////////////////////////////////////////////////////////////////
	of.Init();

	jardin.Init();
	torre.Init();

	kit._3dsLoad("kitt.3ds");	
	//kit.VertexNormals();
	
	llanta._3dsLoad("k_rueda.3ds");
	//silla.Init();
	///////////////////////////////////////////////////////////////////////////////

	cielo.LoadBMP("Construccion/01.bmp");
	cielo.BuildGLTexture();
	cielo.ReleaseImage();

	Ddia.LoadBMP("Construccion/01.bmp");
	Ddia.BuildGLTexture();
	Ddia.ReleaseImage();

	Ttarde.LoadTGA("Construccion/tarde.tga");
 	Ttarde.BuildGLTexture();
 	Ttarde.ReleaseImage();

	Nnoche.LoadTGA("Construccion/noche.tga");
 	Nnoche.BuildGLTexture();
 	Nnoche.ReleaseImage();
	
	Aamanecer.LoadTGA("Construccion/amanecer.tga");
 	Aamanecer.BuildGLTexture();
 	Aamanecer.ReleaseImage();

	suelo.LoadTGA("Construccion/pavQuad.tga");
	suelo.BuildGLTexture();
	suelo.ReleaseImage();

	Lluvioso.LoadTGA("Construccion/nublado.tga");
 	Lluvioso.BuildGLTexture();
 	Lluvioso.ReleaseImage();

	text5.LoadTGA("pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	framesKit();

	quadratic=gluNewQuadric();			// Create A Pointer To The Quadric Object ( NEW )
	gluQuadricNormals(quadratic, GLU_SMOOTH);	// Create Smooth Normals ( NEW )
	gluQuadricTexture(quadratic, GL_TRUE);		// Create Texture Coords ( NEW )


	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);//inizializa la camara//posoicion, vista,inclinación

}

void kittModel(){
	glPushMatrix();
		//if(flg==1)
			glRotatef(angRotKit, 0, 1, 0);
		glScalef(0.3, 0.3, 0.3);
		//Pongo aquí la carroceria del carro
		//glDisable(GL_LIGHTING);
		kit.GLrender(NULL,_SHADED,1.0);  //_WIRED O _POINTS
		//glEnable(GL_LIGHTING);
		//_SHADED es para entero
		//_WIRED es para lineas
		//Poner aquí las llanta
		glPushMatrix();
			glTranslatef(-6.4,-1.1,7.7);
			glRotatef(angRotTires,0,0,1);
			glRotatef(rotTires,1,0,0);
			llanta.GLrender(NULL,_SHADED,1.0);//llanda del der
		glPopMatrix();

		glPushMatrix();
			glTranslatef(6.4,-1.1,7.7);
			glRotatef(180,0,1,0);
			glRotatef(angRotTires,0,0,1);
			glRotatef(-rotTires,1,0,0);
			llanta.GLrender(NULL,_SHADED,1.0);//llanda del izq
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-6.4,-1.1,-9.5);
			glRotatef(angRotTires,0,0,1);
			glRotatef(rotTires,1,0,0);
			llanta.GLrender(NULL,_SHADED,1.0);//llanda tras der
		glPopMatrix();

		glPushMatrix();
			glTranslatef(6.4,-1.1,-9.5);
			glRotatef(180,0,1,0);
			glRotatef(angRotTires,0,0,1);
			glRotatef(-rotTires,1,0,0);
			llanta.GLrender(NULL,_SHADED,1.0);//llanda tras izq
		glPopMatrix();

	glPopMatrix();

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
		
	glPushMatrix();

	glScalef(2,1,1.2);
	glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

			glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				fig1.skybox(150.0, 150.0, 130.0,cielo.GLindex, suelo.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			
			//Poner figuras aqui
			/////////////////////////////////////////////
			glPushMatrix();
				glTranslatef(posX,posY,posZ);
				//glRotatef(angRotKit,0,1,0);
				kittModel();
			/////////////////////////////////////////////
			glPopMatrix();
			glDisable(GL_LIGHTING);//sólo para ver mejor las figuras
			glTranslatef(0,-9,-10);
			//********************
			glPushMatrix();//////////////////////////////////////////////oficina
				glTranslatef(18,-2.8,-1.4);
				glScalef(0.185,0.49,0.39);
				of.setOffice();
				//of.piso();
			glPopMatrix();
			//edificio
			glPushMatrix();
				glDisable(GL_LIGHTING);
				glScalef(1.8,1,1.8);
				torre.creaEdificio();
				//++++++
				//creamos cristales de edificio
				glEnable(GL_LIGHTING);
			glPopMatrix();
			//***********************
			//jardineras con árbol
			//para el sistema local de esta jardinera eje z local-> x global
			glDisable(GL_LIGHTING);
			glPushMatrix();
				glTranslatef(-50,-5,-35);
				glPushMatrix();
					glRotatef(90,0,1,0);
					glScalef(1.8,1.2,1.4);
					jardin.setJardineraArbolIzq();
					glPopMatrix();
				glPushMatrix();
					glTranslatef(100,0,0);
					glRotatef(-90,0,1,0);
					glScalef(1.8,1.2,1.4);
					jardin.setJardineraArbolDer();
					glPopMatrix();
			glPopMatrix();
			
			//*************************
			//jardineras básicas
				glPushMatrix();
					glTranslatef(-50,-5,-20);
					jardin.JardineraBase(1.2,15,30);//altura, largo, profundidad
					glTranslatef(100,0,-15);
					glRotatef(180,0,0,1);
					jardin.JardineraBase(1.2,15,30);
					glPopMatrix();
			//******************************
				//jardineras con pino
				glPushMatrix();
					glTranslatef(-48,-3.5,20);
					glPushMatrix();
						glRotatef(-90,0,1,0);
						glScalef(1,1,1.5);
						jardin.setJardineraPinoIzq();
						glPopMatrix();
					glTranslatef(98,-3,0);
					glRotatef(90,0,1,0);
					glScalef(1,1,1.5);
					jardin.setJardineraPinoDer();
					glPopMatrix();
			//********************************
					//jardineras frontales irregulares
				glPushMatrix();
					glTranslatef(-20,-7,40);
					glPushMatrix();
						glScalef(3.7,1.2,3.5);
						jardin.JardineraPino();
						glPopMatrix();
					glTranslatef(40,3.5,0);
					glRotatef(180,0,0,1);
					glScalef(3.7,1.2,3.5);
					jardin.JardineraPino();
					glPopMatrix();
			//*****************************
					//jardineras frontales
				glPushMatrix();
					glPushMatrix();
					glTranslatef(12,-5,5);
						glScalef(15,1,5);
						jardin.jardinerasFrontales();
						glPopMatrix();
					glPushMatrix();
						glTranslatef(-12,-5,5);
						glRotatef(180,0,0,1);
						glScalef(15,1,5);
						jardin.jardinerasFrontales();
						glPopMatrix();
				glPopMatrix();
		//****************************
				//glPushMatrix();
					//glTranslatef(2,0,0);
					//glScalef(10,5,10);
					//torre.vestibulo();
					//glPopMatrix();

			//************************

				//Vestibulo
				glPushMatrix();
					glTranslatef(0,-5,10.5);
					glScalef(0.45,1,0.3);
					torre.parteTrasera();
					glPopMatrix();
				if (lluvioso){
 					glScalef(3,3,3);
 					torre.lluvia();
 				}
		

			glEnable(GL_LIGHTING);
			//glScalef(0.1,0.1,0.1);
			//

		glPopMatrix();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
			glColor3f(1.0,0.0,0.0);
			pintaTexto(-0.25,0.23,-0.25,(void *)font,"Proyecto Final");
			pintaTexto(-0.25,0.21,-0.25,(void *)font,"Oficinas");
			glColor3f(1.0,1.0,1.0);
		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

}

void animacion()
{
	fig3.text_izq-= 0.01;
	fig3.text_der-= 0.01;
	if(fig3.text_izq<-1)
		fig3.text_izq=0;
	if(fig3.text_der<0)
		fig3.text_der=1;
	glutPostRedisplay();
	if(g_fanimacion){
		if(flgL==1){
			of.elem.rotateL++;
			if(of.elem.getRotateLamp()>=50)
				flgL=2;
		}
		else if(flgL==2){
			of.elem.rotateL--;
			if(of.elem.getRotateLamp()<=-60)
				flgL=3;
		}
		else if(flgL==3){
			of.elem.rotateL++;
			if(of.elem.getRotateLamp()>=20)
				flgL=4;
		}
		else if(flgL==4){
			of.elem.rotateL--;
			if(of.elem.getRotateLamp()<=0)
				flgL=5;
		}
		else if(flgP==1){
			of.rotPerilla++;
			if(of.rotPerilla>=50)
				flgP=2;
		}
		else if(flgP==2){
			of.rotPuerta++;
			if(of.rotPuerta>=90)
				flgP=3;
		}
		else if(flgP==3){
			of.rotPerilla--;
			if(of.rotPerilla<=0)
				flgP=4;
		}
		else if(flgP==4){
			of.rotPuerta--;
			if(of.rotPuerta<=0)
				flgP=5;
		}
		else g_fanimacion=false;

	}
	/////////////////////////key Frames

	if(play)
	{		
		
		if(	i_curr_steps >= i_max_steps) //end of animation between frames?
		{			
			playIndex++;		
			if(playIndex>FrameIndex-2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex=0;
				play=false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
				//Interpolation
				KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;		//
				KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;		//
				KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;		//
				KeyFrame[playIndex].angRotKitInc = (KeyFrame[playIndex + 1].angRotKit - KeyFrame[playIndex].angRotKit) / i_max_steps;		//

				KeyFrame[playIndex].angRotTiresInc = (KeyFrame[playIndex + 1].angRotTires - KeyFrame[playIndex].angRotTires) / i_max_steps;		//
				KeyFrame[playIndex].rotTiresInc = (KeyFrame[playIndex + 1].rotTires - KeyFrame[playIndex].rotTires) / i_max_steps;		//

			}
		}
		else//manda a dibujar la información
		{
			posX+=KeyFrame[playIndex].incX;
			posY+=KeyFrame[playIndex].incY;
			posZ+=KeyFrame[playIndex].incZ;
			angRotKit+=KeyFrame[playIndex].angRotKit;

			angRotTires += KeyFrame[playIndex].angRotTiresInc;
			rotTires+= KeyFrame[playIndex].rotTiresInc;

			i_curr_steps++;
		}
		
	}

	frame++;
	time=glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(s,"FPS:%4.2f",frame*1000.0/(time-timebase));
		timebase = time;		
		frame = 0;
	}

	glutPostRedisplay();

	//////////////////////////////////////

	/////////////// tarde noche ///////////////

	if (tarde){
 		horas++;
 		/*cielo.LoadTGA("Construccion/tarde.tga");
 		cielo.BuildGLTexture();
 		cielo.ReleaseImage();*/
		cielo=Ttarde;
 		if(horas == 60){
 			tarde= false;
 			noche = true;
 			horas = 0;
 		}
	}
	if(noche){
 		horas++;
		/*
 		cielo.LoadTGA("Construccion/noche.tga");
 		cielo.BuildGLTexture();
 		cielo.ReleaseImage();*/
		cielo=Nnoche;
 		if(horas == 60){
 			noche= false;
 			amanecer = true;
 			horas = 0;
 		}
	}
	if(amanecer){
 		horas++;
		/*
 		cielo.LoadTGA("Construccion/amanecer.tga");
 		cielo.BuildGLTexture();
 		cielo.ReleaseImage();*/
		cielo=Aamanecer;
 		if(horas == 60){
 			amanecer= false;
 			dia = true;
 			horas= 0;
 		}
 	}
	if(dia){
		/*
 		cielo.LoadBMP("Construccion/01.bmp");
 		cielo.BuildGLTexture();
 		cielo.ReleaseImage();*/
		cielo=Ddia;
 	}

	if(lluvioso){
 		/*cielo.LoadTGA("Construccion/nublado.tga");
 		cielo.BuildGLTexture();
 		cielo.ReleaseImage();*/
 		cielo=Lluvioso;
 		torre.offset -= 0.002;
 	//torre.lluvia();
 	 
 		if (torre.offset > 1.0){
 			torre.offset = 0.0;
 		}
	}

	///////////////////////////////////


}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'r':		//
		case 'R':
			
			break;

			
		//////////////// agregando nuevas animaciones
		case 'F': 
 			noche = false;
 			tarde = false;
 			amanecer = false;
 			dia = true;
 			break;
 		case 'f':
 			tarde = true;
 			dia = false;
 			break;
 		case 'p':
 			lluvioso=true;
 			dia= false;
 			break;
 		case 'P':
 			lluvioso=false;
 			dia = true;
 			//fig1.offset = 0;
 			torre.offset = 0;
 			break;

 		case 'L':	//vista frontal:D
 		case 'l':
 			objCamera.Position_Camera(0,-5,20, 0, 0, 0, 0, 1, 0);//inizializa la camara//posicion, vista,inclinación
 			break;
 		case 'J':	//vista a la oficina:D
 		case 'j':
 			objCamera.Position_Camera(10,-10,-10, 20, -7, -20, -0,1, 0);//inizializa la camara//posicion, vista,inclinación
 			break;
 		case 'K':	//vista departamento :D
 		case 'k':
 			objCamera.Position_Camera(-10,-10,-10, -20, -7, -20, 0, 1, 0);//inizializa la camara//posicion, vista,inclinación
 			break;
 		case 'I':	//vista isometrica :D
 		case 'i':
 			objCamera.Position_Camera(30,50,10, 0, 0, 0, 0, 1, 0);//inizializa la camara//posicion, vista,inclinación
 			break;
		
		case '1':		//
			g_fanimacion^=true;
			flgL=1;
			flgP=5;
			break;
		case '2':
			g_fanimacion^=true;
			flgP=1;
			flgL=5;
			break;

		case '3':
			// posX =10;
			// posY = -13.0;
			// posZ =10.5;
			if(play==false && FrameIndex>1)
			{
				posX=KeyFrame[0].posX;
				posY=KeyFrame[0].posY;
				posZ=KeyFrame[0].posZ;

				angRotKit=KeyFrame[0].angRotKit;
				angRotTires=KeyFrame[0].angRotTires;
				rotTires=KeyFrame[0].rotTires;


				//First Interpolation
				KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;		//
				KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;		//
				KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;		//
				KeyFrame[playIndex].angRotKitInc = (KeyFrame[playIndex + 1].angRotKit - KeyFrame[playIndex].angRotKit) / i_max_steps;		//


				KeyFrame[playIndex].angRotTiresInc = (KeyFrame[playIndex + 1].angRotTires - KeyFrame[playIndex].angRotTires) / i_max_steps;		//
				KeyFrame[playIndex].rotTiresInc = (KeyFrame[playIndex + 1].rotTires - KeyFrame[playIndex].rotTires) / i_max_steps;		//

				play=true;
				playIndex=0;
				i_curr_steps = 0;
			}
			else
			{
				play=false;
			}
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		//pos_camY -= 0.5f;
		//pos_cam.y += 0.5f;
		//eye_cam.y += 0.5f;
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		//pos_camY += 0.5f;
		//pos_cam.y -= 0.5f;
		//eye_cam.y -= 0.5f;
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  setAudio();
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 9"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}
