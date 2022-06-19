# Some primality tests written on C languge.
## Fermat primality test ##
```
fermat_ptest(unsigned long x)
```
This function returns `1` if number is prime, else retrurns `0`.

> Exemple of code:
```
#include <stdio.h>
#include "prime_tests.h"

int main(){
	unsigned long long n = 11, x = 25;

	if (fermat_ptest(n))
	{
		printf("%Lu is prime\n", n);
	}
	else
	{
		printf("%Lu is not prime\n", n);
	}



	if (fermat_ptest(x))
	{
		printf("%Lu is prime\n", x);
	}
	else
	{
		printf("%Lu is not prime\n", x);
	}

	return 0;
}
```
Output:
```
11 is prime
25 is not prime
```
