//Language: MS C++


#include <iostream>
#include <vector>
#include <string>
#include <set>
//#include <unordered_set>
#include <fstream>
#include <map>
//#include <unordered_map>
#include <random>
#include <stack>
//#include <stdio.h>
#include <algorithm>
#include <cmath>

//#include <ctime>

using namespace std;
#define ll long long
#define MOD 1000000007
#define mp(a, b) make_pair(a, b)
#define PI 3.1415926535
#define EPS 0.00000001
#define pii pair<ll, ll>
const int INF = 1000000002;

#define DEBUG 41

#ifndef DEBUG

ifstream in("input.in");
ofstream out("output.out");

#define cin in
#define cout out

#endif

ll n, k;


int main()
{

	ios_base::sync_with_stdio(0);
	int n, k, a;
	cin >> n >> k >> a;
	set<int> st;
	int m;
	cin >> m;
	vector<pii> moves;
	for(int i = 0; i < m; ++i)
	{
		int t;
		cin >> t;
		if(st.find(t) == st.end())
		{
			moves.push_back(mp(t, i+1));
			st.insert(t);
		}
	}

	st.clear();
	st.insert(0);
	st.insert(n+1);
	++a;
	int curShips = (n+1) / a;
	for(int i = 0; i < moves.size(); ++i)
	{
		int cur = moves[i].first;
		set<int>::iterator itR = st.lower_bound(cur);
		set<int>::iterator itL = --itR;
		++itR;
		int prev = (*itR - *itL) / a;
		int ne = (*itR - cur) / a;
		int ne1 = (cur - *itL) / a;
		curShips -= prev - ne - ne1;
		if(curShips < k)
		{
			cout << moves[i].second;
			return 0;
		}
		st.insert(cur);

	}
	cout << -1;

	return 0;

}