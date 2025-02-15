#include <iostream>
#include <limits> 
using namespace std;

int main() 
{
    double num1,num2;
    char operation,continueCalculation;

    cout<<"Enter the first number:";
    cin>>num1;

    while (cin.fail()) 
    {
        cout<<"Invalid input.please enter a number:";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin>>num1;
    }
    cout<<"Enter the second number:";
    cin>>num2;

    while (cin.fail()) 
    {
        cout<<"Invalid input.Please enter a number:";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin>>num2;
    }

    cout<<"Enter the operation(+, -, *, /):";
    cin>>operation;

    switch (operation) 
    {
        case '+':
            cout<<num1<<"+"<<num2<<"="<<num1+num2<<endl;
            break;

        case '-':
            cout<<num1<<"-"<<num2<<"="<<num1-num2<<endl;
            break;

        case '*':
            cout<<num1<<"*"<<num2<<"="<<num1*num2<<endl;
            break;

        case '/':
            
            if(num2==0)
            {
                cout<<"Error:Division by zero is not allowed."<<endl;
            } else 
            {
                cout<<num1<<"/"<<num2<<"="<<num1/num2<<endl;
            }
            break;
            default:
            cout<<"Invalid operation.Please enter +, -, *, or /."<<endl;       
    }
    return 0;
}