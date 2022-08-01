#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>tr[1010];
int rt;
int deep[1010];
int fa[1010];
void dfs(int x,int f){
	fa[x]=f;
	deep[x]=deep[fa[x]]+1;
	for(int i=0;i<tr[x].size();i++){
		if(tr[x][i]==fa[x])continue;
		dfs(tr[x][i],x);
	}
}
int main(){
	int u,v;
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>u>>v;
		tr[u].push_back(v);
		tr[v].push_back(u); 
		fa[v]=u;
	}
	dfs(1,1);
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		while(deep[u]>deep[v])u=fa[u];
		while(deep[v]>deep[u])v=fa[v];
		while(u!=v)u=fa[u],v=fa[v];
		cout<<u<<endl;
	}
	return 0;
}
/*
5 
1 2
1 3 
2 4 
2 5 
5 
3 5 
2 5 
3 4 
2 4 
5 5
*/ 
