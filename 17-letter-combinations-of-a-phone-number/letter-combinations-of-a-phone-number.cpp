class Solution {
public:
    unordered_map<char,string>f={
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    

    void func(string&digits, int n, int idx,string&temp,vector<string>&ans){
        if(idx == n){
            ans.push_back(temp);
            return;

        }
        string choice = f[digits[idx]];
        for(int j=0;j<choice.size();j++){
            temp.push_back(choice[j]);
            func(digits,n,idx+1,temp,ans);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        string temp = "";
        vector<string>ans;
        func(digits,n,0,temp,ans);
        return ans;

        
    }
};