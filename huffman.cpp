#include<bits/stdc++.h>
using namespace std;

struct node{
    char ch='\0';
    int fre ;
    node* left,*right;
};

struct node *create(char c, int key)
{
    struct node *temp = new node();
    temp->ch = c;
    temp->fre = key;
    temp->left = temp->right = nullptr;
    return temp;
}

struct node* insert(struct node* root, int key, char c) {
    if (root == nullptr) {
        return create(c, key);
    }
    if (key < root->fre) {
        root->left = insert(root->left, key, c);
    }
    else if (key > root->fre) {
        root->right = insert(root->right, key, c);
    }
    return root;
}

void preorder(struct node *root, string s)
{
   if(root==nullptr)  //base case
   {
       return;
   }
   if(root->left==nullptr && root->right==nullptr)
   {
       cout << root->ch << ' ' << s << endl;
   }

   preorder(root->left, s + '0');
   preorder(root->right, s + '1');
}

void collectNodes(struct node* root, vector<struct node*>& nodes) {
    if (root == nullptr){
        return;
    }
    nodes.push_back(root);
    collectNodes(root->left, nodes);
    collectNodes(root->right, nodes);
}

struct node* sortAndMerge(vector<struct node*>& nodes) {
    while (nodes.size() > 1) {
        sort(nodes.begin(), nodes.end(), [](struct node* a, struct node* b) {
            return a->fre < b->fre;
        });

        struct node* left = nodes[0];
        struct node* right = nodes[1];

        struct node* merged = create('\0', left->fre + right->fre);
        merged->left = left;
        merged->right = right;

        nodes.erase(nodes.begin());  // remove these 2 nodes
        nodes.erase(nodes.begin());
        nodes.push_back(merged);
    }

    return nodes[0];  // return the root node
}

int main()
{
    int n, fre;
    char ch;
    vector<pair<char, int>> cha;

    cout << "ENTER THE NUMBER OF CHARACTER:" << endl;
    cin >> n;

    cout << "ENTER CHARACTER AND FREQUENCY:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> ch >> fre;
        cha.push_back({ch, fre});
    }

    vector<struct node*> nodes;


    for (int i = 0; i < cha.size(); i++) {
        struct node* temp = create(cha[i].first, cha[i].second);
        nodes.push_back(temp);
    }

    struct node* root = sortAndMerge(nodes);
    cout << "Huffman Codes:" << endl;
    preorder(root, "");
}
