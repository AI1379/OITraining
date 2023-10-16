#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 100010; 
ll n;
char s[MAXN];
ll pos[3],tot = 0;
int main(){
	#ifndef DEBUG
	freopen("T2.in","r",stdin);
	freopen("T2.out","w",stdout);
	#endif
	scanf("%s",s+1);
	n = strlen(s+1);
	for(int i=1;i<=n/2;++i){
		if(s[i] != s[n-i+1])
			pos[++tot] = i;
	}
	if(tot == 0){
		for(int j=1;j<=n;++j){
			if(s[j] != 'a'){
				s[j] = s[n-j+1] = 'a';
				break;
			}
		}
	}else if(tot == 1){
		if(s[pos[1]]=='a' && n%2==1)
			s[n/2+1] = 'a';
		s[pos[1]] = s[n-pos[1]+1] = 'a';
	}else{
		s[pos[1]] = s[n-pos[1]+1] = min(s[pos[1]],s[n-pos[1]+1]);
		s[pos[2]] = s[n-pos[2]+1] = min(s[pos[2]],s[n-pos[2]+1]);
	}
	printf("%s\n",s+1);
	return 0;
}
