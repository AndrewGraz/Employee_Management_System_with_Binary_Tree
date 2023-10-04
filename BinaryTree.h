#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <memory>
#include <string>

#include "TreeNode.h"
#include "EmployeeInfo.h"

template <class ItemType>
class BinaryTree
{
private:
    std::shared_ptr<TreeNode<ItemType> > root;

    std::shared_ptr<TreeNode<ItemType> > addHelper(std::shared_ptr<TreeNode<ItemType> > newNode, std::shared_ptr<TreeNode<ItemType> > currPtr, bool& adder);
    std::shared_ptr<TreeNode<ItemType> > removeHelper(std::shared_ptr<TreeNode<ItemType> > newNode, std::shared_ptr<TreeNode<ItemType> > currPtr, bool& remover);
    void displayHelper(std::string branches, std::shared_ptr<TreeNode<ItemType> > currPtr);

public:
    BinaryTree();

    bool add(const ItemType& data);
    bool remove(const ItemType& data);
    bool exists( const int& ID_Number);
    void display();
};

#include "BinaryTree.cpp"

#endif // BINARY_TREE_H_