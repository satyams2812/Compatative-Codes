#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;

class Graph
{
    unordered_map<string, list<pair<string, int>>> l;
public:
    void add_edge(string a, string b, bool dir, int x)
    {
        l[a].push_back(make_pair(b, x));
        if(dir)
        {
            l[b].push_back(make_pair(a, x));
        }
    }
    void printList()
    {
        for(auto p:l)
        {
            string city=p.first;
            list<pair<string, int>> nbrs= p.second;
            cout<<city<<"->";
            for(auto nbr:nbrs)
            {
                string dest=nbr.first;
                int value=nbr.second;
                cout<<dest<<" "<<value<<", ";
            }
            cout<<endl;
        }
    }
};

int main() {
    Graph g;
    g.add_edge("A", "B", true, 20);
    g.add_edge("A", "C", true, 10);
    g.add_edge("B", "D", true, 30);
    g.add_edge("C", "D", true, 40);
    g.add_edge("A", "D", false, 50);
    g.printList();
    return 0;
}
