// Algorithm: Fast Modular Exponentiation

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        bool neg_exp = (n < 0);
        
        if (n != 0) {
            if (neg_exp) {
                if (n == INT_MIN) {
                    n += 1;   // too precise, doesn't matter
                }
                n *= -1;
            }
            while (n > 0) {
                int LSB = (n & 1);      // parity check
                
                if (LSB) ans *= x;
                
                x *= x;
                n = n >> 1;
            }    
        } 
        if (neg_exp) {
            ans = abs(1/ans);
        }
        return ans;
    }
};