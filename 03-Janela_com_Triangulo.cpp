#include <stdlib.h>
#include <gl/glut.h>

#define LARGURA_TELA 1920
#define ALTURA_TELA 1080 
#define LARGURA_JANELA 800
#define ALTURA_JANELA 600

void Inicializa(void){
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	
	//Definindo a janela de visualização 2D - o mapeamento dos pixels da tela
	//para numeros com os valores especificados

	//Essa primeira instrução define qual é a matriz de trabalho atual. Existem algumas
	//opções, e por enquanto vamos apenas usar "GL_PROJECTION" sem pensar muito sobre isso
	glMatrixMode(GL_PROJECTION);

	//Aqui é definido o mapeamento de pixels na matriz de trabalho atual. No caso, 
	//(0,0) é o Canto Inferior Esquerdo, e (10,10) é o Canto Superior Direito
	gluOrtho2D(0.0, 10.0, 0.0, 10.0);
}

void Desenha(void){
	//Limpando a tela (coloca a cor setada em glClearColor em 
	//todos os pixels da tela
	glClear(GL_COLOR_BUFFER_BIT);

	//Agora vamos desenhar um triângulo vemelho na janela
	//Primeiro setamos a cor com que iremos preencher o objeto - Vermelho
	glColor3f(1.0, 0.0, 0.0);
	
	//Iniciando a criação de um objeto
	//O sinalizador "GL_TRIANGLES" indica que estamos criando um triangulo
	glBegin(GL_TRIANGLES);
		//Determinando a localização dos vértices na janela de visualização
		glVertex3f(2.0, 2.0, 0);
		glVertex3f(6.0, 2.0, 0);
		glVertex3f(4.0, 6.0, 0);
	glEnd();

	glFlush();
}

//Setando uma função de callback para gerenciar eventos
//Nesse caso, passaremos essa função como parâmetro de "glutKeyboardFunc" - na main()
//De modo que ela setá chamada quando houver um evento no teclado
//Os parâmetros da função são padrões
void Teclado(unsigned char key, int x, int y)
{
	//Quando a tecla 27 - Esc (ASCII) - for pressionada, finalizamos a execução
	if (key == 27) 
		exit(0);
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
	glutKeyboardFunc(Teclado); //Estabelecendo a função que manipula eventos do teclado
	glutMainLoop();
}
