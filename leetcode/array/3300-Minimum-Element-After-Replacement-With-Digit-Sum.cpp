class Solution {
public:
    int minElement(vector<int>& nums) {
        int min = std::numeric_limits<int>::max();

        for (int i: nums) {
            min = std::min({sum_of_digits(i), min});
        }
        
        return min;
    }
    int sum_of_digits(int n) {
        int ans = 0;
        while (n != 0) {
            ans += n % 10;
            n /= 10;
        }

        return ans;
    }
};