#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> small_heap;
    priority_queue<int, vector<int>, greater<int>> large_heap;

    int i;
    int cur_med = -1;
    while (cin >> i)
    {
        if (small_heap.empty())
        {
            small_heap.push(i);
            cur_med = i;
        }
        else if (large_heap.empty())
        {
            large_heap.push(i);
            cur_med = (small_heap.top() + i) / 2;
        }
        else
        {
            int ss = small_heap.size();
            int ls = large_heap.size();

            int l = small_heap.top();
            int r = large_heap.top();

            if (ss == ls)
            {
                if (i < l){
                    cur_med = l;
                    small_heap.push(i);                    
                } else if (i < r) {
                    cur_med = i;
                    small_heap.push(i);
                } else {
                    cur_med = r;
                    large_heap.push(i);
                }
            }  
            else if (ss < ls)
            {
                if(i <= r){
                    small_heap.push(i);
                    cur_med = (small_heap.top()+r)/2;
                } else {
                    int tmp = large_heap.top();
                    large_heap.pop();
                    small_heap.push(tmp);
                    large_heap.push(i);
                    cur_med = (small_heap.top() + large_heap.top())/2;
                }
            }
            else
            {
            }
        }
    }
}