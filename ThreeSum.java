class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i <= N - 3; i++) {
            if (nums[i] > 0)
                break;
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            int lt = i + 1, rt = N - 1;
            while (lt < rt) {
                int sum = nums[i] + nums[lt] + nums[rt];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[lt], nums[rt]});
                    while (lt < rt && nums[lt] == nums[lt + 1])
                        lt++;
                    while (lt < rt && nums[rt] == nums[rt - 1])
                        rt--;
                    lt++;
                    rt--;
                }
                else if (sum < 0) {
                    lt++;
                }
                else {
                    rt--;
                }
            }
        }

        return ans;
    }
};