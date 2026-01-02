#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArrtoLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthofLL(Node* head){
    int count = 0;
    while(head){
        head = head->next;
        count++;
    }
    return count;
}

int main(){
    vector<int> arr = {12, 19, 21, 8, 14};
    Node* head = convertArrtoLL(arr);
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl << "length of the linked-list: " << lengthofLL(head) << endl;
}
