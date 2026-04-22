public class Solution {
    public IList<string> TwoEditWords(string[] queries, string[] dictionary) {
        IList<string>res=new List<string>();
        int n=queries.Length; 
        for(int i =0 ;i<n;i++) 
        {
            foreach(var word in dictionary)
            {
                int cnt=0; 
                for(int j=0;j<word.Length;j++) 
                {
                    if(queries[i][j]!=word[j])cnt++; 
                    if(cnt>2)break;
                } 
                if(cnt<=2)
                {
                    res.Add(queries[i]); 
                    break;
                }
            }
        } 
        return res;
    }
}