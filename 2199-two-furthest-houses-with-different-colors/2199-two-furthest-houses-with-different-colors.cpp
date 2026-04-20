class Solution {
public:
    int maxDistance(vector<int>& nums) {
        int n=nums.size(),mx=0; 
        for(int i =0 ;i<n;i++) 
        {
            if(nums[i]!=nums[0])
            {
                mx=max(mx,i);
            }  
            if(nums[i]!=nums[n-1])
            {
                mx=max(mx,n-i-1);
            }
        } 
        return mx;
    }
};