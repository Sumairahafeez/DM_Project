#include <iostream>
using namespace std;

int calculateGCD(int num1, int num2);
int calculateLCM(int a, int b);

main()
{
    int num1, num2;
    cout << "*LEAST COMMON MULTIPLE (LCM)*" << endl;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    int lcm = calculateLCM(num1, num2);

    cout << "The LCM of " << num1 << " and " << num2 << " is: " << lcm << endl;

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

int calculateLCM(int a, int b)
{
    int gcd = calculateGCD(a, b);
    return (a * b) / gcd;
}