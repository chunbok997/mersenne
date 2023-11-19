// Creator: Chunbok Kim and Bing
// Date: 2023-11-19
// Version: 1.0.0
// Title: Mersenne Prime Number Finder

#include <stdio.h>
#include <gmp.h>
#include <mpfr.h>

int main(int argc, char *argv[])
{
    mpz_t is_prime;

    mpfr_t digits_minus_1;
    mpfr_t digits_min;
    mpfr_t digits_max;
    mpfr_t digits_percision_count;
    mpfr_t ratio;
    mpfr_t log_2;
    mpfr_t ratio_reverse_min;
    mpfr_t ratio_reverse_max;
    mpfr_t ratio_reverse_percision_count;
    mpfr_t result_percision_zero;
    mpfr_t result_percision_min;
    mpfr_t result_percision_max;
    mpfr_t result_percision_first;
    mpfr_t result_percision_last;
    mpfr_t result_percision_count;
    mpfr_t is_mersenne_prime;
    mpfr_t is_mersenne_prime_prev;
    mpfr_t is_mersenne_prime_range_zero;
    mpfr_t is_mersenne_prime_range_min;
    mpfr_t is_mersenne_prime_range_max;
    mpfr_t count;
    mpfr_t one;
    mpfr_t two;

    mpz_init(is_prime);

    mpfr_init(digits_minus_1);
    mpfr_init(digits_min);
    mpfr_init(digits_max);
    mpfr_init(digits_percision_count);
    mpfr_init(ratio);
    mpfr_init(log_2);
    mpfr_init(ratio_reverse_min);
    mpfr_init(ratio_reverse_max);
    mpfr_init(ratio_reverse_percision_count);
    mpfr_init(result_percision_zero);
    mpfr_init(result_percision_min);
    mpfr_init(result_percision_max);
    mpfr_init(result_percision_first);
    mpfr_init(result_percision_last);
    mpfr_init(result_percision_count);
    mpfr_init(is_mersenne_prime);
    mpfr_init(is_mersenne_prime_prev);
    mpfr_init(is_mersenne_prime_range_zero);
    mpfr_init(is_mersenne_prime_range_min);
    mpfr_init(is_mersenne_prime_range_max);
    mpfr_init(count);
    mpfr_init(one);
    mpfr_init(two);

    /*mpz_init2(is_prime, 1024U);

    mpfr_init2(digits_minus_1, 1024U);
    mpfr_init2(digits_min, 1024U);
    mpfr_init2(digits_max, 1024U);
    mpfr_init2(digits_percision_count, 1024U);
    mpfr_init2(ratio, 1024U);
    mpfr_init2(log_2, 1024U);
    mpfr_init2(ratio_reverse_min, 1024U);
    mpfr_init2(ratio_reverse_max, 1024U);
    mpfr_init2(ratio_reverse_percision_count, 1024U);
    mpfr_init2(result_percision_zero, 1024U);
    mpfr_init2(result_percision_min, 1024U);
    mpfr_init2(result_percision_max, 1024U);
    mpfr_init2(result_percision_first, 1024U);
    mpfr_init2(result_percision_last, 1024U);
    mpfr_init2(result_percision_count, 1024U);
    mpfr_init2(is_mersenne_prime, 1024U);
    mpfr_init2(is_mersenne_prime_prev, 1024U);
    mpfr_init2(is_mersenne_prime_range_zero, 1024U);
    mpfr_init2(is_mersenne_prime_range_min, 1024U);
    mpfr_init2(is_mersenne_prime_range_max, 1024U);
    mpfr_init2(count, 1024U);
    mpfr_init2(one, 1024U);
    mpfr_init2(two, 1024U);*/

    mpz_set_str(is_prime, "0.0", 10);

    mpfr_set_str(digits_minus_1, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(digits_min, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(digits_max, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(digits_percision_count, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(ratio, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(log_2, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(ratio_reverse_min, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(ratio_reverse_max, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(ratio_reverse_percision_count, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(result_percision_zero, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(result_percision_min, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(result_percision_max, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(result_percision_first, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(result_percision_last, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(result_percision_count, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(is_mersenne_prime, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(is_mersenne_prime_prev, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(is_mersenne_prime_range_zero, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(is_mersenne_prime_range_min, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(is_mersenne_prime_range_max, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(count, "0.0", 10, MPFR_RNDN);
    mpfr_set_str(one, "1.0", 10, MPFR_RNDN);
    mpfr_set_str(two, "2.0", 10, MPFR_RNDN);

    if (argc == 3)
    {
        mpfr_set_str(digits_min, argv[1], 10, MPFR_RNDN);
        mpfr_set_str(digits_max, argv[2], 10, MPFR_RNDN);
    }
    if (argc == 4)
    {
        mpfr_set_str(digits_min, argv[1], 10, MPFR_RNDN);
        mpfr_set_str(digits_max, argv[2], 10, MPFR_RNDN);
        mpfr_set_str(digits_percision_count, argv[3], 10, MPFR_RNDN);
    }
    if (argc == 5)
    {
        mpfr_set_str(digits_min, argv[1], 10, MPFR_RNDN);
        mpfr_set_str(digits_max, argv[2], 10, MPFR_RNDN);
        mpfr_set_str(digits_percision_count, argv[3], 10, MPFR_RNDN);
        mpfr_set_str(ratio_reverse_min, argv[4], 10, MPFR_RNDN);
    }
    if (argc == 6)
    {
        mpfr_set_str(digits_min, argv[1], 10, MPFR_RNDN);
        mpfr_set_str(digits_max, argv[2], 10, MPFR_RNDN);
        mpfr_set_str(digits_percision_count, argv[3], 10, MPFR_RNDN);
        mpfr_set_str(ratio_reverse_min, argv[4], 10, MPFR_RNDN);
        mpfr_set_str(ratio_reverse_max, argv[5], 10, MPFR_RNDN);
    }
    if (argc == 7)
    {
        mpfr_set_str(digits_min, argv[1], 10, MPFR_RNDN);
        mpfr_set_str(digits_max, argv[2], 10, MPFR_RNDN);
        mpfr_set_str(digits_percision_count, argv[3], 10, MPFR_RNDN);
        mpfr_set_str(ratio_reverse_min, argv[4], 10, MPFR_RNDN);
        mpfr_set_str(ratio_reverse_max, argv[5], 10, MPFR_RNDN);
        mpfr_set_str(ratio_reverse_percision_count, argv[6], 10, MPFR_RNDN);
    }
    if (argc == 8)
    {
        mpfr_set_str(digits_min, argv[1], 10, MPFR_RNDN);
        mpfr_set_str(digits_max, argv[2], 10, MPFR_RNDN);
        mpfr_set_str(digits_percision_count, argv[3], 10, MPFR_RNDN);
        mpfr_set_str(ratio_reverse_min, argv[4], 10, MPFR_RNDN);
        mpfr_set_str(ratio_reverse_max, argv[5], 10, MPFR_RNDN);
        mpfr_set_str(ratio_reverse_percision_count, argv[6], 10, MPFR_RNDN);
        mpfr_set_str(result_percision_min, argv[7], 10, MPFR_RNDN);
    }
    if (argc == 9)
    {
        mpfr_set_str(digits_min, argv[1], 10, MPFR_RNDN);
        mpfr_set_str(digits_max, argv[2], 10, MPFR_RNDN);
        mpfr_set_str(digits_percision_count, argv[3], 10, MPFR_RNDN);
        mpfr_set_str(ratio_reverse_min, argv[4], 10, MPFR_RNDN);
        mpfr_set_str(ratio_reverse_max, argv[5], 10, MPFR_RNDN);
        mpfr_set_str(ratio_reverse_percision_count, argv[6], 10, MPFR_RNDN);
        mpfr_set_str(result_percision_min, argv[7], 10, MPFR_RNDN);
        mpfr_set_str(result_percision_max, argv[8], 10, MPFR_RNDN);
    }
    else
    {
        mpz_set_str(is_prime, "0.0", 10);

        mpfr_set_str(digits_minus_1, "0.0", 10, MPFR_RNDN);
        mpfr_set_str(digits_min, "1.0", 10, MPFR_RNDN);
        mpfr_set_str(digits_max, "100.0", 10, MPFR_RNDN);
        mpfr_set_str(digits_percision_count, "1.0", 10, MPFR_RNDN);
        mpfr_set_str(ratio_reverse_min, "3.1", 10, MPFR_RNDN);
        mpfr_set_str(ratio_reverse_max, "3.3219", 10, MPFR_RNDN);
        mpfr_set_str(ratio_reverse_percision_count, "0.0001", 10, MPFR_RNDN);
        mpfr_set_str(result_percision_min, "0.0001", 10, MPFR_RNDN);
        mpfr_set_str(result_percision_max, "0.004", 10, MPFR_RNDN);
        mpfr_set_str(is_mersenne_prime, "0.0", 10, MPFR_RNDN);
        mpfr_set_str(is_mersenne_prime_prev, "0.0", 10, MPFR_RNDN);
        mpfr_set_str(is_mersenne_prime_range_zero, "0.0", 10, MPFR_RNDN);
        mpfr_set_str(is_mersenne_prime_range_min, "0.0", 10, MPFR_RNDN);
        mpfr_set_str(is_mersenne_prime_range_max, "0.0", 10, MPFR_RNDN);
        mpfr_set_str(count, "0.0", 10, MPFR_RNDN);
        mpfr_set_str(one, "1.0", 10, MPFR_RNDN);
        mpfr_set_str(two, "2.0", 10, MPFR_RNDN);

        printf("Usage: %s <digits first> <digits last> <digits percision count> <ratio reverse min> <ratio reverse max> <ratio reverse percision count> <result percision min> <result percision max>\n\n", argv[0]);

        printf("Example1: ./is_mersenne_prime.out 0.0 9.0 1.0 2.0 3.321 0.001 0.0 0.004\n");
        printf("Example2: ./is_mersenne_prime.out 0.0 99.0 1.0 3.1 3.3219 0.0001 0.0 0.004\n");
        printf("Example3: ./is_mersenne_prime.out 0.0 999.0 1.0 3.3 3.32192 0.00001 0.0 0.006\n");
        printf("Example4: ./is_mersenne_prime.out 0.0 9999.0 1.0 3.32 3.321927 0.000001 0.0 0.006\n");
        printf("Example5: ./is_mersenne_prime.out 0.0 99999.0 1.0 3.321 3.3219279 0.0000001 0.0 0.002\n");
        printf("Example6: ./is_mersenne_prime.out 0.0 999999.0 1.0 3.3219 3.32192780 0.00000001 0.0 0.006\n");
        printf("Example7: ./is_mersenne_prime.out 0.0 9999999.0 1.0 3.32192 3.321927809 0.000000001 0.0 0.007\n\n");

        printf("==================== Example Data (3.32192809488736234787031) ====================\n");
        printf("is_M23.00200 = 7.000000 * 3.2859999999999 [ 9 primes found ]\n");
        printf("is_M317.00160 = 96.000000 * 3.3020999999995 [ 45 primes found ]\n");
        printf("is_M3313.00072 = 998.000000 * 3.3196399999993 [ 365 primes found ]\n");
        printf("is_M33203.00348 = 9996.000000 * 3.3216289999995 [ 2840 primes found ]\n");
        printf("is_M332159.00078 = 99990.000000 * 3.3219221999985 [ 14846 primes found ]\n");
        printf("is_M3321917.00422 = 999997.000000 * 3.3219269699998 [ 200172 primes found ]\n\n");
    }

    mpfr_log10(log_2, two, MPFR_RNDD);
    mpfr_div(ratio, one, log_2, MPFR_RNDD);

    for (; mpfr_cmp (digits_min, digits_max) <= 0; mpfr_add(digits_min, digits_min, digits_percision_count, MPFR_RNDD))
    {
        if (argc >= 5)
            mpfr_set_str(ratio_reverse_min, argv[4], 10, MPFR_RNDD);
        else
            mpfr_set_str(ratio_reverse_min, "3.1", 10, MPFR_RNDD);

        mpfr_sub (digits_minus_1, digits_min, one, MPFR_RNDD);
        
        for (; mpfr_cmp(ratio_reverse_min, ratio_reverse_max) <= 0; mpfr_add(ratio_reverse_min, ratio_reverse_min, ratio_reverse_percision_count, MPFR_RNDD))
        {
            mpfr_mul(is_mersenne_prime, digits_min, ratio_reverse_min, MPFR_RNDD);

            mpfr_get_z(is_prime, is_mersenne_prime, MPFR_RNDD);

            if (mpz_probab_prime_p(is_prime, 1024U) != 0)
            {
                mpfr_floor(is_mersenne_prime_range_zero, is_mersenne_prime);
                mpfr_mul(is_mersenne_prime_range_min, digits_minus_1, ratio, MPFR_RNDD);
                mpfr_mul(is_mersenne_prime_range_max, digits_min, ratio, MPFR_RNDD);

                mpfr_set(result_percision_zero, is_mersenne_prime_range_zero, MPFR_RNDD);
                mpfr_add(result_percision_first, result_percision_zero, result_percision_min, MPFR_RNDD);
                mpfr_add(result_percision_last, result_percision_zero, result_percision_max, MPFR_RNDD);

                if (mpfr_cmp(is_mersenne_prime, result_percision_first) >= 0 && mpfr_cmp(is_mersenne_prime, result_percision_last) <= 0
                    && mpfr_cmp(is_mersenne_prime, is_mersenne_prime_range_min) > 0 && mpfr_cmp(is_mersenne_prime, is_mersenne_prime_range_max) <= 0
                    && mpfr_cmp(is_mersenne_prime_prev, is_mersenne_prime_range_zero) != 0)
                {
                    mpfr_printf("is_M%0.5Rf = %Rf * %1.13Rf\n", is_mersenne_prime, digits_min, ratio_reverse_min);

                    mpfr_add(count, count, one, MPFR_RNDD);   

                    mpfr_set(is_mersenne_prime_prev, is_mersenne_prime_range_zero, MPFR_RNDD);
                }
            }
        }
    }

    mpfr_printf(" %0.0Rf primes found\n", count);

    mpz_clear(is_prime);

    mpfr_clear(digits_minus_1);
    mpfr_clear(digits_min);
    mpfr_clear(digits_max);
    mpfr_clear(digits_percision_count);
    mpfr_clear(ratio);
    mpfr_clear(log_2);
    mpfr_clear(ratio_reverse_min);
    mpfr_clear(ratio_reverse_max);
    mpfr_clear(ratio_reverse_percision_count);
    mpfr_clear(result_percision_zero);
    mpfr_clear(result_percision_min);
    mpfr_clear(result_percision_max);
    mpfr_clear(result_percision_first);
    mpfr_clear(result_percision_last);
    mpfr_clear(result_percision_count);
    mpfr_clear(is_mersenne_prime);
    mpfr_clear(is_mersenne_prime_prev);
    mpfr_clear(is_mersenne_prime_range_zero);
    mpfr_clear(is_mersenne_prime_range_min);
    mpfr_clear(is_mersenne_prime_range_max);
    mpfr_clear(count);
    mpfr_clear(one);
    mpfr_clear(two);

    return 0;
}
