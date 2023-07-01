#include <stdio.h>
#include <gl/glut.h>

#define LARGURA_TELA 1920
#define ALTURA_TELA 1080 
#define LARGURA_JANELA 900
#define ALTURA_JANELA 900

void Inicializar(void){
	//Setando a cor de limpeza do buffer de cores
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//Setando a janela de trabalho
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-50.0, 50.0, -50.0, 50.0); //Mapeamento das dimensões da janela
}

void Desenha(void){
	//Limpando o buffer com a cor definida por glClearColor
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(6.0);
	
	//Desenhando as linhas e colocando as cores
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-35.0, -30.0);
		glVertex2f(-10.0, -2.0);
		//Final da primeira linha. Coloquei aqui para que os pontos 
		//tenham cores diferentes, e assim surge o degradê
		glVertex2f(-10.0, -2.0);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(0.0, 30.0);

		glVertex2f(0.0, 30.0);
		glVertex2f(10.0, -2.0);

		glVertex2f(10.0, -2.0);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(35.0, -30.0);

		glVertex2f(35.0, -30.0);
		glVertex2f(0.0, -18.0);				
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
