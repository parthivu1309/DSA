class Solution {
public:
    int reverse(int &n){
        int temp = n;
        int count = 0;
        while(temp != 0){
            temp/=10;
            count++;
        }
        int ans = 0;
        for(int i = 0; i < count; i++){
            ans += (n%10)*pow(10,count-1-i);
            n/=10;
        }

        return ans;
    }
    int mirrorDistance(int n) {
        return abs(n - reverse(n));
    }
};