#include <iostream>
#include <iomanip> 

using namespace std;

//Function Declarations
void readInputData(int& spoolsOrdered, int& spoolsInStock, double& shippingCharges);
void display(int spoolsOrdered, int spoolsInStock, double shippingCharges);

int main()

{
   //Declaring variables
   int spoolsOrdered, spoolsInStock;
   double shippingCharges;

   //Calling the functions
   readInputData(spoolsOrdered, spoolsInStock, shippingCharges);
   display(spoolsOrdered, spoolsInStock, shippingCharges);

   return 0;
}

//This function will read all the inputs entered by the user
void readInputData(int& spoolsOrdered, int& spoolsInStock, double& shippingCharges)
{
   /* This while loop continues to execute
   * until the user enters a valid number
   */

   while (true)
   {
      cout << "Spools to be ordered" << endl;
      cin >> spoolsOrdered;
      if (spoolsOrdered < 1)
      {
         cout << "Spools order must be 1 or more" << endl;
         continue;
      }
	  else
	  {
		  break;
	  }
   }

   /* This while loop continues to execute
   * until the user enters a valid number
   */
   while (true)
   {
      cout << "Spools in stock" << endl;
      cin >> spoolsInStock;
      if (spoolsInStock < 0)
      {
         cout << "Spools in stock must be 0 or more" << endl;
         continue;
      }
	  else
	  {
		  break;
	  }
   }

   char ch;
   cout << "Special shipping and handling (y or n)" << endl;
   cin >> ch;

   if (ch == 'y')
   {
      /* This while loop continues to execute
      * until the user enters a valid number
      */

      while (true)
      {
         cout << "Shipping and handling amount" << endl;
         cin >> shippingCharges;
         if (shippingCharges < 0)
         {
            cout << "The spool shipping and handling charge must be 0.0 or more" << endl;
            continue;
         }
		 else
		 {
			 break;
		 }
      }
   }
   else
   {
      shippingCharges = 12.99;
   }
}

//This function will display the output
void display(int spoolsOrdered, int spoolsInStock, double shippingCharges)
{
   //Setting the precision to two decimal places
   std::cout << std::setprecision(2) << std::fixed;

   int spoolsReadyToShip; // Calculate stock to ship based on stock and order.
   if (spoolsInStock > spoolsOrdered)
   {
	   spoolsReadyToShip = spoolsOrdered;
   }
   else
   {
	   spoolsReadyToShip = spoolsInStock;
   }

   cout << "Spools ready to ship: " << spoolsReadyToShip << endl;

   if ((spoolsOrdered - spoolsInStock) > 0) // Check if order is back ordered.
   {
	   cout << "Spools on back-order: " << spoolsOrdered - spoolsInStock << endl;
   }
   else
   {
	   cout << "Spools on back-order: 0" << endl;
   }

   int price = 104;

   double subtotal = spoolsReadyToShip * price;
   cout << "Subtotal ready to ship: $" << setw(10) << subtotal << endl;
   cout << "Shipping and handling:  $" << setw(10) << spoolsReadyToShip * shippingCharges << endl;

   double total = (spoolsReadyToShip * price) + (spoolsReadyToShip * shippingCharges);
   cout << "Total shipping charges: $" << setw(10) << total << endl;

}