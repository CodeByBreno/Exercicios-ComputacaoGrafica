#include <stdio.h>
#include <gl/glut.h>

#define LARGURA_TELA 1280
#define ALTURA_TELA 720 
#define LARGURA_JANELA 800
#define ALTURA_JANELA 600

void Inicializar(void){
	//Setando a cor de limpeza do buffer de cores
	glClearColor(0.08f, 0.07f, 0.1f, 1.0f);

	//Setando a janela de trabalho
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-50.0, 50.0, -50.0, 50.0); //Mapeamento das dimensões da janela
}

void Desenha(void){
	//Limpando o buffer com a cor definida por glClearColor
	glClear(GL_COLOR_BUFFER_BIT);

	//Desenhando vários pontinhos
	
	glPointSize(2.0);
	glBegin(GL_POINTS);
		for(int i = -50; i < 50; i++){
			for(int j = -50; j < 50; j++){
				if (i*j % 5 == 0){
					glVertex2f(i, j);
				}
			}
		}
	glEnd();

	//Desenhando os eixos
	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-50.0, 0.0);
		glVertex2f(50.0, 0.0);

		glVertex2f(0.0, -50.0);
		glVertex2f(0.0, 50.0);
	glEnd();

	//Desenhando uma navinha
	glBegin(GL_LINES);
		glColor3f(0.0f, 0.8f, 0.6f);
		glVertex2f(-20.0, -20.0);
		glVertex2f(-10.0, -20.0);

		glVertex2f(-10.0, -20.0);
		glVertex2f(-5.0, -15.0);

		glVertex2f(-5.0, -15.0);
		glVertex2f(5.0, -15.0);

		glVertex2f(5.0, -15.0);
		glVertex2f(10.0, -20.0);

		glVertex2f(10.0, -20.0);
		glVertex2f(20.0, -20.0);
		
		glVertex2f(20.0, -20.0);
		glVertex2f(0.0, 30.0);
	
		glVertex2f(0.0, 30.0);
		glVertex2f(-20.0, -20.0);

		glVertex2f(0.0, 10.0);
		glVertex2f(-5.0, -5.0);

		glVertex2f(-5.0, -5.0);
		glVertex2f(5.0, -5.0);

		glVertex2f(5.0, -5.0);
		glVertex2f(0.0, 10.0);		
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
