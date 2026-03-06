#include <iostream>
using namespace std;

typedef struct 
{
    string judulLagu;
    string artis;
    string genre;
    int tahun;
} Musik;

typedef struct {
    string judul;
    int jumlahlagu = 0;
    Musik lagu[50];
} Playlist;

struct User{
    string username;
    string password;
    int jumlahPlaylist = 0; 
    Playlist musiklist[50];
};

User pengguna[50];
int jumlahuser = 0;

int main(){
    pengguna[jumlahuser].username = "Andi";
    pengguna[jumlahuser].password = "083";
    jumlahuser++;
    while(true) {
        bool login = true;
        bool menu = false;
        int userindex = -1; 
        int bataslogin = 0; 

        while(login == true){
            
            int opsi;
            string username, password;
            cout << endl << endl << "=========================================" << endl;
            cout << "====          HALAMAN MASUK          ====" << endl;
            cout << "=========================================" << endl;
            cout << "1. Register" << endl;
            cout << "2. Login" << endl;
            cout << "3. Keluar" << endl;
            cout << "Pilihlah opsi\t: ";cin >> opsi;

            if(cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Info\t\t: Input harus angka" << endl;
            }
            else if(opsi == 1){
                if(jumlahuser >= 50){
                    cout << "Info\t\t: Kapasitas user sudah penuh" << endl;
                }
                else {
                    cout << "-----------------------------------------" << endl;
                    cout << "=               REGISTER                =" << endl;
                    cout << "-----------------------------------------" << endl;
                    cout << "Username\t: ";cin >> username;
                    bool tersedia = false; 
                    
                    for(int i = 0; i < jumlahuser; i++){
                        if(pengguna[i].username == username){
                            cout << "Info\t\t: Username tidak tersedia" << endl;
                            tersedia = true; 
                            break;
                        }
                    }
                    
                    if(tersedia == false){
                        pengguna[jumlahuser].username = username;
                        cout << "Password\t: ";cin >> password;
                        pengguna[jumlahuser].password = password;
                        jumlahuser++; 
                        cout << "Info\t\t: Akun berhasil dibuat" << endl;
                    }
                }
            }
            else if(opsi == 2){
                cout << "-----------------------------------------" << endl;
                cout << "=                LOGIN                  =" << endl;
                cout << "-----------------------------------------" << endl;
                while(true){
                    cout << "Username\t: ";cin >> username; 
                    cout << "Password\t: ";cin >> password;  
                    bool logvalid = false; 

                    for(int i = 0; i < jumlahuser; i++){
                        if(pengguna[i].username == username && pengguna[i].password == password){
                            cout << "Info\t\t: Login berhasil" << endl;
                            login = false;
                            menu = true;
                            userindex = i; 
                            logvalid = true; 
                            bataslogin = 0;
                            break;
                        }
                    }
                    if(logvalid == true){
                        break;
                    }
                    else if(logvalid == false){
                        bataslogin++;
                        if(bataslogin < 3){
                            cout << "Info\t\t: Username atau Password salah" << endl << endl;
                        }
                        else if(bataslogin == 3){
                            cout << "Info\t\t: Gagal login 3 kali, keluar dari program" << endl << endl;
                            return 0;
                        }
                    }
                }
            }
            else if(opsi == 3){
                cout << "Info\t\t: Keluar dari program" << endl;
                return 0;
            }
            else{
                cout << "Info\t\t: Pilihlah berdasarkan opsi yang valid" << endl;
            }
        }

        while(menu == true){
            int opsi;
            cout << endl << endl << "=========================================" << endl;
            cout << "====          HALAMAN UTAMA          ====" << endl;
            cout << "=========================================" << endl;
            cout << "1. Buat Playlist" << endl;
            cout << "2. Lihat Playlist" << endl;
            cout << "3. Ubah Playlist" << endl;
            cout << "4. Hapus Playlist" << endl;
            cout << "5. Halaman Masuk" << endl;
            cout << "=========================================" << endl;
            cout << "Pilih opsi\t: "; cin >> opsi;
            
            if(cin.fail()){
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Info\t\t: Input harus angka" << endl;
                continue;
            }

            if(opsi == 1){
                int playlist = pengguna[userindex].jumlahPlaylist; 
                if(playlist >= 50){
                    cout << "Info\t\t: Kapasitas Playlist sudah penuh" << endl;
                }
                else{
                    cout << "-----------------------------------------" << endl;
                    cout << "=            BUAT PLAYLIST              =" << endl;
                    cout << "-----------------------------------------" << endl;
                    cout << "Nama Playlist\t: "; 
                    cin.ignore();
                    getline(cin, pengguna[userindex].musiklist[playlist].judul);
                    
                    int jumlahlagu;
                    bool jumlahvalid = false;
                    do{
                        cout << "Jumlah lagu\t: ";
                        cin >> jumlahlagu;

                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Info\t\t: Input harus berupa angka" << endl;
                        } 
                        else if(jumlahlagu <= 0 || jumlahlagu > 50){
                            cout << "Info\t\t: Jumlah lagu hanya dari rentang 1 sampai 50"<< endl;
                        } 
                        else{
                            jumlahvalid = true;
                        }
                    }while(jumlahvalid == false);

                    for(int i = 0; i < jumlahlagu; i++){
                        cout << "Lagu ke-" << i + 1 << endl;   
                        cout << "Judul lagu\t: ";
                        cin.ignore();
                        getline(cin, pengguna[userindex].musiklist[playlist].lagu[i].judulLagu);
                        
                        cout << "Artis\t\t: ";
                        getline(cin, pengguna[userindex].musiklist[playlist].lagu[i].artis);
                        
                        string Genre;
                        bool genrevalid = false;
                        do{
                            cout << "Genre (klasik/pop/rock/jazz/hip hop): ";
                            getline(cin, Genre);
                            
                            if(Genre == "klasik" || Genre == "pop" || Genre == "rock" || Genre == "jazz" || Genre == "hip hop"){
                                genrevalid = true; 
                            }
                            else{
                                cout << "Info\t: Genre tidak valid" << endl;
                            }
                        }while (genrevalid == false);
                        pengguna[userindex].musiklist[playlist].lagu[i].genre = Genre;

                        int Tahun;
                        bool tahunvalid = false;
                        do{
                            cout << "Tahun (1900 - 2026): ";
                            cin >> Tahun;

                            if(cin.fail()){
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cout << "Info\t\t: Input tahun harus berupa angka" << endl;
                            }
                            else if (Tahun < 1900 || Tahun > 2026) {
                                cout << "Info\t\t: Tahun hanya dari rentang 1900 hingga 2026" << '\n';
                            }
                            else {
                                tahunvalid = true;
                            }
                        }while(tahunvalid == false);
                        pengguna[userindex].musiklist[playlist].lagu[i].tahun = Tahun;
                    }

                    pengguna[userindex].musiklist[playlist].jumlahlagu = jumlahlagu;
                    pengguna[userindex].jumlahPlaylist++; 
                    cout << "Info\t\t: Playlist berhasil dibuat" << endl;
                }
            }
            else if(opsi == 2){
                int playlist = pengguna[userindex].jumlahPlaylist;
                
                if(playlist == 0){
                    cout << "Info\t\t: Anda belum memiliki Playlist" << endl;
                }
                else{
                    cout << "-----------------------------------------" << endl;
                    cout << "=            DAFTAR PLAYLIST            =" << endl;
                    cout << "-----------------------------------------" << endl;
                    for(int i = 0; i < playlist; i++){
                        cout << "=========================================" << endl;
                        cout << "Nama Playlist : " << pengguna[userindex].musiklist[i].judul << endl;
                        cout << "Jumlah Lagu   : " << pengguna[userindex].musiklist[i].jumlahlagu << " Lagu" << endl;
                        cout << "=========================================" << endl;
                        for(int j = 0; j < pengguna[userindex].musiklist[i].jumlahlagu; j++){
                            cout << "Lagu ke-" << j + 1 << endl;
                            cout << "Judul   : " << pengguna[userindex].musiklist[i].lagu[j].judulLagu << endl;
                            cout << "Artis   : " << pengguna[userindex].musiklist[i].lagu[j].artis << endl;
                            cout << "Genre   : " << pengguna[userindex].musiklist[i].lagu[j].genre << endl;
                            cout << "Tahun   : " << pengguna[userindex].musiklist[i].lagu[j].tahun << endl;
                            cout << "-----------------------------------------" << endl;
                        }
                    }
                }
            }
            else if(opsi == 3){
                int totalPlaylist = pengguna[userindex].jumlahPlaylist;
                if(totalPlaylist == 0){
                    cout << "Info\t\t: Anda belum memiliki Playlist" << endl;
                }
                else{
                    cout << "-----------------------------------------" << endl;
                    cout << "=            UBAH PLAYLIST              =" << endl;
                    cout << "-----------------------------------------" << endl;
                    cout << "Daftar Playlist: " << endl;

                    for(int i = 0; i < totalPlaylist; i++){
                        cout << i + 1 << ". " << pengguna[userindex].musiklist[i].judul << endl;
                    }

                    int pilihPlaylist;
                    bool validPlaylist = false;
                    do{
                        cout << "Pilih nomor playlist yang ingin diubah (1 - " << totalPlaylist << "): ";
                        cin >> pilihPlaylist;
                        
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Info\t\t: Input harus berupa angka" << endl;
                        }
                        else if(pilihPlaylist < 1 || pilihPlaylist > totalPlaylist){
                            cout << "Info\t\t: Nomor playlist tidak ditemukan" << endl;
                        }
                        else{
                            validPlaylist = true;
                        }
                    }while (validPlaylist == false);
                    int indexP = pilihPlaylist - 1;
                    
                    cout << "---|            Opsi Ubah            |---"  << endl;
                    cout << "1. Nama Playlist" << endl;
                    cout << "2. Data Lagu" << endl;
                    
                    int Opsi;
                    bool opsivalid = false;
                    do{
                        cout << "Pilih opsi (1/2): ";
                        cin >> Opsi;
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Info\t\t: Input harus berupa angka" << endl;
                        }
                        else if(Opsi < 1 || Opsi > 2){
                            cout << "Info\t\t: Pilihan hanya 1 atau 2" << endl;
                        }
                        else{
                            opsivalid = true;
                        }
                    }while (opsivalid == false);

                    if(Opsi == 1){
                        cout << "Nama Playlist Baru\t: ";
                        cin.ignore();
                        getline(cin, pengguna[userindex].musiklist[indexP].judul);
                        cout << "Info\t\t: Judul Playlist berhasil diubah" << endl;
                        
                    }
                    else if(Opsi == 2){
                        int jumlahlagu = pengguna[userindex].musiklist[indexP].jumlahlagu;
                        
                        if(jumlahlagu == 0){
                            cout << "Info\t\t: Playlist belum ada lagu" << endl;
                        }
                        else{
                            cout << "Daftar Lagu" << endl;
                            for (int j = 0; j < jumlahlagu; j++) {
                                cout << j + 1 << ". " << pengguna[userindex].musiklist[indexP].lagu[j].judulLagu << " - " << pengguna[userindex].musiklist[indexP].lagu[j].artis << endl;
                            }
                            
                            int pilihLagu;
                            bool validLagu = false;
                            do{
                                cout << "Pilih nomor lagu yang ingin diubah (1 - " << jumlahlagu << "): ";
                                cin >> pilihLagu;
                                
                                if(cin.fail()){
                                    cin.clear();
                                    cin.ignore(1000, '\n');
                                    cout << "Info\t\t: Input harus berupa angka" << endl;
                                }
                                else if(pilihLagu < 1 || pilihLagu > jumlahlagu){
                                    cout << "Info\t\t: Nomor lagu tidak ditemukan" << endl;
                                }
                                else{
                                    validLagu = true;
                                }
                            }while (validLagu == false);
                            int indexL = pilihLagu - 1;
                            
                            cout << "--- Data Lagu Baru ---" << endl;
                            cout << "Judul lagu\t: ";
                            cin.ignore();
                            getline(cin, pengguna[userindex].musiklist[indexP].lagu[indexL].judulLagu);

                            cout << "Artis\t\t: ";
                            getline(cin, pengguna[userindex].musiklist[indexP].lagu[indexL].artis);
                            
                            string GenreBaru;
                            bool genrevalid = false;
                            do{
                                cout << "Genre (klasik/pop/rock/jazz/hip hop): ";
                                getline(cin, GenreBaru);
                                
                                if(GenreBaru == "klasik" || GenreBaru == "pop" || GenreBaru == "rock" || GenreBaru == "jazz" || GenreBaru == "hip hop"){
                                    genrevalid = true;
                                }
                                else{
                                    cout << "Info\t: Genre tidak valid" << endl;
                                }
                            }while (genrevalid == false);
                            pengguna[userindex].musiklist[indexP].lagu[indexL].genre = GenreBaru;

                            int TahunBaru;
                            bool tahunvalid = false;
                            do{
                                cout << "Tahun (1900 - 2026): ";
                                cin >> TahunBaru;

                                if(cin.fail()){
                                    cin.clear();
                                    cin.ignore(1000, '\n');
                                    cout << "Info\t\t: Input tahun harus berupa angka" << endl;
                                }
                                else if(TahunBaru < 1900 || TahunBaru > 2026){
                                    cout << "Info\t\t: Tahun hanya dari rentang 1900 hingga 2026" << '\n';
                                }
                                else{
                                    tahunvalid = true;
                                }
                            }while (tahunvalid == false);
                            pengguna[userindex].musiklist[indexP].lagu[indexL].tahun = TahunBaru;
                            cout << "Info\t\t: Data lagu berhasil diubah" << endl;
                        }
                    }
                }
            }
            else if(opsi == 4){
                int totalPlaylist = pengguna[userindex].jumlahPlaylist;
                
                if(totalPlaylist == 0){
                    cout << "Info\t\t: Anda belum memiliki Playlist" << endl;
                } 
                else{
                    cout << "-----------------------------------------" << endl;
                    cout << "=             HAPUS PLAYLIST            =" << endl;
                    cout << "-----------------------------------------" << endl;
                    cout << "Daftar Playlist:" << endl;

                    for(int i = 0; i < totalPlaylist; i++){
                        cout << i + 1 << ". " << pengguna[userindex].musiklist[i].judul << endl;
                    }

                    int pilihPlaylist;
                    bool validPlaylist = false;
                    do{
                        cout << "Pilih nomor playlist yang ingin diproses (1 - " << totalPlaylist << "): ";
                        cin >> pilihPlaylist;
                        
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Info\t\t: Input harus berupa angka" << endl;
                        } 
                        else if(pilihPlaylist < 1 || pilihPlaylist > totalPlaylist){
                            cout << "Info\t\t: Nomor playlist tidak ditemukan" << endl;
                        } 
                        else{
                            validPlaylist = true;
                        }
                    }while (validPlaylist == false);
                    
                    int indexP = pilihPlaylist - 1;
                    cout << "---|            Opsi Hapus           |---"  << endl;
                    cout << "1. Hapus Playlist" << endl;
                    cout << "2. Hapus Lagu dalam Playlist" << endl;
                    
                    int Opsi;
                    bool opsivalid = false;
                    do{
                        cout << "Pilih opsi (1/2): ";
                        cin >> Opsi;
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Info\t\t: Input harus berupa angka" << endl;
                        } 
                        else if(Opsi < 1 || Opsi > 2){
                            cout << "Info\t\t: Pilihan hanya 1 atau 2" << endl;
                        } 
                        else{
                            opsivalid = true;
                        }
                    }while(opsivalid == false);

                    if(Opsi == 1){
                        for(int i = indexP; i < totalPlaylist - 1; i++){
                            pengguna[userindex].musiklist[i] = pengguna[userindex].musiklist[i + 1];
                        }
                        pengguna[userindex].jumlahPlaylist--;
                        cout << "Info\t\t: Playlist berhasil dihapus" << endl;
                    } 
                    else if(Opsi == 2){
                        int jumlahlagu = pengguna[userindex].musiklist[indexP].jumlahlagu;
                        
                        if(jumlahlagu == 0){
                            cout << "Info\t\t: Playlist tidak memiliki lagu" << endl;
                        } 
                        else{
                            cout << endl << "Daftar Lagu di '" << pengguna[userindex].musiklist[indexP].judul << "':" << endl;
                            for(int j = 0; j < jumlahlagu; j++){
                                cout << j + 1 << ". " << pengguna[userindex].musiklist[indexP].lagu[j].judulLagu << " - " << pengguna[userindex].musiklist[indexP].lagu[j].artis << endl;
                            }

                            int pilihLagu;
                            bool validLagu = false;
                            do{
                                cout << "Pilih nomor lagu yang ingin dihapus (1 - " << jumlahlagu << "): ";
                                cin >> pilihLagu;
                                
                                if (cin.fail()) {
                                    cin.clear();
                                    cin.ignore(1000, '\n');
                                    cout << "Info\t\t: Input harus berupa angka" << endl;
                                } 
                                else if(pilihLagu < 1 || pilihLagu > jumlahlagu){
                                    cout << "Info\t\t: Nomor lagu tidak ditemukan" << endl;
                                } 
                                else{
                                    validLagu = true;
                                }
                            }while (validLagu == false);
                            
                            int indexL = pilihLagu - 1;
                            for(int k = indexL; k < jumlahlagu - 1; k++){
                                pengguna[userindex].musiklist[indexP].lagu[k] = pengguna[userindex].musiklist[indexP].lagu[k + 1];
                            }
                            pengguna[userindex].musiklist[indexP].jumlahlagu--;
                            cout << "Info\t\t: Lagu berhasil dihapus" << endl;
                        }
                    }
                }
            }
            else if(opsi == 5){
                cout << "Info\t\t: Kembali kehalaman masuk" << endl;
                menu = false; 
            } 
            else{
                cout << "Info\t\t: Pilihan tidak valid" << endl;
            }
        }
    }
    return 0;
}