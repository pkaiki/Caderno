#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 1e3+10;
char M[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;

bool ehvalido(int x, int y){
  if(x < 0 or y < 0) return false;
  if(x > n-1 or y > m-1) return false;
  return true;
}

int dist[MAXN][MAXN];

void bfs(int x_inicial, int y_inicial){
  queue<pair<int, int>> fila;
  fila.push({x_inicial, y_inicial});
  vis[x_inicial][y_inicial] = true;
  dist[x_inicial][y_inicial] = 0;
  while(!fila.empty()){
    int x_atual = fila.front().first;
    int y_atual = fila.front().second;
    fila.pop();
    for(int i=0; i<4; i++){
      int x_vizinho = x_atual + dx[i];
      int y_vizinho = y_atual + dy[i];
      if(vis[x_vizinho][y_vizinho]) continue;
      if(not ehvalido(x_vizinho, y_vizinho)) continue;
      if(M[x_vizinho][y_vizinho] == '#') continue;
      dist[x_vizinho][y_vizinho] = dist[x_atual][y_atual] + 1;
      fila.push({x_vizinho, y_vizinho});
      vis[x_vizinho][y_vizinho] = true;
    }
  }
}

int main(){
  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> M[i][j];
    }
  }

  int x_inicial, y_inicial; cin >> x_inicial >> y_inicial;

  bfs(x_inicial, y_inicial);

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cout << dist[i][j] << ' ';
    }
    cout << endl;
  }

}
