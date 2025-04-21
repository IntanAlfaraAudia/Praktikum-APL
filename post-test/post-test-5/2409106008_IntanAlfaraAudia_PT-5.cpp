#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 50;

struct ReservasiSpa {
    string namaPelanggan;
    string tanggal;
    string layanan;
};

struct User {
    string namaPengguna;
    string nimPengguna;
    int isAdmin;
    ReservasiSpa daftarReservasi[25];
    int jumlahReservasi;
};

User users[MAX] = { {"Intan Alfara", "008", 1, {}, 0} };
int jumlahUser = 1;

int hitungTotalPelanggan(User* user, int indeks) {
    if (indeks == user->jumlahReservasi) return 0;
    return 1 + hitungTotalPelanggan(user, indeks + 1);
}

int cariReservasi(User* user, string namaPelanggan) {
    for (int i = 0; i < user->jumlahReservasi; i++) {
        if (user->daftarReservasi[i].namaPelanggan == namaPelanggan)
            return i;
    }
    return -1;
}

int cariReservasi(User* user, string namaPelanggan, string tanggal) {
    for (int i = 0; i < user->jumlahReservasi; i++) {
        if (user->daftarReservasi[i].namaPelanggan == namaPelanggan &&
            user->daftarReservasi[i].tanggal == tanggal)
            return i;
    }
    return -1;
}

void tambahReservasi(User* user) {
    if (user->jumlahReservasi >= 25) {
        cout << "Kapasitas reservasi penuh!" << endl;
        return;
    }
    cin.ignore();
    int idx = user->jumlahReservasi;
    cout << "Masukkan Nama Pelanggan: ";
    getline(cin, user->daftarReservasi[idx].namaPelanggan);
    cout << "Masukkan Tanggal (DD/MM/YYYY): ";
    getline(cin, user->daftarReservasi[idx].tanggal);
    cout << "Masukkan Layanan Spa: ";
    getline(cin, user->daftarReservasi[idx].layanan);
    user->jumlahReservasi++;
    cout << "Sip! Reservasimu sudah masuk!" << endl;
}

void tampilData(User* user) {
    if (user->jumlahReservasi == 0) {
        cout << "Belum ada reservasi." << endl;
        return;
    }

    cout << "+----+----------------------+--------------+----------------------+" << endl;
    cout << "| No | Nama Pelanggan       | Tanggal      | Layanan Spa          |" << endl;
    cout << "+----+----------------------+--------------+----------------------+" << endl;

    for (int i = 0; i < user->jumlahReservasi; i++) {
        cout << "| " << setw(2) << i + 1 << " | " << left << setw(20) << user->daftarReservasi[i].namaPelanggan
             << " | " << left << setw(12) << user->daftarReservasi[i].tanggal
             << " | " << left << setw(20) << user->daftarReservasi[i].layanan << " |" << endl;
    }

    cout << "+----+----------------------+--------------+----------------------+" << endl;
}

void ubahReservasi(User* user) {
    tampilData(user);
    if (user->jumlahReservasi == 0) {
        cout << "Tidak ada reservasi untuk diubah." << endl;
        return;
    }

    int ubah;
    cout << "Masukkan nomor reservasi yang ingin diubah: ";
    cin >> ubah;
    cin.ignore();

    if (ubah > 0 && ubah <= user->jumlahReservasi) {
        cout << "Masukkan Nama Baru: ";
        getline(cin, user->daftarReservasi[ubah - 1].namaPelanggan);
        cout << "Masukkan Tanggal Baru (DD/MM/YYYY): ";
        getline(cin, user->daftarReservasi[ubah - 1].tanggal);
        cout << "Masukkan Layanan Spa Baru: ";
        getline(cin, user->daftarReservasi[ubah - 1].layanan);
        cout << "Reservasi berhasil diperbarui!" << endl;
    } else {
        cout << "Nomor reservasi tidak valid." << endl;
    }
}

