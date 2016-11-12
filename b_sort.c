#include "b_sort.h"

/*  bsort: ordena un arreglo usando el algoritmo bubble sort
    base: es un apuntador a un arreglo a ordenar
    num: es el número de elementos en el arreglo
    size: es el tamaño en bytes de cada elemento en el arreglo
    compar: es el apuntador a una función comparadora, que regresa:
           número negativo si el primer elemento es menor
           0 si ambos elementos son iguales
           número positivo si el primer elemento es mayor
*/
void bsort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*)){
	//declaramos las variables sobre las que vamos a iterar, asi como las temporales en cada caso
	int i, j, k, tmp;
	double tmpd;
	//igualamos k como el numero de elementos en el arreglo para iterar
	k=num;
	//Arreglo de ints
	if(size!=8){
		for(i=0; i<num-1; i++){
			for(j=0; j<k; j++){
				//si no esta ordenado, para esto usamos el metodo compar a partir de los valores en la posición j y j+1 
				if((*compar)((int*)base + j, (int*)base + j + 1 )>  0){								
				//aplicamos swap
				//usamos tmp para guardar el primer valor
				tmp= *((int*)base + j);			

				//reemplazamos los valores
				*((int*)base+j)= *((int*)base+j+1);

				//usamos tmp para el segundo valor
				*((int*)base+j+1)= tmp;
				}				
			}
			k--;
		}
	}
	//Arreglo de doubles
	else{
		for(i=0; i<num-1; i++){
			for(j=0; j<k; j++){				
				if((*compar)((double*)base + j, (double*)base+j+1)>0){				
				//aplicamos swap
				//usamos tmpd para guardar el primer valor								
				tmpd= *((double*)base+j);				

				//reemplazamos los valores
				*((double*)base+j)= *((double*)base+j+1);

				//usamos tmp para el segundo elemento
				*((double*)base+j+1)= tmpd;
				}			
			}
			k--;
		}
	}
}