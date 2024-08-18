#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

// PROGRAM MANAJEMEN DATA PUSKESMAS SURABAYA
// KELOMPOK 5 
// ANGGOTA :
// 1. ALVITO BRYAN NUGRAHA       (23051204211)
// 2. FAYZUL HAQ                 (23051204203)
// 3. MUCH. JOUFAN ZUHUD ALFAHMI (23051204202)

void MenuLogin();
void MenuDaftarAkun();
void MenuPasien();
void MenuAdmin();
void DaftarPengobatan();
void MenampilkanNomorAntrian();
void CariPasien();
void EditPasien();
void DeletePasien();
void DisplayPuskesmas();
void DaftarPoli();
void ProsesAntrian();
void PanggilAmbulans();
void CariAmbulans();
void HapusAmbulans();
void TampilkanSemuaDataPasien();


struct Date
{
    int tanggal;
    int bulan;
    int tahun;
};
struct DataAkun
{
    string nama;
    string id;
    char kelamin;
    string alamat;
    string daerah;
    Date tanggal_lahirakun;
    DataAkun *next;
};
DataAkun *front = NULL;
DataAkun *back = NULL;
DataAkun *now = front;

struct DataPasien
{
    string nama;
    string nomor_hp;
    char kelamin;
    string alamat;
    Date tanggal_lahirpasien;
    string riwayat;
    string nomor_bpjs;
    int antrian;
    DataPasien *next;
};
DataPasien *newQueue, *del;
DataPasien *depan = NULL;
DataPasien *belakang = NULL;
DataPasien *cur = depan;

struct DataAmbulans
{
    string nama_mobil;
    DataAmbulans *selanjutnya;
    DataAmbulans *sebelumnya;
};

DataAmbulans *newAmbulans, *deletee;
DataAmbulans *awal = NULL;
DataAmbulans *akhir = NULL;
DataAmbulans *sekarang = awal;
struct Ambulans
{
    string namaMobil;
    Ambulans* next;
};

Ambulans *kepala = NULL;
Ambulans *ekor = NULL;
Ambulans *nxt = kepala;

struct DataOrder
{
    string nama_akun;
    string alamat_penjemputan;
    DataOrder *next;
};

struct TreeNode {
    DataPasien pasien;
    TreeNode* left;
    TreeNode* right;
};

struct Queue{
    DataPasien depan;
    DataPasien belakang;
};

struct Node
{
    DataAkun akun;
    DataPasien pasien;
    DataAmbulans ambulans;
    DataOrder order;
    Node *next;
    Node *prev;
};

Node* head = NULL;
Node* tail = NULL;
Node* current = head;

bool isEmpty() {
    return head == NULL;
}

int MenghitungBanyakAntrian()
{
    if ( depan == NULL){
        return 0;
    }else{
        int banyak = 0;
        cur = depan;
        while( cur != NULL){
            cur = cur-> next;
            banyak++;
        }
        return banyak;
    }
}

int MenghitungBanyakAmbulans()
{
    if ( awal == NULL){
        return 0;
    }else{
        int banyak = 0;
        sekarang = awal;
        while ( sekarang != NULL){
            sekarang = sekarang->selanjutnya;
            banyak++;
        }
        return banyak;
    }
}

bool FullAntrianPasien()
{
    if ( MenghitungBanyakAntrian() == 10){
        return true;
    }else{
        return false;
    }
}

bool EmptyAntrianPasien()
{
    if ( MenghitungBanyakAntrian() == 0){
        return true;
    }else{
        return false;
    }
}

bool FullAmbulans()
{
    if ( MenghitungBanyakAmbulans() == 5){
        return true;
    }else{
        return false;
    }
}

bool EmptyAmbulans()
{
    if ( MenghitungBanyakAmbulans() == 0){
        return true;
    }else{
        return false;
    }
}

int countMobil()
{
    if ( awal == NULL){
        return 0;
    }else{
        int banyak = 0;
        sekarang = awal;
        while ( sekarang != NULL){
            sekarang = sekarang->selanjutnya;
            banyak++;
        }
        return banyak;
    }
}

void PopStackMobil()
{
    if ( countMobil() > 1){
        deletee = akhir;
        akhir = akhir->sebelumnya;
        akhir->selanjutnya = NULL;
        delete deletee;
    }else{
        deletee = akhir;
        akhir = NULL;
        delete deletee;
    }
}

int hashFunction(const string& str) {
    int hash = 0;
    for (char c : str) {
        hash = (hash * 31 + c) % 100;
    }
    return hash;
}

void cetaknama(string nama)
{
    const int Lebar_layar = 51;
    int textlength = nama.length();
    int kirilayar = (Lebar_layar - textlength) / 2;
    int kananlayar = Lebar_layar - textlength - kirilayar;

    cout << "|" << string(kirilayar,' ') <<  nama << string(kananlayar, ' ') << "|" << endl;
}

// Fungsi untuk mengubah string menjadi huruf kapital
void toUpperCase(string& str) {
    for (char& c : str) {
        if (c >= 'a' && c <= 'z') {
            c -= 32;  // Kurangi nilai ASCII sebesar 32 untuk mengubah ke huruf kapital
        }
    }
}

void number1()
{
    cout << "|                                                   |" << endl;
    cout << "|                       ####                        |" << endl;
    cout << "|                      ## ##                        |" << endl;
    cout << "|                     #   ##                        |" << endl;
    cout << "|                         ##                        |" << endl;
    cout << "|                         ##                        |" << endl;
    cout << "|                         ##                        |" << endl;
    cout << "|                         ##                        |" << endl;
    cout << "|                      ########                     |" << endl;
    cout << "|                                                   |" << endl;
}
void number2()
{
    cout << "|                                                   |" << endl;
    cout << "|                      #######                      |" << endl;
    cout << "|                    ##       ##                    |" << endl;
    cout << "|                    ##       ##                    |" << endl;
    cout << "|                             ##                    |" << endl;
    cout << "|                      ######                       |" << endl;
    cout << "|                    ##                             |" << endl;
    cout << "|                    ##                             |" << endl;
    cout << "|                    ##########                     |" << endl;
    cout << "|                                                   |" << endl;
}
void number3()
{
    cout << "|                                                   |" << endl;
    cout << "|                      #######                      |" << endl;
    cout << "|                    ##       ##                    |" << endl;
    cout << "|                             ##                    |" << endl;
    cout << "|                      ######                       |" << endl;
    cout << "|                             ##                    |" << endl;
    cout << "|                    ##       ##                    |" << endl;
    cout << "|                     ########                      |" << endl;
    cout << "|                                                   |" << endl;
}
void number4()
{
    cout << "|                                                   |" << endl;
    cout << "|                    ##       ##                    |" << endl;
    cout << "|                    ##       ##                    |" << endl;
    cout << "|                    ##       ##                    |" << endl;
    cout << "|                    ##########                     |" << endl;
    cout << "|                             ##                    |" << endl;
    cout << "|                             ##                    |" << endl;
    cout << "|                             ##                    |" << endl;
    cout << "|                                                   |" << endl;
}
void number5()
{
    cout << "|                                                   |" << endl;
    cout << "|                    ##########                     |" << endl;
    cout << "|                    ##                             |" << endl;
    cout << "|                    ##                             |" << endl;
    cout << "|                    ##########                     |" << endl;
    cout << "|                             ##                    |" << endl;
    cout << "|                             ##                    |" << endl;
    cout << "|                    ##########                     |" << endl;
    cout << "|                                                   |" << endl;
}
void number6()
{
    cout << "|                                                   |" << endl;
    cout << "|                      #######                      |" << endl;
    cout << "|                    ##       ##                    |" << endl;
    cout << "|                    ##                             |" << endl;
    cout << "|                    ###########                    |" << endl;
    cout << "|                    ##       ##                    |" << endl;
    cout << "|                    ##       ##                    |" << endl;
    cout << "|                      #######                      |" << endl;
    cout << "|                                                   |" << endl;
}
void number7()
{
    cout << "|                                                   |" << endl;
    cout << "|                    ###########                    |" << endl;
    cout << "|                             ##                    |" << endl;
    cout << "|                             ##                    |" << endl;
    cout << "|                           ##                      |" << endl;
    cout << "|                          ##                       |" << endl;
    cout << "|                         ##                        |" << endl;
    cout << "|                        ##                         |" << endl;
    cout << "|                                                   |" << endl;
}
void number8()
{
    cout << "|                                                   |" << endl;
    cout << "|                      #######                      |" << endl;
    cout << "|                    ##       ##                    |" << endl;
    cout << "|                    ##       ##                    |" << endl;
    cout << "|                      #######                      |" << endl;
    cout << "|                    ##       ##                    |" << endl;
    cout << "|                    ##       ##                    |" << endl;
    cout << "|                      #######                      |" << endl;
    cout << "|                                                   |" << endl;
}
void number9()
{
    cout << "|                                                   |" << endl;
    cout << "|                      #######                      |" << endl;
    cout << "|                    ##       ##                    |" << endl;
    cout << "|                    ##       ##                    |" << endl;
    cout << "|                      #######                      |" << endl;
    cout << "|                             ##                    |" << endl;
    cout << "|                             ##                    |" << endl;
    cout << "|                      #######                      |" << endl;
    cout << "|                                                   |" << endl;
}
void number10()
{
    cout << "|                                                   |" << endl;
    cout << "|              ######         #######               |" << endl;
    cout << "|             ###  ##       ##       ##             |" << endl;
    cout << "|                  ##       ##       ##             |" << endl;
    cout << "|                  ##       ##       ##             |" << endl;
    cout << "|                  ##       ##       ##             |" << endl;
    cout << "|                  ##       ##       ##             |" << endl;
    cout << "|             ###########     #######               |" << endl;
    cout << "|                                                   |" << endl;
}

