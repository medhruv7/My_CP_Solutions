class Solution {
public:
    map<int,string> st;
    
    int n;
    vector<string> ans;
    void solve(int idx,string &cur,string digits){
        if(idx == n){
            ans.push_back(cur);
            return;
        }else{
            for(int i = 0;i < st[digits[idx] - '0'].size(); ++i){
                cur.push_back(st[digits[idx] - '0'][i]);
                solve(idx + 1,cur,digits);
                cur.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        st[2] = "abc";
        st[3] = "def";
        st[4] = "ghi";
        st[5] = "jkl";
        st[6] = "mno";
        st[7] = "pqrs";
        st[8] = "tuv";
        st[9] = "wxyz";
        n = digits.size();
        if(n == 0) return {};
        string cur;
        solve(0,cur,digits);
        return ans;
    }
};
