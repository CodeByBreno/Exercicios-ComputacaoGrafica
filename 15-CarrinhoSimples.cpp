#include <stdio.h>
#include <math.h>
#include <gl/glut.h>
#include <stdlib.h>

#define LARGURA_TELA 1280
#define ALTURA_TELA 720 
#define LARGURA_JANELA 700
#define ALTURA_JANELA 700
#define CIRCLE_PRECISION 1000
#define SPEED 5.0f

void DrawRectangle(float x0, float  y0, float width, float height){
	glBegin(GL_QUADS);
		glVertex2f(x0, y0);
		glVertex2f(x0 + width, y0);
		glVertex2f(x0 + width, y0 - height);
		glVertex2f(x0, y0 - height);
	glEnd();
}

void DrawCircle(float r, float x0, float y0){
    int precision = CIRCLE_PRECISION;
	float a = (float) 360/precision; //Taxa de variação do ângulo
	glBegin(GL_POLYGON);
		for(int x = 0; x < precision; x++){
			glVertex2f(r*cos(a*x) + x0, r*sin(a*x) + y0);
		}
	glEnd();
}

void DesenhaCarro(){
	glLineWidth(10.0);
	glColor3f(1.0f, 0.0f, 0.0f);

	DrawRectangle(-30.0, 0.0f, 60.0f, 20.0f);   //Corpo
	DrawRectangle(-20.0f, 12.0f, 40.0f, 15.0f); //Cabine 
	glColor3f(1.0f, 1.0f, 1.0f);
	DrawRectangle(-18.0f, 10.0f, 20.0f, 10.0f); //Vidro
	DrawRectangle(4.0f, 10.0f, 14.0f, 10.0f);
	DrawRectangle(26.0f, -2.0f, 6.0f, 4.0f);   //Farol
	DrawRectangle(-32.0f, -2.0f, 6.0f, 4.0f);   //Farol
	glColor3f(0.6f, 0.6f, 0.6f);
	DrawRectangle(-32.0f, -16.0f, 64.0f, 4.0f);	

	//Rodas
	glColor3f(0.0f, 0.0f, 0.0f);
	DrawCircle(10.0, -15.0, -20.0);   //Parte de fora         
	DrawCircle(10.0, 15.0, -20.0); 
	glColor3f(0.8f, 0.8f, 0.8f);
	DrawCircle(5.0, -15.0, -20.0);    //Parte de Dentro
	DrawCircle(5.0, 15.0, -20.0);
}

void Desenha(){
	glClear(GL_COLOR_BUFFER_BIT);
	glScalef(0.4, 0.4f, 0.0f);
	DesenhaCarro();
	glFlush();
}

void Teclado(unsigned char key, int x, int y)
{
	if (key == 97) 
		glTranslatef(-SPEED, 0.0f, 0.0f);
	if (key == 100) 
		glTranslatef(SPEED, 0.0f, 0.0f);

	glClear(GL_COLOR_BUFFER_BIT);
	DesenhaCarro();
	glFlush();
}

void ConstroiTela(void){
    glutInitWindowSize(LARGURA_JANELA, ALTURA_JANELA);        
    glutInitWindowPosition(LARGURA_TELA/2 - LARGURA_JANELA/2,
						   ALTURA_TELA/2 - ALTURA_JANELA/2);
    glutCreateWindow("Foguete");  
}

void Inicializar(void){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    gluOrtho2D(-50.0, 50.0, -50.0, 50.0); 
	glClearColor(0.1f, 0.1f, 0.15f, 1.0f); 
}

int main() {
	//Inicializando o glut e setando apenas um buffer de cor com cores RGB
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	ConstroiTela();
	Inicializar();

    glutDisplayFunc(Desenha);    //Estabelecendo a função básica para desenho da tela 

	glutKeyboardFunc(Teclado);
    glutMainLoop();
    return 0;
}
