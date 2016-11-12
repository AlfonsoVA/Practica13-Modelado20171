#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* arreglo_int(size_t num, int min, int max){	
	time_t t;
	//inicializa el generador de numeros random
	srand((unsigned) time(&t));	 

	//damos espacio en la memoria con calloc, siendo el numero de valores del arreglo por el numero de bytes del tipo de dato	
	int *arreglo_ints; 
	arreglo_ints = (int*)calloc(num, sizeof(int));

	int i;	
	//iteramos sobre la longitud del arreglo, agregando en cada casilla un valor random entre el minimo y maximo
	for(i=0; i<num; i++){			
		arreglo_ints[i]= rand() % (max+1 - min) + min;	
	}
	return arreglo_ints;
}

double* arreglo_double(size_t num, double min, double max){	
	time_t t;
	//inicializa el generador de numeros random
	srand((unsigned) time(&t));	
	
	//damos espacio en la memoria con calloc, siendo el numero de valores del arreglo por el numero de bytes del tipo de dato  
	double *arreglo_doubles;
	arreglo_doubles = (double*)calloc(num, sizeof(double));
	
	int i;	
	//iteramos sobre la longitud del arreglo, agregando en cada casilla un valor random entre el minimo y maximo
	for(i=0; i<num; i++){
		//en el caso de los doubles casteamos los minimos y maximos a ints, vemos por ello que en el metodo anterior no es necesario
		arreglo_doubles[i]= ((double)rand()*(max - min) / RAND_MAX) + min;		
	}
	return arreglo_doubles;
}