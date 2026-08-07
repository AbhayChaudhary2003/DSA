class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> res;

        for(int i = 0; i < nums.size(); i++) {
            if(res.empty() || res[res.size() - 1] != nums[i]) {
                res.push_back(nums[i]);
            }
        }

        for(int i = 0; i < res.size(); i++) {
            nums[i] = res[i];
        }

        return res.size();
    }
};