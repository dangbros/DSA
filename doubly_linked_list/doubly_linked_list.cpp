#include<bits/stdc++.h>
#include <cstddef>
#include <locale>
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

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* removeHead(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;

    return head;
}


int main(){
    vector<int> arr = {2, 3, 6, 7, 8};
    Node* head = arrToDLL(arr);
    print(head);

    head = removeHead(head);
    print(head);
    return 0;
}
