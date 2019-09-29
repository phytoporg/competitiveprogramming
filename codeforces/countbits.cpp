#include <iostream>
#include <cstdlib>

typedef unsigned long long bigtype;

bigtype countBits(int x)
{
    bigtype numSet = 0;
    while(x > 0)
    {
        x &= (x - 1);
        ++numSet;
    }

    return numSet;
}

int main(int argc, char** argv)
{
    int a = std::atoi(argv[1]);

    std::cout << countBits(a) << std::endl;
}

