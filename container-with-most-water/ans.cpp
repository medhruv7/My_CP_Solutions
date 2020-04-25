class Solution {
public:
    int maxArea(vector<int>& a) {
        int n = a.size();
        int i = 0,j = n - 1;
        int ans = 0;
        while(i != j){
            ans = max(ans,(j - i)*(min(a[i],a[j])));
            if(a[i] < a[j])++i;
            else --j;
        }
        return ans;
    }
};
