#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int n,k;
bool mp[510][510];
bool vis[510][510];
int fa[250010];
inline int pos(int x,int y) {
	return (x-1)*n+y;
}
int find(int x){
	if(fa[x]==x)return x;
	else return (fa[x]=find(fa[x]));
}
int main() {
	string str;
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>str;
		for(int j=0; j<n; j++) {
			mp[i][j]=(str[j]=='.');
			fa[pos(i,j)]=pos(i,j);
		}
	}
	queue<pair<int,int> > q;
	pair<int,int>tmp;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!vis[i][j]){
				q.push(make_pair(i,j));
				while(!q.empty()){
					tmp=q.top();q.pop();
					for(int k=0;k<4;k++){
						if(!vis[tmp.first+dx[k]][tmp.second+dy[k]]&&
							0<tmp.first+dx[k]&&tmp.first+dx[k]<=n&&
							0<tmp.second+dy[k]&&tmp.second+dy[k]<=n){
							q.push(make_pair(tmp.first+dx[k],tmp.second+dy[k]));
							vis[tmp.first+dx[k]][tmp.second+dy[k]]=true;
							fa[find(pos(tmp.first+dx[k],tmp.second+dy[k]))]=find(pos(tmp.first,tmp.second));
						}
					}
				}
			}
		}
	}
}
