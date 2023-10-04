#ifndef _BINARY_NODE 
#define _BINARY_NODE

#include <memory>

template<class ItemType> 
class TreeNode
{
private:
    ItemType data;
    std::shared_ptr<TreeNode<ItemType> > leftChildPtr;
    std::shared_ptr<TreeNode<ItemType> > rightChildPtr;

public:
    TreeNode();
    TreeNode(const ItemType& data);
    TreeNode(const ItemType& data, std::shared_ptr<TreeNode<ItemType> > leftChildPtr, std::shared_ptr<TreeNode<ItemType> > rightChildPtr);

    ItemType getData() const;
    std::string toString();
    std::shared_ptr<TreeNode<ItemType> > getLeftChild() const;
    std::shared_ptr<TreeNode<ItemType> > getRightChild() const;
    void setLeftChild(std::shared_ptr<TreeNode<ItemType> > newNode);
    void setRightChild(std::shared_ptr<TreeNode<ItemType> > newNode);

}; // class TreeNode
#include "TreeNode.cpp"

#endif // TREE_NODE_H_