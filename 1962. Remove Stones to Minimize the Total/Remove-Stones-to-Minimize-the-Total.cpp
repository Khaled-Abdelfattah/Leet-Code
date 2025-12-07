1class MaxPriorityQueue {
2private:
3    vector<int> heap;
4    void MaxHeapifyUp(int i) {
5        int parent = (i - 1) / 2;
6        while (i > 0 && heap[i] > heap[parent]) {
7            swap(heap[i], heap[parent]);
8            i = parent;
9            parent = (i - 1) / 2;
10        }
11    }
12    void MaxHeapifyDown(int i) {
13        int n = heap.size();
14        int mxIndx = i;
15        int l = 2 * i + 1;
16        int r = 2 * i + 2;
17        if (l < n && heap[l] > heap[mxIndx]) {
18            mxIndx = l;
19        }
20        if (r < n && heap[r] > heap[mxIndx]) {
21            mxIndx = r;
22        }
23        if (mxIndx != i) {
24            swap(heap[i], heap[mxIndx]);
25            MaxHeapifyDown(mxIndx);
26        }
27    }
28
29public:
30    MaxPriorityQueue() {}
31    bool isEmpty() { return heap.empty(); }
32    int Size() { return heap.size(); }
33    int top() {
34        if (isEmpty()) {
35            return -1;
36        }
37        return heap[0];
38    }
39    void push(int x) {
40        heap.push_back(x);
41        MaxHeapifyUp(heap.size() - 1);
42    }
43    void pop() {
44        if (isEmpty()) {
45            return;
46        }
47        heap[0] = heap.back();
48        heap.pop_back();
49        if (!isEmpty()) {
50            MaxHeapifyDown(0);
51        }
52    }
53};
54
55class Solution {
56public:
57    int minStoneSum(vector<int>& v, int k) {
58        MaxPriorityQueue pq;
59        int sum = 0;
60        for (int it : v) {
61            pq.push(it);
62            sum += it;
63        }
64        while (k--) {
65            int x = pq.top();
66            pq.pop();
67            pq.push(x - x / 2);
68            sum -= x / 2;
69        }
70        return sum;
71    }
72};