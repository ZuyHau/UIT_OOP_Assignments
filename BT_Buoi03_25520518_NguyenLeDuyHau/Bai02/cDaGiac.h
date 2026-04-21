// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2
#pragma once
#include <iostream>
#include <cmath>

using namespace std;

struct Diem {
    float x, y;
};

class cDaGiac {
private:
    int n; // Số đỉnh
    Diem* dsDinh; // Mảng động chứa các đỉnh

public:
    cDaGiac();
    ~cDaGiac();

    void Nhap();
    void Xuat();

    float TinhChuVi();
    float TinhDienTich();

    void TinhTien(float dx, float dy);
    void Quay(float goc);
    void PhongTo(float k);
    void ThuNho(float k);
};