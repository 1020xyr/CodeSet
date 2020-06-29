#include<iostream>

using namespace std;

void func(){
	int n;
	while (cin >> n) {
		for (int x = 0;x <= 20;x++) {
			for (int y = 0;y <= 33;y++) {
				int z = 100 - x - y;
				int sum; 
				// if (x * 5 * 3 + y * 3 * 3 + z <= n * 3)
				if (z % 3 == 0) {
					sum = 5 * x + 3 * y + z / 3;
				}
				else {
					sum = 5 * x + 3 * y + z / 3 + 1;
				}
				if (sum <= n) {
					cout << "x=" << x << ",";
					cout << "y=" << y << ",";
					cout << "z=" << z << endl;
				}
					
			}
		}
	}
}
int main() {
	func();
	return 0;
}
