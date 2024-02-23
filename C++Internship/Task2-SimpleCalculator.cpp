// Task2 C++ Internship
// Simple Calculator
#include <iostream>
using namespace std;
bool CheckInput(double num)
{
  return cin.fail(); // cin.fail() returns true if the last cin command failed, and false otherwise10
}
int main()
{
  double a, b;
  char choice;
  char oper; // Operator
  cout << "Simple Calculator!" << endl;
  do
  {
    cout<< "Enter 1st Number:";
    cin >> a;
    if (CheckInput(a))
    {
      cout << "Invalid input for the first number." << endl;
      return 1;
    }

    cout << "Enter 2nd Number:";
    cin >> b;
    if (CheckInput(b))
    {
      cout << "Invalid input for the second number." << endl;
      return 1;
    }

    cout << "Choose an operator(+,-,*,%,/):";
    cin >> oper;
    switch (oper)
    {
    case '+':
      cout << "Sum=" << a + b << endl;
      break;
    case '-':
      cout << "Difference=" << a - b << endl;
      break;
    case '*':
      cout << "Product=" << a * b << endl;
      break;
    case '/':
      if (b != 0)
      {
        cout << "Quotient=" << a / b << endl;
      }
      else // Handling Error
      {
        cout << "Error:Division by Zero!" << endl;
        return 1;
      }
      break;
    case '%':
      if (b != 0)
      {
        cout << "Remainder=" << (int)a % (int)b << endl; // Since modulus operator works with integer data type
      }
      else // Handling Error
      {
        cout << "Error: Modulus by zero!" << endl;
        return 1;
      }

      break;
    default: // Output if user inputs any other character
      cout << "Invalid operator. Please use +, -,%, * or /." << endl;
    }
    cout << "Do you want to perform another calculation? (Y/N): ";
    cin >> choice;
    

  }while(choice == 'Y' || choice == 'y');


  return 0;
}
