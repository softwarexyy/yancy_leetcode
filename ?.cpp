class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n>1){
            vector<string> resTmp = generateParenthesis(n-1);   //recursive
            vector<string> newResTmp;
            int i;
            for(i=0; i<resTmp.size(); i++){
                newResTmp.push_back("(" + resTmp[i] + ")");
            }
            for(i=0; i<resTmp.size(); i++){
                bool allPair = true;                        //判断是否多对括号相连
                for (int j=1; j<resTmp[i].size(); j++){
                    string strTmp = resTmp[i];
                    if (strTmp[j] == strTmp[j-1]){
                        allPair = false;
                        break;
                    }
                }
                if (!allPair){
                    newResTmp.push_back(resTmp[i] + "()");
                    newResTmp.push_back("()" + resTmp[i]);
                }
                else {       //如果是多对括号相连的状况
                    newResTmp.push_back(resTmp[i] + "()");
                }
            }
            return newResTmp;
        }
        if (n==1){
            vector<string> resTmp;
            resTmp.push_back("()");
            return resTmp;
        }
    }
};
