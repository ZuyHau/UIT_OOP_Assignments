// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2
#pragma once
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class cDaThuc {
private:
    int n;      // Bậc của đa thức
    float* a;   // Mảng động chứa các hệ số
public:
    cDaThuc(int bac = 0);
    cDaThuc(const cDaThuc& other); // Copy constructor để trả về đối tượng
    ~cDaThuc();

    void Nhap();
    void Xuat();
    float TinhGiaTri(float x);

    // Phép toán cộng trừ
    cDaThuc operator+(const cDaThuc& other);
    cDaThuc operator-(const cDaThuc& other);
    cDaThuc& operator=(const cDaThuc& other);
};