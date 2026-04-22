// Mã số sinh viên: 25520518
// Họ và tên sinh viên: Nguyễn Lê Duy Hậu
// Ngày sinh: 22/03/2007
// Lớp: IT002.Q25.2
#include "cCandidate.h"

void cCandidate::Nhap() {
    cout << "Nhap MSSV: "; cin >> ma;
    cin.ignore();
    cout << "Nhap ho ten: "; getline(cin, ten);
    cout << "Nhap ngay thang nam sinh (d m y): ";
    cin >> ngaySinh.d >> ngaySinh.m >> ngaySinh.y;
    cout << "Nhap diem Toan - Van - Anh: ";
    cin >> toan >> van >> anh;
}

void cCandidate::Xuat() {
    cout << "[" << ma << "] " << ten << " | NS: " << ngaySinh.d << "/" << ngaySinh.m << "/" << ngaySinh.y;
    cout << " | Toan: " << toan << " Van: " << van << " Anh: " << anh;
    cout << " | Tong: " << TinhTong() << endl;
}

float cCandidate::TinhTong() {
    return toan + van + anh;
}

// --- Lớp cListCandidate ---
cListCandidate::cListCandidate() : n(0), ds(nullptr) {}
cListCandidate::~cListCandidate() { if (ds) delete[] ds; }

void cListCandidate::Nhap() {
    cout << "Nhap so luong thi sinh: "; cin >> n;
    ds = new cCandidate[n];
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thi sinh thu " << i + 1 << " ---\n";
        ds[i].Nhap();
    }
}

void cListCandidate::XuatTren15() {
    bool co = false;
    for (int i = 0; i < n; i++) {
        if (ds[i].TinhTong() > 15) {
            ds[i].Xuat();
            co = true;
        }
    }
    if (!co) cout << "Khong co thi sinh nao co tong diem > 15." << endl;
}

void cListCandidate::TimMaxTong() {
    if (n == 0) return;
    float maxDiem = ds[0].TinhTong();
    for (int i = 1; i < n; i++) {
        if (ds[i].TinhTong() > maxDiem) maxDiem = ds[i].TinhTong();
    }
    cout << "Cac thi sinh co diem cao nhat (" << maxDiem << "):" << endl;
    for (int i = 0; i < n; i++) {
        if (ds[i].TinhTong() == maxDiem) ds[i].Xuat();
    }
}

void cListCandidate::SapXepGiam() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].TinhTong() < ds[j].TinhTong()) {
                swap(ds[i], ds[j]);
            }
        }
    }
}