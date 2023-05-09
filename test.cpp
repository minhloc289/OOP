#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Polynomial {
private:
    vector<int> coeffs;

public:
    Polynomial() {}

    void read() {
        int degree;
        cin >> degree;
        coeffs.resize(degree + 1);
        for (int i = degree; i >= 0; i--) {
            cin >> coeffs[i];
        }
    }

    void print() const {
        int degree = coeffs.size() - 1;
        for (int i = degree; i >= 0; i--) {
            if (coeffs[i] == 0) {
                continue;
            }
            if (i < degree && coeffs[i] > 0) {
                cout << "+";
            }
            if (coeffs[i] != 1 || i == 0) {
                cout << coeffs[i];
            }
            if (i > 0) {
                cout << "x";
            }
            if (i > 1) {
                cout << "^" << i;
            }
        }
        if (degree < 0) {
            cout << "0";
        }
        cout << endl;
    }

    Polynomial operator+(const Polynomial& other) const {
        Polynomial result;
        int n = coeffs.size();
        int m = other.coeffs.size();
        result.coeffs.resize(max(n, m));
        for (int i = 0; i < n; i++) {
            result.coeffs[i] += coeffs[i];
        }
        for (int i = 0; i < m; i++) {
            result.coeffs[i] += other.coeffs[i];
        }
        return result;
    }

    Polynomial operator-(const Polynomial& other) const {
        Polynomial result;
        int n = coeffs.size();
        int m = other.coeffs.size();
        result.coeffs.resize(max(n, m));
        for (int i = 0; i < n; i++) {
            result.coeffs[i] += coeffs[i];
        }
        for (int i = 0; i < m; i++) {
            result.coeffs[i] -= other.coeffs[i];
        }
        return result;
    }

    Polynomial operator*(const Polynomial& other) const {
        Polynomial result;
        int n = coeffs.size();
        int m = other.coeffs.size();
        result.coeffs.resize(n + m - 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result.coeffs[i + j] += coeffs[i] * other.coeffs[j];
            }
        }
        return result;
    }
};

int main() {
    Polynomial p1, p2, result;
    char op;

   
    p1.read();
   
    p2.read();
    
    cin >> op;

    switch (op) {
    case '+':
        result = p1 + p2;
        break;
    case '-':
        result = p1 - p2;
        break;
    case '*':
        result = p1 * p2;
        break;
    default:
        cout << "Invalid operator" << endl;
        return 1;
    }

    cout << "Result: ";
    result.print();

    return 0;
}