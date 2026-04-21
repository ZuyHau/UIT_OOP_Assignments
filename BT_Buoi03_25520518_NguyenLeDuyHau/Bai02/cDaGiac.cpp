// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2
#include "cDaGiac.h"

#define PI 3.1415926535

cDaGiac::cDaGiac() {
    n = 0;
    dsDinh = nullptr;
}

cDaGiac::~cDaGiac() {
    if (dsDinh != nullptr) {
        delete[] dsDinh;
    }
}

void cDaGiac::Nhap() {
    do {
        cout << "Nhap so dinh cua da giac (n >= 3): ";
        cin >> n;
        if (n < 3) cout << "Da giac phai co it nhat 3 dinh!\n";
    } while (n < 3);

    if (dsDinh != nullptr) delete[] dsDinh;
    dsDinh = new Diem[n];

    for (int i = 0; i < n; i++) {
        cout << "Nhap toa do dinh " << i + 1 << " (x y): ";
        cin >> dsDinh[i].x >> dsDinh[i].y;
    }
}

void cDaGiac::Xuat() {
    cout << "Da giac co " << n << " dinh: ";
    for (int i = 0; i < n; i++) {
        cout << "(" << dsDinh[i].x << ", " << dsDinh[i].y << ") ";
    }
    cout << endl;
}

float cDaGiac::TinhChuVi() {
    float p = 0;
    for (int i = 0; i < n; i++) {
        Diem d1 = dsDinh[i];
        Diem d2 = dsDinh[(i + 1) % n];
        p += sqrt(pow(d2.x - d1.x, 2) + pow(d2.y - d1.y, 2));
    }
    return p;
}

float cDaGiac::TinhDienTich() {
    float area = 0;
    for (int i = 0; i < n; i++) {
        area += (dsDinh[i].x * dsDinh[(i + 1) % n].y) - (dsDinh[(i + 1) % n].x * dsDinh[i].y);
    }
    return abs(area) / 2.0f;
}

void cDaGiac::TinhTien(float dx, float dy) {
    for (int i = 0; i < n; i++) {
        dsDinh[i].x += dx;
        dsDinh[i].y += dy;
    }
}

void cDaGiac::Quay(float goc) {
    float rad = goc * (float)PI / 180.0f;
    for (int i = 0; i < n; i++) {
        float x0 = dsDinh[i].x;
        dsDinh[i].x = x0 * cos(rad) - dsDinh[i].y * sin(rad);
        dsDinh[i].y = x0 * sin(rad) + dsDinh[i].y * cos(rad);
    }
}

void cDaGiac::PhongTo(float k) {
    for (int i = 0; i < n; i++) {
        dsDinh[i].x *= k;
        dsDinh[i].y *= k;
    }
}

void cDaGiac::ThuNho(float k) {
    if (k != 0) PhongTo(1.0f / k);
}