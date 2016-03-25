class Solution {
public:
    double myPow1(double x, int n){
        if (n==0)
            return 1;
        double tmp = myPow1(x, n/2);
        if (n%2 == 0){
            return tmp*tmp;
        }
        else{
            return tmp*tmp*x;
        }
    }
    double myPow(double x, int n) {
        if (n < 0)
            return 1/myPow1(x, -n);
        else
            return myPow1(x, n);
    }
};






//方法：
// x^n = x^(n/2) * x^(n/2)          (当n是偶数时)
// x^n = x^(n/2) * x^(n/2) * x      (当n是奇数时)
