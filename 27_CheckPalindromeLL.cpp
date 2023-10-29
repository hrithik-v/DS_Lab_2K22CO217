// 27. Check if linked list is palindrome or Not

#include <iostream>
#include <stack>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

int calcLength(Node* root){
    int size = 0;
    while(root!=NULL){
        size++;
        root = root->next;
    }
    return size;
}

bool isPalindrome(Node* root){
    stack<int> st;
    int n = calcLength(root);

    for(int i=0; i<n/2; i++){
        st.push(root->data);
        root = root->next;
    }

    if (n%2){
        root = root->next;
    }

    while(!st.empty()){
        if (st.top() == root->data){
            st.pop();
            root = root->next;
        }
        else
            return false;
    }

    return true;
}


void print(Node *root);
void insert_end(Node *&root, int data);

int main(){
    Node *root = NULL;

    insert_end(root, 1);
    insert_end(root, 2);
    insert_end(root, 3);
    insert_end(root, 2);
    insert_end(root, 1);

    print(root);

    if(isPalindrome(root))
        cout<<"It is Palindrome"<<endl;
    else    
        cout<<"It is NOT Palindrome"<<endl;

    
}

// ----------------------------------------------------

void print(Node *root)
{
    if (root == NULL)
    {
        cout << endl;
        return;
    }
    cout << root->data << " ";
    print(root->next);

    return;
}

void insert_end(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return;
    }
    insert_end(root->next, data);
    return;
}