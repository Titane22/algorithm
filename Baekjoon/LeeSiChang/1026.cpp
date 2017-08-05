#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

int main() {
	int n;

	cin >> n;
	assert(n <= 50 && n > 0);
	vector<vector<int>> a(n,vector<int>(n));
	vector<vector<int>> b(n, vector<int>(n));
	// input list a & b
	for (int i = 0; i < n; i++) {
		cin >> a[0][i];
		assert(a[0][i] <= 100 && a[0][i] >=0);
	}
	for (int i = 0; i < n; i++) {
		cin >> b[0][i];
		assert(b[0][i] <= 100 && b[0][i] >=0);
	}
	
	// w: 가중치 
	int w = n -1;
	// a 배열은 가장 낮은 값부터 가중치 부여
	for (int i = 0; i < n; i++) {
		int min = 100;
		int idx = 0;
		/*
			1 1 1 6 0
			0 0 0 0 0
			3 2 1 0 4
		*/
		for (int j = 0; j < n; j++) {
			if (a[0][j] < min && a[1][j] == 0) {
				min = a[0][j];
				idx = j;
			}
		}
		a[1][idx] = w--;
	}

	w = n - 1;
	// b 배열은 가장 높은 값부터 가중치 부여
	for (int i = 0; i < n; i++) {
		int max = -1;
		int idx = 0;
		/*
		   2 7 8 3 1
		   0 0 0 0 0
		   1 3 4 2 0
		*/
		for (int j = 0; j < n; j++) {
			if (b[0][j] > max && b[1][j] == 0) {
				max = b[0][j];
				idx = j;
			}
		}
		b[1][idx] = w--;
	}
	
	// 가중치 값이 같은 것끼리 a배열을 재배열
	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[1][i] == b[1][j]) {
				c[j] = a[0][i];
			}
		}
	}

	for (int i = 0; i < n; i++)
		a[0][i] = c[i];
	cout << endl;
	// output list a & b
	for (int i = 0; i < n; i++) {
		cout << a[0][i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << b[0][i] << " ";
	}
	cout << endl<<endl;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[0][i] * b[0][i];
	}

	cout << "sum : " << sum << endl;
}
