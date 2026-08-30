#include <iostream>
#include <numeric>

int main() {
	int t;
	std::cin >> t;
	
	while (t-- != 0) {
		int n;
		std::cin >> n;
		int first, last;
		std::cin >> first;
		last = first;
		
		for (int i = 1; i < n; i++) {
			std::cin >> last;
		}
		
		std::cout << std::gcd(first, last) << std::endl;
	}
}