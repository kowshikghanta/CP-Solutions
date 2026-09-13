#include<bits/stdc++.h>

int main() {
	int t;
	std::cin >> t;
	
	while (t-- != 0) {
		long long n, k;
		std::cin >> n;
		std::cin >> k;
		
		
		if (n > k || 2 * n == k) {
			std::cout << -1 << std::endl;
			continue;
		}
		
		std::vector<std::vector<int>> ans(n, std::vector<int>(n, 0));
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans[i][j] = i * n + j + 1;
			}
		}
		
		int idx = 0;
		for (int i = 2 * n - 1; i > k; i--) {
			int temp = ans[0][idx];
			ans[0][idx] = ans[idx + 1][idx];
			ans[idx + 1][idx] = temp;
            idx++;
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << ans[i][j] << " ";
			}
			std::cout << std::endl;
 		}
	}
}