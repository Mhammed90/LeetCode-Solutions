public class Solution {
    public int FurthestDistanceFromOrigin(string moves) {
        int cnt=0,_=0; 
        foreach(var i in moves) 
        {
            if(i=='_')_++;
            if(i=='L')cnt--; 
            if(i=='R')cnt++;
        } 

        return Math.Abs(cnt)+_;
    }
}