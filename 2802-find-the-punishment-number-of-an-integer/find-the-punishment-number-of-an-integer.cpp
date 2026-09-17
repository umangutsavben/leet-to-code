class Solution {
public:
    bool f(int idx,string s,int sum,int target){
        if(idx == s.size()){
            return target==0;
        }
        for(int i=idx;i<s.size();i++){
            sum = sum*10 + s[i]- '0';
            if(f(i+1,s,0,target-sum)) return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1;i<n+1;i++){
            long long tmp = i*1LL*i;
            string s = to_string(tmp);
            if(f(0,s,0,i)){
                ans = ans + tmp;
            };
        }
        return ans;
    }
};