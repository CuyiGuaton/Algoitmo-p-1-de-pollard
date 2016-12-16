#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "a.c"
//para funcionar se debe cambiar el main de a.c a int main(mpt_z n) y borrar las declaración, iniciacion y liberación de n

int main(int argc, char const *argv[]) {

  mpz_t a; //random
  mpz_t n;
  mpz_init(a);
  mpz_init_set_str(n, "1000000000000", 10);
  gmp_randstate_t state; // semilla random
  gmp_randinit_default(state); //inicializa algoritmo random
  gmp_randseed_ui(state, 100); //semilla de random
  mpz_urandomm(a,state, n);

  for (size_t i = 0; i < 1000; i++){
    mpz_urandomm(a,state, n);
    ar(a);
  }

  gmp_randclear(state);
  mpz_clear(a);

  return 0;
}
