#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan ukuran array: ";
    cin >> n;
    int arr[n];
    int arrInverted[n];
    int sumarrinverted = 0;
    cout << "Masukkan elemen array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            int num = arr[i];
            int reversedNum = 0;
            while (num != 0) {
                int digit = num % 10;
                reversedNum = reversedNum * 10 + digit;
                num /= 10;
            }
            arrInverted[i] = reversedNum;
        } else {
            arrInverted[i] = arr[i];
        }
        sumarrinverted += arrInverted[i];
    }
    cout << "Array setelah inversi: ";
    for (int i = 0; i < n; i++) {
        cout << arrInverted[i] << " ";
    }
    cout << endl << "Jumlah elemen array setelah inversi: " << sumarrinverted << endl;
    return 0;
}