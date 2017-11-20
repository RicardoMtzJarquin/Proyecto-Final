//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"


int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;


CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

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




CFiguras sky;
CFiguras prisma;


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
    
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadBMP("logopumas.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();


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
	//END NEW//////////////////////////////

	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);

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
		prisma.prisma(25.0, 0.5, 30.0, wall.GLindex);
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
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(-11.9, 5.0, 15.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		prisma.prisma2(7.0, 5.5, 0.5, cuadro1.GLindex, madera.GLindex);//cuadro
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
		glTranslatef(11.9, 5.0, 15.0);
		glRotatef(-90.0, 0.0, 1.0, 0.0);
		prisma.prisma2(7.0, 5.5, 0.5, cuadro2.GLindex, madera.GLindex);//cuadro
		glEnable(GL_LIGHTING);
		glPopMatrix();


		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.2, 0.2, 0.2);
	//	glRotatef(90.0, 0.0, 1.0, 0.0);
		glTranslatef(0.0, 5.0, 0.5);
		prisma.prisma2(12.0, 5.0, 0.5, cuadro3.GLindex, madera.GLindex);//cuadro
		glEnable(GL_LIGHTING);
		glPopMatrix();





		glPopMatrix();
/*****************************/

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

int main ( int argc, char** argv )   // Main Function
{

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
