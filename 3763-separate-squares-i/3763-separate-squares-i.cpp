class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double total = 0;
        int mx = 0;
        for (auto &sq : squares) {
            int y = sq[1], l = sq[2];
            total += (double)l * l;
            mx = max(mx,y+l); 
            swap(sq[0],sq[1]);
        }  
        sort(squares.begin(),squares.end());

        total /= 2.0;

        double l = 0, r =  mx;
        double ans = 0;
        double EPS = 1e-5;

        while (abs(r - l) >= EPS) {
            double mid = (l + r) / 2;

            double curArea = 0;
            for (auto sq : squares) {
                double y = sq[0], l = sq[2];
                if (y < mid) {
                    curArea += l * min(mid - y, l);
                }
                 else break;
            }

            if (curArea >= total) {
                r = mid;
                ans = mid;
            } else
                l = mid;
        }

        return ans;
    }
};