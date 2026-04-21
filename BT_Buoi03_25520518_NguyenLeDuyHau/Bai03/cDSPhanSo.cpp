// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2
#include "cDSPhanSo.h"

int cPhanSo::GetMau() const {
    return mau;
}
int UCLN(int a, int b) {
    a = abs(a); b = abs(b);
    while (b) { a %= b; swap(a, b); }
    return a;
}

bool LaNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) if (n % i == 0) return false;
    return true;
}

// --- Lớp cPhanSo ---
cPhanSo::cPhanSo(int t, int m) : tu(t), mau(m == 0 ? 1 : m) {}

void cPhanSo::Nhap() {
    cout << "Nhap tu va mau: ";
    cin >> tu >> mau;
    if (mau == 0) mau = 1;
    RutGon();
}

void cPhanSo::Xuat() {
    if (mau == 1) cout << tu;
    else cout << tu << "/" << mau;
}

void cPhanSo::RutGon() {
    int u = UCLN(tu, mau);
    tu /= u; mau /= u;
    if (mau < 0) { tu = -tu; mau = -mau; }
}

float cPhanSo::GiaTri() const { return (float)tu / mau; }
int cPhanSo::GetTu() const { return tu; }

cPhanSo cPhanSo::operator+(const cPhanSo& other) const {
    cPhanSo res(tu * other.mau + other.tu * mau, mau * other.mau);
    res.RutGon();
    return res;
}

// --- Lớp cDSPhanSo ---
cDSPhanSo::cDSPhanSo() : n(0), ds(nullptr) {}
cDSPhanSo::~cDSPhanSo() { if (ds) delete[] ds; }

void cDSPhanSo::Nhap() {
    cout << "Nhap so luong phan so: "; cin >> n;
    ds = new cPhanSo[n];
    for (int i = 0; i < n; i++) {
        cout << "Phan so thu " << i + 1 << ": ";
        ds[i].Nhap();
    }
}

void cDSPhanSo::Xuat() {
    for (int i = 0; i < n; i++) {
        ds[i].Xuat(); cout << "  ";
    }
    cout << endl;
}

cPhanSo cDSPhanSo::TinhTong() {
    cPhanSo tong(0, 1);
    for (int i = 0; i < n; i++) tong = tong + ds[i];
    return tong;
}

cPhanSo cDSPhanSo::TimMax() {
    cPhanSo maxVal = ds[0];
    for (int i = 1; i < n; i++) if (ds[i].GiaTri() > maxVal.GiaTri()) maxVal = ds[i];
    return maxVal;
}

cPhanSo cDSPhanSo::TimMin() {
    cPhanSo minVal = ds[0];
    for (int i = 1; i < n; i++) if (ds[i].GiaTri() < minVal.GiaTri()) minVal = ds[i];
    return minVal;
}

cPhanSo cDSPhanSo::TuNguyenToLonNhat() {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (LaNguyenTo(ds[i].GetTu())) {
            if (index == -1 || ds[i].GetTu() > ds[index].GetTu()) index = i;
        }
    }
    return (index != -1) ? ds[index] : cPhanSo(0, 0); // Trả về 0 nếu ko tìm thấy
}

void cDSPhanSo::SapXepTang() {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (ds[i].GiaTri() > ds[j].GiaTri()) swap(ds[i], ds[j]);
}

void cDSPhanSo::SapXepGiam() {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (ds[i].GiaTri() < ds[j].GiaTri()) swap(ds[i], ds[j]);
}