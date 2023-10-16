#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
char str[maxn]; bool flag[maxn];

int main() {
//	 freopen("8.in", "r", stdin);
//	 freopen("8.out", "w", stdout);
	cin >> (str + 1);
	int len = strlen(str + 1);
	int cnt = 0;
	for(int i = 1;i <= len / 2; ++i) {
		if(str[i] != str[len + 1 - i]) {
			char ch = min(str[i], str[len + 1 - i]);
			str[i] = ch;
			str[len + 1 - i] = ch;
			flag[i] = 1;
			++cnt;
		}
	}
	// cout << "test: " << cnt << '\n';
	for(int i = 1;i <= len / 2; ++i) {
		if(cnt == 2) break;
		if(flag[i] == true && cnt <= 1 && str[i] != 'a') {
			str[i] = 'a', str[len + 1 - i] = 'a';
			++cnt;
		} else if(flag[i] == false && cnt <= 0 && str[i] != 'a') {
			str[i] = 'a', str[len + 1 - i] = 'a';
			cnt += 2; 
		}
	}
	if(cnt <= 1 && len % 2 == 1)
		str[len / 2 + 1] = 'a';
	cout << (str + 1) << '\n';
	return 0;
}
