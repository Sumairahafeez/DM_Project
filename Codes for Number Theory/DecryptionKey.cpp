#include<iostream>
#include<tuple>
using namespace std;
int decryptionKey(int p, int q, int e);
int gcd(int num1, int num2);
int modularInverse(int num1, int num2);
int main()
{
    int p,q,e;
    cout<<"Enter the first prime number p: ";
    cin>>p;
    cout<<"Enter the second prime number q: ";
    cin>>q;
    cout<<"Enter the encryption key (e): ";
    cin>>e;
    int d = decryptionKey(p,q,e);
    cout<<"Decryption Key is: "<<d;
    return 0;
}    
int modularInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) {
        return 0;
    }

    while (a > 1) {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as Euclid's algorithm
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0) {
        x1 += m0;
    }

    return x1;
}
int gcd(int num1, int num2)
{
     while(num2!=0)
    {
        int temp = num2;
        num2 = num1%num2;
        num1 = temp;
    }
    return num1;
}
int decryptionKey(int p, int q, int e)
{   int n = p*q;
    int product =(p-1) * (q-1);
    int d;
    d = modularInverse(e, product);
    return d;
}