#include <stdio.h>
#include <gl/glut.h>

#define LARGURA_TELA 1280
#define ALTURA_TELA 720 
#define LARGURA_JANELA 700
#define ALTURA_JANELA 700

void DesenhaFoguete(){
	//Ponta do Foguete
	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.3, 0.3);
		glVertex2f(-8.0, 25.0);
		glVertex2f(8.0, 25.0);
		glVertex2f(0.0, 45.0);
	glEnd();

	//Corpo
	glBegin(GL_QUADS);
		glColor3f(0.9, 0.9, 0.85);
		glVertex2f(-8.0, 25.0);	
		glVertex2f(8.0, 25.0);
		glVertex2f(8.0, -30.0);	
		glVertex2f(-8.0,-30.0);	
	glEnd();

	//Asas e Propulsor
	glBegin(GL_QUADS);
		glColor3f(0.3, 0.3, 1.0);

		//Asa Direita
		glVertex2f(8.0, -30.0);	
		glVertex2f(8.0, -10.0);
		glVertex2f(18.0, -20.0);
		glVertex2f(18.0, -40.0);

		//Asa Esquerda
		glVertex2f(-8.0, -30.0);	
		glVertex2f(-8.0, -10.0);
		glVertex2f(-18.0, -20.0);
		glVertex2f(-18.0, -40.0);

		//Propulsor
		glColor3f(0.7, 0.7, 0.5);
		glVertex2f(8.0, -30.0);	
		glVertex2f(-8.0, -30.0);
		glVertex2f(-4.0, -40.0);
		glVertex2f(4.0, -40.0);
	glEnd();

	glPointSize(2.0);
	glBegin(GL_POINTS);
		glVertex2f(2.0, -45.0);
		glVertex2f(0.0, -50.0);
		glVertex2f(-1.0, -48.0);
		glVertex2f(-3.0, -42.0);
		glVertex2f(-2.0, -47.0);
		glVertex2f(-3.0, -43.0);
		glVertex2f(-1.0, -52.0);
		glVertex2f(1.0, -54.0);
		glVertex2f(0.0, -56.0);
		glVertex2f(1.0, -42.0);
		glVertex2f(-1.0, -44.0);
		glVertex2f(3.0, -41.0);
		glVertex2f(-1.0, -58.0);
		glVertex2f(1.0, -60.0);
	glEnd();
}

void Desenha(){
	glClear(GL_COLOR_BUFFER_BIT);

	//Rotacionando
	glRotatef(45.0, 0.0f, 0.0f, 1.0f); //Girando em torno do vetor do eixo z
	//Redimensionando
	glScalef(0.25f, 0.25f, 0.25f); //Reduz o tamanho em 4 vezes

	DesenhaFoguete(); //Desenho o foguete

	//Transladando o Foguete
	glTranslatef(100.0f, 100.0f, 0.0f); //Ao modificar a escala, as dimens�es [-50, 50] 
									    //viraram [-250, 250]
										//Cuidado! O Sistema de Coordenadas foi rotacionado!
	DesenhaFoguete(); //Desenho um novo foguete. As matrizes de transforma��o anteriores 
					  //Continuam salvas, logo, ele tamb�m estar� rotacionado e redimensionado
					  //(Assim como o primeiro)

	//Desenhando mais um foguete
	glTranslatef(-100.0f, -100.0f, 0.0f); //Desfazendo a �ltima transla��o
	glTranslatef(100.f, -100.0f, 0.0f);   //Como o sistema de coordenadas est� rotacionado
										  //em 45�, isso vai colocar o foguete � direita
										  //do anterior
	DesenhaFoguete();

	//Desenhando um novo foguete
	glLoadIdentity(); //Carrego a matriz identidade. Todas as transforma��es anteriores
					  //se foram

	//� preciso reduzir dr�sticamente a escala do foguete para que ele n�o fique gigante
	//na tela.
	glScalef(0.015f, 0.015f, 0.015f); //O foguete ter� o triplo de tamanho dos anteriores
								      //explica��es abaixo:

	//Mas porque isso?
	//Bom, os foguetes anteriores, desenhados na mesma tela, foram feitos numa escala
	//4 vezes menor do que [-50, 50]
	//Portanto, ao desenhar um objeto na escala [-50, 50], ele ser� 4*50 = 200 vezes
	//maior que os objetos desenhados na escala anterior!

	glTranslatef(-25.0f, -25.0f, 0.0f);

	//** na verdade n�o � bem isso. � [-50.0, 50.0] em rela��o ao que j� se havia
	//construido antes
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	DesenhaFoguete();

	//Mais um foguete
	glTranslatef(35.55f, 0.0f, 0.0f); //Colocando o centro do sistema de volta no meio da 
									  //tela. Lembre da rota��o de 45� feita antes
	//Antes da rota��o tinhamos ido 25 para baixo e 25 para esquerda
	//Agora que rotacionamos, precisamos nos mover para nordeste
	//O valor que precisaremos mover � dado pelo teorema de pit�goras: sqrt(25^2 + 25^2)
	//Ou seja, � a diagonal do quadrado de lado 25. 25*sqrt(2)

	glScalef(0.5f, 0.5f, 0.5f);       //Agora vou fazer um com metade do tamanho do anterior
	glTranslatef(0.0f, -100.0f, 0.0f);   //O sistema � relativamente o dobro do anterior,
									  //ou seja, [100, 100]
	DesenhaFoguete();

	//Mais um foguete...
	//Desfazendo a �ltima transla��o ANTES de fazer uma rota��o, para n�o complicar a 
	//geometria
	glTranslatef(0.0f, 100.0f, 0.0f);
	glScalef(0.5f, 0.5f, 0.5f); //Um bem pequeno, com metade do tamanho do anterior
	glTranslatef(0.0f, 200.0f, 0.0f); //Escala foi pra 500...

	DesenhaFoguete();
	glFlush();
	return;
}

void ConstroiTela(void){
    glutInitWindowSize(LARGURA_JANELA, ALTURA_JANELA);        
    glutInitWindowPosition(LARGURA_TELA/2 - LARGURA_JANELA/2,
						   ALTURA_TELA/2 - ALTURA_JANELA/2);
    glutCreateWindow("Foguete");  
}

void Inicializar(void){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    gluOrtho2D(-50.0, 50.0, -50.0, 50.0); 
	glClearColor(0.1f, 0.1f, 0.15f, 1.0f); 
}

int main() {
	//Inicializando o glut e setando apenas um buffer de cor com cores RGB
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	ConstroiTela();
	Inicializar();

    glutDisplayFunc(Desenha);    //Estabelecendo a fun��o b�sica para desenho da tela 

    glutMainLoop();
    return 0;
}
