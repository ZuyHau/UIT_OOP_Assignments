// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2
#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class cPhanSo {
private:
    int tu, mau;
public:
    cPhanSo(int t = 0, int m = 1);
    void Nhap();
    void Xuat();
    void RutGon();
    float GiaTri() const;
    int GetTu() const;
    int GetMau() const;

    // Nạp chồng toán tử cộng để tính tổng cho dễ
    cPhanSo operator+(const cPhanSo& other) const;
};

class cDSPhanSo {
private:
    int n;
    cPhanSo* ds;
public:
    cDSPhanSo();
    ~cDSPhanSo();
    void Nhap();
    void Xuat();

    cPhanSo TinhTong();
    cPhanSo TimMax();
    cPhanSo TimMin();
    cPhanSo TuNguyenToLonNhat();

    void SapXepTang();
    void SapXepGiam();
};

bool LaNguyenTo(int n);