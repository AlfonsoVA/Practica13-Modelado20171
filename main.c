/*Incluye las funciones de b_sort.c y arreglos_random.c*/
#include "b_sort.h"
#include "arreglos_random.h"

/*Declara las funciones que vamos a ocupar*/
// función que compara dos enteros
int cmp_int(const void *a, const void *b);
// función que compara dos doubles
int cmp_double(const void *a, const void *b);
// función que imprime una lista de enteros de tamaño num
void imprime_int(int *arreglo, size_t num);
// función que imprime una lista de doubles de tamaño num
void imprime_double(double *arreglo, size_t num);

//metodo cmp_int, compara dos ints
int cmp_int(const void *a, const void *b){
	//guardamos los valores en los tmp_a y tmp_b
	//no podemos usar switch u~u
	int tmp_a=*(int *)a;
	int tmp_b=*(int *)b;		
	if(tmp_a<tmp_b){			
		return -1;
	}
	if(tmp_a>tmp_b){
		return 1;		
	}	
	return 0;	
}
//metodo cmp_double, compara dos doubles
int cmp_double(const void *a, const void *b){
	//guardamos los valores en los tmp_a y tmp_b
	double tmp_a=*(double *)a;
	double tmp_b=*(double *)b;
	if(tmp_a<tmp_b){			
		return -1;
	}
	if(tmp_a>tmp_b){
		return 1;		
	}
	return 0;
}

//metodo imprime_int, itera sobre el apuntador a arreglo tipo int tamanio num para imprimirlo
void imprime_int(int *arreglo, size_t num){
	int i;
	for(i=0; i<num; i++){
		printf("%d  ", arreglo[i]);
	}
	printf("\n");
}
//metodo imprime_int, itera sobre el apuntador a arreglo tipo double tamanio num para imprimirlo
void imprime_double(double *arreglo, size_t num){
	int i;
	for(i=0; i<num; i++){
		printf("%f  ", arreglo[i]);
	}
	printf("\n");
}


int main()
{
    // Se inicializan 2 arreglos, uno de ints y otro de doubles
    int * arr1 = arreglo_int(20, 0, 10);
    double * arr2 = arreglo_double(20, 0, 10);

    // Se imprime ordena e imprime el primer arreglo
    printf("Arreglo inicial \n");
    imprime_int(arr1, 20);
    bsort(arr1, 20, sizeof(int), &cmp_int);
    printf("Arreglo ordenado \n");
    imprime_int(arr1, 20);

    // Se imprime ordena e imprime el segundo arreglo
    printf("Arreglo inicial \n");
    imprime_double(arr2, 20);
    bsort(arr2, 20, sizeof(double), &cmp_double);
    printf("Arreglo ordenado \n");
    imprime_double(arr2, 20);

    // Se libera la memoria que ocupan los arreglos ordenados        
    free(arr1);
    free(arr2);
    return 0;
}