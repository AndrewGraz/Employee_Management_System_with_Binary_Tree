#include "BinaryTree.h"

#include "TreeNode.h"
#include "EmployeeInfo.h"

#include <iostream>

//Default constructor, set root to nullptr
template <class ItemType>
BinaryTree<ItemType>::BinaryTree() : root(nullptr)
{ 
}// end default constructor

/******************************************************************************/
/* Function:   add
/  Inputs:     data, user entered name an id
/  Outputs:    no outputs, retruns bool statment fot letting user know 
/                  if it was added  
/             
/  Purpose:    Used for adding employee data 
/             
/******************************************************************************/
template <class ItemType>
bool BinaryTree<ItemType>::add(const ItemType& data)
{
    //creates new node
    std::shared_ptr<TreeNode<ItemType> > newNode = std::shared_ptr<TreeNode<ItemType> >(new TreeNode<ItemType>(data));
    //points to root
    std::shared_ptr<TreeNode<ItemType> > currPtr = root;
    bool adder = true; // returns true wheen completed

    root = addHelper(newNode, currPtr, adder);

    return adder; 
} // end add

/******************************************************************************/
/* Function:   addHelper
/  Inputs:     newNode, currPtr, and adder
/  Outputs:    returns the currPtr
/             
/  Purpose:    Helps the adder by recursively calling itself to get the new
/                   employee added
/             
/******************************************************************************/
template <class ItemType>
std::shared_ptr<TreeNode<ItemType> > BinaryTree<ItemType>::addHelper(std::shared_ptr<TreeNode<ItemType> > newNode, std::shared_ptr<TreeNode<ItemType> > currPtr, bool& adder)
{
    //if the currPtr is null then it is set to new node 
    if (currPtr == nullptr)
    {
        currPtr = newNode;
    }
    // if the data is the same as the id then adder is set false, ends recursion
    else if (newNode->getData().getID() == currPtr->getData().getID())
    {
        adder = false; // value already exists
    }
    // if currptr is greater than newnNode, compares id with other id  
    else if (newNode->getData().getID() < currPtr->getData().getID())
    {
        currPtr->setLeftChild(addHelper(newNode, currPtr->getLeftChild(), adder)); //traverse through recursion
    }
    //if currptr is less than newnNode, compares id with other id  
    else 
    {
        currPtr->setRightChild(addHelper(newNode, currPtr->getRightChild(), adder)); //traverse through recursion
    }
    return currPtr;//returns the curptr
} // end AddHelper

/******************************************************************************/
/* Function:   exists
/  Inputs:     id number 
/  Outputs:    checks to see if a file exist or not, displays the employee 
/                   name and id. 
/             
/  Purpose:    used in order to tell if a file exist 
/             
/******************************************************************************/
template <class ItemType>
bool BinaryTree<ItemType>::exists(const int& id)
{
    //points to root
    std::shared_ptr<TreeNode<ItemType> > currPtr = root;

    //while currptr is not equal to null 
    while (currPtr != nullptr)
    {
        //if the currptr ID is equal to the input id  display the employee id and name and return true
        if (currPtr->getData().getID() == id)
        {
            std::string value_name = currPtr->getData().getName();
            std::cout << "Employee name: " << value_name << "\n";
            std::cout << "Employee ID: " << id << "\n";
            return true;
        }
        //traverse the left side if curptr is to id is bigger than input id 
        else if (currPtr->getData().getID() > id)
        {
            currPtr = currPtr->getLeftChild();
        }
        //traverse the right side if curptr is to id is smaller than input id 
        else 
        {
            currPtr = currPtr->getRightChild();
        }
    }

    return false;
} // end exists


/******************************************************************************/
/* Function:   display
/  Inputs:     none
/  Outputs:    dispalys the tree
/             
/  Purpose:    used in order to display the tree of employees
/             
/******************************************************************************/
template <class ItemType>
void BinaryTree<ItemType>::display()
{
    //points to root 
    std::shared_ptr<TreeNode<ItemType> > currPtr = root; 
    //calls helper, for recursion in order to traverse
    displayHelper("", currPtr);


} // end DisplayTree

/******************************************************************************/
/* Function:   displayHelper
/  Inputs:     branches and currptr
/  Outputs:    dispalys the tree
/             
/  Purpose:    helps the diaply function display the tree of employees
/             
/******************************************************************************/
template <class ItemType>
void BinaryTree<ItemType>::displayHelper(std::string branches, std::shared_ptr<TreeNode<ItemType> > currPtr)
{
    // if root isn't null, display the tree
    if (currPtr != nullptr)
    {
        // displays the iformation
        std::cout << currPtr -> toString() << "     ";
        // traverse right side
        displayHelper("   ", currPtr->getRightChild());

        // traverse left side
        displayHelper("   ", currPtr->getLeftChild());
    }
} // end DisplayTreeHelper



