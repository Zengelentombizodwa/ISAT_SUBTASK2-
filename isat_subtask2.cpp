#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

// Function to convert decimal to binary
string decimalToBinary(int decimal) {
    return std::bitset<16>(decimal).to_string(); // Converts to 16-bit binary
}

// Function to convert binary to decimal
int binaryToDecimal(string binary) {
    int decimal = 0;
    int length = binary.length();
    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, length - 1 - i);
        }
    }
    return decimal;
}

int main() {
    int choice;
    
    // Display the menu
    cout << "Conversion Menu:\n";
    cout << "1. Decimal to Binary\n";
    cout << "2. Binary to Decimal\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    // Process user choice
    if (choice == 1) {
        int decimal;
        cout << "Enter a decimal number: ";
        cin >> decimal;
        cout << "Binary representation: " << decimalToBinary(decimal) << endl;
    } 
    else if (choice == 2) {
        string binary;
        cout << "Enter a binary number: ";
        cin >> binary;
        cout << "Decimal representation: " << binaryToDecimal(binary) << endl;
    } 
    else {
        cout << "Invalid choice.\n";
    }

    return 0;
}


 
