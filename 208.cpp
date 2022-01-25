class Trie {
public:
    Trie() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }
    
    void insert(string word) {
        Trie* cur = this;
        for (char c : word) {
            if (cur->next[c-'a'] == nullptr) {   // 不存在这个字符
                cur->next[c-'a'] = new Trie();
            }
            cur = cur->next[c-'a'];
        }
        // 插入完毕，更新尾节点
        cur->isEnd = true;
    }
    
    bool search(string word) {
        Trie* cur = this;
        for (char c : word) {
            if (cur->next[c-'a'] == nullptr) {
                return false;
            }
            cur = cur->next[c-'a'];
        }
        if (cur->isEnd == true) {   // 最后一个是否为尾节点
            return true;
        } else {
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        Trie* cur = this;
        for (char c : prefix) {
            if (cur->next[c-'a'] == nullptr) {
                return false;
            }
            cur = cur->next[c-'a'];
        }
        return true;
    }
private:
    bool isEnd;     // 是尾节点
    Trie* next[26]; // 表示下一个可能字符的位置
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
