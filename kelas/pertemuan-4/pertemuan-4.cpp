#include <iostream>
using namespace std;

int ubahNilai(int& a, int b){
    return a = b;
}

int main(){
    // cout << "Pointer yang menunjuk ke suatu array" << endl;
    // int a[5] = {1, 2, 3, 4, 5};
    // int (*aPtr)[5] = &a;
    // for(int i = 0; i < 5; i++){
    //     cout << "Alamat: " << aPtr << " Nilai :" << a[i] << endl;
    //     aPtr++;
    // }

    // cout << "\nPointer yang menunjuk ke arah elemen array" << endl;
    // int b[5] = {1, 2, 3, 4, 5};
    // int* bPtr = b;
    // for(int i = 0; i < 5; i++){
    //     cout << "Alamat: " << bPtr << " | Nilai: " << *bPtr << endl;
    //     bPtr++;
    // }
    int a, b;
    a = 5;
    b = 20;
    ubahNilai(a, b);
    cout << "Nilai a setelah fungsi: " << a << endl;
    return 0;
    return 0;
}