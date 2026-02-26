#include <iostream>
using namespace std;

int main(){
    int logout = 0;
    bool menu;
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
                cout << "Info\t\t: Nama tidak valid" << endl;
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
        cout << "======================================" << endl;
        cout << "===         Menu Konversi          ===" << endl; 
        cout << "======================================" << endl;
        cout << "--------------------------------------" << endl;
        cout << "|             Jenis Opsi             |" << endl;
        cout << "|------------------------------------|" << endl;
        cout << "|1. Meter -> Kilometer dan Centimeter|" << endl;
        cout << "|2. Kilometer -> Meter dan Centimeter|" << endl;
        cout << "|3. Centimeter -> Meter dan Kilometer|" << endl;
        cout << "|4. Keluar                           |" << endl;
        cout << "--------------------------------------" << endl;
        cin >> opsi;
        menu = false;
    }
    cout << "selesai";
    return 0;
}
