#ifndef EMPLOYEE_INFO_H_
#define EMPLOYEE_INFO_H_

#include <string>

class EmployeeInfo
{
private:
    int ID_Number;
    std::string Name;

public:
    EmployeeInfo(const int& ID_Number, const std::string& Name);
    int getID();
    std::string getName();

    void setID(const int& ID_Number);
    void setName(const std::string& Name);
    std::string toString();

};

#include "EmployeeInfo.cpp"

#endif // EMPLOYEE_INFO_H_