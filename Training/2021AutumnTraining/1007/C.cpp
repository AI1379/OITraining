#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
int n,v;
vector<pair<int,double> > graph[110];
int mp[110][110];
pair<int,int> pos[110];
double dis[110];
__gnu_pbds::priority_queue<pair<double,int>,greater<pair<double,int> > > q;
__gnu_pbds::priority_queue<pair<double,int>,greater<pair<double,int> > >::point_iterator its[110];
void dijkstra(int s){
	for(int i=1;i<=n;i++){
		its[i]=q.push(make_pair(1e9,i));
		dis[i]=1e9;
	}
	q.modify(its[s],make_pair(0,s));
	dis[s]=0.00;
	int u;
	while(!q.empty()){
		u=q.top().second;q.pop();
		for(int i=0;i<graph[u].size();i++){
			if(dis[graph[u][i].first]>dis[u]+graph[u][i].second){
				dis[graph[u][i].first]=dis[u]+graph[u][i].second;
				q.modify(its[graph[u][i].first],make_pair(dis[graph[u][i].first],graph[u][i].first));
			}
		}
	}
}
int main() {
	int x,y,f;
	int maxx=0,maxy=0;
	double t;
	cin>>n>>v;
	for(int i=1; i<=n; i++) {
		cin>>x>>y>>f;
		maxx=max(maxx,x);maxy=max(maxy,y);
		if(f!=0) {
			t=sqrt((pos[f].first-x)*(pos[f].first-x)+(pos[f].second-y)*(pos[f].second-y))/(double)(v);
			graph[i].push_back(make_pair(f,t));
			graph[f].push_back(make_pair(i,t));
		}
		pos[i]=make_pair(x,y);
		mp[x][y]=i;
	}
	for(int i=0;i<=maxx;i++){
		for(int j=maxy;j>=0;j--){
			if(mp[i][j]!=0){
				for(int k=j-1;k>=0;k--){
					if(mp[i][k]!=0){
						graph[mp[i][j]].push_back(make_pair(mp[i][k],sqrt((j-k)*2.0/10.0)));
					}
				}
			}
		}
	}
	dijkstra(1);
	cout<<fixed<<setprecision(2)<<dis[n]<<endl;
	return 0;
}
