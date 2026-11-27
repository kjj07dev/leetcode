class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int totalTime = 0, target = tickets[k];

        for(int i = 0; i < tickets.size(); i++) {
            if(i <= k) {
                totalTime += min(tickets[i], target);
            }
            else {
                totalTime += min(tickets[i], target-1);
            }
        }

        return totalTime;
    }
};
