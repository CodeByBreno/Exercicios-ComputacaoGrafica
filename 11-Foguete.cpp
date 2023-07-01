#include <stdio.h>
#include <gl/glut.h>

#define LARGURA_TELA 1280
#define ALTURA_TELA 720 
#define LARGURA_JANELA 700
#define ALTURA_JANELA 700

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

void DesenhaFoguete(){
	//Ponta do Foguete
	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.3, 0.3);
		glVertex2f(-8.0, 25.0);
		glVertex2f(8.0, 25.0);
		glVertex2f(0.0, 45.0);
	glEnd();

	//Corpo
	glBegin(GL_QUADS);
		glColor3f(0.9, 0.9, 0.85);
		glVertex2f(-8.0, 25.0);	
		glVertex2f(8.0, 25.0);
		glVertex2f(8.0, -30.0);	
		glVertex2f(-8.0,-30.0);	
	glEnd();

	//Asas e Propulsor
	glBegin(GL_QUADS);
		glColor3f(0.3, 0.3, 1.0);

		//Asa Direita
		glVertex2f(8.0, -30.0);	
		glVertex2f(8.0, -10.0);
		glVertex2f(18.0, -20.0);
		glVertex2f(18.0, -40.0);

		//Asa Esquerda
		glVertex2f(-8.0, -30.0);	
		glVertex2f(-8.0, -10.0);
		glVertex2f(-18.0, -20.0);
		glVertex2f(-18.0, -40.0);

		//Propulsor
		glColor3f(0.7, 0.7, 0.5);
		glVertex2f(8.0, -30.0);	
		glVertex2f(-8.0, -30.0);
		glVertex2f(-4.0, -40.0);
		glVertex2f(4.0, -40.0);
	glEnd();

	glPointSize(5.0);
	glBegin(GL_POINTS);
		glColor3f(0.8f, 0.8f, 0.0f);
		glVertex2f(2.0, -45.0);
		glVertex2f(0.0, -50.0);
		glVertex2f(-1.0, -48.0);
		glVertex2f(-3.0, -42.0);
		glVertex2f(-2.0, -47.0);
		glVertex2f(-3.0, -43.0);
		glVertex2f(-1.0, -52.0);
		glVertex2f(1.0, -54.0);
		glVertex2f(0.0, -56.0);
		glVertex2f(1.0, -42.0);
		glVertex2f(-1.0, -44.0);
		glVertex2f(3.0, -41.0);
		glVertex2f(-1.0, -58.0);
		glVertex2f(1.0, -60.0);
	glEnd();
}

void Desenha(){
	glClear(GL_COLOR_BUFFER_BIT);

	glScalef(0.75f, 0.75f, 0.75f);
	DesenhaFoguete();
	glFlush();
	return;
}

int main() {
	//Inicializando o glut e setando apenas um buffer de cor com cores RGB
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	ConstroiTela();
	Inicializar();

    glutDisplayFunc(Desenha);    //Estabelecendo a função básica para desenho da tela 

    glutMainLoop();
    return 0;
}
