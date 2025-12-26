
class Solution {
public:
    int bestClosingTime(string customers) {
        int mnY = 0, mnN = 0;
        for (auto i: customers) {
            mnY += i == 'Y';
        }
        int idx = 0, ans = 0, sum = customers.size() + 2;
        for (auto i: customers) {
            if (mnN + mnY < sum) {
                sum = mnN + mnY;
                ans = idx;
            }
            idx++;
            mnY -= i == 'Y';
            mnN += i == 'N';
        }
        if (mnN + mnY < sum) {
            sum = mnN + mnY;
            ans = idx;
        }
        return ans;
    }
};