// TITLE         ACC COSC-2436 - Lab 4
// AUTHOR:       Andrew Graziano
// Professor:    Kathryn Rehfield
// DESCRIPTION:  Get an employee file from the user, read the contents into a tree, then ask the user if they want 
//                     to dipslay the tree of employees, add, or check for existing employess. 
//               

#include <iostream>
#include <fstream>
#include <sstream>
#include "BinaryTree.h"
#include "EmployeeInfo.h"

using namespace std;

int main()
{
    BinaryTree<EmployeeInfo> employeeTree; //creates a 
    bool restart = true; //used for knowing when to restart the program
    bool file_valid = false; //used to know if the file is calid 
    ifstream reader_file; //file for reading from
    string file; //used to hold the name of the file the user want to enter
    string line; //used in read from each line of the file
    int selection; //used in finding what optino the user wants to do  .

    while(file_valid == false)
    {
        cout << "Enter the file name: \n";
        cin >> file;
        reader_file.open(file); //opens the file
        if(reader_file)
        {
            file_valid = true; //ends loop
            cout << "The file you entered is opening. \n"; 
        }
        else
        {
            cout << "The file you entered does not exist. \n";
        }//end if
    }//end while loop
    
    //goes through the file and
    while (reader_file)
    {
        string Employee_ID;//gets the id of the employee from frist number on documet
        string Employee_name;//gets the name of the employee from second section on documet

        if (getline(reader_file, line)) //if there is a line reads it
        {
            //gets the number and the name of the employee
            stringstream ss(line);
            if (ss >> Employee_ID >> Employee_name) 
            {
                employeeTree.add(EmployeeInfo(stoi(Employee_ID), Employee_name)); 

            }//end if
        }//end if
    }//end while loop
    reader_file.close(); //closes up file 

    //continues the program as long as restart is equal to true
    while(restart == true)
    {

        cout << "Press 1 to Find the Employee. \n"
             << "Press 2 to Add an Employee. \n"
             << "Press 3 to Remove an Employee \n"
             << "Press 4 to Display the employee's numbers and ID's. \n"
             << "Press 5 to quit the program. \n";
        
        cin >> selection; //get user selction
        //defines user selection
        switch (selection)
        {
            case 1: //finds if employee exist
            {
                string ID_finder;
                int int_ID_finder;

                cout << "Enter the ID you want to find: \n";
                cin >> ID_finder;

                int_ID_finder = stoi(ID_finder);
                if(employeeTree.exists(int_ID_finder) == true)
                {
                    cout << "The employee exist. \n";
                }
                else
                {
                    cout << "The employee does not exist. ";
                }
            } //end case 1 
                break;
            case 2: // adds emplyee 
            {
                string Employee_name; //used to get employee name
                int Employee_ID; //used to get employee id
                //get employee info 
                cout << "Please eneter the new Employee name: \n";
                cin >> Employee_name;
                cout << "Please enter the nbew Employee ID number: \n";
                cin >> Employee_ID; 

                //makes certain that what the user input was valid, and that they did not include too many names
                try
                {
                    EmployeeInfo newEmployee (Employee_ID, Employee_name);
                    //adds new employee to the roster
                    if (employeeTree.add(newEmployee))
                    {
                        cout << "New employee was added. \n"; 
                    }
                    else 
                    {
                        cout << "Employee number already exist. \n";
                    }
                }
                catch(const invalid_argument& e)
                {
                    cout << "You did not enter a valid input value.\n ";
                } //end try catch statemnt
            }//end case 2
                break; 
            case 3: //removes
            {
                cout << "nothing to see here yet \n";
            }//end case 3
                break; 
            case 4: //displays the tree
            {
                employeeTree.display();
            }//end case 4
                break; 
            case 5: //quits program
            {
                cout << "Program is quitting. \n";
                restart = false; 
            }//end case 5 
                break; 
            default:
                cout << "What you entered was not a valid option. \n";
                break;
        }//end switch
    }//end while 
}//end main