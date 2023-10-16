#include <iostream>
using namespace std;
const int maxn = 2e6;
bool vis[2000005];
int prime[2000005], a[maxn], cnt;
void init(){
	for(int i = 2; i < maxn; i++){
		if(!vis[i]){
			prime[++cnt] = i;
		}
		for(int j = 1; j <= cnt && i * prime[j] < maxn; j++){
			vis[i*prime[j]] = 1; 
			if(i % prime[j] == 0)	break;
		}
	}
}
int main(){
	init();
	int n, ans;
	cin >> n;
	ans = n - 1;
	for (int i = 1; i <= n; i++)   cin >> a[i];
	int ww, yy;
	for (int i = 1; i < n; i++) {
		cin >> ww >> yy;
		if (vis[a[ww] + a[yy]])    ans--;
	}
	cout << ans << endl;
	return 0;
}
