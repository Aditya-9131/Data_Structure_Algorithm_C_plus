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
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftH = height(root->left);
    int rightH = height(root->right);

    int currH = max(leftH, rightH) + 1;
    return currH;
}
static int idx = -1;
Node* buildTree(vector<int> data){
    if(data[idx] == -1){
        return NULL;
    }
idx++;
Node* currNode = new Node(data[idx]);
currNode->left = buildTree(data);
currNode->right = buildTree(data);

return currNode;
}
int diameter(Node* root){
    if(root == NULL){
        return 0;
    }
    int currDiameter = height(root->left) + height(root->right)+1;
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    return max(currDiameter,max(leftDiameter,rightDiameter));
}
pair<int, int>diameter2(Node* root){
    if(root == NULL){
        return make_pair(0,0);
    }
    pair<int, int> leftInfo = diameter2(root->left);
    pair<int, int> rightInfo = diameter2(root->right);

    int currDiameter = leftInfo.second + rightInfo.second + 1;

    int finaldiameter = max(currDiameter, max(leftDiameter.first, rightDiameter.first));
    int finalH(leftInfo.second, rightInfo.second);

    return(currDiameter, finalH);
}
bool isSubtree(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL)
    return true;
    if(root1->data != root2->data){
        return false;
    }
    return isIdentical(root1->left, root2->left)&&
    isIdentical(root1->right, root2->right);
}
bool isSubtree(Node* root, Node* subRoot){
    if(root == NULL && subRoot == NULL){
        return true;
    }else if(root == NULL || subRoot == NULL){
        return false;
    }
    if(root->data == subRoot->data){
       
    }
    int isLeftsubtree = isSubtree(root->left, subRoot);
    if(!isLeftsubtree){
       return isSubtree(root->right, subRoot);
    }
    return true;
}
int main(){
vector<int> data = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = buildTree(data);
cout << "diameter = " << diameter(root) << endl;
cout << "diameter = " << diameter2(root).first << endl;
Node* subRoot = new Node(2);
subRoot->left = new Node(4);
subRoot->right = new Node(5);

cout << isSubtree(root, subRoot) << endl;
    return 0;
}