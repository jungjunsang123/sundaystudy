#include <string>
#include <vector>

using namespace std;

bool visited[201];

void BFS(int node, int n, vector<vector <int>> &computers) {
    for (int i=0;i<n;i++) {
        if ((i != node) && (computers[node][i] != 0) && (!visited[i])) {
            visited[i] = true;
            BFS(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i=0;i<n;i++) {
        if (!visited[i]) {
            visited[i] = true;
            answer++;
            BFS(i, n, computers);
        }
    }
    
    return answer;
}
