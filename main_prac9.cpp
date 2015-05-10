//Semestre 2015 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//

#include "Elementos.h"
//#include "figuras.h"
#include "Camera.h"
#include "Audio.h"

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
CCamera objCamera; 

Elementos silla;
Oficina of;

Jardineras jardin;
Torres torre;

int flgL;
int flgP;

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 
//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

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

	//silla.Init();
	///////////////////////////////////////////////////////////////////////////////

	cielo.LoadBMP("Construccion/01.bmp");
	cielo.BuildGLTexture();
	cielo.ReleaseImage();

	suelo.LoadTGA("Construccion/pavQuad.tga");
	suelo.BuildGLTexture();
	suelo.ReleaseImage();



	text5.LoadTGA("pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();


	quadratic=gluNewQuadric();			// Create A Pointer To The Quadric Object ( NEW )
	gluQuadricNormals(quadratic, GLU_SMOOTH);	// Create Smooth Normals ( NEW )
	gluQuadricTexture(quadratic, GL_TRUE);		// Create Texture Coords ( NEW )


	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);//inizializa la camara//posoicion, vista,inclinación

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

		case 'f':		//
		case 'F':
			
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
