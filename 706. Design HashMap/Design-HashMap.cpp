1class MyHashMap {
2public:
3    int arr[1000001];
4    MyHashMap() { fill(arr, arr + 1000001, -1); }
5
6    void put(int key, int x) { arr[key] = x; }
7
8    int get(int key) { return arr[key]; }
9
10    void remove(int key) { arr[key] = -1; }
11};
12
13/**
14 * Your MyHashMap object will be instantiated and called as such:
15 * MyHashMap* obj = new MyHashMap();
16 * obj->put(key,value);
17 * int param_2 = obj->get(key);
18 * obj->remove(key);
19 */