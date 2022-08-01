#include<bits/stdc++.h>
using namespace std;
int n;
int r[6010];
vector<int> tr[6010];
int f[6010][2];
bool vis[6010];
int rt; 
void dfs(int u){
	for(int i=0;i<tr[u].size();i++){
		dfs(tr[u][i]);
		f[u][0]+=max(f[tr[u][i]][0],f[tr[u][i]][1]);
		f[u][1]+=f[tr[u][i]][0];
	}
}
int main(){
	int x,y;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		f[i][1]=r[i];
	}
	for(int i=1;i<=n-1;i++){
		cin>>x>>y;
		tr[y].push_back(x);
		vis[x]=true;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			rt=i;
			break;
		}
	}
	dfs(rt);
	cout<<max(f[rt][0],f[rt][1])<<endl;
	return 0; 
}
