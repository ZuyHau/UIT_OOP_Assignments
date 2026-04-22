// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2
#pragma once
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Diem {
    float x, y;
};

class cTamGiac {
private:
    Diem A, B, C;

public:
    cTamGiac();
    ~cTamGiac();

    void Nhap();
    void Xuat();
    bool KiemTra();
    string PhanLoai();
    float TinhChuVi();
    float TinhDienTich();

    void TinhTien(float dx, float dy);
    void Quay(float goc); // Quay quanh gốc tọa độ O(0,0)
    void PhongTo(float k);
    void ThuNho(float k);
};