// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
#include "cArray.h"

cArray::cArray() { n = 0; a = nullptr; }

cArray::~cArray() { if (a) delete[] a; }

bool LaNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) if (n % i == 0) return false;
    return true;
}

void cArray::TaoNgauNhien(int size) {
    n = size;
    if (a) delete[] a;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100; // Ngẫu nhiên từ 0-99 cho dễ nhìn
    }
}

void cArray::Xuat() {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int cArray::DemX(int x) {
    int count = 0;
    for (int i = 0; i < n; i++) if (a[i] == x) count++;
    return count;
}

bool cArray::KiemTraTangDan() {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}

int cArray::TimLeNhoNhat() {
    int minLe = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0 && a[i] < minLe) minLe = a[i];
    }
    return (minLe == INT_MAX) ? -1 : minLe; // Trả về -1 nếu ko có số lẻ
}

int cArray::TimNguyenToLonNhat() {
    int maxNT = -1;
    for (int i = 0; i < n; i++) {
        if (LaNguyenTo(a[i]) && a[i] > maxNT) maxNT = a[i];
    }
    return maxNT;
}

void cArray::SapXepTang() {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[minIdx]) minIdx = j;
        swap(a[i], a[minIdx]);
    }
}

void cArray::SapXepGiam() {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] > a[maxIdx]) maxIdx = j;
        swap(a[i], a[maxIdx]);
    }
}