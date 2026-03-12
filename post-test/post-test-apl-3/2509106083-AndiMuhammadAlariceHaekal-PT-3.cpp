#include <iostream>
using namespace std;

typedef struct {
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

struct User {
    string username;
    string password;
    int jumlahPlaylist = 0; 
    Playlist musiklist[50];
};

User pengguna[50];
int jumlahuser = 0;

void error(int cek) {
    if (cek == 1) {
        cout << "Info\t\t: Input harus angka" << endl;
    }
    else {
        cout << "Info\t\t: Terjadi kesalahan input" << endl;
    }
}

void error(string pesan) {
    cout << "Info\t\t: Input harus " << pesan << endl;
}

void Daftarlagu(Playlist &p, int indexLagu) {
    if(indexLagu == p.jumlahlagu){
        return; 
    }
    cout << "Lagu ke-" << indexLagu + 1 << endl;
    cout << "Judul\t: " << p.lagu[indexLagu].judulLagu << endl;
    cout << "Artis\t: " << p.lagu[indexLagu].artis << endl;
    cout << "Genre\t: " << p.lagu[indexLagu].genre << endl;
    cout << "Tahun\t: " << p.lagu[indexLagu].tahun << endl;
    cout << "-----------------------------------------" << endl;
    Daftarlagu(p, indexLagu + 1);
}

bool usntersedia(User pengguna[], int jumlahuser, string targetUsername) {
    for(int i = 0; i < jumlahuser; i++){
        if(pengguna[i].username == targetUsername) {
            return false; 
        }
    }
    return true; 
}

bool validasigenre(string genre) {
    if(genre == "klasik" || genre == "pop" || genre == "rock" || genre == "jazz" || genre == "hip hop"){
        return true;
    }
    return false;
}

void Register(User pengguna[], int &jumlahuser) {
    string username, password;
    if(jumlahuser >= 50){
        cout << "Info\t\t: Kapasitas user sudah penuh" << endl;
        return;
    }
    cout << "-----------------------------------------" << endl;
    cout << "=                REGISTER               =" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Username\t: "; cin >> username;
    
    if(usntersedia(pengguna, jumlahuser, username) == false){
        cout << "Info\t\t: Username tidak tersedia" << endl;
    }
    else {
        pengguna[jumlahuser].username = username;
        cout << "Password\t: "; cin >> password;
        pengguna[jumlahuser].password = password;
        jumlahuser++; 
        cout << "Info\t\t: Akun berhasil dibuat" << endl;
    }
}

int Login(User pengguna[], int jumlahuser, int &userindex, int &bataslogin) {
    string username, password;
    cout << "-----------------------------------------" << endl;
    cout << "=                 LOGIN                 =" << endl;
    cout << "-----------------------------------------" << endl;
    while(true){
        cout << "Username\t: "; cin >> username; 
        cout << "Password\t: "; cin >> password;  
        bool logvalid = false; 

        for(int i = 0; i < jumlahuser; i++){
            if(pengguna[i].username == username && pengguna[i].password == password){
                cout << "Info\t\t: Login berhasil" << endl;
                userindex = i; 
                logvalid = true; 
                bataslogin = 0;
                return 1; 
            }
        }
        if(logvalid == false){
            bataslogin++;
            if(bataslogin < 3){
                cout << "Info\t\t: Username atau Password salah" << endl << endl;
            }
            else if(bataslogin == 3){
                cout << "Info\t\t: Gagal login 3 kali, keluar dari program" << endl << endl;
                return -1; 
            }
        }
    }
}

void Datalagu(Musik &laguBaru) {
    cout << "Judul lagu\t: ";
    cin.ignore();
    getline(cin, laguBaru.judulLagu);
    
    cout << "Artis\t\t: ";
    getline(cin, laguBaru.artis);
    
    string Genre;
    bool genrevalid = false;
    do{
        cout << "Genre (klasik/pop/rock/jazz/hip hop): ";
        getline(cin, Genre);
        
        if(validasigenre(Genre) == true){
            genrevalid = true; 
        }
        else{
            error("klasik, pop, rock, jazz, atau hip hop"); 
        }
    }while (genrevalid == false);
    laguBaru.genre = Genre;

    int Tahun;
    bool tahunvalid = false;
    do{
        cout << "Tahun (1900 - 2026): ";
        cin >> Tahun;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            error(1);
        }
        else if (Tahun < 1900 || Tahun > 2026) {
            cout << "Info\t\t: Tahun hanya dari rentang 1900 hingga 2026" << '\n';
        }
        else {
            tahunvalid = true;
        }
    }while(tahunvalid == false);
    laguBaru.tahun = Tahun;
}

