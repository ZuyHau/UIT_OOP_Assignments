// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2
#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Ngay {
    int d, m, y;
};

class cCandidate {
private:
    string ma, ten;
    Ngay ngaySinh;
    float toan, van, anh;
public:
    void Nhap();
    void Xuat();
    float TinhTong();
};

class cListCandidate {
private:
    int n;
    cCandidate* ds;
public:
    cListCandidate();
    ~cListCandidate();
    void Nhap();
    void XuatTren15();
    void TimMaxTong();
    void SapXepGiam();
};