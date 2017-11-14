#ifndef TREE_HPP_
#define TREE_HPP_

class Tree
{
public:
    Tree()
    {
        this->root = nullptr;
    }
    ~Tree(){}

    void push(int a);

    bool find(int n);

    //void delete(int n);

private:
    struct Treenode{

        Treenode* left {nullptr};
        Treenode* right {nullptr};
        int val;

        Treenode(){}

    };

    Treenode* root;

private:
    void push(Treenode* node,int n);

    //void delete(Treenode* node, int n);

    bool find(Treenode* node,int n);
};

#endif // TREE_HPP_
