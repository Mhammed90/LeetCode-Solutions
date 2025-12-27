class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

        int n = popped.size();
        stack<int> a;
        int j = 0, i = 0;
        while (i < n && j < n) {
            while (a.size() && j < n && popped[j] == a.top()) {
                a.pop();
                j++;
            }
            a.push(pushed[i]);
            i++;
        }
        while (j < n && a.size() && a.top() == popped[j]) {
            a.pop();
            j++;
        }
        return j == n;
    }
};