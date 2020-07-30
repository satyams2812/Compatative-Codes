#include <iostream>
#include <list>
#include <queue>
#include <map>
using namespace std;

template<typename T>
class Graph
{
    map<T, list<T>> l;
public:
    void add_edge(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void dfs_helper(T src, map<T, bool> &visited)
    {
        cout<<src<<" ";
        visited[src]=true;
        // visit all the neighbours one by one
        for(T nbr:l[src])
        {
            if(!visited[nbr])
            {
                dfs_helper(nbr, visited);
            }
        }
    }
    void dfs(T src)
    {
        map<T, bool> visited;
        for(auto p:l)
        {
            T node=p.first;
            visited[node]=false;
        }
        dfs_helper(src, visited);
    }
};

int main() {
    Graph<int> g;
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(0,3);
    g.add_edge(3,4);
    g.add_edge(4,5);
    g.dfs(0);
    return 0;
}
