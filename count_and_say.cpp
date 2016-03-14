class Solution {
public:
    string countAndSay(int n) {
        string res;
        if (n==1)
            return "1";
        if (n>1){
            string temp = countAndSay(n-1);
            int i = 0;
            while ( i < temp.size() ){
                char val = temp[i];
                int cnt = 0;
                while (i<temp.size() && temp[i]==val){
                    i++;
                    cnt ++;
                }
                res.push_back('0'+cnt);
                res.push_back(val);
            }
        }
        return res;
    }
};

//方法：递归，用上一次的结果得到新的结果
//  遍历字符串中的每个字符，相同的一串记下来，比如有连在一起的cnt个的相同的某数val，则下一个字符串中记成cnt val，
//  要记得将int型的cnt和val转为字符型，即：(char)cnt+48, (char)val+48
