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

Node* insertBeforeHead(Node* head, int val) {
    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;
    return newHead;
}

Node* insertBeforeTail(Node* head, int val) {
    if(head->next == NULL)
        return insertBeforeHead(head, val);

    Node* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }

    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);

    prev->next = newNode;
    tail->back = newNode;

    return head;
}

Node* insertBeforeKth(Node* head, int val, int k){
    if(head == NULL || k <= 0) return NULL;
    if(k == 1)
        return insertBeforeHead(head, val);

    Node* temp = head;
    int cnt = 0;
    while(temp != NULL) {
        cnt++;
        if (cnt == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;

    return head;
}

void insertBeforeNode(Node* node, int val) {
    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}
int main(){
    vector<int> arr = {2, 4, 6, 7, 8};
    Node* head = arrToDLL(arr);
    print(head);
    insertBeforeNode(head->next->next->next->next, 0);
    print(head);
    return 0;
}
