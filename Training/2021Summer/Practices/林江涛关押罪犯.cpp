#include<bits/stdc++.h>
using namespace std;
struct rel{
	int a,b;
	int c;
	bool operator<(const rel &x)const{
		return c<x.c;
	}
};
int n,m;
int fa[20010];
int enemy[20010];
int fd(int x){
	return fa[x]=(fa[x]==x?fa[x]:fd(fa[x]));
}
void un(int x,int y){
	int a=fd(x),b=fd(y);
	if(a!=b)fa[a]=b;
}
priority_queue<rel> relations;
int main(){
	int x,y,z;
	rel tmp;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		tmp.a=x;tmp.b=y;tmp.c=z;
		relations.push(tmp); 
	}
	while(!relations.empty()){
		x=fd(relations.top().a);
		y=fd(relations.top().b);
		if(x==y){
			cout<<relations.top().c<<endl;
			return 0;
		}
		if(!enemy[relations.top().a])enemy[relations.top().a]=relations.top().b;
		else un(enemy[relations.top().a],relations.top().b);
		if(!enemy[relations.top().b])enemy[relations.top().b]=relations.top().a;
		else un(enemy[relations.top().b],relations.top().a);
		relations.pop();
	}
	cout<<"0"<<endl;
	return 0;
}
