#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int cas;
int n,m;
int fa[maxn];
int fd(int x){
	return fa[x]=(fa[x]==x?fa[x]:fd(fa[x]));
}
bool un(int x,int y){
	int a=fd(x),b=fd(y);
	if(a==b)return false;
	return fa[a]=b;
}
int main(){
	int x,y;
	bool flag;
	cin>>cas;
	while(cas--){
		flag = true;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			if(!un(x,y)){
				cout<<"Yes"<<endl;
				flag = false;
//				break;
			}
		}
		if(flag){
			cout<<"No"<<endl;
		} 
	}
	return 0;
} 
