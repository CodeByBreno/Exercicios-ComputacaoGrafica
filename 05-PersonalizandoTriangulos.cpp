#include <stdlib.h>
#include <gl/glut.h>

#define LARGURA_TELA 1280
#define ALTURA_TELA 720 
#define LARGURA_JANELA 800
#define ALTURA_JANELA 600
#define LADO_TRIANGULO 30

void Inicializa(void){
	glClearColor(1.0f, 1.0f, 0.2f, 0.5f);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-20.0, 20.0, -20.0, 20.0);
}

void Desenha(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	
	glBegin(GL_TRIANGLES);
		glColor3f(0.87f, 0.0f, 0.73f);
		glVertex3f(-LADO_TRIANGULO/2, -LADO_TRIANGULO*0.2886, 0);
		glColor3f(0.45f, 0.29f, 0.96f);
		glVertex3f(LADO_TRIANGULO/2, -LADO_TRIANGULO*0.2886, 0);
		glColor3f(0.46f, 0.05f, 0.67f);
		glVertex3f(0.0, LADO_TRIANGULO*0.577, 0);
	glEnd();

	glFlush();
}

void Teclado(unsigned char key, int x, int y)
{
	if (key == 27) 
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
