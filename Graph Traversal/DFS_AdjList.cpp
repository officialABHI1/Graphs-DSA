#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int visited[21] = {0}; // Initialize the visited array

vector<int> dfs(int src, vector<int>& ans, vector<vector<int>>& adjL) {
    if (visited[src] == 0) {
        ans.push_back(src);
        visited[src] = 1; // Mark the source vertex as visited
    }

    for (int i = 0; i < adjL[src].size(); i++) {
        int neighbor = adjL[src][i];
        if (visited[neighbor] == 0) {
            dfs(neighbor, ans, adjL); // Visit unvisited neighbors
        }
    }

    return ans;
}

int main() {
    int n, v, a, b, maxm = INT_MIN;
    cin >> n >> v;

    vector<vector<int>> adjL(v + 1); // Correct type: vector<vector<int>>

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        maxm = max(maxm, max(a, b));
        adjL[a].push_back(b);
        adjL[b].push_back(a);
    }

    cout << maxm << endl;

    for (int i = 1; i <= v; i++) {
        cout << i << " --> ";
        for (auto neighbor : adjL[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    vector<int> ans;
    ans = dfs(1, ans, adjL);

    for (auto x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}
