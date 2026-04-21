//Mã số sinh viên: 25520518
//Họ và tên sinh viên: Nguyễn Lê Duy Hậu
//Ngày sinh: 22/03/2007
//Lớp : KTMT.1
#include <iostream>
#include <cmath>
using namespace std;

struct PhanSo {
    int t, m;
};

int UCLN(int a, int b) {
    a = abs(a); b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void rutGon(PhanSo& ps) {
    int u = UCLN(ps.t, ps.m);
    ps.t /= u;
    ps.m /= u;
    if (ps.m < 0) 
    {
        ps.t = -ps.t;
        ps.m = -ps.m;
    }
}

void xuat(PhanSo ps) {
    rutGon(ps);
    cout << ps.t;
    if (ps.m != 1) cout << "/" << ps.m;
    cout << endl;
}

int main() {
    PhanSo p1, p2, kq;

    cin >> p1.t >> p1.m;
    cin >> p2.t >> p2.m;

    kq.t = p1.t * p2.m + p2.t * p1.m;
    kq.m = p1.m * p2.m;
    xuat(kq);

    kq.t = p1.t * p2.m - p2.t * p1.m;
    kq.m = p1.m * p2.m;
    xuat(kq);

    kq.t = p1.t * p2.t;
    kq.m = p1.m * p2.m;
    xuat(kq);

    if (p2.t == 0) {
        cout << "Khong the chia cho phan so bang 0!" << endl;
    }
    else {
        kq.t = p1.t * p2.m;
        kq.m = p1.m * p2.t;
        xuat(kq);
    }

    return 0;
}