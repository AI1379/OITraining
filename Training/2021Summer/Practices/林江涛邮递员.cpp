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
vector<node>graph[2][1010]; 
priority_queue<node>q;
int dis[1010];
void dijkstra(int s,int p){
	memset(dis,0x3f,sizeof(dis));
	while(!q.empty())q.pop();
	node head, to;
	q.push(mkNode(s,0));
	dis[s]=0;
	while(!q.empty()){
		head = q.top();
		q.pop();
		if(head.dis>dis[head.id])continue;
		for(int i=0;i<graph[p][head.id].size();i++){
			to=graph[p][head.id][i];	
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
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		graph[0][u].push_back(mkNode(v,w));
		graph[1][v].push_back(mkNode(u,w));
	}
	dijkstra(1,0);
	for(int i=1;i<=n;i++){
		ans+=dis[i];
	}
	dijkstra(1,1);
	for(int i=1;i<=n;i++){
		ans+=dis[i];
	}
	cout<<ans<<endl;
	return 0;
}
