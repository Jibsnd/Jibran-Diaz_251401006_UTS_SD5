// Buatlah program pembentuk Binary Search Tree dinamis dengan aturan:
// - Angka pertama menjadi root.
// - Angka lebih kecil ke kiri, lebih besar ke kanan.
// - Input berhenti saat memasukkan angka 0.
// Setelah Tree terbentuk, tampilkan traversal In-Order (Kiri-Akar-Kanan). Lalu,
// tambahkan kode untuk mencari dan mencetak Nilai Terbesar di dalam tree tersebut
// tanpa harus membaca ulang data, beserta menampilkan nilai dari Root. (Clue:
// Manfaatkan pointer yang ditelusuri terus ke kanan mentok untuk mencari nilai
// terbesar).

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

Node* akar = NULL;

void addNode (Node** akar, int isi){
    if (*akar == NULL)  {
        Node* baru = new Node;
        baru->data = isi;
        baru->kiri = NULL;
        baru->kanan = NULL;
        *akar = baru;
    }
}

void preOrder (Node* akar)  {
    if (akar != NULL) {
        cout << akar->data << " ";
        preOrder (akar->kiri);
        preOrder (akar->kanan);
    }
}

void inOrder (Node* akar)  {
    if (akar != NULL) {
        preOrder (akar->kiri);
        cout << akar->data << " ";
        preOrder (akar->kanan);
    }
}

void postOrder (Node* akar)  {
    if (akar != NULL) {
        preOrder (akar->kiri);
        preOrder (akar->kanan);
        cout << akar->data << " ";
    }
}

int main () {
    system("cls");

    cout << "\n\n\tPosisi Awal Tree:\n\n";

    cout << "\t        15\n";
    cout << "\t       /  \\\n";
    cout << "\t      27   30\n";
    cout << "\t      / \\\n";
    cout << "\t     25  29\n\n";

    addNode (&akar, 15);
    addNode (&akar->kiri, 27);
    addNode (&akar->kanan, 30);
    addNode (&akar->kiri->kiri, 25);
    addNode (&akar->kiri->kanan, 29);

    cout << "Tampilan PreOrder : ";
    preOrder(akar);

    cout << "\nTampilan InOrder : ";
    inOrder(akar);
    
    cout << "\nTampilan PostOrder : ";
    postOrder(akar);

    return 0;
}

//Maaf bang untuk materi yang ini saya kurang belajar ;(