/*In this file we'll try to write every natural number (up to certain threshold) as a sum of two
    primes.*/

#include"GoldbachEvenNumbers.hpp"
#include"PrimeList.hpp"

GoldbachEvenSum* Goldbach_even_numbers(ui64 threshold){
    PrimeList primes(threshold);
    int pl = primes.length; //primes length

    int** goldbachGrid = new int*[pl];
    int i;
    for(i = 0; i < pl; i++)
        goldbachGrid[i] = new int[pl];

    int pl2 = pl*pl;
    pointer_prime ptr_p1 = primes.primes, ptr_p2 = primes.primes;
    for(i = 0; i < pl2; i++){
        goldbachGrid[i/pl][i%pl] = ptr_p1->primeNumber + ptr_p2->primeNumber;
        ptr_p2 = ptr_p2->nextPrime;
        if(ptr_p2 == nullptr){
            ptr_p1 = ptr_p1->nextPrime;
            ptr_p2 = primes.primes;
        }
    }
    int AoEN; // Amaount of even Numbers (greater than zero and smallers or equals than 'threshold').
    if(threshold%2) // Even
        AoEN = threshold/2;
    else // Odd
        AoEN = (threshold - 1)/2;

    //GoldbachEvenSum Array.
    GoldbachEvenSum* gesArray = new GoldbachEvenSum[AoEN - 1];
    int j = 0, k = 0;
    ptr_p1 = primes.primes;
    ptr_p2 = primes.primes;
    for(i = 2; i <= AoEN; i++){
        while(j < pl && goldbachGrid[j][k] != i*2){
            k++; ptr_p2 = ptr_p2->nextPrime;
            if(k == pl){
                k = 0; ptr_p2 = primes.primes;
                j++; ptr_p1 = ptr_p1->nextPrime;
            }
        }
        if(ptr_p1 != nullptr && ptr_p2 != nullptr){
            gesArray[i-2].number = i*2;
            gesArray[i-2].prime1 = ptr_p1->primeNumber;
            gesArray[i-2].prime2 = ptr_p2->primeNumber;
        }    
    }
    return gesArray;
}