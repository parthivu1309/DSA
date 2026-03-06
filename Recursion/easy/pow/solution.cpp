/* Intution
x^n = (x^(n/2))^2 if n is even
x^n = x * (x^(n/2))^2 if n is odd
*/
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;

        // Handle negative exponent
        long long N = n;   // prevent overflow
        if(N < 0){
            x = 1/x;
            N = -N;
        }

        double half = myPow(x, N/2);

        if(N % 2 == 0)
            return half * half;
        else
            return x * half * half;
    }
};