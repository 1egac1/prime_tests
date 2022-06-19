#include "prime_tests.h"
#include <stdio.h>
#include <gmp.h>
#include <math.h>

unsigned int fermat_ptest(unsigned long long n){
	// First, convert n to the string
	unsigned int n_length = (int)((ceil(log10(n))+1) * sizeof(char));
	char n_str[n_length];
	sprintf(n_str, "%Lu", n);

	// Next, initialize mpz with our number
	mpz_t number, result, biggest, i_mpz, rasing;
	mpz_init_set_str(number, n_str, 10);
	mpz_inits(result, biggest, i_mpz, NULL);
	mpz_init_set(rasing, number);
	mpz_sub_ui(rasing, rasing, 1);

	// Define the biggest
	mpz_sqrt(biggest, number);

	// For all i < biggest and coprime with n checking "i ^ (n - 1) = 1 (mod n)"
	for (unsigned long i = 2; mpz_cmp_ui(biggest, i-1); i++)
	{
		// Checking: is i coprime to number
		mpz_mod_ui(result, number, i);

		if(!mpz_sgn(result))
		{
			// Converting i to mpz
			mpz_set_ui(i_mpz, i);
			// Realization of expression
			mpz_powm(result, i_mpz, rasing, number);
			if (mpz_cmp_ui(result, 1))
			{
				return 0;
			}
		}
	}

	return 1;
}
