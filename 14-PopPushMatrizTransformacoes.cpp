#include <stdio.h>
#include <gl/glut.h>
#include <math.h>

#define LARGURA_TELA 1280
#define ALTURA_TELA 720 
#define LARGURA_JANELA 700
#define ALTURA_JANELA 700
#define CIRCLE_PRECISION 1000

void DrawCircle(float r, float x0, float y0){
    int precision = CIRCLE_PRECISION;
	float a = (float) 360/precision; //Taxa de variação do ângulo
	glBegin(GL_POLYGON);
		for(int x = 0; x < precision; x++){
			glVertex2f(r*cos(a*x) + x0, r*sin(a*x) + y0);
		}
	glEnd();
}

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

	glPushMatrix(); //Guardo a matriz original
		//Foguete 1
		glTranslatef(40.0f, -30.0f, 0.0f); //Translate antes de rotacionar e redimensionar, 
										   //assim o sistema de coordenadas não terá mudado!
		glScalef(0.25f, 0.25f, 0.0f);
		glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
		DesenhaFoguete();
	glPopMatrix(); //Jogo fora a matriz modificada, e volto a usar a original
	//Dessa maneira, garanto a independência completa entre as formatações!

	//Foguete 2
	glPushMatrix();//Guardo a matrix inicial de novo, senão ela já era 
		glTranslatef(-40.0f, -30.0f, 0.0f); //Translate antes de rotacionar e redimensionar, assim
										  //o sistema de coordenadas não terá mudado!
		glScalef(0.25f, 0.25f, 0.0f);
		glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
		DesenhaFoguete();
	glPopMatrix(); //Recupero a matriz original! Sem mais ter que ficar pensando aquele
				   //Monte de detalhes sobre as matrizes!

	//Foguete 3
	glPushMatrix();
		glTranslatef(-25.0f, -14.0f, 0.0f);
		glScalef(0.4f, 0.4f, 0.0f);
		glRotatef(30.0f, 0.0f, 0.0f, 1.0f);
		DesenhaFoguete();
	glPopMatrix();

	//Foguete 4
	glPushMatrix();
		glTranslatef(25.0f, -14.0f, 0.0f);
		glScalef(0.4f, 0.4f, 0.0f);
		glRotatef(-30.0f, 0.0f, 0.0f, 1.0f);
		DesenhaFoguete();
	glPopMatrix();

	//Foguete 5
	glPushMatrix();
		glTranslatef(0.0f, 0.0f, 0.0f);
		glScalef(0.55f, 0.55f, 0.0f);
		DesenhaFoguete();
	glPopMatrix();

	glColor3f(0.1f, 0.6f, 0.1f);
	DrawCircle(50, 0.0f, -85.0f);
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

    glutDisplayFunc(Desenha);    //Estabelecendo a função básica para desenho da tela 

    glutMainLoop();
    return 0;
}
