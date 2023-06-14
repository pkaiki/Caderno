#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 2e5+10;

int dist[MAXN];
bool vis[MAXN];
vector<int> g[MAXN];
int n, m;

void bfs(int inicio){
  for(int i=1; i<=n; i++) dist[i] = INF;
  queue<int> fila;
  fila.push(inicio);
  dist[inicio] = 0;
  while(!fila.empty()){
    int atual = fila.front();
    fila.pop();
    vis[atual] = true;
    for(auto vizinho : g[atual]){
      if(vis[vizinho]) continue;
      dist[vizinho] = dist[atual] + 1;
      vis[vizinho] = true;
      fila.push(vizinho);
    }
  }
}

int main(){
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
  bfs(2);

  for(int i=1; i<=n; i++) cout << "A distancia de 2 com o vétice " << i << " eh " << dist[i] << endl;
}
