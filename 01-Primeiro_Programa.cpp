#include <stdlib.h>
#include <gl/glut.h>

void Inicializa(void){
	//Coloca a cor informada no Buffer de Cor
	//Essa será a cor a ser utilizada ao limpar a tela
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void Desenha(void){
	//Limpa o buffer de cor especificado no sinalizador GL_COLOR_BUFFER_BIT
	//Nesse caso, temos apenas um buffer de cor, e é ele quem está sendo limpo
	//Ao fazer isso, o valor da cor dos bits da tela (presente no buffer de cor) 
	//é atualizado com aquele setado pela função glutClearColor
	glClear(GL_COLOR_BUFFER_BIT);

	//Realiza todas as ações pendentes de atualização no OpenGL
	glFlush();
}

int main(void){
	//Inicializa o OpenGL e estabelece o modo de operação. Nesse caso, selecionamos
	//um modo com apenas um buffer de cor (sinalizador GLUT_SINGLE) e com modo de cor
	//RGBA (GLUT_RGB) (RGB com nível de opacidade)
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	//Cria uma janela com título "Primeiro Programa"
	glutCreateWindow("Primeiro Programa");

	//Estabelece qual a função que será usada para desenhar a tela. Nesse caso, é a função
	//"desenha"
	glutDisplayFunc(Desenha);

	//Executa a função Inicializa - setando o valor da cor para aquele especificado
	Inicializa();

	//Inicia o loop principal do glut. Mais detalhes sobre isso depois
	glutMainLoop();
}
