#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
struct node{
	int x,y,num;
	int fx,fy;
	node(int a,int b,int c,int d,int e):x(a),y(b),num(c),fx(d),fy(e){}
};
int n,m;
char mp[2510][2510];
int bfsn[2510][2510];
bool vis[2510][2510];
void solve(){
	cin>>n>>m;
	getchar();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			mp[i][j]=getchar();
		}
		getchar();
	}
	int x,y;
	queue<node>q;
	node t(0,0,0,0,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!vis[i][j]){
				x=i;y=j;
				vis[i][j]=true;
				q.push(node(i,j,1,i,j));
				bfsn[i][j]=1;
				while(!q.empty()){
					t=q.front();
//					cout<<t.x<<' '<<t.y<<' '<<t.num<<endl;
					q.pop();
					for(int k=0;k<4;k++){
//						if(t.x+dx[k]==x&&t.y+dy[k]==y&&t.num>=4){
//							cout<<"Yes"<<endl;
//							return;
//						}
						if(vis[t.x+dx[k]][t.y+dy[k]]
						   &&t.x+dx[k]!=t.fx&&t.y+dy[k]!=t.fy
						   &&mp[t.x+dx[k]][t.y+dy[k]]==mp[x][y]
						   &&bfsn[t.x][t.y]+bfsn[t.x+dx[k]][t.y+dy[k]]-1>=4){
							cout<<"Yes"<<endl;
							return;
						}
						if(!vis[t.x+dx[k]][t.y+dy[k]]&&mp[t.x+dx[k]][t.y+dy[k]]==mp[x][y]
							&&0<t.x+dx[k]&&t.x+dx[k]<=n
							&&0<t.y+dy[k]&&t.y+dy[k]<=m){
							q.push(node(t.x+dx[k],t.y+dy[k],t.num+1,t.x,t.y));
							vis[t.x+dx[k]][t.y+dy[k]]=true;
							bfsn[t.x+dx[k]][t.y+dy[k]]=t.num;
						}
					}
				}
				cout<<endl;
			}
		}
	}
	cout<<"No"<<endl;
	return;
}
int main(){
	solve();
	return 0;
}
