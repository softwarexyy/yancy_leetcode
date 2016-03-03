class Solution {
public:
    bool isValid(string s) {
        string stackDemo;
        stackDemo.push_back(s[0]);
        for(int i=1; i<s.size(); i++){  
            if (s[i]==')' && stackDemo[stackDemo.size()-1]=='(' ){
                stackDemo.pop_back();
                continue;
            }
            if (s[i]==']' && stackDemo[stackDemo.size()-1]=='['){
                stackDemo.pop_back();
                continue;
            }
            if (s[i]=='}' && stackDemo[stackDemo.size()-1]=='{'){
                stackDemo.pop_back();
                continue;
            }
            stackDemo.push_back(s[i]);  //与栈顶不匹配，压入栈中
        }
        if (stackDemo == "")
            return true;
        else
            return false;
    }
};
