#include <cmath>
#include <stdio.h>
#include <conio.h>
#include <GL\glut.h>

int n = 4;
float alpha;
float Pi = 3.14159265358979323846;

//Primitiva 01 - Polígono circunscrito
int P01 = 1;
float lado01;
float perimetro01;
float Pi_aproximado01;
float R01 = 0.3, G01 = 0.3, B01 = 0.3;

//Primitiva 02 - Polígono inscrito
int P02 = 1;
float lado02;
float perimetro02;
float Pi_aproximado02;
float R02 = 0.8, G02 = 0.8, B02 = 0.8;

//Pontos da Cincunferência
float xc, yc;

//Função responsável pelo esquema (design) da tela.
void Layout(){
	
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);//Por algum motivo se eu tiro esse glBeguin(GL_QUADS);
	glEnd();//e esse glEnd();
	//o programa fica misturando as cores dos poligonos com o layout dos simbolos laterais
	
    //Layout de controle do número de lados
	//Diminui o número de lados n--
	glBegin(GL_QUADS);
		glVertex2f(2.1, 0.9);
		glVertex2f(2.1, 1.1);
		glVertex2f(2.9, 1.1);
		glVertex2f(2.9, 0.9);
	glEnd();	
	
	//Aumenta o número de lados n++
	glBegin(GL_QUADS);
		glVertex2f(2.1, 0.1);
		glVertex2f(2.1, -0.1);
		glVertex2f(2.9, -0.1);
		glVertex2f(2.9, 0.1);
		
		glVertex2f(2.4, -0.4);
		glVertex2f(2.4, 0.4);
		glVertex2f(2.6, 0.4);
		glVertex2f(2.6, -0.4);
	glEnd();
 
    //Pi
    glBegin(GL_QUADS);
    	glVertex2f(2.1,-0.6);
		glVertex2f(2.1,-0.7);
		glVertex2f(2.9,-0.7);
		glVertex2f(2.9,-0.6);
		
		glVertex2f(2.3,-0.6);
		glVertex2f(2.3,-1.3);
		glVertex2f(2.4,-1.3);
		glVertex2f(2.4,-0.6);
		
		glVertex2f(2.6,-0.6);
		glVertex2f(2.6,-1.2);
		glVertex2f(2.7,-1.2);
		glVertex2f(2.7,-0.6);
		
		glVertex2f(2.7,-1.1);
		glVertex2f(2.7,-1.2);
		glVertex2f(2.8,-1.2);
		glVertex2f(2.8,-1.1);
	
		glVertex2f(2.7,-1.2);
		glVertex2f(2.7,-1.3);
		glVertex2f(2.9,-1.3);
		glVertex2f(2.9,-1.2);
		
	glEnd();
	//Cores do polígono circunscrito (Primitiva 01)
	//Cinza
	glBegin(GL_QUADS);
		glColor3f(0.3, 0.3, 0.3);
		glVertex2f(2, 2);
		glVertex2f(2, 1.5);
		glVertex2f(2.25, 1.5);
		glVertex2f(2.25, 2);

	//Vermelho
		glColor3f(0.3, 0, 0);
		glVertex2f(2.25, 2);
		glVertex2f(2.25, 1.5);
		glVertex2f(2.5, 1.5);
		glVertex2f(2.5, 2);

	//Verde
		glColor3f(0, 0.3, 0);
		glVertex2f(2.5, 2);
		glVertex2f(2.5, 1.5);
		glVertex2f(2.75, 1.5);
		glVertex2f(2.75, 2);

	//Azul
		glColor3f(0, 0, 0.3);
		glVertex2f(2.75, 2);
		glVertex2f(2.75, 1.5);
		glVertex2f(3, 1.5);
		glVertex2f(3, 2);
	
	//Cores do polígono inscritos (Primitiva 02)
	//Cinza
		glColor3f(0.8, 0.8, 0.8);
		glVertex2f(2, -2);
		glVertex2f(2, -1.5);
		glVertex2f(2.25, -1.5);
		glVertex2f(2.25, -2);

	//Vermelho
		glColor3f(0.8, 0, 0);
		glVertex2f(2.25, -2);
		glVertex2f(2.25, -1.5);
		glVertex2f(2.5, -1.5);
		glVertex2f(2.5, -2);

	//Verde
		glColor3f(0, 0.8, 0);
		glVertex2f(2.5, -2);
		glVertex2f(2.5, -1.5);
		glVertex2f(2.75, -1.5);
		glVertex2f(2.75, -2);

	//Azul
		glColor3f(0, 0, 0.8);
		glVertex2f(2.75, -2);
		glVertex2f(2.75, -1.5);
		glVertex2f(3, -1.5);
		glVertex2f(3, -2);
	
	glEnd();
	
	//Linhas de Contorno
	glLineWidth(5);
    glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
       	glVertex2f( -2, -2);
		glVertex2f(  3, -2);	 
		glVertex2f(  3,  2);
		glVertex2f( -2,  2);
	glEnd();
	
	glBegin(GL_LINES);
		glColor3f(0, 0, 0);	
	   	glVertex2f( 2,-2);	 
		glVertex2f( 2, 2);
	
	 for(float i = -1.5; i <= 3; i++){
	 	glVertex2f(2, i);
	 	glVertex2f(3, i);
	 }
	 for(float i = 2.25; i <= 3; i += 0.25){
	 	glVertex2f(i, -2);
	 	glVertex2f(i, -1.5);
	 	glVertex2f(i, 2);
	 	glVertex2f(i, 1.5);
	}
	
	glEnd();
	
	//Circunferencia de raio 1
	// x^2 + y^2 = 1
	glPointSize(4);
	glBegin(GL_POINTS);	
	
		for (xc =-1 ; xc < 1; xc+=0.00001){
			yc = pow(1-xc*xc, 0.5);
			
			glVertex2f( xc, yc);	 
			glVertex2f( xc,-yc);	 
		}
	
	glEnd();    
}

