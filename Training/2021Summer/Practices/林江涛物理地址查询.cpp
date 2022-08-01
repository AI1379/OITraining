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
int n;
vector<node>graph[1010]; 
priority_queue<node>q;
int dis[1010];
void dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	while(!q.empty())q.pop();
	node head, to;
	q.push(mkNode(s,0));
	dis[s]=0;
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
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='x')
        	return -1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int ans=0;
int main(){
	int w;
	cin>>n;
	for(int u=2;u<=n;u++){
		for(int v=1;v<u;v++){
			w=read();
			if(w!=-1){
				graph[u].push_back(mkNode(v,w));
				graph[v].push_back(mkNode(u,w));
			}
		}
	}
	dijkstra(1);
	for(int i=1;i<=n;i++){
		ans=max(ans,dis[i]);
	}
	cout<<ans<<endl;
	return 0;
}
