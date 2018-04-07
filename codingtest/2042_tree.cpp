#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;
vector<long long> arr;
vector<long long> tree;

long long init(int node, int start, int end){
    if(start == end){
        return tree[node] = arr[start];
    }
    int mid = (start+end)/2;
    return tree[node] = init(node*2, start, mid) + init(node*2+1, mid+1, end);
}
long long sum(int node, int start, int end, int left, int right){
    if(left > end || right < start){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[node];
    }
    return sum(node*2, start, (start+end)/2, left, right) + sum(node*2+1, (start+end)/2 + 1, end, left, right);
}

void update(int node, int start, int end, int index, long long diff){
    if(index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if(start != end){
        update(node*2, start, (start+end)/2, index, diff);
        update(node*2+1, (start+end)/2 +1, end, index, diff);
    }
}
int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    
    for(int i = 0; i < n; i++){
        long long t;
        scanf("%lld", &t);
        arr.push_back(t);
    }
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    tree=vector<long long>(tree_size);
    init(1, 0, n-1);
    m+=k;
    for(int i = 0; i < m; i++){
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        if(a == 1){
            b -= 1; 
            long long diff = c - arr[b];
            arr[b] = c;
            update(1,0,n-1,b,diff);
        }else{
            printf("%lld\n", sum(1,0,n-1, b-1, c-1));
        }
    }
    return 0;
}