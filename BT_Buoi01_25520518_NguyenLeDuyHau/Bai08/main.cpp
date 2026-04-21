//Mã số sinh viên: 25520518
//Họ và tên sinh viên: Nguyễn Lê Duy Hậu
//Ngày sinh: 22/03/2007
//Lớp : KTMT.1
#include <iostream>
#include <string>
using namespace std;

int main() {
    int d, m, y;
    if (!(cin >> d >> m >> y)) return 0;

    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    if (m < 3) y -= 1;
    int res = (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;

    string thu[] = { "Chu Nhat", "Thu Hai", "Thu Ba", "Thu Tu", "Thu Nam", "Thu Sau", "Thu Bay" };

    cout << thu[res] << endl;

    return 0;
}