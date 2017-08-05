#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;

	/*while (1) {
		cin >> n;
		if (n < 51) break;
	}*/
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	vector<int> c(n);

	for (int i = 0; i < n; i++) {
		c[i]=b[i];
	}

	for (int j = n - 1; j>0; j--) {
		for (int i = 0; i < j; i++) {
			if (a[i] > a[i + 1]) {
				int tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
		}
	}

	for (int j = n - 1; j>0; j--) {
		for (int i = 0; i < j; i++) {
			if (c[i] < c[i + 1]) {
				int tmp = c[i];
				c[i] = c[i + 1];
				c[i + 1] = tmp;
			}
		}
	}

	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += a[i] * c[i];

	cout << sum;
}