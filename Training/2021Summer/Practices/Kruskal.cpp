#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to;
	int value;
};
edge edges[200010];
int n,m;
int num,ans;
int fa[5010];
bool cmp(edge a,edge b){
	return a.value<b.value;
}
int fd(int x){
	return fa[x]=(fa[x]==x?fa[x]:fd(fa[x]));
}
void un(int x,int y){
	int a=fd(x),b=fd(y);
	if(a!=b)fa[a]=b;
}
int main(){
	int x,y,z;
	edge tmp;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		tmp.from=x;tmp.to=y;tmp.value=z;
		edges[i]=tmp;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(edges+1,edges+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(fd(edges[i].from)!=fd(edges[i].to)){
			un(edges[i].from,edges[i].to);
			ans+=edges[i].value;
			num++;
		}
	}
	if(num!=n-1){
		cout<<"orz"<<endl;
	}
	else{
		cout<<ans<<endl;
	}
	return 0;
}