// Polígono Circunscrito (Primitiva 01)
void Primitiva1(){
	
	float x, y;
	float a, b;
	
	float beta;
	float gama;
	
	alpha = 2 * Pi/n;
	gama = alpha/2;
	beta = (Pi - alpha)/2;
	
	y = sin(gama)/sin(beta);
	x = 1;
	lado01 = 2 * y; 
	
	glColor3f(R01, G01, B01);
	glBegin(GL_POLYGON);
		
		glVertex2f(x, y);
		for(int i = 1; i < n; i++){
			a = x * cos(alpha * i) - y * sin(alpha * i);
			b = y * cos(alpha * i) + x * sin(alpha * i);
			
			glVertex2f(a, b);
		}

	glEnd(); 	 
}

// Polígono Inscrito (Primitiva 02)
void Primitiva2(){
	
	float x, y;
	alpha = 2 * Pi/n;
	glColor3f(R02, G02, B02);
	glBegin(GL_POLYGON);
	
		glVertex2f(1, 0);
		for(int i = 1; i < n; i++){
			x = cos(alpha * i);
			y = sin(alpha * i);
			glVertex2f(x, y);
		}
}

void Dados(){
	//Cílculos 
	float Resultado_Pi;
	int diagonais;
	
	alpha = 360/n;
	diagonais = (n - 3) * n/2;
	
	perimetro01 = n * lado01;
	Pi_aproximado01 = perimetro01/2;
	
	lado02 = pow(2 - 2 * cos(2 * Pi/n), 0.5);
	perimetro02 = n * lado02;
	Pi_aproximado02 = perimetro02/2;
	
	Resultado_Pi = Pi_aproximado01 - Pi_aproximado02;
	
	system("cls");
	system("color B");
  
	printf("\n*-- Informacoes  do  Poligono Circunscrito --*\n");
	printf("\n (*) Numero de lados (n): %d", n);
	printf("\n (*) Numero de diagonais (d): %d", diagonais);
	printf("\n (*) Media do Angulo Interno: %.1f", alpha);
	printf("\n (*) Medida do lado: %.4f", lado01);
	printf("\n (*) Perimetro: %.4f", perimetro01);
	printf("\n (*) Pi Aproximado: %.4f", Pi_aproximado01);
	
	printf("\n\n*-- Informacoes  do  Poligono Inscrito --*\n");
	printf("\n (*) Numero de lados (n): %d", n);
	printf("\n (*) Numero de diagonais (d): %d", diagonais);
	printf("\n (*) Media do Angulo Interno: %.1f", alpha);
	printf("\n (*) Medida do lado: %.4f", lado02);
	printf("\n (*) Perimetro: %.4f", perimetro02);
	printf("\n (*) Pi Aproximado: %.4f", Pi_aproximado02);

	printf("\n\n (*) Margem de precisao: %f", Resultado_Pi);
}

