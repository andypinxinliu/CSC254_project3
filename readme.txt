#use "ecl_interpret.ml";;
#use "ecl_test.ml";;
ocamlc -o test_ecl str.cma ecl_test.ml
./test_ecl < primes.ecl > primes_test.c
./test_ecl < gcd.ecl > gcd_test.c
./test_ecl < sum.ecl > sum_test.c
gcc -o primes_test primes_test.c
gcc -o gcd_test gcd_test.c
gcc -o sum_test sum_test.c
./primes_test
./gcd_test
./sum_test