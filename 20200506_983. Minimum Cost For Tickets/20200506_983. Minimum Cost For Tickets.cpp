class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int endDay = days.back();
        vector<int> F(endDay + 1);
        for (int i = 0; i < days.size(); i++)
            F[days[i]] = 2147483647;
        for (int i = 1; i <= endDay; i++)
        {
            if (!F[i])  F[i] = F[i - 1];
            else {
                F[i] = min({ F[i], F[i - 1] + costs[0],
                F[max(0,i - 7)] + costs[1], F[max(0,i - 30)] + costs[2] });
            }
        }
        return F[endDay];
    }
};