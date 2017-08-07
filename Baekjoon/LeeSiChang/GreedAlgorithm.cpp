#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;
static const int MAX = 100000000;
int main() {
	int t;
	cin >> t;
	for (int c = 0; c < t; c++)
	{
		int e, f;
		cin >> e >> f;
		//assert(e >= 1 && f > e && f <= 10000);
		int n;
		cin >> n;
		vector<int> p(50000), w(10000);

		for (int i = 0; i < n; i++)
		{
			cin >> p[i] >> w[i];
		}

		vector<int> s(f - e + 1);
		s[0] = 0;
		for (int i = 1; i <= f - e; i++)
		{
			s[i] = MAX;
		}

		for (int i = 0; i < n; i++)
		{
			for (int h = 0; h <= f - e - w[i]; h++)
			{
				if (s[h] + p[i] < s[h + w[i]])
				{
					s[h + w[i]] = s[h] + p[i];
				}
			}
		}

		if (s[f - e] != MAX)
		{
			cout << s[f - e] << endl;
		}
		else
		{
			cout << "-1" << endl;
		}
	}
}