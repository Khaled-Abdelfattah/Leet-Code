1class MaxPriorityQueue
2{
3private:
4    vector<int> heap;
5    void MaxHeapifyUp(int i)
6    {
7        int parent = (i - 1) / 2;
8        while (i > 0 && heap[i] > heap[parent])
9        {
10            swap(heap[i], heap[parent]);
11            i = parent;
12            parent = (i - 1) / 2;
13        }
14    }
15    void MaxHeapifyDown(int i)
16    {
17        int n = heap.size();
18        int mxIndx = i;
19        int l = 2 * i + 1;
20        int r = 2 * i + 2;
21        if (l < n && heap[l] > heap[mxIndx])
22        {
23            mxIndx = l;
24        }
25        if (r < n && heap[r] > heap[mxIndx])
26        {
27            mxIndx = r;
28        }
29        if (mxIndx != i)
30        {
31            swap(heap[i], heap[mxIndx]);
32            MaxHeapifyDown(mxIndx);
33        }
34    }
35
36public:
37    MaxPriorityQueue() {}
38    bool isEmpty()
39    {
40        return heap.empty();
41    }
42    int Size()
43    {
44        return heap.size();
45    }
46    int top()
47    {
48        if (isEmpty())
49        {
50            return -1;
51        }
52        return heap[0];
53    }
54    void push(int x)
55    {
56        heap.push_back(x);
57        MaxHeapifyUp(heap.size() - 1);
58    }
59    void pop()
60    {
61        if (isEmpty())
62        {
63            return;
64        }
65        heap[0] = heap.back();
66        heap.pop_back();
67        if (!isEmpty())
68        {
69            MaxHeapifyDown(0);
70        }
71    }
72};
73class Solution
74{
75public:
76    int lastStoneWeight(vector<int> &v)
77    {
78        MaxPriorityQueue pq;
79        for (int it : v)
80        {
81            pq.push(it);
82        }
83        while (pq.Size() > 1)
84        {
85            int x = pq.top();
86            pq.pop();
87            int y = pq.top();
88            pq.pop();
89            if (x > y)
90            {
91                pq.push(x - y);
92            }
93        }
94        return pq.isEmpty() ? 0 : pq.top();
95    }
96};