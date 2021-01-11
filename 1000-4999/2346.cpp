//BaekJoon_2346
//«≥º± ≈Õ∂ﬂ∏Æ±‚
/*
* ¡¶«— Ω√∞£ : 2s
* ¡§¥‰ ∫Ò¿≤ : 39.080%
*/


#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
	int n, step = 0, now = 0;
	cin >> n;
	vector <pair<int, int>> balloons(n);
	for (int i = 0; i <n; i++) {
		balloons[i].first = i+1;
		cin >> balloons[i].second;
	}
	
	while (n != 0) {
		step = balloons[now].second;
		cout << balloons[now].first << " " ;
		
		//«≥º± ≈Õ∂ﬂ∏Æ±‚
		balloons.erase(balloons.begin() + now, balloons.begin() + now + 1);
		if (step > 0) now--;
		now += step;
		n--;
		if (n == 0) break;
		while (now < 0) 
			now += n;
		if (now >= n) now%=n;
	}

	return 0;
}