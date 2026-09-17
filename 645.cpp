class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size(), s = 0, q = 0;

        for (int x : nums)
            s += x, q += 1LL * x * x;

        long long d = s - n * (n + 1) / 2;
        long long p = (q - n * (n + 1) * (2 * n + 1) / 6) / d;

        return {(int)((d + p) / 2), (int)((p - d) / 2)};
    }
};

/*
    메인 아이디어. 
    처음 생각했을 때 누적합에서 뺄셈을 이용하려는 아이디어였는데
    중복과 누락을 각각 알 수 없는 문제가 있어서 제곱의 합을 이용함

    중복^2 - 누락^2 = 값_1 을 알면
    (중복+누락)(중복-누락) = 값_1 이고
    이전 누적합에서 중복 - 누락 = 값_2 을 구할 수 있으니
    중복 + 누적 = 값_3 을 알 수 있습니다.
    이를 통해 2 * 중복 = 값_1 + 값_2 를 알고
    중복 = (값_1 + 값_2) / 2
    중복 + 누락 = 값 으로 누락 또한 알 수 있습니다.

    s = sum(nums[i], i=0..nums.size()-1)

    q = sum(nums[i]^2, i=0..nums.size()-1)

    d = duplicate - missing
    
    p = duplicate + missing
*/
