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

    string judulManga[] = {"One Piece", "Naruto", "Bleach", "Attack on Titan", "Dragon Ball"};
    int hargaManga[] = {50000, 45000, 48000, 55000, 52000};
    int jumlahManga = sizeof(judulManga) / sizeof(judulManga[0]);

    Manga mangaList[5];
    for (int i = 0; i < jumlahManga; i++) {
        mangaList[i].judul = judulManga[i];
        mangaList[i].harga = hargaManga[i];
    }

    Keranjang keranjang[10];
    int jumlahKeranjang = 0;

    while (true) {
        // Menu Utama
        cout << "\n========================================";
        cout << "\n             MENU UTAMA";
        cout << "\n========================================";
        cout << "\n1. Login sebagai Pembeli";
        cout << "\n2. Keluar";
        cout << "\n----------------------------------------";
        cout << "\nPilihan: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {  
            while (percobaan > 0) {
                // Menu Login
                cout << "\n========================================";
                cout << "\n           LOGIN PEMBELI";
                cout << "\n========================================";
                cout << "\nUsername: ";
                getline(cin, username);
                cout << "Password: ";
                cin >> password;
                cin.ignore();

                if (username == userakun.username && password == userakun.password) {
                    while (true) {
                        // Menu Pembeli
                        cout << "\n========================================";
                        cout << "\n       SELAMAT DATANG PEMBELI";
                        cout << "\n========================================";
                        cout << "\n1. Lihat Daftar Manga";
                        cout << "\n2. Tambah Manga ke Keranjang";
                        cout << "\n3. Lihat Keranjang";
                        cout << "\n4. Hapus Manga dari Keranjang";
                        cout << "\n5. Logout";
                        cout << "\n----------------------------------------";
                        cout << "\nPilihan: ";
                        cin >> pilihan;
                        cin.ignore();

                        if (pilihan == 1) { 
                            // Daftar Manga
                            cout << "\n========================================";
                            cout << "\n           DAFTAR MANGA";
                            cout << "\n========================================";
                            cout << "\nNo.  Judul Manga          Harga";
                            cout << "\n----------------------------------------";
                            for (int i = 0; i < jumlahManga; i++) {
                                cout << "\n" << i + 1 << ".   " << mangaList[i].judul;
                                // Tambahkan spasi untuk merapikan kolom
                                if (mangaList[i].judul.length() < 15) {
                                    cout << string(15 - mangaList[i].judul.length(), ' ');
                                }
                                cout << "Rp" << mangaList[i].harga;
                            }
                            cout << "\n========================================";
                        } 
                        else if (pilihan == 2) { 
                            // Tambah ke Keranjang
                            int pilihManga, Jumlahbeli;
                            cout << "\n========================================";
                            cout << "\n       TAMBAH KE KERANJANG";
                            cout << "\n========================================";
                            cout << "\nPilih manga yang ingin dibeli (nomor): ";
                            cin >> pilihManga;

                            if (pilihManga < 1 || pilihManga > jumlahManga) {
                                cout << "\nERROR: Nomor manga tidak valid!";
                            } else {
                                cout << "Masukkan jumlah: ";
                                cin >> Jumlahbeli;

                                if (Jumlahbeli <= 0) {
                                    cout << "\nERROR: Jumlah tidak valid!";
                                } else {
                                    int ditemukan = 0;
                                    for (int i = 0; i < jumlahKeranjang; i++) {
                                        if (keranjang[i].judul == mangaList[pilihManga - 1].judul) {
                                            keranjang[i].jumlah += Jumlahbeli;
                                            keranjang[i].totalHarga += mangaList[pilihManga - 1].harga * Jumlahbeli;
                                            ditemukan = 1;
                                            break;
                                        }
                                    }

                                    if (ditemukan == 0) {
                                        keranjang[jumlahKeranjang].judul = mangaList[pilihManga - 1].judul;
                                        keranjang[jumlahKeranjang].jumlah = Jumlahbeli;
                                        keranjang[jumlahKeranjang].totalHarga = mangaList[pilihManga - 1].harga * Jumlahbeli;
                                        jumlahKeranjang++;
                                    }

                                    cout << "\nBERHASIL: Manga berhasil ditambahkan ke keranjang!";
                                }
                            }
                            cout << "\n========================================";
                        } 
                        else if (pilihan == 3) { 
                            // Lihat Keranjang
                            if (jumlahKeranjang == 0) {
                                cout << "\n========================================";
                                cout << "\n             KERANJANG";
                                cout << "\n========================================";
                                cout << "\nKeranjang Anda masih kosong.";
                                cout << "\n========================================";
                            } else {
                                cout << "\n========================================";
                                cout << "\n             KERANJANG";
                                cout << "\n========================================";
                                cout << "\nNo.  Judul Manga          Jumlah   Total Harga";
                                cout << "\n----------------------------------------";
                                for (int i = 0; i < jumlahKeranjang; i++) {
                                    cout << "\n" << i + 1 << ".   " << keranjang[i].judul;
                                    // Tambahkan spasi untuk merapikan kolom
                                    if (keranjang[i].judul.length() < 15) {
                                        cout << string(15 - keranjang[i].judul.length(), ' ');
                                    }
                                    cout << keranjang[i].jumlah << "      Rp" << keranjang[i].totalHarga;
                                }
                                cout << "\n========================================";
                            }
                        } 
                        else if (pilihan == 4) { 
                            // Hapus dari Keranjang
                            if (jumlahKeranjang == 0) {
                                cout << "\n========================================";
                                cout << "\n       HAPUS DARI KERANJANG";
                                cout << "\n========================================";
                                cout << "\nKeranjang Anda masih kosong.";
                                cout << "\n========================================";
                            } else {
                                cout << "\n========================================";
                                cout << "\n       HAPUS DARI KERANJANG";
                                cout << "\n========================================";
                                cout << "\nNo.  Judul Manga          Jumlah   Total Harga";
                                cout << "\n----------------------------------------";
                                for (int i = 0; i < jumlahKeranjang; i++) {
                                    cout << "\n" << i + 1 << ".   " << keranjang[i].judul;
                                    // Tambahkan spasi untuk merapikan kolom
                                    if (keranjang[i].judul.length() < 15) {
                                        cout << string(15 - keranjang[i].judul.length(), ' ');
                                    }
                                    cout << keranjang[i].jumlah << "      Rp" << keranjang[i].totalHarga;
                                }
                                cout << "\n========================================";
                                
                                int hapus;
                                cout << "\nPilih nomor manga yang ingin dihapus: ";
                                cin >> hapus;
                                if (hapus < 1 || hapus > jumlahKeranjang) {
                                    cout << "\nERROR: Nomor tidak valid!";
                                } else {
                                    for (int i = hapus - 1; i < jumlahKeranjang - 1; i++) {
                                        keranjang[i] = keranjang[i + 1];
                                    }
                                    jumlahKeranjang--;
                                    cout << "\nBERHASIL: Manga berhasil dihapus dari keranjang!";
                                }
                                cout << "\n========================================";
                            }
                        }
                        else if (pilihan == 5) { 
                            cout << "\nBERHASIL: Anda telah logout.";
                            cout << "\n========================================";
                            break;
                        } 
                        else {
                            cout << "\nERROR: Pilihan tidak valid!";
                            cout << "\n========================================";
                        }
                    }
                    break;
                } else {
                    percobaan--;
                    if (percobaan == 0) {
                        cout << "\n========================================";
                        cout << "\n  LOGIN GAGAL 3x! PROGRAM BERHENTI";
                        cout << "\n========================================";
                        return 0;
                    }
                    cout << "\nERROR: Login gagal! Username atau password salah.";
                    cout << "\nSisa percobaan: " << percobaan;
                    cout << "\n========================================";
                }
            }
        }
        else if (pilihan == 2) {  
            cout << "\n========================================";
            cout << "\n          PROGRAM SELESAI";
            cout << "\n========================================";
            return 0;
        }
        else {
            cout << "\nERROR: Pilihan tidak valid!";
            cout << "\n========================================";
        }
    }
    return 0;
}