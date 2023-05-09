#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class SachGiaoKhoa {
private:
	string ma, tensach, nxb;
	int soluong;
	float price;
	int tinhtrang;
public:
	SachGiaoKhoa() {
		ma = tensach = nxb = "";
		soluong = price = tinhtrang = 0;
	}

	SachGiaoKhoa(string ma, string tensach, string nxb, int soluong, float price, int tinhtrang) {
		this->ma = ma;
		this->tensach = tensach;
		this->nxb = nxb;
		this->soluong = soluong;
		this->price = price;
		this->tinhtrang = tinhtrang;
	}

	float ThanhTienSGK() {
		if (tinhtrang == 1) {
			return soluong * price;
		}
		else if (tinhtrang == 0) {
			return soluong * price * 0.5;
		}
	}

	string nxbSGK() {
		return nxb;
	}

	void Xuat() {
		cout << "Ma sach: " << ma << endl;
		cout << "Ten sach: " << tensach << endl;
		cout << "Ten nha xuat ban: " << nxb << endl;
		cout << "So luong: " << soluong << endl;
		cout << "Don gia: " << price << endl;
		cout << "Tinh trang (0/1): " << tinhtrang << endl;
	}
};

class SachThamKhao {
private:
	string ma, tensach, nxb;
	int soluong;
	float price;
	float tax;
public:
	SachThamKhao() {
		ma = tensach = nxb = "";
		soluong = price = tax = 0;
	}

	SachThamKhao(string ma, string tensach, string nxb, int soluong, float price, float tax) {
		this->ma = ma;
		this->tensach = tensach;
		this->nxb = nxb;
		this->soluong = soluong;
		this->price = price;
		this->tax = tax;
	}

	float ThanhTienSTK() {
		return soluong * price + tax;
	}

	void Xuat() {
		cout << "Ma sach: " << ma << endl;
		cout << "Ten sach: " << tensach << endl;
		cout << "Ten nha xuat ban: " << nxb << endl;
		cout << "So luong: " << soluong << endl;
		cout << "Don gia: " << price << endl;
		cout << "Thue: " << tax << endl;
	}
};

class QuanLiThuVien {
private:
	SachGiaoKhoa* danhsachSGK;
	SachThamKhao* danhsachSTK;
	int n;
	int m;
public:
	QuanLiThuVien() {
		danhsachSGK = NULL;
		danhsachSTK = NULL;
		n = m = 0;
	}
	~QuanLiThuVien() {
		delete[]danhsachSGK;
		delete[]danhsachSTK;
	}

	void NhapDanhSachSGK() {
		cout << "Nhap danh sach SGK: ";
		cin >> n;
		danhsachSGK = new SachGiaoKhoa[n];
		for (int i = 0; i < n; i++) {
			string ma, tensach, nxb;
			int soluong;
			float price;
			float thanhtien;
			int tinhtrang;

			cout << "Nhap ma sach: ";
			cin >> ma;

			cout << "Nhap ten sach: ";
			cin.ignore();
			getline(cin, tensach);

			cout << "Nhap ten nha xuat ban: ";
			getline(cin,nxb);

			cout << "Nhap so luong: ";
			cin >> soluong;
			
			cout << "Nhap gia tien: ";
			cin >> price;

			cout << "Nhap tinh trang sach (0/1): ";
			cin >> tinhtrang;
			
			danhsachSGK[i] = SachGiaoKhoa(ma, tensach, nxb, soluong, price, tinhtrang);

		}
	}

	void NhapDanhSachSTK() {
		cout << "Nhap danh sach STK: ";
		cin >> m;
		danhsachSTK = new SachThamKhao[n];
		for (int i = 0; i < m; i++) {
			string ma, tensach, nxb;
			int soluong;
			float price;
			float thanhtien;
			float tax;

			cout << "Nhap ma sach: ";
			cin >> ma;

			cout << "Nhap ten sach: ";
			cin.ignore();
			getline(cin, tensach);

			cout << "Nhap ten nha xuat ban: ";
			getline(cin,nxb);

			cout << "Nhap so luong: ";
			cin >> soluong;

			cout << "Nhap gia tien: ";
			cin >> price;

			cout << "Nhap thue: ";
			cin >> tax;

			danhsachSTK[i] = SachThamKhao(ma, tensach, nxb, soluong, price, tax);

		}
	}

	void XuatDanhSachSGK() {
		for (int i = 0; i < n; i++) {
			danhsachSGK[i].Xuat();
			cout << endl;
		}
	}

	void XuatDanhSachSTK() {
		for (int i = 0; i < m; i++) {
			danhsachSTK[i].Xuat();
			cout << endl;
		}
	}

	void TinhTienSGK() {
		float TongTienSGK = 0;
		for (int i = 0; i < n; i++) {
			TongTienSGK += danhsachSGK[i].ThanhTienSGK();
		}
		cout << TongTienSGK;
	}
	
	void TinhTienSTK() {
		float TongTienSTK = 0;
		for (int i = 0; i < m; i++) {
			TongTienSTK += danhsachSTK[i].ThanhTienSTK();
		}
		cout << TongTienSTK;
	}

	void CheapestSGK() {
		int min = danhsachSGK[0].ThanhTienSGK();
		for (int i = 1; i < n; i++) {
			float thanhTien = danhsachSGK[i].ThanhTienSGK();
			if (thanhTien < min) {
				min = danhsachSGK[i].ThanhTienSGK();
			}
			danhsachSGK[i].Xuat();
		}
	}

	void CheapestSTK() {
		int min = danhsachSTK[0].ThanhTienSTK();
		for (int i = 1; i < m; i++) {
			if (danhsachSTK[i].ThanhTienSTK() < min) {
				min = danhsachSTK[i].ThanhTienSTK();
			}
			danhsachSTK[i].Xuat();
		}
	}
	
	void FindSGK() {
		string nxb;
		cout << "Nhap ten nha xuat ban sach muon tim: ";
		cin.ignore();
		getline(cin, nxb);
		for (int i = 0; i < n; i++) {
			if (danhsachSGK[i].nxbSGK() == nxb) {
				danhsachSGK[i].Xuat();
			}
		}
	}
	
};

int main() {
	QuanLiThuVien qltv;
	qltv.NhapDanhSachSGK();
	qltv.NhapDanhSachSTK();

	cout << "Danh sach SGK: " << endl;
	qltv.XuatDanhSachSGK();
	cout << endl;

	cout << "Danh sach STK: " << endl;
	qltv.XuatDanhSachSTK();
	cout << endl;

	cout << "So tien truong phai tra cho SGK: " << endl;
	qltv.TinhTienSGK();
	cout << endl;

	cout << "So tien truong phai tra cho STK: " << endl;
	qltv.TinhTienSTK();
	cout << endl;

	cout << "SGK re nhat: " << endl;
	qltv.CheapestSGK();
	cout << endl;

	cout << "STK re nhat: " << endl;
	qltv.CheapestSTK();
	cout << endl;

	
	qltv.FindSGK();
	return 0;
}
