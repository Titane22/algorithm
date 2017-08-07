#include<iostream>
using namespace std;

int main()
{
	int n;
	int round = 0;
	int a, b;
	int bin=1, atd = 0;
	cin >> n >> a >> b;

	while (a != b)
	{
		
		a = (a+1) / 2;
		b = (b+1) / 2;
		round++;
	}
	cout << round << endl;
}