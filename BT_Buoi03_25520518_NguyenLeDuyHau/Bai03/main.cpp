// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2
#include "cDSPhanSo.h"

int main() {
    cDSPhanSo ds;
    ds.Nhap();

    cout << "\nDanh sach vua nhap: "; ds.Xuat();

    cPhanSo tong = ds.TinhTong();
    cout << "Tong cac phan so: "; tong.Xuat(); cout << endl;

    cout << "Phan so lon nhat: "; ds.TimMax().Xuat(); cout << endl;
    cout << "Phan so nho nhat: "; ds.TimMin().Xuat(); cout << endl;

    cPhanSo snt = ds.TuNguyenToLonNhat();
    if (snt.GetMau() != 0) {
        cout << "Phan so co tu la SNT lon nhat: "; snt.Xuat(); cout << endl;
    }
    else {
        cout << "Khong co phan so nao co tu la so nguyen to." << endl;
    }

    cout << "\nSap xep tang dan: "; ds.SapXepTang(); ds.Xuat();
    cout << "Sap xep giam dan: "; ds.SapXepGiam(); ds.Xuat();

    return 0;
}