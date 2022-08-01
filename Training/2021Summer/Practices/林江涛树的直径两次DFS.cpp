#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> tr[100010];
int res,maxNode;
void dfs(int rt,int dep,int fa){
	if(dep>res){
		res=dep;
		maxNode=rt;
	}
	for(int i=0;i<tr[rt].size();i++){
		if(tr[rt][i]==fa)continue;
		dfs(tr[rt][i],dep+1,rt);
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
	dfs(1,1,1);
	res=0;
	dfs(maxNode,1,maxNode);
	cout<<res-1<<endl;
	return 0;
}
