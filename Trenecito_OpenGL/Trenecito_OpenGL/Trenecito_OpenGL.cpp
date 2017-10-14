// trenecito_resureccion.cpp : Defines the entry point for the console application.
//

# include "stdafx.h"
# include <GL\glut.h>//Incluir librerias
# include <stdlib.h>//Biblioteca estandar

float aum;//Variable que almacena los valores para aumentar o disminuir
int grados; //variable para rotacion
int estrellas_x[500]; //array para almacenar 500 valores en x para las estrellas
int estrellas_y[500]; //array para almacenar 500 valores en x para las estrellas con estos dos arrays se determinan los puntos
float stars; //movimiento de las estrellas

void reshape(int width, int height)
{//Metodo llamado reshape
	glViewport(0, 0, width, height);//Definir el area de trabajo 
	glMatrixMode(GL_PROJECTION);//Establece los parametros de proyeccion
	glLoadIdentity();//Carga la matriz identidad
	glOrtho(-100, 100, -100, 100, -100, 100);//Manera de proyeccion de openGL
	glMatrixMode(GL_MODELVIEW); //se limpia la matriz, se carga la matriz activa (GL_MODELVIEW) con la matriz identidad
}
void valoresEstrellas()
{//asigna valores a las estrellas en los array para eje x y eje y (500 valores)
	for (int i = 0; i < 500; i++)
	{
		if (i % 2 != 0)
		{ //se distribuyen en eje x entre ambas partes (negativo y positivo en eje x)
			estrellas_x[i] = rand() % 500 + 1;
		}
		else
		{
			estrellas_x[i] = -rand() % 500 + 1;
		}
	}//valores para y de 0 a 100 en y, 500 valores
	for (int i = 0; i < (500); i++)
	{
		estrellas_y[i] = rand() % 100 + 1;
	}
}
void init()
{//Metodo llamado init
	glClearColor(1, 1, 1, 1);//Establece el color de la ventana de visualizacion en blanco
	aum = 0;//Establece el valor inicial para la variable aum
	grados = 0; //se inicializa grados
	stars = 0; //se inicializa stars
	valoresEstrellas(); //se invoca al metodo que llega los arrays de valores
}

