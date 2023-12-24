/*
Nombre de archivo: hw3.c (No cambiar el nombre de este archivo)
El repositorio donde esta tu HW3 es: github.com/unlu-edu-ar/prog1-2023-hw-3-TuNombreDeUsuarioGithub
Importante: No cambiar el nombre del archivo

Completa con tu nombre, apellido y DNI
Nombre y Apellido: Valentin Morello
DNI:45676930
*/
 
 /* 
 Se disponen de archivos de texto, donde se guardan los datos del clima. 
 Cada linea de un archivo de clima se corresponde a un dia del anio. 
 Los datos en cada linea estan separados por tabuladores (a los archivos de texto 
 que tienen los datos separados por tabuladores, se los acostumbra guardar con 
 la extension .tsv, que viene del ingles tab separated values).
 Los datos guardados en cada linea son numeros enteros, y estan en el siguiente orden:
 - dia
 - mes
 - anio 
 - cantidad de lluvia caida 
 - temperatura minima
 - temperatura maxima

 Nota: para evitar errores de incompatilidades, no hemos puesto tildes, ni caracteres
 propios del lenguaje castellano.
 */

#include <stdio.h>

/* 
Programe una funcion que recibe los datos de un archivo de clima, y un mes, 
y devuelva cuantos dias hubo sin lluvias en ese mes.
INPUT: fp (puntero a archivo), mes (int)
OUTPUT: sin_lluvias (int)
*/

int sin_lluvias(FILE* fp, int mes){ 
	rewind(fp);
	int dia, mesArchivo, anio, lluvia, tempMin, tempMax;
    int sin_lluvias = 0;
	
    while (!feof(fp)) {
        if (mesArchivo == mes && lluvia == 0) {
            sin_lluvias++;
        }
		fscanf(fp, "%d\t%d\t%d\t%d\t%d\t%d", &dia, &mesArchivo, &anio, &lluvia, &tempMin, &tempMax);
	}
    return sin_lluvias;
}



/* 
Programe una funcion que recibe los datos de un archivo de clima, y devuelva cuantos dias 
llovio menos de x mm, y cuantos dias llovio x mm o mas que x mm, en el anio.
INPUT: fp (puntero a archivo), x (int), lluvias_menor_x (int*), lluvias_mayorigual_x (int*)  
OUTPUT: void
*/

void llovio_umbral(FILE* fp, int x, int* lluvias_menor_x, int* lluvias_mayorigual_x){ 
	rewind(fp);
	int dia, mes, anio, lluvia, tempMin, tempMax;
	*lluvias_menor_x = 0;
	*lluvias_mayorigual_x = 0;
	fscanf(fp, "%d\t%d\t%d\t%d\t%d\t%d", &dia, &mes, &anio, &lluvia, &tempMin, &tempMax);
	
	while(!feof(fp)){
		
		if(lluvia < x){
			(*lluvias_menor_x)++;
		}
		else{
			(*lluvias_mayorigual_x)++;
		}
		fscanf(fp, "%d\t%d\t%d\t%d\t%d\t%d", &dia, &mes, &anio, &lluvia, &tempMin, &tempMax);
	}
}

/* 
Programe una funcion que recibe los datos de un archivo de clima, y un mes, y
devuelva cuantos dias se registro la maxima temperatura del mes. 
INPUT: fp (puntero a archivo), mes (int)
OUTPUT: cant_dias_maximo_calor (int) 
*/

int contador_dias_maximo_calor(FILE* fp, int mes){ 
	rewind(fp);
	int dia, mesArchivo, anio, lluvia, tempMin, tempMax;
	int cant_dias_maximo_calor = 0;
	int alm_temp_max = 0;
	

	while(!feof(fp)){
		fscanf(fp, "%d\t%d\t%d\t%d\t%d\t%d", &dia, &mesArchivo, &anio, &lluvia, &tempMin, &tempMax);
		if(mes == mesArchivo){
			if(tempMax > alm_temp_max){
				alm_temp_max = tempMax;
				cant_dias_maximo_calor = 1;
			}
			else if(tempMax == alm_temp_max){
				cant_dias_maximo_calor ++;
			}
		}
		
	}
	return (cant_dias_maximo_calor);
}

/* 
Programe una funcion que recibe los datos de un archivo de clima, y un mes, y
devuelva el dia donde se registro la minima temperatura del mes y cual fue dicha temperatura. 
En el caso de haber varios dias con temperatura minima, debe devolver el primer dia.
INPUT: fp (puntero a archivo), mes (int), dia (int*), temp_minima (int*)  
OUTPUT: void
*/

void dia_mas_frio_mes(FILE* fp, int mes, int* dia, int* temp_minima){ 
	rewind(fp);
	int diaArchivo, mesArchivo, anio, lluvia, tempMin, tempMax;
	*dia = 0;
	fscanf(fp, "%d\t%d\t%d\t%d\t%d\t%d", &diaArchivo, &mesArchivo, &anio, &lluvia, &tempMin, &tempMax);
	*temp_minima = tempMax;

	while(!feof(fp)){
		fscanf(fp, "%d\t%d\t%d\t%d\t%d\t%d", &diaArchivo, &mesArchivo, &anio, &lluvia, &tempMin, &tempMax);
		if(mes == mesArchivo){
			if(tempMin<*temp_minima){
				*temp_minima = tempMin;
				*dia = diaArchivo;
				
			}
		}
	}
}

/* 
Programe una funcion que recibe los datos de un archivo de clima, y un mes, y
devuelva el promedio de lluvias de dicho mes. 
INPUT: fp (puntero a archivo), mes (int) 
OUTPUT: promedio_lluvia (float) 
*/

float promedio_lluvias_mes(FILE* fp, int mes){ 
	rewind(fp);
	int dia, mesArchivo, anio, lluvia, tempMin, tempMax;
	int cont_lluvia = 0;
	float promedio_lluvia = 0;
	int contador = 0;

	while(!feof(fp)){
		fscanf(fp, "%d\t%d\t%d\t%d\t%d\t%d", &dia, &mesArchivo, &anio, &lluvia, &tempMin, &tempMax);
		if(mes == mesArchivo){
			cont_lluvia += lluvia;
			contador += 1;
		}
		
	}
	promedio_lluvia = cont_lluvia / contador;
	return promedio_lluvia;
}

