class Solution {
public:
    //count thr number of set bit
    int setBit(int n){
        int count = 0;
        while(n > 0){
            if(n % 2) count++;
            n /= 2;
        }
        return count;
    }
    int calculateScore(int a, int b) {

        int n = setBit(a);
        int m = setBit(b);

        if(n >= m) return (n * m);
        else return (m / n);
    }
};