void dibuja_tren()
{//Metodo llamado dibuja_tren
	glColor3f(0.8, 0, 0);//Establece el color del cuadrado en rojo (RGB)
	glBegin(GL_QUADS);//Inicializa una constante para dibujar un cuadrado
	glVertex3f(-40, 0, 0);//Define vertice, como no trabajamos en 3d estamos dejando en 0 valor en z
	glVertex3f(-40, 25, 0);//Indicamos los vertices 
	glVertex3f(10, 25, 0);//Indicamos los vertices 
	glVertex3f(10, 0, 0);//Indicamos los vertices 
	glEnd();//Finaliza el trazo del cuadrado

	glBegin(GL_QUADS);//Inicializa una constante para dibujar un cuadrado
	glVertex3f(-55, 0, 0);//Define vertice, como no trabajamos en 3d estamos dejando en 0 valor en z
	glVertex3f(-55, 35, 0);//Indicamos los vertices 
	glVertex3f(-40, 35, 0);//Indicamos los vertices 
	glVertex3f(-40, 0, 0);//Indicamos los vertices 
	glEnd();//Finaliza el trazo del cuadrado

	glColor3f(0.5, 0.1, 0);
	glBegin(GL_QUADS);//Inicializa una constante para dibujar un cuadrado
	glVertex3f(-30, 25, 0);//Define vertice, como no trabajamos en 3d estamos dejando en 0 valor en z
	glVertex3f(-30, 35, 0);//Indicamos los vertices 
	glVertex3f(-24, 35, 0);//Indicamos los vertices 
	glVertex3f(-24, 25, 0);//Indicamos los vertices 
	glEnd();//Finaliza el trazo del cuadrado

	glColor3f(0.5, 0.1, 0);
	glBegin(GL_QUADS);//Inicializa una constante para dibujar un cuadrado
	glVertex3f(-14, 25, 0);//Define vertice, como no trabajamos en 3d estamos dejando en 0 valor en z
	glVertex3f(-14, 35, 0);//Indicamos los vertices 
	glVertex3f(-8, 35, 0);//Indicamos los vertices 
	glVertex3f(-8, 25, 0);//Indicamos los vertices 
	glEnd();//Finaliza el trazo del cuadrado

	glColor3f(0.8, 0, 0);
	glBegin(GL_QUADS);//Inicializa una constante para dibujar un cuadrado
	glVertex3f(2, 25, 0);//Define vertice, como no trabajamos en 3d estamos dejando en 0 valor en z
	glVertex3f(2, 35, 0);//Indicamos los vertices 
	glVertex3f(8, 35, 0);//Indicamos los vertices 
	glVertex3f(8, 25, 0);//Indicamos los vertices 
	glEnd();//Finaliza el trazo del cuadrado

	glBegin(GL_TRIANGLES);//Inicializa una constante para dibujar un cuadrado
	glVertex3f(5, 33, 0);//Define vertice, como no trabajamos en 3d estamos dejando en 0 valor en z
	glVertex3f(0, 43, 0);//Indicamos los vertices 
	glVertex3f(10, 43, 0);//Indicamos los vertices 
	glEnd();//Finaliza el trazo del cuadrado

	glBegin(GL_TRIANGLES);//Inicializa una constante para dibujar un cuadrado
	glVertex3f(10, -4, 0);//Define vertice, como no trabajamos en 3d estamos dejando en 0 valor en z
	glVertex3f(10, 12, 0);//Indicamos los vertices 
	glVertex3f(30, -4, 0);//Indicamos los vertices 
	glEnd();//Finaliza el trazo del cuadrado

	glColor3f(.8, .8, 0);
	glBegin(GL_QUADS);//Inicializa una constante para dibujar un cuadrado
	glVertex3f(-45, -4, 0);//Define vertice, como no trabajamos en 3d estamos dejando en 0 valor en z
	glVertex3f(-45, -2, 0);
	glVertex3f(10, -2, 0);//Indicamos los vertices 
	glVertex3f(10, -4, 0);
	glEnd();//Finaliza el trazo del cuadrado

	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);//Inicializa una constante para dibujar un cuadrado
	glVertex3f(-53, 25, 0);//Define vertice, como no trabajamos en 3d estamos dejando en 0 valor en z
	glVertex3f(-53, 33, 0);//Indicamos los vertices 
	glVertex3f(-49, 33, 0);//Indicamos los vertices 
	glVertex3f(-49, 25, 0);//Indicamos los vertices 
	glEnd();//Finaliza el trazo del cuadrado

	glBegin(GL_QUADS);//Inicializa una constante para dibujar un cuadrado
	glVertex3f(-46, 25, 0);//Define vertice, como no trabajamos en 3d estamos dejando en 0 valor en z
	glVertex3f(-46, 33, 0);//Indicamos los vertices 
	glVertex3f(-42, 33, 0);//Indicamos los vertices 
	glVertex3f(-42, 25, 0);//Indicamos los vertices 
	glEnd();//Finaliza el trazo del cuadrado

	glColor3f(0.7, 0.7, 0.7);//se crean y se trasladan las llantas
	glRotatef(grados, 1.0f, 0.0f, 0.0f); //se les agrega a las llantas el efecto de rotacion

	glutSolidSphere(9.0f, 30, 30);
	glTranslatef(-22, 0, 0);
	glutSolidSphere(9.0f, 30, 30);
	glTranslatef(-20, 0, 0);
	glutSolidSphere(9.0f, 30, 30);
	glFlush();// Procesa todas las subrutinas de OpenGL tan rapidamente como sea posible
}

