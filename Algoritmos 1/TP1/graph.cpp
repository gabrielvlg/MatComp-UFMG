#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// Função para adicionar arestas não direcionadas ao grafo
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  // Por ser não direcionado
}

int main() {
    int N, M;
    cout << "Digite o numero de vertices e arestas: ";
    cin >> N >> M;

    // Mapeia cada cidade a um índice
    map<string, int> cityIndex;
    vector<string> cities(N);
    vector<vector<int>> adj(N);

    cout << "Digite os nomes das cidades:\n";
    for (int i = 0; i < N; ++i) {
        cin >> cities[i];
        cityIndex[cities[i]] = i;
    }

    cout << "Digite as arestas no formato 'cidade1 cidade2':\n";
    for (int i = 0; i < M; ++i) {
        string city1, city2;
        cin >> city1 >> city2;
        int u = cityIndex[city1];
        int v = cityIndex[city2];
        addEdge(adj, u, v);
    }

    // Exibe a lista de adjacência
    cout << "\nLista de Adjacência do Grafo:\n";
    for (int i = 0; i < N; ++i) {
        cout << cities[i] << ": ";
        for (int neighbor : adj[i]) {
            cout << cities[neighbor] << " ";
        }
        cout << endl;
    }

    return 0;
}
