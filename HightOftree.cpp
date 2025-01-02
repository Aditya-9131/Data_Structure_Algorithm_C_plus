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
Node*buildTree(vector<int> v){
idx ++;
      if(v[idx] == -1){
      return NULL;
     }
     Node* currNode = new Node(v[idx]);
     currNode->left = buildTree(v);
     currNode->right = buildTree(v);

     return currNode;
}
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftHit = height(root->left);
    int rightHit = height(root->right);

    int currHit = max(leftHit, rightHit) + 1;

    return currHit;
}

int main(){
    vector<int> v = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node*root = buildTree(v);
    cout << "height : " << height(root) << endl;
    return 0;
}