#include <stdlib.h>
#include <gl/glut.h>

void Inicializa(void){
	//Coloca a cor informada no Buffer de Cor
	//Essa ser� a cor a ser utilizada ao limpar a tela
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void Desenha(void){
	//Limpa o buffer de cor especificado no sinalizador GL_COLOR_BUFFER_BIT
	//Nesse caso, temos apenas um buffer de cor, e � ele quem est� sendo limpo
	//Ao fazer isso, o valor da cor dos bits da tela (presente no buffer de cor) 
	//� atualizado com aquele setado pela fun��o glutClearColor
	glClear(GL_COLOR_BUFFER_BIT);

	//Realiza todas as a��es pendentes de atualiza��o no OpenGL
	glFlush();
}

int main(void){
	//Inicializa o OpenGL e estabelece o modo de opera��o. Nesse caso, selecionamos
	//um modo com apenas um buffer de cor (sinalizador GLUT_SINGLE) e com modo de cor
	//RGBA (GLUT_RGB) (RGB com n�vel de opacidade)
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	//Cria uma janela com t�tulo "Primeiro Programa"
	glutCreateWindow("Primeiro Programa");

	//Estabelece qual a fun��o que ser� usada para desenhar a tela. Nesse caso, � a fun��o
	//"desenha"
	glutDisplayFunc(Desenha);

	//Executa a fun��o Inicializa - setando o valor da cor para aquele especificado
	Inicializa();

	//Inicia o loop principal do glut. Mais detalhes sobre isso depois
	glutMainLoop();
}
