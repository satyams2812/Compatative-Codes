#include <iostream>
#include <list>
#include <queue>
using namespace std;

class graph
{
    list<int> *l;
    int v;
public:
    graph(int v)
    {
        this->v=v;
        l=new list<int>[v];
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool is_tree()
    {
        bool *visited=new bool[v];
        int *parent=new int[v];
        queue<int> q;
        for(int i=0; i<v; i++)
        {
            visited[i]=false;
            parent[i]=i;
        }
        int src=0;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int nbr:l[node])
            {
                if(visited[nbr]==true && parent[node]!=nbr)
                {
                    return false;
                }
                else if(!visited[nbr])
                {
                    visited[nbr]=true;
                    parent[nbr]=node;
                    q.push(nbr);
                }
            }
        }
        return true;
    }
};

int main() {
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    if(g.is_tree())
    {
        cout<<"yes it is tree";
    }
    else
    {
        cout<<"no a tree";
    }
    return 0;
}
