
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slo = nums[0];
        int fst = nums[0];
        slo = nums[slo];
        fst = nums[nums[fst]];
        // since in this question we will be having a dublicate for sure 
        // so we will be finding the cycle for sure ...
        while(slo != fst){
            slo = nums[slo];
            fst = nums[fst];
            fst = nums[fst];
        }
        slo = nums[0];
        while(slo!=fst){
            slo = nums[slo];
            fst = nums[fst];
        }
        return fst;
    }
};