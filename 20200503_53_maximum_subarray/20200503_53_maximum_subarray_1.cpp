
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int maxSum = -2147483647;
        for (int i=0;i<len;i++)
        {
            for (int j=i;j<len;j++)
            {
                int curSum = 0;
                for(int k=i;k<=j;k++)
                {
                   curSum += nums[k];
                }
                maxSum = max(curSum,maxSum);
            }
        }
        return maxSum;
    }
};