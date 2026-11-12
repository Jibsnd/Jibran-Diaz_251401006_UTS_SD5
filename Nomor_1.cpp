// Buatlah program C++ yang mendeklarasikan array 3 dimensi berukuran
// [2][3][4].
// - Layer pertama diisi dengan barisan bilangan tambah 5 kurang 1, dimulai
// dari 4 (4, 9, 8, 13, …).
// - Layer kedua diisi dengan bilangan kelipatan 4 (4, 8, 12, 16, ...).
// - Yang harus kamu lakukan adalah, hitung rata-rata dari elemen layer
// pertama dan layer keuda pada posisi indeks yang sama, lalu tampilkan
// hasilnya dalam bentuk tabel 2 dimensi bertipe integer (3x4).

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    system("cls");
    int arr[2][3][4];
    
    int nilaiLayer1 = 4;
    int nilaiLayer2 = 4;

    int langkah = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            arr[0][i][j] = nilaiLayer1;
            
            if (langkah % 2 == 0) {
                nilaiLayer1 += 5;
            } else {
                nilaiLayer1 -= 1;
            }
            langkah++;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            arr[1][i][j] = nilaiLayer2;
            nilaiLayer2 += 4;
        }
    }

    cout << "Layer 1 :" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << setw(4) << arr[0][i][j];
        }
        cout << endl;
    }

    cout << "\nIsi Layer 2 :" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << setw(4) << arr[1][i][j];
        }
        cout << endl;
    }

    cout << "\nHasil Rata-Rata :" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            int rataRata = (arr[0][i][j] + arr[1][i][j]) / 2;
            cout << setw(4) << rataRata;
        }
        cout << endl;
    }

    return 0;
}


    