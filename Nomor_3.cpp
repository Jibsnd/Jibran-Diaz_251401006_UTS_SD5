// Buatlah program C++ menggunakan struktur Stack berbasis Array murni
// untuk membalikkan kata sekaligus mengubah format hurufnya (Kapitalisasi
// Terbalik).
// Alur program:
// - User memasukkan sebuah kata (direkomendasikan tanpa spasi)
// - Masukkan (push) setiap huruf dari kata tersebut ke dalam Stack.
// - Keluarkan (pop) huruf dari Stack satu per satu. Saat dikeluarkan, ubah
// huruf kecil tersebut menjadi huruf kapital (bisa menggunakan manipulasi ASCII atau fungsi bawaan (toupper)), lalu cetak ke layar sehingga
// membentuk kata kapital yang terbalik.

#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

const int MAX_SIZE = 100;

struct CharStack {
    char data[MAX_SIZE];
    int top;

    void init() {
        top = -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(char c) {
        if (isFull()) {
            cout << "Stack penuh'" << c << "' tidak dapat dimasukkan." << endl;
            return;
        }
        top++;
        data[top] = c;
    }

    char pop() {
        if (isEmpty()) {
            return '\0';
        }
        char poppedChar = data[top];
        top--;
        return poppedChar;
    }
};

int main() {
    system("cls");
    CharStack s;
    s.init(); 

    string inputKata;

    cout << "Masukkan kalimat (tidak boleh spasi): ";
    cin >> inputKata;

    for (int i = 0; i < inputKata.length(); i++) {
        s.push(inputKata[i]);
    }

    cout << "Hasil : ";
    while (!s.isEmpty()) {
        char huruf = s.pop();
        
        char hurufKapital = toupper(huruf);
        
        cout << hurufKapital;
    }
    cout << endl;

    return 0;
}
