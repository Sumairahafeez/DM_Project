#include<iostream>
using namespace std;
int calculateGCD(int num1, int num2);
main()
{
    int num1, num2;
    cout<<"Enter the first number: ";
    cin>>num1;
    cout<<"Enter the second number: ";
    cin>>num2;
    cout<<"Gcd is: "<<calculateGCD(num1, num2);

}
int calculateGCD(int num1, int num2)
{
    while(num2!=0)
    {
        int temp = num2;
        num2 = num1%num2;
        num1 = temp;
    }
    return num1;
}