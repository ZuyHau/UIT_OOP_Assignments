// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2
#include "cDaThuc.h"

int main() {
    cDaThuc dt1, dt2;

    cout << "--- NHAP DA THUC 1 ---" << endl;
    dt1.Nhap();
    cout << "--- NHAP DA THUC 2 ---" << endl;
    dt2.Nhap();

    cout << "\nDa thuc 1: "; dt1.Xuat();
    cout << "Da thuc 2: "; dt2.Xuat();

    cDaThuc tong = dt1 + dt2;
    cout << "\nTong hai da thuc: "; tong.Xuat();

    cDaThuc hieu = dt1 - dt2;
    cout << "Hieu hai da thuc: "; hieu.Xuat();

    float x;
    cout << "\nNhap gia tri x de tinh P(x) cho da thuc tong: ";
    cin >> x;
    cout << "Gia tri tai x = " << x << " la: " << tong.TinhGiaTri(x) << endl;

    return 0;
}