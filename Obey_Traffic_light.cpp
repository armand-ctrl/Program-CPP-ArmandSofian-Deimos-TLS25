#include <iostream>
using namespace std;

// urutan lampu adalah hijau -> kuning -> merah. hijau selama 20 detik, kuning selama 3 detik, merah selama 80 detik. waktu dimulai dari detik 45, menunjukkan warna kuning hingga detik ke 47
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
      