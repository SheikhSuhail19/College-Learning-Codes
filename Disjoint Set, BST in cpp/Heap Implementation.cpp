#include <bits/stdc++.h>
using namespace std;

class Heap {
  
public:
    int arr[1001];
    int size;
    
    Heap() {
        size = 0;
    }
    
    void insertIntoHeap(int val) {
        size++;
        int index = size-1;
        arr[index] = val;
        
        while(index >= 0) {
            int parent = index/2;
            
            if(arr[parent] < arr[index]) {
                swap(arr[parent],arr[index]);
                index = parent;
            }
            
            else {
                return;
            }
        }
    }
    
    void printHeap() {
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    void deleteFromHeap() {
        if(size == 0) {
            cout << "Heap is Empty" << endl;
            return;
        }
        
        arr[0] = arr[size-1];
        size--;
        
        int i = 0;
        while(i < size) {
            int left = 2*i+1;
            int right = 2*i+2;
            
            if(left < size && arr[left] > arr[i]) {
                swap(arr[left],arr[i]);
                i = left;
            }
            else if(right < size && arr[right] > arr[i]) {
                swap(arr[right],arr[i]);
                i = right;
            }
            else {
                return;
            }
        }
    }
    
};

void minHeapify(int i, vector<int> &arr, int n) {
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if(right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }
    
    if(smallest != i) {
        swap(arr[smallest],arr[i]);
        minHeapify(smallest,arr,n);
    }
    
}

void maxHeapify(int i, vector<int> &arr, int n) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    if(largest != i) {
        swap(arr[largest],arr[i]);
        maxHeapify(largest,arr,n);
    }
    
}

void heapSort(vector<int> &arr, int n) {
    int size = n-1;
    while(size > 1) {
        swap(arr[0],arr[size]);
        size--;
        maxHeapify(0,arr,size);
    }
}

int main() {
    
    Heap h;
    h.insertIntoHeap(4);
    h.insertIntoHeap(3);
    h.insertIntoHeap(12);
    h.insertIntoHeap(42);
    h.insertIntoHeap(10);
    h.insertIntoHeap(41);
    h.insertIntoHeap(1);
    
    h.printHeap();
    
    h.deleteFromHeap();
    h.deleteFromHeap();
    
    h.printHeap();
    
    vector<int> arr = {54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2-1; i >= 0; i--) {
        maxHeapify(i,arr,n);
    }
    
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    heapSort(arr,n);
    
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // MAX HEAP
    priority_queue<int> pq;
    pq.push(4);
    pq.push(31);
    pq.push(42);
    pq.push(311);
    pq.push(14);
    pq.push(13);
    
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    
    
    // MIN HEAP
    priority_queue<int, vector<int>, greater<int> > mpq;
    mpq.push(4);
    mpq.push(31);
    mpq.push(42);
    mpq.push(311);
    mpq.push(14);
    mpq.push(13);
    
    while(!mpq.empty()) {
        cout << mpq.top() << " ";
        mpq.pop();
    }
    cout << endl;
    
    return 0;
}
