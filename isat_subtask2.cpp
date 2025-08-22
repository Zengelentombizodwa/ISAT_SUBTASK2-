#include <iostream>
#include <bitset>
#include <cmath>
#include <limits>   // for numeric_limits
using namespace std;

// Function to convert decimal to binary (16-bit representation)
string decimalToBinary(int decimal) {
    return bitset<16>(decimal).to_string(); 
}

// Function to convert binary to decimal safely
int binaryToDecimal(const string& binary) {
    int decimal = 0;
    int length = binary.length();
    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, length - 1 - i);
        } else if (binary[i] != '0') {
            cout << "Error: Invalid binary digit '" << binary[i] << "'\n";
            return -1; // return error code
        }
    }
    return decimal;
}

// Function to clear input buffer after invalid input
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    int choice;

    while (true) {
        // Display the menu
        cout << "\n===== Conversion Menu =====\n";
        cout << "1. Decimal to Binary\n";
        cout << "2. Binary to Decimal\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) { 
            cout << "Invalid input. Please enter a number.\n";
            clearInput();
            continue;
        }

        if (choice == 1) {
            int decimal;
            cout << "Enter a decimal number: ";
            if (!(cin >> decimal)) {
                cout << "Invalid input. Please enter an integer.\n";
                clearInput();
                continue;
            }
            cout << "Binary representation: " << decimalToBinary(decimal) << endl;
        } 
        else if (choice == 2) {
            string binary;
            cout << "Enter a binary number: ";
            cin >> binary;
            int decimal = binaryToDecimal(binary);
            if (decimal != -1) {
                cout << "Decimal representation: " << decimal << endl;
            }
        } 
        else if (choice == 3) {
            cout << "Exiting program...\n";
            break;
        } 
        else {
            cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    }

    return 0;
}
