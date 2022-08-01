#include<bits/stdc++.h>
using namespace std;
struct node{
	int dis,id;
	bool operator < (const node &b)const{
		return dis>b.dis;
	}
};
node mkNode(int v,int w){
	node tmp;
	tmp.dis=w;tmp.id=v;
	return tmp;
}
int n,m;
vector<node>graph[100010]; 
priority_queue<node>q;
int dis[100010];
int ticket[100010];
void dijkstra(int s){
	while(!q.empty())q.pop();
//	for(int i=1;i<=n;i++)dis[i]=ticket[i];
	memset(dis,0x3f,sizeof(dis));
	node head, to;
	q.push(mkNode(s,0));
	while(!q.empty()){
		head = q.top();
		q.pop();
		if(head.dis>dis[head.id])continue;
		for(int i=0;i<graph[head.id].size();i++){
			to=graph[head.id][i];
			if(dis[to.id]>dis[head.id]+to.dis){
				dis[to.id]=dis[head.id]+to.dis;
				q.push(mkNode(to.id,dis[to.id]));
			}
		}
	}
}
int ans=0;
int main(){
	int u,v,w;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ticket[i];
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		graph[u].push_back(mkNode(v,w*2)); 
		graph[v].push_back(mkNode(u,w*2));
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
		ans=0x3f3f3f;
		for(int j=1;j<=n;j++){
			cout<<dis[i]<<' ';
			ans=min(dis[i],ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}
