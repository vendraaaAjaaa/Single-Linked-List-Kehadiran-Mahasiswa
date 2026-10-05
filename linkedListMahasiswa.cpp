#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    float persentaseKehadiran;
    Mahasiswa* next;
};

Mahasiswa* head = nullptr;


void insertHead(string nim, string nama, float kehadiran) {
    Mahasiswa* baru = new Mahasiswa;

    baru->nim = nim;
    baru->nama = nama;
    baru->persentaseKehadiran = kehadiran;

    baru->next = head;
    head = baru;

    cout << "\nData berhasil ditambahkan di depan.\n";
}

void insertLast(string nim, string nama, float kehadiran) {
    Mahasiswa* baru = new Mahasiswa;

    baru->nim = nim;
    baru->nama = nama;
    baru->persentaseKehadiran = kehadiran;
    baru->next = nullptr;

    // Jika linked list masih kosong
    if (head == nullptr) {
        head = baru;
    } else {
        Mahasiswa* bantu = head;

        // Mencari node paling akhir
        while (bantu->next != nullptr) {
            bantu = bantu->next;
        }

        bantu->next = baru;
    }

    cout << "\nData berhasil ditambahkan di belakang.\n";
}

void deleteHead() {
    if (head == nullptr) {
        cout << "\nLinked List masih kosong.\n";
        return;
    }

    Mahasiswa* hapus = head;

    cout << "\nMahasiswa yang dihapus:\n";
    cout << "NIM  : " << hapus->nim << endl;
    cout << "Nama : " << hapus->nama << endl;

    head = head->next;

    delete hapus;

    cout << "Data paling depan berhasil dihapus.\n";
}

void deleteLast() {
    if (head == nullptr) {
        cout << "\nLinked List masih kosong.\n";
        return;
    }

    // Jika hanya ada satu node
    if (head->next == nullptr) {
        cout << "\nMahasiswa yang dihapus:\n";
        cout << "NIM  : " << head->nim << endl;
        cout << "Nama : " << head->nama << endl;

        delete head;
        head = nullptr;

        cout << "Data paling belakang berhasil dihapus.\n";
        return;
    }

    Mahasiswa* bantu = head;

    // Berhenti di node sebelum node terakhir
    while (bantu->next->next != nullptr) {
        bantu = bantu->next;
    }

    Mahasiswa* hapus = bantu->next;

    cout << "\nMahasiswa yang dihapus:\n";
    cout << "NIM  : " << hapus->nim << endl;
    cout << "Nama : " << hapus->nama << endl;

    bantu->next = nullptr;

    delete hapus;

    cout << "Data paling belakang berhasil dihapus.\n";
}

void isiDataAwal() {
    insertLast("103032500005", "Fadhil Asyam Damanik", 100);
    insertLast("103032500041", "Rahsya Iman Dehavilland", 100);
    insertLast("103032500146", "Mahesa Putra Mulyawan", 100);
    insertLast("103032500149", "Gyio Rangga Satria Putra", 100);
    insertLast("103032500150", "Naufal Nafiz Faturrahman", 100);
    insertLast("103032500153", "Fazli Baktiadi", 100);
    insertLast("103032500159", "Matthew Glen Abram Pakpahan", 100);
    insertLast("103032500176", "Vendra Fausta Andrean", 100);
    insertLast("103032500180", "Dzaky Allam Shidiq", 100);
    insertLast("103032500191", "Nayla Novtiera Anjani", 100);
    insertLast("103032540001", "Fathin Arib Nurhumam", 100);
    insertLast("103032540002", "Ida Bagus Harell", 100);
    insertLast("103032540003", "Nigel William Pieters", 100);
    insertLast("103032540004", "Aqila Fathatulayya", 100);
    insertLast("103032540005", "Badriah Nuraini Rahayu", 100);
}

int main() {
    int pilihan;

    string nim;
    string nama;
    float kehadiran;

    isiDataAwal();

    do {
        cout << "\n=====================================\n";
        cout << " SINGLE LINKED LIST KEHADIRAN\n";
        cout << "=====================================\n";
        cout << "1. Tampilkan daftar mahasiswa\n";
        cout << "2. Insert Head\n";
        cout << "3. Insert Last\n";
        cout << "4. Delete Head\n";
        cout << "5. Delete Last\n";
        cout << "0. Keluar\n";
        cout << "=====================================\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                cetakDaftar();
                break;

            case 2:
                cout << "\n--- INSERT HEAD ---\n";

                cout << "Masukkan NIM               : ";
                cin >> nim;

                cin.ignore();

                cout << "Masukkan Nama              : ";
                getline(cin, nama);

                cout << "Persentase Kehadiran (%)   : ";
                cin >> kehadiran;

                insertHead(nim, nama, kehadiran);
                break;

            case 3:
                cout << "\n--- INSERT LAST ---\n";

                cout << "Masukkan NIM               : ";
                cin >> nim;

                cin.ignore();

                cout << "Masukkan Nama              : ";
                getline(cin, nama);

                cout << "Persentase Kehadiran (%)   : ";
                cin >> kehadiran;

                insertLast(nim, nama, kehadiran);
                break;

            case 4:
                deleteHead();
                break;

            case 5:
                deleteLast();
                break;

            case 0:
                cout << "\nProgram selesai.\n";
                break;

            default:
                cout << "\nPilihan tidak tersedia.\n";
        }

    } while (pilihan != 0);

    return 0;
}

int main() {
    return 0;
}