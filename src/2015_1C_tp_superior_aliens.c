/*
 ============================================================================
 Name        : 2015_1C_tp_superior_aliens.c
 Author      : Equipo - Matemática Superior
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Matemática Superior
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define recta1 0
#define recta2 1


/*
=========
VARIABLES 
=========
*/

float a;	/*Termino lineal de la recta1*/
float b;	/*Termino independiente de la recta1*/
float c;	/*Termino lineal de la recta2*/
float d;	/*Termino independiente de la recta2*/
float e1;	/*Error de la recta1*/
float e2;	/*Error de la recta2*/

int i;		/*variable 1 del ciclo*/
int j;		/*variable 2 del ciclo*/
int k;		/*variable 3 del ciclo*/
int m;		/*variable 4 del ciclo*/

int r[5];	/*Recta1*/
int p[5];	/*Recta2*/
int v[8] = {2,3,4,5,6,7,8,9}; /*Punto nºX (0-7), ignorando los primeros 2.*/
int datos[10][2] = { {100,54} , {150,83} , {230,118} , {240,123} , {260,132}, {290,148} , {300,150}, {350,178}, {375,184}, {390,198}};

/*
==========
PROTOTIPOS
==========
*/

int verificarSiCumpleError (int Flag);
float hacerSumatoria(int* columna);
void calcularAB(float sumatoriaX, float sumatoriaY, float sumatoriaX2, float sumatoriaXY);
float calcularError (int* columnaX, int* columnaY);
void determinarElOtroVector(void);
int elOtroVectorVerifica(void);
int cuadrado (int dato);

void imprimirMensaje(void);


/*
==================
PROGRAMA PRINCIPAL
==================
*/

int main(void) {
	r[0] = 0;	/*La primer recta siempre tendrá el punto nº0.*/
	p[0] = 1;	/*La segunda recta siempre tendrá al punto nº1.*/
	for(i=0; i<=7; i++) {
		r[1] = v[i];
		for(j=i+1; j<=7; j++) {
			r[2] = v[j];
			for(k=j+1; k<=7; k++) {
				r[3] = v[k];
				for(m=k+1; m<=7; m++) {
					r[4] = v[m];
				
					if(verificarSiCumpleError(recta1) == -1)	/*Si la funcion retorna 0, significa que su error es menor a 0,3*/
						continue;								/*El -1 ignifica error.*/
	
					if (elOtroVectorVerifica () == -1);			/*Si retorna 0, la 2da rectsa tambien tendrá error <0,3*/
						continue;								/*El -1 significa error.*/
					imprimirMensaje();
				}
			}	
		}
	}
	return EXIT_SUCCESS;
}

/*
=========
FUNCIONES
=========
*/

int verificarSiCumpleError (int Flag){
	int columnaX[5];
	int columnaY[5];
	int columnaX2[5];
	int columnaXY[5];
	int i;
	float sumatoriaX;
	float sumatoriaY;		
	float sumatoriaX2;	
	float sumatoriaXY;

	if(Flag == recta1) {
	
		for(i=0; i<5; i++){
			columnaX[i] = datos[r[i]][0];		
			columnaY[i] = datos[r[i]][1];	
			columnaX2[i] = cuadrado (datos[r[i]][0]);
			columnaXY[i] = datos[r[i]][0] * datos[r[i]][1];	
		}
	}
	else {
		for(i=0; i<5; i++){
		columnaX[i] = datos[p[i]][0];		
		columnaY[i] = datos[p[i]][1];	
		columnaX2[i] = cuadrado (datos[p[i]][0]);
		columnaXY[i] = datos[p[i]][0] * datos[p[i]][1];	
		}
	}

	sumatoriaX = hacerSumatoria(columnaX);
	sumatoriaY = hacerSumatoria(columnaY);
	sumatoriaX2 = hacerSumatoria(columnaX2);
	sumatoriaXY = hacerSumatoria(columnaXY);
	
	calcularAB(sumatoriaX, sumatoriaY, sumatoriaX2, sumatoriaXY);
	
	if(Flag == recta1) {
		e1 = calcularError (columnaX, columnaY);
		if (e1 < 0,3) 
			return (0);		/*Modifique lo anterior por return(0) o return(-1).*/
		else
			return(-1);
	}
	else {
		e2 = calcularError (columnaX, columnaY);
		if(e2 < 0,3)
			return(0);
		else
			return(-1);
}
}

float hacerSumatoria(int* columna) {
	float sumatoria = columna[0]+columna[1]+columna[2]+columna[3]+columna[4];

	return(sumatoria);
}


void calcularAB(float sumatoriaX, float sumatoriaY, float sumatoriaX2, float sumatoriaXY) {
	
	float sumatoria1 = 5;		/*Saco a y b despejando de la formula a manopla; y genericamente.*/
	b = (sumatoriaXY * sumatoriaX - sumatoriaX2 * sumatoriaY ) / (cuadrado(sumatoriaX) - sumatoriaX2 * sumatoria1);
	a = (sumatoriaY - sumatoria1 * b) / sumatoriaX;
	
}

float calcularError (int* columnaX, int* columnaY){	/*Le agrege * a los int, ya que son vectores.*/
	float valor;
	float e = 0;
	int i;
	
	for(i=0; i<5; i++){
		valor = columnaY[i] - (a * columnaX[i] + b);
		valor = cuadrado(valor);
		e += valor;
	}
	
	return e;
}

int elOtroVectorVerifica(void) {
	int valoresRecta2[4];
	int i=0;
	int j;
	
	for(j=2;j<10;j++) {
		if(r[1] != j && r[2] != j && r[3] != j && r[4] != j) {
			valoresRecta2[i] = j;
			i++;
		}
		
	}
	/*Se asigno el valor de p[0] en comienzo del main.*/
	p[1] = valoresRecta2[0];
	p[2] = valoresRecta2[1];
	p[3] = valoresRecta2[2];
	p[4] = valoresRecta2[3];
	if(verificarSiCumpleError(recta2) == -1)
		return(-1);
	return(0);
	
}

int cuadrado (int dato) {

 return (dato * dato);
}

void imprimirMensaje(void) {
	
puts("Aclaracion: los puntos seran devueltos en formato de par ordenado (x,y)");
puts("Los datos de la primera recta son: ");
printf("Punto 1: (%d,%d)\n", datos[r[0]][0], datos[r[0]][1]);
printf("Punto 2: (%d,%d)\n", datos[r[1]][0], datos[r[1]][1]);
printf("Punto 3: (%d,%d)\n", datos[r[2]][0], datos[r[2]][1]);
printf("Punto 4: (%d,%d)\n", datos[r[3]][0], datos[r[3]][1]);
printf("Punto 5: (%d,%d)\n", datos[r[4]][0], datos[r[4]][1]);
printf("El error total de la recta1 es %f\n", e1);

puts("");
puts("");

puts("Los datos de la primera recta son: ");
printf("Punto 1: (%d,%d)\n", datos[p[0]][0], datos[p[0]][1]);
printf("Punto 2: (%d,%d)\n", datos[p[1]][0], datos[p[1]][1]);
printf("Punto 3: (%d,%d)\n", datos[p[2]][0], datos[p[2]][1]);
printf("Punto 4: (%d,%d)\n", datos[p[3]][0], datos[p[3]][1]);
printf("Punto 5: (%d,%d)\n", datos[p[4]][0], datos[p[4]][1]);
printf("El error total de la recta1 es %f\n", e2);
puts("");
puts("Fin de los datos.");
/*puts("Presione una tecla para finalizar.");
getchar();*/

}