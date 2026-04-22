// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2
#include "cDaThuc.h"

cDaThuc::cDaThuc(int bac) {
    n = bac;
    a = new float[n + 1];
    for (int i = 0; i <= n; i++) a[i] = 0;
}

cDaThuc::cDaThuc(const cDaThuc& other) {
    n = other.n;
    a = new float[n + 1];
    for (int i = 0; i <= n; i++) a[i] = other.a[i];
}

cDaThuc::~cDaThuc() {
    if (a) delete[] a;
}

cDaThuc& cDaThuc::operator=(const cDaThuc& other) {
    if (this != &other) {
        delete[] a;
        n = other.n;
        a = new float[n + 1];
        for (int i = 0; i <= n; i++) a[i] = other.a[i];
    }
    return *this;
}

void cDaThuc::Nhap() {
    cout << "Nhap bac cua da thuc: "; cin >> n;
    if (a) delete[] a;
    a = new float[n + 1];
    for (int i = n; i >= 0; i--) {
        cout << "Nhap he so cua X^" << i << ": ";
        cin >> a[i];
    }
}

void cDaThuc::Xuat() {
    bool first = true;
    for (int i = n; i >= 0; i--) {
        if (a[i] == 0) continue;
        if (!first && a[i] > 0) cout << " + ";
        if (a[i] < 0) cout << " - ";

        float val = abs(a[i]);
        if (val != 1 || i == 0) cout << val;

        if (i > 0) cout << "X";
        if (i > 1) cout << "^" << i;
        first = false;
    }
    if (first) cout << "0";
    cout << endl;
}

float cDaThuc::TinhGiaTri(float x) {
    float res = 0;
    for (int i = 0; i <= n; i++) {
        res += a[i] * pow(x, i);
    }
    return res;
}

cDaThuc cDaThuc::operator+(const cDaThuc& other) {
    int maxBac = max(n, other.n);
    cDaThuc res(maxBac);
    for (int i = 0; i <= maxBac; i++) {
        float h1 = (i <= n) ? a[i] : 0;
        float h2 = (i <= other.n) ? other.a[i] : 0;
        res.a[i] = h1 + h2;
    }
    return res;
}

cDaThuc cDaThuc::operator-(const cDaThuc& other) {
    int maxBac = max(n, other.n);
    cDaThuc res(maxBac);
    for (int i = 0; i <= maxBac; i++) {
        float h1 = (i <= n) ? a[i] : 0;
        float h2 = (i <= other.n) ? other.a[i] : 0;
        res.a[i] = h1 - h2;
    }
    return res;
}