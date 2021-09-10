#include <stdint.h>
#include <string.h>

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class edge {
   public:
    int to;
    int cost;
    edge(int To, int Cost) : to(To), cost(Cost) {}
};

int main() {
    int N;
    cin >> N;
    while (N--) {
        int n, m;
        cin >> n >> m;
        vector<edge> graph[n];
        for (int i = 0; i < m; i++) {
            int start, to, cost;
            cin >> start >> to >> cost;
            start--, to--;
            graph[start].push_back(edge(to, cost));
            graph[to].push_back(edge(start, cost));
        }
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int source, destination, required_cost;
            cin >> source >> destination >> required_cost;
            source--, destination--;
            int dist[n];
            bool in_queue[n];
            memset(dist, 63, sizeof(dist));
            memset(in_queue, false, sizeof(in_queue));
            dist[source] = 0;
            queue<int> q;
            q.push(source);
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                in_queue[cur] = false;
                for (auto i = graph[cur].begin(); i != graph[cur].end(); i++) {
                    if (dist[i->to] > dist[cur] + i->cost) {
                        dist[i->to] = dist[cur] + i->cost;
                        if (!in_queue[i->to]) {
                            q.push(i->to);
                            in_queue[i->to] = true;
                        }
                    }
                }
            }

            int dp[100001], on_way = 0;
            memset(dp, 63, sizeof(dp));
            int oo = dp[0];
            dp[0] = 0;
            q.push(destination);
            if (required_cost - dist[destination] < 0 || (required_cost - dist[destination]) % 2 == 1) {
                cout << "NO" << endl;
                continue;
            }

            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                on_way++;
                for (auto i = graph[cur].begin(); i != graph[cur].end(); i++) {
                    if (dist[i->to] + i->cost == dist[cur]) {
                        if (cur != destination) {
                            for (int j = 0; j <= required_cost - dist[destination]; j++) {
                                int double_cost = (i->cost) * 2;
                                dp[j + double_cost] = min(dp[j + double_cost], dp[j] + 2);
                            }
                        }
                        if (!in_queue[i->to]) {
                            q.push(i->to);
                            in_queue[i->to] = true;
                        }
                    }
                }
            }

            if (required_cost - dist[destination] == 0) {
                cout << "Yes " << dp[required_cost - dist[destination]] + on_way - 1;
            } else {
                cout << "No";
            }
            cout << endl;
        }

        if (N) {
            cout << endl;
        }
    }
    return 0;
}