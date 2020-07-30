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
        //l[y].push_back(x);
    }
    void dfs_helper(T src, map<T, bool> &visited, list<T>&ordering)
    {
        visited[src]=true;
        // visit all the neighbours one by one
        for(T nbr:l[src])
        {
            if(!visited[nbr])
            {
                dfs_helper(nbr, visited, ordering);
            }
        }
        // after function call
        ordering.push_front(src);
        return;
    }
    void dfs()
    {
        map<T, bool> visited;
        list<T> ordering;
        for(auto p:l)
        {
            T node=p.first;
            visited[node]=false;
        }
        // iterate over all vertices
        for(auto p:l)
        {
            T node=p.first;
            if(!visited[node])
            {
                dfs_helper(node, visited, ordering);
            }
        }
        for(auto node:ordering)
        {
            cout<<node<<endl;
        }
    }
};

int main() {
    Graph<string> g;
    g.add_edge("python", "datapre");
    g.add_edge("datapre", "ML");
    g.add_edge("python", "ML");
    g.add_edge("python", "pytorch");
    g.add_edge("pytorch", "DL");
    g.add_edge("ML", "DL");
    g.add_edge("DL", "facerec");
    g.add_edge("dataset", "facerec");
    g.dfs();
    return 0;
}
