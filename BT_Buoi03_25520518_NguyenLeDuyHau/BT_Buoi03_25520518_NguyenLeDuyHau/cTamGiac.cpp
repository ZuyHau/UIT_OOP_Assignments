// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2
#include "cTamGiac.h"

#define PI 3.1415926535
#define EPSILON 0.0001 // Sai số cho phép khi so sánh số thực

cTamGiac::cTamGiac() {}
cTamGiac::~cTamGiac() {}

// Hàm bổ trợ tính khoảng cách giữa 2 điểm
float KhoangCach(Diem d1, Diem d2) {
    return sqrt(pow(d2.x - d1.x, 2) + pow(d2.y - d1.y, 2));
}

void cTamGiac::Nhap() {
    do {
        cout << "Nhap tọa do dinh A (x y): "; cin >> A.x >> A.y;
        cout << "Nhap tọa do dinh B (x y): "; cin >> B.x >> B.y;
        cout << "Nhap tọa do dinh C (x y): "; cin >> C.x >> C.y;
        if (!KiemTra()) {
            cout << "Ba diem thang hang! Khong tao thanh tam giac. Vui long nhap lai.\n";
        }
    } while (!KiemTra());
}

void cTamGiac::Xuat() {
    cout << "Toa do: A(" << A.x << ", " << A.y << "), B(" << B.x << ", " << B.y << "), C(" << C.x << ", " << C.y << ")" << endl;
}

bool cTamGiac::KiemTra() {
    float a = KhoangCach(B, C);
    float b = KhoangCach(A, C);
    float c = KhoangCach(A, B);
    return (a + b > c + EPSILON && a + c > b + EPSILON && b + c > a + EPSILON);
}

string cTamGiac::PhanLoai() {
    float a = KhoangCach(B, C);
    float b = KhoangCach(A, C);
    float c = KhoangCach(A, B);

    bool deu = (abs(a - b) < EPSILON && abs(b - c) < EPSILON);
    bool can = (abs(a - b) < EPSILON || abs(b - c) < EPSILON || abs(a - c) < EPSILON);
    bool vuong = (abs(a * a + b * b - c * c) < 0.1 || abs(a * a + c * c - b * b) < 0.1 || abs(b * b + c * c - a * a) < 0.1);

    if (deu) return "Tam giac Deu";
    if (vuong && can) return "Tam giac Vuong Can";
    if (vuong) return "Tam giac Vuong";
    if (can) return "Tam giac Can";
    return "Tam giac Thuong";
}

float cTamGiac::TinhChuVi() {
    return KhoangCach(A, B) + KhoangCach(B, C) + KhoangCach(A, C);
}

float cTamGiac::TinhDienTich() {
    float a = KhoangCach(B, C);
    float b = KhoangCach(A, C);
    float c = KhoangCach(A, B);
    float p = TinhChuVi() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void cTamGiac::TinhTien(float dx, float dy) {
    A.x += dx; A.y += dy;
    B.x += dx; B.y += dy;
    C.x += dx; C.y += dy;
}

void cTamGiac::Quay(float goc) {
    float rad = goc * (float)PI / 180.0f;
    auto rotatePoint = [&](Diem& d) {
        float x_old = d.x;
        d.x = x_old * cos(rad) - d.y * sin(rad);
        d.y = x_old * sin(rad) + d.y * cos(rad);
        };
    rotatePoint(A); rotatePoint(B); rotatePoint(C);
}

void cTamGiac::PhongTo(float k) {
    A.x *= k; A.y *= k;
    B.x *= k; B.y *= k;
    C.x *= k; C.y *= k;
}

void cTamGiac::ThuNho(float k) {
    if (k != 0) PhongTo(1.0f / k);
}