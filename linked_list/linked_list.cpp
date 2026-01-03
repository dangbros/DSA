#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

class Node {
public:
  int data;
  Node *next;

public:
  Node(int data1, Node *next1) {
    data = data1;
    next = next1;
  }

  Node(int data1) {
    data = data1;
    next = nullptr;
  }
};

Node *convertArrtoLL(vector<int> arr) {
  Node *head = new Node(arr[0]);
  Node *mover = head;
  for (int i = 1; i < arr.size(); i++) {
    Node *temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }
  return head;
}

int lengthofLL(Node *head) {
  int count = 0;
  while (head) {
    head = head->next;
    count++;
  }
  return count;
}

bool checkIfPresent(Node *head, int val) {
  Node *temp = head;
  while (temp) {
    if (temp->data == val)
      return true;
    else
      temp = temp->next;
  }
  return false;
}

Node* removeHead(Node* head){
    if(head == NULL) return head;

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* removeTail(Node * head){
    Node* temp = head;
    Node* newHead = temp;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = NULL;
    return newHead;
}
void printLL(Node* head){
    Node *temp = head;
    while (temp) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
}

int main() {
  vector<int> arr = {12, 19, 21, 8, 14};
  Node *head = convertArrtoLL(arr);
  printLL(head);
  cout << endl << "length of the linked-list: " << lengthofLL(head) << endl;
  cout << "Is 8 present in the linked-list: " << checkIfPresent(head, 8) << endl;
  head = removeHead(head);
  cout << "after head removed length of LL: " << lengthofLL(head) << endl;
  head = removeTail(head);
  printLL(head);
}
