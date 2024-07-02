#include <iostream>
#include <stdio.h>
using namespace std;
int T = 0;
long long int umn(long long int x, long long int y, long long int N);
long long int perep(long long int x, long long int y, long long int k)
{
	long long int k1 = (k / 2 + k % 2), a1 = x / pow(10, k), a2 = x % (long long int)pow(10, k), b1 = y / pow(10, k), b2 = y % (long long int)pow(10, k);
	T += 3;
	//return (a1 * b1 * pow(10, (2 * k)) + (a1 * b2 + a2 * b1) * pow(10, k) + a2 * b2);
	return (umn(a1, b1, k) * pow(10, (2 * k)) + (umn(a1, b2, k) + umn(a2, b1, k)) * pow(10, k) + umn(a2, b2, k));
}
long long int umn(long long int x, long long int y, long long int N)
{
	long long int k = N / 2 + (N % 2), a = x / pow(10, k), b = x % (long long int)pow(10, k), c = y / pow(10, k), d = y % (long long int)pow(10, k), u, v, w;
	if (N == 1)
		return (x * y);
	v = umn(a, c, k);
	w = umn(b, d, k);
	if (((a + b) / pow(10, k) >= 10) || ((c + d) / pow(10, k) >= 10))
		u = perep(x, y, k);
	else
		u = umn((a + b), (c + d), k);
	T += 7;
	a = v * pow(10, (2 * k));
	b = (u - v - w) * pow(10, k);
	return (a + b + w);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	long long int x = 999999999, y = 999999999, max, N = 0, res;
	if (x > y)
		max = x;
	else
		max = y;
	for (; max != 0; max /= 10, N++);
	res = umn(x, y, N);
	cout << x * y << "\n Результат: " << res << "\n Трудоемкость: " << T;

	return 0;
}