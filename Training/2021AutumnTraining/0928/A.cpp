#include<bits/stdc++.h>
using namespace std;
string in;
string str[4];
int main(){
	cin>>in;
	for(int i=0;i<in.length();i++){
		if('a'<=in[i]&&in[i]<='z')str[0].push_back(in[i]);
		else if('A'<=in[i]&&in[i]<='Z')str[1].push_back(in[i]);
		else if('0'<=in[i]&&in[i]<='9')str[2].push_back(in[i]);
		else str[3].push_back(in[i]);
	}
	int level=0;
	for(int i=0;i<4;i++){
		if(!str[i].empty())level++;
	}
	cout<<"password level:"<<level<<endl;
	for(int i=0;i<4;i++){
		if(!str[i].empty())cout<<str[i]<<endl;
		else cout<<"(Null)"<<endl;
	}
	return 0;
}
