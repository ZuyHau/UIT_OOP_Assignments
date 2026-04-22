// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2
#include "cNhanVienVP.h"

cNhanVienVP::cNhanVienVP() : luong(0) { ngaySinh = { 1, 1, 1900 }; }
cNhanVienVP::~cNhanVienVP() {}

// Getter/Setter
string cNhanVienVP::GetMaNV() { return maNV; }
void cNhanVienVP::SetMaNV(string ma) { maNV = ma; }
double cNhanVienVP::GetLuong() { return luong; }
void cNhanVienVP::SetLuong(double l) { luong = l; }
Ngay cNhanVienVP::GetNgaySinh() { return ngaySinh; }

void cNhanVienVP::Nhap() {
    cout << "Nhap Ma NV: "; cin >> maNV;
    cin.ignore();
    cout << "Nhap Ho ten: "; getline(cin, hoTen);
    cout << "Nhap Ngay sinh (d m y): "; cin >> ngaySinh.d >> ngaySinh.m >> ngaySinh.y;
    cout << "Nhap Luong: "; cin >> luong;
}

void cNhanVienVP::Xuat() {
    cout << "ID: " << maNV << " | Ten: " << hoTen;
    cout << " | NS: " << ngaySinh.d << "/" << ngaySinh.m << "/" << ngaySinh.y;
    cout << " | Luong: " << (long long)luong << " VND" << endl;
}

// --- Xu ly Danh sach ---
cListNhanVien::cListNhanVien() : n(0), ds(nullptr) {}
cListNhanVien::~cListNhanVien() { if (ds) delete[] ds; }

void cListNhanVien::NhapDS() {
    cout << "Nhap so luong nhan vien: "; cin >> n;
    ds = new cNhanVienVP[n];
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhan vien thu " << i + 1 << " ---\n";
        ds[i].Nhap();
    }
}

void cListNhanVien::XuatDS() {
    for (int i = 0; i < n; i++) ds[i].Xuat();
}

void cListNhanVien::TimLuongCaoNhat() {
    if (n == 0) return;
    double maxL = ds[0].GetLuong();
    for (int i = 1; i < n; i++) if (ds[i].GetLuong() > maxL) maxL = ds[i].GetLuong();

    cout << "\nNhan vien co luong cao nhat (" << (long long)maxL << " VND):" << endl;
    for (int i = 0; i < n; i++) if (ds[i].GetLuong() == maxL) ds[i].Xuat();
}

double cListNhanVien::TinhTongLuong() {
    double tong = 0;
    for (int i = 0; i < n; i++) tong += ds[i].GetLuong();
    return tong;
}

void cListNhanVien::TimNhanVienGiaNhat() {
    if (n == 0) return;
    cNhanVienVP giaNhat = ds[0];
    for (int i = 1; i < n; i++) {
        Ngay n1 = ds[i].GetNgaySinh();
        Ngay n2 = giaNhat.GetNgaySinh();
        // So sánh năm -> tháng -> ngày (năm càng nhỏ càng già)
        if (n1.y < n2.y || (n1.y == n2.y && n1.m < n2.m) || (n1.y == n2.y && n1.m == n2.m && n1.d < n2.d)) {
            giaNhat = ds[i];
        }
    }
    cout << "\nNhan vien lon tuoi nhat: "; giaNhat.Xuat();
}

void cListNhanVien::SapXepTangDanTheoLuong() {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (ds[i].GetLuong() > ds[j].GetLuong()) swap(ds[i], ds[j]);
}