int much = 0;
int antri = 0;

int main(){

    system ("cls"); 
    int pil;
    cout << " ___________________________________________________" << endl;
    cout << "|                                                   |" << endl;
    cout << "|----------------- SELAMAT  DATANG -----------------|" << endl;
    cout << "|------ PENDAFTARAN PUSKESMAS PEMKOT SURABAYA ------|" << endl;
    cout << "|___________________________________________________|" << endl;
    cout << "|                                                   |" << endl;
    cout << "| 1. LOGIN                                          |" << endl;
    cout << "| 2. DAFTAR                                         |" << endl;
    cout << "|                                           EXIT .0 |" << endl;
    cout << "|---------------------------------------------------|" << endl;
    cout << "| MASUKKAN PILIHAN ANDA : ";
    cin >> pil;
    system ("cls");

    switch(pil){
        case 1:
            MenuLogin();
        case 2:
            MenuDaftarAkun();
            break;
        case 0:
            cout << "|===================================================|" << endl;
            cout << "|------------------ TERIMA  KASIH ------------------|" << endl;
            cout << "|--------------- SEMOGA SEHAT SELALU ---------------|" << endl;
            cout << "|                                                   |" << endl;
            cout << "|                                                   |" << endl;
            cout << "|        \"Kekayaan Terbesar Adalah Kesehatan\"       |" << endl;
            cout << "|                      -Virgil                      |" << endl;
            cout << "|                                                   |" << endl;
            cout << "|                                                   |" << endl;
            cout << "|===================================================|" << endl;
            cout << endl;
            return 0;

        default:
            cout << "|===================================================|" << endl;
            cout << "|------ HARAP MASUKKAN  PILIHAN YANG TERSEDIA ------|" << endl;
            cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
            cout << "|===================================================|" << endl;
            Sleep(3000);
            system("cls");
            main();
            break;

    }

}

void MenuLogin()
{
    DataAkun akun;
    string id;
    cout << "|===================================================|" << endl;
    cout << "|------------------- MENU  LOGIN -------------------|" << endl;
    cout << "|===================================================|" << endl;
    cout << "|MASUKKAN ID ANDA : ";
    cin >> id;
    system("cls");

    if (id == "*123#"){
        MenuAdmin();
    }else{
        Node* temp = head;
        bool found = false;

        if (head != NULL){
            do{
                if(temp -> akun.id ==id){
                    found = true;
                    current = temp;
                    break;
                }
                temp = temp->next;
            } while(temp != head);
        }
        if(found){
            MenuPasien();
        }else{
            cout << "|===================================================|" << endl;
            cout << "|-------------- !! NOMOR  ID SALAH !! --------------|" << endl;
            cout << "|-- ANDA AKAN KEMBALI KE  MENU AWAL DALAM 3 DETIK --|" << endl;
            cout << "|===================================================|" << endl;
            Sleep(3000);
            system ("cls");
            main();
        }
    }
}

void EnqueueDataPasien(string nama, string nomor_hp, char kelamin, string alamat, Date tanggal_lahirpasien, string riwayat, string nomor_bpjs, int antrian)
{
    if ( FullAntrianPasien() ){
        cout << "|===================================================|" << endl;
        cout << "|--------- !! MOHON MAAF  ANTRIAN PENUH !! ---------|" << endl;
        cout << "|----- SILAHKAN COBA LAGI DALAM BEBERAPA MENIT -----|" << endl;
        cout << "|===================================================|" << endl;
        system("pause");
        system("cls");
        MenuPasien();
    }else{

        if( EmptyAntrianPasien() ){
            depan = new DataPasien();
            depan->nama = nama;
            depan->nomor_hp = nomor_hp;
            depan->kelamin = kelamin;
            depan->alamat = alamat;
            depan->tanggal_lahirpasien = tanggal_lahirpasien;
            depan->riwayat = riwayat;
            depan->nomor_bpjs = nomor_bpjs;
            depan->antrian = antrian;
            depan->next = NULL;
            belakang = depan;

        }else{
            newQueue = new DataPasien();
            newQueue->nama = nama;
            newQueue->nomor_hp = nomor_hp;
            newQueue->kelamin = kelamin;
            newQueue->alamat = alamat;
            newQueue->tanggal_lahirpasien = tanggal_lahirpasien;
            newQueue->riwayat = riwayat;
            newQueue->nomor_bpjs = nomor_bpjs;
            newQueue->next = NULL;
            belakang->next = newQueue;
            belakang = newQueue;
        }
    }
}

void DequeueDataPasien()
{
    if ( EmptyAntrianPasien() ){
        cout << "|===================================================|" << endl;
        cout << "|--------!!  ANTRIAN PASIEN MASIH KOSONG  !!--------|" << endl;
        cout << "|-- ANDA AKAN KEMBALI KE MENU ADMIN DALAM 3 DETIK --|" << endl;
        cout << "|===================================================|" << endl;
        Sleep (3000);
        system("cls");
        MenuAdmin();
    }else{
        del = belakang;
        depan = depan->next;
        del->next = NULL;
        delete del;
    }
}


TreeNode* root = nullptr;

TreeNode* createTreeNode(DataPasien pasien) {
    TreeNode* newNode = new TreeNode;
    newNode->pasien = pasien;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

TreeNode* insertTreeNode(TreeNode* root, DataPasien pasien) {
    if (root == nullptr) {
        return createTreeNode(pasien);
    }

    if (pasien.nama < root->pasien.nama) {
        root->left = insertTreeNode(root->left, pasien);
    } else if (pasien.nama > root->pasien.nama) {
        root->right = insertTreeNode(root->right, pasien);
    }

    return root;
}

TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

TreeNode* deleteTreeNode(TreeNode* root, string nama) {
    if (root == nullptr) {
        return root;
    } else if (nama < root->pasien.nama) {
        root->left = deleteTreeNode(root->left, nama);
    } else if (nama > root->pasien.nama) {
        root->right = deleteTreeNode(root->right, nama);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr) {
            TreeNode* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            TreeNode* temp = findMin(root->right);
            root->pasien = temp->pasien;
            root->right = deleteTreeNode(root->right, temp->pasien.nama);
        }
    }
    return root;
}

