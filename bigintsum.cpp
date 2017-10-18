#include <iostream>

using std::string;
using std::cout;
using std::cin;
int toInt(char a)
{
    int tmp = (int)a;

    return abs(48-tmp);
}
string reverse(string a)
{
    string newOne;
    for(int i = a.size() - 1 ; i >= 0; i--)
    {
        newOne += a[i];
    }

    return newOne;
}
char toChar(int a)
{
    return (char)48+a;
}
string dodawanie(string a, string b)
{
    int ogon;
    string longer, shorter;
    bool increment = false;
    bool bigger;
    if (a.size() >= b.size())
    {
        bigger = true;
        longer = reverse(a);
        shorter = reverse(b);
    }
    else
    {
        bigger = false;
        longer = reverse(b);
        shorter = reverse(a);
    }
    string wynik;

    for (int i = 0; i < shorter.size(); i++)
    {
            int inc;
            increment ? inc = 1 : inc = 0;
            int sum = toInt(longer[i]) + toInt(shorter[i]) + inc;
            if(sum >= 10)
            {
                ogon = sum - 10;
                wynik += toChar(ogon);
                increment = true;
            }
            else if(sum < 10)
            {
                wynik += toChar(sum);
                increment = false;
            }
    }

    if(bigger)
    {
        for(int i = shorter.size(); i < longer.size(); i++)
        {
            if(increment)
            {
                int x = 1;
                int y = toInt(longer[i]);

                if(x + y >= 10)
                {
                    wynik +=  (x + y - 10);
                    increment = true;
                }else
                {
                    increment = false;
                    wynik += toChar(x + y);
                }


            }
            else
                wynik += longer[i];
        }
    }

    if(increment && longer.size() == shorter.size())
        wynik += toChar(1);

    return reverse(wynik);
}

int main()
{
  cout << "Dodawanie duzych liczb!!\n" << "Podaj liczbe pierwsza: ";
  string l1,l2;
  cin >> l1;
  cout << "Podaj liczbe druga: ";
  cin >> l2;
  cout << "Wynik to : " + dodawanie(l1,l2);
}
