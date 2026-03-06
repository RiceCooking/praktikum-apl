// #include <iostream>
// using namespace std;

// struct date {
// int month;
// int day;
// int year;
// };
// struct mahasiswa{
// string nama;
// struct date birthday;
// };

// int main(){
// // // Contoh deklarasi
// // int bilangan[5]; // Array integer, 5 elemen
// // string nama[4]; // Array string, 4 elemen
// // float nilai[10]; // Array float, 10 elemen
// // // Deklarasi + Inisialisasi langsung
// // string buah[4] = {"Jeruk", "Mangga", "Nanas", "Apel"};
// // // Deklarasi array tanpa inisialisasi elemen array
// // int angka[3];
// // angka[0] = 10;
// // angka[1] = 19;
// // angka[2] = 30;

// // for (int i = 0; i < 3; i++){
// //     cout << angka[i] < endl;
// // }
// // const int n = 10;
// // struct mahasiswa mhs[10];

// // for(int i = 0; i < n; i++){
// //     cout << "Nama Mahasiswa\t: ";getline(cin, mhs[i].nama);
// //     cout << "Tanggal Lahir ==\nBulan\t\t: ";cin >> mhs[i].birthday.month;
// //     cout << "Hari\t\t: "; cin >> mhs[i].birthday.day;
// //     cout << "Tahun\t\t: ";cin >> mhs[i].birthday.year;
// //     cin.ignore();
// // }
// // int matriks[3][3] = {

// // {1, 2, 3}, // Baris ke-0
// // {4, 5, 6}, // Baris ke-1
// // {7, 8, 9} // Baris ke-2

// // };
// // // Mengakses elemen
// // cout << matriks[0][1] << endl;
// // cout << matriks[2][0] << endl;
// // // Menampilkan seluruh matriks dengan nested loop
// // for (int i = 0; i < 3; i ++) { // Loop baris
// // for (int j = 0; j < 3; j ++) { // Loop kolom
// // cout << matriks[i][j] <<" ";
// // }
// // cout << endl;
// // }
// // for (auto &baris : matriks) { //Iterasi setiap baris (array 1D)
// // for (auto &elemen : baris) { //Iterasi setiap elemen dalam baris
// // cout << elemen << " ";
// // }
// // cout << endl;
// // }
// struct mahasiswa mhs[1];
// mhs[0].nama = "Andi";
// mhs[0].birthday.day = 2;
// mhs[0].birthday.month = 2;
// mhs[0].birthday.year= 200;
//     return 0;
// }

#include <iostream>
using namespace std;
 
struct Alamat {
    string jalan;
    int    nomor;
    string kota;
};
 
struct Mahasiswa {
    string nama;
    int    umur;
    string jurusan;
    Alamat alamat;
};
 
#define MAX_MAHASISWA 100
int panjang = 0;
Mahasiswa mhs[MAX_MAHASISWA];
 
int main() {
    int pilihan, index;
    
    do {
        cout << "==============================" << endl;
        cout << "   Menu Manajemen Mahasiswa  " << endl;
        cout << "==============================" << endl;
        cout << "1. Tampilkan Data Mahasiswa"  << endl;
        cout << "2. Tambah Data Mahasiswa"     << endl;
        cout << "3. Ubah Data Mahasiswa"       << endl;
        cout << "4. Hapus Data Mahasiswa"      << endl;
        cout << "5. Keluar"                    << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch (pilihan) {
            
        case 1: // READ
            if (panjang == 0) {
                cout << "Belum ada data mahasiswa." << endl;
            } else {
                cout << "Daftar Mahasiswa:" << endl;
                cout << "================================" << endl;
                for (int i = 0; i < panjang; i++) {
                    cout << "Mahasiswa ke-" << i + 1 << endl;
                    cout << "Nama    : " << mhs[i].nama    << endl;
                    cout << "Umur    : " << mhs[i].umur    << endl;
                    cout << "Jurusan : " << mhs[i].jurusan << endl;
                    cout << "Alamat  : " << mhs[i].alamat.jalan
                         << " No. " << mhs[i].alamat.nomor
                         << ", "    << mhs[i].alamat.kota << endl;
                    cout << "--------------------------------" << endl;
                }
            }
            break;
            
        case 2: // CREATE
            if (panjang < MAX_MAHASISWA) {
                cin.ignore();
                cout << "Masukkan nama     : ";
                getline(cin, mhs[panjang].nama);
                
                cout << "Masukkan umur     : ";
                cin >> mhs[panjang].umur;
                
                cin.ignore();
                cout << "Masukkan jurusan  : ";
                getline(cin, mhs[panjang].jurusan);
                
                cout << "--- Alamat ---" << endl;
                cout << "Jalan : ";
                getline(cin, mhs[panjang].alamat.jalan);
                
                cout << "Nomor : ";
                cin >> mhs[panjang].alamat.nomor;
                
                cin.ignore();
                cout << "Kota  : ";
                getline(cin, mhs[panjang].alamat.kota);
                
                panjang++;
                cout << "Data berhasil ditambahkan!" << endl;
            } else {
                cout << "Kapasitas penuh!" << endl;
            }
            break;
            
        case 3: // UPDATE
            if (panjang == 0) {
                cout << "Belum ada mahasiswa untuk diubah." << endl;
            } else {
                cout << "Daftar Mahasiswa" << endl;
                cout << "==================" << endl;
                for (int i = 0; i < panjang; i++) {
                    cout << i + 1 << ". " << mhs[i].nama << endl;
                }
                
                cout << "Masukkan nomor mahasiswa yang akan diubah: ";
                cin >> index;
                
                if (index > 0 && index <= panjang) {
                    cin.ignore();
                    cout << "Masukkan nama mahasiswa baru: ";
                    getline(cin, mhs[index - 1].nama);
                    
                    cout << "Masukkan umur mahasiswa baru: ";
                    cin >> mhs[index - 1].umur;
                    
                    cin.ignore();
                    cout << "Masukkan jurusan mahasiswa baru: ";
                    getline(cin, mhs[index - 1].jurusan);
                    
                    cout << "Masukkan alamat mahasiswa baru:" << endl;
                    cout << "Jalan: ";
                    getline(cin, mhs[index - 1].alamat.jalan);
                    
                    cout << "Nomor: ";
                    cin >> mhs[index - 1].alamat.nomor;
                    
                    cin.ignore();
                    cout << "Kota: ";
                    getline(cin, mhs[index - 1].alamat.kota);
                    
                    cout << "Mahasiswa berhasil diubah" << endl;
                } else {
                    cout << "Nomor mahasiswa tidak valid" << endl;
                }
            }
            break;
            
        case 4: // DELETE
            if (panjang == 0) {
                cout << "Belum ada mahasiswa untuk dihapus." << endl;
            } else {
                cout << "Daftar Mahasiswa" << endl;
                cout << "==================" << endl;
                for (int i = 0; i < panjang; i++) {
                    cout << i + 1 << ". " << mhs[i].nama << endl;
                }
                
                cout << "Masukkan nomor mahasiswa yang akan dihapus: ";
                cin >> index;
                
                if (index > 0 && index <= panjang) {
                    for (int i = index - 1; i < panjang - 1; i++) {
                        mhs[i] = mhs[i + 1];
                    }
                    panjang--;
                    cout << "Mahasiswa berhasil dihapus" << endl;
                } else {
                    cout << "Nomor mahasiswa tidak valid" << endl;
                }
            }
            break;
            
        case 5:
            cout << "Sampai jumpa!" << endl;
            break;
            
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }
        
    } while (pilihan != 5);
    
    return 0;
}