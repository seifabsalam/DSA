#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define V 11
int adjMTX[V][V] ;

vector< vector<int> > matrix (V, vector <int> (V, 0) );

void fillADJ( const vector<vector <int> > &edges ) {

    int Size = edges.size();
    for(int i=0 ;i < Size; i++) {
        int n = edges[i][0]     ;
        int m = edges[i][1]     ;
        adjMTX[n][m] = 1        ;
        adjMTX[m][n] = 1        ;
    }
}
/*
int adj[V][V] =
{
    // 1  2  3  4  5  6  7  8  9 10
    { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0 }, // 1
    { 1, 0, 1, 0, 1, 0, 1, 1, 0, 0 }, // 2
    { 0, 1, 0, 1, 0, 0, 0, 0, 1, 1 }, // 3
    { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, // 4
    { 0, 1, 0, 0, 0, 1, 1, 1, 0, 0 }, // 5
    { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }, // 6
    { 0, 1, 0, 0, 1, 0, 0, 1, 0, 0 }, // 7
    { 0, 1, 0, 0, 1, 0, 1, 0, 0, 0 }, // 8
    { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, // 9
    { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }  // 10
};
*/

void printADJ()
{
    for (int i = 1; i < V; i++)
    {
        for (int j = 1; j < V; j++)
            cout << adjMTX[i][j] << "\t" ;
        cout << endl;
    }
}

void BFS(int start)
{
    bool visited[V] = { false };
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 1; i <= V; i++)
        {
            if (adjMTX[v][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

void DFS(int start)
{
    bool visited[V] = { false };
    stack<int> s;

    s.push(start);

    cout << "DFS Traversal: ";

    while (!s.empty())
    {
        int v = s.top();
        s.pop();

        if (!visited[v])
        {
            visited[v] = true;
            cout << v << " ";

            for (int i = V - 1; i > 0; i--)
            {
                if (adjMTX[v][i] == 1 && !visited[i])
                {
                    s.push(i);
                }
            }
        }
    }
    cout << endl;
}

int main()
{

    vector<vector<int> > edges = {{1,2}, {1,4}, {2,3}, {3,4}, {3,9}, {3,10}, {2,5}, {2,7}, {2,8}, {5,7}, {5,6}, {7,8}, {5,8}};

    fillADJ(edges);
    printADJ();
    BFS(1);
    DFS(1);

    return 0;
}
