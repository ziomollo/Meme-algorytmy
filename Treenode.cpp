#include "tree.hpp"

void Tree::push(int a)
{
    if(root!=nullptr)
        push(root,a);
    else
    {
        root=new Treenode;
        root->val=a;
        root->left=nullptr;
        root->right=nullptr;
    }
}

void Tree::push(Treenode* node, int n)
{
    if(n< node->val)
    {
        if(node->left!=nullptr)
         push(node->left, n);
        else
        {
          node->left=new Treenode;
          node->left->val=n;
          node->left->left=nullptr;
          node->left->right=nullptr;
        }
    }
    else if(n>=node->val)
    {
        if(node->right!=nullptr)
          push(node->right, n);
        else
        {
          node->right=new Treenode;
          node->right->val=n;
          node->right->left=nullptr;
          node->right->right=nullptr;
        }
    }
}

bool Tree::find(int n)
{
    return this->find(root,n);
}

bool Tree::find(Treenode* node, int n)
{
    if(node->val == n)
        return true;
    else if(root->val > n)
        return find(node->left, n);
    else return find(node->right, n);
}
