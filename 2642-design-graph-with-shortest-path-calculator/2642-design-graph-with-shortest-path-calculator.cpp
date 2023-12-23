#define INF 0x3f3f3f3f

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

class Graph {
    int V; // No. of vertices
 
    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list<iPair>* adj;
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->V = n;

        adj = new list<iPair>[V]; // [,]->[,]->[,]->[,]

        // add weight in the matrix
        for (int i = 0, edgeSize = edges.size(); i < edgeSize; i++) {
            addEdge(edges[i]);
        }
    }
    
    void addEdge(vector<int> edge) {
        int from = edge[0], to = edge[1], weight = edge[2];
        adj[from].push_back(make_pair(to, weight));
    }

    // https://www.geeksforgeeks.org/introduction-to-dijkstras-shortest-path-algorithm/?ref=lbp
    int shortestPath(int src, int dest) {
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

        vector<int> dist(V, INF);

        // <distance, source> 
        pq.push(make_pair(0, src));
        dist[src] = 0;

        while (!pq.empty()) {
            int currentCost = pq.top().first;
            int currentNode = pq.top().second;
            pq.pop();

            // Skip if a shorter path has already been found
            if (currentCost > dist[currentNode]) {
                continue;
            }
            
            // If found the target node then return the cost
            if (currentNode == dest) {
                return currentCost;
            }
    
            // 'it' is used to get all adjacent vertices of a vertex
            // list<pair<int, int>>::iterator it;

            for (auto it : adj[currentNode]) {
                int neighbour = it.first;
                int weight = it.second;

                // If there is shorted path to neighbour through currentNode
                int newCost = dist[currentNode] + weight;
                if (dist[neighbour] > newCost) {
                    dist[neighbour] = newCost;

                    pq.push(make_pair(newCost, neighbour));
                }
                
            }
        }

        return (dist[dest] == INF ? -1 : dist[dest]);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */