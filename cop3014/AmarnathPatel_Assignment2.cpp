/******************************************************************************
 Amarnath Patel, Assignment 2, loan calculator, Sat 23 Sep 2023 

*******************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

double
calculateMonthlyInterestRate (double APR)
{
  return pow (1 + APR / 100, 1.0 / 12) - 1;
}
// Function above calculates the interest rate by being given an APR by the user.
double
amortizationEquation (double P, double r, int n)
{
  double M = P * (r * pow (1 + r, n)) / (pow (1 + r, n) - 1);
  return M;
}
//Function above simply calculates an amortization equation.
void
calculateMonthlyBalance (double &P, double r, double &interest,
			 double &principal)
{
  interest = P * r;
  principal = principal - interest;
  P -= principal;
}
//Function above calculates the monthly balance by taking the interest and principal.
void
updateTotalPayments (double interest, double &totalPayment,
		     double &totalInterest)
{
  totalPayment += interest;
  totalInterest += interest;
}
// Function above calculates the total payment and total interest for the user.
void
userInputs (double &P, double &APR, int &n)
{
  cout << "Loan amount:";
  cin >> P;
  cout << "Annual Percentage Rate? (APR):";
  cin >> APR;
  cout << "Loan term in months? :";
  cin >> n;
}
// Function above simply gets some crucial values and inputs for the program to work.
void
displayAmortizationSchedule (int month, double payment, double interest,
			     double principal, double balance)
{
  cout << "Month " << month << ":" << endl;
  cout << "Payment: $" << payment << endl;
  cout << "Interest Payment: $" << interest << endl;
  cout << "Principal Payment: $" << principal << endl;
  cout << "Remaining Balance: $" << balance << endl << endl;
}
// Function above prints the schedule inside of a loop in the main.

void
displaySummary (double &totalPayment, double &totalInterest)
{
  cout << "Payment Every Month: $" << totalPayment << endl;
  cout << "Total Payments: $" << totalPayment << endl;
  cout << "Total Interest: $" << totalInterest << endl;
}
// Function above prints a simple summary for each month.
int
main ()
{
  double P, APR, r, M, interest, principal, totalPayment = 0, totalInterest =
    0;
  int n;

  userInputs (P, APR, n);

  r = calculateMonthlyInterestRate (APR);
  M = amortizationEquation (P, r, n);
  principal = P;

  cout << "displayAmortizationSchedule:" << endl;
  cout << "----------------------------" << endl;

  for (int month = 1; month <= n; ++month)
    {
      calculateMonthlyBalance (P, r, interest, principal);
      updateTotalPayments (interest, totalPayment, totalInterest);
      displayAmortizationSchedule (month, M, interest, principal, P);
    }

  displaySummary (totalPayment, totalInterest);

  return 0;
}

// Simply the main function.