void buatPlaylist(User &u) {
    int playlist = u.jumlahPlaylist; 
    if(playlist >= 50){
        cout << "Info\t\t: Kapasitas Playlist sudah penuh" << endl;
        return;
    }

    cout << "-----------------------------------------" << endl;
    cout << "=            BUAT PLAYLIST              =" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Nama Playlist\t: "; 
    cin.ignore();
    getline(cin, u.musiklist[playlist].judul);
    
    int jumlahlagu;
    bool jumlahvalid = false;
    do{
        cout << "Jumlah lagu\t: ";
        cin >> jumlahlagu;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            error(1);
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
            Datalagu(u.musiklist[playlist].lagu[i]);
        }

        u.musiklist[playlist].jumlahlagu = jumlahlagu;
        u.jumlahPlaylist++; 
        cout << "Info\t\t: Playlist berhasil dibuat" << endl;
}

void lihatPlaylist(User &u) {
    int playlist = u.jumlahPlaylist;
    
    if(playlist == 0){
        cout << "Info\t\t: Anda belum memiliki Playlist" << endl;
        return;
    }
    
    cout << "-----------------------------------------" << endl;
    cout << "=            DAFTAR PLAYLIST            =" << endl;
    cout << "-----------------------------------------" << endl;
    for(int i = 0; i < playlist; i++){
        cout << "=========================================" << endl;
        cout << "Nama Playlist : " << u.musiklist[i].judul << endl;
        cout << "Jumlah Lagu   : " << u.musiklist[i].jumlahlagu << " Lagu" << endl;
        cout << "=========================================" << endl;
        
        Daftarlagu(u.musiklist[i], 0);
    }
}

