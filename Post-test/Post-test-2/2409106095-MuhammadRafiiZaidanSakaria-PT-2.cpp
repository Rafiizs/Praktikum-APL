#include <iostream>

using namespace std;

struct User {
    string username;
    string password;
};

struct Manga {
    string judul;
    int harga;
};

struct Keranjang {
    string judul;
    int jumlah;
    int totalHarga;
};

int main() {
    int pilihan;
    User userakun = {"Muhammad Rafii Zaidan Sakaria", "2409106095"}; 
    int akunTerdaftar = 1; 
    string username, password;
    int percobaan = 3; 

    Manga mangaList[] = {
        {"One Piece", 50000},
        {"Naruto", 45000},
        {"Bleach", 48000},
        {"Attack on Titan", 55000},
        {"Dragon Ball", 52000}
    };
    int jumlahManga = sizeof(mangaList) / sizeof(mangaList[0]);

    Keranjang keranjang[10];
    int jumlahKeranjang = 0;

    while (true) {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Login sebagai Pembeli\n";
        cout << "2. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {  
            while (percobaan > 0) {
                cout << "\n===== LOGIN PEMBELI =====\n";
                cout << "Username: ";
                getline(cin, username);
                cout << "Password: ";
                cin >> password;
                cin.ignore();

                if (username == userakun.username && password == userakun.password) {
                    while (true) {
                        cout << "\n=== SELAMAT DATANG PEMBELI ===\n";
                        cout << "1. Lihat Daftar Manga\n";
                        cout << "2. Tambah Manga ke Keranjang\n";
                        cout << "3. Lihat Keranjang\n";
                        cout << "4. Logout\n";
                        cout << "Pilihan: ";
                        cin >> pilihan;
                        cin.ignore();

                        if (pilihan == 1) { 
                            cout << "\n===== DAFTAR MANGA =====\n";
                            for (int i = 0; i < jumlahManga; i++) {
                                cout << i + 1 << ". " << mangaList[i].judul 
                                    << " - Rp" << mangaList[i].harga << endl;
                            }
                        } 
                        else if (pilihan == 2) { 
                            int pilihManga, jumlahBeli;
                            cout << "\nPilih manga yang ingin dibeli (nomor): ";
                            cin >> pilihManga;

                            if (pilihManga < 1 || pilihManga > jumlahManga) {
                                cout << "Nomor manga tidak valid!\n";
                            } else {
                                cout << "Masukkan jumlah: ";
                                cin >> jumlahBeli;

                                if (jumlahBeli <= 0) {
                                    cout << "Jumlah tidak valid!\n";
                                } else {
                                    int ditemukan = 0;
                                    for (int i = 0; i < jumlahKeranjang; i++) {
                                        if (keranjang[i].judul == mangaList[pilihManga - 1].judul) {
                                            keranjang[i].jumlah += jumlahBeli;
                                            keranjang[i].totalHarga += mangaList[pilihManga - 1].harga * jumlahBeli;
                                            ditemukan = 1;
                                            break;
                                        }
                                    }

                                    if (ditemukan == 0) {
                                        keranjang[jumlahKeranjang].judul = mangaList[pilihManga - 1].judul;
                                        keranjang[jumlahKeranjang].jumlah = jumlahBeli;
                                        keranjang[jumlahKeranjang].totalHarga = mangaList[pilihManga - 1].harga * jumlahBeli;
                                        jumlahKeranjang++;
                                    }

                                    cout << "Manga berhasil ditambahkan ke keranjang!\n";
                                }
                            }
                        } 
                        else if (pilihan == 3) { 
                            if (jumlahKeranjang == 0) {
                                cout << "\nKeranjang Anda masih kosong.\n";
                            } else {
                                cout << "\n===== KERANJANG BELANJA =====\n";
                                for (int i = 0; i < jumlahKeranjang; i++) {
                                    cout << i + 1 << ". " << keranjang[i].judul
                                        << " - Jumlah: " << keranjang[i].jumlah
                                        << " - Total: Rp" << keranjang[i].totalHarga << endl;
                                }
                            }
                        } 
                        else if (pilihan == 4) { 
                            cout << "Anda telah logout.\n";
                            break;
                        } 
                        else {
                            cout << "Pilihan tidak valid!\n";
                        }
                    }
                    break;
                } else {
                    percobaan--;
                    if (percobaan == 0) {
                        cout << "Login gagal 3x! Program berhenti.\n";
                        return 0;
                    }
                    cout << "Login gagal! Username atau password salah. Sisa percobaan: " << percobaan << "\n";
                }
            }
        }
        else if (pilihan == 2) {  
            cout << "Program selesai.\n";
            return 0;
        }
        else {
            cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}