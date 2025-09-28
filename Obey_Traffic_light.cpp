#include <iostream>
using namespace std;

int main() {
    int waktu;
    cout << "Masukkan waktu dalam detik: ";
    cin >> waktu;
    int waktuAwal = 45; 
    bool warnaditemukan = false;
    while (!warnaditemukan) {
        waktuAwal += 3; //lampu kuning
        if (waktu < waktuAwal) {
            cout << "Kuning" << endl;
            warnaditemukan = true;
            break;
        }
        waktuAwal += 80; //lampu merah
        if (waktu < waktuAwal) {
            cout << "Merah" << endl;
            warnaditemukan = true;
            break;
        }
        waktuAwal += 20; //lampu hijau
        if (waktu < waktuAwal) {
            cout << "Hijau" << endl;
            warnaditemukan = true;
            break;
        }
    }
    return 0;
}

      
