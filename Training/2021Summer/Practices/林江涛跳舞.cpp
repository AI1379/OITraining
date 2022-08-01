#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>graph[110];
queue<int>q;
int ans[110]; 
int main(){
	char tmp;
	int head;
	cin>>n;
	memset(ans,-1,sizeof(ans));
	for(int i=0;i<n;i++){
		getchar();
		for(int j=0;j<n;j++){
			tmp=getchar();
			if(tmp=='Y'){
				if(i==0&&j==1){
					cout<<0<<endl;
					return 0;
				}
				graph[i].push_back(j);
			}
		}
	}
	q.push(0);
	ans[0]=0;
	while(!q.empty()){
		head=q.front();
		q.pop();
		for(int i=0;i<graph[head].size();i++){
			if(ans[graph[head][i]]==-1){
				q.push(graph[head][i]);
				ans[graph[head][i]]=ans[head]+1;
				if(graph[head][i]==1){
					cout<<ans[graph[head][i]]-1<<endl;
					return 0;
				}
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}
