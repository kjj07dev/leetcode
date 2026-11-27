class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0, 0};
        
        for (int s : students)
            count[s]++;
        
        for (int sw : sandwiches) {
            if (count[sw] > 0) count[sw]--;
            else break;
        }
        
        return count[0] + count[1];
    }
};
