#include <vector>
using namespace std;

struct FlowNetwork {
    vector<vector<int>> capacity;
    int source, sink;
    int maxflow;

    vector<vector<int>> get_adj() {
        int n = capacity.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (capacity[i][j] || capacity[j][i])
                    adj[i].push_back(j);
            }
        }
        return adj;
    }
};

vector<FlowNetwork> flow_networks = {
    // test flow network from the e-maxx-eng article
    {{
        {0, 7, 0, 0, 4, 0},
        {0, 0, 5, 3, 0, 0},
        {0, 0, 0, 0, 0, 8},
        {0, 0, 3, 0, 0, 5},
        {0, 3, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 0}
    }, 0, 5, 10}, 
    // test flow network from wikipedia (Edmonds-Karp article)
    {{
        {0, 3, 0, 3, 0, 0, 0},
        {0, 0, 4, 0, 0, 0, 0},
        {3, 0, 0, 1, 2, 0, 0},
        {0, 0, 0, 0, 2, 6, 0},
        {0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 9},
        {0, 0, 0, 0, 0, 0, 0}
     }, 0, 6, 5}, 
    // test worst case flow network (for Ford-Fulkerson) from wikipedia
    {{
        {0, 1000, 1000, 0},
        {0, 0, 1, 1000},
        {0, 0, 0, 1000},
        {0, 0, 0, 0}
    }, 0, 3, 2000}
};
