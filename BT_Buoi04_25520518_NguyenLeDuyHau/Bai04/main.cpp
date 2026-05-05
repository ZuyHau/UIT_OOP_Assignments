#include <iostream>
#include <cmath>

using namespace std;

class CDate {
private:
    int ngay, thang, nam;

    // Kiểm tra năm nhuận
    bool laNamNhuan(int y) {
        return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    }

    // Trả về số ngày tối đa trong tháng
    int ngayTrongThang(int m, int y) {
        int ds[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (m == 2 && laNamNhuan(y)) return 29;
        return ds[m];
    }

    // Chuyển ngày hiện tại thành tổng số ngày tính từ 01/01/0001
    long long toTotalDays() const {
        long long total = ngay;
        for (int y = 1; y < nam; ++y) total += (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) ? 366 : 365;
        for (int m = 1; m < thang; ++m) {
            int ds[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            total += ds[m];
            if (m == 2 && (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))) total += 1;
        }
        return total;
    }

    // Chuyển ngược từ tổng số ngày về định dạng ngày/tháng/nam
    static CDate fromTotalDays(long long total) {
        int y = 1, m = 1;
        while (total > ((y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) ? 366 : 365)) {
            total -= (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) ? 366 : 365;
            y++;
        }
        CDate res(1, 1, y);
        while (total > res.ngayTrongThang(m, y)) {
            total -= res.ngayTrongThang(m, y);
            m++;
        }
        res.ngay = (int)total;
        res.thang = m;
        return res;
    }

public:
    CDate(int d = 1, int m = 1, int y = 1) : ngay(d), thang(m), nam(y) {}

    // Nạp chồng toán tử + và - với số nguyên ngày
    CDate operator+(int d) { return fromTotalDays(this->toTotalDays() + d); }
    CDate operator-(int d) { return fromTotalDays(this->toTotalDays() - d); }

    // Toán tử tăng/giảm 1 ngày
    CDate& operator++() { *this = *this + 1; return *this; }
    CDate operator++(int) { CDate temp = *this; ++(*this); return temp; }
    CDate& operator--() { *this = *this - 1; return *this; }
    CDate operator--(int) { CDate temp = *this; --(*this); return temp; }

    // Khoảng cách giữa hai ngày (trả về số ngày)
    long long operator-(const CDate& other) {
        return abs(this->toTotalDays() - other.toTotalDays());
    }

    friend istream& operator>>(istream& is, CDate& d) {
        is >> d.ngay >> d.thang >> d.nam;
        return is;
    }

    friend ostream& operator<<(ostream& os, const CDate& d) {
        os << d.ngay << "/" << d.thang << "/" << d.nam;
        return os;
    }
};

int main() {
    CDate ngayGui, ngayRut;
    double tienGoc, laiSuatNam;

    // 1. NHẬP DỮ LIỆU
    cout << "Nhap ngay gui tien (d m y): "; cin >> ngayGui;
    cout << "Nhap ngay rut tien (d m y): "; cin >> ngayRut;
    cout << "Nhap so tien goc (VND): "; cin >> tienGoc;
    cout << "Nhap lai suat nam (%): "; cin >> laiSuatNam;

    // 2. TÍNH TOÁN DỰA TRÊN KHOẢNG CÁCH NGÀY
    long long soNgayGui = ngayRut - ngayGui;

    // Công thức: Lãi = Gốc * (Lãi suất / 100) * (Số ngày / 365)
    double tienLai = tienGoc * (laiSuatNam / 100.0) * (soNgayGui / 365.0);

    // 3. XUẤT KẾT QUẢ
    cout << "\n--- KET QUA ---" << endl;
    cout << "Khoang cach gui tien: " << soNgayGui << " ngay." << endl;
    cout << "So tien lai nhan duoc: " << (long long)tienLai << " VND" << endl;
    cout << "Tong so tien rut: " << (long long)(tienGoc + tienLai) << " VND" << endl;

    return 0;
}