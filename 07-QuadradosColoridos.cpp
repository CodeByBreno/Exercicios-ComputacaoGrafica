#include <stdio.h>
#include <gl/glut.h>

#define LARGURA_TELA 1280
#define ALTURA_TELA 720 
#define LARGURA_JANELA 600
#define ALTURA_JANELA 600

void Inicializar(void){
	//Setando a cor de limpeza do buffer de cores
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);

	//Setando a janela de trabalho
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-50.0, 50.0, -50.0, 50.0); //Mapeamento das dimensões da janela
}

void Desenha(void){
	//Limpando o buffer com a cor definida por glClearColor
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Desenhando uns quadrados
	glBegin(GL_QUADS);
		//Quadrado Amarelo
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(-35.0, 0.0);
		glVertex2f(-20.0, 15.0);
		glVertex2f(-5.0, 0.0);
		glVertex2f(-20.0, -15.0);

		//Quadrado Vermelho
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(35.0, 0.0);
		glVertex2f(20.0, 15.0);
		glVertex2f(5.0, 0.0);
		glVertex2f(20.0, -15.0);

		//Quadrado Azul
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(0.0, 35.0);
		glVertex2f(15.0, 20.0);
		glVertex2f(0.0, 5.0);
		glVertex2f(-15.0, 20.0);

		//Quadrado Preto
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(0.0, -35.0);
		glVertex2f(15.0, -20.0);
		glVertex2f(0.0, -5.0);
		glVertex2f(-15.0, -20.0);

	glEnd();
	//Renderizando mudanças
	glFlush();
}

int main(){
	//Setando o modo do OpenGL com apenas um buffer de cores e cor em RGB
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );

	//Criando uma janela no SO
	glutInitWindowPosition((int)(LARGURA_TELA/2 - LARGURA_JANELA/2), (int)(ALTURA_TELA/2 - ALTURA_JANELA/2));
	glutInitWindowSize(LARGURA_JANELA, ALTURA_JANELA);
	glutCreateWindow("Primitivas Gráficas");

	//Setando a função padrão de desenho
	glutDisplayFunc(Desenha);
	
	Inicializar();
	//Loop de callback e captura de eventos
	glutMainLoop();
}
