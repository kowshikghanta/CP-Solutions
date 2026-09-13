struct CompareIdx1 {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        return a[1] < b[1];
    }
};


class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        std::vector<int> ans(n, -1);
        std::priority_queue<vector<int>, vector<vector<int>>, CompareIdx1> pq;
        std::unordered_map<int, int> freq;

        for (int i: barcodes) {
            freq[i]++;
        }

        for (const auto& [key, value] : freq) {
            vector<int> temp;
            temp.push_back(key);
            temp.push_back(value);
            pq.push(temp);
        }

        vector<int> prev = {-1, 0};

        for (int i = 0; i < n; i++) {
            vector<int> temp = pq.top();
            pq.pop();

            ans[i] = temp[0];
            temp[1]--;

            if(prev[1] > 0) {
                pq.push(prev);
            }

            prev = temp;
        }
        
        return ans;
    }
};