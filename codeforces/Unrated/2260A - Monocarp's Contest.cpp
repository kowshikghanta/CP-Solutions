#include <iostream>
#include <vector>

int main() {
	int t;
	std::cin >> t;
	
	while (t-- != 0) {
		int n;
		std::cin >> n;
		std::vector<int> arr;
		int zeros = 0;
		for (int i = 0; i < n; i++) {
			int temp;
			std::cin >> temp;
			if (temp == 0) {
				zeros++;
			}
			arr.push_back(temp);
		}
		if (arr[0] == 0 && arr[n - 1] == 0) {
			std::cout << 0 << std::endl;
		} else if ((arr[0] == 0 && arr[n - 1] == 1 || arr[0] == 1 && arr[n - 1] == 0) && zeros >= 2) {
			std::cout << 1 << std::endl;
		} else if (arr[0] == 1 && arr[n - 1] == 1 && zeros >= 2) {
			std::cout << 2 << std::endl;
		} else {
			std::cout << -1 << std::endl;
		}
		
	}
}