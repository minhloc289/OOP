#include <iostream>

using namespace std;

class Array {
private:
	int n;
	int* a;
public:
	Array() {
		this->a = new int[n];
	}

	void Nhap() {
		cin >> n;
		for (int i = 0; i < this->n; i++) {
			cin >> a[i];
		}
	}

	void Xuat() {
		for (int i = 0; i < this->n; i++) {
			cout << a[i] << " ";
		}
	}

	void Count() {
		int x;
		cout << "Nhap so can tim: ";
		cin >> x;
		int count = 0;
		for (int i = 0; i < this->n; i++) {
			if (a[i] == x) {
				count++;
			}
		}
		cout << x << " xuat hien " << count << " lan" << endl;
	}

	bool Kiemtra() {
		for (int i = 0; i < this->n - 1; i++) {
			if (a[i] > a[i + 1]) {
				return false;
			}
		}
		return true;
	}

};

int main() {
	Array a;
	a.Nhap();
	a.Xuat();
	cout << endl;
	a.Count();
	if (a.Kiemtra() == true) {
		cout << "Mang tang dan";
	}
	else cout << "Mang khong tang dan";
}