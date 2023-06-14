#include <bits/stdc++.h>
using namespace std;
int n, m;
const int MAXN = 2e5+10;
const int INF = 1e9;
vector<pair<int,int>> g[MAXN];
int dist[MAXN];

void dijkstra(int inicio){
  for(int i=1; i<=n; i++) dist[i] = INF;
  set<pair<int,int>> st;
  dist[inicio] = 0;
  st.insert({0, inicio});

  while(not st.empty()){
    pair<int, int> atual = *st.begin();
    st.erase(st.begin());
    int distancia_atual = atual.first;
    int vertice_atual = atual.second;
    for(auto vizinho : g[vertice_atual]){
      int vertice_vizinho = vizinho.first;
      int distancia_vizinho = vizinho.second;
      if(dist[vertice_vizinho] > dist[vertice_atual] + distancia_vizinho){
        st.erase({dist[vertice_vizinho], vertice_vizinho});
        dist[vertice_vizinho] = dist[vertice_atual] + distancia_vizinho;
        st.insert({dist[vertice_vizinho], vertice_vizinho});
      }
    }
  }
  
}

int main(){
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int u, v, c; cin >> u >> v >> c;
    g[u].push_back({v, c});
  }
  dijkstra(1);

  for(int i=1; i<=n; i++){
    cout << "A distancia de 1 com " << i << " eh " << dist[i] << endl;
  }
}
