using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int counts = 0, maxCounts = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                counts++;
                if(counts > maxCounts) maxCounts = counts;
            }
            else counts = 0;
                    
        }
        return maxCounts;
    }
};