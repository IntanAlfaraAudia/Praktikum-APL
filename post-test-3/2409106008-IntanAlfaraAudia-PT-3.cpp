#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX 25

struct User {
    string nama;
    string nim;
};

struct Reservasi {
    string namaPelanggan;
    string tanggal;
    string layanan;
};

User users[MAX] = {{"Intan Alfara", "008"}};
int jumlahUser = 1;

Reservasi daftarReservasi[MAX];
int jumlahReservasi = 0;

int main() {
    int pilihan;
    
    cout << "==========================================" << endl;
    cout << "===   SELAMAT DATANG DI RESERVASI SPA  ===" << endl;
    cout << "==========================================" << endl << endl;

    do {
        cout << "=====================================" << endl;
        cout << "===           MENU USER           ===" << endl;
        cout << "=====================================" << endl;
        cout << "| 1. Registrasi                     |" << endl;
        cout << "| 2. Login                          |" << endl;
        cout << "| 3. Keluar                         |" << endl;
        cout << "=====================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore(); 

        if (pilihan == 1) {
            if (jumlahUser < MAX) {
                cout << "=====================================" << endl;
                cout << "==           REGISTRASI            ==" << endl;
                cout << "=====================================" << endl;
                cout << "Masukkan Nama: ";
                getline(cin, users[jumlahUser].nama);
                cout << "Masukkan NIM: ";
                getline(cin, users[jumlahUser].nim);
                jumlahUser++;
                cout << "Registrasi berhasil! Yuk, lanjut " << endl;
            } else {
                cout << "Kapasitas user penuh!" << endl;
            }
        } else if (pilihan == 2) {
            cout << "=====================================" << endl;
            cout << "==             LOGIN               ==" << endl;
            cout << "=====================================" << endl;
            string namaPengguna, nimPengguna;
            int percobaan = 0, loginBerhasil = 0;

            while (percobaan < 3) {
                cout << "Masukkan Nama: ";
                getline(cin, namaPengguna);
                cout << "Masukkan NIM: ";
                getline(cin, nimPengguna);

                for (int i = 0; i < jumlahUser; i++) {
                    if (users[i].nama == namaPengguna && users[i].nim == nimPengguna) {
                        cout << "Hore, Login berhasil! Selamat datang " << namaPengguna << "!" << endl;
                        loginBerhasil = 1;
                        break;
                    }
                }

                if (loginBerhasil) break;

                percobaan++;
                cout << "Oops! Nama atau NIM salah. Percobaan ke-" << percobaan << " dari 3." << endl;
            }

            if (percobaan == 3) {
                cout << "Yah, kamu sudah gagal login 3 kali. Program berhenti." << endl;
                return 0;
            }

            do {
                cout << "==========================================" << endl;
                cout << "===      MANAJEMEN RESERVASI SPA       ===" << endl;
                cout << "==========================================" << endl;
                cout << "| 1. Tambah Reservasi                    |" << endl;
                cout << "| 2. Lihat Reservasi                     |" << endl;
                cout << "| 3. Ubah Reservasi                      |" << endl;
                cout << "| 4. Hapus Reservasi                     |" << endl;
                cout << "| 5. Keluar                              |" << endl;
                cout << "==========================================" << endl;
                cout << "Pilihan: ";
                cin >> pilihan;
                cin.ignore();

                if (pilihan == 1) {
                    if (jumlahReservasi < MAX) {
                        cout << "Masukkan Nama Pelanggan: ";
                        getline(cin, daftarReservasi[jumlahReservasi].namaPelanggan);
                        cout << "Masukkan Tanggal (DD/MM/YYYY): ";
                        getline(cin, daftarReservasi[jumlahReservasi].tanggal);
                        cout << "Masukkan Layanan Spa: ";
                        getline(cin, daftarReservasi[jumlahReservasi].layanan);
                        jumlahReservasi++;
                        cout << "Sip! Reservasimu sudah masuk!" << endl;
                    } else {
                        cout << "Kapasitas reservasi penuh!" << endl;
                    }
                } else if (pilihan == 2) {
                    if (jumlahReservasi == 0) {
                        cout << "Belum ada reservasi." << endl;
                    } else {
                        cout << "+----+----------------------+--------------+----------------------+" << endl;
                        cout << "| No | Nama Pelanggan       | Tanggal      | Layanan Spa         |" << endl;
                        cout << "+----+----------------------+--------------+----------------------+" << endl;
                        for (int i = 0; i < jumlahReservasi; i++) {
                            cout << "| " << setw(2) << i + 1 << " | " << left << setw(20) << daftarReservasi[i].namaPelanggan
                                 << " | " << left << setw(12) << daftarReservasi[i].tanggal
                                 << " | " << left << setw(20) << daftarReservasi[i].layanan << " |" << endl;
                        }
                        cout << "+----+----------------------+--------------+----------------------+" << endl;
                    }
                } else if (pilihan == 3) {
                    int ubah;
                    if (jumlahReservasi == 0) {
                        cout << "Tidak ada reservasi untuk diubah." << endl;
                    } else {
                        cout << "Masukkan nomor reservasi yang ingin diubah: ";
                        cin >> ubah;
                        cin.ignore();

                        if (ubah > 0 && ubah <= jumlahReservasi) {
                            cout << "Masukkan Nama Baru: ";
                            getline(cin, daftarReservasi[ubah - 1].namaPelanggan);
                            cout << "Masukkan Tanggal Baru (DD/MM/YYYY): ";
                            getline(cin, daftarReservasi[ubah - 1].tanggal);
                            cout << "Masukkan Layanan Spa Baru: ";
                            getline(cin, daftarReservasi[ubah - 1].layanan);
                            cout << "Reservasi berhasil diperbarui!" << endl;
                        } else {
                            cout << "Nomor reservasi tidak valid." << endl;
                        }
                    }
                } else if (pilihan == 4) {
                    int hapus;
                    if (jumlahReservasi == 0) {
                        cout << "Tidak ada reservasi untuk dihapus." << endl;
                    } else {
                        cout << "Masukkan nomor reservasi yang ingin dihapus: ";
                        cin >> hapus;

                        if (hapus > 0 && hapus <= jumlahReservasi) {
                            for (int i = hapus - 1; i < jumlahReservasi - 1; i++) {
                                daftarReservasi[i] = daftarReservasi[i + 1];
                            }
                            jumlahReservasi--;
                            cout << "Reservasi berhasil dihapus." << endl;
                        } else {
                            cout << "Nomor reservasi tidak valid." << endl;
                        }
                    }
                } else if (pilihan == 5) {
                    cout << "Kembali ke menu user!" << endl;
                    break; 
                } else {
                    cout << "Eh, pilihannya gak ada nih! Coba lagi ya!" << endl;
                }
            } while (true);
        } else if (pilihan == 3) {
            cout << "Bye bye! Terima kasih telah menggunakan layanan kami!" << endl;
            break; 
        } else {
            cout << "Eh, pilihannya gak ada nih! Coba lagi ya!" << endl;
        }
    } while (true);

    return 0;
}
