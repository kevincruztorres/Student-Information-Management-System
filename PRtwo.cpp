#include <iostream>

using namespace std;

int main()
{
    const int MAX=100;
    string StudentName[MAX];
    int StudentsGrade[MAX];
    int ID[MAX];
    int op, grade, number, retrieve, del, lowest, highest;
    string name;
    int validity = 0;
    double avg;
    int total = 0;
    int usedID = 0;

    while(op != 6)
    {
        cout << "\n***CSCI 1010 Student Information Management System***" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Search Student" << endl;
        cout << "3. Remove Student" << endl;
        cout << "4. Display lowest, highest and average grades" << endl;
        cout << "5. Display all Students" << endl;
        cout << "6. Exit" << endl;
        cout << "\nChoose an option: ";
        cin >> op;
        
        switch(op)
        {
            case 1:
                if (total >= MAX)
                {
                    cout << "\nError. Maximum student capacity reached" << endl;
                }

                else
                {
                    cout << "The ID for the new student is: ";
                    cin >> number;

                    if(number + total >= MAX)
                    {
                        cout << "\nThis number of students cannot be added. The number entered is " << MAX - number + total << " over the maximum." << endl;
                        break;
                    }

                    for(int i=1; i <= number; i++)
                    {
                        ID[total] = usedID + 1;
                        cout << "Enter new student's name (Lastname,FirstName) (" << i << "/" << number << "): ";
                        cin >> name;
                        cout << "Enter new student's grade: ";
                        cin >> grade;
                        StudentName[total] = name;
                        StudentsGrade[total] = grade;

                        usedID += 1;
                        total += 1;

                        cout << "***Student successfully added***\n" << endl;
                    }
                }
                break;

            case 2:
                cout << "Enter student's ID: ";
                cin >> retrieve;
                validity = 0;
                for(int i=0; i<usedID; i++)
                {
                    if(retrieve <= i && i >= total)
                    {
                        validity = 1;
                        break;
                    }
                    else
                    {
                        validity = 0;
                    }
                }
                
                if(retrieve < 1 || retrieve > usedID)
                {
                    cout << "\n***Error. Try again.***" << endl;   
                }

                else if(validity == 1)
                {
                    cout << "\n***Error. ID does not exist.***" << endl;
                    validity = 0;
                    break;
                }

                else
                {
                    int i=0;
                    cout << "entering else" << endl;
                    while(i <= usedID)
                    {
                        if(ID[i] == retrieve)
                        {
                            retrieve = i;
                            break;
                        }
                        else
                        {
                            i++;
                        }
                    }
                    cout << "\nStudent ID: " << ID[retrieve] << "\nStudent Name: " << StudentName[retrieve] << "\nStudent Grade: " << StudentsGrade[retrieve] << endl;
                }
                break;

            case 3:
                cout << "Enter Student's ID: ";
                cin >> del;
                int i;
                validity = 0;

                for(i=0; i<usedID; i++)
                {
                    if(del <= i && i >= total)
                    {
                        validity = 1;
                        break;
                    }
                    else
                    {
                        validity = 0;
                    }
                }

                if(del < 1 || del > usedID-1)
                {
                    cout << "***Error. Invalid input.***" << endl;
                }

                else if(validity == 1)
                {
                    cout << "\n***Error. Student ID does not exist.***" << endl;
                    validity = 0;
                    break;
                }

                else
                {
                    int i=0;
                    while(i < usedID)
                    {
                        if(ID[i] == del)
                        {
                            del = i;
                            break;
                        }
                        i++;
                    }
                    
                    for(i = del; i < total-1; i++)
                    {
                        StudentsGrade[i] = StudentsGrade[i+1];
                        StudentName[i] = StudentName[i+1];
                        ID[i] = ID[i+1];
                    }
                    
                    total--;
                    cout << "\n***Student Successfully Removed From Database***\n" << endl;
                }
                break;
  
            case 4:
                lowest = 10000;
                highest = 0;
                avg = 0;
                for(int i=0; i < total; i++)
                {
                    if(lowest > StudentsGrade[i])
                    {
                        lowest = StudentsGrade[i];
                    }
                    
                    if(highest < StudentsGrade[i])
                    {
                        highest = StudentsGrade[i];
                    }
                    
                    avg += StudentsGrade[i];
                }
                
                avg /= total;
                cout << "Lowest Grade: " << lowest << endl;
                cout << "Highest Grade: " << highest << endl;
                cout << "Average Grade: " << avg << endl;
                
                cout << endl;
                break;
  
            case 5:
                cout << "Student ID:\t" << "Student Name:\t" << "Student Grade:\t" << endl;     
                for(int i=0; i < total; i++)
                {
                    cout << ID[i] << "\t\t" << StudentName[i] << "\t\t" << StudentsGrade[i] << endl;
                }
                cout << "Total number of students: " << total << endl;
                break;

            case 6:
                cout << "***Successfully Existed the Student Information Management System***\n";
                return 0;

            default:
                cout << "***Error. Try again.***" << endl;
                return 0;
            }
        }
        return 0;
    }