// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2
#include "cDaGiac.h"

int main() {
    cDaGiac dg;

    cout << "=== BAI TAP 2: LOP CDAGIAC ===" << endl;
    dg.Nhap();

    cout << "\n--- THONG TIN DA GIAC ---" << endl;
    dg.Xuat();
    cout << "Chu vi: " << dg.TinhChuVi() << endl;
    cout << "Dien tich: " << dg.TinhDienTich() << endl;

    cout << "\n--- THUC HIEN BIEN DOI ---" << endl;
    cout << "1. Tinh tien (2, 3)" << endl;
    dg.TinhTien(2, 3);
    dg.Xuat();

    cout << "2. Quay 45 do" << endl;
    dg.Quay(45);
    dg.Xuat();

    cout << "3. Phong to 2 lan" << endl;
    dg.PhongTo(2);
    dg.Xuat();

    return 0;
}