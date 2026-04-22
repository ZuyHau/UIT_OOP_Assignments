// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
#include "cNhanVienSX.h"

cNhanVienSX::cNhanVienSX() : soSanPham(0), donGia(0) { ngaySinh = { 1, 1, 1900 }; }
cNhanVienSX::~cNhanVienSX() {}

string cNhanVienSX::GetMaNV() { return maNV; }
double cNhanVienSX::TinhLuong() { return (double)soSanPham * donGia; }
Ngay cNhanVienSX::GetNgaySinh() { return ngaySinh; }

void cNhanVienSX::Nhap() {
    cout << "Nhap Ma NV: "; cin >> maNV;
    cin.ignore();
    cout << "Nhap Ho ten: "; getline(cin, hoTen);
    cout << "Nhap Ngay sinh (d m y): "; cin >> ngaySinh.d >> ngaySinh.m >> ngaySinh.y;
    cout << "Nhap So san pham: "; cin >> soSanPham;
    cout << "Nhap Don gia: "; cin >> donGia;
}

void cNhanVienSX::Xuat() {
    cout << "ID: " << maNV << " | Ten: " << hoTen;
    cout << " | NS: " << ngaySinh.d << "/" << ngaySinh.m << "/" << ngaySinh.y;
    cout << " | Luong: " << (long long)TinhLuong() << " VND" << endl;
}

// --- Xu ly Danh sach ---
cListNhanVienSX::cListNhanVienSX() : n(0), ds(nullptr) {}
cListNhanVienSX::~cListNhanVienSX() { if (ds) delete[] ds; }

void cListNhanVienSX::NhapDS() {
    cout << "Nhap so luong nhan vien san xuat: "; cin >> n;
    ds = new cNhanVienSX[n];
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhan vien thu " << i + 1 << " ---\n";
        ds[i].Nhap();
    }
}

void cListNhanVienSX::XuatDS() {
    for (int i = 0; i < n; i++) ds[i].Xuat();
}

void cListNhanVienSX::TimLuongThapNhat() {
    if (n == 0) return;
    double minL = ds[0].TinhLuong();
    for (int i = 1; i < n; i++) if (ds[i].TinhLuong() < minL) minL = ds[i].TinhLuong();

    cout << "\nNhan vien luong thap nhat (" << (long long)minL << " VND):" << endl;
    for (int i = 0; i < n; i++) if (ds[i].TinhLuong() == minL) ds[i].Xuat();
}

double cListNhanVienSX::TinhTongLuong() {
    double tong = 0;
    for (int i = 0; i < n; i++) tong += ds[i].TinhLuong();
    return tong;
}

void cListNhanVienSX::TimNhanVienGiaNhat() {
    if (n == 0) return;
    cNhanVienSX giaNhat = ds[0];
    for (int i = 1; i < n; i++) {
        Ngay n1 = ds[i].GetNgaySinh();
        Ngay n2 = giaNhat.GetNgaySinh();
        if (n1.y < n2.y || (n1.y == n2.y && n1.m < n2.m) || (n1.y == n2.y && n1.m == n2.m && n1.d < n2.d)) {
            giaNhat = ds[i];
        }
    }
    cout << "\nNhan vien lon tuoi nhat: "; giaNhat.Xuat();
}

void cListNhanVienSX::SapXepTangDanTheoLuong() {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (ds[i].TinhLuong() > ds[j].TinhLuong()) swap(ds[i], ds[j]);
}