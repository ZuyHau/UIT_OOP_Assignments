// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
#include "cArray.h"

int main() {
    srand(time(0)); // Reset seed ngẫu nhiên
    cArray arr;
    int n, x;

    cout << "Nhap so phan tu mang: "; cin >> n;
    arr.TaoNgauNhien(n);

    cout << "Mang ngau nhien vua tao: ";
    arr.Xuat();

    cout << "Nhap gia tri x can dem: "; cin >> x;
    cout << "So lan xuat hien cua " << x << ": " << arr.DemX(x) << endl;

    if (arr.KiemTraTangDan()) cout << "Mang dang tang dan." << endl;
    else cout << "Mang KHONG tang dan." << endl;

    int leMin = arr.TimLeNhoNhat();
    if (leMin != -1) cout << "So le nho nhat: " << leMin << endl;
    else cout << "Mang ko co so le." << endl;

    int ntMax = arr.TimNguyenToLonNhat();
    if (ntMax != -1) cout << "So nguyen to lon nhat: " << ntMax << endl;
    else cout << "Mang ko co so nguyen to." << endl;

    cout << "Sap xep tang dan: "; arr.SapXepTang(); arr.Xuat();
    cout << "Sap xep giam dan: "; arr.SapXepGiam(); arr.Xuat();

    return 0;
}