#define INT_MAX     2147483647              //int值上限
#define INT_MIN     (-INT_MAX - 1)          //int值下限

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)                            // a negative number is surely not a palindrome number
            return false;
        int sum = 0;
        int xtemp = x;
        while(x!=0){
            if (sum > INT_MAX/10 || sum < INT_MIN/10){
                return false;
            }
            sum = sum*10+x%10;
            x /= 10;
        }
        if (sum == xtemp)
            return true;
        else
            return false;
    }
};
