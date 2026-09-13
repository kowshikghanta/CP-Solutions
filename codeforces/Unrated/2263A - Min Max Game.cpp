#include<bits/stdc++.h>

int main() {
	int t;
	std::cin >> t;
	
	while (t-- != 0) {
		long long n;
		std::cin >> n;
		
		int count = 0;
		
		for (int i = 0; i < n; i++) {
			int temp;
			std::cin >> temp;
			if (temp == 1) {
				count++;
			}
		}
		
		if (count * 2 >= n) {
			std::cout << "Bessie" << std::endl;
		} else {
			std::cout << "Elsie" << std::endl;
		}
	}
}