// Creator: Chunbok Kim and Bing
// Date: 2023-11-20
// Version: 1.0.0
// Title: Mersenne Prime base_number (2^127-1)

#include <stdio.h>
#include <gmp.h>
#include <mpfr.h>

int main(int argc, char *argv[])
{
    mpz_t prime;

    mpfr_t digits_min;
    mpfr_t digits_max;
    mpfr_t digits_count;
    mpfr_t numbers_min;
    mpfr_t numbers_max;
    mpfr_t digits;
    mpfr_t digits_minus_1;
    mpfr_t digits_zero;
    mpfr_t digits_plus_1;
    mpfr_t digits_change;
    mpfr_t digits_change_min;
    mpfr_t digits_change_max;
    mpfr_t log_2;
    mpfr_t log_2_temp;
    mpfr_t zero;
    mpfr_t one;
    mpfr_t two;
    mpfr_t q;
    mpfr_t r;
    mpfr_t exp;
    mpfr_t e;
    mpfr_t e_count;
    mpfr_t base;
    mpfr_t count;
    mpfr_t is_prime;
    mpfr_t print;
    mpfr_t print_count;

    mpz_init(prime);

    mpfr_init(digits_min);
    mpfr_init(digits_max);
    mpfr_init(digits_count);
    mpfr_init(numbers_min);
    mpfr_init(numbers_max);
    mpfr_init(digits);
    mpfr_init(digits_minus_1);
    mpfr_init(digits_zero);
    mpfr_init(digits_plus_1);
    mpfr_init(digits_change);
    mpfr_init(digits_change_min);
    mpfr_init(digits_change_max);
    mpfr_init(log_2);
    mpfr_init(log_2_temp);
    mpfr_init(zero);
    mpfr_init(one);
    mpfr_init(two);
    mpfr_init(q);
    mpfr_init(r);
    mpfr_init(exp);
    mpfr_init(e);
    mpfr_init(e_count);
    mpfr_init(base);
    mpfr_init(count);
    mpfr_init(is_prime);
    mpfr_init(print);
    mpfr_init(print_count);

    mpz_set_str(prime, "0", 10);

    mpfr_set_str(digits_min, "1.0", 10, MPFR_RNDN);
    mpfr_set_str(digits_max, "127.0", 10, MPFR_RNDN);
    mpfr_set_str(digits_count, "1.0", 10, MPFR_RNDN);
    mpfr_set_str(numbers_min, "0.0", 10, MPFR_RNDD);
    mpfr_set_str(numbers_max, "127.0", 10, MPFR_RNDD);
    mpfr_set_str(digits, "1.0", 10, MPFR_RNDD);
    mpfr_set_str(digits_minus_1, "1.0", 10, MPFR_RNDD);
    mpfr_set_str(digits_zero, "1.0", 10, MPFR_RNDD);
    mpfr_set_str(digits_plus_1, "1.0", 10, MPFR_RNDD);
    mpfr_set_str(digits_change, "1.0", 10, MPFR_RNDD);
    mpfr_set_str(digits_change_min, "1.0", 10, MPFR_RNDD);
    mpfr_set_str(digits_change_max, "1.0", 10, MPFR_RNDD);
    mpfr_set_str(log_2, "2.0", 10, MPFR_RNDD);
    mpfr_set_str(log_2_temp, "0.0", 10, MPFR_RNDD);
    mpfr_set_str(zero, "0.0", 10, MPFR_RNDD);
    mpfr_set_str(one, "1.0", 10, MPFR_RNDD);
    mpfr_set_str(two, "2.0", 10, MPFR_RNDD);
    mpfr_set_str(q, "0.0", 10, MPFR_RNDD);
    mpfr_set_str(r, "0.0", 10, MPFR_RNDD);
    mpfr_set_str(exp, "0.0", 10, MPFR_RNDD);
    mpfr_set_str(e, "0.0", 10, MPFR_RNDD);
    mpfr_set_str(e_count, "0.0", 10, MPFR_RNDD);
    mpfr_set_str(base, "2.0", 10, MPFR_RNDD);
    mpfr_set_str(count, "0.0", 10, MPFR_RNDD);
    mpfr_set_str(is_prime, "2.0", 10, MPFR_RNDD);
    mpfr_set_str(print, "1.0", 10, MPFR_RNDD);
    mpfr_set_str(print_count, "0.0", 10, MPFR_RNDD);

    if (argc == 2)
    {
        mpfr_set_str(numbers_min, argv[1], 10, MPFR_RNDN);
        mpfr_set_str(numbers_max, argv[1], 10, MPFR_RNDN);

        mpfr_log10(log_2, two, MPFR_RNDD);
        mpfr_div(log_2_temp, one, log_2, MPFR_RNDD);

        mpfr_div(digits_max, numbers_min, log_2_temp, MPFR_RNDD);
        mpfr_add_ui(digits_max, digits_max, 1, MPFR_RNDD);
        mpfr_floor(digits_max, digits_max);

        mpfr_set(digits_min, digits_max, MPFR_RNDD);
    }
    else if (argc == 3)
    {
        mpfr_set_str(numbers_min, argv[1], 10, MPFR_RNDN);
        mpfr_set_str(numbers_max, argv[2], 10, MPFR_RNDN);

        mpfr_log10(log_2, two, MPFR_RNDD);
        mpfr_div(log_2_temp, one, log_2, MPFR_RNDD);

        mpfr_div(digits_min, numbers_min, log_2_temp, MPFR_RNDD);
        mpfr_add_ui(digits_min, digits_min, 1, MPFR_RNDD);
        mpfr_floor(digits_min, digits_min);
        
        mpfr_div(digits_max, numbers_max, log_2_temp, MPFR_RNDD);
        mpfr_add_ui(digits_max, digits_max, 1, MPFR_RNDD);
        mpfr_floor(digits_max, digits_max);
    }
    else if (argc == 4)
    {
        mpfr_set_str(numbers_min, argv[1], 10, MPFR_RNDN);
        mpfr_set_str(numbers_max, argv[2], 10, MPFR_RNDN);
        mpfr_set_str(digits_min, argv[3], 10, MPFR_RNDN);
        mpfr_set_str(digits_max, argv[3], 10, MPFR_RNDN);
    }
    else if (argc == 5)
    {
        mpfr_set_str(numbers_min, argv[1], 10, MPFR_RNDN);
        mpfr_set_str(numbers_max, argv[2], 10, MPFR_RNDN);
        mpfr_set_str(digits_min, argv[3], 10, MPFR_RNDN);
        mpfr_set_str(digits_max, argv[4], 10, MPFR_RNDN);
    }
    else
    {
        mpfr_set_str(numbers_min, "1", 10, MPFR_RNDN);
        mpfr_set_str(numbers_max, "100", 10, MPFR_RNDN);
        mpfr_set_str(digits_min, "1", 10, MPFR_RNDN);
        mpfr_set_str(digits_max, "5", 10, MPFR_RNDN);

        printf("Usage: %s <exp min> <exp max> <digits min> <digits max>\n\n", argv[0]);
        printf("Example1: ./is_M127.out 1 200 30 39\n\n");
        printf("==================== Example Data ====================\n");
        printf("1                  97 ~ 99         [ 30         ]    97 : (6) (5)\n"); 
        printf("2                 100 ~ 102        [ 31         ]    101 : (6) (5) (2)\n"); 
        printf("3                 103 ~ 106        [ 32         ]    103 : (6) (5) (2) (1)\n");
        printf("4                 107 ~ 109        [ 33         ]    107 : (6) (5) (3) (1) \n");
        printf("5                 107 ~ 109        [ 33         ]    109 : (6) (5) (3) (2) \n");
        printf("6                 113 ~ 116        [ 35         ]    113 : (6) (5) (4) \n");
        printf("7                 127 ~ 129        [ 39         ]    127 : (6) (5) (4) (3) (2) (1)\n\n");
    }

    if (mpfr_cmp(numbers_min, zero) <= 0 || mpfr_cmp(numbers_max, zero) <= 0 || mpfr_cmp(digits_min, zero) <= 0 || mpfr_cmp(digits_max, zero) <= 0)
    {
        mpfr_set_str(numbers_min, "1.0", 10, MPFR_RNDN);
        mpfr_set_str(numbers_max, "1.0", 10, MPFR_RNDN);
        mpfr_set_str(digits_min, "1.0", 10, MPFR_RNDN);
        mpfr_set_str(digits_max, "1.0", 10, MPFR_RNDN);        
    }

    for (mpfr_set(digits_count, digits_min, MPFR_RNDD); mpfr_cmp(digits_count, digits_max) <= 0; mpfr_add_ui(digits_count, digits_count, 1, MPFR_RNDD))
    {
        mpfr_log10(log_2, two, MPFR_RNDD);
        mpfr_div(log_2_temp, one, log_2, MPFR_RNDD);

        mpfr_set(digits, digits_count, MPFR_RNDD);
        mpfr_set(digits_zero, digits_count, MPFR_RNDD);
        mpfr_sub_ui(digits_minus_1, digits, 1, MPFR_RNDD);
        mpfr_add_ui(digits_plus_1, digits, 1, MPFR_RNDD);

        mpfr_mul(digits_change, digits, log_2_temp, MPFR_RNDD);
        mpfr_mul(digits_change_min, digits_minus_1, log_2_temp, MPFR_RNDD);
        mpfr_mul(digits_change_max, digits_plus_1, log_2_temp, MPFR_RNDD);

        mpfr_add_ui(digits_change_min, digits_change_min, 1, MPFR_RNDD);

        mpfr_floor(digits_change, digits_change);
        mpfr_floor(digits_change_min, digits_change_min);
        mpfr_floor(digits_change_max, digits_change);

        if ((mpfr_cmp(digits_change_min, numbers_min) >= 0 || mpfr_cmp(digits_change, numbers_min) >= 0)
            && (mpfr_cmp(digits_change_min, numbers_max) <= 0 || mpfr_cmp(digits_change, numbers_max) <= 0))
        {
            mpfr_add_ui(print_count, print_count, 1, MPFR_RNDD);

            for (mpfr_set(is_prime, digits_change_min, MPFR_RNDD); mpfr_cmp(is_prime, digits_change) <= 0; mpfr_add_ui(is_prime, is_prime, 1, MPFR_RNDD))
            {
                mpfr_set(e, is_prime, MPFR_RNDD);
                mpfr_set(exp, is_prime, MPFR_RNDD);

                mpfr_get_z(prime, is_prime, MPFR_RNDD);

                if (mpz_probab_prime_p(prime, 1024U) != 0)
                {
                    mpfr_add_ui(count, count, 1, MPFR_RNDD);

                    mpfr_printf("%-10.0Rf %10.0Rf ~ %-10.0Rf [ %-10.0Rf ]    ", count, digits_change_min, digits_change_max, digits);

                    mpfr_printf("%0.0Rf : ", is_prime);

                    while(1)
                    {
                        while(1)
                        {
                            mpfr_div(q, e, two, MPFR_RNDD);
                            mpfr_floor(q, q);
                            mpfr_div(r, e, two, MPFR_RNDD);
                            mpfr_sub(r, r, q, MPFR_RNDD);

                            if (mpfr_cmp(q, zero) == 0)
                            {
                                mpfr_set(e, exp, MPFR_RNDD);
                                mpfr_pow_ui(exp, base, mpfr_get_ui(e_count, MPFR_RNDD), MPFR_RNDD);
                                mpfr_sub(e, e, exp, MPFR_RNDD);
                                mpfr_printf("(%0.0Rf) ", e_count);
                                mpfr_set(exp, e, MPFR_RNDD);
                                break;
                            }
                            else
                            {
                                mpfr_set(e, q, MPFR_RNDD);
                                mpfr_add_ui(e_count, e_count, 1, MPFR_RNDD);
                            }
                        }

                        mpfr_set_str(e_count, "0", 10, MPFR_RNDD);

                        if (mpfr_cmp(e, one) == 0 || mpfr_cmp(e, zero) == 0) break;
                    }
                    
                    if (mpfr_cmp(print_count, one) >= 0)
                        printf("\n");
                }
            }
        }
    }

    mpfr_clear(digits_min);
    mpfr_clear(digits_max);
    mpfr_clear(digits_count);
    mpfr_clear(numbers_min);
    mpfr_clear(numbers_max);
    mpfr_clear(digits);
    mpfr_clear(digits_minus_1);
    mpfr_clear(digits_zero);
    mpfr_clear(digits_plus_1);
    mpfr_clear(digits_change);
    mpfr_clear(digits_change_min);
    mpfr_clear(digits_change_max);
    mpfr_clear(log_2);
    mpfr_clear(log_2_temp);
    mpfr_clear(zero);
    mpfr_clear(one);
    mpfr_clear(two);
    mpfr_clear(q);
    mpfr_clear(r);
    mpfr_clear(exp);
    mpfr_clear(e);
    mpfr_clear(e_count);
    mpfr_clear(base);
    mpfr_clear(count);

    return 0;
}
