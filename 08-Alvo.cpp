#include <stdio.h>
#include <gl/glut.h>

#define LARGURA_TELA 1280
#define ALTURA_TELA 720 
#define LARGURA_JANELA 600
#define ALTURA_JANELA 600

void Inicializar(void){
	//Setando a cor de limpeza do buffer de cores
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f);

	//Setando a janela de trabalho
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-50.0, 50.0, -50.0, 50.0); //Mapeamento das dimensões da janela
}

void Desenha(void){
	//Limpando o buffer com a cor definida por glClearColor
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(10.0);

	//Desenhando o quadrado central
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-25.0, 25.0);
		glVertex2f(-25.0, -25.0);
		glVertex2f(25.0, -25.0);
		glVertex2f(25.0, 25.0);
	glEnd();

	//Desenhando as linhas do alvo
	glBegin(GL_LINES);
		//Linha na esquerda
		glVertex2f(-50.0, 0.0);
		glVertex2f(-5.0, 0.0);

		//Linha na direita
		glVertex2f(50.0, 0.0);
		glVertex2f(5.0, 0.0);

		//Linha de Cima
		glVertex2f(0.0, 50.0);
		glVertex2f(0.0, 5.0);

		//Linha de Baixo
		glVertex2f(0.0, -50.0);
		glVertex2f(0.0, -5.0);
		
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
