#!/bin/sh

gcc print_mersenne_prime_numbers.c -o print_mersenne_prime_numbers.out -lm -lgmp -lmpfr
gcc print_mersenne_prime_numbers.c -o print_mersenne_prime_numbers.ubuntu_22.04.3LTS -lm -lgmp -lmpfr
./print_mersenne_prime_numbers.ubuntu_22.04.3LTS > print_mersenne_prime_numbers.txt
gcc print_mersenne_digits.c -o print_mersenne_digits.out -lm -lgmp -lmpfr
gcc print_mersenne_digits.c -o print_mersenne_digits.ubuntu_22.04.3LTS -lm -lgmp -lmpfr
./print_mersenne_digits.ubuntu_22.04.3LTS > print_mersenne_digits.txt
gcc print_mersenne_ratio.c -o print_mersenne_ratio.out -lm -lgmp -lmpfr
gcc print_mersenne_ratio.c -o print_mersenne_ratio.ubuntu_22.04.3LTS -lm -lgmp -lmpfr
./print_mersenne_ratio.ubuntu_22.04.3LTS > print_mersenne_ratio.txt
gcc print_mersenne_ratio_reverse.c -o print_mersenne_ratio_reverse.out -lm -lgmp -lmpfr
gcc print_mersenne_ratio_reverse.c -o print_mersenne_ratio_reverse.ubuntu_22.04.3LTS -lm -lgmp -lmpfr
./print_mersenne_ratio_reverse.ubuntu_22.04.3LTS > print_mersenne_ratio_reverse.txt
gcc print_mersenne_log_2_near.c -o print_mersenne_log_2_near.out -lm -lgmp -lmpfr
gcc print_mersenne_log_2_near.c -o print_mersenne_log_2_near.ubuntu_22.04.3LTS -lm -lgmp -lmpfr
./print_mersenne_log_2_near.ubuntu_22.04.3LTS > print_mersenne_log_2_near.txt
gcc print_mersenne_log_2_near_reverse.c -o print_mersenne_log_2_near_reverse.out -lm -lgmp -lmpfr
gcc print_mersenne_log_2_near_reverse.c -o print_mersenne_log_2_near_reverse.ubuntu_22.04.3LTS -lm -lgmp -lmpfr
./print_mersenne_log_2_near_reverse.ubuntu_22.04.3LTS > print_mersenne_log_2_near_reverse.txt

echo "compile print_mersenne_prime_numbers and run done"

gcc is_prime.c -o is_prime.out -lm -lgmp
gcc is_prime.c -o is_prime.ubuntu_22.04.3LTS -lm -lgmp

echo "compile is_prime and run done"

gcc is_mersenne_prime.c -o is_mersenne_prime.out -lm -lgmp -lmpfr
gcc is_mersenne_prime.c -o is_mersenne_prime.ubuntu_22.04.3LTS -lm -lgmp -lmpfr

echo "compile is_mersenne_prime and run done"

gcc is_M127.c -o is_M127.out -lm -lgmp -lmpfr
gcc is_M127.c -o is_M127.ubuntu_22.04_3LTS -lm -lgmp -lmpfr

echo "compile is_M127 and run done"
