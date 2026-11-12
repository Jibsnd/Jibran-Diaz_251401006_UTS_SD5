// Buatlah program C++ untuk mendata Nama Player Mobile Legends.
// Setiap node dalam Linked List harus menyimpan dua tipe data:
// Username(String) dan Bintang Mythic(int). Buatlah menu pilihan untuk:
// - Tambah data di akhir (Insert tail)
// - Hapus data paling depan (Delete head)
// - Hapus data paling belakang (Delete tail)
// - Tampilkan, hanya User dengan bintang ≥ 100 (Yang Imo Imo aja)
// Program hanya akan memberikan output jika user memilih menu 4 (Tampilkan,
// hanya User dengan bintang ≥ 100 (Yang Imo Imo aja)). Yang ditampilkan
// adalah Username dan jumlah bintang-nya.

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string username;
    int bintang;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void insertTail(string username, int bintang) {
    Node* newNode = new Node;
    newNode->username = username;
    newNode->bintang = bintang;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteHead() {
    if (head == NULL) {
        return;
    }
    Node* temp = head;
    if (head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        head = head->next;
    }
    delete temp;
}

void deleteTail() {
    if (head == NULL) {
        return;
    }
    if (head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = NULL;
}

void tampilkanImo() {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->bintang >= 100) {
            cout << temp->username << " - " << temp->bintang << " Bintang" << endl;
        }
        temp = temp->next;
    }
}

int main() {
    int pilihan;
    string username;
    int bintang;

    do {
        cout << "Data Player Mobile Legend" << endl;
        cout << "1. Tambah data di akhir (Insert tail)" << endl;
        cout << "2. Hapus data paling depan (Delete head)" << endl;
        cout << "3. Hapus data paling belakang (Delete tail)" << endl;
        cout << "4. Menampilkan User dengan bintang >= 100 [ Immortal Only >:) ]" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cin.ignore();
                getline(cin, username);
                cin >> bintang;
                insertTail(username, bintang);
                break;
            case 2:
                deleteHead();
                break;
            case 3:
                deleteTail();
                break;
            case 4:
                tampilkanImo();
                break;
            case 5:
                break;
            default:
                break;
        }
    } while (pilihan != 5);

    return 0;
}
