class Solution {
public:
    char kthCharacter(int k) {
        string cur = "a";
        string las = "a";
        while (cur.size() < 500) {
            int n = las.size();
            string x = "";
            for (int i = 0; i < n; i++) {
                int c = (int)las[i];
                c++;
                if (c == 123)
                    c = 97;
                x += (char)(c);
            }

            cur += x;
            las = cur;
        }
        return cur[k - 1];
    }
};