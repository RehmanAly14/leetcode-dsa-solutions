class Solution {
public:
    void fun(string &s, char c, int i, string &res) {
        if(i == s.size()) return;

        if(s[i] != c) {
            res.push_back(s[i]);   
        }

        fun(s, c, i + 1, res);
    }

    void removeCharacter(string &s, char c) {
        string res = "";
        fun(s, c, 0, res);
        s = res;
    }
};
