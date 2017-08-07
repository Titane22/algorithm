#include<iostream>
using namespace std;

int main()
{
	int n;
	int round = 1;
	int a, b;
	cin >> n;
	cin >> a >> b;

	int r1 = a + (n - 1);
	int r2 = b + (n - 1);

	while (r1 / 2 != r2 / 2)
	{
		r1 /= 2;
		r2 /= 2;
		round++;
	}
	cout << round << endl;
}