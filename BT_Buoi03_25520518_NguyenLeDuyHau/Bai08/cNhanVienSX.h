// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Ngay {
    int d, m, y;
};

class cNhanVienSX {
private:
    string maNV, hoTen;
    Ngay ngaySinh;
    int soSanPham;
    double donGia;

public:
    cNhanVienSX();
    ~cNhanVienSX();

    // Getter & Setter
    string GetMaNV();
    double TinhLuong();
    Ngay GetNgaySinh();

    void Nhap();
    void Xuat();
};

class cListNhanVienSX {
private:
    int n;
    cNhanVienSX* ds;

public:
    cListNhanVienSX();
    ~cListNhanVienSX();
    void NhapDS();
    void XuatDS();
    void TimLuongThapNhat();
    double TinhTongLuong();
    void TimNhanVienGiaNhat();
    void SapXepTangDanTheoLuong();
};