#include <iostream>
using namespace std;

class MYINT {
private:
    int value;
public:
    MYINT(int n) {
        value = n;
    }

    MYINT operator+(const MYINT& other) {
        return MYINT(value - other.value);
    }

    MYINT operator*(const MYINT& other) {
        return MYINT(value * other.value);
    }

    friend ostream& operator << (ostream& out, const MYINT& I) {
        out << I.value;
        return out;
    }

};

int main() {
    MYINT a(4), b(5);
    cout << (a + b) * a << endl;
    cout << a * b << endl;
    system("pause");
    return 0;
}