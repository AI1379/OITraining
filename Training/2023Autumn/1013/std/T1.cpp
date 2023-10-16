#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n, k, a, minn = 1e9 + 1, sum = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a;
		minn = min(minn, a);
		sum += a;
	}
	if(n == 1)	cout << a << endl;
	else 
	cout << (k == 2 ? minn : (sum - 2 * minn)) << endl;
}
