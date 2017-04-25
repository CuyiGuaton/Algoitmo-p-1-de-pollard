/*
	Autores: 		Katerine Muñoz & Sergio Salinas
	Programa: 	Algoritmo de factorización
se compila con gcc bfnp.c -lgmp -lm  && ./a.out n
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gmp.h>
#include <math.h>


//Paso 1: Inicializar.

int main(int argc, char const *argv[]){
	/* definition */
	mpz_t *P;
	
	int n = atoi(argv[1]);
	/* initialization of A */
	P = (mpz_t *) malloc(n * sizeof(mpz_t));
	if (NULL == P) {
	    printf("ERROR: Out of memory\n");
	    return 1;
	}

	printf("\n Prime number list = ");
	mpz_t aux;
	mpz_init_set_ui(aux,2);
	mpz_nextprime (P[0], aux);
	for(int i=1; i<sqrt(n);i++){
		mpz_nextprime (P[i], P[i-1]);
		printf(" ");
		mpz_out_str(stdout, 10, P[i] );
	}	
	/* no longer need A */
	free(P);
	return 0;
}

//Paso 2: Termino.

//Paso 3: Remover los múltiplos de p_i.

//Paso 4: Salida.

//Paso 5: Inicializar.

//Paso 6: Chequeando si es primo.

//Paso 8: Añadiendo Factor.

//Paso 9: Se puede factorizar n?

//Paso 10: Obtener el próximo primo.
