class Solution {
public:
    int numSteps(string S) {

        deque<int> s;
        for (int i = 0; i < S.size(); i++) {
            s.push_back(S[i] - '0');
        }
        int ans = 0;
        while (s.size() > 1) {
            ans++;
            if (s.back() == 1) {
                int idx = -1;
                for (int i = s.size() - 1; i >= 0; i--) {
                    if (s[i] == 0) {
                        idx = i;
                        break;
                    }
                }
                if (idx == -1) {
                    s.push_front(1);
                    idx++;
                }
                s[idx] = 1;
                for (int i = idx + 1; i < s.size(); i++)
                    s[i] = 0;

            } else
                s.pop_back();
        }

        return ans;
    }
};