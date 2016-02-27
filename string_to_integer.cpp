class Solution {
public:
    int myAtoi(string str) {
        int i;
        int strSize = str.size();
        string rslt_str;
        int rslt_int;
        bool negative = false;
        bool sig = false;   //判断一开始是否有正负号
        for(i=0; i<strSize; i++){
            if (rslt_str.empty() && sig==false && str[i]==' ')  //前面有空串时，前面无符号时，空格都忽略掉
                    continue;
            if (rslt_str.empty() && (str[i]==43 || str[i]==45)){    //has or not '+'/'-'
                if (str[i] == 43){       // first element is '+'
                    if (sig == true)        //如果前面已经有正负号了，直接退出返回0
                        return 0;
                    negative = false;
                    sig = true;
                    continue;
                }
                else{                   //  first element is '-'
                    if (sig == true)        //如果前面已经有正负号了，直接退出返回0
                        return 0;
                    negative = true;
                    sig = true;
                    continue;
                }
            }
            else{
                if (str[i]>=48 && str[i]<=57)   // str[i] is a number
                    rslt_str.push_back(str[i]);
                else
                    break;
            }
        }
        int rslt_size = rslt_str.size();        // how long does the rslt_int
        if (rslt_size == 0)
            return 0;
        i = 0;
        rslt_int = 0;
        int temp;
        while (rslt_size != 0){                 // convert to integer
            temp = negative?-rslt_int:rslt_int;    //temp是上一次循环的答案(with '+/-')
            rslt_int = rslt_int*10+(int)rslt_str[i]-48;
            if ((negative? -rslt_int : rslt_int)/10 != temp){  //is overflow
                return negative? INT_MIN : INT_MAX;
            }
            i++;
            rslt_size --;
        }
        return negative? -rslt_int : rslt_int;
    }
};
