#include<bits/stdc++.h>
#include <cstddef>
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

Node* removeTail(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;

    Node* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    Node* newTail = tail->back;
    tail->back = nullptr;
    newTail->next = nullptr;
    delete tail;
    return head;
}

int countNode(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp) {
        count++;
        temp = temp->next;
    }

    return count;
}

Node* removeKth(Node* head, int k) {
    if(head == NULL || k <= 0) return NULL;
    if(k == 1) return removeHead(head);
    Node* temp = head;
    int cnt = 1;

    while(temp != NULL) {
        if(cnt == k) {
            if(temp->next == NULL) return removeTail(head);
            temp->back->next = temp->next;
            temp->next->back = temp->back;
            delete temp;
            break;
        }
        temp = temp->next;
        cnt++;
    }
    return head;
}

Node* removeEle(Node* head, int ele) {
    if(head == NULL) return NULL;
    if(ele == head->data) return removeHead(head);

    Node* temp = head;
    while(temp != NULL) {
        if(ele == temp->data) {
            if(temp->next == NULL) return removeTail(head);
            temp->back->next = temp->next;
            temp->next->back = temp->back;
            delete temp;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {2, 4, 6, 7, 8};
    Node* head = arrToDLL(arr);
    print(head);
    head = removeEle(head, 6);
    print(head);
    return 0;
}
