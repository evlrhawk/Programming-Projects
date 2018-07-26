/**************************************
* Author: Thomas Burr 
* Sieve of Eratosthenes
* Concept: Find all the prime numbers 
* less than the given number, n.
**************************************/
#include <iostream>
#include <vector>

using namespace std;

// Prompts for number, n 
int getNumber()
{
    int number = 0;

    cout << "Input a whole number: ";
    cin >> number; 
    cout << endl;

    return number;
}

//finds all prime numbers less than n
void calcNumbers(vector<bool> &prime, int number)
{
   for (int i = 0; i < number; ++i)
   {
      prime[i] = true;
   }

   for (int i = 2; i < number; ++i)
   {
      while(prime[i] == false && i < number)
      {
         i++;
      }

      for (int j = 2; i < number; ++j)
      {
         if ((j+1) % i == 0)
         {
            prime[j + 1] = false;
         }
      }
   }
}

// Driver Method
int main()
{
    int count = 0;
    int number = getNumber();

    vector<bool> prime;

    calcNumbers(prime, number);

    cout << "The prime numbers less than " << number << " are:" << endl;

    for (int i = 2; i < number; ++i)
    {
       if(prime[i] == true)
       {
         if(count != 0)
         {
            cout << ", " << i;
         }
         else
         {
            cout << i;
         }
       }
    }
}