//// #include <<iostream>
//// using namespace std;

//// //// 'kadarGula' punya nilai default "Normal"
//// //// parameter default wajib di taruh paling kanan!
//// void pesankopi(string menu = "kopi susu", string kadargula = "Normal") {
//// cout <<<< "Pesanan: " <<<< menu <<<< " | Gula: " <<<< kadargula <<<< endl;
//// }

//// int main() {
//// //// Kasus 1: pengguna mengirim 1 parameter
//// pesankopi("Kopi Susu");

//// //// Kasus 2: pengguna mengirim 2 parameter dan menggantikan
//// ////parameter default dari prosedur
//// pesankopi(menu , "Less Sugar");

//// return 0;

//// }

#include <iostream>
using namespace std;
// Fungsi menjumlahkan bilangan bulat
int tambah(int a, int b) {
return a + b;
}
// Fungsi 2 menjumlahkan bilangan desimal
double tambah(double a, double b) {
return a + b;
}
int main() {
cout << "Hasil Int : " << tambah(5, 6) << endl;
cout << "Hasil Double : " << tambah(5.5, 6.6) << endl;
return 0;
}