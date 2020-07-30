#include<iostream>
#include<list>
#include<queue>
#include<map>

using namespace std;


template<typename T>
class Graph{
    map<T,list<T>> l;
    public:
    void add_edge(T x, T y)
    {
        l[x].push_back(y);
         l[y].push_back(x);

    }

    void bfs(T src)
    {
        map<T,bool> visted;
        queue<T> q;
        q.push(src);
        visted[src] = true;
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            cout<<node<<" ";
            for(T nbr : l[node])
            {
                if(!visted[nbr])
                {
                    q.push(nbr);
                    visted[nbr] = true;
                }
            }
        }
    }
};



int main()
{

 Graph<int> g;
 g.add_edge(0,1);
 g.add_edge(1,2);
 g.add_edge(2,3);
 g.add_edge(0,3);
 g.add_edge(3,4);
 g.add_edge(4,5);
g.bfs(0);
}