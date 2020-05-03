

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, -1);
        int res = 0, left = -1;
        for(int i=0;i<s.length();i++){
            left = max(m[s[i]], left);//若已经访问过这个点就更新左值
            m[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};