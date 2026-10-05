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

int main() {
    return 0;
}