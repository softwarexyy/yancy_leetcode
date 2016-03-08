class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0 || (dividend==INT_MIN && divisor==-1))   //当dividend=-2147483648(INT_MIN)时，且divisor=-1时，得出的答案2147483648是溢出的(>INT_MAX)
            return INT_MAX;
        int res = 0;
        bool negative = false;
        if((dividend<0&&divisor>0) || (dividend>0&&divisor<0))
            negative = true;
        
        long long dividend1=abs((long long)dividend);   //使用longlong类型, 暂不考虑int溢出的问题
        long long divisor1=abs((long long)divisor);
        long long temp = 0;
        while(divisor1 <= dividend1){
            int count = 1;
            temp = divisor1;
            while((temp<<=1) <= dividend1)
                count <<= 1;
            res += count;
            dividend1 -= (temp>>1);
        }
        return (int)negative? -res : res;
    }
};
