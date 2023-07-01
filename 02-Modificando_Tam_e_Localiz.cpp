#include <stdlib.h>
#include <gl/glut.h>

#define LARGURA_TELA 1920
#define ALTURA_TELA 1080 
#define LARGURA_JANELA 800
#define ALTURA_JANELA 600

void Inicializa(void){
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	
	//Definindo a janela de visualização 2D
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 10.0, 0.0, 10.0);
}

void Desenha(void){
	//Limpando a tela (coloca a cor setada em glClearColor em 
	//todos os pixels da tela
	glClear(GL_COLOR_BUFFER_BIT);

	//Agora vamos desenhar um triângulo
	glColor


	glFlush();
}

int main(void){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//Centralizando a janela na tela
	glutInitWindowPosition((int)(LARGURA_TELA/2 - LARGURA_JANELA/2), (int)(ALTURA_TELA/2 - ALTURA_JANELA/2));

	//Setando as dimensões da tela
	glutInitWindowSize(LARGURA_JANELA, ALTURA_JANELA);

	//Após setar as confiurações da janela, crio-a
	glutCreateWindow("Primeiro Programa");
	glutDisplayFunc(Desenha);
	Inicializa();

	//Passa a execução para a GLUT, o processador de eventos do OpenGL. Depois dessa instrução,
	//nenhuma outra do nosso código será executada
	glutMainLoop();
}
