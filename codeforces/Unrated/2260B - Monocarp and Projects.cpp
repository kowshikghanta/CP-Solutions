#include<bits/stdc++.h>

int main() {
	int t;
	std::cin >> t;
	
	while (t-- != 0) {
		long long x, y, k, ans = 0;
		std::cin >> x;
		std::cin >> y;
		std::cin >> k;
		
		for (long long i = 0; i < std::min(y, k); i++) {
			ans += (y + i) % (x + i);
		}
		long long full = std::max(0ll, k - y);
		full *= (y - x);
		std::cout << ans + full << std::endl;
	}
}