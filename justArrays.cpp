#include <bits/stdc++.h>
#define optimize_io ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fo(i,a,b) for(int i=a; i < (b);i++)
#define maxn (int)(1e5+5)
#define maxm (int)(1e5+5)
#define LN (int)(20)
using namespace std;
typedef long long ll;

int n,m;
ll arr[maxn];
ll xval[maxm];
map<ll, ll> cnt;
ll st[maxn][LN];

/**
 * Read input from stdin
 */
void takeInput(void){
  cin>>n>>m;
  fo(i,0,n){
    cin>>arr[i];
  }
  fo(i,0,m){
    cin>>xval[i];
  }
}

/**
 * Sparse table calculations
 */
void compute_st(void){
  fo(i,0,n){
    st[i][0] = arr[i];
  }
  for(ll j = 1; j< LN; j++){
    for(ll i = 0; i + (1<<j) <= n; i++){
      st[i][j] = (st[i][j-1] & st[i+(1<<(j-1))][j-1]);
    }
  }
}

/**
 * Calculate value between l and r
 */
ll getAndValue(int l, int r){
  int lgdiff = log2(r-l+1);
  ll val = st[l][lgdiff] & st[r-(1<<lgdiff)+1][lgdiff];
  return val;
}

/**
 * Precompute
 */
void precompute(void){
  fo(i,0,n){
    int start = i, end = i;
    ll cur = arr[i];
    while(start < n){
      cur = arr[start] & cur;
      int l = start, r = n-1;
      while(l <= r){
	int mid = (l+r)/2;
	if(getAndValue(i, mid) == cur){
	  end = mid, l = mid+1;
	}else{
	  r = mid - 1;
	}
      }
      ll l1 = start - i, l2 = end-i+1;
      cnt[cur] += ((l2*(l2+1))/2) - ((l1*(l1+1))/2);
      start = end + 1;
      end = start;
    }
  }
}

/**
 * Main function
 */
int main(){
  optimize_io;
  takeInput();
  compute_st();
  precompute();
  fo(i,0,m){
    cout<<cnt[xval[i]]<<endl;
  }
  return 0;
}
