#include<bits/stdc++.h>
using namespace std;

struct Treap{
  int val, prior, cnt;
  Treap *l, *r;
  Treap(int v): l(NULL), r(NULL), val(v), prior((rand() << 15) + rand()), cnt(1) {}
} *root;

int sz(Treap *t) {return (t == NULL) ? 0:t->cnt;}

void upd_sz(Treap *t){
  if(t) t->cnt = 1 + sz(t->l) + sz(t->r);
}

void split(Treap *t, Treap *&l, Treap *&r, int pos, int add = 0)
{
  if(!t) return void(l = r = NULL);
  int cur_pos = add + sz(t->l) + 1;
  if(cur_pos <= pos) split(t->r, t->r, r, pos, cur_pos), l = t;
  else split(t->l, l ,t->l, pos, add), r = t;
  upd_sz(t);
}

void merge(Treap *&t, Treap *l, Treap *r)
{
  if(!l || !r) t = l? l:r;
  else if(l->prior > r->prior) {merge(l->r, l->r, r); t = l;}
  else {merge(r->l, l, r->l);t = r;}
  upd_sz(t);
}

void insert(Treap *&t, int pos, int val)
{
  Treap *l, *r, *cur = new Treap(val);
  split(t, l, r, pos-1);
  merge(t, l, cur);
  merge(t, t, r);
}

void erase(Treap *&t, int pos)
{
  Treap *l, *r, *g;
  split(t, l, r, pos-1);
  split(r, g, r, 1);
  merge(t, l, r);
}

int find_kth(Treap *t, int k, int add = 0)
{
  int cur_pos = add + sz(t->l) + 1;
  if(cur_pos == k) return t-> val;
  if(cur_pos < k) return find_kth(t->r, k, cur_pos);
  return find_kth(t->l, k, add);
}

int main(){
  int n,m,a,b,c;
  Treap *acard, *bcard, *ccard, *dcard, *ecard, *fcard, *gcard, *hcard;
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    insert(root, i, i);
  }
  for(int i=1;i<=m;i++){
    cin>>a>>b>>c;
    //Take a cards from stack
    split(root, acard, root, a);
    //Take b cards from stack
    split(root, bcard, root, b);
    //put a cards on the stack
    merge(root, acard, root);
    //Take c cards from stack
    split(root, ccard, root, c);
    //reverse b cards
    for(int i=1;i<b;i++){
      split(bcard, ecard, fcard, 1);
      merge(bcard, fcard, ecard);
    }
    //put b cards  on the stack;
    merge(root, bcard, root);
    //put c cards on the stack
    merge(root, ccard, root);
    
    
    /*split(root, acard, bcard, a-1); //take acards from stack
      split(bcard, ccard, dcard, b-1); // take bcards from stack
      merge(ecard, acard, dcard); // put acards on the stack
      split(ecard,fcard, gcard,c-1); //take ccards from stack
      merge(hcard, ccard, gcard); // put bcards on the stack
      merge(root, fcard, hcard);*/
  }
  for(int i=1;i<=n;i++){
    cout<<find_kth(root,i)<<" ";
  }
  cout<<endl;
  return 0;
}
