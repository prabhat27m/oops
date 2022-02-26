#include <iostream>
using namespace std;
class date
{
public:
    int dd, mm, yy;
    void read()
    {
        cout << "Enter date:" << endl;
        cin >> dd >> mm >> yy;
    }
    int operator-(date);
    date operator+(int);
    friend ostream &operator<<(ostream &print, date &d);
};
int a[] = {0,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int b[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int date::operator-(date d2){
    int i, nod1, nod2, nody, lc, no_of_days;
    nod1 = nod2 = lc = 0;

    for (i = 1; i < mm; i++)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            nod1 += 31;
        else if (i == 2)
            nod1 += 28;
        else
            nod1 += 30;
    }

    nod1 += dd;

    for (i = 1; i < d2.mm; i++)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            nod2 += 31;
        else if (i == 2)
            nod2 += 28;
        else
            nod2 += 30;
    }

    nod2 += d2.dd;


    nody = (yy - d2.yy) * 365;


    for (i = d2.yy; i < yy; i++)
        if ((i % 4) == 0)
            lc++;

    if ((mm > 2) && (yy % 4) == 0)
        lc++;
    if ((d2.mm > 2) && (d2.yy % 4) == 0)
        lc--;

    no_of_days = nody + nod1 - nod2 + lc;
   
        cout << "total number of days between these dates is= ";
        return (no_of_days);    
}

date date::operator+(int ndays)
{
    date d;
    d.dd = dd, d.mm = mm, d.yy = yy;
    for (int i = 1; i <= ndays; i++)
    {
        d.dd++;
        if (d.yy % 4 == 0)
        {
            if (d.dd > a[d.mm])
            {
                d.dd = 1;
                d.mm++;
            }
        }
        else
        {
            if (d.dd > b[d.mm])
            {
                d.dd = 1;
                d.mm++;
            }
        }
        if (d.mm > 12)
        {
            d.mm = 1;
            d.yy++;
        }
    }
    return d;
}
ostream &operator<<(ostream &out, date &d)
{
    out << "The date is:" << endl;
    out << d.dd << "/ " << d.mm << "/ " << d.yy << endl;
    return out;
}
int main()
{
    date d;
    d.read();
    cout << d;
    date d1 = d.operator+(1000);
    cout << d1;
    date d2;
    d2.read();
    cout<<d.operator-(d2);
    return 0;
}