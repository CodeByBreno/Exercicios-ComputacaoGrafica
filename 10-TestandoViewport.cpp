#include <stdio.h>
#include <gl/glut.h>

#define LARGURA_TELA 1280
#define ALTURA_TELA 720 
#define LARGURA_JANELA 700
#define ALTURA_JANELA 700

void DesenhaNavinha(){
	//Desenhando vários pontinhos
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
}

void DesenhaLinhasColoridas(){
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
}

void DesenhaAlvo(){
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
}

void DesenhaQuadradosColoridos(){
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
}

void ConstroiTela(void){
	//Definindo as características da Janela de Exibição a ser apresentada na tela
    glutInitWindowSize(LARGURA_JANELA, ALTURA_JANELA);        //Dimensoões
    glutInitWindowPosition(LARGURA_TELA/2 - LARGURA_JANELA/2, //Centralizando na tela
						   ALTURA_TELA/2 - ALTURA_JANELA/2);
    glutCreateWindow("Viewport");      //Criando a janela e dando o título "Viewport"
}

void Inicializar(void){
	//Vou trabalhar com uma projeção ortogonal, então utilizo a matriz GL_PROJECTION
	//no cálculo do posicionamento dos elementos após transformações
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  //Carregando a matriz identidade como a mat. de transformações inicial
    gluOrtho2D(-50.0, 50.0, -50.0, 50.0); //Setando a Janela de Seleção e seu sistema de coordenadas

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //Colocando a cor de "limpeza" do buffer
										  //como branco
}

void DesenhaViewport1(void) {
    glViewport(0, 0, LARGURA_JANELA/2, ALTURA_JANELA/2);  //Começo desenhando a própria viewport

	//Agora é só fazer um desenho dentro dela. As coordenadas são exatamente as
	//mesmas definidas para a janela, -50.0 à 50.0 para X e Y
    
	//Vou usar os desenhos feitos em questões anteriores pra ficar mais bonitinho
	//Como trabalhei com janelas -50.0x50.0 em todos, vai dar certo!
	
	//Desenhando o background
	glBegin(GL_QUADS);
		glColor3f(0.08f, 0.07f, 0.1f);
		glVertex2f(-50.0, -50.0);
		glVertex2f(-50.0, 50.0);
		glVertex2f(50.0, 50.0);
		glVertex2f(50.0, -50.0);
	glEnd();

	DesenhaNavinha();
}

void DesenhaViewport2(void) {
    glViewport(LARGURA_JANELA/2, ALTURA_JANELA/2, LARGURA_JANELA/2, ALTURA_JANELA/2); //Desenho uma viewport para ficar no canto superior direito

	//Desenhando o fundo verdinho
	glBegin(GL_QUADS);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(-50.0, -50.0);
		glVertex2f(-50.0, 50.0);
		glVertex2f(50.0, 50.0);
		glVertex2f(50.0, -50.0);
	glEnd();

	DesenhaQuadradosColoridos();
}

void DesenhaViewport3(){
	glViewport(0, ALTURA_JANELA/2, LARGURA_JANELA/2, ALTURA_JANELA/2);

	//Desenhando o fundo com a cor preta
	glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(-50.0, -50.0);
		glVertex2f(-50.0, 50.0);
		glVertex2f(50.0, 50.0);
		glVertex2f(50.0, -50.0);
	glEnd();
	DesenhaLinhasColoridas();
}

void DesenhaViewport4(){
	//Viewport no Canto Inferior Direito
	glViewport(LARGURA_JANELA/2, 0, LARGURA_JANELA/2, ALTURA_JANELA/2);

	//Background
	glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(-50.0, -50.0);
		glVertex2f(-50.0, 50.0);
		glVertex2f(50.0, 50.0);
		glVertex2f(50.0, -50.0);
	glEnd();

	DesenhaAlvo();
}

void Desenha(void) {
    glClear(GL_COLOR_BUFFER_BIT);     //Limpando o buffer de cores e colocando a cor setada
									  //em glClearColor() em todos os pixels
	DesenhaViewport1(); //Canto Inferior Esquerdo
	DesenhaViewport2(); //Canto Superior Direito
	DesenhaViewport3();	//Canto Superior Esquerdo
	DesenhaViewport4(); //Canto Inferior Direito

    glFlush();                        //Renderizando os efeitos
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

