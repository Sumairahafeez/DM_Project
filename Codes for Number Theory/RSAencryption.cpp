#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int gcd(int num1, int num2);
string rsaMessage(string message, int n, int e);
int modularPow(int base, int exponent, int modulus);
int main()
{
    int p,q,n,e;
    string message;
    cout<<"Enter first odd prime numbers p: ";
    cin>>p;
    cout<<"Enter second odd prime numbers p: ";
    cin>>q;
    cout<<"Enter a public key exponent (e): ";
    cin>>e;
    cout<<"Enter the message: ";
    cin.ignore();
    getline(cin, message); 
    //First we have to calculate n=pq
    n = p*q;
    int product = (p-1)*(q-1);
    //checking if it is relatively prime otherwise generate error
    if(gcd(n, product)!=1)
    {   
        std::cerr << "Error: e must be relatively prime to (p-1)(q-1)." << std::endl;
        return 1;
    } 
    string encryptedMessage=rsaMessage(message,n,e);
    cout<<"The Encrypted Message is: "<<encryptedMessage;
    
   return 0;  
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
string rsaMessage(string message, int n, int e)
{   int charValue;
string encrypted_message;
    //Its Formula is C=M^e mod n where M is message and c is encrypted message
    for (char ch : message) 
    
    {
        // Convert each character to its corresponding two-digit number (A=00, B=01, C=02, ..., Z=25)
        charValue = static_cast<int>(ch) - 'A';
        int cypherText = modularPow(charValue,e,n);
        string encrypted_digit = (cypherText < 10) ? "0" + to_string(cypherText) : to_string(cypherText);

        // Append the encrypted character to the result string
         encrypted_message += encrypted_digit + " ";
    }
    return encrypted_message;
    
}
// Function to calculate modular exponentiation (a^b mod m)
int modularPow(int base, int exponent, int modulus) {
    int result = 1;
    base = base % modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }

    return result;
}