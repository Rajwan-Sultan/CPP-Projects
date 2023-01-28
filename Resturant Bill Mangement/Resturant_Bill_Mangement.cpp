#include <bits/stdc++.h>
using namespace std;

class Restaurant
{
public:
    int code;
    string item;
    float price, tax;
    Restaurant(int c, string s, float p, float t)
    {
        code = c;
        item = s;
        price = p;
        tax = t;
    }
};

class T
{
public:
    int co, q, table;
    string s;
    float total = 0, taxes = 0;
    T(int x, int quan)
    {
        co = x;
        q = quan;
    }
};

Restaurant *makeBill()
{
    int c;
    string i;
    float p;
    cin >> c;
    getchar();
    // getline(cin,i);
    cin>>i;
    cin>>p;
    float t = 0;
    Restaurant *bill = new Restaurant(c, i, p, t);
    return bill;
}

T *addBill()
{
    int q, code;
    cout << "Enter the code: ";
    cin >> code;
    cout << "Enter the quantity: ";
    cin >> q;
    T *a_bill = new T(code, q);
    return a_bill;
}

void out(Restaurant *a)
{
    cout << a->code << "\t\t\t\t" << a->item << "\t\t\t\t" << a->price << endl;
    // cout<<"CODE->"<<<<" ITEM->"<<<<" PRICE->"<<<<endl;
}

void out_Bill(T *a)
{
    cout << a->co << "\t\t\t\t" << a->s << "\t\t\t\t" << a->q << "\t\t\t" << a->total << endl;
    // cout<<"CODE->"<<<<" ITEM->"<<<<" PRICE->"<<<<endl;
}

void assign_code(Restaurant *acc, T *z)
{
    if (z->co == acc->code)
    {
        z->s.assign(acc->item);
        z->total += ((acc->price) * (z->q));
        z->taxes = ((z->total * 5) / 100);
        acc->tax += z->taxes;
    }
}

bool check_element(Restaurant *a[], int l, int x)
{
    for (int i = 0; i < l; i++)
    {
        if (a[i]->code == x)
            return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    Restaurant * acc[n];
    for (int i = 0; i < n; i++)
    {
        acc[i] = makeBill();
    }

    cout << "\t\t\t\tMake Bill" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "ITEM CODE\t\t\tITEM NAME\t\t\tITEM PRICE" << endl;
    cout << "*********\t\t\t*********\t\t\t**********" << endl;
    for (int i = 0; i < n; i++)
    {
        out(acc[i]);
    }

    int n1, t;
    cout << "Enter table number: ";
    cin >> t;
    cout << "Enter number of items: ";
    cin >> n1;

    T *z[n1];
    int i = 0, j;

    for (i; i < n1; i++)
    {
    flag:
        z[i] = addBill();
        if (check_element(acc, n, z[i]->co))
        {
            continue;
        }
        else
        {
            cout << "INVALID CODE.RETRY" << endl;
            goto flag;
        }
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            assign_code(acc[j], z[i]);
        }
    }

    cout << "\t\t\t\t Bill    FOR     TABLE NO: " << t << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "ITEM CODE\t\t\tITEM NAME\t\t\tQUANTITY\t\tTOTAL PRICE" << endl;
    cout << "*********\t\t\t*********\t\t\t********\t\t***********" << endl;
    for (int i = 0; i < n1; i++)
    {
        out_Bill(z[i]);
    }

    float sum_of_tax = 0;
    float total = 0;
    for (int i = 0; i < n; i++)
    {
        sum_of_tax += acc[i]->tax;
    }
    for (int i = 0; i < n1; i++)
    {
        total += z[i]->total;
    }
    total += sum_of_tax;
    cout << "TAX:\t\t\t\t\t\t\t\t\t\t\t" << sum_of_tax << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "NET TOTAL:"
         << "TAX:\t\t\t\t\t\t\t\t\t" << total << endl;
}
