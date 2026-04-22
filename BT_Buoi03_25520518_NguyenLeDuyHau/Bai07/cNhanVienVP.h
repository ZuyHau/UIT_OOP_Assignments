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

class cNhanVienVP {
private:
    string maNV, hoTen;
    Ngay ngaySinh;
    double luong;

public:
    cNhanVienVP();
    ~cNhanVienVP();

    // Getter & Setter
    string GetMaNV();
    void SetMaNV(string ma);
    string GetHoTen();
    void SetHoTen(string ten);
    double GetLuong();
    void SetLuong(double l);
    Ngay GetNgaySinh();
    void SetNgaySinh(int d, int m, int y);

    void Nhap();
    void Xuat();
};

// Lớp quản lý danh sách
class cListNhanVien {
private:
    int n;
    cNhanVienVP* ds;

public:
    cListNhanVien();
    ~cListNhanVien();
    void NhapDS();
    void XuatDS();
    void TimLuongCaoNhat();
    double TinhTongLuong();
    void TimNhanVienGiaNhat();
    void SapXepTangDanTheoLuong();
};