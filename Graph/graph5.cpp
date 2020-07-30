#include <iostream>
#include <map>
#include <list>
using namespace std;

template<typename T>
class graph
{
    map<T, list<T>> l;
public:
    void add_edge(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T src, map<T, bool>&visited)
    {
        cout<<src<<" ";
        visited[src]=true;
        for(T nbr:l[src])
        {
            if(!visited[nbr])
            {
                dfs_helper(nbr, visited);
            }
        }
    }

    void dfs()
    {
        map<T, bool> visited;
        for(auto p:l)
        {
            T node=p.first;
            visited[node]=false;
        }
        // iterate over all one by one
        int count=0;
        for(auto p:l)
        {
            T node=p.first;
            if(!visited[node])
            {
                cout<<"component "<<count<<"->";
                dfs_helper(node, visited);
                count++;
                cout<<endl;
            }
        }
    }
};

int main() {

    graph<int> g;
    g.add_edge(0,1);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(3,0);
    g.add_edge(0,4);

    g.add_edge(5,6);
    g.add_edge(6,7);

    g.add_edge(8,8);
    g.dfs();
    return 0;
}
