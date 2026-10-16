class Solution {
public:
    bool threeFibonacciSum(int n) {
        int first = 0;
        int second = 1;
        int third = first + second;

        while(first + second + third < n){
            int temp = third;
            third = third + second;
            first = second;
            second = temp;
        }

        if(first + second + third == n)return true;
        else return false;
    }
};