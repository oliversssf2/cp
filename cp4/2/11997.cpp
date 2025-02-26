#include <bits/stdc++.h>
using namespace std;

struct Node{
    int sum;
    vector<int> idx;
    bool operator<(const Node& n) const{
        return sum > n.sum;
    }
};

int get_sum(vector<vector<int>>& vv, vector<int>& idx){
    int sum = 0;
    for(int i = 0; i < idx.size(); i++){
        sum += vv[i][idx[i]];
    }
    return sum;
}

int main()
{
    int n;
    int tmp;
    vector<vector<int>> vv;
    while(cin>>n){
        vv = vector<vector<int>>(n);
        for(size_t i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin>>tmp;
                vv[i].push_back(tmp);
            }
            sort(vv[i].begin(), vv[i].end());
        }   
        
        vector<int> init(n, 0);

        vector<Node> kssums;
        struct Node init_node{get_sum(vv, init), init};
        kssums.push_back(init_node);
        priority_queue<Node> pq;
        pq.push(init_node);
        while(kssums.size() < n){
            Node node = pq.top();
            pq.pop();
            for(int i = 0; i < n; i++){
                vector<int> idx = node.idx;
                idx[i]++;
                if(idx[i] < n){
                    Node new_node{get_sum(vv, idx), idx};
                    pq.push(new_node);
                }
            }
            kssums.push_back(pq.top());            
        }
        
        for(auto& node : kssums){
            cout<<node.sum<<" ";
        }
        cout<<endl;
    }
}