TreeNode* searchTreeNode(TreeNode* root, string nama) {
    if (root == nullptr || root->pasien.nama == nama) {
        return root;
    }

    if (nama < root->pasien.nama) {
        return searchTreeNode(root->left, nama);
    }

    return searchTreeNode(root->right, nama);
}

bool cekID(string id) {
    Node* temp = head;
    if (head == nullptr) {
        return false;
    }

    do {
        if (temp->akun.id == id) {
            return true;
        }
        temp = temp->next;
    } while (temp != head);
    
    return false;
}

int Huruf_Angka(char a) {
    return (int)a - 96;
}

void insertdataakun (DataAkun akun) {
    Node* newNode = new Node;
    newNode->akun = akun;
    newNode->next = NULL;
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        head->next = newNode;
        head = newNode;
    }
    head->next = tail;
}

void insertdataambulans(DataAmbulans ambulans) {
    Node* newNode = new Node;
    newNode->ambulans = ambulans;
    newNode->next = NULL;
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    tail->next = head;
}

void insertdataorder(DataOrder order) {
    Node* newNode = new Node;
    newNode->order = order;
    newNode->next = NULL;
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    tail->next = head;
}

string GenerateID(string nama, char kelamin, Date tanggal_lahir){

    int hurufawal = Huruf_Angka(tolower(nama[0]));
    int hurufakhir = Huruf_Angka(tolower(nama[nama.length() - 1]));
    int digit12 = abs(hurufawal - hurufakhir);

    string digit1_2; 
    
    if (digit12 < 10) {
        digit1_2 = '0' + to_string(digit12);
    }
    else {
        digit1_2 = to_string(digit12);
    }
    
    int digit3 = (kelamin == 'l' || kelamin == 'L' ) ? 1 : 0;
    
    int digit4 = (tanggal_lahir.tanggal % 10) + (tanggal_lahir.bulan % 10) + (tanggal_lahir.tahun % 10);
    digit4 %= 9;
    
    int digit5 = 0;
    
    string id = digit1_2 + to_string(digit3) + to_string(digit4) + to_string(digit5);

    bool checkIDsama = cekID(id);
    while(checkIDsama) {
        digit5+=1;
        id = digit1_2 + to_string(digit3) + to_string(digit4) + to_string(digit5);
        checkIDsama = cekID(id);
    }
    return id;
}
void MenampilkanDataAkun()
{
    Node *current = head, *next = current->next;
    while (current != nullptr)
    {
        cout << "|---------------------------------------------------|" << endl;
        cout << "|                    DATA  AKUN                     |" << endl;
        cout << "|---------------------------------------------------|" << endl;
        cout << "| Nama      : " << current->akun.nama << endl;
        cout << "| Nomor Id  : " << current->akun.id << endl;
        cout << "| Tgl Lahir : " << current->akun.tanggal_lahirakun.tanggal << "-" << current->akun.tanggal_lahirakun.bulan << "-" << current->akun.tanggal_lahirakun.tahun << endl;
        cout << "| Kelamin   : " << current->akun.kelamin << endl;
        cout << "| Alamat    : " << current->akun.alamat << endl;
        cout << "| Daerah    : " << current->akun.daerah << endl;
        cout << "|---------------------------------------------------|" << endl;
        break;
    }
}

int InputDataAkun(){
    DataAkun NewAkun;
    string daerah;
    cin.ignore();
    cout << "| Masukkan Nama                     : ";
    getline(cin, NewAkun.nama);
    cout << "| Masukkan Tanggal Lahir\n| Sesuai Format (DD MM YYYY)        : ";
    cin >> NewAkun.tanggal_lahirakun.tanggal >> NewAkun.tanggal_lahirakun.bulan >> NewAkun.tanggal_lahirakun.tahun;
    cout << "| Masukkan Jenis Kelamin (L/P)      : ";
    cin >> NewAkun.kelamin;
    cin.ignore();
    cout << "| Masukkan Alamat                   : ";
    getline(cin, NewAkun.alamat);
    cout << "| Masukkan Daerah Sesuai Format\n| (Utara/Selatan/Timur/Barat/Pusat) : ";
    getline(cin, NewAkun.daerah);
    
    NewAkun.id = GenerateID(NewAkun.nama, NewAkun.kelamin, NewAkun.tanggal_lahirakun);

    insertdataakun(NewAkun);

    system("cls");
    cout << "|===================================================|" << endl;
    cout << "|------------ DATA BERHASIL DITAMBAHKAN ------------|" << endl;
    MenampilkanDataAkun();
    cout << "|---------- GUNAKAN NOMOR ID  UNTUK LOGIN ----------|" << endl;
    cout << "|===================================================|" << endl;
    system("pause");
    main();
    return 0;
}

void MenuDaftarAkun()
{
    cout << "|===================================================|" << endl;
    cout << "|--------- SILAHKAN INPUT DATA DIRI ANDA -----------|" << endl;
    cout << "|===================================================|" << endl;
    InputDataAkun();
}

int DisplayAntrian(string nama)
{
    much++;
    cout << "|===================================================|" << endl;
    cout << "|-------- DATA PASIEN  BERHASIL DITAMBAHKAN --------|" << endl;
    cout << "|                                                   |" << endl;
    cout << "|-------- BERIKUT ADALAH NOMOR ANTRIAN ANDA --------|" << endl;
    cout << "|===================================================|" << endl;
    cout << "|                                                   |" << endl;
    cout << "|                                                   |" << endl;
    cout << "|             NOMOR ANTRIAN POLI/KLINIK             |" << endl;
    cout << "|                                                   |" << endl;

    switch (much)
    {
        case 1: number1(); break;
        case 2: number2(); break;
        case 3: number3(); break;
        case 4: number4(); break;
        case 5: number5(); break;
        case 6: number6(); break;
        case 7: number7(); break;
        case 8: number8(); break;
        case 9: number9(); break;
        case 10: number10(); break;

    }
    cout << "|                                                   |" << endl;
    cout << "|                     ATAS NAMA                     |" << endl;
    cout << "|                                                   |" << endl;
    string decoy = nama;
    toUpperCase(decoy);
    cetaknama(decoy);
    cout << "|                                                   |" << endl;
    cout << "|             HARAP DATANG  TEPAT WAKTU             |" << endl;
    cout << "|===================================================|" << endl;
    return much;
}

int TampilkanAntrian(string nama, int antrian)
{
    cout << "|===================================================|" << endl;
    cout << "|-------- BERIKUT ADALAH NOMOR ANTRIAN ANDA --------|" << endl;
    cout << "|===================================================|" << endl;
    cout << "|                                                   |" << endl;
    cout << "|                                                   |" << endl;
    cout << "|             NOMOR ANTRIAN POLI/KLINIK             |" << endl;
    cout << "|                                                   |" << endl;

    switch (antrian)
    {
        case 1: number1(); break;
        case 2: number2(); break;
        case 3: number3(); break;
        case 4: number4(); break;
        case 5: number5(); break;
        case 6: number6(); break;
        case 7: number7(); break;
        case 8: number8(); break;
        case 9: number9(); break;
        case 10: number10(); break;

    }
    cout << "|                                                   |" << endl;
    cout << "|                     ATAS NAMA                     |" << endl;
    cout << "|                                                   |" << endl;
    string decoy = nama;
    toUpperCase(decoy);
    cetaknama(decoy);
    cout << "|                                                   |" << endl;
    cout << "|             HARAP DATANG  TEPAT WAKTU             |" << endl;
    cout << "|===================================================|" << endl;
    return much;
}

