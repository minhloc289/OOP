#include <iostream>
#include <math.h>
using namespace std;

class DonThuc {
private:
	double a;
	int b;
public:
	DonThuc(){
		a = 0;
		b = 0;
	}

	DonThuc(double a, int b) {
		this->a = a;
		this->b = b;
	}


	void input() {
		cin >> a;
		cin >> b;
	}
	void output() {
		cout << a << "x^" << b;
	}

	double Tinh(double x) {
		cin >> b;
		return a * pow(x, b);
	}

	DonThuc DaoHam() {
		return DonThuc(a * b, b - 1);
	}

	DonThuc Cong(DonThuc &other) {
		if (b == other.b) {
			return DonThuc(a + other.a, b);
		}
		else {
			cout << "Hai don thuc phai cung bac." << endl;
			return DonThuc();
		}
	}
	
	DonThuc operator+(){}
};

int main() {
	DonThuc x, y;
	cout << "Nhap don thuc dau tien: ";
	x.input();
	cout << endl;
	cout << "Nhap don thuc thu hai: ";
	y.input();
	cout << "Xuat don thuc dau tien: ";
	x.output();
	cout << endl;
	cout << "Xuat don thuc thu hai: ";
	y.output();
	cout << endl;
	DonThuc p1 = x.DaoHam();
	cout << "Dao ham don thuc dau tien: ";
	p1.output();
	cout << endl;
	DonThuc p2 = y.DaoHam();
	cout << "Dao ham don thuc thu hai: ";
	p2.output();
	cout << endl;
	cout << "Tong hai don thuc: ";
	DonThuc sum = x.Cong(y);
	sum.output();
}