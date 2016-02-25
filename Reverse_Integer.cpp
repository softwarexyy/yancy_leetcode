#define INT_MAX     2147483647              //int值上限
#define INT_MIN     (-INT_MAX - 1)          //int值下限

class Solution {
public:
    int reverse(int x) {
        int sum = 0;
        for (x; x!=0; x/=10){
            if (sum>INT_MAX/10 || sum<INT_MIN/10)   //提前一个循环判溢出，否则等到真的溢出时是无法判断的
                return 0;
            sum = sum*10 + x%10;
        }
    
        return sum;
    }
};
