// Data Structures <DS6> Project Implemented by Ghaid E. Althobaity 

#include <iostream>
using namespace std;

// An employee record class 
class EmpRecord{
    // private feilds
    private:
        string empID;
        string empName;
        string empFirstDay;
        string empPhoneNo;
        string empAddress;
        int empWorkHours;
        double empSalary;
        EmpRecord *next;



    // public fields
    public: 
        // A constructor with parameters
        EmpRecord (string ID,string Name,string FirstDay,string PhoneNo,string Address,int WorkHours,double Salary){
            empID = ID;
            empName = Name;
            empFirstDay = FirstDay;
            empPhoneNo = PhoneNo;
            empAddress = Address;
            empWorkHours = WorkHours;
            empSalary = Salary;
            next = NULL;
        }

        //*************************************** Setters *****************************************
        void setEmpID(string empID){
            this->empID = empID;
        }

        void setEmpName(string empName){
            this->empName = empName;
        }

        void setEmpFirstDay(string empFirstDay){
            this->empFirstDay = empFirstDay;
        }

        void setEmpPhoneNo(string empPhoneNo){
            this->empPhoneNo = empPhoneNo;
        }

        void setEmpAddress(string empAddress){
            this->empAddress = empAddress;
        }
        
        void setNext(EmpRecord *next){
            this->next = next;
        }

        void setEmpSalary(double empSalary){
            this->empSalary = empSalary;
        }

        void setEmpWorkHours(int empWorkHours){
            this->empWorkHours = empWorkHours;
        }

        //************************************* Getters *******************************************
        string getEmpID(){
            return this->empID;
        }

        string getEmpName(){
            return this->empName;
        } 

        string getEmpFirstDay(){
            return this->empFirstDay;
        }

        string getEmpPhoneNo(){
            return this->empPhoneNo;
        }
        
        string getEmpAddress(){
            return this->empAddress;
        }

        int getEmpWorkHours(){
            return this->empWorkHours;
        }

        double getEmpSalary(){
            return this->empSalary;
        }

        EmpRecord *getNext(){
            return this->next;
        }
}; // End of EmpRecord

class EmpLinkedList{
    // private fields
    private:
        EmpRecord* head;

    // public fields
    public:
        // A constructor
        EmpLinkedList(){
            head = NULL;
        }

        //********************************* Methods ***************************************

        // A method to check if ID exists in list
        bool checkRecord(string ID){
            bool flag = false;
            EmpRecord* temp = head;
            while(temp != NULL){
                if(temp->getEmpID() == ID){
                    flag = true;
                    break;
                }
                temp = temp->getNext();
            }
            return flag;
        }

        // A method to insert a employee record in list
        void insertRecord(string ID,string Name,string FirstDay,string PhoneNo,string Address,int WorkHours,double Salary){
            // ID must be unique
            if(checkRecord(ID)){
                cout<<"Employee with ID "<<ID<<" Already exsits."<<endl;
            }else{
                EmpRecord* newEmp = new EmpRecord( ID, Name, FirstDay, PhoneNo, Address, WorkHours, Salary);
                // insert at the begining
                // if empty list or first node's ID is larger than new ID (sorted insert)
                if (head == NULL || head->getEmpID() >= newEmp->getEmpID()){
                    newEmp->setNext(head);
                    head = newEmp;
                }else{
                    EmpRecord* temp = head;
                    // insert at the middle or end
                    while (temp->getNext() != NULL && (temp->getNext())->getEmpID() < newEmp->getEmpID()){
                        temp = temp->getNext();
                    }
                    newEmp->setNext(temp->getNext());
                    temp->setNext(newEmp);
                }
                cout<<"Employee with ID "<<newEmp->getEmpID()<<" Was ADDED successfully."<<endl;
            }
        }

        // A method to delete a record from list 
        void deleteRecord(string ID){
            EmpRecord* prevEmp = NULL; // hold prev record
            EmpRecord* temp = head;
            // if empty
            if (temp == NULL){
                cout<<"No records in DB"<<endl;
            }else{
                // if exist
                if(checkRecord(ID)){
                    // traversing
                    while(temp != NULL){
                        if(temp->getEmpID() == ID){
                            break;
                        }
                        prevEmp = temp;
                        temp = temp->getNext();
                    } 

                    // Del from front  
                    if(prevEmp == NULL){
                        head = head->getNext();
                        delete temp;
                    }else{
                        prevEmp->setNext(temp->getNext());
                        delete temp;
                    }
                    cout<<"Employee with ID "<<ID<<" Was DELETED successfully."<<endl;
                }else{
                    cout<<"Employee with ID "<<ID<<" does not exsit."<<endl;
                    return;
                }
            }
            
        }

