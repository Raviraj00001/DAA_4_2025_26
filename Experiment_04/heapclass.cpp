#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int heap[MAX];
int heapSize = 0;

void heapifyDown(int i) {

    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < heapSize && heap[left] < heap[smallest]) 
        smallest = left;
    if(right < heapSize && heap[right] < heap[smallest])  
        smallest = right;

    if(i != smallest) {
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}

void heapifyUp(int i) {

    while(i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(heap[(i-1)/2], heap[i]);
        i = (i-1)/2;
    } 
}

void insert(int val) {

    if(heapSize == MAX) {
        cout<<"full\n";
        return;
    }
    heap[heapSize] = val;
    heapSize++;
    heapifyUp(heapSize-1);
}

void deleteRoot() {

    if(heapSize == 0) {
        cout<<"underflow\n";
        return;
    }

    heap[0] = heap[heapSize-1];
    heapSize--;
    heapifyDown(0);
}

//search
int searchHeap(int val) {
    for(int i = 0; i < heapSize; i++) {
        if(heap[i] == val)
            return i;
    }
    return -1;
}

// delete
void deleteAt(int index) {

    if(index < 0 || index >= heapSize) {
        cout<<"invalid index\n";
        return;
    }

    heap[index] = heap[heapSize-1];
    heapSize--;

    if(index > 0 && heap[index] < heap[(index-1)/2])
        heapifyUp(index);
    else
        heapifyDown(index);
}

int main() {

    insert(3);
    insert(12);
    insert(9);
    insert(2);

    cout<<"Heap before deleteRoot: ";
    for(int i = 0; i < heapSize; i++) 
        cout<<heap[i]<<" ";
    cout<<"\n";

    deleteRoot();

    cout<<"Heap after deleteRoot: ";
    for(int i = 0; i < heapSize; i++) 
        cout<<heap[i]<<" ";
    cout<<"\n";

    int idx = searchHeap(9);
    if(idx == -1)
        cout<<"9 not found\n";
    else
        cout<<"9 found at index: "<<idx<<"\n";

    deleteAt(1);

    cout<<"Heap after deleting index 1: ";
    for(int i = 0; i < heapSize; i++) 
        cout<<heap[i]<<" ";
    cout<<"\n";

    return 0;
}
