#include <iostream>
#include <cstdlib>

bool isPrime(int x)
{
    if (x == 2) { return true; }
    if ((x & 1) == 0) { return false; }

    const int FactorUpperBound = x / 2;
    for (int i = 3; i < FactorUpperBound; i += 2)
    {
        if (x % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char** argv)
{
    int a = std::atoi(argv[1]);

    std::cout << (a & 1) << std::endl;
    std::cout << (isPrime(a) ? "prime" : "not prime") << std::endl;
}

