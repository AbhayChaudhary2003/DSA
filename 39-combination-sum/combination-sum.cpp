class Solution {
public:
    void func(vector<int>&candidates,int target,int idx, int n,int sum,vector<int>&diary,      vector<vector<int>>&res){
        if(idx == n){
            if(sum == target)
                res.push_back(diary);
            return;
        }
        func(candidates,target,idx+1,n,sum,diary,res);
        if(candidates[idx]+sum<=target){
            diary.push_back(candidates[idx]);
            sum = sum+candidates[idx];
            func(candidates,target,idx,n,sum,diary,res);
            diary.pop_back();
            sum = sum-candidates[idx];
        }
        return;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum =0;
        vector<int>diary;
        vector<vector<int>>res;
        func(candidates,target,0,n,sum,diary,res);
        return res;
    }
};