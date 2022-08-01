#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll odd[200010],eve[200010];
int main(){
	ll x;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>x;
		odd[i]=odd[i-1]+(i%2)*x;
		eve[i]=eve[i-1]+((i+1)%2)*x;
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		if(odd[i-1]+eve[n]-eve[i]==eve[i-1]+odd[n]-odd[i])ans++;
	}
	cout<<ans<<endl;
	return 0;
}
