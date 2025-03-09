#include <iostream>
#include <cstring>
using namespace std;


string username = "Muhammad Rafii Zaidan Sakaria";
string password = "2409106095";

int main() {
    string inputUser, inputPass;
    cout << "=== Login User ===\n";
    cout << "Masukkan Username : ";
    getline(cin, inputUser);
    cout << "Masukkan Password(NIM) :";
    cin >> inputPass;

    if (inputUser != username || inputPass != password) {
        cout << "Login Gagal!. Username Atau Password Salah!\n";
        return 0;
    }

int opsi;
do {
    cout << "\n== Sistem Bangun Datar Dan Bangun Ruang ==\n";
    cout << "1. Hitung luas\n";
    cout << "2. Hitung keliling\n";
    cout << "3. Hitung volume\n";
    cout << "4. Logout\n";
    cout << "Opsi : ";
    cin >> opsi;

    switch (opsi) {
        case 1: {
            int subpilihan;
            cout << "\n== Hitung Luas ==\n";
            cout << "1. Persegi\n2. Persegi Panjang\n3. Lingkaran\n4. Segitiga\n5. Kembali\nPilihan : ";
            cin >> subpilihan;
    
            switch (subpilihan) {
                case 1: {
                    float sisi;
                    cout << "Masukkan sisi : ";
                    cin >> sisi;
                    cout << "Luas Persegi : " << sisi * sisi << "\n";
                    break;
                }
                case 2: {
                    float panjang, lebar;
                    cout << "Masukkan panjang dan lebar : ";
                    cin >> panjang >> lebar;
                    cout << "Luas persegi panjang : " << panjang * lebar << "\n";
                    break;
                }
                case 3: {
                    float r;
                    cout << "Masukkan jari-jari : ";
                    cin >> r;
                    cout << "Luas Lingkaran : " << 3.14 * r * r << "\n";
                    break;
                }
                case 4: {
                    float alas, tinggi;
                    cout << "Masukkan alas dan tinggi : ";
                    cin >> alas >> tinggi;
                    cout << "Luas Segitga : " << 0.5 * alas * tinggi << "\n";
                    break;
                }
            }
            break;
        }
        case 2: {
            int subpilihan;
            cout << "\n == Hitung Keliling == \n";
            cout << "1. Persegi\n2. Persegi Panjang\n3. Lingkaran\n4. Segitiga\n5. Kembali\nPilihan : ";
            cin >> subpilihan;

            switch (subpilihan) {
                case 1: {
                    float sisi;
                    cout << "Masukkan sisi : ";
                    cin >> sisi;
                    cout << "Keliling Persegi : " << 4 * sisi << "\n";
                    break;
                }
                case 2: {
                    float panjang, lebar, tinggi;
                    cout << "Masukkan panjang, lebar, dan tinggi : ";
                    cin >> panjang >> lebar >> tinggi;
                    cout << "Volume Balok : " << 2 * (panjang + lebar) << "\n";
                    break;
                }
                case 3: {
                    float r;
                    cout << "Masukkan jari-jari : ";
                    cin >> r;
                    cout << "Keliling Lingkaran : " << 2 * 3.14 * r << "\n";
                    break;
                }
            }
            break;
        }
        case 3: {
            int subpilihan;
            cout << "\n== Hitung Volume ==\n";
            cout << "1. Kubus\n2. Balok\n3. Bola\n4. Kerucut\n5. Kembali\nPilihan : ";
            cin >> subpilihan;

            switch (subpilihan) {
                case 1: {
                    float sisi;
                    cout << "Masukkan sisi : ";
                    cin >> sisi;
                    cout << "Volume Kubus : " << sisi * sisi * sisi << "\n";
                    break;
                }
                case 2: {
                    float panjang, lebar, tinggi;
                    cout << "Masukkan panjang, lebar, dan tinggi : ";
                    cin >> panjang >> lebar >> tinggi;
                    cout << "Volume Balok: " << panjang * lebar * tinggi << "\n";
                    break; 
                }
                case 3: {
                    float r;
                    cout << "Masukkan jari-jari: ";
                    cin >> r;
                    cout << "Volume Bola: " << (4.0/3.0) * 3.14 * r * r * r << "\n";
                    break;
                }
                case 4: {
                    float r, tinggi;
                    cout << "Masukkan jari-jari dan tinggi: ";
                    cin >> r >> tinggi;
                    cout << "Volume Kerucut: " << (1.0/3.0) * 3.14 * r * r * tinggi << "\n";
                    break;
                }
            }
            break;
        }
        
    }
} while (opsi != 4);

cout << "Logout Berhasil.\n";
return 0;
}