class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n=nums.size();
        int length=0;
        int l=0,r=0;
        while(r<n){
            m[nums[r]]++;
            while(m[nums[r]]>k){
                m[nums[l]]--;
                l++;
                
            }
            
            r++;
            length=max(length,r-l);
        }
        return length;
    }
};