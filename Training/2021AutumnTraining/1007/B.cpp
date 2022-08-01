#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll l,r;
bool check(ll x) {
	int a=0,b=0;
	int y=x*x;
	while(x>0) {
		a+=x%10;
		x/=10;
	}
	while(y>0) {
		b+=y%10;
		y/=10;
	}
	return a*a==b;
}
int ans=0;
int main() {
	cin>>l>>r;
	for(ll i=l; i<=r; i++) {
		if(check(i)) {
			ans++;
		}
//		cout<<i<<' '<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