void dibuja_fondo()
{ //por medio del dibujado de rectangulos se diseña el fondo
	glBegin(GL_QUADS);//capa cafe que simula tierra
	glColor3f(0.38, 0.3, 0.3);
	glVertex3f(-100, -100, 0);
	glVertex3f(-100, -20, 0);
	glVertex3f(100, -20, 0);
	glVertex3f(100, -100, 0);
	glEnd();

	glBegin(GL_QUADS);//capa gris que simula la base de las vias
	glColor3f(0.15, 0.15, 0.15);
	glVertex3f(-100, -20, 0);
	glVertex3f(-100, -10, 0);
	glVertex3f(100, -10, 0);
	glVertex3f(100, -20, 0);
	glEnd();

	glBegin(GL_QUADS);//capa negra que simula la base de las vias
	glColor3f(0, 0, 0);
	glVertex3f(-100, -10, 0);
	glVertex3f(-100, -5, 0);
	glVertex3f(100, -5, 0);
	glVertex3f(100, -10, 0);
	glEnd();

	glBegin(GL_QUADS);//capa azul que simula el cielo
	glColor3f(0.0, 0.0, 0.3);
	glVertex3f(-100, -5, 0);
	glVertex3f(-100, 100, 0);
	glVertex3f(100, 100, 0);
	glVertex3f(100, -5, 0);
	glEnd();
}
void dibujar_estrellas()
{//se dibujan las estrellas
	for (int i = 0; i < 500; i++)
	{//500 estrellas distribuidas en la capa azul
		glBegin(GL_TRIANGLES); //se representan con triangulos
		glColor3f(0.9, 0.9, 0.9);
		glVertex3f(estrellas_x[i], estrellas_y[i], 0); //coordenada correspondiente en x e y, previamente almacenados en el array
		glVertex3f(estrellas_x[i] + 1, estrellas_y[i] + 1, 0);
		glVertex3f(estrellas_x[i] + 2, estrellas_y[i], 0);
		glEnd();
	}
}
void traslacion()
{//Metodo que traslada
	glMatrixMode(GL_MODELVIEW);//Establece la matriz que va trabajar
	glLoadIdentity();//Carga la matriz identidad	
	glTranslatef(aum, 0.0, 0.0);//Traslada el tren en el eje x
	dibuja_tren();//Se redibuja el cuadrado
}
void traslacion2()
{ //traslada las estrellas
	glMatrixMode(GL_MODELVIEW);//Establece la matriz que va trabajar
	glLoadIdentity();//Carga la matriz identidad	
	glTranslatef(stars, 0.0, 0.0);//Traslada el tren en el eje x
	dibujar_estrellas();
}


void display()
{//Metodo llamado display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Borra los 2 buffer
	glLoadIdentity();//Carga la matriz identidad
	dibuja_fondo();
	traslacion2(); //estrellas
	traslacion();//Llamada al metodo Traslacion()	
	glutSwapBuffers();//Cambia de buffer 
}
void keyboard(unsigned char key, int x, int y)
{//Metodo parecido a un keyboard listener
	switch (key)
	{ //Se evalua la tecla
	case 'd'://En caso de que se presione d
	case 'D'://o D 
		stars -= 0.5; //movimiento estrellas, stars manipula la velocidad
		aum += 0.2;//Aumenta la variable aum 
		grados += 32;//Aumenta la variable grados
		display();//se prepara la pantalla para redibujar y redibuja
		break;//Fin del case
	case 'a'://En caso de que se presione a
	case 'A'://o A
		stars += 0.5; //movimiento estrellas
		aum -= 0.2;//Disminuye la variable aum 
		grados -= 32;//Disminuye la variable grados
		display();//se prepara la pantalla para redibujar y redibuja
		break;//Fin del case
	case 27: //Escape
		exit(0);//salir del switch
		break; //Fin del case 
	}
}
int main(int argc, char** argv)
{//Metodo llamado main
	glutInit(&argc, argv);//Inicializa a GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);//Establece el modo de visualizacion
	glutInitWindowPosition(50, 50);//Posicion inicial de la ventana
	glutInitWindowSize(1000, 800);//Establece el ancho y la altura de la ventana de visualización.
	glutCreateWindow("traslacion");//Crea la ventana de visualización y coloca titulo.
	init();//Ejecuta el procedimiento de inicialización.
	glutDisplayFunc(display);//llama al metodo display y envía los gráficos a la ventana de visualización.
	glutReshapeFunc(reshape);//llama al metodo reshape
	glutKeyboardFunc(keyboard);//llama al metodo keyboard
	glutMainLoop();// Muestra todo y espera.
	return 0;
}
