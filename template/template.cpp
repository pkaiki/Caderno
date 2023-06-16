include <bits/stdc++.h>
using namespace std;
void dbg_out() { cerr << endl; }
template <typename H, typename... T> 
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__);
#define ln cerr << "line:" << __LINE__ << " bao, sow" << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9+7, INFLL = 0x3f3f3f3f3f3f3f3f, oo = INFLL;

void solve(){
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1; 
  while(t--) solve();
  return 0;
}
