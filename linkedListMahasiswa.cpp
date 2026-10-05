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


int main() {
    return 0;
}