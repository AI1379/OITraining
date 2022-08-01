#include<bits/stdc++.h>
using namespace std;
int n; 
vector<int>t[1010];
int ans;
void dfs(int rt,int dep){
	ans=max(ans,dep);
	for(int i=0;i<t[rt].size();i++){
		dfs(t[rt][i],dep+1);
	}
} 
int main(){
	int x,y;
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		t[x].push_back(y);
	}
	dfs(1,1);
	cout<<ans<<endl;
	return 0;
} 
