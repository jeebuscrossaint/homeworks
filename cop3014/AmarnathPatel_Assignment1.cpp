//Name: Amarnath Patel
//Date: 09/09/2023
//Assignment: #1 Coin Dispenser
//Description: This program will dispense change from a dollar amount or calculate the monetary value from coins.

#include <iostream>
#include <cstdlib> // for exit(1)

using namespace std;

// Constants for coin values
const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;
const int PENNY = 1;

// Function to dispense change from a dollar amount
void dispenseChange() {
    double dollars;
    cout << "Enter a dollar amount (e.g., $x.xx): ";
    cin >> dollars;

    // Check for negative input
    if (dollars < 0) {
        cout << "Invalid input. Dollar amount cannot be negative." << endl;
        exit(1);
    }

    // Convert dollars to cents
    int cents = static_cast<int>(dollars * 100);

    // Calculate the number of each coin
    int quarters = cents / QUARTER;
    cents %= QUARTER;
    int dimes = cents / DIME;
    cents %= DIME;
    int nickels = cents / NICKEL;
    cents %= NICKEL;
    int pennies = cents;

    // Display the results
    cout << "Value: $" << dollars << endl;
    cout << "Quarter: " << quarters << endl;
    cout << "Dime: " << dimes << endl;
    cout << "Nickel: " << nickels << endl;
    cout << "Penny: " << pennies << endl;
}

// Function to calculate monetary value from coins
void calculateValue() {
    int quarters, dimes, nickels, pennies;
    cout << "Enter the number of quarters: ";
    cin >> quarters;
    cout << "Enter the number of dimes: ";
    cin >> dimes;
    cout << "Enter the number of nickels: ";
    cin >> nickels;
    cout << "Enter the number of pennies: ";
    cin >> pennies;

    // Calculate the total value in cents
    int totalCents = (quarters * QUARTER) + (dimes * DIME) + (nickels * NICKEL) + pennies;

    // Convert cents to dollars and cents
    double dollars = totalCents / 100.0;

    // Display the result
    cout << "The coins are worth $" << dollars << endl;
}

int main() {
    int choice;

    cout << "Choose an option:" << endl;
    cout << "1. Dispense Change" << endl;
    cout << "2. Calculate Value from Coins" << endl;
    cin >> choice;

    if (choice == 1) {
        dispenseChange();
    } else if (choice == 2) {
        calculateValue();
    } else {
        cout << "Invalid choice. Please select 1 or 2." << endl;
    }

    return 0;
}
