#include <iostream>
#include <numeric>

int main() {
	int t;
	std::cin >> t;
	
	while (t-- != 0) {
		int n;
		std::cin >> n;
		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			std::cin >> arr[i];
		}
		
		if (n == 1) {
			std::cout << arr[0] << std::endl;
		} else {
			std::cout << std::gcd(arr[0], arr[n - 1]) << std::endl;
		}
	}
}