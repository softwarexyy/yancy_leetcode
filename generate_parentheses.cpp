class Solution {
public:
    void generate(int rightcount, int leftcount, string s, vector<string>& res) {
        if (rightcount==0 && leftcount==0) {
            res.push_back(s);
        }
        if (leftcount > 0) {
            generate(rightcount, leftcount-1, s+'(', res);
        }
        if (rightcount>0 && rightcount>leftcount) {
            generate(rightcount-1, leftcount, s+')', res);
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> res;
        generate (n,n,s,res);
        return res;
    }
};

/********************************************************************************************
第1到2n个位置都满足如下规则：左括号的个数大于等于右括号的个数。
所以，我们就可以按照这个规则去打印括号：
  假设在位置k我们还剩余left个左括号和right个右括号，如果left>0，则我们可以直接打印左括号，而不违背规则。
能否打印右括号，我们还必须验证left和right的值是否满足规则，
如果left>=right，则我们不能打印右括号，因为打印会违背合法排列的规则，否则可以打印右括号。
如果left和right均为零，则说明我们已经完成一个合法排列，可以将其打印出来。
**************************************************************************************/
