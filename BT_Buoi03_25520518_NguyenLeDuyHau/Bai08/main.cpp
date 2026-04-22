// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
#include "cNhanVienSX.h"

int main() {
    cListNhanVienSX list;
    list.NhapDS();

    cout << "\n--- DANH SACH NHAN VIEN SAN XUAT ---\n";
    list.XuatDS();

    list.TimLuongThapNhat();

    cout << "\nTong luong cty chi tra cho bo phan SX: " << (long long)list.TinhTongLuong() << " VND" << endl;

    list.TimNhanVienGiaNhat();

    cout << "\n--- DANH SACH TANG DAN THEO LUONG ---\n";
    list.SapXepTangDanTheoLuong();
    list.XuatDS();

    return 0;
}