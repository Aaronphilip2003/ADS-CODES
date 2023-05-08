#include <iostream>
#include <queue>
using namespace std;

class Graph
{
private:
    int num;
    int cost[10][10];

public:
    void createGraph();
    void displayCostMatrix();
    void BFS(int start);
    void DFS(int start);
    void DFSUtil(int v,bool visited[]);
};
void Graph::createGraph()
{
    cout << "Enter the number of vertices:";
    cin >> num;

    int i, j, costVal;
    cout << "Enter i, j and cost for each edge (separated by spaces):" << endl;
    cout << "(enter -1 -1 -1 to exit)" << endl;

    for (int x = 0; x < num; x++)
    {
        for (int y = 0; y < num; y++)
        {
            cost[x][y] = 999;
        }
    }

    while (true)
    {
        cin >> i >> j >> costVal;
        if (i == -1 && j == -1 && costVal == -1)
        {
            break;
        }

        cost[i][j] = costVal;
        cost[j][i] = costVal;
    }
}

void Graph::displayCostMatrix()
{
    cout << "The entered cost matrix is:\n";
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (i == j)
            {
                cout << "0 ";
            }
            else if (cost[i][j] != 999)
            {
                cout << cost[i][j] << " ";
            }
            else
            {
                cout << "999 ";
            }
        }
        cout << endl;
    }
}

void Graph::BFS(int start)
{
    int visited[num]={false};
    queue<int>q;

    visited[start]=true;
    q.push(start);

    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";

        for(int i=0;i<num;i++)
        {
            if(cost[curr][i]!=999 && !visited[i])
            {
                visited[i]=true;
                q.push(i);
            }
        }
    }
    cout<<endl;
}

void Graph::DFSUtil(int v,bool visited[])
{
    visited[v]=true;
    cout<<v<<" ";
    for(int i=0;i<num;i++)
    {
        if(cost[v][i]!=999 and !visited[i])
        {
            DFSUtil(i,visited);   
        }
    }
}
void Graph::DFS(int start)
{
    bool visited[num]={false};
    DFSUtil(start,visited);
    cout<<endl;
}

int main()
{
    Graph g;
    g.createGraph();
    g.displayCostMatrix();
    g.BFS(0);
    g.DFS(0);
    return 0;
}
