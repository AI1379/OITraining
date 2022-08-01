#include<bits/stdc++.h>
using namespace std;
int f[100010];
int p[100010];
int n;
pair<int,bool> sol[100010];
deque<pair<int,int> > q1;//+p   first:p second:pos
deque<pair<int,int> > q2;//+p+1
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i];
	memset(f,0x3f,sizeof(f));
	f[1]=0;
	q1.push_back(make_pair(1+p[1],1));
	q2.push_back(make_pair(1+p[1],1));
	for(int i=2;i<=n+1;i++){
		while(!q1.empty()&&q1.front().first<i)q1.pop_front();
		while(!q2.empty()&&q2.front().first+1<i)q2.pop_front();
		if(!q1.empty()){
			f[i]=f[q1.front().second];
			sol[i].first=q1.front().second;
			sol[i].second=false;
		}
		else if(!q2.empty()){
			f[i]=f[q2.front().second]+1;
			sol[i].first=q2.front().second;
			sol[i].second=true;
		}
		while(!q1.empty()&&f[q1.back().second]>f[i])q1.pop_back();
		q1.push_back(make_pair(i+p[i],i));
		while(!q2.empty()&&f[q2.back().second]>f[i])q2.pop_back();
		q2.push_back(make_pair(i+p[i],i));
	}
	cout<<f[n+1]<<endl;
	stack<int>stk;
	int tmp=n+1;
	while(tmp!=0){
		if(sol[tmp].second)stk.push(sol[tmp].first);
		tmp=sol[tmp].first;
	}
	while(!stk.empty()){
		cout<<stk.top()<<' ';
		stk.pop();
	}
	return 0;
}
