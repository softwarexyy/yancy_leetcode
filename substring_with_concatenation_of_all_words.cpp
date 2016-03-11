class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        
        int i;
        map<string, int> m;                 //建立映射字典
        for (i=0; i<words.size(); i++)
            m[words[i]]++;
    
        int word_len = words[0].size();     //每个单词的长度（都相等）
        for(i=0; i+words.size()*word_len <= s.size(); i++){
            int j = i;
            int k = 0;  
            // k统计所有匹配的单词个数，如果k==words.size()，就代表都匹配完毕，那么就将i纳入结果中
            map<string, int> m1;
            while(k<words.size()){        // 1 选择字符串; 2 进行匹配对比
                string temp = s.substr(j, word_len);
                map<string, int>::iterator findCur;
                findCur = m.find(temp);
                if (findCur == m.end()){        // 没有匹配
                    break;
                }
                else{                           // 有匹配
                    m1[temp]++;
                    if (m1[temp] > m[temp]){    // 有匹配但次数重复过多
                        break;
                    }
                    else{
                        j += word_len;
                        k ++;
                    }
                }
            }
            if (k==words.size())
                res.push_back(i);
        }
        return res;
    }
};
