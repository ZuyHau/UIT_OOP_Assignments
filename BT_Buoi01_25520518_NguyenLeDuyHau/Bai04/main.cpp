//Mã số sinh viên: 25520518
//Họ và tên sinh viên: Nguyễn Lê Duy Hậu
//Ngày sinh: 22/03/2007
//Lớp : KTMT.1
#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo {
    int t, m;
};

void chuanHoa(PhanSo& ps) {
    if (ps.m < 0) {
        ps.t = -ps.t;
        ps.m = -ps.m;
    }
}

int soSanh(PhanSo a, PhanSo b) {
    long long v1 = (long long)a.t * b.m;
    long long v2 = (long long)b.t * a.m;
    if (v1 > v2) return 1;
    if (v1 < v2) return -1;
    return 0;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    PhanSo a[100];
    for (int i = 0; i < n; i++) {
        cin >> a[i].t >> a[i].m;
        chuanHoa(a[i]);
    }

    PhanSo max = a[0];
    for (int i = 1; i < n; i++) {
        if (soSanh(a[i], max) == 1) max = a[i];
    }
    cout << max.t << "/" << max.m << endl;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (soSanh(a[i], a[j]) == 1) swap(a[i], a[j]);
        }
    }
    for (int i = 0; i < n; i++) cout << a[i].t << "/" << a[i].m << (i == n - 1 ? "" : " ");
    cout << endl;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (soSanh(a[i], a[j]) == -1) swap(a[i], a[j]);
        }
    }
    for (int i = 0; i < n; i++) cout << a[i].t << "/" << a[i].m << (i == n - 1 ? "" : " ");

    return 0;
}