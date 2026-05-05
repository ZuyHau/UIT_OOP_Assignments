
#include <iostream>
#include <cmath>
using namespace std;

class SoPhuc {
private:
    double thuc, ao;
public:
    
    SoPhuc(double r = 0, double i = 0) : thuc(r), ao(i) {}

    
    SoPhuc operator+(const SoPhuc& sp) { return SoPhuc(thuc + sp.thuc, ao + sp.ao); }
    SoPhuc operator-(const SoPhuc& sp) { return SoPhuc(thuc - sp.thuc, ao - sp.ao); }
    SoPhuc operator*(const SoPhuc& sp) {
        return SoPhuc(thuc * sp.thuc - ao * sp.ao, thuc * sp.ao + ao * sp.thuc);
    }
    SoPhuc operator/(const SoPhuc& sp) {
        double mau = sp.thuc * sp.thuc + sp.ao * sp.ao;
        return SoPhuc((thuc * sp.thuc + ao * sp.ao) / mau, (ao * sp.thuc - thuc * sp.ao) / mau);
    }

    
    bool operator==(const SoPhuc& sp) { return (thuc == sp.thuc && ao == sp.ao); }
    bool operator!=(const SoPhuc& sp) { return !(*this == sp); }

    
    friend istream& operator>>(istream& is, SoPhuc& sp) {
        cout << "Nhap phan thuc: "; is >> sp.thuc;
        cout << "Nhap phan ao: "; is >> sp.ao;
        return is;
    }
    friend ostream& operator<<(ostream& os, const SoPhuc& sp) {
        os << sp.thuc << (sp.ao >= 0 ? " + " : " - ") << abs(sp.ao) << "i";
        return os;
    }
};

int main() {
    SoPhuc sp1, sp2;
    cout << "--- Nhap So Phuc 1 ---" << endl; cin >> sp1;
    cout << "--- Nhap So Phuc 2 ---" << endl; cin >> sp2;

    cout << "\nKet qua phep tinh:" << endl;
    cout << "Tong: " << sp1 + sp2 << endl;
    cout << "Hieu: " << sp1 - sp2 << endl;
    cout << "Tich: " << sp1 * sp2 << endl;
    cout << "Thuong: " << sp1 / sp2 << endl;
    cout << "So sanh ==: " << (sp1 == sp2 ? "Bang nhau" : "Khac nhau") << endl;

    return 0;
}