void MenuDaftarPasien() {
    DataPasien newPasien;
    cout << "|===================================================|" << endl;
    cout << "|--------- SILAHKAN INPUT DATA DIRI ANDA -----------|" << endl;
    cout << "|===================================================|" << endl;
    cout << "| Masukkan Nama                       : ";
    cin.ignore();
    getline(cin, newPasien.nama);
    cout << "| Masukkan Nomor HP                   : ";
    cin >> newPasien.nomor_hp;
    cout << "| Masukkan Jenis Kelamin (L/P)        : ";
    cin >> newPasien.kelamin;
    cin.ignore();
    cout << "| Masukkan Alamat                     : ";
    getline(cin, newPasien.alamat);
    cout << "| Masukkan Tanggal Lahir (DD MM YYYY) : ";
    cin >> newPasien.tanggal_lahirpasien.tanggal >> newPasien.tanggal_lahirpasien.bulan >> newPasien.tanggal_lahirpasien.tahun;
    cin.ignore();
    cout << "| Masukkan Riwayat Penyakit           : ";
    getline(cin, newPasien.riwayat);
    cout << "| Masukkan Nomor BPJS                 : ";
    getline(cin, newPasien.nomor_bpjs);
    antri++;
    newPasien.antrian = antri;

    EnqueueDataPasien(newPasien.nama, newPasien.nomor_hp, newPasien.kelamin, newPasien.alamat, newPasien.tanggal_lahirpasien, newPasien.riwayat, newPasien.nomor_bpjs, newPasien.antrian);
    
    root = insertTreeNode(root, newPasien);
    system("cls");
    DisplayAntrian(newPasien.nama);
    system("pause");
    system("cls");
    MenuPasien();
}


void DaftarPoli()
{
    int pil;
    cout << "|===================================================|" << endl;
    cout << "|---------- PILIH POLI/KLINIK PENGOBATAN -----------|" << endl;
    cout << "|===================================================|" << endl;
    cout << "| 1. UMUM                                           |" << endl;
    cout << "| 2. GIGI                                           |" << endl;
    cout << "| 3. ANAK                                           |" << endl;
    cout << "| 4. LANSIA                                         |" << endl;
    cout << "| 5. GIZI                                           |" << endl;
    cout << "|                                        KEMBALI .0 |" << endl;
    cout << "|---------------------------------------------------|" << endl;
    cout << "| MASUKKAN PILIHAN ANDA : ";
    cin >> pil; 
    system ("cls");

    switch (pil)
    {
        case 1:
            MenuDaftarPasien();
            MenuPasien();
            break;
        case 2:
            MenuDaftarPasien();
            MenuPasien();
            break;
        case 3:
            MenuDaftarPasien();
            MenuPasien();
            break;
        case 4:
            MenuDaftarPasien();
            MenuPasien();
            break;
        case 5:
            MenuDaftarPasien();
            MenuPasien();
            break;
        case 0:
            cout << "|===================================================|" << endl;
            cout << "|----------- KEMBALI KE  MENU SEBELUMNYA -----------|" << endl;
            cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
            cout << "|===================================================|" << endl;
            Sleep(3000);
            system ("cls");
            MenuPasien();
        default:
            cout << "|===================================================|" << endl;
            cout << "|------ HARAP MASUKKAN  PILIHAN YANG TERSEDIA ------|" << endl;
            cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
            cout << "|===================================================|" << endl;
            Sleep(3000);
            system ("cls");
            DaftarPoli();
    }
}

void DaftarPengobatan()
{
    Node *current = head, *next = current->next;
    
    string PuskesmasUtara[] ={"Puskesmas Bulak Banteng", "Puskesmas Kenjeran", "Puskesmas Dupak", "Puskesmas Sidotopo"};
    string PuskesmasSelatan[] ={"Puskesmas Balas Klumprik", "Puskesmas Wiyung", "Puskesmas Kedurus", "Puskesmas Wonokromo"};
    string PuskesmasTimur[] ={"Puskesmas Gading", "Puskesmas Keputih", "Puskesmas Pacar Keling", "Puskesmas Tenggilis"};
    string PuskesmasBarat[] ={"Puskesmas Asemrowo", "Puskesmas Benowo", "Puskesmas Lidah Kulon", "Puskesmas Manukan"};
    string PuskesmasPusat[] ={"Puskesmas Dr. Soetomo", "Puskesmas Gundih", "Puskesmas Kedungdoro", "Puskesmas Ketabang"};
    int pil;
    cout << "|===================================================|" << endl;
    cout << "|--------------- DAFTAR PENGOBATAN -----------------|" << endl;
    cout << "|===================================================|" << endl;
    
    if (current->akun.daerah == "utara" || current->akun.daerah == "Utara"){
        cout << "| 1. " << PuskesmasUtara[0] << endl;
        cout << "| 2. " << PuskesmasUtara[1] << endl;
        cout << "| 3. " << PuskesmasUtara[2] << endl;
        cout << "| 4. " << PuskesmasUtara[3] << endl;
        cout << "|                                        KEMBALI .0 |" << endl;
        cout << "|---------------------------------------------------|" << endl;
        cout << "| MASUKKAN PILIHAN ANDA : ";
        cin >> pil;
        system("cls");
        
        switch(pil)
        {
            case 1:
                DaftarPoli();
                MenuPasien();
                break;
            case 2:
                DaftarPoli();
                MenuPasien();
                break;
            case 3:
                DaftarPoli();
                MenuPasien();
                break;
            case 4:
                DaftarPoli();
                MenuPasien();
                break;
            case 0:
                cout << "|===================================================|" << endl;
                cout << "|----------- KEMBALI KE  MENU SEBELUMNYA -----------|" << endl;
                cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
                cout << "|===================================================|" << endl;
                Sleep(3000);
                system ("cls");
                MenuPasien();
                break;
            default:
                cout << "|===================================================|" << endl;
                cout << "|------ HARAP MASUKKAN  PILIHAN YANG TERSEDIA ------|" << endl;
                cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
                cout << "|===================================================|" << endl;
                Sleep(3000);
                system ("cls");
                DaftarPengobatan();
        }
    } else if (current->akun.daerah == "selatan" || current->akun.daerah == "Selatan"){
        cout << "| 1. " << PuskesmasSelatan[0] << endl;
        cout << "| 2. " << PuskesmasSelatan[1] << endl;
        cout << "| 3. " << PuskesmasSelatan[2] << endl;
        cout << "| 4. " << PuskesmasSelatan[3] << endl;
        cout << "|                                        KEMBALI .0 |" << endl;
        cout << "|---------------------------------------------------|" << endl;
        cout << "| MASUKKAN PILIHAN ANDA : ";
        cin >> pil;
        system("cls");
        
        switch(pil)
        {
            case 1:
                DaftarPoli();
                MenuPasien();
                break;
            case 2:
                DaftarPoli();
                MenuPasien();
                break;
            case 3:
                DaftarPoli();
                MenuPasien();
                break;
            case 4:
                DaftarPoli();
                MenuPasien();
                break;
            case 0:
                cout << "|===================================================|" << endl;
                cout << "|----------- KEMBALI KE  MENU SEBELUMNYA -----------|" << endl;
                cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
                cout << "|===================================================|" << endl;
                Sleep(3000);
                system ("cls");
                MenuPasien();
                break;
            default:
                cout << "|===================================================|" << endl;
                cout << "|------ HARAP MASUKKAN  PILIHAN YANG TERSEDIA ------|" << endl;
                cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
                cout << "|===================================================|" << endl;
                Sleep(3000);
                system ("cls");
                DaftarPengobatan();
        }
    } else if (current->akun.daerah == "timur" || current->akun.daerah == "Timur"){
        cout << "| 1. " << PuskesmasTimur[0] << endl;
        cout << "| 2. " << PuskesmasTimur[1] << endl;
        cout << "| 3. " << PuskesmasTimur[2] << endl;
        cout << "| 4. " << PuskesmasTimur[3] << endl;
        cout << "|                                        KEMBALI .0 |" << endl;
        cout << "|---------------------------------------------------|" << endl;
        cout << "| MASUKKAN PILIHAN ANDA : ";
        cin >> pil;
        system("cls");
        
        switch(pil)
        {
            case 1:
                DaftarPoli();
                MenuPasien();
                break;
            case 2:
                DaftarPoli();
                MenuPasien();
                break;
            case 3:
                DaftarPoli();
                MenuPasien();
                break;
            case 4:
                DaftarPoli();
                MenuPasien();
                break;
            case 0:
                cout << "|===================================================|" << endl;
                cout << "|----------- KEMBALI KE  MENU SEBELUMNYA -----------|" << endl;
                cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
                cout << "|===================================================|" << endl;
                Sleep(3000);
                system ("cls");
                MenuPasien();
                break;
            default:
                cout << "|===================================================|" << endl;
                cout << "|------ HARAP MASUKKAN  PILIHAN YANG TERSEDIA ------|" << endl;
                cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
                cout << "|===================================================|" << endl;
                Sleep(3000);
                system ("cls");
                DaftarPengobatan();
        }
    } else if (current->akun.daerah == "barat" || current->akun.daerah == "Barat"){
        cout << "| 1. " << PuskesmasBarat[0] << endl;
        cout << "| 2. " << PuskesmasBarat[1] << endl;
        cout << "| 3. " << PuskesmasBarat[2] << endl;
        cout << "| 4. " << PuskesmasBarat[3] << endl;
        cout << "|                                        KEMBALI .0 |" << endl;
        cout << "|---------------------------------------------------|" << endl;
        cout << "| MASUKKAN PILIHAN ANDA : ";
        cin >> pil;
        system("cls");
        
        switch(pil)
        {
            case 1:
                DaftarPoli();
                MenuPasien();
                break;
            case 2:
                DaftarPoli();
                MenuPasien();
                break;
            case 3:
                DaftarPoli();
                MenuPasien();
                break;
            case 4:
                DaftarPoli();
                MenuPasien();
                break;
            case 0:
                cout << "|===================================================|" << endl;
                cout << "|----------- KEMBALI KE  MENU SEBELUMNYA -----------|" << endl;
                cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
                cout << "|===================================================|" << endl;
                Sleep(3000);
                system ("cls");
                MenuPasien();
                break;
            default:
                cout << "|===================================================|" << endl;
                cout << "|------ HARAP MASUKKAN  PILIHAN YANG TERSEDIA ------|" << endl;
                cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
                cout << "|===================================================|" << endl;
                Sleep(3000);
                system ("cls");
                DaftarPengobatan();
        }
    } else if (current->akun.daerah == "pusat" || current->akun.daerah == "Pusat"){
        cout << "| 1. " << PuskesmasPusat[0] << endl;
        cout << "| 2. " << PuskesmasPusat[1] << endl;
        cout << "| 3. " << PuskesmasPusat[2] << endl;
        cout << "| 4. " << PuskesmasPusat[3] << endl;
        cout << "|                                        KEMBALI .0 |" << endl;
        cout << "|---------------------------------------------------|" << endl;
        cout << "| MASUKKAN PILIHAN ANDA : ";
        cin >> pil;
        system("cls");
        
        switch(pil)
        {
            case 1:
                DaftarPoli();
                MenuPasien();
                break;
            case 2:
                DaftarPoli();
                MenuPasien();
                break;
            case 3:
                DaftarPoli();
                MenuPasien();
                break;
            case 4:
                DaftarPoli();
                MenuPasien();
                break;
            case 0:
                cout << "|===================================================|" << endl;
                cout << "|----------- KEMBALI KE MENU SEBELUMNYA ------------|" << endl;
                cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
                cout << "|===================================================|" << endl;
                Sleep(3000);
                system ("cls");
                MenuPasien();
                break;
            default:
                cout << "|===================================================|" << endl;
                cout << "|------ HARAP MASUKKAN  PILIHAN YANG TERSEDIA ------|" << endl;
                cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
                cout << "|===================================================|" << endl;
                Sleep(3000);
                system ("cls");
                DaftarPengobatan();
        }
    }
}

void MenampilkanNomorAntrian()
{
    string nama;
    cout << "|===================================================|" << endl;
    cout << "|----------------- CARI DATA PASIEN ----------------|" << endl;
    cout << "|===================================================|" << endl;
    cout << "| Masukkan Nama Pasien : ";
    cin.ignore();
    getline(cin, nama);
    system("cls");

    TreeNode* hasil = searchTreeNode(root, nama);
    if (hasil != nullptr) {
        cout << "| Nama       : " << hasil->pasien.nama << endl;
        cout << "| Antrian    : " << hasil->pasien.antrian << endl;
        system("cls");
        TampilkanAntrian(hasil->pasien.nama,hasil -> pasien.antrian);
    }
}

