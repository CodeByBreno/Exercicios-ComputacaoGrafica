#include <stdlib.h>
#include <gl/glut.h>

#define LARGURA_TELA 1920
#define ALTURA_TELA 1080 
#define LARGURA_JANELA 800
#define ALTURA_JANELA 600

void Inicializa(void){
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	
	//Definindo a janela de visualiza��o 2D - o mapeamento dos pixels da tela
	//para numeros com os valores especificados

	//Essa primeira instru��o define qual � a matriz de trabalho atual. Existem algumas
	//op��es, e por enquanto vamos apenas usar "GL_PROJECTION" sem pensar muito sobre isso
	glMatrixMode(GL_PROJECTION);

	//Aqui � definido o mapeamento de pixels na matriz de trabalho atual. No caso, 
	//(0,0) � o Canto Inferior Esquerdo, e (10,10) � o Canto Superior Direito
	gluOrtho2D(0.0, 10.0, 0.0, 10.0);
}

void Desenha(void){
	//Limpando a tela (coloca a cor setada em glClearColor em 
	//todos os pixels da tela
	glClear(GL_COLOR_BUFFER_BIT);

	//Agora vamos desenhar um tri�ngulo vemelho na janela
	//Primeiro setamos a cor com que iremos preencher o objeto - Vermelho
	glColor3f(1.0, 0.0, 0.0);
	
	//Iniciando a cria��o de um objeto
	//O sinalizador "GL_TRIANGLES" indica que estamos criando um triangulo
	glBegin(GL_TRIANGLES);
		//Determinando a localiza��o dos v�rtices na janela de visualiza��o
		glVertex3f(2.0, 2.0, 0);
		glVertex3f(6.0, 2.0, 0);
		glVertex3f(4.0, 6.0, 0);
	glEnd();

	glFlush();
}

//Setando uma fun��o de callback para gerenciar eventos
//Nesse caso, passaremos essa fun��o como par�metro de "glutKeyboardFunc" - na main()
//De modo que ela set� chamada quando houver um evento no teclado
//Os par�metros da fun��o s�o padr�es
void Teclado(unsigned char key, int x, int y)
{
	//Quando a tecla 27 - Esc (ASCII) - for pressionada, finalizamos a execu��o
	if (key == 27) 
		exit(0);
}

int main(void){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//Centralizando a janela na tela
	glutInitWindowPosition((int)(LARGURA_TELA/2 - LARGURA_JANELA/2), (int)(ALTURA_TELA/2 - ALTURA_JANELA/2));

	//Setando as dimens�es da tela
	glutInitWindowSize(LARGURA_JANELA, ALTURA_JANELA);

	//Ap�s setar as confiura��es da janela, crio-a
	glutCreateWindow("Primeiro Programa");
	glutDisplayFunc(Desenha);
	Inicializa();

	//Passa a execu��o para a GLUT, o processador de eventos do OpenGL. Depois dessa instru��o,
	//nenhuma outra do nosso c�digo ser� executada
	glutKeyboardFunc(Teclado); //Estabelecendo a fun��o que manipula eventos do teclado
	glutMainLoop();
}
