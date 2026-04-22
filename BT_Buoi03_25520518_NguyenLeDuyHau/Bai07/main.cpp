// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2
#include "cNhanVienVP.h"

int main() {
    cListNhanVien list;
    list.NhapDS();

    cout << "\n--- DANH SACH NHAN VIEN ---\n";
    list.XuatDS();

    list.TimLuongCaoNhat();

    cout << "\nTong luong cong ty phai tra: " << (long long)list.TinhTongLuong() << " VND" << endl;

    list.TimNhanVienGiaNhat();

    cout << "\n--- DANH SACH SAU KHI SAP XEP TANG DAN THEO LUONG ---\n";
    list.SapXepTangDanTheoLuong();
    list.XuatDS();

    return 0;
}