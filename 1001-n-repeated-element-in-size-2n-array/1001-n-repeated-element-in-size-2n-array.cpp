class Solution {
public: 
int seen[50001];
    int repeatedNTimes(vector<int>& nums) {
        for(int i:nums) 
        {
            if(seen[i])return i; 

            seen[i]=1;
        } 
        return 0 ;
    }
};