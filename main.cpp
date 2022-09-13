#include<iostream>
#include"PrimeList.hpp"
#include"GoldbachEvenNumbers.hpp"

int main(int argc, char* argv[]){
    ui64 upperBound;
    std::cout << "Set an upper bound\n";
    std::cin >> upperBound;

    //Goldbach even numbers list.
    GoldbachEvenSum* genList = Goldbach_even_numbers(upperBound);
    int AoEN; // Amaount of even Numbers (greater than zero and smallers or equals than 'threshold').
    if(upperBound%2) // Even
        AoEN = upperBound/2;
    else // Odd
        AoEN = (upperBound - 1)/2;

    for(int i = 0; i < AoEN -1; i++)
        std::cout << genList[i].prime1 << " + " << genList[i].prime2 << " = " << genList[i].number << '\n'; 
}