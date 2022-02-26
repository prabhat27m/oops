#include <bits/stdc++.h>
using namespace std;
class octal
{
public:
    int oct[15], count;
    octal(int a);
    int operator+(int a);
    friend ostream &operator<<(ostream &out, octal &c);
};
octal::octal(int x)
{
    int i = 0, rem, a[15];
    while (x != 0)
    {
        rem = x % 8;
        x = x / 8;
        a[i++] = rem;
    }
    count = i;
    int j = count - 1;
    cout << i;
    for (int i = 0; i < count; i++)
    {
        oct[i] = a[j--];
    }
}
int octal::operator+(int k)
{
    int x = 0;
    int j = count - 1;
    for (int i = 0; i < count; i++)
    {
        x = x + oct[j] * pow(8, i);
        j--;
    }
    return (x + k);
}
ostream &operator<<(ostream &print, octal &o)
{
    for (int i = 0; i < o.count; i++)
        print << o.oct[i];
    return print;
}
int main()
{
    int x, k, y = 0;
    cout << "\nEnter the Integer value of x (In Decimal) : ";
    cin >> x;
    octal h = octal(x);
    cout << "The corresponding Octal Equivalent of " << x << " is : " << h;
    cout << "\n\nEnter the integer to be added to the Octal value : ";
    cin >> k;
    y = h + k;
    cout << "\t\t\t" << h << " (Octal) + " << k << " (Decimal) = " << y << " (Decimal)";
}
