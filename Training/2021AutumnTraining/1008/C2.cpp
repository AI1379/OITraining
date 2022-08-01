#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int t;
int n,m;
char mp[2510][2510];
int vis[2510][2510];
bool dfs(int x,int y,int ex,int ey,int dep){
	for(int k=0;k<4;k++){
		if(x+dx[k]==ex&&y+dy[k]==ey&&dep>=4)return true;
		if(vis[x+dx[k]][y+dy[k]]!=t
			&&mp[x+dx[k]][y+dy[k]]==mp[ex][ey]
			&&0<x+dx[k]&&x+dx[k]<=n
			&&0<y+dy[k]&&y+dy[k]<=m){
			vis[x+dx[k]][y+dy[k]]=t;
			if(dfs(x+dx[k],y+dy[k],ex,ey,dep+1))return true;
			vis[x+dx[k]][y+dy[k]]=-1;
		}
	}
	return false;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>(mp[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			vis[i][j]=t;
			if(dfs(i,j,i,j,1)){
				cout<<"Yes"<<endl;
				return;
			}
			vis[i][j]=-1;
		}
	}
	cout<<"No"<<endl;
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
