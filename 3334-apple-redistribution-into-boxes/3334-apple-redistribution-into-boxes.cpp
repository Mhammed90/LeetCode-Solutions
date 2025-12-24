class Solution {
public:
    int freq[51];
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        for (int i : capacity)
            freq[i]++; 
            int sum=0;
        for (int i : apple)
           sum+=i;

        int ans = 0;
        for (int i = 50; i >=0; i--)
            {
                while(sum>0&&freq[i]) 
                {
                    sum-=i; 
                    freq[i]--; 
                    ans++;
                }
            }
        return ans;
    }
};