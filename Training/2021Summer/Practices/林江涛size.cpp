#include<bits/stdc++.h>
using namespace std;
int n; 
int size[1010]; 
vector<int>t[1010];
int ans=0;
void dfs(int rt){
	size[rt]=1;
	for(int i=0;i<t[rt].size();i++){
		dfs(t[rt][i]);
		size[rt]+=size[t[rt][i]];
	}
	ans+=size[rt];
} 
int main(){
	int x,y;
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		t[x].push_back(y);
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
} 
