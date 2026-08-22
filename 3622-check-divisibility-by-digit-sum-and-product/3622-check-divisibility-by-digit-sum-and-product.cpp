class Solution {
public:
    int digitSum(int n){
        int sum = 0;
        while(n > 0){
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
    int productSum(int n){
        int sum = 1;
        while(n > 0){
            sum *= n % 10;
            n = n / 10;
        }
        return sum;
    }
    bool checkDivisibility(int n) {
        int digit_sum = digitSum(n);
        int product_sum = productSum(n);

        if(n % (digit_sum + product_sum) == 0) return true;
        else return false;
    }
};