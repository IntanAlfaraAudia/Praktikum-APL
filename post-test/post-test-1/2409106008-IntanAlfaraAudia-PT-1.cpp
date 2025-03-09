#include <iostream>

using namespace std;

int main() { 
    string namaPengguna, nimPengguna;
    int jumlahPercobaan = 0;
    int batasPercobaan = 3;
    bool statusLogin = false;
    
    cout << "==========================================" << endl;
    cout << "|         SELAMAT DATANG DI              |" << endl;
    cout << "|      PROGRAM KONVERSI SATUAN           |" << endl;
    cout << "==========================================" << endl << endl;

    while (jumlahPercobaan  < batasPercobaan) {
        cout << "==========================================" << endl;
        cout << "|             LOGIN DULU GUYS            |" << endl;
        cout << "==========================================" << endl;

        cout << " Masukkan Nama: ";
        getline(cin, namaPengguna); 
    
        cout << " Masukkan NIM: ";
        getline(cin, nimPengguna);
    
        cout << "==========================================" << endl;
        
        if (namaPengguna == "Intan Alfara Audia" && nimPengguna == "2409106008") {
            statusLogin = true;
            cout << "| Hore, Login berhasil! Selamat datang, |" << endl << namaPengguna << "!" << endl << endl;
            break;
        } else {
            cout << "|  Aduh, Login gagal! Silakan coba lagi. |" << endl << endl;
            jumlahPercobaan++;
        }
    }

    if (!statusLogin) {
        cout << "| Huft, Batas login anda habis! Program berhenti.|" << endl;
        cout << "==========================================" << endl;
        return 0;
    }

    int pilihanMenu;
    float nilaiKonversi;

    do {
        cout << "==========================================" << endl;
        cout << "|              MENU KONVERSI            |" << endl;
        cout << "==========================================" << endl;
        cout << "| 1. Meter ke (Centimeter, Mile, Foot)  |" << endl;
        cout << "| 2. Centimeter ke (Meter, Mile, Foot)  |" << endl;
        cout << "| 3. Mile ke (Meter, Centimeter, Foot)  |" << endl;
        cout << "| 4. Foot ke (Meter, Centimeter, Mile)  |" << endl;
        cout << "| 5. Keluar                             |" << endl;
        cout << "==========================================" << endl;
        cout << "| Masukkan pilihan: ";
        cin >> pilihanMenu;
        cout << "==========================================" << endl;
    
        if (pilihanMenu >= 1 && pilihanMenu <= 4) {
            cout << "| Masukkan nilai: ";
            cin >> nilaiKonversi;
            cout << "==========================================" << endl;
            
            cout << "==========================================" << endl;
            cout << "|              HASIL KONVERSI           |" << endl;
            cout << "==========================================" << endl;
            cout << "| Satuan Awal  : " << nilaiKonversi << " " << endl;
            
            switch (pilihanMenu) {
                case 1:
                    cout << "| Centimeter: " << nilaiKonversi * 100 << " cm" << endl;
                    cout << "| Mile: " << nilaiKonversi * 0.000621371 << " mi" << endl;
                    cout << "| Foot: " << nilaiKonversi * 3.28084 << " ft" << endl;
                    break;
                case 2:
                    cout << "| Meter: " << nilaiKonversi / 100 << " m" << endl;
                    cout << "| Mile: " << nilaiKonversi * 0.00000621371 << " mi" << endl;
                    cout << "| Foot: " << nilaiKonversi * 0.0328084 << " ft" << endl;
                    break;
                case 3:
                    cout << "| Meter: " << nilaiKonversi / 0.000621371 << " m" << endl;
                    cout << "| Centimeter: " << (nilaiKonversi / 0.000621371) * 100 << " cm" << endl;
                    cout << "| Foot: " << nilaiKonversi * 5280 << " ft" << endl;
                    break;
                case 4:
                    cout << "| Meter: " << nilaiKonversi / 3.28084 << " m" << endl;
                    cout << "| Centimeter: " << (nilaiKonversi / 3.28084) * 100 << " cm" << endl;
                    cout << "| Mile: " << nilaiKonversi / 5280 << " mi" << endl;
                    break;
                default:
                    cout << "| Pilihan tidak valid!" << endl;
                    break;
            }
            cout << "==========================================" << endl;
        }
    } while (pilihanMenu != 5);
    
    cout << "|  Hore, Program selesai. Terima kasih!  |" << endl;
    cout << "==========================================" << endl;
    return 0;
}