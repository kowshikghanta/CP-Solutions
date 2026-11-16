
class Solution {
public:
    string digitSum(string s, int k) {
        
        while (s.size() > k) {
            string temp = "";

            for (int i = 0; i < (s.size() + k - 1) / k; i++) {
                int sod = 0;

                for (int j = 0; j < k && i * k + j < s.size(); j++) {
                    sod += s[i * k + j] - '0';
                }

                temp += to_string(sod);
            }

            s = temp;
        }

        return s;
    }
};
