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

// Deklarasi fungsi dan prosedur
void tampilkanDaftarManga(Manga mangaList[], int jumlahmanga);
void tampilkanKeranjang(Keranjang keranjang[], int jumlahKeranjang);
void tambahKeKeranjang(Keranjang keranjang[], int &jumlahKeranjang, Manga mangaList[], int jumlahmanga);
void hapusDariKeranjang(Keranjang keranjang[], int &jumlahKeranjang);
void checkout(Keranjang keranjang[], int &jumlahKeranjang);
void tambahDiskon(int &totalHarga);     // address-of
void resetTotal(int *total);            // dereference

// Fungsi untuk menampilkan daftar manga
void tampilkanDaftarManga(Manga mangaList[], int jumlahmanga) {
    cout << "\n========================================";
    cout << "\n           DAFTAR MANGA";
    cout << "\n========================================";
    cout << "\nNo.  Judul Manga          Harga";
    cout << "\n----------------------------------------";
    for (int i = 0; i < jumlahmanga; i++) {
        cout << "\n" << i + 1 << ".   " << mangaList[i].judul;
        if (mangaList[i].judul.length() < 15) {
            cout << string(15 - mangaList[i].judul.length(), ' ');
        }
        cout << "Rp" << mangaList[i].harga;
    }
    cout << "\n========================================";
}

// Fungsi untuk menampilkan keranjang
void tampilkanKeranjang(Keranjang keranjang[], int jumlahKeranjang) {
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
            if (keranjang[i].judul.length() < 15) {
                cout << string(15 - keranjang[i].judul.length(), ' ');
            }
            cout << keranjang[i].jumlah << "      Rp" << keranjang[i].totalHarga;
        }
        cout << "\n========================================";
    }
}

// Fungsi untuk menambah manga ke keranjang
void tambahKeKeranjang(Keranjang keranjang[], int &jumlahKeranjang, Manga mangaList[], int jumlahmanga) {
    int pilihManga, Jumlahbeli;
    cout << "\n========================================";
    cout << "\n       TAMBAH KE KERANJANG";
    cout << "\n========================================";
    cout << "\nPilih manga yang ingin dibeli (nomor): ";
    cin >> pilihManga;

    if (pilihManga < 1 || pilihManga > jumlahmanga) {
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

// Fungsi untuk menghapus manga dari keranjang
void hapusDariKeranjang(Keranjang keranjang[], int &jumlahKeranjang) {
    if (jumlahKeranjang == 0) {
        cout << "\n========================================";
        cout << "\n       HAPUS DARI KERANJANG";
        cout << "\n========================================";
        cout << "\nKeranjang Anda masih kosong.";
        cout << "\n========================================";
    } else {
        tampilkanKeranjang(keranjang, jumlahKeranjang);

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

// Fungsi dengan parameter reference (address-of)
void tambahDiskon(int &totalHarga) {
    int diskon = 5000;
    totalHarga -= diskon;
}

// Fungsi dengan parameter dereference (pointer)
void resetTotal(int *total) {
    *total = 0;
}

// Prosedur checkout
void checkout(Keranjang keranjang[], int &jumlahKeranjang) {
    if (jumlahKeranjang == 0) {
        cout << "\n========================================";
        cout << "\n             CHECKOUT";
        cout << "\n========================================";
        cout << "\nKeranjang masih kosong.";
        cout << "\n========================================";
        return;
    }

    int total = 0;
    for (int i = 0; i < jumlahKeranjang; i++) {
        total += keranjang[i].totalHarga;
    }

    cout << "\nTotal belanja: Rp" << total;

    // Tambah diskon
    tambahDiskon(total);
    cout << "\nDiskon Rp5000 diterapkan!";
    cout << "\nTotal setelah diskon: Rp" << total;

    // Reset total menggunakan dereference (simulasi)
    resetTotal(&total);

    // Kosongkan keranjang
    jumlahKeranjang = 0;

    cout << "\nCheckout selesai. Terima kasih sudah belanja!";
    cout << "\n========================================";
}

// MAIN FUNCTION
int main() {
    int pilihan;
    User userakun = {"Muhammad Rafii Zaidan Sakaria", "2409106095"}; 
    string username, password;
    int percobaan = 3;

    string judulmanga[] = {"One Piece", "Naruto", "Bleach", "Attack on Titan", "Dragon Ball"};
    int hargaManga[] = {50000, 45000, 48000, 55000, 52000};
    int jumlahmanga = sizeof(judulmanga) / sizeof(judulmanga[0]);

    Manga mangaList[5];
    for (int i = 0; i < jumlahmanga; i++) {
        mangaList[i].judul = judulmanga[i];
        mangaList[i].harga = hargaManga[i];
    }

    Keranjang keranjang[10];
    int jumlahKeranjang = 0;

    while (true) {
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
                        cout << "\n========================================";
                        cout << "\n       SELAMAT DATANG PEMBELI";
                        cout << "\n========================================";
                        cout << "\n1. Lihat Daftar Manga";
                        cout << "\n2. Tambah Manga ke Keranjang";
                        cout << "\n3. Lihat Keranjang";
                        cout << "\n4. Hapus Manga dari Keranjang";
                        cout << "\n5. Checkout";
                        cout << "\n6. Logout";
                        cout << "\n----------------------------------------";
                        cout << "\nPilihan: ";
                        cin >> pilihan;
                        cin.ignore();

                        if (pilihan == 1) {
                            tampilkanDaftarManga(mangaList, jumlahmanga);
                        } else if (pilihan == 2) {
                            tambahKeKeranjang(keranjang, jumlahKeranjang, mangaList, jumlahmanga);
                        } else if (pilihan == 3) {
                            tampilkanKeranjang(keranjang, jumlahKeranjang);
                        } else if (pilihan == 4) {
                            hapusDariKeranjang(keranjang, jumlahKeranjang);
                        } else if (pilihan == 5) {
                            checkout(keranjang, jumlahKeranjang);
                        } else if (pilihan == 6) {
                            cout << "\nBERHASIL: Anda telah logout.";
                            cout << "\n========================================";
                            break;
                        } else {
                            cout << "\nERROR: Pilihan tidak valid!";
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
        } else if (pilihan == 2) {
            cout << "\n========================================";
            cout << "\n          PROGRAM SELESAI";
            cout << "\n========================================";
            return 0;
        } else {
            cout << "\nERROR: Pilihan tidak valid!";
        }
    }

    return 0;
}