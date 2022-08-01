#include<bits/stdc++.h>
using namespace std;
int f[100010];
int p[100010];
int n;
pair<int,int> sol[100010];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i];
	memset(f,0x3f,sizeof(f));
	f[1]=0;
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<i;j++){
			if(j+p[j]>=i&&f[i]>f[j]){
				f[i]=f[j];
				sol[i].first=j;
				sol[i].second=0;
			}
			else if(j+p[j]+1>=i&&f[i]>f[j]+1){
				f[i]=f[j]+1;
				sol[i].first=j;
				sol[i].second=1;
			}
		}
	}
	cout<<f[n+1]<<endl;
	stack<int>stk;
	int tmp=n+1;
	while(tmp!=0){
		if(sol[tmp].second)stk.push(sol[tmp].first);
		tmp=sol[tmp].first;
	}
	while(!stk.empty()){
		cout<<stk.top()<<' ';
		stk.pop();
	}
	return 0;
}
