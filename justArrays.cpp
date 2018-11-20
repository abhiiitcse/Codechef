#include <bits/stdc++.h>
#define optimize_io ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fo(i,a,b) for(int i=a; i < b;i++)
#define maxn (int)(1e5+5)
#define maxm (int)(1e5+5)
#define LN (int)(20)
using namespace std;
typedef long long ll;

int n,m;
ll arr[maxn];
ll xval[maxm];

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
  
}

/**
 * Main function
 */
int main(){
  optimize_io;
  compute_st();
  return 0;
}
