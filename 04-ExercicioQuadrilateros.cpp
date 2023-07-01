#include <stdlib.h>
#include <gl/glut.h>

#define LARGURA_TELA 1280
#define ALTURA_TELA 720 
#define LARGURA_JANELA 800
#define ALTURA_JANELA 600

void Inicializa(void){
	glClearColor(0.95f, 0.92f, 0.76f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 10.0, 0.0, 10.0);
}

void Desenha(void){

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.61, 0.82, 0.73);
	
	glBegin(GL_QUADS);
		//Primeiro Quadrilátero
		glVertex3f(2.0, 4.0, 0);
		glVertex3f(1.0, 8.0, 0);
		glVertex3f(3.0, 8.0, 0);	
		glVertex3f(4.0, 4.0, 0);

		//Terceiro Quadrilátero	
		float slide_horizontal = 3.5;
		float slide_vertical = 0;
		glColor3f(0.92, 0.33, 0.30);
		glVertex3f(2.0 + slide_horizontal, 4.0 - slide_vertical, 0);
		glVertex3f(1.0 + slide_horizontal, 8.0 - slide_vertical, 0);
		glVertex3f(3.0 + slide_horizontal, 8.0 - slide_vertical, 0);	
		glVertex3f(4.0 + slide_horizontal, 4.0 - slide_vertical, 0);

		//Segundo Quadrilátero
		slide_horizontal = 2;
		slide_vertical = 1;
		glColor3f(0.96, 0.71, 0.38);
		glVertex3f(2.0 + slide_horizontal, 4.0 - slide_vertical, 0);
		glVertex3f(1.0 + slide_horizontal, 8.0 - slide_vertical, 0);
		glVertex3f(3.0 + slide_horizontal, 8.0 - slide_vertical, 0);	
		glVertex3f(4.0 + slide_horizontal, 4.0 - slide_vertical, 0);

		//Quarto Quadrilátero
		slide_horizontal = 5.5;
		slide_vertical = 1;
		glColor3f(0.11, 0.31, 0.54);
		glVertex3f(2.0 + slide_horizontal, 4.0 - slide_vertical, 0);
		glVertex3f(1.0 + slide_horizontal, 8.0 - slide_vertical, 0);
		glVertex3f(3.0 + slide_horizontal, 8.0 - slide_vertical, 0);	
		glVertex3f(4.0 + slide_horizontal, 4.0 - slide_vertical, 0);
	
	glEnd();

	glFlush();
}

void Teclado(unsigned char key, int x, int y)
{
	if (key == 27 or key == 81) // Se apertar ESC ou Q, fecha a janela 
		exit(0);
}

int main(void){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition((int)(LARGURA_TELA/2 - LARGURA_JANELA/2), (int)(ALTURA_TELA/2 - ALTURA_JANELA/2));

	glutInitWindowSize(LARGURA_JANELA, ALTURA_JANELA);

	glutCreateWindow("Primeiro Programa");
	glutDisplayFunc(Desenha);
	Inicializa();

	glutKeyboardFunc(Teclado); 
	glutMainLoop();
}