void bubbleSortPasienNama() {
    if (depan == NULL) return;

    bool swapped;
    DataPasien *ptr1;
    DataPasien *lptr = NULL;
    int n = MenghitungBanyakAntrian();

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        ptr1 = depan;

         // Kompleksitas waktu: O(n^2)
        for (int j = 0; j < n - i - 1; j++) {
            if (ptr1->nama > ptr1->next->nama) {
                swap(ptr1->nama, ptr1->next->nama);
                swap(ptr1->nomor_hp, ptr1->next->nomor_hp);
                swap(ptr1->kelamin, ptr1->next->kelamin);
                swap(ptr1->alamat, ptr1->next->alamat);
                swap(ptr1->tanggal_lahirpasien, ptr1->next->tanggal_lahirpasien);
                swap(ptr1->riwayat, ptr1->next->riwayat);
                swap(ptr1->nomor_bpjs, ptr1->next->nomor_bpjs);
                swap(ptr1->antrian, ptr1->next->antrian);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
}

void TampilkanSemuaDataPasien() {
    if (depan == NULL) {
        cout << "|===================================================|" << endl;
        cout << "|----------------- BELUM ADA PASIEN ----------------|" << endl;
        cout << "|----------- KEMBALI KE  MENU SEBELUMNYA -----------|" << endl;
        cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
        cout << "|===================================================|" << endl;
        Sleep(3000);
        system("cls");
        MenuAdmin();
    }

    bubbleSortPasienNama();
        cout << "|===================================================|" << endl;
        cout << "|----------- BERIKUT ADALAH  DATA PASIEN -----------|" << endl;
        cout << "|===================================================|" << endl;

    DataPasien* current = depan;
    while (current != NULL) {
        cout << "| Nama: " << current->nama << endl;
        cout << "| Nomor HP: " << current->nomor_hp << endl;
        cout << "| Jenis Kelamin: " << current->kelamin << endl;
        cout << "| Alamat: " << current->alamat << endl;
        cout << "| Tanggal Lahir: " << current->tanggal_lahirpasien.tanggal << "/" << current->tanggal_lahirpasien.bulan << "/" << current->tanggal_lahirpasien.tahun << endl;
        cout << "| Riwayat: " << current->riwayat << endl;
        cout << "| Nomor BPJS: " << current->nomor_bpjs << endl;
        cout << "|===================================================|" << endl;
        current = current->next;
    }
    system("pause");
    system("cls");
    MenuAdmin();
}

void CariPasien() {
    string nama;
    cout << "|===================================================|" << endl;
    cout << "|----------------- CARI DATA PASIEN ----------------|" << endl;
    cout << "|===================================================|" << endl;
    cout << "|Masukkan Nama Pasien : ";
    cin.ignore();
    getline(cin, nama);
    system("cls");

    TreeNode* result = searchTreeNode(root, nama);
    if (result != nullptr) {
        cout << "|===================================================|" << endl;
        cout << "|--------------- BERIKUT DATA PASIEN ---------------|" << endl;
        cout << "|===================================================|" << endl;
        cout << "| Nama       : " << result->pasien.nama << endl;
        cout << "| Nomor HP   : " << result->pasien.nomor_hp << endl;
        cout << "| Tgl Lahir  : " << result->pasien.tanggal_lahirpasien.tanggal << "-" << result->pasien.tanggal_lahirpasien.bulan << "-" << result->pasien.tanggal_lahirpasien.tahun << endl;
        cout << "| Kelamin    : " << result->pasien.kelamin << endl;
        cout << "| Alamat     : " << result->pasien.alamat << endl;
        cout << "| Riwayat    : " << result->pasien.riwayat << endl;
        cout << "| Nomor BPJS : " << result->pasien.nomor_bpjs << endl;
        cout << "| Antrian    : " << result->pasien.antrian << endl;
        cout << "|===================================================|" << endl;
        cout << "|---------------------------------------------------|" << endl;
        cout << "|===================================================|" << endl;
    } else {
        cout << "|===================================================|" << endl;
        cout << "|----------- DATA PASIEN TIDAK DITEMUKAN -----------|" << endl;
        cout << "|----------- KEMBALI KE  MENU SEBELUMNYA -----------|" << endl;
        cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
        cout << "|===================================================|" << endl;
    }
    system("pause");
    system("cls");
}


void EditPasien()
{
    string nama;
    cout << "|===================================================|" << endl;
    cout << "| MASUKKAN NAMA PASIEN YANG INGIN DIEDIT : ";
    cin.ignore();
    getline(cin, nama);
    system("cls");

    TreeNode* found = searchTreeNode(root, nama);
    if (found != nullptr) {
        cout << "|---------------------------------------------------|" << endl;
        cout << "|                  EDIT DATA PASIEN                 |" << endl;
        cout << "|---------------------------------------------------|" << endl;
        cout << "| Masukkan Nama Pasien           : ";
        getline(cin, found->pasien.nama);
        cout << "| Masukkan Nomor HP              : ";
        getline(cin, found->pasien.nomor_hp);
        cout << "| Masukkan Jenis Kelamin (L/P)   : ";
        cin >> found->pasien.kelamin;
        cin.ignore();
        cout << "| Masukkan Alamat                : ";
        getline(cin, found->pasien.alamat);
        cout << "| Masukkan Tanggal Lahir\n|Sesuai Format (DD MM YYYY)    : ";
        cin >> found->pasien.tanggal_lahirpasien.tanggal >> found->pasien.tanggal_lahirpasien.bulan >> found->pasien.tanggal_lahirpasien.tahun;
        cin.ignore();
        cout << "| Masukkan Riwayat Penyakit      : ";
        getline(cin, found->pasien.riwayat);
        cout << "| Masukkan Nomor BPJS            : ";
        getline(cin, found->pasien.nomor_bpjs);
        system("cls");

        cout << "|===================================================|" << endl;
        cout << "|----------- DATA PASIEN BERHASIL DIEDIT -----------|" << endl;
        cout << "|===================================================|" << endl;
    } else {
        cout << "|===================================================|" << endl;
        cout << "|----------- DATA PASIEN TIDAK DITEMUKAN -----------|" << endl;
        cout << "|===================================================|" << endl;
    }

}

void DeletePasien()
{
    string nama;
    cout << "|===================================================|" << endl;
    cout << "|---------------- HAPUS DATA PASIEN ----------------|" << endl;
    cout << "|===================================================|" << endl;
    cout << "|Masukkan Nama Pasien yang akan dihapus : ";
    cin.ignore();
    getline(cin, nama);

    root = deleteTreeNode(root, nama);

    system("cls");
    cout << "|===================================================|" << endl;
    cout << "|-------------- DATA BERHASIL DIHAPUS --------------|" << endl;
    cout << "|===================================================|" << endl;

}

void DisplayPuskesmas()
{
    cout << "|===================================================|" << endl;
    cout << "|--------- DAFTAR PUSKESMAS PEMKOT SURABAYA --------|" << endl;
    cout << "|===================================================|" << endl;
    cout << "| 1. DAERAH SURABAYA UTARA                          |" << endl;
    cout << "|                                                   |" << endl;
    cout << "|     *PUSKESMAS BULAK BANTENG                      |" << endl;
    cout << "|     *PUSKESMAS KENJERAN                           |" << endl;
    cout << "|     *PUSKESMAS DUPAK                              |" << endl;
    cout << "|     *PUSKESMAS SIDOTOPO                           |" << endl;
    cout << "|                                                   |" << endl;
    cout << "| 2. DAERAH SURABAYA SELATAN                        |" << endl;
    cout << "|                                                   |" << endl;
    cout << "|     *PUSKESMAS BALAS KLUMRPIK                     |" << endl;
    cout << "|     *PUSKESMAS WIYUNG                             |" << endl;
    cout << "|     *PUSKESMAS KEDURUS                            |" << endl;
    cout << "|     *PUSKESMAS WONOKROMO                          |" << endl;
    cout << "|                                                   |" << endl;
    cout << "| 3. DAERAH SURABAYA TIMUR                          |" << endl;
    cout << "|                                                   |" << endl;
    cout << "|     *PUSKESMAS GADING                             |" << endl;
    cout << "|     *PUSKESMAS KEPUTIH                            |" << endl;
    cout << "|     *PUSKESMAS PACAR KELING                       |" << endl;
    cout << "|     *PUSKESMAS TENGGILIS                          |" << endl;
    cout << "|                                                   |" << endl;
    cout << "| 4. DAERAH SURABAYA BARAT                          |" << endl;
    cout << "|                                                   |" << endl;
    cout << "|     *PUSKESMAS ASEMROWO                           |" << endl;
    cout << "|     *PUSKESMAS BENOWO                             |" << endl;
    cout << "|     *PUSKESMAS LIDAH KULON                        |" << endl;
    cout << "|     *PUSKESMAS MANUKAN                            |" << endl;
    cout << "|                                                   |" << endl;
    cout << "| 5. DAERAH SURABAYA PUSAT                          |" << endl;
    cout << "|                                                   |" << endl;
    cout << "|     *PUSKESMAS DR. SOETOMO                        |" << endl;
    cout << "|     *PUSKESMAS GUNDIH                             |" << endl;
    cout << "|     *PUSKESMAS KEDUNGDORO                         |" << endl;
    cout << "|     *PUSKESMAS KETABANG                           |" << endl;
    cout << "|===================================================|" << endl;
    cout << "|---------------------------------------------------|" << endl;
    cout << "|===================================================|" << endl;
    system("pause");
    system("cls");
    MenuAdmin;
}

void ProsesAntrian() {
    if (EmptyAntrianPasien()) {
        cout << "|===================================================|" << endl;
        cout << "|--------------- TIDAK ADA ANTRIAN -----------------|" << endl;
        cout << "|-- ANDA AKAN KEMBALI KE MENU ADMIN DALAM 3 DETIK --|" << endl;
        cout << "|===================================================|" << endl;
        Sleep(3000);
        system("cls");
        MenuAdmin();
    } else {
        DataPasien* current = depan;
        int pil;
        while (current != NULL) {
            cout << "|===================================================|" << endl;
            cout << "|----------------- ANTRIAN  PASIEN -----------------|" << endl;
            cout << "|===================================================|" << endl;
            cout << "| Nama             : " << current->nama << endl;
            cout << "| Nomor HP         : " << current->nomor_hp << endl;
            cout << "| Jenis Kelamin    : " << current->kelamin << endl;
            cout << "| Alamat           : " << current->alamat << endl;
            cout << "| Tanggal Lahir    : " << current->tanggal_lahirpasien.tanggal << "/" << current->tanggal_lahirpasien.bulan << "/" << current->tanggal_lahirpasien.tahun << endl;
            cout << "| Riwayat Penyakit : " << current->riwayat << endl;
            cout << "| Nomor BPJS       : " << current->nomor_bpjs << endl;
            cout << "|---------------------------------------------------|" << endl;
            cout << "| 1. Terima Antrian                                 |" << endl;
            cout << "| 2. Tolak Antrian                                  |" << endl;
            cout << "| 0. Kembali                                        |" << endl;
            cout << "|---------------------------------------------------|" << endl;
            cout << "| Masukkan Pilihan Anda : ";
            cin >> pil;
            system("cls");

            switch (pil) {
                case 1:
                    cout << "|===================================================|" << endl;
                    cout << "|------------ ANTRIAN BERHASIL DITERIMA ------------|" << endl;
                    cout << "|----------- KEMBALI KE  MENU SEBELUMNYA -----------|" << endl;
                    cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
                    cout << "|===================================================|" << endl;
                    DequeueDataPasien();
                    much--;
                    antri--;
                    Sleep(3000);
                    break;
                case 2:
                    cout << "|===================================================|" << endl;
                    cout << "|------------ ANTRIAN BERHASIL DITOLAK -------------|" << endl;
                    cout << "|----------- KEMBALI KE  MENU SEBELUMNYA -----------|" << endl;
                    cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
                    cout << "|===================================================|" << endl;
                    DequeueDataPasien();
                    much--;
                    antri--;
                    Sleep(3000);
                    break;
                case 0:
                    cout << "|===================================================|" << endl;
                    cout << "|----------- KEMBALI KE MENU SEBELUMNYA ------------|" << endl;
                    cout << "|===================================================|" << endl;
                    MenuAdmin();
                    return;
                default:
                    cout << "|===================================================|" << endl;
                    cout << "|------ HARAP MASUKKAN PILIHAN YANG TERSEDIA -------|" << endl;
                    cout << "|===================================================|" << endl;
                    Sleep(3000);
                    system("cls");
                    break;
            }
            if (current == belakang) {
                current = NULL;
            } else {
                current = current->next;
            }
        }
    }
}

void Order(string nama)
{
    DataOrder neworder;
    cin.ignore();
    cout << "|===================================================|" << endl;
    cout << "|--------------- INPUT  DATA PASIEN ----------------|" << endl;
    cout << "|===================================================|" << endl;
    cout << "| Masukkan Nama Pelanggan     : ";
    getline(cin, neworder.nama_akun);
    cout << "| Masukkan Alamat Penjemputan : ";
    getline(cin, neworder.alamat_penjemputan);

    system("cls");

    insertdataorder(neworder);
    
}

void PanggilAmbulans()
{
    if( EmptyAmbulans() ){
        cout << "|===================================================|" << endl;
        cout << "|-----------!! AMBULANS  SEDANG KOSONG !!-----------|" << endl;
        cout << "|------ KEMBALI KE MENU  PASIEN DALAM 3 DETIK ------|" << endl;
        cout << "|===================================================|" << endl;
        Sleep (3000);
        system("cls");
        MenuPasien();
    }else{
        sekarang = akhir;
        int pil;
        while ( sekarang != NULL){
                cout << "|===================================================|" << endl;
                cout << "|---------------- AMBULANS TERSEDIA ----------------|" << endl;
                cout << "|===================================================|" << endl;
                cout << "| Nama Ambulans       : " << sekarang->nama_mobil << endl;
                cout << "|---------------------------------------------------|" << endl;
                cout << "| 1. Panggil Ambulans                               |" << endl;
                cout << "|                                        KEMBALI .0 |" << endl;
                cout << "|---------------------------------------------------|" << endl;
                cout << "| Masukkan Pilihan Anda : ";
                cin >> pil;
                system("cls");

                switch(pil)
                {
                    case 1:
                        PopStackMobil();
                        cout << "|===================================================|" << endl;
                        cout << "|----------- BERHASIL  MEMANGGIL AMBULAN -----------|" << endl;
                        cout << "|---- HARAP MENUNGGU  AMBULANS AKAN SEGERA TIBA ----|" << endl;
                        cout << "|===================================================|" << endl;
                        system("pause");
                        system("cls");
                        MenuPasien();
                        break;
                    case 0:
                        cout << "|===================================================|" << endl;
                        cout << "|---------------  KELUAR DARI MENU  ----------------|" << endl;
                        cout << "|------ KEMBALI KE MENU  PASIEN DALAM 3 DETIK ------|" << endl;
                        cout << "|===================================================|" << endl;
                        Sleep (3000);
                        system("cls");
                        MenuPasien();
                        break;
                }
            }
        
    }
}

void StackAmbulans(string nama_mobil)
{
    if ( FullAmbulans() ){
        cout << "|===================================================|" << endl;
        cout << "|-------------- AMBULANS SUDAH PENUH ---------------|" << endl;
        cout << "|-- ANDA AKAN KEMBALI KE MENU ADMIN DALAM 3 DETIK --|" << endl;
        cout << "|===================================================|" << endl;
        Sleep (3000);
        system("cls");
        MenuAdmin();
    }else{
        if ( EmptyAmbulans() ){
            awal = new DataAmbulans;
            awal->nama_mobil = nama_mobil;
            awal->sebelumnya = NULL;
            awal->selanjutnya = NULL;
            akhir = awal;
        }else{
            newAmbulans = new DataAmbulans;
            newAmbulans->nama_mobil = nama_mobil;
            newAmbulans->sebelumnya = akhir;
            akhir->selanjutnya = newAmbulans;
            newAmbulans->selanjutnya = NULL;
            akhir = newAmbulans;
        }
    }
}

Ambulans* dataAmbulans[100];

void tambahAmbulans(const string& namaMobil)
{
    int index = hashFunction(namaMobil);
    Ambulans* newAmbulans = new Ambulans;
    newAmbulans->namaMobil = namaMobil;
    newAmbulans->next = dataAmbulans[index];
    dataAmbulans[index] = newAmbulans;
}

Ambulans* cariAmbulans(const string& namaMobil)
{
    int index = hashFunction(namaMobil);
    Ambulans* curr = dataAmbulans[index];
    while (curr != nullptr) {
        if (curr->namaMobil == namaMobil) {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

bool hapusAmbulans(const string& namaMobil) {
    int index = hashFunction(namaMobil);
    Ambulans* curr = dataAmbulans[index];
    Ambulans* prev = nullptr;

    while (curr != nullptr) {
        if (curr->namaMobil == namaMobil) {
            if (prev == nullptr) {
                dataAmbulans[index] = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}

void printAmbulans(Ambulans* ambulans) {
    if (ambulans != nullptr) {
        cout << "|===================================================|" << endl;
        cout << "|---------------- MENCARI  AMBULANS ----------------|" << endl;
        cout << "|===================================================|" << endl;
        cout << "|                                                   |" << endl;
        cout << "| NAMA AMBULANS: " << ambulans->namaMobil << endl;
        cout << "|                                                   |" << endl;
        cout << "|===================================================|" << endl;
        cout << "|---------------------------------------------------|" << endl;
        cout << "|===================================================|" << endl;
        system("pause");
        system("cls");
    } else {
        cout << "|===================================================|" << endl;
        cout << "|---------------- MENCARI  AMBULANS ----------------|" << endl;
        cout << "|===================================================|" << endl;
        cout << "|                                                   |" << endl;
        cout << "|              AMBULANS TIDAK DITEMUKAN             |"<< endl;
        cout << "|                                                   |" << endl;
        cout << "|===================================================|" << endl;
        cout << "|---------------------------------------------------|" << endl;
        cout << "|===================================================|" << endl;
        system("pause");
        system("cls");
    }
}

void TambahAmbulans()
{
    if ( FullAmbulans() ){
        cout << "|===================================================|" << endl;
        cout << "|-------------- AMBULANS SUDAH PENUH ---------------|" << endl;
        cout << "|-- ANDA AKAN KEMBALI KE MENU ADMIN DALAM 3 DETIK --|" << endl;
        cout << "|===================================================|" << endl;
        Sleep (3000);
        system("cls");
        MenuAdmin();
    }else{
        DataAmbulans newambulans;
        cin.ignore();
        cout << "|===================================================|" << endl;
        cout << "|------------ MASUKKAN  NAMA AMBULANS --------------|" << endl;
        cout << "|===================================================|" << endl;
        cout << "| Masukkan Nama Ambulans : ";
        getline(cin, newambulans.nama_mobil);
        system("cls");

        tambahAmbulans(newambulans.nama_mobil);
        insertdataambulans(newambulans);

        StackAmbulans(newambulans.nama_mobil);


        cout << "|===================================================|" << endl;
        cout << "|--------  DATA MOBIL BERHASIL DITAMBAHKAN ---------|" << endl;
        cout << "|-- ANDA AKAN KEMBALI  KE MENU USER DALAM 3 DETIK --|" << endl;
        cout << "|===================================================|" << endl;
        Sleep (3000);
        system("cls");
        MenuAdmin();
    }
}

void CariAmbulans()
{
    string nama;
    cout << "|===================================================|" << endl;
    cout << "|------------------ CARI  AMBULANS -----------------|" << endl;
    cout << "|===================================================|" << endl;
    cout << "| Masukkan Nama Ambulans : ";
    cin.ignore();
    getline(cin, nama);
    system("cls");

    Ambulans* hasil = cariAmbulans(nama);
    printAmbulans(hasil);
}

void HapusAmbulansLL(string namaMobil) {

    if (head == nullptr) {
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    // Jika node yang dihapus adalah node pertama
    if (temp->ambulans.nama_mobil == namaMobil) {
        head = temp->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        return;
    }

    // Mencari node yang akan dihapus
    while (temp != nullptr && temp->ambulans.nama_mobil != namaMobil) {
        prev = temp;
        temp = temp->next;
    }

    // Jika node tidak ditemukan
    if (temp == nullptr)
        return;

    // Menghapus node
    prev->next = temp->next;
    if (temp == tail) {
        tail = prev;
    }
    delete temp;
}

void HapusAmbulans()
{
    string nama;
    cout << "|===================================================|" << endl;
    cout << "|------------------ CARI  AMBULANS -----------------|" << endl;
    cout << "|===================================================|" << endl;
    cout << "| Masukkan Nama Ambulans : ";
    cin.ignore();
    getline(cin, nama);
    system("cls");

    if (hapusAmbulans(nama)) {
        cout << "|===================================================|" << endl;
        cout << "|------------ AMBULANS BERHASIL DIHAPUS ------------|" << endl;
        cout << "|----------- KEMBALI KE  MENU SEBELUMNYA -----------|" << endl;
        cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
        cout << "|===================================================|" << endl;
        HapusAmbulansLL(nama);
        PopStackMobil();
        Sleep(3000);
        system("cls");
    } else {
        cout << "|===================================================|" << endl;
        cout << "|------------ AMBULANS  TIDAK DITEMUKAN ------------|" << endl;
        cout << "|----------- KEMBALI KE  MENU SEBELUMNYA -----------|" << endl;
        cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
        cout << "|===================================================|" << endl;
        Sleep(3000);
        system("cls");
    }
}

void MenuPasien()
{
    int pil;
    cout << "|===================================================|" << endl;
    cout << "|------------------ MENU PASIEN --------------------|" << endl;
    cout << "|===================================================|" << endl;
    cout << "| 1. Daftar Pengobatan                              |" << endl;
    cout << "| 2. Lihat Data Akun                                |" << endl;
    cout << "| 3. Lihat Nomor Antrian                            |" << endl;
    cout << "| 4. Lihat Data Pasien                              |" << endl;
    cout << "| 5. Panggil Ambulans                               |" << endl;
    cout << "|                                        KEMBALI .0 |" << endl;
    cout << "|-------------------------------------------------- |" << endl;
    cout << "| Masukkan Pilihan Anda : ";
    cin >> pil;
    system ("cls");

    switch (pil)
    {
        case 1:
            DaftarPengobatan();
            MenuPasien();
            break;
        case 2:
            MenampilkanDataAkun();
            system("pause");
            system("cls");
            MenuPasien();
            break;
        case 3:
            MenampilkanNomorAntrian();
            system("pause");
            system("cls");
            MenuPasien();
            break;
        case 4:
            CariPasien();
            MenuPasien();
            break;
        case 5:
            PanggilAmbulans();
            MenuPasien();
            break;
        case 0:
            cout << "|===================================================|" << endl;
            cout << "|----------- KEMBALI KE  MENU SEBELUMNYA -----------|" << endl;
            cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
            cout << "|===================================================|" << endl;
            Sleep(3000);
            system ("cls");
            main();
        default:
            cout << "|===================================================|" << endl;
            cout << "|------ HARAP MASUKKAN  PILIHAN YANG TERSEDIA ------|" << endl;
            cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
            cout << "|===================================================|" << endl;
            Sleep(3000);
            system ("cls");
            MenuPasien();
    }
}

void MenuAdmin()
{
    int pil;
    cout << "|===================================================|" << endl;
    cout << "|------------------- MENU ADMIN --------------------|" << endl;
    cout << "|===================================================|" << endl;
    cout << "| 1. Mencari Data Pasien                            |" << endl;
    cout << "| 2. Menampilkan Semua Data Pasien                  |" << endl;
    cout << "| 3. Mengedit Data Pasien                           |" << endl;
    cout << "| 4. Menghapus Data Pasien                          |" << endl;
    cout << "| 5. Proses Antrian Poli/Klinik                     |" << endl;
    cout << "| 6. Melihat Daftar Puskesmas                       |" << endl;
    cout << "| 7. Tambah Ambulans                                |" << endl;
    cout << "| 8. Cari Ambulans                                  |" << endl;
    cout << "| 9. Hapus Ambulans                                 |" << endl;
    cout << "|                                        KEMBALI .0 |" << endl;
    cout << "|-------------------------------------------------- |" << endl;
    cout << "| Masukkan Pilihan Anda : ";
    cin >> pil;
    system ("cls");

    switch(pil)
    {
        case 1:
            CariPasien();
            MenuAdmin();
            break;
        case 2:
            TampilkanSemuaDataPasien();
            MenuAdmin();
            break;
        case 3:
            EditPasien();
            MenuAdmin();
            break;
        case 4:
            DeletePasien();
            MenuAdmin();
            break;
        case 5:
            ProsesAntrian();
            MenuAdmin();
            break;
        case 6:
            DisplayPuskesmas();
            MenuAdmin();
            break;
        case 7:
            TambahAmbulans();
            MenuAdmin();
            break;
        case 8:
            CariAmbulans();
            MenuAdmin();
            break;
        case 9:
            HapusAmbulans();
            MenuAdmin();
            break;
        case 0:
            main();
            break;
        default:
            cout << "|===================================================|" << endl;
            cout << "|------ HARAP MASUKKAN  PILIHAN YANG TERSEDIA ------|" << endl;
            cout << "|----------- HARAP TUNGGU  DALAM 3 DETIK -----------|" << endl;
            cout << "|===================================================|" << endl;
            Sleep(3000);
            system ("cls");
            MenuAdmin();
            break;
    }
    
}