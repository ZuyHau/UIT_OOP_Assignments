//Mã số sinh viên: 25520518
//Họ và tên sinh viên: Nguyễn Lê Duy Hậu
//Ngày sinh: 22/03/2007
//Lớp : KTMT.1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct S {
    string n; 
    float d1, d2, m; 
};

int main() {
    int n;
    if (!(cin >> n)) return 0;

    S ds[100];
    for (int i = 0; i < n; i++)
    {
        cin.ignore(); 
        getline(cin, ds[i].n);
        cin >> ds[i].d1 >> ds[i].d2;
        ds[i].m = (ds[i].d1 + ds[i].d2) / 2.0;
    }

    int pMax = 0, pMin = 0;
    for (int i = 1; i < n; i++)
    {
        if (ds[i].m > ds[pMax].m) pMax = i;
        if (ds[i].m < ds[pMin].m) pMin = i;
    }

    cout << ds[pMax].n << " " << ds[pMax].m << endl;
    cout << ds[pMin].n << " " << ds[pMin].m;

    return 0;
}