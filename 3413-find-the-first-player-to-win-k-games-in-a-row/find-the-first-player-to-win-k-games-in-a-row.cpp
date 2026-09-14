class Solution {
public:
    int findWinningPlayer(vector<int>& s, int k) {
        int n = s.size();
        int prev = s[0];
        int idx = 0;
        int curr = 0;
        for(int i=1;i<n;i++){
            if(prev<s[i]){
                curr = 1;
                idx = i;
                prev = s[i];
            }
            else curr++;
            if(curr>=k) break;
        }
        return idx;
    }
};