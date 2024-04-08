#include<iostream>
#include<tuple>
using namespace std;
pair<int,int> calculateBezout(int num1, int num2, int s, int t);
tuple<int,int,int> calculateGCD(int num1, int num2);
main()
{
    int num1, num2, s, t;
    cout<<"Enter the first number: ";
    cin>>num1;
    cout<<"Enter the second number: ";
    cin>>num2;
    std::tie(s,t) = calculateBezout(num1, num2,s,t);
    cout<<"Bezout coefficients are: "<<s<<" and "<<t<<endl;
    cout<<"The inverse is: ";
    //formula is ax=bmodm where a = num1 , b = 1 , x = s and t and m= num2;
    //if m%ax-1 == 0 then it is a inverse
    int inverse1 = num2%((num1*s)-1);
    int inverse2 = num2%((num1*t)-1);
    if(inverse1 == 0)
    {
        cout<<s<<"  ";
    }
    if(inverse2 == 0)
    {
        cout<<t<<"  ";
    }
 
}
pair<int,int> calculateBezout(int num1, int num2, int s, int t)
{   int gcd;
    std::tie(gcd,s,t)=calculateGCD(num1, num2);
    return std::make_pair(s,t);
}
tuple<int,int,int> calculateGCD(int num1, int num2)
{   int g,x,y;
    if(num1==0)
    {
        return std::make_tuple(num2, 0, 1);

    }
    else
    {
        std::tie(g,x,y) = calculateGCD(num2%num1, num1);
        return std::make_tuple(g,y-(num2/num1)*x, x);
    }
}
