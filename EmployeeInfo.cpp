#include "EmployeeInfo.h"

#include <string>

//default constructor 
EmployeeInfo::EmployeeInfo(const int& ID_Number, const std::string& Name)
    : ID_Number(ID_Number), Name(Name)
{ }

/******************************************************************************/
/* Function:   getID
/  Inputs:     none
/  Outputs:    returns the id
/             
/  Purpose:    gets the id number
/             
/******************************************************************************/
int EmployeeInfo::getID()
{
    return ID_Number;
} // end getID

/******************************************************************************/
/* Function:   getName
/  Inputs:     none
/  Outputs:    returns the name 
/             
/  Purpose:    Used to get the name attacthed with the idnumber
/             
/******************************************************************************/
std::string EmployeeInfo::getName()
{
    return Name;
} // end getName

/******************************************************************************/
/* Function:   setID
/  Inputs:     Takes the int of the number for the ID
/  Outputs:    none
/             
/  Purpose:    Used to set the id number
/             
/******************************************************************************/
void EmployeeInfo::setID(const int& ID_Number)
{
    this->ID_Number = ID_Number;
} // end setID

/******************************************************************************/
/* Function:   setName
/  Inputs:     takes the string for the name of the employee 
/  Outputs:    none
/             
/  Purpose:    Used in setting the name of the employee
/             
/******************************************************************************/
void EmployeeInfo::setName(const std::string& Name)
{
    this->Name = Name;
} // end setName

/******************************************************************************/
/* Function:   toString
/  Inputs:     none
/  Outputs:    displays the name and the id number 
/             
/  Purpose:    Used for displayning the names of the employees
/             
/******************************************************************************/
std::string EmployeeInfo::toString()
{
    return this->Name + " [" + std::to_string(this->ID_Number) + "]";
} // end toString