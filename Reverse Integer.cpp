#define INT_MAX     2147483647
#define INT_MIN     (-INT_MAX - 1)

class Solution {
public:
    int reverse(int x) {
        int sum = 0;
        for (x; x!=0; x/=10){
            if (sum>INT_MAX/10 || sum<INT_MIN/10)
                return 0;
            sum = sum*10 + x%10;
        }
    
        return sum;
    }
};
