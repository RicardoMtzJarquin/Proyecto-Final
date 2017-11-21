//Semestre 2018 - 1
//************************************************************//
//***   Proyecto Final            Recorrido             ******//
//*** 	Alumno (s):                                     ******//
//***			Martinez Jarquin Ricardo Eduardo        ******//
//***			Salgado Salazar Carlos Eduardo          ******//
//***                                                   ******//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "cmodel/CModel.h"
//Solo para Visual Studio 2015
#if (_MSC_VER == 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;

//NEW// Keyframes
float posX = 0, posY = 2.5, posZ = -3.5, rotRodIzq = 0;
float giroMonito = 0;
float movBrazoDer = 0.0;

#define MAX_FRAMES 9
int i_max_steps = 90;
int i_curr_steps = 0;
typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float rotRodIzq;
	float rotInc;
	float giroMonito;
	float giroMonitoInc;
	float movBrazoDer;
	float movBrazoDerInc;


}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 5;			//introducir datos
bool play = false;
int playIndex = 0;

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////


CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position


//////////////////////////////////          Carga de texturas //////////////////////////////////////////////////
CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture tree;
CTexture ambiente;
CTexture ambiente2;
CTexture pasto;
CTexture muro;
CTexture madera;
CTexture puerta;
CTexture cuadro;
CTexture colchon;
CTexture oxido;
CTexture help;
CTexture blood;
CTexture raya;
CTexture mono;
CTexture piso_casa;
CTexture neblina;
CTexture neblina1;
CTexture trans;
CTexture wall;
CTexture piso;
CTexture door;
CTexture wood;
CTexture ventana;
CTexture ventan_arriba;
CTexture vela;
CTexture penta;
CTexture cuadro1;
CTexture cuadro2;
CTexture cuadro3;
CTexture madera_cama;
CTexture pasaje;
CTexture bruja;
CTexture bruja2;
CTexture sangre_tortura;
CTexture woodS;
CTexture carne;
////////////////////////////////////////     Carga de Figuras   //////////////////////////////////////////////
CFiguras sky;
CFiguras prisma;
CFiguras fig7;	//Para crear Monito
///////////////////////////////////////     Carga de modelos 3ds ///////////////////////////////////////////////
CModel kit;
CModel FEMUR;
/////////////////////////////////////////////   Funciones PROPIAS    ///////////////////////////////////////////


/////////////////////////////////////////////7  Animaciones del Carro y variables del monito //////////////////////77
//Animación del coche

float giroruedas = 0;

float angRot = 0.0;
float movKitX = -50;
float movKitY = 0;
float movKitZ = -60;
float rotKit = 0.0;
float portal = 0.0;
float contador = 0.0;
float brujax = 53.0;
float brujay = 80.0;
float brujaz = 50.0;

bool circuito = false;
bool recorrido1 = true;
bool recorrido2 = false;
bool recorrido3 = false;
bool recorrido4 = false;
bool recorrido5 = false;

bool recorrido6 = false;
bool recorrido7 = false;
bool recorrido8 = false;
bool recorrido9 = false;
bool recorrido10 = false;


void plano(GLint text) {
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off

	glAlphaFunc(GL_GREATER, 0.1);
	//glEnable(GL_BLEND);     // Turn Blending On
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, text);
	glBegin(GL_QUADS); //plano
	//glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

}

void dosde(GLint text)
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
	glAlphaFunc(GL_GREATER, 0.1);
	//glEnable(GL_BLEND);     // Turn Blending On
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, text);
	glBegin(GL_QUADS); //plano
	//glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	//glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glDisable(GL_BLEND);        // Turn Blending Off
	//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
	glEnable(GL_LIGHTING);

	glPopMatrix();
}

void triangulo(GLuint textura1)  //Funcion creacion prisma
{

	GLfloat vertice[6][3] = {
		{ -0.5 ,-0.3, 0.5 },    //Coordenadas Vértice 0 V0
		{ 0.5 ,-0.3, 0.5 },    //Coordenadas Vértice 1 V1
		{ 0.0 ,0.3, 0.5 },    //Coordenadas Vértice 2 V2
		{ 0.0 ,0.3, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,-0.3, -0.5 },    //Coordenadas Vértice 4 V4
		{ -0.5 ,-0.3, -0.5 },    //Coordenadas Vértice 5 V5

	};


	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
							//glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[5]);
	glEnd();

}

void arbol()
{
	glPushMatrix();
					glDisable(GL_LIGHTING);
					glEnable( GL_ALPHA_TEST );
					//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
					glAlphaFunc( GL_GREATER, 0.1 );
					//glEnable(GL_BLEND);     // Turn Blending On
					//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
					glBindTexture(GL_TEXTURE_2D, tree.GLindex);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(-45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
					glDisable( GL_ALPHA_TEST );
					//glDisable(GL_BLEND);        // Turn Blending Off
					//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
					glEnable(GL_LIGHTING);
				
			glPopMatrix();
}
void alpha(GLint text)
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
	glAlphaFunc(GL_GREATER, 0.1);
	//glEnable(GL_BLEND);     // Turn Blending On
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D,text);
	
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	
	glDisable(GL_ALPHA_TEST);
	//glDisable(GL_BLEND);        // Turn Blending Off
	//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
	glEnable(GL_LIGHTING);

	glPopMatrix();
}

