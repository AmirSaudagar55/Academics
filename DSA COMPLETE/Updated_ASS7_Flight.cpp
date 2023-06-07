#include <iostream>
#include <queue>
using namespace std;

int adj_mat[50][50] = {0};
bool visited[50] = {false};

void dfs(int s, int n, string arr[])
{
    visited[s] = true;
    cout << arr[s] << " ";

    for (int i = 0; i < n; i++)
    {
        if (adj_mat[s][i] && !visited[i])
            dfs(i, n, arr);
    }
}

void bfs(int s, int n, string arr[])
{
    for (int i = 0; i < n; i++)
        visited[i] = false;

    queue<int> bfsq;
    bfsq.push(s);
    visited[s] = true;

    while (!bfsq.empty())
    {
        int v = bfsq.front();
        bfsq.pop();
        cout << arr[v] << " ";

        for (int i = 0; i < n; i++)
        {
            if (adj_mat[v][i] && !visited[i])
            {
                bfsq.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    cout << "Enter the number of cities: ";
    int n;
    cin >> n;

    string cities[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter city #" << i << " (Airport Code): ";
        cin >> cities[i];
    }

    cout << "\nYour cities are: " << endl;
    for (int i = 0; i < n; i++)
        cout << "City #" << i << ": " << cities[i] << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "Enter distance between " << cities[i] << " and " << cities[j] << ": ";
            cin >> adj_mat[i][j];
            adj_mat[j][i] = adj_mat[i][j];
        }
    }

    cout << endl;
    for (int i = 0; i < n; i++)
        cout << "\t" << cities[i] << "\t";

    for (int i = 0; i < n; i++)
    {
        cout << "\n" << cities[i];
        for (int j = 0; j < n; j++)
            cout << "\t" << adj_mat[i][j] << "\t";
        cout << endl;
    }

    int u;
    cout << "Enter Starting Vertex: ";
    cin >> u;

    cout << "DFS: ";
    dfs(u, n, cities);
    cout << endl;

    cout << "BFS: ";
    bfs(u, n, cities);

    return 0;
}
