// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2
#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

class cArray {
private:
    int* a; // Mảng động
    int n;  // Số lượng phần tử
public:
    cArray();
    ~cArray();

    void TaoNgauNhien(int size);
    void Xuat();
    int DemX(int x);
    bool KiemTraTangDan();
    int TimLeNhoNhat();
    int TimNguyenToLonNhat();

    // Sử dụng thuật toán Selection Sort từ môn DSA
    void SapXepTang();
    void SapXepGiam();
};

bool LaNguyenTo(int n);