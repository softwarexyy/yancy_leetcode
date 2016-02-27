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
        return (sum == xtemp);
    }
};

/*******   this is another method *********
class Solution {
public:
    bool isPalindrome(int x) {
        int result = 0;
        int num = x;
        while (num>0){
            int tmp = result;
            result = result*10 + num%10;
            if ((result/10)!=tmp) return false; //will return false if overflow
            num/=10;
        }
        return result==x;
    }
};
*/
