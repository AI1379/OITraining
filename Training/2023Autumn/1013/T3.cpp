#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 300010;
const ll MAXV = 1000010*2;
ll n;
ll val[MAXN];
ll prime[MAXN],cnt = 0;
bool notprime[MAXV];
void init(ll maxv){
	for(int i=2;i<=maxv;++i){
		if(!notprime[i]){
			prime[++cnt] = i;
		}
		for(int j=1;j<=cnt;++j){
			if(1ll * prime[j] * i>maxv)break;
			notprime[prime[j]*i] = true;
			if(i % prime[j] == 0)break;
		}
	}
}
ll ans = 0;
int main(){
	#ifndef DEBUG
	freopen("T3.in","r",stdin);
	freopen("T3.out","w",stdout);
	#endif
	ll u,v;
	ios::sync_with_stdio(false);
	cin>>n;
	u = 0;
	for(int i=1;i<=n;++i){
		cin>>val[i];
		u = max(u,val[i]);
	}
	ans = n-1;
	init(u*2);
	for(int i=1;i<=n-1;++i){
		cin>>u>>v;
		if(notprime[val[u]+val[v]]){
			--ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}
