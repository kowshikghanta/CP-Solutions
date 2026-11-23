
class ProductOfNumbers {
public:
    vector<int> list;

    ProductOfNumbers() {
        list.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            list.clear();
            list.push_back(1);
            return;
        }

        list.push_back(num * list.back());
    }
    
    int getProduct(int k) {
        int n = list.size();

        if (k >= n) {
            return 0;
        }

        return list[n - 1] / list[n - k - 1];
    }
};
