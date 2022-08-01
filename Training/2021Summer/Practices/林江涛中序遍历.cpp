#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,int> tr[100001];
void dfs(int rt){
	if(tr[rt].first!=0)dfs(tr[rt].first);
	cout<<rt<<endl;
	if(tr[rt].second!=0)dfs(tr[rt].second);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>tr[i].first>>tr[i].second;
	}
	dfs(1);
	return 0;
}
