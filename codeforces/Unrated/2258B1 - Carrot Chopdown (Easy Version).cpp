#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int t;
	std::cin >> t;
	
	while (t-- != 0) {
		int n, m;
		std::cin >> n >> m;
		std::vector<int> frequency(m + 1, 0);
		for (int i = 0; i < n; i++) {
			int x;
			std::cin >> x;
			frequency[x]++;
		}
		
		int lesser = 0;
		int ans = 0;
		
		for (int i = 0; i < m + 1; i++) {
			lesser += frequency[i];
			int extra = 0;
			if (i * 2 < m + 1) {
				extra = frequency[i * 2];
			}
			ans = std::max(ans, frequency[i] + (n - lesser) + extra);
		}
		std::cout << ans << std::endl;
	}
}