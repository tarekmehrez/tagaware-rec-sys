//Language: GNU C++


#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

struct rule
{
	int a, b;
	std::string sign;
};
long long f[100][100] = {};
std::vector<rule> rules;
int n, m;

bool check(int i, int j, int a, int b)
{
	int h[100] = {};
	h[a] = 1;
	h[b] = 1;
	for (int k = 0; k < m; ++k)
	{
		rule r = rules[k];
		if (i < r.a && r.a <= n * 2 - j) continue;
		if (i < r.b && r.b <= n * 2 - j) continue;
		if (!(r.a == a || r.a == b || r.b == a || r.b == b)) continue;
		if (r.sign == "<")
		{
			if (!(h[r.a] < h[r.b])) return false;
		}
		else if (r.sign == ">")
		{
			if (!(h[r.a] > h[r.b])) return false;
		}
		else if (r.sign == "<=")
		{
			if (!(h[r.a] <= h[r.b])) return false;
		}
		else if (r.sign == ">=")
		{
			if (!(h[r.a] >= h[r.b])) return false;
		}
		else if (r.sign == "=")
		{
			if (!(h[r.a] == h[r.b])) return false;
		}
	}
	return true;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		char sign[1024];
		scanf("%d%s%d", &a, sign, &b);
		rule r;
		r.a = a;
		r.b = b;
		r.sign = std::string(sign);
		rules.push_back(r);
	}
	f[0][0] = 1;
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 0; i <= k * 2; ++i)
		{
			int j = k * 2 - i;
			long long sum = 0;
			bool c1 = false, c2 = false, c3 = false;
			if (i >= 2 && (c1 = check(i, j, i - 1, i))) sum += f[i - 2][j];
			if (j >= 2 && (c2 = check(i, j, n * 2 - j + 1, n * 2 - j + 2))) sum += f[i][j - 2];
			if (i >= 1 && j >= 1 && (c3 = check(i, j, i, n * 2 - j + 1))) sum += f[i - 1][j - 1];
			f[i][j] = sum;
			//printf("%d %d %d f[%d][%d] = %I64d\n", c1, c2, c3, i, j, f[i][j]);
		}
	}
	long long ans = 0;
	for (int i = 0; i <= n * 2; ++i) ans += f[i][n * 2 - i];
	//ans /= 3;
	printf("%I64d\n", ans / 3);
	return 0;
}
