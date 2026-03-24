// Priority Queue Algorithm Implementation In C++
#include<iostream>
#include <queue>
using namespace std;
// Main function
int main() {
    // ------------------
    // 1. Min Heap
    // ------------------
    cout<<"Enter number of terms in min heap: ";
    int n,m;
    cin>>n;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    cout<<"Enter elements in min heap: ";
    int values;
    for(int i=0;i<n;i++) {
        cin>>values;
        // Push Operation
        minHeap.push(values);
    }
    cout<<"Min Heap(ascending): ";
    while(!minHeap.empty()) {
        // Top Operation return top value from priority queue
        cout<<minHeap.top()<<" ";
        // Pop Operation delete the top value from priority queue
        minHeap.pop();
    }
    cout<<endl;
    // 🔹 Force memory release
    priority_queue<int, vector<int>, greater<int>>().swap(minHeap);

     // ------------------
    // 2. Max Heap
    // ------------------
    priority_queue<int> maxHeap;
    cout<<"Enter elements in max heap: ";
    cin>>m;
    for(int i=0;i<m;i++) {
        cin>>values;
        // Push Operation
        maxHeap.push(values);
    }
    cout<<"Max Heap(descending): ";
    while(!maxHeap.empty()) {
        // Top Operation return top value from priority queue
        cout<<maxHeap.top()<<" ";
        // Pop Operation delete the top value from priority queue
        maxHeap.pop();
    }
    cout<<endl;
    // 🔹 Force memory release
    priority_queue<int>().swap(maxHeap);
    return 0;
}

