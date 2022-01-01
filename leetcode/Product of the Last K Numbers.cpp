class ProductOfNumbers {
    vector<int> products;
    
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num == 0) {
            products.clear();
            return;
        }
        if (products.size() == 0) {
            products.push_back(num);
        } else {
            products.push_back(num * products.back());
        }
    }
    
    int getProduct(int k) {
        if (products.size() == k) {
            return products.back();
        } 
        if (products.size() < k) {
            return 0;
        }
        int leftSide = *(products.end() - k - 1);
        return products.back() / leftSide;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
