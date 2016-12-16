#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>

int main(int argc, char const *argv[]) {

        //Para el tiempo
        clock_t tStart;
        float t=0;
        float  cont=0;

        mpz_t n; //entrada
        mpz_t a; //random a
        mpz_t B;
        mpz_t np1; // no primo 1
        mpz_t np2; // no primo 1
        mpz_t aux; // variable auxiliar que guarda el gcd(a,n)
        gmp_randstate_t state; // semilla random

        //se le asigna valor e inicia varaibles
        mpz_init_set_str(n, argv[1], 10);
        mpz_init(a);
        mpz_init(B);
        mpz_init(np1);
        mpz_init(np2);
        mpz_init(aux);
        gmp_randinit_default(state); //inicializa algoritmo random
        gmp_randseed_ui(state, 100); //semilla de random

        //falta verificar que n es no primo

do{

// Se elige un a al azar 1 < a < n-1, gcd(a,n)=1
        if(mpz_probab_prime_p(n,15) == 2 || mpz_probab_prime_p(n,15) == 1) {
                //printf("No tiene que ser primo el número\n");
                return 0;
        }
tStart = clock();
B:
        do {
                mpz_urandomm(a,state, n);
                if(mpz_cmp_ui(a,1) != 0)
                        mpz_urandomm(a,state, n);
                //mpz_sub_ui(aux2, a, 1); // aux = a-1
                //mpz_gcd(aux, n, aux2); //el gcd(n,a) se guarda en aux y luego se comprara
                mpz_gcd(aux, n, a);
        } while(mpz_cmp_ui(aux,1) != 0); // obliga que a cumpla gcd(a,n) =1 y a!= 1

        mpz_set_ui(B,1); // B = 2
        mpz_powm(a, a, B, n); // a = a^B mod n
        mpz_sub_ui(aux, a, 1); // aux = a-1
        mpz_gcd(np1, aux, n); // np1 = gcd(a-1,n)

        while (mpz_cmp_ui(np1,1) == 0) { //mientras que np1 = 1
                mpz_add_ui(B,B,1); // B= B+1
                mpz_powm(a, a, B, n); // a = a^B mod n
                mpz_sub_ui(aux, a, 1); // aux = a-1
                mpz_gcd(np1, aux, n); // np1 = gcd(a -1,n)
        }
        if(mpz_cmp(np1,n)==0 )
                goto B;
t += (double)(clock() - tStart)/CLOCKS_PER_SEC;
cont++;
}while( t < 1);
        mpz_tdiv_q(np2,n,np1); // np2 = n/np1
        printf("\nnp1 = ");
        mpz_out_str(stdout, 10, np1 );
        printf("\nnp2 = ");
        mpz_out_str(stdout, 10, np2 );
        printf("\nB = ");
        mpz_out_str(stdout, 10, B);
        printf("\nt= ");
        printf("%.6f\n",t/cont );


        gmp_randclear(state);
        mpz_clear(a);
        mpz_clear(n);
        mpz_clear(B);
        mpz_clear(np1);
        mpz_clear(np2);
        mpz_clear(aux);
        return 0;
}
