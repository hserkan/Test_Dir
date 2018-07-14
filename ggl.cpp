#include <iostream>
using namespace std;
const int num_digits = 10;
const int num_primes = 4;
const int num_evens = 5;
int prime_array[num_primes] = {2, 3, 5, 7};
int even_array[num_evens] = {0,2,4,6,8};
int number[num_digits];
void prime_digit(int index, int digit);

void helloWorldTest()
 {
    const std::string myString = "Hello World";

    auto it = myString.find("Hello");
    if (it != std::string::npos)
        std::cout << it << " Hello\n";
    
    auto it2 = myString.find("World");
    if (it2 != std::string::npos)
        std::cout << it2 << " World\n";

	// additional enclosing scope so 'it' doesn't 'leak'
    {
		auto it = myString.find("Hello");
		if (it != std::string::npos)
            std::cout << "Hello\n";
    }
    
    {
        auto it = myString.find("World");
        if (it != std::string::npos)
            std::cout << "World\n";
    }

	// C++17 with init if:
    if (const auto it = myString.find("Hello"); it != std::string::npos)
        std::cout << it << " Hello\n";

    if (const auto it = myString.find("World"); it != std::string::npos)
        std::cout << it << " World\n";
}

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
    int number;
    helloWorldTest();
    cin >> number;
    for (int i = 1; i < num_evens; i++)
        even_digit(i, 0);
    return 1;
}
