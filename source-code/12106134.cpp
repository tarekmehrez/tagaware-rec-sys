//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL m[1000005],L[1000005],maxi=0,mini=2000000000,ch=-1;
int main(){
	LL n,i;
	cin >> n;
	LL a;
	for(i=0;i<n;i++){
		cin >> a;
		if(m[a]==0){
			L[a]=i;
			m[a]=1;
		}
		else{
			m[a]++;
		}
		if(m[a]>maxi){
			maxi=m[a];
			mini=i-L[a]+1;
			ch=L[a]+1;
		}
		else if(m[a]==maxi && i-L[a]+1<mini){
      		mini=i-L[a]+1;
      		ch=L[a]+1;
    	}
	}
	cout<<ch<<" "<<ch+mini-1;
	return 0;
}