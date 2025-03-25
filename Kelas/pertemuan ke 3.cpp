#include <iostream>

using namespace std;


// struct mahasiswa {
//     string nama;
//     int umur;
//     string jurusan;
//     string nim;
// }

// mahasiswa mhs[100];

// int main() {
//     mhs[0] 
// }




struct nestedmhs {
    string nama;
    string nilai [100];
};

struct nestednilai {
    int nilai;
    string matkul;
};

struct datamhs {
    nestedmhs mhs;
    nestednilai milai;
};

int main() {
    nestedmhs mhs[100];
    mhs[0].nilai[110] = "A";
    cout << mhs[0].nilai[-1] << endl;
    cout << mhs[0].nilai[0] << endl;

    // datamhs data;

}