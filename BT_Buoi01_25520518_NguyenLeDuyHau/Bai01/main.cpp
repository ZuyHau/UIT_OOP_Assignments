//Mã số sinh viên: 25520518
//Họ và tên sinh viên: Nguyễn Lê Duy Hậu
//Ngày sinh: 22/03/2007
//Lớp : KTMT.1
#include<iostream>
#include<cmath>
using namespace std;

int UCLN(int a, int b)
{
    a = abs(a);
    b = abs(b);
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int tuso, mauso;
    cin >> tuso >> mauso;

    int gcd = UCLN(tuso, mauso);
    tuso /= gcd;
    mauso /= gcd;

    cout << tuso << "/" << mauso;

    return 0;
}