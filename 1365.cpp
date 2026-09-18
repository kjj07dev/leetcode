#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> rank;

        for(int i = 0; i < sorted.size(); i++)
            if(rank.find(sorted[i]) == rank.end())
                rank[sorted[i]] = i;
        
        vector<int> ans;

        for(int n : nums) {
            ans.push_back(rank[n]);
        }

        return ans;
    }
};

/*
    아이디어
    이중 폴문으로 돌리려다가 느릴것 같아서 솔트 한 후 해당 값까지 찾는 방법을 생각했는데
    이것도 결국 거의 n^2에 수렴하는 것 같아서
    해시맵을 만들고 그 해시값에 접근하는 방식으로 O(1)의 속도로 만들었습니다.

    결국 정렬하고 그 해당 위치가 앞에 있는 원소의 순서이기 때문에 성립하는 랭크인 셈이죠.
*/