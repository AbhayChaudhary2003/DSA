class Solution {
public:
    bool isPalindrome(string s) {
        //int n = s.size();

        // Remove non-alphabet characters
        for(int i = 0; i < s.size(); i++) {
            if(!isalnum(s[i])) {
                s.erase(i, 1);
                i--;
                //n--;
            }
        }

        // Convert uppercase to lowercase
        int index = 0;

        while(index < s.size()) {
            if(s[index] >= 'A' && s[index] <= 'Z') {
                s[index] = s[index] - 'A' + 'a';
            }
            index++;
        }

        // Check palindrome using two pointers
        int a = 0;
        int b = s.size() - 1;

        while(a < b) {
            if(s[a] != s[b]) {
                return false;
            }

            a++;
            b--;
        }

        return true;
    }
};