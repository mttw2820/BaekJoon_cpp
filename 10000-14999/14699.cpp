#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct shelter {
	int index;
	int height;
	vector<int> conn;
};

bool height(shelter a, shelter b) {
	return a.height < b.height;
}

int main() {
	int n, m, x, y;
	scanf("%d %d", &n, &m);
	vector<shelter> v(n);
	vector<int> dp(n, 1);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i].height);
		v[i].index = i;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		x--; y--;
		if (v[x].height > v[y].height) {
			v[x].conn.push_back(y);
		}
		else {
			v[y].conn.push_back(x);
		}
	}
	sort(v.begin(), v.end(), height);
	
	for (int i = n-1; i >=0; i--) {
		for (int next : v[i].conn) {
			if (dp[next] == 1)
				dp[next] += dp[v[i].index];
			else {
				if (dp[next] < 1 + dp[v[i].index])
					dp[next] = 1 + dp[v[i].index];
			}
		}
	}
	
	for (int i = 0; i < n; i++)
		printf("%d\n", dp[i]);
	

	return 0;
}