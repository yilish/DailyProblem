
class Solution {
public:
    inline int max(int a, int b) { return a > b ? a : b; }
    int triMax(int a, int b, int c)
{
        int res = a > b ? a : b;
        res = res > c ? res : c;
        return res;
    }
    int divideAndConquer(vector<int>& nums, int left, int right)
{
        if (left >= right)
        {//子列落单则直接返回该数。
            return nums[left];
        }
        int mid = (right - left) / 2 + left;//求中点
        int leftSum = divideAndConquer(nums, left, mid);//递归地去求两边的最大子列和
        int rightSum = divideAndConquer(nums, mid + 1, right);
        //开始求跨越中点的最大子列和,这里使用从中线向左向右依次扫描的方法
        int leftCrossNum = 0, rightCrossNum = 0;
        int maxLeftCrossNum = -2147483647, maxRightCrossNum = -2147483647;
        for (int i = mid; i >= left; i--)
        {
            leftCrossNum += nums[i];
            maxLeftCrossNum = max(leftCrossNum, maxLeftCrossNum);
            //用贪心法，不需要于leftCrossNum < 0时更新值。
        }
        for (int i = mid + 1; i <= right; i++)
        {
            rightCrossNum += nums[i];
            maxRightCrossNum = max(rightCrossNum, maxRightCrossNum);
        }
        return triMax(leftSum, rightSum, maxLeftCrossNum + maxRightCrossNum);
    }
    int maxSubArray(vector<int>& nums) {
        return divideAndConquer(nums, 0, nums.size() - 1);
    }
};