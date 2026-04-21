//Mã số sinh viên: 25520518
//Họ và tên sinh viên: Nguyễn Lê Duy Hậu
//Ngày sinh: 22/03/2007
//Lớp : KTMT.1
#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

struct HocSinh {
    string hoTen;
    float toan, van, dtb;
};

int main() {
    HocSinh hs;

    getline(cin, hs.hoTen);
    cin >> hs.toan >> hs.van;

    hs.dtb = (hs.toan + hs.van) / 2.0;
    cout <<  setprecision(3) << hs.dtb << endl;

    return 0;
}