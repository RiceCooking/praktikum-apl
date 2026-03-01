#include <iostream>
using namespace std;

int main(){
// Contoh deklarasi
int bilangan[5]; // Array integer, 5 elemen
string nama[4]; // Array string, 4 elemen
float nilai[10]; // Array float, 10 elemen
// Deklarasi + Inisialisasi langsung
string buah[4] = {"Jeruk", "Mangga", "Nanas", "Apel"};
// Deklarasi array tanpa inisialisasi elemen array
int angka[3];
angka[0] = 10;
angka[1] = 19;
angka[2] = 30;

for (int i = 0; i < 3; i++){
    cout << angka[i] << endl;
}

    return 0;
}