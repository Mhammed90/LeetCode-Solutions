class Solution {

public:
    int vis[(int)1e5 + 10];

    vector<int> adj[(int)1e5 + 10];

    void dfs(int u) {

        vis[u] = 1;

        for (auto v : adj[u])

        {

            if (vis[v] == 0)

            {

                dfs(v);
            }
        }
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {

        vector<pair<int, pair<int, int>>> v;

        for (auto i : meetings) {

            v.push_back({i[2], {i[1], i[0]}});
        }
        sort(v.begin(), v.end());
        vis[0] = 1;

        vis[firstPerson] = 1;

        for (int i = 0; i < v.size(); i++) {

            int curTime = v[i].first;

            set<int> temp;

            temp.insert(v[i].second.second);

            temp.insert(v[i].second.first);

            adj[v[i].second.second].push_back(v[i].second.first);

            adj[v[i].second.first].push_back(v[i].second.second);

            while (i + 1 < v.size() && curTime == v[i + 1].first) {

                i++;

                temp.insert(v[i].second.second);

                temp.insert(v[i].second.first);

                adj[v[i].second.second].push_back(v[i].second.first);

                adj[v[i].second.first].push_back(v[i].second.second);
            }

            ////        for(auto j:temp)cout<<j<<" " ;

            ////        cout<<el;

            //         for(int j:adj[1])cout<<j<<" ";

            for (auto j : temp)

            {

                if (vis[j] == 1)

                {

                    dfs(j);
                }
            }

            for (auto j : temp)
                adj[j].clear();
        }

        vector<int> ans;

        for (int i = 0; i < n; i++)

        {

            if (vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};