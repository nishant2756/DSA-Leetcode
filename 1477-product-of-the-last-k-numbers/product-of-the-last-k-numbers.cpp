class ProductOfNumbers {
    vector<int> prefix;  // prefix[i] = product of the first i numbers since the last zero
public:
    ProductOfNumbers() {
        prefix.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            prefix.clear();
            prefix.push_back(1);   // reset: any window spanning this zero has product 0
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {
        int n = prefix.size();
        if (k >= n) return 0;      // window reaches back past the last zero
        return prefix.back() / prefix[n - 1 - k];
    }
};