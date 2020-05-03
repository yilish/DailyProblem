
class Solution {
public:
    inline int max(int a, int b) { return a > b ? a : b; }
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int len = s.length() - 1;
        if (len == -1)  return 0;
        int res = 1;
        if (len == 0) return 1;//预处理一哈
        bool bucket[128] = { false };//CHAR_MAX是127
        bucket[s[0]] = 1;
        while (right < len)
        {
            while (bucket[s[right + 1]])
            {
                bucket[s[left++]] = 0;//清空桶
            }
            right++;
            bucket[s[right]] = 1;//把右边的值丢入桶
            res = max(res, right - left + 1);
        }
        return res;
    }
};