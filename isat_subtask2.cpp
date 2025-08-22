#include <iostream>
#include <bitset>
#include <string>
#include <limits>

using namespace std;

// Converts a non-negative decimal number to a 16-bit binary string
string decimalToBinary(unsigned int decimal) {
    if (decimal > 65535u) {
        cout << "Error: Please enter a number between 0 and 65535.\n";
        return "";
    }
    return bitset<16>(decimal).to_string();
}

// Converts a binary string to its decimal equivalent (0..65535)
int binaryToDecimal(const string& binary) {
    if (binary.empty()) {
        cout << "Error: Empty input.\n";
        return -1;
    }
    if (binary.length() > 16u) {
        cout << "Error: Binary input exceeds 16 bits.\n";
        return -1;
    }

    unsigned int value = 0;
    for (char c : binary) {
        if (c != '0' && c != '1') {
            cout << "Error: Invalid binary digit '" << c << "'.\n";
            return -1;
        }
        value = (value << 1) + (c - '0'); // shift left and add current bit
    }
    return static_cast<int>(value);
}

// Clears the input buffer after invalid input
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== Conversion Menu =====\n";
        cout << "1. Convert Decimal to Binary\n";
        cout << "2. Convert Binary to Decimal\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a numeric value.\n";
            clearInput();
            continue;
        }

        switch (choice) {
            case 1: {
                unsigned int decimal;
                cout << "Enter a decimal number (0-65535): ";
                if (!(cin >> decimal)) {
                    cout << "Invalid input. Please enter a valid integer.\n";
                    clearInput();
                    continue;
                }
                string binary = decimalToBinary(decimal);
                if (!binary.empty()) {
                    cout << "Binary representation (16-bit): " << binary << "\n";
                }
                break;
            }

            case 2: {
                string binary;
                cout << "Enter a binary number (up to 16 bits): ";
                cin >> binary;
                int decimal = binaryToDecimal(binary);
                if (decimal != -1) {
                    cout << "Decimal representation: " << decimal << "\n";
                }
                break;
            }

            case 3:
                cout << "Exiting program. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice. Please select option 1, 2, or 3.\n";
        }
    }
}
