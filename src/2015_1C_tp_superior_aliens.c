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
int p[5];
int r[5];
int v[2, 3, 4, 5, 6, 7, 8, 9];


//TODO
//Crear la matriz datos[10][2] (el primer parametro son las posiciones de los puntos [0-9] 
//el segundo es si es el dato de x(0) o y(1) [0-1])
//asignarle los datos de la tabla a la matris datos



/*
==================
PROGRAMA PRINCIPAL
==================
*/

int main(void) {
	r[0];
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
	
					p= determinarElOtroVector (r); //falta
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

int verificarSiCumpleError (r, *a, *b, *e1){
	//crear columnaX[6] "en el 6to se guarda la sumatoria"
	//crear columnaY[6] "en el 6to se guarda la sumatoria"
	//crear columnaX2[6] "en el 6to se guarda la sumatoria"
	//crear columnaXY[6] "en el 6to se guarda la sumatoria"
	int i;
	float sumatoriaX;
	float sumatoriaY;
	float sumatoriaX2;
	float sumatoriaXY;

	for(i=0; i<5, i++){
		columnaX[i] = datos[r[i]].[0];
		columnaX[i] = datos[r[i]].[0];
		columnaX[i] = cuadrado (datos[r[i]].[0]);
		columnaX[i] = datos[r[i]].[0] * datos[r[i]].[1];
	}

	sumatoriaX = hacerSumatoria(columnaX);  //falta hacer sumatoria
	sumatoriaY = hacerSumatoria(columnaY);
	sumatoriaX2 = hacerSumatoria(columnaX2);
	sumatoriaXY = hacerSumatoria(columnaXY);
	
	calcularAB(sumatoriaX, sumatoriaY, sumatoriaX2, sumatoriaXY, *a, *b) //falta hacer carcularAB
		e1 = calcularError (columnaX, columnaY, a, b);
	return (e1 - 0,3);
}


float calcularError (columnaX, columnaY, a, b){
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
	return dato * dato;
}




