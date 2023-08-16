#include<iostream>
#include<vector>
#include<unordered_map>
#include "../model/Student.h"
#include<algorithm>

using namespace std;
unordered_map<string,Student> Student::allStudents;
unordered_map<string,float> Student::moduleMarks;


void Student::addStudentModuleMarks(unordered_map<string,float> marks){
    moduleMarks.insert(marks.begin(), marks.end());
}

void Student::printStudentMarks(){
    for(auto it : Student::moduleMarks){
        cout <<" Student ID: "<< it.first << " Marks: " << it.second << "\n";
    }
}

void Student::displayStudent(Student s){
    cout<<"\nId: "<<s.studentId<<" Name: "<<s.name<<" Blood Group: "<<s.bloodGrp<<" Address: "<<s.address<<" DOB: "<<s.dob;
}

void Student::displayStudentWithId(string id){
            displayStudent(Student::allStudents[id]);
}
string Student::addStudent(Student s){
    if(s.studentId.length()==4){
        Student::allStudents[s.getStudentId()] = s;
        return "Success";
    }
    return "ID length Error";
}

string Student::updateStudent(Student s){
    if(s.studentId.length()==4 && (Student::allStudents.find(s.getStudentId())!=Student::allStudents.end())){
        Student::allStudents[s.getStudentId()] = s;
        return "Success";
    }
    return "ID Error";
}

string Student::deleteStudent(Student s){
    if(Student::allStudents.find(s.getStudentId())!=Student::allStudents.end()){
        Student::allStudents.erase(s.getStudentId());
        return "Success";
    }
    return "ID does not exist Error";
    
}

void Student::displayAllStudents(){
     for (auto i : Student::allStudents)
        displayStudent(i.second);
}


string Student::getStudentId()
{
    return this->studentId;
}
