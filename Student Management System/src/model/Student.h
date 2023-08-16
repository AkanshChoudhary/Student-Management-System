#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<vector>
#include<unordered_map>
#include "../model/Module.h"

using namespace std;

class Student{
    private:
        string studentId;
        string name;
        string bloodGrp;
        string address;
        string dob;
        
    public:
        static unordered_map<string,Student> allStudents;
        static unordered_map<string,float> moduleMarks;
        Student(){}
        Student(string studentId,string name,string bloodGrp,string address,string dob){
            this->studentId = studentId;
            this->name = name;
            this->bloodGrp = bloodGrp;
            this->address = address;
            this->dob = dob;
        }
        
        void addStudentModuleMarks(unordered_map<string,float> marks);


        static void displayStudent(Student s);

        static string addStudent(Student s);

        static string updateStudent(Student s);

        static string deleteStudent(Student s);

        static void displayAllStudents();

        static void displayStudentWithId(string id);

        static void printStudentMarks();

        string getStudentId();

        void setStudentId(string studentId);
};

#endif 