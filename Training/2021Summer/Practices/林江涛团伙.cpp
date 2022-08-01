#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[1010];
int enemy[1010];
int fd(int x){
	return fa[x]=(fa[x]==x?fa[x]:fd(fa[x]));
}
void un(int x,int y){
	int a=fd(x),b=fd(y);
	if(a!=b)fa[a]=b;
}
int main(){
	char opt;
	int x,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>opt>>x>>y;
		if(opt == 'F'){
			un(x,y);
		}
		else{
			if(!enemy[x])enemy[x]=y;
			else un(enemy[x],y);
			if(!enemy[y])enemy[y]=x;
			else un(enemy[y],x);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(fd(i)==i){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
