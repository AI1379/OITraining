#include<bits/stdc++.h>
using namespace std;
struct node{
	int to;
	int w;
};
int n,q;
vector<node>tr[1010];
int rt;
int deep[1010];
int fa[1010];
int lca(int u,int v){
	while(deep[u]>deep[v])u=fa[u];
	while(deep[v]>deep[u])v=fa[v];
	while(u!=v)u=fa[u],v=fa[v];
	return u;
}
void dfs(int x,int f){
	fa[x]=f;
	for(int i=0;i<tr[x].size();i++){
		if(tr[x][i].to==fa[x])continue;
		deep[tr[x][i].to]=deep[x]+tr[x][i].w;
		dfs(tr[x][i].to,x);
	}
}
int main(){
	int u,v,w;
	node tmp; 
	cin>>n>>q;
	for(int i=0;i<n-1;i++){
		cin>>u>>v>>w;
		tmp.to=v;tmp.w=w;
		tr[u].push_back(tmp);
		tmp.to=u;
		tr[v].push_back(tmp);
	}
	dfs(1,1);
	for(int i=0;i<q;i++){
		cin>>u>>v;
		w=lca(u,v);
		cout<<deep[u]+deep[v]-2*deep[w]<<endl;
	}
	return 0;
} 
