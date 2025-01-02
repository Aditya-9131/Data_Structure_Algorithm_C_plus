#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};
static int idx = -1;
Node* builtTree(vector<int> result){
idx++;
    if(result[idx] == -1){
    return NULL;
   }
   Node* currNode = new Node(result[idx]);
   currNode->left = builtTree(result);
   currNode->right = builtTree(result);

   return currNode;
};
int count(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftCount = count(root->left);
    int rightCount = count(root->right);
    return leftCount + rightCount + 1;
}
int main(){
    vector<int> result = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = builtTree(result);
    cout << "count : " << count(root) << endl;

    Node* root2 = new Node(5);
    root2 -> left = new Node(3);
    root2 -> right = new Node(4);
    return 0;
}