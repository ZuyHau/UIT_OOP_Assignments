// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2
#include "cTamGiac.h"

int main() {
    cTamGiac tg;
    cout << "=== BAI TAP 1: LOP CTAMGIAC ===\n";
    tg.Nhap();

    cout << "\n--- Thong tin ban dau ---\n";
    tg.Xuat();
    cout << "Loai: " << tg.PhanLoai() << endl;
    cout << "Chu vi: " << tg.TinhChuVi() << endl;
    cout << "Dien tich: " << tg.TinhDienTich() << endl;

    cout << "\n--- Thuc hien Phong to 2 lan ---\n";
    tg.PhongTo(2);
    tg.Xuat();

    cout << "\n--- Thuc hien Thu nho 4 lan ---\n";
    tg.ThuNho(4);
    tg.Xuat();

    cout << "\n--- Thuc hien Tinh tien (2, 3) ---\n";
    tg.TinhTien(2, 3);
    tg.Xuat();

    return 0;
}