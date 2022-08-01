#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
const ll rev2 = 500000004;
ll qpow(ll a,ll b,ll m) {
	a%=m;
	ll res=1;
	while(b>0) {
		if(b&1)res=res*a%m;
		a=a*a%m;
		b>>=1;
	}
	return res;
}
ll n;
int main() {
	cin>>n;
	cout<<(qpow(3,n+1,MOD)-1+MOD)%MOD*rev2%MOD<<endl;
	return 0;
}
