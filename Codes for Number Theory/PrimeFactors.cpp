#include<iostream>
using namespace std;
void calculatePrimeFactors(int num);
main()
{   int number;
    cout<<"Enter the Number: ";
    cin>>number;
    cout<<"Prime Factorization of number is: ";
    calculatePrimeFactors(number);

}
void calculatePrimeFactors(int num)
{
    //check if it is a factor of 2
    while(num % 2 == 0)
    {
        cout<<"2";
        num = num/2;
        if(num>1)
        {
            cout<<" x ";
        }
    }
    //check if it is factor of odd primes
    int i = 3;
    while(num!=1)
    { while(num % i == 0)
        {   num = num/i;
            if(i<0)
            {   
                i = i * (-1);
                cout<<i;
            }
            else if(i>0)
            {   
               cout<<i;  
            }
            if(num!= 1)
        {
            cout<<" x ";
        }
        }i=i+2;
    }
}