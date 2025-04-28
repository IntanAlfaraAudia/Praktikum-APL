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

void bubbleSortNamaDescending(User* user) {
    for (int i = 0; i < user->jumlahReservasi - 1; i++) {
        for (int j = 0; j < user->jumlahReservasi - i - 1; j++) {
            if (user->daftarReservasi[j].namaPelanggan < user->daftarReservasi[j + 1].namaPelanggan) {
                swap(user->daftarReservasi[j], user->daftarReservasi[j + 1]);
            }
        }
    }
}

void merge(ReservasiSpa arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    ReservasiSpa L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].tanggal <= R[j].tanggal) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortTanggal(ReservasiSpa arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortTanggal(arr, l, m);
        mergeSortTanggal(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void selectionSortNamaAscending(User* user) {
    for (int i = 0; i < user->jumlahReservasi - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < user->jumlahReservasi; j++) {
            if (user->daftarReservasi[j].namaPelanggan < user->daftarReservasi[min_idx].namaPelanggan) {
                min_idx = j;
            }
        }
        swap(user->daftarReservasi[min_idx], user->daftarReservasi[i]);
    }
}

void selectionSortLayananAscending(User* user) {
    for (int i = 0; i < user->jumlahReservasi - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < user->jumlahReservasi; j++) {
            if (user->daftarReservasi[j].layanan < user->daftarReservasi[min_idx].layanan) {
                min_idx = j;
            }
        }
        swap(user->daftarReservasi[min_idx], user->daftarReservasi[i]);
    }
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

    int pilihanSort;
    cout << "\nPilihan urutan data:\n";
    cout << "1. Urutkan Nama Pelanggan Descending (Bubble Sort)\n";
    cout << "2. Urutkan Tanggal Ascending (Merge Sort)\n";
    cout << "3. Urutkan Layanan Spa Ascending (Selection Sort)\n";
    cout << "Pilih metode sorting (1/2/3): ";
    cin >> pilihanSort;

    switch (pilihanSort) {
        case 1: bubbleSortNamaDescending(user); break;
        case 2: mergeSortTanggal(user->daftarReservasi, 0, user->jumlahReservasi - 1); break;
        case 3: selectionSortLayananAscending(user); break;
        default: cout << "Pilihan tidak valid! Data tidak diurutkan.\n"; break;
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

// Ubah Reservasi
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

// Hapus Reservasi
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

// Registrasi
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

// Login
int login(string nama, string nim) {
    for (int i = 0; i < jumlahUser; i++) {
        if (users[i].namaPengguna == nama && users[i].nimPengguna == nim) {
            return i;
        }
    }
    return -1;
}

// Main Program
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
                    loginBerhasil = 1;
                    break;
                }
                percobaan++;
                cout << "Nama/NIM salah, coba lagi!" << endl;
            }

            if (loginBerhasil == 1) {
                while (true) {
                    cout << "\n=====================================" << endl;
                    cout << "===           MENU SPA           ===" << endl;
                    cout << "=====================================" << endl;
                    cout << "| 1. Tambah Reservasi              |" << endl;
                    cout << "| 2. Tampilkan Data Reservasi      |" << endl;
                    cout << "| 3. Ubah Reservasi                |" << endl;
                    cout << "| 4. Hapus Reservasi               |" << endl;
                    cout << "| 5. Keluar                        |" << endl;
                    cout << "=====================================" << endl;
                    cout << "Pilihan: ";
                    cin >> pilihan;

                    if (pilihan == 1) {
                        tambahReservasi(&users[indexUser]);
                    } else if (pilihan == 2) {
                        tampilData(&users[indexUser]);
                    } else if (pilihan == 3) {
                        ubahReservasi(&users[indexUser]);
                    } else if (pilihan == 4) {
                        hapusReservasi(&users[indexUser]);
                    } else if (pilihan == 5) {
                        break;
                    }
                }
            } else {
                cout << "Login gagal setelah 3 kali percobaan." << endl;
            }
        } else if (pilihan == 3) {
            break;
        }
    }

    return 0;
}
