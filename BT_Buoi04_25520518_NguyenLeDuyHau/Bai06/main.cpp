#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// 1. ĐỊNH NGHĨA LỚP CVECTOR
class CVector {
private:
    int n; // Số chiều
    vector<double> elements;
public:
    CVector(int num = 0) : n(num), elements(num, 0) {}

    int getNDim() const { return n; }
    double getAt(int i) const { return elements[i]; }
    void setAt(int i, double val) { elements[i] = val; }

    // Nhập/Xuất Vector
    friend istream& operator>>(istream& is, CVector& v) {
        cout << "Nhap " << v.n << " phan tu cua vector: ";
        for (int i = 0; i < v.n; i++) is >> v.elements[i];
        return is;
    }
    friend ostream& operator<<(ostream& os, const CVector& v) {
        os << "(";
        for (int i = 0; i < v.n; i++) {
            os << v.elements[i] << (i == v.n - 1 ? "" : ", ");
        }
        os << ")";
        return os;
    }
};

// 2. ĐỊNH NGHĨA LỚP CMATRIX
class CMatrix {
private:
    int rows, cols;
    vector<vector<double>> data;
public:
    CMatrix(int r = 0, int c = 0) : rows(r), cols(c), data(r, vector<double>(c, 0)) {}

    // Nhập/Xuất Ma trận
    friend istream& operator>>(istream& is, CMatrix& m) {
        cout << "Nhap cac phan tu cua ma tran (" << m.rows << "x" << m.cols << "):" << endl;
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) is >> m.data[i][j];
        }
        return is;
    }
    friend ostream& operator<<(ostream& os, const CMatrix& m) {
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) os << setw(8) << m.data[i][j];
            os << endl;
        }
        return os;
    }

    // TÍCH MA TRẬN * VECTOR
    CVector operator*(const CVector& v) {
        if (this->cols != v.getNDim()) {
            cout << "Loi: Kich thuoc khong phu hop de nhan Ma tran * Vector!" << endl;
            return CVector(0);
        }
        CVector res(this->rows);
        for (int i = 0; i < this->rows; i++) {
            double sum = 0;
            for (int j = 0; j < this->cols; j++) {
                sum += this->data[i][j] * v.getAt(j);
            }
            res.setAt(i, sum);
        }
        return res;
    }

    // TÍCH MA TRẬN * MA TRẬN
    CMatrix operator*(const CMatrix& other) {
        if (this->cols != other.rows) {
            cout << "Loi: Kich thuoc khong phu hop de nhan hai ma tran!" << endl;
            return CMatrix(0, 0);
        }
        CMatrix res(this->rows, other.cols);
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < this->cols; k++) {
                    res.data[i][j] += this->data[i][k] * other.data[k][j];
                }
            }
        }
        return res;
    }
};

int main() {
    // Test tích Ma trận và Vector
    cout << "--- TEST NHAN MA TRAN VOI VECTOR ---" << endl;
    CMatrix A(2, 3); cin >> A;
    CVector V(3); cin >> V;
    CVector resV = A * V;
    cout << "Ket qua A * V: " << resV << endl << endl;

    // Test tích hai Ma trận
    cout << "--- TEST NHAN HAI MA TRAN ---" << endl;
    CMatrix B(3, 2); cin >> B;
    CMatrix resM = A * B;
    cout << "Ket qua A * B:" << endl << resM;

    return 0;
}