void hapusReservasi(User* user) {
    tampilData(user);
    if (user->jumlahReservasi == 0) {
        cout << "Tidak ada reservasi untuk dihapus." << endl;
        return;
    }

    int hapus;
    cout << "Masukkan nomor reservasi yang ingin dihapus: ";
    cin >> hapus;

    if (hapus > 0 && hapus <= user->jumlahReservasi) {
        for (int i = hapus - 1; i < user->jumlahReservasi - 1; i++) {
            user->daftarReservasi[i] = user->daftarReservasi[i + 1];
        }
        user->jumlahReservasi--;
        cout << "Reservasi berhasil dihapus." << endl;
    } else {
        cout << "Nomor reservasi tidak valid." << endl;
    }
}

void registrasi() {
    if (jumlahUser >= MAX) {
        cout << "Kapasitas user penuh!" << endl;
        return;
    }
    cin.ignore();
    cout << "Masukkan Nama: ";
    getline(cin, users[jumlahUser].namaPengguna);
    cout << "Masukkan NIM: ";
    getline(cin, users[jumlahUser].nimPengguna);
    users[jumlahUser].isAdmin = 0;
    users[jumlahUser].jumlahReservasi = 0;
    jumlahUser++;
    cout << "Registrasi berhasil! Yuk lanjut login" << endl;
}

int login(string nama, string nim) {
    for (int i = 0; i < jumlahUser; i++) {
        if (users[i].namaPengguna == nama && users[i].nimPengguna == nim) {
            return i;
        }
    }
    return -1;
}

int main() {
    int pilihan;

    cout << "==========================================" << endl;
    cout << "===   SELAMAT DATANG DI RESERVASI SPA  ===" << endl;
    cout << "==========================================" << endl;

    while (true) {
        cout << "\n=====================================" << endl;
        cout << "===           MENU USER           ===" << endl;
        cout << "=====================================" << endl;
        cout << "| 1. Registrasi                     |" << endl;
        cout << "| 2. Login                          |" << endl;
        cout << "| 3. Keluar                         |" << endl;
        cout << "=====================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            registrasi();
        } else if (pilihan == 2) {
            string namaPengguna, nimPengguna;
            int percobaan = 0, loginBerhasil = 0, indexUser = -1;
            cin.ignore();
            while (percobaan < 3) {
                cout << "Masukkan Nama: ";
                getline(cin, namaPengguna);
                cout << "Masukkan NIM: ";
                getline(cin, nimPengguna);

                indexUser = login(namaPengguna, nimPengguna);
                if (indexUser != -1) {
                    cout << "Hore, login berhasil! Selamat datang " << namaPengguna << "!" << endl;
                    cout << "Total pelanggan (reservasi): "
                         << hitungTotalPelanggan(&users[indexUser], 0) << endl;
                    loginBerhasil = 1;
                    break;
                }

                percobaan++;
                cout << "Oops! Nama atau NIM salah. Percobaan ke-" << percobaan << " dari 3." << endl;
            }

            if (!loginBerhasil) {
                cout << "Yah, kamu sudah gagal login 3 kali. Program berhenti." << endl;
                return 0;
            }

            int menuReservasi;
            do {
                cout << "\n==========================================" << endl;
                cout << "===      MANAJEMEN RESERVASI SPA       ===" << endl;
                cout << "==========================================" << endl;
                cout << "| 1. Tambah Reservasi                    |" << endl;
                cout << "| 2. Lihat Reservasi                     |" << endl;
                cout << "| 3. Ubah Reservasi                      |" << endl;
                cout << "| 4. Hapus Reservasi                     |" << endl;
                cout << "| 5. Keluar                              |" << endl;
                cout << "==========================================" << endl;
                cout << "Pilihan: ";
                cin >> menuReservasi;

                switch (menuReservasi) {
                    case 1: tambahReservasi(&users[indexUser]); break;
                    case 2: tampilData(&users[indexUser]); break;
                    case 3: ubahReservasi(&users[indexUser]); break;
                    case 4: hapusReservasi(&users[indexUser]); break;
                    case 5: cout << "Kembali ke menu user!\n"; break;
                    default: cout << "Pilihan tidak valid!" << endl;
                }
            } while (menuReservasi != 5);

        } else if (pilihan == 3) {
            cout << "Bye bye! Terima kasih telah menggunakan layanan kami!" << endl;
            break;
        } else {
            cout << "Eh, pilihannya gak ada nih! Coba lagi ya!" << endl;
        }
    }

    return 0;
}
