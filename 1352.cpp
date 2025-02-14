class ProductOfNumbers {
public:
    ProductOfNumbers() {
    }
    
    void add(int num) {
        vec.push_back(num);
    }
    
    int getProduct(int k) {
        int product = 1;
        for (int i = vec.size() - k; i < vec.size(); i++) {
            product *= vec[i];
        }
        return product;
        
    }

    vector<int> vec;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
