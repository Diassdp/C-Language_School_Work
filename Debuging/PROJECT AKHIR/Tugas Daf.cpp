#include <iostream>
#include<stdio.h>
using namespace std;

int main(){
    char nama[50];
    int tgl, bln, thn, tglnow, blnnow, thnnow, jam;
    float diskon, total;
    float a, b;
    char ulang;

    awal:
    cout << "\n::::: Point of Sale Suatu Collaborative Space ::::\n"<< endl;
    cout << "Nama Pengguna  : "; cin >> nama;
    cout << "Tanggal Lahir  : "; cin >> tgl;
    cout << "Bulan Lahir    : "; cin >> bln;
    cout << "Tahun Lahir    : "; cin >> thn;
    cout << "-------------------------------"<< endl;
    cout << "Tanggal Kunjungan  : "; cin >> tglnow;
    cout << "Bulan Kunjungan    : "; cin >> blnnow;
    cout << "Tahun Kunjungan    : "; cin >> thnnow;
    cout << "Lama Kunjungan     : "; cin >> jam;

    if (blnnow == bln){
        if (jam > 1){
            a = jam % 3;
            b = (jam - a)/3;
            diskon = b * 10000;
            total = ((jam * 12500) - diskon) + 8000;
        } else{
            a = jam % 3;
            b = (jam - a)/3;
            diskon = b * 10000;
            total = (jam * 12500) - diskon;
        }
    }else{
        if (jam > 1){
            total = jam * 12500 + 8000;
        } else{
            total = 12500;
        }
    }

    cout << "-------------------------------"<< endl;
    cout << "Total Biaya Kunjungan : Rp " << total << endl;
    cout << "Terimakasih!" << endl << endl;

    ulang:
    cout << "Ingin ulang program (y/n) ? "; cin >> ulang;
    if (ulang == 'y' || ulang == 'Y'){
            system("cls");
            goto awal;
    }else if (ulang == 'n' || ulang == 'N'){
            return 0;
    }else{
            goto ulang;
    }
}
