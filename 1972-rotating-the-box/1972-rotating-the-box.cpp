class Solution {
public:
    vector<char> get(vector<char>& v) {
        int sz = v.size();

        for (int i = sz - 1; i >= 0; i--) {
            if (v[i] == '.') {
                int j = i;
                while (j >= 0 && v[j] == '.')
                    j--;
                int cnt = 0;
                while (j >= 0 && v[j] == '#'){
                    v[j] = '.', j--,cnt++;
                }
                 j=i;
                while (cnt--) {
                    v[j--] = '#';
                } 
              
            }
        }
        return v;
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> res(m, vector<char>(n));
        int J = n - 1;
        for (int i = 0; i < n; i++) {
            auto v = get(box[i]);
            for (int j = 0; j < m; j++) {
                res[j][J] = v[j];
            }
            J--; 
        }
        return res;
    }
};
