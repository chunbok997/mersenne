// Creator: Chunbok Kim and Bing
// Date: 2023-11-18
// Version: 1.0.0
// Title: Prime Number Finder

#include <stdio.h>
#include <gmp.h>

int main(int argc, char *argv[])
{
    mpz_t isprime_first;
    mpz_t isprime_last;
    mpz_t isprime;
    mpz_t count;
    
    mpz_init(isprime_first);
    mpz_init(isprime_last);
    mpz_init(isprime);
    mpz_init(count);

    mpz_set_str(isprime_first, "0", 10);
    mpz_set_str(isprime_last, "0", 10);
    mpz_set_str(isprime, "0", 10);
    mpz_set_str(count, "0", 10);

    if (argc == 2)
    {
        mpz_set_str(isprime_first, argv[1], 10);
    }
    else if (argc == 3)
    {
        mpz_set_str(isprime_first, argv[1], 10);
        mpz_set_str(isprime_last, argv[2], 10);
    }
    else
    {
        printf("Usage: %s <number>\n", argv[0]);
        printf("Usage: %s <first number> <last number>\n", argv[0]);
    }

    if (argc == 2)
    {
        if (mpz_probab_prime_p(isprime_first, 1024U) != 0)
        {
            gmp_printf(" %13Zd is prime\n", isprime_first);
        }
    }

    if (argc == 3)
    {
        for (mpz_set(isprime, isprime_first); mpz_cmp(isprime, isprime_last) <= 0; mpz_add_ui(isprime, isprime, 1))
        {
            if (mpz_probab_prime_p(isprime, 1024U) != 0)
            {
                mpz_add_ui(count, count, 1);

                gmp_printf(" %13Zd is prime\n", isprime);
            }
        }

        gmp_printf(" %13Zd primes found\n", count);
    }

    mpz_clear(isprime_first);
    mpz_clear(isprime_last);
    mpz_clear(isprime);
    mpz_clear(count);

    return 0;
}
