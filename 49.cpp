class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 新建一个map，其中键是已排序的单词，对应的值是这个单词的所有异位词
        unordered_map<string, vector<string>> words;
        for (string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            words[key].emplace_back(str);
        }

        vector<vector<string>> ret;
        for (auto it = words.begin(); it != words.end(); it++) {
            ret.push_back(it->second);
        }
        return ret;
    }
};
