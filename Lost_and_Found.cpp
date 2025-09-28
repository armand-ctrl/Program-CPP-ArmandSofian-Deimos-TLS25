#include <iostream>
using namespace std;

int main() {
    string input, output, result = "";
    cout << "Masukkan Password: ";
    cin >> input;
    int len = input.length();
    for (int i = 0; i < len; i++) {
        char ch = input[i];
        if (!isdigit(ch)) {
            output += ch; 
        }
    }
    for (int i = 0; i < output.length(); i++) {
        result += output[output.length() - 1- i];
    }
    cout << "sebagian kata dari sandi: " << result<<endl;
    return 0;  
}