#include<bits/stdc++.h>
using namespace std;
pair<int,int> col[1010],row[1010];
int n,m,q;
int main() {
	int t,x,y;
	cin>>n>>m>>q;
	for(int i=1; i<=q; i++) {
		cin>>t>>x>>y;
		if(t==1)row[x]=make_pair(y,i);
		if(t==2)col[x]=make_pair(y,i);
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(row[i].second>col[j].second)cout<<row[i].first<<' ';
			else if(row[i].second<col[j].second)cout<<col[j].first<<' ';
			else cout<<0<<' ';
		}
		cout<<endl;
	}
	return 0;
}
