//Mã số sinh viên: 25520518
//Họ và tên sinh viên: Nguyễn Lê Duy Hậu
//Ngày sinh: 22/03/2007
//Lớp : KTMT.1
#include <iostream>
using namespace std;

bool isLeap(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int daysInMonth(int m, int y) {
    if (m == 2) return isLeap(y) ? 29 : 28;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

int main() {
    int d, m, y;
    if (!(cin >> d >> m >> y)) return 0;
    if (y < 1 || m < 1 || m > 12 || d < 1 || d > daysInMonth(m, y)) return 0;
   
    d++;
    if (d > daysInMonth(m, y)) {
        d = 1;
        m++;
        if (m > 12) {
            m = 1;
            y++;
        }
    }
    cout << d << " " << m << " " << y << endl;

    return 0;
}