//Mã số sinh viên: 25520518
//Họ và tên sinh viên: Nguyễn Lê Duy Hậu
//Ngày sinh: 22/03/2007
//Lớp : KTMT.1
#include <iostream>
using namespace std;

struct PhanSo 
{
    int tu, mau;
};

void nhapPhanSo(PhanSo& ps) 
{
    cin >> ps.tu >> ps.mau;
}

int main() 
{
    PhanSo ps1, ps2;

    nhapPhanSo(ps1);
    nhapPhanSo(ps2);

    long long v1 = (long long)ps1.tu * ps2.mau;
    long long v2 = (long long)ps2.tu * ps1.mau;

    if (v1 > v2) {
        cout << ps1.tu << "/" << ps1.mau;
    }
    else {
        cout << ps2.tu << "/" << ps2.mau;
    }

    cout << endl;
    return 0;
}