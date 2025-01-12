#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


/*
            WITHOUT PRIORITY QUEUE
*/

const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

/*
            USING PRIORITY QUEUE
*/

#define INF 0x3f3f3f3f

typedef pair<ll, ll> pll;

class Graph{
    ll V; // No. of vertices
    list<pair<ll, ll> >* adj;

    public:
        Graph(ll V);
        void addEdge(ll u, ll v, ll w);
        void shortestPath(ll s);
};


Graph::Graph(ll V){
    this->V = V;
    adj = new list<pll>[V];
}

void Graph::addEdge(ll u, ll v, ll w){
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Graph::shortestPath(ll src){
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    vector<ll> dist(V, INF);
    
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()){
        ll u = pq.top().second;
        pq.pop();

        list<pair<ll, ll>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i){
            ll v = (*i).first;
            ll weight = (*i).second;

            // If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for (ll i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main(){
    // create the graph given in above figure
    ll V = 9;
    Graph g(V);

    // making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestPath(0);

    return 0;
}