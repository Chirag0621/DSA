#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
using namespace std;

class Graph{
    int v;
    list<int> * l;
    bool isUndir;
public:
    Graph(int v,bool isUndir=true){
        this->v=v;
        l=new list<int> [v];
        this->isUndir = isUndir;
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        if(isUndir){
            l[v].push_back(u);
        }
    }
    void topoHelper(int src,vector<bool> &vis,stack<int> &s){
        vis[src]=true;
        list<int> neighbors =l[src];
        for(int v:neighbors){
            if(!vis[v]){
                topoHelper(v,vis,s);
            }
        }
        s.push(src);
    }
    void toposort(){
        vector<bool> vis(v,false);
        stack<int> s;

        for(int i=0;i<v;i++){
            if(!vis[i]){
                topoHelper(i,vis,s);
            }
        }
        while(s.size()>0){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
};
int main(){
    Graph graph(6,false);
    graph.addEdge(2,3);
    graph.addEdge(3,1);

    graph.addEdge(4,0);
    graph.addEdge(4,1);

    graph.addEdge(5,0);
    graph.addEdge(5,2);
    graph.toposort();
}