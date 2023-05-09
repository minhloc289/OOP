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
		cout << tu << "/" << mau;
	}

	float value() {
		return (float)tu / mau;
	}
};
class arrPhanSo {
private:
	int n;
	PhanSo* a;
public:
	arrPhanSo() {
		
		this->a = new PhanSo[n];
	}

	void Nhap() {
		cin >> n;
		for (int i = 0; i < this->n; i++) {
			this->a[i].Nhap();
		}
	}

	void Xuat() {
		for (int i = 0; i < this->n; i++) {
			this->a[i].Xuat();
			cout << " " << endl;
		}
	}

	PhanSo TimMax() {
		PhanSo max = this->a[0];
		for (int i = 0; i < this->n; i++) {
			if (this->a[i].value() > max.value()) {
				max = this->a[i];
			}
		}
		return max;
	}

	void SapXep() {
		for (int i = 0; i < this->n - 1; i++) {
			for (int j = i + 1; j < this->n; j++) {
				if (this->a[i].value() > this->a[j].value()) {
					swap(a[i], a[j]);
				}
			}
		}
	}
};

int main() {
	arrPhanSo arr;
	arr.Nhap();
	cout << "danh sach: " << endl;
	arr.Xuat();
	cout << "max: " << endl;
	arr.TimMax().Xuat();
	cout << endl;
	arr.SapXep();
	cout << "sap xep xong: " << endl;
	arr.Xuat();
}