#include "TreeNode.h"

#include <memory>

// Default constructor
template<class ItemType>
TreeNode<ItemType>::TreeNode()
{
}  // end default constructor

// copy constructor 
template<class ItemType>
TreeNode<ItemType>::TreeNode(const ItemType& data)
    : data(data), leftChildPtr(nullptr), rightChildPtr(nullptr)
{ }// end copy constructor

template <class ItemType>
TreeNode<ItemType>::TreeNode (const ItemType& data, std::shared_ptr<TreeNode<ItemType> > leftChildPtr, std::shared_ptr<TreeNode<ItemType> > rightChildPtr)
    : data(data), leftChildPtr(leftChildPtr), rightChildPtr(rightChildPtr)
{ } // end  

/******************************************************************************/
/* Function:   getData
/  Inputs:     none
/  Outputs:    Gets the data from the pointer 
/             
/  Purpose:    To get the data from the node
/             
/******************************************************************************/
template <class ItemType>
ItemType TreeNode<ItemType>::getData() const
{
    return this->data;
} // end getData

/******************************************************************************/
/* Function:   getLeftChild
/  Inputs:     none
/  Outputs:    Gets the data from the left side/child of the tree
/             
/  Purpose:    Gets the data from the left side/child of the tree
/             
/******************************************************************************/
template <class ItemType>
std::shared_ptr<TreeNode<ItemType> > TreeNode<ItemType>::getLeftChild() const
{
    return leftChildPtr;
} // end getLeftCHILD

/******************************************************************************/
/* Function:   getRightChild
/  Inputs:     none
/  Outputs:    Gets the data from the right side/child of the tree
/             
/  Purpose:    Gets the data from the tight side/child of the tree
/             
/******************************************************************************/
template <class ItemType>
std::shared_ptr<TreeNode<ItemType> > TreeNode<ItemType>::getRightChild() const
{
    return rightChildPtr;
} // end getRightCHILD

/******************************************************************************/
/* Function:   setLeftChild
/  Inputs:     none
/  Outputs:    Creastes a pointer to the left side of the child of the tree 
/             
/  Purpose:    Creastes a pointer to the left side of the child of the tree 
/             
/******************************************************************************/
template <class ItemType>
void TreeNode<ItemType>::setLeftChild(std::shared_ptr<TreeNode<ItemType> > newNode)
{
    this->leftChildPtr = newNode;
} // end setLeftChild

/******************************************************************************/
/* Function:   setRightChild
/  Inputs:     none
/  Outputs:    Creastes a pointer to the right side of the child of the tree 
/             
/  Purpose:    Creastes a pointer to the right side of the child of the tree 
/             
/******************************************************************************/
template <class ItemType>
void TreeNode<ItemType>::setRightChild(std::shared_ptr<TreeNode<ItemType> > newNode)
{
    this->rightChildPtr = newNode;
} // end setRightChild

/******************************************************************************/
/* Function:   toString
/  Inputs:     none
/  Outputs:    returns a string of the data stored from the node
/             
/  Purpose:    usefule for display fucniton, and dispalys the node data
/             
/******************************************************************************/
template <class ItemType>
std::string TreeNode<ItemType>::toString()
{
    return this->data.toString();
} // end toString