#include<iostream>
#include "service/Student.cpp"
#include "service/Module.cpp"

using namespace std;

int main(){
    cout<<"Hello All";

    int input;

    do{
        cout<<"\n1> Add Student Record: ";
        cout<<"\n2> Update Student Record: ";
        cout<<"\n3> Get One Student Record: ";
        cout<<"\n4> Get All Student Record: ";
        cout<<"\n5> Add Module: ";
        cout<<"\n6> Get One Module Data: ";
        cout<<"\n7> Get All Module Data: ";
        cout<<"\n8> Update One Module: ";
        cout<<"\n9> Add Student Marks For Each Module: ";
        cout<<"\n10> Find Student Marks: ";
        cout<<"\n0> Exit: ";
        cout<<"\n\nEnter your choice: ";
        
        cin>>input;

        if(input == 1){
            string id,name,bloodGrp,address,dob;
            float marks;
            cout<<"Enter Student ID <space> Name <space> Blood Grp <space> Address <space> DOB <space> marks: ";
            cin>>id>>name>>bloodGrp>>address>>dob>>marks;
            string response = Student::addStudent(Student(id,name,bloodGrp,address,dob));
            Student::moduleMarks[id] = marks;
            cout<<"\n Student Add "<<response;
        }

        else if(input == 2){
            string id,name,bloodGrp,address,dob;
            cout<<"Enter Updated Student ID <space> Name <space> Blood Grp <space> Address <space> DOB: ";
            cin>>id>>name>>bloodGrp>>address>>dob;
            string response = Student::updateStudent(Student(id,name,bloodGrp,address,dob));
            cout<<"\nUpdate "<<response;
        }

        else if(input == 3){
            string studentId;
            cout<<"Enter Student ID: ";
            cin>>studentId;
            Student::displayStudentWithId(studentId);
        }

        else if(input == 4){
            Student::displayAllStudents();
        }

        else if(input==5){
            string id,name,startDate;
            int durationInMonths,fees;
            cout<<"Enter Module ID <space> Name <space> Duration In Months <space> Fees <space> Start Date: ";
            cin>>id>>name>>durationInMonths>>fees>>startDate;
            string response = Module::addModule(Module(id,name,durationInMonths,fees,startDate));
            cout<<"\n Module Add "<<response;
        }

        else if (input == 6){
            string moduleId;
            cout<<"Enter Module ID: ";
            cin>>moduleId;
            Module::displayModuleWithId(moduleId);
        }

        else if (input == 7){
            Module::displayAllModules();
        }

        else if(input == 8){
            string id,name,startDate;
            int durationInMonths,fees;
            cout<<"Enter Updated Module ID <space> Name <space> Duration In Months <space> Fees <space> Start Date: ";
            cin>>id>>name>>durationInMonths>>fees>>startDate;
            string response = Module::updateModule(Module(id,name,durationInMonths,fees,startDate));
            cout<<"\nUpdate "<<response;
        }

        else if (input == 9){
            cout<<"\nEnter the number of marks you want to publish: ";
            int n;
            cin>>n;
            unordered_map<string,float> temp;

            for(int i=0;i<n;i++){
                string studentId;
                float marks;
                cout<<"\nEnter student id: ";
                cin>>studentId;
                cout<<"\nEnter marks: ";
                cin>>marks;
                temp[studentId] = marks;
            }
            Student::moduleMarks.insert(temp.begin(),temp.end());
        }

        else if(input==10){
            Student::printStudentMarks();
        }

        else if(input == 0){
            cout<<"\n Thank you!";
            break;
        }

    }while(input!=0);
}