void redesenha(){

    glClearColor(0.98,0.98,0.98, 0);
    glClear(GL_COLOR_BUFFER_BIT );  
	
	
	Primitiva1();
	Primitiva2();
	Layout();
		
    glFlush();
}

void Teclado(unsigned char key, int x, int y)
{
	switch(key) {
		case '0':
			Dados();
		break;
		case '1':
	        R01 = 0.3, G01 = 0, B01 = 0; 
		break;
		case '2':
			R01 = 0.0, G01 = 0.3, B01 = 0;
		break;
		case '3':
	        R01 = 0, G01 = 0, B01 = 0.3;
		break;
		case '4':
	        R01 = 0.3, G01 = 0.3, B01 = 0.3;
		break;
		case '5':
	        R02 = 0.8, G02 = 0, B02 = 0;
		break;
		case '6':
	        R02 = 0, G02 = 0.8, B02 = 0;
		break;
		case '7':
	        R02 = 0, G02 = 0, B02 = 0.8;
		break;
		case '8':
	       R02 = 0.8, G02 = 0.8, B02 = 0.8;
		break;
		case '-':
	        n --;
	        if(n < 4)
	        	n = 4;
		break;
		case '+':
	    	n ++;
	    	if(n > 360)
	    		n = 360;
		break;
		case 'C':
		case 'c':
			n = 4;
			R01 = 0.3, G01 = 0.3, B01 = 0.3;
			R02 = 0.8, G02 = 0.8, B02 = 0.8; 
		break;
		case 'I':
	    case 'i':
			n = 360;
		break;
	}
	redesenha();
}
void TeclasEspeciais(int key, int x, int y) {
	
	switch(key) {
		case GLUT_KEY_HOME:
			R01 = 0, G01 = 0, B01 = 0.3;
			R02 = 0.8, G02 = 0.8, B02 = 0.8;
		break;
		
		case GLUT_KEY_END:
			exit(0);
		break;
    }
	redesenha();
}

void Mouse(int button, int state, int x, int y)
{
    if (button == GLUT_RIGHT_BUTTON){
		n = 4;
		R01 = 0.3, G01 = 0.3, B01 = 0.3;
		R02 = 0.8, G02 = 0.8, B02 = 0.8;
    }
    if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)){
  
    	//Selecionar cor da Primitiva1
    	if(y >= 1 and y < 50){
    		if(x >= 400 and x < 425){
    			R01 = 0.3, G01 = 0.3, B01 = 0.3;
			}
			if(x > 425 and x < 450){
    			R01 = 0.3, G01 = 0, B01 = 0;
			}
			if(x > 450 and x < 475){
    			R01 = 0, G01 = 0.3, B01 = 0;
			}
			if(x > 475 and x < 500){
    			R01 = 0, G01 = 0, B01 = 0.3;
			}	
		}
		//Selecionar cor da Primitiva2
		if(y >= 350 and y < 400){
			if(x >= 400 and x < 425){
    			R02 = 0.8, G02 = 0.8, B02 = 0.8;
			}
			if(x > 425 and x < 450){
    			R02 = 0.8, G02 = 0, B02 = 0;
			}
			if(x > 450 and x < 475){
    			R02 = 0, G02 = 0.8, B02 = 0;
			}
			if(x > 475 and x < 500){
    			R02 = 0, G02 = 0, B02 = 0.8;
			}
		}
		//Adição, Subtração e Pi
		if(x >= 400 and x < 500){
			if(y >= 50 and y < 150){
				n --;
				if(n < 4)
					n = 4;
			}
			if(y >= 150 and y < 250){
				n ++;
				if(n > 360)
					n = 360;
			}
			if(y >= 250 and y < 350){
				Dados();
			}
		}	
	}     
	redesenha();
}

int main(int argc, char **argv) {
	
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(500, 400);
    glutInitWindowPosition(450,50);
    glutCreateWindow("AV2: N?mero Pi");
    glutKeyboardFunc(Teclado);
    glutMouseFunc(Mouse);
    glutSpecialFunc(TeclasEspeciais);
    gluOrtho2D(-2, 3, -2, 2);
    glutDisplayFunc(redesenha);

    glutMainLoop();
    
   return(0);
}

