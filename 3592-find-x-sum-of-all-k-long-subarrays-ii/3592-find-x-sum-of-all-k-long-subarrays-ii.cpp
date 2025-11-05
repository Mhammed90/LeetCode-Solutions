
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using ll = long long;
using T = pair<ll, ll>;
using namespace __gnu_pbds;
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<ll> ans;
        ordered_set s;
        unordered_map<ll, ll> mp;
        for (int i = 0; i < k; ++i) {
            mp[nums[i]]++;
        }
        for (const auto [v, c] : mp) {
            s.insert({c, v});
        }

        ll sum = 0;
        int take = min<int>(x, s.size());
        int cnt = 0;

        for (auto it = s.rbegin(); it != s.rend() && cnt < take; ++it, ++cnt) {
            const auto& [c, v] = *it;
            sum += c * v;
        }

        ans.push_back(sum);
        const auto upd = [&](ll v, ll c, int sign) -> ll {
            if (c == 0)
                return 0;
            if (sign == 1)
                s.insert({c, v});
            ll res = 0;
            if (s.order_of_key({c, v}) + x >= s.size()) {
                res += ((c * v) * sign);
                if (s.size() > x) {
                    const auto [cPrev, vPrev] =
                        *s.find_by_order(s.size() - x - 1);
                    res -= (cPrev * vPrev) * sign;
                }
            }
            if (sign == -1)
                s.erase({c, v});

            return res;
        };

        int n = nums.size();
        for (int i = k; i < n; ++i) {
            int c = mp[nums[i]]++;
            int cPrev = mp[nums[i - k]]--;
            ll sumUpdate = upd(nums[i], c + 1, 1) + upd(nums[i], c, -1) +
                           upd(nums[i - k], cPrev - 1, 1) +
                           upd(nums[i - k], cPrev, -1);
            ans.push_back(ans.back() + sumUpdate);
        }
        return ans;
    }
};