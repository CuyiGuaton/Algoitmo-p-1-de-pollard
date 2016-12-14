#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(int argc, char const *argv[]) {

  mpz_t n; //entrada
  mpz_t a; //random a
  mpz_t np1; // no primo 1
  mpz_t np2; // no primo 1
  mpz_t gcd; // variable auxiliar que guarda el gcd(a,n)
  gmp_randstate_t state; // semilla random
  //se le asigna valor e inicia varaibles
  mpz_init_set_str (n, argv[1], 10);
  mpz_init_set_ui(a, rand()%100);
  mpz_init(a);
  mpz_init_set_ui(gcd,0);
  gmp_randinit_default(state); //inicializa algoritmo random
  gmp_randseed_ui(state, 100); //semilla de random

  //falta verificar que n es no primo
  while(mpz_cmp_ui(gcd,1) != 0 ){ // hace a siempre sea menor que n-1 y que gcd(a,n) =1
    mpz_urandomm(a,state, n);
    mpz_out_str(stdout, 10, a);
    mpz_gcd(gcd, n, a);
  }
  gmp_randclear(state);
  mpz_clear(a);
  return 0;
}
