// HolaOpenGL.cpp: define el punto de entrada de la aplicaci�n de consola.
//

#include "stdafx.h"
#include<GL/glut.h>


void display(void)
{
	// Borra los valores preajustados
	glClear(GL_COLOR_BUFFER_BIT);

	// Delimita los v�rtices de una primitiva o un grupo de como primitivas
	// , GL_POLYGON es el modo que se a seleccionado.
	glBegin(GL_POLYGON);
	// Indica los puntos que se trazan en un plano cartesiano para
	// formar la figura. En el identificador "glVertex2f" el numero
	// "2" indica el n�mero de argumentos y "f" el tipo de dato que
	// se pasa como argumento. En el caso de la f es float.
	double pixel = 0.0025,
		x1 = -0.0025,
		y1 = -0.0025,
		x2 = -0.0025,
		y2 = 0.0025,
		x3 = 0.0025
		, y3 = 0.0025
		, x4 = 0.0025
		, y4 = -0.0025;
	for (int i = 1; i <= 150; i++)
	{
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glVertex2f(x3, y3);
		glVertex2f(x4, y4);
		x1 += pixel;
		y1 += pixel;
		x2 += pixel;
		y2 += pixel;
		x3 += pixel;
		y3 += pixel;
		x4 += pixel;
		y4 += pixel;
	}
	// Termina de dibujar.    
	glEnd();

	// Fuerza de la ejecuci�n de comandos en OpenGl
	glFlush();
}

void RespuestaMenuColor(int s)
{
}

void RespuestaMenuPrincipal(int s)
{
}


int main(int argc, char** argv)
{

	// Se inicia el modo Glut, los argumentos son para enviar ordenes
	// externas al programa.
	glutInit(&argc, argv);
	// Inicializa el modo de visualizaci�n del programa, si est� en modo
	// GLUT_SINGLE significa que tendr� un solo bufer. Lo que guardar� la
	// imagen para luego mostrarla. Y el modo GLUT_RGB se asigna el modo
	// color. RGB resume "Red, Green, Blue".
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// El tama�o de la ventana 500 P�xeles de ancho y alto.  
	glutInitWindowSize(1080, 1920);
	// Indica la posici�n de la ventana.
	glutInitWindowPosition(0, 0);
	// Define la ventana y le a�ade el t�tulo "simple".
	glutCreateWindow("simple");
	// Enviar una funci�n para que se ejecute de forma independiente. Se
	// dice que es conectar la se�al "display".
	glutDisplayFunc(display);

	// Empieza todo lo dicho anteriormente. Se mantiene ejecutando la
	// ventana y esperando cualquier evento dicho anteriormente, u otros
	// predefinido por glut. Por ejemplo, se espera que alguien presione
	// la x de la ventana para salir del programa.


	// Identificadores de los men�s
	int menuColor, menuPrincipal;
	// Crear submen� y asociarle su funci�n de respuesta
	menuColor = glutCreateMenu(RespuestaMenuColor);
	glutAddMenuEntry("Rojo", 1);
	glutAddMenuEntry("Verde", 2);
	glutAddMenuEntry("Azul", 3);
	// Crear men� principal y asociarle su funci�n de respuesta

	menuPrincipal = glutCreateMenu(RespuestaMenuPrincipal);
	glutAddMenuEntry("Luz", 1);
	glutAddMenuEntry("Material", 2);
	glutAddSubMenu("Color", menuColor);
	// Asociar el men� al bot�n derecho del rat�n
	glutAttachMenu(GLUT_RIGHT_BUTTON);




	glutMainLoop();

	return 0;
}

