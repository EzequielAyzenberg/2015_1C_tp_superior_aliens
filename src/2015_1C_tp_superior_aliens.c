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

/*
=========
VARIABLES 
=========
*/

float a;
float b;
float c;
float d;
float e1;
float e2;

int i;
int j;
int k;
int m;

int r[5];
int p[5];
int v[8] = {2,3,4,5,6,7,8,9}; 
int datos[10][2] = { {100,54} , {150,83} , {230,118} , {240,123} , {260,132}, {290,148} , {300,150}, {350,178}, {375,184}, {390,198}};

/*
==========
PROTOTIPOS
==========
*/

int verificarSiCumpleError (int* r, float* a, float* b, float* e1);
float calcularError (int* columnaX, int* columnaY, int a, int b);
int cuadrado (int dato);
float hacerSumatoria(int* columna);

/*
==================
PROGRAMA PRINCIPAL
==================
*/

int main(void) {
	r[0] = 0;		//Lo dejo como estaba antes ya que no se cual es la idea del "r[0]"
	for(i=0; i<=7; i++) {
		r[1] = v[i];
		for(j=i+1; j<=7; j++) {
			r[2] = v[j];
			for(k=j+1; k<=7; k++) {
				r[3] = v[k];
				for(m=k+1; m<=7; m++) {
					r[4] = v[m];
				
					if(!verificarSiCumpleError(r, &a, &b, &e1))
						continue;
	
					p = determinarElOtroVector (r); //falta
					if(!verificarSiCumpleError(r, &c, &d, &e2))
						continue;
	
					imprimirMensaje (r, p, a, b, c, d, e1, e2);
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

int verificarSiCumpleError (int* r, float* a, float* b, float* e1){
	int columnaX[5]; 	//Te modifico esto de 6 a 5, ya que el resultado de la sumatoria lo terminas guardando en una variable aparte
	int columnaY[5];	//Te modifico esto de 6 a 5, ya que el resultado de la sumatoria lo terminas guardando en una variable aparte
	int columnaX2[5]; 	//Te modifico esto de 6 a 5, ya que el resultado de la sumatoria lo terminas guardando en una variable aparte
	int columnaXY[5]; 	//Te modifico esto de 6 a 5, ya que el resultado de la sumatoria lo terminas guardando en una variable aparte
	int i;				//Las columnas supuse que son de tipo int.
	float sumatoriaX;
	float sumatoriaY;		
	float sumatoriaX2;	
	float sumatoriaXY;

	for(i=0; i<5, i++){					//Modifique este for, ya que antes estaba mal. Fijense que onda.
		columnaX[i] = datos[r[i]].[0];		
		columnaY[i] = datos[r[i]].[1];	
		columnaX2[i] = cuadrado (datos[r[i]].[0]);
		columnaXY[i] = datos[r[i]].[0] * datos[r[i]].[1];	
	}

	sumatoriaX = hacerSumatoria(columnaX);
	sumatoriaY = hacerSumatoria(columnaY);
	sumatoriaX2 = hacerSumatoria(columnaX2);
	sumatoriaXY = hacerSumatoria(columnaXY);
	
	calcularAB(sumatoriaX, sumatoriaY, sumatoriaX2, sumatoriaXY, *a, *b) //falta hacer carcularAB
	e1 = calcularError (columnaX, columnaY, a, b);
	return (e1 - 0,3);
}

float calcularError (int* columnaX, int* columnaY, int a, int b){	//Le agrege * a los int, ya que son vectores.
	float e = 0;
	int i;
	for(i=0; i<5; i++){
		valor = columnaY[i] - (a * columnaX[i] + b);
		valor = cuadrado(valor);
		e += valor
	}
	return e;
}

int cuadrado (int dato) {

 return (dato * dato);
}

float hacerSumatoria(int* columna) {		//Esta funcion es muy sencilla ya que el vector siempre contendrá 5 numeros
	float sumatoria = columna[0]+columna[1]+columna[2]+columna[3]+columna[4];

	return(sumatoria);
}