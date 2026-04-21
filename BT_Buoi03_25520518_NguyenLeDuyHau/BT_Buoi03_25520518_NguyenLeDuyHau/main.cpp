// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2
#include "cTamGiac.h"

int main() {
    cTamGiac tg;

    cout << "=== BAI TAP 1: LOP CTAMGIAC ===" << endl;
    tg.Nhap();

    cout << "\n--- THONG TIN BAN DAU ---" << endl;
    tg.Xuat();
    cout << "Phan loai: " << tg.PhanLoai() << endl;
    cout << "Chu vi: " << tg.TinhChuVi() << endl;
    cout << "Dien tich: " << tg.TinhDienTich() << endl;

    cout << "\n--- THUC HIEN BIEN DOI ---" << endl;

    // Tịnh tiến
    tg.TinhTien(2, 3);
    cout << "1. Sau khi tinh tien vector (2, 3):" << endl;
    tg.Xuat();

    // Quay
    tg.Quay(90);
    cout << "2. Sau khi quay 90 do (quanh goc toa do):" << endl;
    tg.Xuat();

    // Phóng to
    tg.PhongTo(2);
    cout << "3. Sau khi phong to gap 2 lan:" << endl;
    tg.Xuat();

    // Thu nhỏ
    tg.ThuNho(2);
    cout << "4. Sau khi thu nho 2 lan (quay ve kich thuoc cu):" << endl;
    tg.Xuat();

    cout << "\n===============================" << endl;
    cout << "Hoan thanh minh hoa lop cTamGiac." << endl;

    return 0;
}