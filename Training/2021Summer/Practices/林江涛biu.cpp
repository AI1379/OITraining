#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>tr[100010];
int fa[100010];
int a[100010],b[100010];
int ans=0;
void dfs(int u){
	if(b[u]!=-1){
		a[u]=b[u]-b[fa[u]];
	}
	else{	for(int i=0;i<tr[u].size();i++){
		dfs(tr[u][i]);
	}
		b[u]=0x3f3f3f;
		for(int i=0;i<tr[u].size();i++){
			b[u]=min(b[tr[u][i]],b[u]);
		}
		a[u]=b[u]-b[fa[u]];	
	}

}
int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		cin>>fa[i];
		tr[fa[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		ans+=a[i];
	}
	cout<<ans<<endl;
	return 0;
}
