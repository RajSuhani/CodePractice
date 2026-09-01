#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<pair<int,int>> litter;
        int sr = 0, sc = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        if (k == 0)
            return 0;

        unordered_map<int, int> id;
        for (int i = 0; i < k; i++) {
            id[litter[i].first * n + litter[i].second] = i;
        }

        int total = 1 << k;

        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int,int>> q;

        q.push({sr, sc});
        dist[sr][sc] = 0;

        vector<int> startDist(m * n, -1);
        startDist[sr * n + sc] = 0;

        vector<vector<int>> d(k + 1, vector<int>(k + 1, -1));

        auto bfs = [&](int r, int c, int idx) {
            vector<vector<int>> ds(m, vector<int>(n, -1));
            queue<pair<int,int>> qu;

            ds[r][c] = 0;
            qu.push({r, c});

            while (!qu.empty()) {
                auto [x, y] = qu.front();
                qu.pop();

                int dx[] = {1, -1, 0, 0};
                int dy[] = {0, 0, 1, -1};

                for (int z = 0; z < 4; z++) {
                    int nx = x + dx[z];
                    int ny = y + dy[z];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    if (classroom[nx][ny] == 'X' || ds[nx][ny] != -1)
                        continue;

                    ds[nx][ny] = ds[x][y] + 1;
                    qu.push({nx, ny});
                }
            }

            for (int j = 0; j < k; j++)
                d[idx][j] = ds[litter[j].first][litter[j].second];

            return ds;
        };

        auto ds = bfs(sr, sc, k);

        vector<vector<int>> ld(k, vector<int>(k));

        for (int i = 0; i < k; i++) {
            auto cur = bfs(litter[i].first, litter[i].second, i);
            for (int j = 0; j < k; j++)
                ld[i][j] = cur[litter[j].first][litter[j].second];
        }

        vector<vector<int>> resetDist(k, vector<int>());

        vector<pair<int,int>> resets;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (classroom[i][j] == 'R')
                    resets.push_back({i, j});

        vector<vector<int>> fromReset(k);

        for (int i = 0; i < k; i++) {
            auto cur = bfs(litter[i].first, litter[i].second, i);

            for (auto [r, c] : resets) {
                if (cur[r][c] != -1)
                    fromReset[i].push_back(cur[r][c]);
            }
        }

        vector<vector<int>> toReset(k);

        auto startBfs = bfs(sr, sc, k);

        for (int i = 0; i < k; i++) {
            for (auto [r, c] : resets) {
                if (startBfs[r][c] != -1)
                    toReset[i].push_back(startBfs[r][c]);
            }
        }

        struct State {
            int r, c, mask, e;
        };

        queue<State> bfsq;

        int srMask = 0;

        bfsq.push({sr, sc, srMask, energy});

        vector<vector<vector<unordered_set<int>>>> vis(
            m, vector<vector<unordered_set<int>>>(
                   n, vector<unordered_set<int>>(total)));

        vis[sr][sc][0].insert(energy);

        int moves = 0;

        while (!bfsq.empty()) {
            int sz = bfsq.size();

            while (sz--) {
                auto [r, c, mask, en] = bfsq.front();
                bfsq.pop();

                if (mask == total - 1)
                    return moves;

                int dr[] = {1, -1, 0, 0};
                int dc[] = {0, 0, 1, -1};

                for (int z = 0; z < 4; z++) {
                    int nr = r + dr[z];
                    int nc = c + dc[z];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    if (en == 0)
                        continue;

                    int ne = en - 1;

                    if (classroom[nr][nc] == 'R')
                        ne = energy;

                    int nmask = mask;

                    if (classroom[nr][nc] == 'L') {
                        int idx = id[nr * n + nc];
                        nmask |= (1 << idx);
                    }

                    bool skip = false;

                    for (int old : vis[nr][nc][nmask]) {
                        if (old >= ne) {
                            skip = true;
                            break;
                        }
                    }

                    if (skip)
                        continue;

                    vector<int> eraseList;

                    for (int old : vis[nr][nc][nmask]) {
                        if (old <= ne)
                            eraseList.push_back(old);
                    }

                    for (int old : eraseList)
                        vis[nr][nc][nmask].erase(old);

                    vis[nr][nc][nmask].insert(ne);
                    bfsq.push({nr, nc, nmask, ne});
                }
            }

            moves++;
        }

        return -1;
    }
};