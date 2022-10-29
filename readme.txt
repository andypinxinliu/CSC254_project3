#use "ecl_interpret.ml";;
#use "ecl_test.ml";;
ocamlc -o test_ecl str.cma ecl_test.ml
./test_ecl < primes.ecl > primes_test.c