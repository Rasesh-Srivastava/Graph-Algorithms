// applicable only in a directed acyclic graph
// if there is a path from a to b then a appears before b.
// this type of ordering is topological sort
#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
vector<bool> visited(N, false);
vector<int> adj[N];
vector<int> state(N, 0);
// state=0//not processed yet
// state=1 currently being processed
// state=2 processed
bool cycle_present = false;
vector<int> ans;
void dfs(int node)
{
    state[node] == 1;
    for (int child : adj[node])
    {
        if (state[child] == 1)
        {
            cycle_present = true;
            cout << "cycle present" << endl;
            exit(1);
        }
        else if (state[child] == 0)
        {
            dfs(child);
        }
    }
    state[node] = 2;
    ans.push_back(node);
}

bool dfss(int n)
{
    for (int i : adj[n])
    {
        if (state[i] == 1)
        {
            cycle_present = 1;
            return 1;
        }
        else if (state[i] == 0)
        {
            state[i] = 1;
            if (dfss(i))
                return 1;
        }
    }
    state[n] = 2;
    ans.push_back(n);
    return 0;
}

int main()
{
    int n, e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
    {
        if (state[i] == 0)
        {
            if (dfss(i))
            {
                cout << "cycle present" << endl;
                break;
            }
        }
    }

    if (!cycle_present)
    {
        reverse(ans.begin(), ans.end());
        for (int node : ans)
        {
            cout << node << " ";
        }
    }
    if (ans.size() == 0)
    {
        cout << "cycle exists" << endl;
    }
}