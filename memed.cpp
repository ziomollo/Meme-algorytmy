#include<iostream>
#include<cmath>
using std::cout;
using std::endl;
using std::cin;

bool modulo_exponent(unsigned short base, unsigned short exponent, unsigned short mod)
{
    unsigned short result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return (bool)(result - 1);
}

bool euklides(unsigned short a,unsigned short b)
{
   while (a != b)
    {
        if (a < b)
            b -= a;
        else
            a -= b;
    }

    if(a == 1)
        return true;

    return false;
}

bool prime(unsigned short a)
{
    for(unsigned short i = 2 ; i * i <= a ; ++i)
        if(a % i == 0)
            return false;

    return true;
}


bool karmelowa(unsigned short a)
{
    if(prime(a))
        return false;

    for(unsigned short i=2; i < a; ++i)
    {
        if(euklides(a,i))
            if(modulo_exponent(i,a-1,a))
                return false;
    }

    return true;
}
int main()
{

    unsigned short tab[10];
    unsigned short n,i = 0;

    while(cin >> n && n != 0)
    {
        tab[i] = n;
        ++i;
    }

    for(int j = 0 ; j <= i-1 ; ++j)
    {
        if(karmelowa(tab[j]))
        {
            cout << "The number " << tab[j] << " is a Carmichael number.\n";
        }
        else
        {
            cout << tab[j] << " is normal.\n";
        }
    }
}
