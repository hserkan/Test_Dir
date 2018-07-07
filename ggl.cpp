#include <iostream>
using namespace std;
const int num_digits = 10;
const int num_primes = 4;
const int num_evens = 5;
int prime_array[num_primes] = {2, 3, 5, 7};
int even_array[num_evens] = {0,2,4,6,8};
int number[num_digits];
void prime_digit(int index, int digit);

void print_number() 
{
    for (int j = 0; j < num_digits; j++)
        cout << number[j]; 
    cout << endl;
}
 
void even_digit(int index, int digit)
{
    number[digit] = even_array[index];
    if (digit < num_digits - 1)
    {
        for (int i = 0; i < num_primes; i++)
            prime_digit(i,digit+1);
    }
    else 
        print_number();
}

void prime_digit(int index, int digit)
{
    number[digit] = prime_array[index];
    if (digit < num_digits - 1)
    {
        for (int i = 0; i < num_evens; i++)
            even_digit(i,digit+1);
    }
    else
        print_number();
}

int main()
{
    for (int i = 1; i < num_evens; i++)
        even_digit(i, 0);
    return 1;
}
