using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int p = 0;
        for(int i = 1; i <= n; i++) {
            if(target[p] == i) {
                ans.push_back("Push");
                p++;
            }
            else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            
            if(target.size() == p) {
                break;
            }
        }

        return ans;
    }
};

/*
    더 나은 메모리 사용
    class Solution {
        public:
            vector<string> buildArray(vector<int>& target, int n) {
                vector<string> answer;
                int current = 1;

                for (int num : target) {
                    while (current < num) {
                        answer.push_back("Push");
                        answer.push_back("Pop");
                        current++;
                    }

                    answer.push_back("Push");
                    current++;
                }

                return answer;
            }
        };
*/