        // A method to display all records
        void displayAll(){
            EmpRecord* temp = head;
            // if empty
            if(temp == NULL){
                cout<<"DB is empty"<<endl;
                return;
            }
            while (temp != NULL){
                cout<<"__________________________________________________________"<<endl;
                cout<<"\nEnter Employee's Name: "<<temp->getEmpName()<<endl;
                cout<<"Enter Employee's ID: "<<temp->getEmpID()<<endl;
                cout<<"Enter First Day of Work: "<<temp->getEmpFirstDay()<<endl;
                cout<<"Enter Employee's Phone Number: "<<temp->getEmpPhoneNo()<<endl;
                cout<<"Enter Employee's Address: "<<temp->getEmpAddress()<<endl;
                cout<<"Enter Employee's Work hours: "<<temp->getEmpWorkHours()<<endl;
                cout<<"Enter Employee's Salary: "<<temp->getEmpSalary()<<endl;

                temp = temp->getNext();
            }
            cout<<"__________________________________________________________"<<endl;
        }

        // A method to display a record
        void searchEmp(string ID){
            EmpRecord* temp = head;
            if(checkRecord(ID)){
                while(temp != NULL){
                    if(temp->getEmpID() == ID){
                        cout<<"__________________________________________________________"<<endl;
                        cout<<"Enter Employee's Name: "<<temp->getEmpName()<<endl;
                        cout<<"Enter Employee's ID: "<<temp->getEmpID()<<endl;
                        cout<<"Enter First Day of Work: "<<temp->getEmpFirstDay()<<endl;
                        cout<<"Enter Employee's Phone Number: "<<temp->getEmpPhoneNo()<<endl;
                        cout<<"Enter Employee's Address: "<<temp->getEmpAddress()<<endl;
                        cout<<"Enter Employee's Work hours: "<<temp->getEmpWorkHours()<<endl;
                        cout<<"Enter Employee's Salary: "<<temp->getEmpSalary()<<endl;
                        return ;
                    }
                    temp = temp->getNext();
                }
                cout<<"__________________________________________________________"<<endl;
            }else{
                cout<<"Employee with ID "<<ID<<" does not exsit."<<endl;
            }
            
        }

        // A method to update salary of employee if working hours greater than 32
        void updateSal(string ID){
            EmpRecord* temp = head;
            double newSal=0;
            double curSal=0;
            if(checkRecord(ID)){
                while(temp != NULL){
                    if((temp->getEmpID() == ID ) && (temp->getEmpWorkHours()>=32)){
                        curSal = temp->getEmpSalary();
                        newSal =  curSal + (curSal*0.02);
                        temp->setEmpSalary(newSal);
                        cout<<"Employee with ID "<<ID<<" has been updated."<<endl;
                        break;
                    }
                    else if ((temp->getEmpID() == ID ) && (temp->getEmpWorkHours()<=32)){
                        cout<<"Employee with ID "<<ID<<" is not eligible for an update."<<endl;
                    }
                    temp = temp->getNext();
                }
            }else{
                cout<<"Employee with ID "<<ID<<" does not exsit."<<endl;
            }
        }

};

int main(){
    // Declare variables 
    int choice, WorkHours;
    double Salary;
    string ID, Name, FirstDay, PhoneNo, Address;

    // Create a list
    EmpLinkedList* emp = new EmpLinkedList();

    cout<<"\n********************* Welcome to Employees DBMS, Enter the number of service *********************"<<endl;
    do{
        // Display menu
        cout<<"\n1- Insert Employee Record"<<endl;
        cout<<"2- Delete Employee Record"<<endl;
        cout<<"3- update Employee's Salary"<<endl;
        cout<<"4- Display Employee Records"<<endl;
        cout<<"5- Search Employee Record"<<endl;
        cout<<"6- Exit"<<endl;

        // Get wanted service
        cout<<"\nNumber of service: ";
        cin>>choice;

        switch (choice){
        // Insert
        case 1:
        // Get information of employee
            cout<<"Enter Employee's Name: ";
            cin>>Name;
            cout<<"Enter Employee's ID: ";
            cin>>ID;
            cout<<"Enter First Day of Work: ";
            cin>>FirstDay;
            cout<<"Enter Employee's Phone Number: ";
            cin>>PhoneNo;
            cout<<"Enter Employee's Address: ";
            cin>>Address;
            cout<<"Enter Employee's Work hours: ";
            cin>>WorkHours;
            cout<<"Enter Employee's Salary: ";
            cin>>Salary;

            emp->insertRecord(ID, Name, FirstDay, PhoneNo, Address, WorkHours, Salary);
            break;

        // Delete
        case 2:
        // Get Employee ID
            cout<<"Enter Employee's ID: ";
            cin>>ID;
            emp->deleteRecord(ID);
            break;

        // Update
        case 3:
        // Get Employee ID
            cout<<"Enter Employee's ID: ";
            cin>>ID;
            emp->updateSal(ID);
            break;

        // Display
        case 4:
            emp->displayAll();
            break;

        // Search
        case 5:
        // Get Employee ID
            cout<<"Enter Employee's ID: ";
            cin>>ID;
            emp->searchEmp(ID);
            break;
        
        // Exit
        case 6: 
        cout<<"Exiting...";
            exit(0);

        default:
            cout<<"Invalid choice. Try again.";
            break;
        }
    }while(choice != 6);

    return 0;
}