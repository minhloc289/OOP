#include <iostream>
#include <cmath>
using namespace std;

class Clock {
private:
	int hour, minute, second;
public:
	Clock(int h = 0, int m = 0, int s = 0) {
		this->hour = h;
		this->minute = m;
		this->second = s;
	}
	
	void ChuanHoa() {
		while (second < 0) {
			minute--;
			second += 60;
		}

		while (second > 59) {
			minute++;
			second -= 60;
		}

		while (minute < 0) {
			hour--;
			minute += 60;
		}

		while (minute > 59) {
			hour++;
			minute -= 60;
		}

		while (hour < 0) {
			hour += 24;
		}
		hour %= 24;
	}

	void operator++() {
		second++;
		ChuanHoa();
	}

	void operator--() {
		second--;
		ChuanHoa();
	}

	Clock operator+(int n) {
		Clock res(hour, minute, second + n);
		res.ChuanHoa();
		return res;
	}

	Clock operator-(int n) {
		Clock res(hour, minute, second - n);
		res.ChuanHoa();
		return res;
	}

	friend ostream& operator << (ostream& out, Clock& c) {
		out << c.hour << " " << c.minute << " " << c.second;
		return out;
	}

};

int main() {
	int h, m, s, n;
	cin >> h >> m >> s;
	Clock clock(h, m, s);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string oper;
		int d = 0;
		cin >> oper;
		if (oper == "++") {
			++clock;
		}
		else if (oper == "--") {
			--clock;
		}
		else if (oper == "+") {
			cin >> d;
			clock = clock + d;
		}
		else if (oper == "-") {
			cin >> d;
			clock = clock - d;
		}
	}
	cout << clock << endl;
	return 0;
}