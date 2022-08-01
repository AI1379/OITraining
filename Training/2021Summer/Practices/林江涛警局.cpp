#include<bits/stdc++.h>
using namespace std;
int n,k,d;
queue<int> q;
vector<int> graph[100010];
int ans[100010];
int main(){
	int tmp,u,v,cnt=0;
	cin>>n>>k>>d;
	memset(ans,-1,sizeof(ans));
	for(int i=1;i<=k;i++){
		cin>>tmp;
		q.push(tmp);
		ans[tmp]=0;
	}
	for(int i=1;i<=n-1;i++){
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	while(!q.empty()){
		tmp=q.front();
		q.pop();
		for(int i=0;i<graph[tmp].size();i++){
			if(ans[graph[tmp][i]]==-1){
				q.push(graph[tmp][i]);
				if(ans[tmp]==d)break;
				ans[graph[tmp][i]]=ans[tmp]+1;
			}
		}
		if(ans[tmp]==d)break;
	}
	for(int i=1;i<=n;i++){
		if(ans[i]==-1){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
