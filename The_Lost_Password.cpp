#include <iostream>
using namespace std; 

//mesin bekerja dengan cara mengambil sebuah kata, menghilangkan semua huruf vokal, membalikkan semua huruf, kemudian memasukkan kode ascii dari huruf pertama dari kata awal di tengah tengah sandi
int main() {
    string password, sandi = "";
    cout << "Masukkan password: ";
    cin >> password;
    int len = password.length();
    for (int i = 0; i < len; i++) {
        char ch = password[i];
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u' &&
            ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U') {
            sandi = ch + sandi; // membalikkan huruf
        }
    }
    // jika sandi ganjil, ascii dimasukkan setelah huruf tengah
    int ascii = static_cast<int>(password[0]);
    int mid = sandi.length() / 2;
    if (sandi.length() % 2 == 0) {
        sandi = sandi.substr(0, mid) + to_string(ascii) + sandi.substr(mid);
    } else {
        sandi = sandi.substr(0, mid + 1) + to_string(ascii) + sandi.substr(mid + 1);
    }
    cout << "Sandi: " << sandi << endl;
    return 0;
}