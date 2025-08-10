
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val = 0) : data(val), next(nullptr) {}
};

Node* merge_disc (Node* A, Node* B) {
    Node * pa = A -> next;
    Node * pb = B -> next;
    Node * C = A;
    C -> next = nullptr;

   while (pa && pb) {
        Node * temp = nullptr;
        if (pa -> data < pb -> data) {
            temp = pa ;
            pa  = pa -> next;
        } else {
            temp = pb;
            pb = pb -> next;
        }
        temp -> next = C -> next;
        C -> next = temp;
   }

    while(pa){
        Node * temp = pa;
        pa = pa -> next;
        temp -> next = C -> next;
        C -> next = temp;
    }

    while(pb){
        Node * temp = pb;
        pb = pb -> next;
        temp -> next = C -> next;
        C -> next = temp;
    }
    delete B;
    return C;
}
