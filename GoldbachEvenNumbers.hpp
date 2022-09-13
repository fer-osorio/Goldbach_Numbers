/*In this file we'll try to write every natural number (up to certain threshold) as a sum of two
    primes.*/

#include"SomeDataTypes.hpp"

/*prime1 + prime2 = number*/
typedef struct goldbachEvenSum{
    ui64 number;    /*Number has to be even.*/
    ui64 prime1;
    ui64 prime2;
}GoldbachEvenSum;

/*Attempting to build an array in witch each element is conformed by a number 'n' and two primes,
    where the sum of the two primes is equal to the n.*/
GoldbachEvenSum* Goldbach_even_numbers(ui64 threshold);