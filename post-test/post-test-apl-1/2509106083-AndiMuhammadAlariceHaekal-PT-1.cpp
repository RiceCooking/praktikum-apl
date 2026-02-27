#include <iostream>
using namespace std;

int main(){
    int logout = 0;
    bool menu = false;
    string nama, password;

    while(logout != 3){
        cout << "======================================" << endl;
        cout << "===         Halaman Login          ===" << endl; 
        cout << "======================================" << endl;
        cout << "Username\t: ";cin >> nama;
        cout << "Password\t: ";cin >> password;
        if(nama == "Andi" && password == "083"){
            cout << "Login berhasil" << endl;
            cout << "======================================" << endl;
            menu = true;
            break;
        }
        else{
            logout++;
            if(nama != "Andi" && password == "083"){
                cout << "Info\t\t: Username tidak valid" << endl;
            }

            else if(password != "083" && nama == "Andi"){
                cout << "Info\t\t: Password salah" << endl;
            }

            else{
                cout << "Info\t\t: Username dan Password salah" << endl;
            }
            if(logout < 3){
            cout << "Coba lagi";
            for(int i = 4; i > 0; i--){
                cout << ".";
                for(long x = 0; x < 50000000; x++);
            }
            cout << endl << "======================================" << endl << endl << endl;
            }
        }

        if(logout == 3){
            cout << "Gagal login..." << endl;
            cout << "======================================" << endl;
        }
        
    }
    cout << endl << endl;

    while(menu == true){
        string opsi;
        double nilai;
        cout << endl << "======================================" << endl;
        cout << "===         Menu Konversi          ===" << endl; 
        cout << "===                                ===" << endl;
        cout << "--------------------------------------" << endl;
        cout << "|             Jenis Opsi             |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "|1. Meter -> Kilometer dan Centimeter|" << endl;
        cout << "|2. Kilometer -> Meter dan Centimeter|" << endl;
        cout << "|3. Centimeter -> Meter dan Kilometer|" << endl;
        cout << "|4. Keluar                           |" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Pilih opsi\t\t: ";
        cin >> opsi;

        if(opsi == "1"){
            cout << "--------------------------------------" << endl;
            cout << "-----------|Konversi Meter|-----------" << endl;
            cout << "--------------------------------------" << endl;
            cout << "Masukkan nilai Meter\t: ";cin >> nilai;

            cout << "Kilometer\t\t: " << nilai / 1000 << endl;
            cout << "Centimeter\t\t: " << nilai * 100 << endl;
            cout << "--------------------------------------" << endl;

        }
        else if(opsi == "2"){
            cout << "--------------------------------------" << endl;
            cout << "---------|Konversi Kilometer|---------" << endl;
            cout << "--------------------------------------" << endl;
            cout << "Masukkan nilai Kilometer : ";cin >> nilai;

            cout << "Meter\t\t\t : " << nilai * 1000 << endl;
            cout << "Centimeter\t\t : " << nilai * 100000 << endl;
            cout << "--------------------------------------" << endl;
        }

        else if(opsi == "3"){
            cout << "--------------------------------------" << endl;
            cout << "--------|Konversi Centimeter|---------" << endl;
            cout << "--------------------------------------" << endl;
            cout << "Masukkan nilai Centimeter\t: ";cin >> nilai;

            cout << "Meter\t\t\t: " << nilai / 100 << endl;
            cout << "Kilometer\t\t: " << nilai / 100000 << endl;
            cout << "--------------------------------------" << endl;
        }

        else if(opsi == "4"){
            cout << "Keluar dari program, terima kasih telah menggunakan program" << endl;
            menu = false;
        }

        else{
            cout << "Pilihlah berdasarkan opsi" << endl;
        }

    }

    return 0;
}
