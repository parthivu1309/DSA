class ProductOfNumbers {

    private ArrayList<Integer> arr;

    public ProductOfNumbers() {
        arr = new ArrayList<>();
    }
    
    public void add(int num) {
        arr.add(num);
    }
    
    public int getProduct(int k) {
        int product = 1;

        for (int i = arr.size() - 1; i >= arr.size() - k; i--) {
            product *= arr.get(i);
        }

        return product;
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */