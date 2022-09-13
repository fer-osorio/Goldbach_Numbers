/*  This class will store the primes up to certain threshold.*/
/*  We are consider the set of primes as an ordered set.*/

#include"SomeDataTypes.hpp"

/*  We need to save the prime and its position in the set of primes, that is the reason for the 'index'
    fied; for example: the number two has the index one, the number three has the index two, the number
    five has the index three and so on.*/
typedef struct prime
{
    unsigned long long primeNumber;
    unsigned int index;
    struct prime *nextPrime;
}Prime;

typedef Prime* pointer_prime;

class PrimeList{
    public:
        pointer_prime primes;
        unsigned int length;

    PrimeList(void);
    PrimeList(ui64 threshold);

    /*  This function gives us the biggest integer that is smaller or equal than the square root of
        'number'.*/
    ui64 Integral_square_root(ui64 number);
    /*  Creates a new element for the list of pointers.*/
    pointer_prime New_pointer_prime(unsigned long long primeNumber, unsigned int index);
    /*  Find the primes smallers or equals than threshold using the sieve of Eratosthenes.*/
    pointer_prime Eratosthenes_sieve(const ui64 threshold);
    void Print_list(void);
    /*Realese used memory.*/
    void Clean_list(void);
};