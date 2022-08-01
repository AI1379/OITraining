#include<bits/stdc++.h>
using namespace std;
int maxw,len,n;
int w[1010],s[1010];
int prew[1010];
double t[1010];
double pret[1010][1010];
double f[1010];
int main(){
	cin>>maxw>>len>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i]>>s[i];
		t[i]=(double)(len)/(double)(s[i]);
		prew[i]=prew[i-1]+w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			pret[i][j]=fmax(pret[i][j-1],t[j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int p=i-1;p>0&&prew[i]-prew[p];p--){
			f[i]=fmin(f[i],f[p]+pret[p+1][i]);
		}
	}
	printf("%.1lf\n",f[n]);
	return 0;
}

