#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll MAXN = 100010;
ll n,k;
ll v;
__int128 sm=0,mn=1e9;
void print(__int128 x){
	if(x>9)print(x/10);
	putchar(x%10 + '0');
} 
int main(){
	#ifndef DEBUG
	freopen("T1.in","r",stdin);
	freopen("T1.out","w",stdout);
	#endif
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>v;
		sm += v;
		mn = min(mn,(__int128)(v));
	}
	if(k==1&&n!=1)print(sm-2*mn);
	else if(n==1) print(mn);
	else print(mn);
	putchar('\n');
	return 0;
} 
