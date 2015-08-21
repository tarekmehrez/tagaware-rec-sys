//Language: GNU C++11


#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long       ll;
#define all(A)          A.begin(),A.end()
#define rall(A)         A.rbegin(),A.rend()
#define SP              setprecision
#define mem(A,B)        memset(A,B,sizeof A)
#define sorta(A)        sort(all(A))
#define sortd(A)        sort(rall(A))
#define sortf(A,F)      sort(all(A),F)
#define Get(mask,bit)   (mask&(1LL<<bit))
#define Set(mask,bit)   (mask|(1LL<<bit))
#define Reset(mask,bit) (mask&(~(1LL<<bit)))
#define Flib(mask,bit)  (mask^(1LL<<bit))
#define LowOn(mask,bit) (mask&-mask)
#define PI              (acos(0.) * 2)
#define exp             2.71828182845904523536028747135266249775724709369995
#define eps             .000000001
#define oo              1000000000
#define endl            '\n'
template <class T> inline void remax(T& A, T B){ if (A < B)A = B; }
template <class T> inline void remin(T& A, T B){ if (A > B)A = B; }
string ToString(ll num){ string ret; do{ ret += ((num % 10) + '0'); num /= 10; } while (num); reverse(all(ret)); return ret; }
ll ToNumber(string s){ ll r = 0, p = 1; for (int i = s.size() - 1; i >= 0; --i)r += (s[i] - '0') * p, p *= 10; return r; }
ll Gcd(ll a, ll b){ while (a %= b ^= a ^= b ^= a);  return b; }
ll Power(ll base, ll power){ ll ret = 1; while (power){ if (power & 1)ret *= base; power >>= 1; base *= base; } return ret; }
ll PowerMod(ll base, ll power, ll mod){ if (!power)return 1; if (power & 1)return (base * PowerMod(base, power - 1, mod)) % mod; return PowerMod((base * base) % mod, power >> 1, mod); }
int Log(ll num, ll base){ int ret = 0; while (num){ ++ret; num /= base; } return ret; }
int Count(ll mask){ int ret = 0; while (mask){ if (mask & 1)++ret; mask >>= 1; } return ret; }


#define point pair <int , int>
#define X first
#define Y second
int fact[200001];
int inv[200001];
const int mod = 1000000007;
int INV(int x){
    if (~inv[x])return inv[x];
    return inv[x] = PowerMod(fact[x], mod - 2, mod);
}
int nCr(int n, int r){
    return (ll)fact[n] * (ll)INV(r) % mod * (ll)INV(n - r) % mod;
}
inline void run(){
    pair <int, int> arr[2001];
    int dp[2001];
    const int mod = 1000000007;
    int h, w, n;
    scanf("%d%d%d", &h, &w, &n);
    for (int i = 0; i < n; ++i){
        scanf("%d%d", &arr[i].X, &arr[i].Y);
        --arr[i].X;
        --arr[i].Y;
    }
    sort(arr, arr + n);
    arr[n++] = { h - 1, w - 1 };
    fact[0] = 1;
    for (int i = 1; i <= 200000; ++i)
        fact[i] = (ll)fact[i - 1] * (ll)i % mod;
    mem(inv, -1);
    for (int i = 0; i < n; ++i){
        dp[i] = nCr(arr[i].X + arr[i].Y, arr[i].X);
        for (int j = 0; j < i; ++j)
        if (arr[j].Y <= arr[i].Y)
            dp[i] = ((ll)dp[i] - (ll)dp[j] * (ll)nCr(arr[i].X - arr[j].X + arr[i].Y - arr[j].Y, arr[i].X - arr[j].X) + mod) % mod;
    }
    (dp[n - 1] += mod) %= mod;
    printf("%d\n", dp[n - 1]);
}
int main(){
    FILE *input = stdin;
    FILE *output = stdout;
#ifdef LOCAL
    input = freopen("input.txt", "r", stdin);
    output = freopen("output.txt", "w", stdout);
#endif
    while (!feof(input)){
        run();
#ifdef LOCAL
        puts("");
#else
        break;
#endif
    }
#ifdef LOCAL
    fprintf(output, "\n\nTime: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}