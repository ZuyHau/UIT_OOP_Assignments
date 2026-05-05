#include <iostream>
#include <numeric> // Dùng cho hàm std::gcd (C++17 trở lên)
using namespace std;

class PhanSo {
private:
    int tu, mau;
    // Hàm nội bộ để luôn giữ phân số ở dạng tối giản
    void rutGon() {
        if (mau == 0) return;
        int chung = std::gcd(tu, mau);
        tu /= chung;
        mau /= chung;
        // Đảm bảo dấu trừ luôn nằm ở tử số
        if (mau < 0) { tu = -tu; mau = -mau; }
    }
public:
    // Thiết lập cho phép số nguyên (mẫu mặc định = 1)
    PhanSo(int t = 0, int m = 1) : tu(t), mau(m) { rutGon(); }

    // Nạp chồng toán tử số học
    PhanSo operator+(const PhanSo& p) { return PhanSo(tu * p.mau + p.tu * mau, mau * p.mau); }
    PhanSo operator-(const PhanSo& p) { return PhanSo(tu * p.mau - p.tu * mau, mau * p.mau); }
    PhanSo operator*(const PhanSo& p) { return PhanSo(tu * p.tu, mau * p.mau); }
    PhanSo operator/(const PhanSo& p) { return PhanSo(tu * p.mau, mau * p.tu); }

    // Nạp chồng toán tử so sánh
    bool operator==(const PhanSo& p) { return tu * p.mau == p.tu * mau; }
    bool operator>(const PhanSo& p) { return tu * p.mau > p.tu * mau; }
    bool operator<(const PhanSo& p) { return tu * p.mau < p.tu * mau; }

    // Nạp chồng toán tử nhập xuất
    friend istream& operator>>(istream& is, PhanSo& p) {
        cout << "Nhap tu: "; is >> p.tu;
        cout << "Nhap mau: "; is >> p.mau;
        p.rutGon();
        return is;
    }
    friend ostream& operator<<(ostream& os, const PhanSo& p) {
        if (p.mau == 1) os << p.tu;
        else os << p.tu << "/" << p.mau;
        return os;
    }
};

int main() {
    PhanSo ps1, ps2;
    cout << "--- Nhap Phan So 1 ---" << endl; cin >> ps1;
    cout << "--- Nhap Phan So 2 ---" << endl; cin >> ps2;

    cout << "\nKet qua tinh toan:" << endl;
    cout << ps1 << " + " << ps2 << " = " << ps1 + ps2 << endl;
    cout << ps1 << " * " << ps2 << " = " << ps1 * ps2 << endl;

    cout << "\nKet qua so sanh:" << endl;
    if (ps1 > ps2) cout << ps1 << " lon hon " << ps2 << endl;
    else if (ps1 < ps2) cout << ps1 << " nho hon " << ps2 << endl;
    else cout << "Hai phan so bang nhau" << endl;

    return 0;
}