//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 40;
const int inf = 0x3f3f3f3f;
const int maxm = 200;

int n, m;
int a[2 * maxn];
ll f[2 * maxn][2 * maxn];
bool vis[2 * maxn][2 * maxn];
char str[101];

struct node
{
    int x, y, type;
    node() {}
    node(int x, int y, int type) : x(x), y(y), type(type) {}
};
node p[maxm];

bool check()
{
    for (int i = 1; i <= m; i ++)
    {
        if (a[p[i].x] == inf && a[p[i].y] == inf) continue;
        if (p[i].type == 0 && a[p[i].x] != a[p[i].y]) return false;
        if (p[i].type == 1 && a[p[i].x] >= a[p[i].y]) return false;
        if (p[i].type == 2 && a[p[i].x] > a[p[i].y]) return false;
    }
    return true;
}
ll Dp(int l, int r)
{
    int now = (l + 1 + 2 * n - r) / 2;
    if (r - l + 1 == 2)
    {
        a[l] = a[r] = now;
        if (check())
        {
            a[l] = a[r] = inf;
            return 1LL;
        }
        else
        {
            a[l] = a[r] = inf;
            return 0LL;
        }
    }
    if (vis[l][r]) return f[l][r];
    vis[l][r] = true;
    a[l] = a[l + 1] = now;
    if (check()) f[l][r] += Dp(l + 2, r);
    a[l] = a[l + 1] = inf;
    a[r - 1] = a[r] = now;
    if (check()) f[l][r] += Dp(l, r - 2);
    a[r - 1] = a[r] = inf;
    a[l] = a[r] = now;
    if (check()) f[l][r] += Dp(l + 1, r - 1);
    a[l] = a[r] = inf;
    return f[l][r];
}

int main( )
{
    int x, type, y;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= 2 * n; i ++) a[i] = inf;
    for (int i = 1; i <= m; i ++)
    {
        scanf("%d", &x);
        scanf("%s", str);
        int len = strlen(str);
        scanf("%d", &y);
        if (str[0] == '=') type = 0;
        else if (str[0] == '<' && len == 1) type = 1;
        else if (str[0] == '>' && len == 1) type = 1, swap(x, y);
        else if (str[0] == '<') type = 2;
        else type = 2, swap(x, y);
        p[i] = node(x, y, type);
    }
    printf("%I64d\n", Dp(1, 2 * n));
    return 0;
}