class Solution {
public:
    string add(string& num1, string& num2){
        string res;
        int i;
        int size = num1.size()>num2.size() ? (num1.size()+1) : (num2.size()+1);
        for (i=0; i<size; i++)
            res.push_back('0');     //所有位初始化为'0'
            
        for (i=0; i<num1.size() && i<num2.size(); i++){
            int temp = res[i]-'0' + num1[i]-'0' + num2[i]-'0';
            res[i] = temp%10 + '0';
            res[i+1] = temp/10 + '0'; 
        }
        if (i==num1.size()){   //num1完毕
            for (i; i<num2.size(); i++){
                int temp = res[i]-'0' + num2[i]-'0';
                res[i] = temp%10 + '0';
                res[i+1] = temp/10 + '0';
            }
        }
        else{                   //num2完毕
            for (i; i<num1.size(); i++){
                int temp = res[i]-'0' + num1[i]-'0';
                res[i] = temp%10 + '0';
                res[i+1] = temp/10 + '0';
            }
        }
        
        if (res[size-1] == '0')
            res.erase(res.end()-1);
        
        return res;
    }
    
    string multi_single(string num1, char num2){
        string res;
        for (int i=0; i<num1.size()+1; i++)
            res.push_back('0');

        for (int i=0; i<num1.size(); i++){
            int tmpres = (num1[i]-'0') * (num2-'0') + (res[i]-'0');
            res[i] = tmpres%10 + '0';
            res[i+1] = tmpres/10 + '0';
        }
        if (res[res.size()-1] == '0')
            res.erase(res.end()-1);

        return res;
    }
    
    string multiply(string num1, string num2) {
        if (num1=="0" || num2=="0"){
            return "0";
        }
        string res;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i=0; i<num2.size(); i++){
            string tmpres = multi_single(num1, num2[i]);
            reverse(tmpres.begin(), tmpres.end());
            for (int j=0; j<i; j++)
                tmpres.push_back('0');
            reverse(tmpres.begin(), tmpres.end());
            res = add(res, tmpres);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//大数乘法，首先需实现字符串型大整数的相加 以及 一个整数和一个单位数字相乘(例如999*3)