void saveFrame(void)
{

	printf("frameindex %d\n", FrameIndex);

	KeyFrame[FrameIndex].posX = posX;
	KeyFrame[FrameIndex].posY = posY;
	KeyFrame[FrameIndex].posZ = posZ;

	KeyFrame[FrameIndex].rotRodIzq = rotRodIzq;
	KeyFrame[FrameIndex].giroMonito = giroMonito;
	KeyFrame[FrameIndex].movBrazoDer = movBrazoDer;

	FrameIndex++;
}

void resetElements(void)
{
	posX = KeyFrame[0].posX;
	posY = KeyFrame[0].posY;
	posZ = KeyFrame[0].posZ;

	rotRodIzq = KeyFrame[0].rotRodIzq;
	giroMonito = KeyFrame[0].giroMonito;
	movBrazoDer = KeyFrame[0].movBrazoDer;

}

void interpolation(void)
{
	KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;
	KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;
	KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;

	KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;
	KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;
	KeyFrame[playIndex].movBrazoDerInc = (KeyFrame[playIndex + 1].movBrazoDer - KeyFrame[playIndex].movBrazoDer) / i_max_steps;

}

void monito()
{
	//glNewList(1, GL_COMPILE);
	glPushMatrix();//Pecho
	glScalef(0.5, 0.5, 0.5);
	fig7.prisma(2.0, 2.0, 1, text2.GLindex);

	glPushMatrix();//Cuello
	glTranslatef(0, 1.0, 0.0);
	fig7.cilindro(0.25, 0.25, 15, 0);
	glPushMatrix();//Cabeza
	glTranslatef(0, 1.0, 0);
	fig7.esfera(0.75, 15, 15, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo derecho-->
	glTranslatef(1.25, 0.65, 0);
	fig7.esfera(0.5, 12, 12, 0);
	glPushMatrix();
	glTranslatef(0.25, 0, 0);
	glRotatef(movBrazoDer, 0.0, 0.0, 1.0);
	glRotatef(-45, 0, 1, 0);
	glTranslatef(0.75, 0, 0);
	fig7.prisma(0.7, 1.5, 0.7, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Brazo izquierdo <--
	glTranslatef(-1.25, 0.65, 0);
	fig7.esfera(0.5, 12, 12, 0);
	glPushMatrix();
	glTranslatef(-0.25, 0, 0);
	glRotatef(45, 0, 1, 0);
	glRotatef(25, 0, 0, 1);
	glRotatef(25, 1, 0, 0);
	glTranslatef(-0.75, 0, 0);
	fig7.prisma(0.7, 1.5, 0.7, 0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//Cintura
	glColor3f(0, 0, 1);
	glTranslatef(0, -1.5, 0);
	fig7.prisma(1, 2, 1, 0);

	glPushMatrix(); //Pie Derecho -->
	glTranslatef(0.75, -0.5, 0);
	glRotatef(-15, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(15, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	fig7.prisma(0.2, 1.2, 1.5, 0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix(); //Pie Izquierdo -->
	glTranslatef(-0.75, -0.5, 0);
	glRotatef(-5, 1, 0, 0);
	glTranslatef(0, -0.5, 0);
	fig7.prisma(1.0, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glRotatef(15 + rotRodIzq, 1, 0, 0);
	glTranslatef(0, -0.75, 0);
	fig7.prisma(1.5, 0.5, 1, 0);

	glPushMatrix();
	glTranslatef(0, -0.75, 0.3);
	fig7.prisma(0.2, 1.2, 1.5, 0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPopMatrix();


	glColor3f(1, 1, 1);
	glPopMatrix();
	//glEndList();
}
	
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
    
	/////////////////////////////////////////////       carga de texturas //////////////////////////7
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();


	tree.LoadTGA("Texturas/arbol.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();
	ambiente.LoadTGA("Texturas/ambiente.tga");
	ambiente.BuildGLTexture();
	ambiente.ReleaseImage();
	ambiente2.LoadTGA("Texturas/ambiente2.tga");
	ambiente2.BuildGLTexture();
	ambiente2.ReleaseImage();
	pasto.LoadTGA("Texturas/Pasto.tga");
	pasto.BuildGLTexture();
	pasto.ReleaseImage();
	muro.LoadTGA("Texturas/muro.tga");
	muro.BuildGLTexture();
	muro.ReleaseImage();
	madera.LoadTGA("Texturas/madera_vieja.tga");
	madera.BuildGLTexture();
	madera.ReleaseImage();
	puerta.LoadTGA("Texturas/puerta_closet.tga");
	puerta.BuildGLTexture();
	puerta.ReleaseImage();
	cuadro.LoadTGA("Texturas/cuadro.tga");
	cuadro.BuildGLTexture();
	cuadro.ReleaseImage();
	colchon.LoadTGA("Texturas/colchon.tga");
	colchon.BuildGLTexture();
	colchon.ReleaseImage();
	oxido.LoadTGA("Texturas/oxido.tga");
	oxido.BuildGLTexture();
	oxido.ReleaseImage();
	help.LoadTGA("Texturas/HELP.tga");
	help.BuildGLTexture();
	help.ReleaseImage();
	blood.LoadTGA("Texturas/blood.tga");
	blood.BuildGLTexture();
	blood.ReleaseImage();
	raya.LoadTGA("Texturas/raya.tga");
	raya.BuildGLTexture();
	raya.ReleaseImage();
	mono.LoadTGA("Texturas/mono.tga");
	mono.BuildGLTexture();
	mono.ReleaseImage();
	piso_casa.LoadTGA("Texturas/piso_casa.tga");
	piso_casa.BuildGLTexture();
	piso_casa.ReleaseImage();
    neblina.LoadTGA("Texturas/neblina.tga");
	neblina.BuildGLTexture();
	neblina.ReleaseImage();
	neblina1.LoadTGA("Texturas/neblina1.tga");
	neblina1.BuildGLTexture();
	neblina1.ReleaseImage();
	trans.LoadTGA("Texturas/tranzparencia.tga");
	trans.BuildGLTexture();
	trans.ReleaseImage();
	wall.LoadTGA("Texturas/wall.tga");
	wall.BuildGLTexture();
	wall.ReleaseImage();
	piso.LoadTGA("Texturas/floor.tga");
	piso.BuildGLTexture();
	piso.ReleaseImage();
	door.LoadTGA("Texturas/door.tga");
	door.BuildGLTexture();
	door.ReleaseImage();
	wood.LoadTGA("Texturas/techo.tga");
	wood.BuildGLTexture();
	wood.ReleaseImage();
	woodS.LoadTGA("Texturas/woodS.tga");
	woodS.BuildGLTexture();
	woodS.ReleaseImage();
	ventana.LoadTGA("Texturas/ventana.tga");
	ventana.BuildGLTexture();
	ventana.ReleaseImage();
	ventan_arriba.LoadTGA("Texturas/ventan_arriba.tga");
	ventan_arriba.BuildGLTexture();
	ventan_arriba.ReleaseImage();
	vela.LoadTGA("Texturas/vela.tga");
	vela.BuildGLTexture();
	vela.ReleaseImage();
	penta.LoadTGA("Texturas/penta.tga");
	penta.BuildGLTexture();
	penta.ReleaseImage();
	cuadro1.LoadTGA("Texturas/feo.tga");
	cuadro1.BuildGLTexture();
	cuadro1.ReleaseImage();
	cuadro2.LoadTGA("Texturas/boca.tga");
	cuadro2.BuildGLTexture();
	cuadro2.ReleaseImage();
	cuadro3.LoadTGA("Texturas/face.tga");
	cuadro3.BuildGLTexture();
	cuadro3.ReleaseImage();
	madera_cama.LoadTGA("Texturas/madera_cama.tga");
	madera_cama.BuildGLTexture();
	madera_cama.ReleaseImage();
	
	sangre_tortura.LoadTGA("Texturas/tortura.tga");
	sangre_tortura.BuildGLTexture();
	sangre_tortura.ReleaseImage();

	carne.LoadTGA("Texturas/colgado.tga");
	carne.BuildGLTexture();
	carne.ReleaseImage();

	pasaje.LoadBMP("Texturas/pasaje.bmp");
	pasaje.BuildGLTexture();
	pasaje.ReleaseImage();

	bruja.LoadTGA("Texturas/bruja.tga");
	bruja.BuildGLTexture();
	bruja.ReleaseImage();

	bruja2.LoadTGA("Texturas/bruja2.tga");
	bruja2.BuildGLTexture();
	bruja2.ReleaseImage();
	
	////////////////////carga de modelos ///////////////////////////

	kit._3dsLoad("modelos/carroza.3ds");
	FEMUR._3dsLoad("modelos/FEMUR.3ds");
	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);


	//////////////////////////////   KEYFRAMES           ////////////////////////////////////////

	//NEW Iniciar variables de KeyFrames
	/*for(int i=0; i<MAX_FRAMES; i++)
	{
	KeyFrame[i].posX =0;
	KeyFrame[i].posY =0;
	KeyFrame[i].posZ =0;
	KeyFrame[i].incX =0;
	KeyFrame[i].incY =0;
	KeyFrame[i].incZ =0;
	KeyFrame[i].rotRodIzq =0;
	KeyFrame[i].rotInc =0;
	KeyFrame[i].giroMonito =0;
	KeyFrame[i].giroMonitoInc =0;
	KeyFrame[i].giroBrazo =0;
	KeyFrame[i].giroBrazoInc = 0;

	}*/

	KeyFrame[0].posX = 0;
	KeyFrame[0].posY = 2.5;
	KeyFrame[0].posZ = -3.5;
	KeyFrame[0].rotRodIzq = 0;
	KeyFrame[0].giroMonito = 0;
	KeyFrame[0].movBrazoDer = 0;

	KeyFrame[1].posX = 20;
	KeyFrame[1].posY = 2.5;
	KeyFrame[1].posZ = -3.5;
	KeyFrame[1].rotRodIzq = 60;
	KeyFrame[1].giroMonito = -90.0;
	KeyFrame[1].movBrazoDer = 40;

	KeyFrame[2].posX = 20;
	KeyFrame[2].posY = 2.5;
	KeyFrame[2].posZ = 4.0;
	KeyFrame[2].rotRodIzq = -20.0;
	KeyFrame[2].giroMonito = 0;
	KeyFrame[2].movBrazoDer = 0;

	KeyFrame[3].posX = 20;
	KeyFrame[3].posY = 2.5;
	KeyFrame[3].posZ = 4.0;
	KeyFrame[3].rotRodIzq = 40.0;
	KeyFrame[3].giroMonito = 45;
	KeyFrame[3].movBrazoDer = 90;

	KeyFrame[4].posX = 20;
	KeyFrame[4].posY = 2.5;
	KeyFrame[4].posZ = 4.0;
	KeyFrame[4].rotRodIzq = -40.0;
	KeyFrame[4].giroMonito = -45;
	KeyFrame[4].movBrazoDer = -90;
	//NEW//////////////////NEW//////////////////NEW//////////////////

}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
		
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,64,0);
				sky.skybox2(130.0, 130.0, 130.0,ambiente.GLindex, ambiente2.GLindex);
				glEnable(GL_LIGHTING);
				glColor3f(1.0,1.0,1.0);
			glPopMatrix();

			/*Piso Pasto*/
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			prisma.prisma(0.0, 130.0, 130.0, pasto.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			/*************************************************/
			/*CASITA*/
			
			glTranslatef(-20.0, 0.0, -30.0);
			glScalef(0.7, 0.7, 0.7);
			
			glPushMatrix();

			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(0.0, 10.1, 0.0);
			prisma.prisma(20.0, 20.0, 1.0,muro.GLindex);//muro atras
			glEnable(GL_LIGHTING);

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(6.0, 0.0, 20.0);
			prisma.prisma(20.0, 8.0, 1.0, muro.GLindex);//muro frente derecha
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(-6.0, 0.0, 20.0);
			prisma.prisma(20.0, 8.0, 1.0, muro.GLindex);//muro frente izquierda
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glTranslatef(-10.0, 0.0, 10.5);
			prisma.prisma(20.0, 21.0, 1.0, muro.GLindex);//muro  izquierdo
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glTranslatef(-10.0, 0.0, -10.5);
			prisma.prisma(20.0, 21.0, 1.0, muro.GLindex);//muro  derecho
			glEnable(GL_LIGHTING);
			glPopMatrix();


			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(0.0, 10.5, 10.0);
			prisma.prisma(1.0, 22.0, 21.0, muro.GLindex);//techo
			glEnable(GL_LIGHTING);
			glPopMatrix();





			glPopMatrix();
/*********************************************************/
/*ARMARIO*/
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.15, 0.15, 0.15);
			glTranslatef(0.0, 9.5, 3.0);
			prisma.prisma2(18.0, 5.0, 2.0, puerta.GLindex,madera.GLindex);//armario
			glEnable(GL_LIGHTING);

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glTranslatef(-5.0, 5.0, -9.9);
			prisma.prisma2(5.0, 3.5, 0.5, cuadro.GLindex,madera.GLindex);//cuadro
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glTranslatef(-4.0, -8.5, 0.0);
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(0.0, 5.0, 3.0);
			prisma.prisma(3.5, 0.2, 0.2, oxido.GLindex);//cama cabezera
			glEnable(GL_LIGHTING);

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(1.0, 0.0, 0.0);
			prisma.prisma(3.5, 0.2, 0.2, oxido.GLindex);//cama cabezera
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(-1.0, 0.0, 0.0);
			prisma.prisma(3.5, 0.2, 0.2, oxido.GLindex);//cama cabezera
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(-2.0, 0.0, 0.0);
			prisma.prisma(3.5, 0.2, 0.2, oxido.GLindex);//cama cabezera
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(-3.0, -2.0, 0.0);
			prisma.prisma(7.5, 0.2, 0.2, oxido.GLindex);//cama cabezera
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(2.0, -2.0, 0.0);
			prisma.prisma(7.5, 0.2, 0.2, oxido.GLindex);//cama cabezera
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(-0.5, 1.8, 0.0);
			prisma.prisma(0.2, 5.5, 0.2, oxido.GLindex);//cama cabezera
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(-0.5, -1.8, 0.0);
			prisma.prisma(0.2, 5.2, 0.2, oxido.GLindex);//cama cabezera
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(-0.5, -2.5, 0.0);
			prisma.prisma(0.2, 5.2, 0.2, oxido.GLindex);//cama cabezera
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(-0.5, -2.5, 8.2);
			prisma.prisma(0.2, 5.2, 0.2, oxido.GLindex);//cama cabezera
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(-3.0, -4.0, 8.2);
			prisma.prisma(3.0, 0.2, 0.2, oxido.GLindex);//cama cabezera
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(2.0, -4.0, 8.2);
			prisma.prisma(3.0, 0.2, 0.2, oxido.GLindex);//cama cabezera
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(-3.0, -2.5, 4.2);
			prisma.prisma(0.2, 0.2, 8.2, oxido.GLindex);//cama cabezera
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(2.0, -2.5, 4.2);
			prisma.prisma(0.2, 0.2, 8.2, oxido.GLindex);//cama cabezera
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(0.0, -1.8, 5.0);
			prisma.prisma(1.0, 5.2, 8.2, colchon.GLindex);//colchon
			glEnable(GL_LIGHTING);
			glPopMatrix();
//////////SANGRE///////////////

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.4, 0.4, 0.4);
			glRotatef(90.0, 1.0, 0.0, 0.0);
			glTranslatef(4.0, -5.5, 5.9);
			glScalef(1.0, 0.93, 0.0);
			plano(piso_casa.GLindex);//piso_casa
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.4, 0.4, 0.4);
			glTranslatef(4.0, 0.0, -1.9);
			glScalef(0.3, 0.3, 0.0);
			plano(help.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.4, 0.4, 0.4);
			glRotatef(-90.0, 0.0, 1.0, 0.0);
			glTranslatef(7.0, 0.0, -13.9);
			glScalef(0.4, 0.4, 0.0);
			plano(blood.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
			
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(0.4, 0.4, 0.4);
			glRotatef(-90.0, 0.0, 1.0, 0.0);
			glTranslatef(8.0, 0.0, 5.9);
			glScalef(0.4, 0.4, 0.0);
			plano(raya.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPopMatrix();
///////////////////////////////////////////////////////////
			/*ARBOLES*/
			glPushMatrix();
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(8.0, -2.5, 30.0);
			glScalef(3.0, 3.0, 3.0);
			arbol();

			glPushMatrix();
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(8.0, 0.0, -10.0);
			arbol();
			glPopMatrix();

			glPushMatrix();
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(8.0, 0.0, -10.0);
			arbol();
			glPopMatrix();
	
			glPushMatrix();
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(-8.0, 0.0, -10.0);
			arbol();
			glPopMatrix();

			glPushMatrix();
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(-5.0, 0.0, -15.0);
			arbol();
			glPopMatrix();

			glPushMatrix();
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(-13.0, 0.0, -15.0);
			arbol();
			glPopMatrix();

			glPushMatrix();
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(12.0, 0.0, -15.0);
			arbol();
			glPopMatrix();

			glPushMatrix();
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(2.0, 0.0, -15.0);
			arbol();
			glPopMatrix();
			glPopMatrix();


/*************************************************************************************************************************************************************/

			glPopMatrix();

		glPopMatrix(); 
/**************NEBLINA****************/

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		//glRotatef(90.0, 1.0, 0.0, 0.0);
		glTranslatef(0.0, 0.0, -1.0);
		glScalef(130.0, 1.0, 130.0);
		prisma.prisma_anun(neblina1.GLindex, trans.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();
/**********************************************/


/*IGLESIA*/
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2,0.2,0.2);
		glTranslatef(0.0, 12.5, 10.0);
		prisma.prisma(25.0, 25.0, 0.5, wall.GLindex);
		glEnable(GL_LIGHTING);

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(12.5, 0.0, 15.2);
		prisma.prisma(25.0, 0.5, 30.0, wall.GLindex);/////////////////////////////////////
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-12.5, 0.0, 15.2);
		prisma.prisma(25.0, 0.5, 30.0,wall.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(0.0, -12.4, 0.0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glScalef(1.22, 1.51, 0.0);
		plano(piso.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(0.0, 0.0, 30.0);
		prisma.prisma(25.0, 25.0, 0.5, door.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(0.0, 21.6, 15.0);
		glScalef(30.0, 30.0, 30.0);
		triangulo(wood.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.4, 0.4, 0.4);
		glTranslatef(-12.0, 2.0, 7.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glScalef(0.3, 0.3, 0.0);//ventana
		plano(ventana.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.4, 0.4, 0.4);
		glTranslatef(-12.9, 2.0, 7.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glScalef(0.3, 0.3, 0.0);//ventana
		plano(ventana.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.4, 0.4, 0.4);
		glTranslatef(-12.0, 2.0, 24.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glScalef(0.3, 0.3, 0.0);//ventana
		plano(ventana.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.4, 0.4, 0.4);
		glTranslatef(-12.9, 2.0, 24.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glScalef(0.3, 0.3, 0.0);//ventana
		plano(ventana.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.4, 0.4, 0.4);
		glTranslatef(12.0, 2.0, 7.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glScalef(0.3, 0.3, 0.0);
		plano(ventana.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.4, 0.4, 0.4);
		glTranslatef(12.9, 2.0, 7.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glScalef(0.3, 0.3, 0.0);
		plano(ventana.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.4, 0.4, 0.4);
		glTranslatef(12.0, 2.0, 24.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glScalef(0.3, 0.3, 0.0);//ventana
		plano(ventana.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.4, 0.4, 0.4);
		glTranslatef(12.9, 2.0, 24.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glScalef(0.3, 0.3, 0.0);//ventana
		plano(ventana.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.4, 0.4, 0.4);
		glTranslatef(0.0, 18.0, 30.1);
		glScalef(0.3, 0.5, 0.0);//ventana techo
		plano(ventan_arriba.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		/////////VELAS/////////////////////////
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.9, 0.9, 0.9);
		glTranslatef(0.0, -12.2, 0.0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glScalef(1.22, 1.51, 0.0);
		plano(penta.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(0.0, -12.0, 17.0);
		glScalef(0.1, 0.1, 0.1);
		dosde(vela.GLindex);
		glPopMatrix();

		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(0.0, -12.0, 27.0);
		glScalef(0.1, 0.1, 0.1);
		dosde(vela.GLindex);
		glPopMatrix();

		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(6.0, -12.0, 5.0);
		glScalef(0.1, 0.1, 0.1);
		dosde(vela.GLindex);
		glPopMatrix();

		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(-6.0, -12.0, 5.0);
		glScalef(0.1, 0.1, 0.1);
		dosde(vela.GLindex);
		glPopMatrix();

		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(-9.0, -12.0, 20.0);
		glScalef(0.1, 0.1, 0.1);
		dosde(vela.GLindex);
		glPopMatrix();

		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(9.0, -12.0, 20.0);
		glScalef(0.1, 0.1, 0.1);
		dosde(vela.GLindex);
		glPopMatrix();
		////////////////////////////////////////////////////

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(-11.9, 5.0, 15.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		prisma.prisma2(7.0, 5.5, 0.5, cuadro1.GLindex, madera.GLindex);//cuadro
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(11.9, 5.0, 15.0);
		glRotatef(-90.0, 0.0, 1.0, 0.0);
		prisma.prisma2(7.0, 5.5, 0.5, cuadro2.GLindex, madera.GLindex);//cuadro
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 1.0);
	//	glRotatef(90.0, 0.0, 1.0, 0.0);
		glTranslatef(0.0, 5.0, 0.5);
		prisma.prisma2(12.0, 5.0, 0.5, cuadro3.GLindex, madera.GLindex);//cuadro
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPopMatrix();
/*****************************/

		//Torre
		glDisable(GL_LIGHTING);
		glPushMatrix();
			glColor3f(0.2, 0.2, 0.2);
			glTranslatef(25.0, 12.5, 10);
			prisma.prisma(25.0, 25.0, 0.5, door.GLindex); 
			glPushMatrix();
				glTranslatef(12.5, 0.0, -15);
				prisma.prisma(25.0, 0.5, 30.0, wall.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.25, 0.0, -30.25);
				glRotatef(90, 0, 1, 0);
				prisma.prisma(25.0, 0.5, 25.0, wall.GLindex);
				glPushMatrix();
					glTranslatef(-15, 0.0, -12.5);
					glRotatef(90, 0, 1, 0);
					prisma.prisma(25.0, 0.5, 30.0, wall.GLindex);
				glPopMatrix();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.0, 12.5, -30);
				glRotatef(90.0, 1.0, 0.0, 0.0);
				glScalef(1.22, 1.51, 0.0);
				plano(piso.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.0, -12.4, -30);
				glRotatef(90.0, 1.0, 0.0, 0.0);
				glScalef(1.22, 1.51, 0.0);
				plano(piso.GLindex);
			glPopMatrix();
			glEnable(GL_LIGHTING);
		glPopMatrix();
	
		glPushMatrix();
			glDisable(GL_COLOR_MATERIAL);
			glTranslatef(movKitX, movKitY, movKitZ);
			glRotatef(rotKit, 0, 1, 0);
			kit.GLrender(NULL, _SHADED, 1.0); //Dibujamos la carroceria
			glEnable(GL_COLOR_MATERIAL);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-41, 0.0, -5.0);
			glColor3f(1.0, 1.0, 1.0);
			fig7.esfera(portal, 20.0, 20.0, pasaje.GLindex);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(brujax, brujay, brujaz);
			glColor3f(1.0, 1.0, 1.0);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			fig7.prisma1(15, 15, 0.01, bruja.GLindex,bruja2.GLindex);
			glDisable(GL_ALPHA_TEST);
		glPopMatrix();

		glTranslatef(20.0, 0.0, -10.0);//cama

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(0.0, 5.0, 3.0);
		//prisma.prisma(3.5, 0.2, 0.2, oxido.GLindex);//cama cabezera
		glEnable(GL_LIGHTING);

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(1.0, 0.0, 0.0);
//		prisma.prisma(3.5, 0.2, 0.2, oxido.GLindex);//cama cabezera
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-1.0, 0.0, 0.0);
		//prisma.prisma(3.5, 0.2, 0.2, oxido.GLindex);//cama cabezera
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-2.0, 0.0, 0.0);
		//prisma.prisma(3.5, 0.2, 0.2, oxido.GLindex);//cama cabezera
		glEnable(GL_LIGHTING);
		glPopMatrix();



		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-3.0, -3.5, 0.0);
		prisma.prisma(2.5, 0.2, 0.2, oxido.GLindex);//cama cabezera
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(2.0, -3.5, 0.0);
		prisma.prisma(2.5, 0.2, 0.2, oxido.GLindex);//cama cabezera
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-0.5, 1.8, 0.0);
		//prisma.prisma(0.2, 5.5, 0.2, oxido.GLindex);//cama cabezera
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-0.5, -1.8, 0.0);
		//prisma.prisma(0.2, 5.2, 0.2, oxido.GLindex);//cama cabezera
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-0.5, -2.5, 0.0);
		prisma.prisma(0.2, 5.2, 0.2, oxido.GLindex);//cama cabezera
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-0.5, -2.5, 8.2);
		prisma.prisma(0.2, 5.2, 0.2, oxido.GLindex);//cama cabezera
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-3.0, -3.5, 8.2);
		prisma.prisma(2.5, 0.15, 0.2, oxido.GLindex);//cama cabezera
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(2.0, -3.5, 8.2);
		prisma.prisma(2.5, 0.15, 0.2, oxido.GLindex);//cama cabezera
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-3.0, -2.5, 4.2);
		prisma.prisma(0.2, 0.2, 8.2, oxido.GLindex);//cama cabezera
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(2.0, -2.5, 4.2);
		prisma.prisma(0.2, 0.2, 8.2, oxido.GLindex);//cama cabezera
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-0.5, -1.8, 4.0);
		prisma.prisma(1.0, 5.2, 8.2, madera_cama.GLindex);//colchon
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(2.0, -0.8, 1.0);
		glRotatef(90.0, 0.0, 0.0, 1.0);
		prisma.cilindro(0.5, 5.0, 15.0, madera_cama.GLindex);//colchon
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(2.0, -1.0, 4.0);
		glRotatef(90.0, 0.0, 0.0, 1.0);
		prisma.cilindro(0.2, 5.0, 15.0, madera_cama.GLindex);//colchon
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(2.0, -1.0, 6.0);
		glRotatef(90.0, 0.0, 0.0, 1.0);
		prisma.cilindro(0.2, 5.0, 15.0, madera_cama.GLindex);//colchon
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(2.0, -1.0, 8.0);
		glRotatef(90.0, 0.0, 0.0, 1.0);
		prisma.cilindro(0.2, 5.0, 15.0, madera_cama.GLindex);//colchon
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.9, 0.9, 0.9);
		glTranslatef(0.0, -1.0, 2.0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glScalef(0.2, 0.2, 0.0);
		plano(sangre_tortura.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		//caballo///
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(10.0, -1.0, 4.0);
		glScalef(3.0, 5.0, 8.0);
		triangulo(woodS.GLindex);
		glEnable(GL_LIGHTING);

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-0.4, -0.2, -0.4);
		//glRotatef(90.0, 0.0, 0.0, 10.0);
		prisma.prisma(1.0, 0.2, 0.05, woodS.GLindex);//colchon
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-0.4, -0.2, 0.4);
		//glRotatef(90.0, 0.0, 0.0, 10.0);
		prisma.prisma(1.0, 0.2, 0.05, woodS.GLindex);//colchon
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(0.4, -0.2, -0.4);
		//glRotatef(90.0, 0.0, 0.0, 10.0);
		prisma.prisma(1.0, 0.2, 0.05, woodS.GLindex);//colchon
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(0.4, -0.2, 0.4);
		//glRotatef(90.0, 0.0, 0.0, 10.0);
		prisma.prisma(1.0, 0.2, 0.05, woodS.GLindex);//colchon
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_COLOR_MATERIAL);
		glTranslatef(-3.5, 0.08, 0.4);
		//glRotatef(rotKit, 0, 1, 0);
		glScalef(0.001, 0.001, 0.001);
		FEMUR.GLrender(NULL, _SHADED, 1.0); //Dibujamos la carroceria
		glEnable(GL_COLOR_MATERIAL);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_COLOR_MATERIAL);
		glTranslatef(-2.8, 0.08, 0.0);
		//glRotatef(rotKit, 0, 1, 0);
		glScalef(0.001, 0.001, 0.001);
		FEMUR.GLrender(NULL, _SHADED, 1.0); //Dibujamos la carroceria
		glEnable(GL_COLOR_MATERIAL);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_COLOR_MATERIAL);
		glTranslatef(-3.4, 0.08, 0.0);
		//glRotatef(rotKit, 0, 1, 0);
		glScalef(0.001, 0.001, 0.001);
		FEMUR.GLrender(NULL, _SHADED, 1.0); //Dibujamos la carroceria
		glEnable(GL_COLOR_MATERIAL);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_COLOR_MATERIAL);
		glTranslatef(-3.8, 0.08, 0.0);
		//glRotatef(rotKit, 0, 1, 0);
		glScalef(0.001, 0.001, 0.001);
		FEMUR.GLrender(NULL, _SHADED, 1.0); //Dibujamos la carroceria
		glEnable(GL_COLOR_MATERIAL);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(0.4, 1.2, -1.4);
		glScalef(0.15, 0.15, 0.0);
		plano(carne.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-2.2, 1.2, -1.4);
		glScalef(0.15, 0.15, 0.0);
		plano(carne.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-4.2, 1.2, -1.4);
		glScalef(0.15, 0.15, 0.0);
		plano(carne.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-2.2, 1.2, -0.4);
		glScalef(0.15, 0.15, 0.0);
		plano(carne.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-4.2, 1.2, -0.4);
		glScalef(0.15, 0.15, 0.0);
		plano(carne.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(0.2, 1.2, -0.4);
		glScalef(0.15, 0.15, 0.0);
		plano(carne.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPopMatrix();
		///caballo
		glPopMatrix();

	glPopMatrix();

	glutSwapBuffers ( );

}

void animacion()
{
	
	prisma.text_izq -= 0.0001;
	prisma.text_der += 0.0001;
	if (prisma.text_izq<-1)
		prisma.text_izq = 0;
	if (prisma.text_der<0)
		prisma.text_der = 1;
	
///////////////////// animacion kit diabolico ///////////////////
	if (circuito)
	{
		if (recorrido1)
		{
			movKitX++;

			if (movKitX > 53)
			{

				recorrido1 = false;
				recorrido2 = true;
			}
		}
		if (recorrido2)
		{
			rotKit = -90.0;
			movKitZ++;

			if (movKitZ > 55)
			{
				recorrido2 = false;
				recorrido3 = true;
			}
		}
		if (recorrido3)
		{
			rotKit = -180.0;
			movKitX--;
			if (movKitX < -40)
			{
				recorrido3 = false;
				recorrido4 = true;
			}
		}
		if (recorrido4)
		{
			rotKit = 90;
			movKitZ--;

			if (movKitZ < -5)
			{
				recorrido4 = false;
				recorrido5 = true;
			}
		}
		if (recorrido5)
		{
			portal ++;


			if (portal > 15)
			{
				recorrido5 = false;
				recorrido6 = true;
			}
		}
		if (recorrido6)
		{
			movKitY--;
			portal --;
			if (movKitY < -10.0 && portal <=  0)
			{
				recorrido6 = false;
				recorrido7 = true;
			}
		}
		if (recorrido7)
		{
			movKitZ = -60;
			movKitY = 0.0;
			movKitX = -50;
			rotKit = 0;
			contador ++;
			
			if (contador > 20)
			{
				recorrido7 = false;
				recorrido1 = true;
			}
		}
	}
//////////////////////////////  FIN animacion kit diabolico             /////////////////////////7

///////////////////// animacion bruja sexi ///////////////////

///////////////////// FIN animacion bruja sexi ///////////////////

	//Movimiento del monito
	if (play)
	{
		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex>FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation
				interpolation();
			}
		}
		else
		{
			//Draw animation
			posX += KeyFrame[playIndex].incX;
			posY += KeyFrame[playIndex].incY;
			posZ += KeyFrame[playIndex].incZ;

			rotRodIzq += KeyFrame[playIndex].rotInc;
			giroMonito += KeyFrame[playIndex].giroMonitoInc;
			movBrazoDer += KeyFrame[playIndex].movBrazoDerInc;

			i_curr_steps++;
		}

	}

	/*frame++;
	time=glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
	sprintf(s,"FPS:%4.2f",frame*1000.0/(time-timebase));
	timebase = time;
	frame = 0;
	}*/


	glutPostRedisplay();
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

		case '1':
			circuito^= true;
			printf("%f  X \n", movKitX);
			printf("%f Y \n", movKitY);
			printf("%f Z\n", movKitZ);
			break;
		
		case '2':
			circuito ^= true;
			printf("%f  X \n", movKitX);
			printf("%f Y \n", movKitY);
			printf("%f Z\n", movKitZ);
			break;

		case 'k':		
		case 'K':
			if (FrameIndex<MAX_FRAMES)
			{
				saveFrame();
			}

			break;

		case 'l':
		case 'L':
			if (play == false && (FrameIndex>1))
			{

				resetElements();
				//First Interpolation				
				interpolation();

				play = true;
				playIndex = 0;
				i_curr_steps = 0;
			}
			else
			{
				play = false;
			}
			break;

		case 'y':
		case 'Y':
			posZ++;
			//printf("%f \n", posZ);
			break;
		case 'g':
		case 'G':
			posX--;
			//printf("%f \n", posX);
			break;

		case 'h':
		case 'H':
			posZ--;
			//printf("%f \n", posZ);
			break;

		case 'j':
		case 'J':
			posX++;
			//printf("%f \n", posX);
			break;

		case 'b':
			rotRodIzq++;
			//printf("%f \n", rotRodIzq);
			break;

		case 'B':
			rotRodIzq--;
			//printf("%f \n", rotRodIzq);
			break;

		case 'p':
			giroMonito++;
			//printf("%f \n", giroMonito);
			break;

		case 'P':
			giroMonito--;
			//printf("%f \n", giroMonito);
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
		case 'T':
			
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
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

void menuKeyFrame(int id)
{
	switch (id)
	{
	case 0:	//Save KeyFrame
		if (FrameIndex<MAX_FRAMES)
		{
			saveFrame();
		}
		break;

	case 1:	//Play animation
		if (play == false && FrameIndex >1)
		{

			resetElements();
			//First Interpolation
			interpolation();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;


	}
}

int main ( int argc, char** argv )   // Main Function
{
  PlaySound(TEXT("Soundtrack/Malthael.wav"), NULL, SND_ASYNC | SND_LOOP);
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (1800, 1800);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Recorrido"); // Nombre de la Ventana
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
