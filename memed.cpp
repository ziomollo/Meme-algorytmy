#include<iostream>
#include<cmath>
using std::cout;

bool euklides(int a,int b)
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

bool prime(int a)
{
    for(int i = 2 ; i * i <= a ; ++i)
        if(a % i == 0)
            return false;

    return true;
}

bool divided(int a, int b)
{
    int p = pow(a,b-1);
    p -= 1;


    cout << p << "\n";
    if(p == 0)
        return true;

    return false;
}

bool karmelowa(int a)
{
    if(prime(a))
        return false;

    for(int i=2; i < a; ++i)
    {
        if(euklides(a,i))
            if(!divided(i,a))
                return false;
    }

    return true;
}
int main()
{

    cout << std::boolalpha;
    int a = 1729;



    cout << divided(2,561);
    //cout << karmelowa(1729);

   ;

}