void ubahPlaylist(User &u) {
    int totalPlaylist = u.jumlahPlaylist;
    if(totalPlaylist == 0){
        cout << "Info\t\t: Anda belum memiliki Playlist" << endl;
        return;
    }

    cout << "-----------------------------------------" << endl;
    cout << "=            UBAH PLAYLIST              =" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Daftar Playlist: " << endl;

    for(int i = 0; i < totalPlaylist; i++){
        cout << i + 1 << ". " << u.musiklist[i].judul << endl;
    }

    int pilihPlaylist;
    bool validPlaylist = false;
    do{
        cout << "Pilih nomor playlist yang ingin diubah (1 - " << totalPlaylist << "): ";
        cin >> pilihPlaylist;
        
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            error(1); 
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
            error(1);
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
        getline(cin, u.musiklist[indexP].judul);
        cout << "Info\t\t: Judul Playlist berhasil diubah" << endl;
        
    }
    else if(Opsi == 2){
        int jumlahlagu = u.musiklist[indexP].jumlahlagu;
        
        if(jumlahlagu == 0){
            cout << "Info\t\t: Playlist belum ada lagu" << endl;
        }
        else{
            cout << "Daftar Lagu" << endl;
            for (int j = 0; j < jumlahlagu; j++) {
                cout << j + 1 << ". " << u.musiklist[indexP].lagu[j].judulLagu << " - " << u.musiklist[indexP].lagu[j].artis << endl;
            }
            
            int pilihLagu;
            bool validLagu = false;
            do{
                cout << "Pilih nomor lagu yang ingin diubah (1 - " << jumlahlagu << "): ";
                cin >> pilihLagu;
                
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    error(1);
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
            Datalagu(u.musiklist[indexP].lagu[indexL]);
            
            cout << "Info\t\t: Data lagu berhasil diubah" << endl;
        }
    }
}

void hapusPlaylist(User &u) {
    int totalPlaylist = u.jumlahPlaylist;
    
    if(totalPlaylist == 0){
        cout << "Info\t\t: Anda belum memiliki Playlist" << endl;
        return;
    }

    cout << "-----------------------------------------" << endl;
    cout << "=             HAPUS PLAYLIST            =" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Daftar Playlist:" << endl;

    for(int i = 0; i < totalPlaylist; i++){
        cout << i + 1 << ". " << u.musiklist[i].judul << endl;
    }

    int pilihPlaylist;
    bool validPlaylist = false;
    do{
        cout << "Pilih nomor playlist yang ingin diproses (1 - " << totalPlaylist << "): ";
        cin >> pilihPlaylist;
        
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            error(1);
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
            error(1);
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
            u.musiklist[i] = u.musiklist[i + 1];
        }
        u.jumlahPlaylist--;
        cout << "Info\t\t: Playlist berhasil dihapus" << endl;
    } 
    else if(Opsi == 2){
        int jumlahlagu = u.musiklist[indexP].jumlahlagu;
        
        if(jumlahlagu == 0){
            cout << "Info\t\t: Playlist tidak memiliki lagu" << endl;
        } 
        else{
            cout << endl << "Daftar Lagu di '" << u.musiklist[indexP].judul << "':" << endl;
            for(int j = 0; j < jumlahlagu; j++){
                cout << j + 1 << ". " << u.musiklist[indexP].lagu[j].judulLagu << " - " << u.musiklist[indexP].lagu[j].artis << endl;
            }

            int pilihLagu;
            bool validLagu = false;
            do{
                cout << "Pilih nomor lagu yang ingin dihapus (1 - " << jumlahlagu << "): ";
                cin >> pilihLagu;
                
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    error(1);
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
                u.musiklist[indexP].lagu[k] = u.musiklist[indexP].lagu[k + 1];
            }
            u.musiklist[indexP].jumlahlagu--;
            cout << "Info\t\t: Lagu berhasil dihapus" << endl;
        }
    }
}

bool halamanMasuk(int &userindex) {
    int bataslogin = 0; 
    while(true){
        int opsi;
        cout << endl << endl << "=========================================" << endl;
        cout << "====          HALAMAN MASUK          ====" << endl;
        cout << "=========================================" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihlah opsi\t: "; cin >> opsi;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            error(1);
        }
        else if(opsi == 1){
            Register(pengguna, jumlahuser);
        }
        else if(opsi == 2){
            int loginStatus = Login(pengguna, jumlahuser, userindex, bataslogin);
            if(loginStatus == 1){ 
                return true;
            }
            else if (loginStatus == -1) { 
                return false;
            }
        }
        else if(opsi == 3){
            cout << "Info\t\t: Keluar dari program" << endl;
            return false;
        }
        else{
            cout << "Info\t\t: Pilihlah berdasarkan opsi yang valid" << endl;
        }
    }
}

void halamanUtama(int userindex) {
    while(true){
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
            error(1);
            continue;
        }

        if(opsi == 1){
            buatPlaylist(pengguna[userindex]);
        }
        else if(opsi == 2){
            lihatPlaylist(pengguna[userindex]);
        }
        else if(opsi == 3){
            ubahPlaylist(pengguna[userindex]);
        }
        else if(opsi == 4){
            hapusPlaylist(pengguna[userindex]);
        }
        else if(opsi == 5){
            cout << "Info\t\t: Kembali kehalaman masuk" << endl;
            return;
        } 
        else{
            cout << "Info\t\t: Pilihan tidak valid" << endl;
        }
    }
}

int main(){
    pengguna[jumlahuser].username = "Andi";
    pengguna[jumlahuser].password = "083";
    jumlahuser++;
    while(true) {
        int userindex = -1;
        if (halamanMasuk(userindex) == false) {
            break; 
        }
        halamanUtama(userindex);
    }
    return 0;
}