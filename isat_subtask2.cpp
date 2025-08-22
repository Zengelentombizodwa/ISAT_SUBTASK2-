#include <iostream>
#include <bitset>
#include <string>
#include <limits>

using namespace std;

// Converts a non-negative decimal number to a 16-bit binary string
string decimalToBinary(int decimal) {
    if (decimal < 0 || decimal > 65535) {
        cout << "Error: Please enter a number between 0 and 65535.\n";
        return "";
    }
    return bitset<16>(decimal).to_string();
}

// Converts a binary string to its decimal equivalent
int binaryToDecimal(const string& binary) {
    if (binary.length() > 16) {
        cout << "Error: Binary input exceeds 16 bits.\n";
        return -1;
    }

    int decimal = 0;
    for (size_t i = 0; i < binary.length(); ++i) {
        char digit = binary[i];
        if (digit == '1') {
            decimal += 1 << (binary.length() - 1 - i);
        } else if (digit != '0') {
            cout << "Error: Invalid binary digit '" << digit << "'.\n";
            return -1;
        }
    }
    return decimal;
}

// Clears the input buffer after invalid input
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Displays the main menu and handles user interaction
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
                int decimal;
                cout << "Enter a decimal number (0–65535): ";
                if (!(cin >> decimal)) {
                    cout << "Invalid input. Please enter a valid integer.\n";
                    clearInput();
                    continue;
                }
                string binary = decimalToBinary(decimal);
                if (!binary.empty()) {
                    cout << "Binary representation: " << binary << "\n";
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
