#include <bits/stdc++.h>
using namespace std;

struct treeNode{

int data;
treeNode* left;
treeNode* right;

};

struct treeNode *create(int key)
{
    struct treeNode *temp=(struct treeNode*)malloc (sizeof(struct treeNode));
    cout<<"ENTER THE KEY:"<<key <<endl ;
    temp->data=key ;
    temp->left=temp->right=nullptr ;
    return temp ;
}

struct treeNode *preorder(struct treeNode *root)
{
  if(root!=nullptr)
  {
      cout<< root->data << " " ;
      preorder(root->left);
      preorder(root->right);
  }

}

struct treeNode *inorder(struct treeNode *root)
{
  if(root!=nullptr)
  {
      preorder(root->left);
      cout<< root->data << " " ;
      preorder(root->right);
  }

}

struct treeNode *postorder(struct treeNode *root)
{
  if(root!=nullptr)
  {
      preorder(root->left);
      preorder(root->right);
      cout<< root->data << " " ;
  }

}

struct treeNode *insert(struct treeNode *root,int key)
{
    if(root==nullptr)
    {
        return create(key);
    }
    if(key < root->data)
    {
        root->left=insert(root->left,key);
    }
    else if(key>root->data)
    {
        root-> right=insert(root->right,key);
    }
    return root ;

}

int main()
{
    treeNode *root=nullptr ;

    root =insert(root,50);
    root =insert(root, 30);
    root =insert(root, 70);
    root =insert(root, 20);
    root =insert(root, 40);
    root =insert(root, 60);
    root =insert(root, 80);

    cout<< "pre order traversal:" ;
    preorder(root);
    cout<<endl ;

    cout << "In-order Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postorder(root);
    cout << endl;
}

