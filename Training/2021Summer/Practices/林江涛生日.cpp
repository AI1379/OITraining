#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n,m;
int fa[maxn];
int fd(int x){
	return fa[x]=(fa[x]==x?fa[x]:fd(fa[x]));
}
void un(int x,int y){
	int a=fd(x),b=fd(y);
	if(a!=b)fa[a]=b;
}
int main(){
	int x,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		un(x,y);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(fd(i)==i)ans++;
	}
	cout<<ans<<endl;
	return 0;
}
