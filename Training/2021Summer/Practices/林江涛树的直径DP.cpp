#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> tr[100010];
int ans;
int d[100010],f[100010];
void dfs(int rt,int fa){
	int max1=0,max2=0;
	for(int i=0;i<tr[rt].size();i++){
		if(tr[rt][i]==fa)continue;
		dfs(tr[rt][i],rt);
		d[rt]=max(d[rt],d[tr[rt][i]]+1);
		if(d[tr[rt][i]]>max1){
			max2=max1;
			max1=d[tr[rt][i]];
		}
	}
	if(tr[rt].size()<2)f[rt]=0;
	else{
		f[rt]=max1+max2+2;
	}
}
int main(){
	int u,v;
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>u>>v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	dfs(1,1);
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
	return 0;
}
