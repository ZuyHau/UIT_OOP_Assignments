#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class DaThuc {
private:
    vector<double> heSo; // heSo[i] là hệ số của x^i

public:
    // Khởi tạo đa thức bậc n với các hệ số bằng 0
    DaThuc(int bac = 0) {
        heSo.assign(bac + 1, 0);
    }

    // Nạp chồng toán tử cộng hai đa thức
    DaThuc operator+(const DaThuc& dt) const {
        int bacMax = max(this->heSo.size(), dt.heSo.size());
        DaThuc res(bacMax - 1);
        for (int i = 0; i < bacMax; i++) {
            double v1 = (i < this->heSo.size()) ? this->heSo[i] : 0;
            double v2 = (i < dt.heSo.size()) ? dt.heSo[i] : 0;
            res.heSo[i] = v1 + v2;
        }
        return res;
    }

    // Nạp chồng toán tử trừ hai đa thức
    DaThuc operator-(const DaThuc& dt) const {
        int bacMax = max(this->heSo.size(), dt.heSo.size());
        DaThuc res(bacMax - 1);
        for (int i = 0; i < bacMax; i++) {
            double v1 = (i < this->heSo.size()) ? this->heSo[i] : 0;
            double v2 = (i < dt.heSo.size()) ? dt.heSo[i] : 0;
            res.heSo[i] = v1 - v2;
        }
        return res;
    }

    // Tính giá trị đa thức tại x
    double tinhGiaTri(double x) const {
        double res = 0;
        for (int i = 0; i < heSo.size(); i++) {
            res += heSo[i] * pow(x, i);
        }
        return res;
    }

    // Nạp chồng toán tử nhập
    friend istream& operator>>(istream& is, DaThuc& dt) {
        int bac;
        cout << "Nhap bac cua da thuc: "; is >> bac;
        dt.heSo.assign(bac + 1, 0);
        for (int i = bac; i >= 0; i--) {
            cout << "Nhap he so x^" << i << ": ";
            is >> dt.heSo[i];
        }
        return is;
    }

    // Nạp chồng toán tử xuất
    friend ostream& operator<<(ostream& os, const DaThuc& dt) {
        bool first = true;
        for (int i = dt.heSo.size() - 1; i >= 0; i--) {
            if (dt.heSo[i] == 0) continue;
            if (!first && dt.heSo[i] > 0) os << " + ";
            if (dt.heSo[i] < 0) os << " - ";

            double val = abs(dt.heSo[i]);
            if (val != 1 || i == 0) os << val;

            if (i > 0) os << "x";
            if (i > 1) os << "^" << i;
            first = false;
        }
        if (first) os << "0";
        return os;
    }
};

int main() {
    DaThuc dt1, dt2;

    cout << "--- Nhap da thuc 1 ---" << endl;
    cin >> dt1;
    cout << "--- Nhap da thuc 2 ---" << endl;
    cin >> dt2;

    cout << "\nDa thuc 1: " << dt1 << endl;
    cout << "Da thuc 2: " << dt2 << endl;

    DaThuc tong = dt1 + dt2;
    cout << "Tong hai da thuc: " << tong << endl;

    DaThuc hieu = dt1 - dt2;
    cout << "Hieu hai da thuc: " << hieu << endl;

    double x;
    cout << "\nNhap gia tri x de tinh P(x) cho da thuc tong: ";
    cin >> x;
    cout << "Gia tri cua tong tai x = " << x << " la: " << tong.tinhGiaTri(x) << endl;

    return 0;
}