#include <iostream>
using namespace std;

class PhanSo {
private:
	int tu;
	int mau;
public:
	PhanSo() {
		tu = 0;
		mau = 1;
	}
	PhanSo(int tu, int mau) {
		this->tu = tu;
		this->mau = mau;
	}

	void Nhap() {
		cin >> tu >> mau;
	}
	void Xuat() {
		cout << tu << "/" << mau << endl;
	}
	float value() {
		return (float)tu / mau;
	}
};

class arrPhanSo {
public:
	PhanSo* a;
	int n;
	arrPhanSo() {
		n = 0;
		a = new PhanSo[n];
	}

	void nhap() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			a[i].Nhap();
		}
	}

	void xuat() {
		for (int i = 0; i < n; i++) {
			a[i].Xuat();
		}
	}

	PhanSo TimMax() {
		PhanSo max = a[0];
		for (int i = 0; i < n; i++) {
			if (a[i].value() > max.value()) {
				max = a[i];
			}
		}
		return max;
	}

	void SapXep() {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i].value() > a[j].value()) {
					swap(a[i], a[j]);
				}
			}
		}
	}
};

int main() {
	arrPhanSo a;
	a.nhap();
	cout << "danh sach phan so: " << endl;
	a.xuat();
	cout << "phan so lon nhat: ";
	a.TimMax().Xuat();	
	a.SapXep();
	cout << "sap xep xong: " << endl;
	a.xuat();
}


