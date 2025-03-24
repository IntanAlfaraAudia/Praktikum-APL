#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX 25
#define INFO 3

int main() {
string reservasi[MAX][INFO]; 
string namaPengguna, nimPengguna;
int percobaan = 0, pilihan, jumlah = 0;

cout << "==========================================" << endl;
cout << "|           SELAMAT DATANG DI            |" << endl;
cout << "|        MANAJEMEN RESERVASI SPA         |" << endl;
cout << "==========================================" << endl << endl;

    while (percobaan < 3) {
        cout << "==========================================" << endl;
        cout << "|            LOGIN DULU GUYS             |" << endl;
        cout << "==========================================" << endl;

        cout << " Masukkan Nama: ";
        getline(cin, namaPengguna);
    
        cout << " Masukkan NIM: ";
        getline(cin, nimPengguna);
    
        cout << "==========================================" << endl;
        
        if (namaPengguna == "Intan Alfara Audia" && nimPengguna == "008") {
            cout << "Hore, Login berhasil! Selamat datang " << namaPengguna << "!" << endl << endl;
            break;
        } else {
            percobaan++;
            cout << "Gagal login. Nama atau NIM salah. Percobaan ke-" << percobaan << " dari 3." << endl;
        }
    
         (percobaan == 3) {
            cout << "Anda telah login 3 kali. Program berhenti." << endl;
            return 0;
        }
    }

    do {
        cout << "==========================================" << endl;
        cout << "===       MANAJEMEN RESERVASI SPA      ===" << endl;
        cout << "==========================================" << endl;
        cout << "| 1. Tambah Reservasi                    |" << endl;
        cout << "| 2. Lihat Reservasi                     |" << endl;
        cout << "| 3. Ubah Reservasi                      |" << endl;
        cout << "| 4. Hapus Reservasi                     |" << endl;
        cout << "| 5. Keluar                              |" << endl;
        cout << "==========================================" << endl;
        cout << " Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                if (jumlah < MAX) {
                    cout << "Masukkan Nama Pelanggan: ";
                    getline(cin, reservasi[jumlah][0]);
                    cout << "Masukkan Tanggal Reservasi (DD/MM/YYYY): ";
                    getline(cin, reservasi[jumlah][1]);
                    cout << "Masukkan Layanan Spa: ";
                    getline(cin, reservasi[jumlah][2]);
                    jumlah++;
                    cout << "Reservasi berhasil ditambahkan!" << endl;
                } else {
                    cout << "Kapasitas reservasi penuh!" << endl;
                }
                break;
            case 2:
                if (jumlah == 0) {
                    cout << "Tidak ada reservasi saat ini." << endl;
                } else {
                    cout << "\nDaftar Reservasi:" << endl;
                    cout << "+----+----------------------+--------------+----------------------+" << endl;
                    cout << "| No | Nama Pelanggan       | Tanggal       | Layanan Spa         |" << endl;
                    cout << "+----+----------------------+--------------+----------------------+" << endl;
                    for (int i = 0; i < jumlah; i++) {
                        cout << "| " << setw(2) << i+1 << " | " << left << setw(20) << reservasi[i][0]
                        << " | " << left << setw(12) << reservasi[i][1]
                        << " | " << left << setw(20) << reservasi[i][2] << " |" << endl;
                    }
                    cout << "+----+----------------------+--------------+----------------------+" << endl;
                }
                break;
            case 3:
                int ubah;
                if (jumlah == 0) {
                    cout << "Tidak ada reservasi untuk diubah." << endl;
                } else {
                    cout << "Masukkan nomor reservasi yang ingin diubah: ";
                    cin >> ubah;
                    cin.ignore();
                    if (ubah > 0 && ubah <= jumlah) {
                        cout << "Masukkan Nama Baru: ";
                        getline(cin, reservasi[ubah - 1][0]);
                        cout << "Masukkan Tanggal Baru (DD/MM/YYYY): ";
                        getline(cin, reservasi[ubah - 1][1]);
                        cout << "Masukkan Layanan Spa Baru: ";
                        getline(cin, reservasi[ubah - 1][2]);
                        cout << "Reservasi berhasil diperbarui!" << endl;
                    } else {
                        cout << "Nomor reservasi tidak valid." << endl;
                    }
                }
                break;
            case 4:
                int hapus;
                if (jumlah == 0) {
                    cout << "Tidak ada reservasi untuk dihapus." << endl;
                } else {
                    cout << "Masukkan nomor reservasi yang ingin dihapus: ";
                    cin >> hapus;
                    if (hapus > 0 && hapus <= jumlah) {
                        for (int i = hapus - 1; i < jumlah - 1; i++) {
                            reservasi[i][0] = reservasi[i + 1][0];
                            reservasi[i][1] = reservasi[i + 1][1];
                            reservasi[i][2] = reservasi[i + 1][2];
                        }
                        jumlah--;
                        cout << "Reservasi berhasil dihapus." << endl;
                    } else {
                        cout << "Nomor reservasi tidak valid." << endl;
                    }
                }
                break;
            case 5:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (pilihan != 5);
    cout << "==========================================" << endl;
    cout << "|  Hore, Program selesai. Terima kasih!  |" << endl;
    cout << "==========================================" << endl;
    return 0;
}
