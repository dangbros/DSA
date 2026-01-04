#include<bits/stdc++.h>
#include <vector>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* back;

        Node(int data1, Node* next1, Node* back1){
            data = data1;
            next = next1;
            back = back1;
        }

        Node(int data1){
            data = data1;
            next = nullptr;
            back = nullptr;
        }
};

Node* arrToDLL(vector<int> arr){
    if(arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

int main(){
    vector<int> arr = {2, 3, 6, 7, 8};
    Node* head = arrToDLL(arr);
    return 0;
}
