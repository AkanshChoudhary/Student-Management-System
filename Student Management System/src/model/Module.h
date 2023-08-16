#ifndef MODULE_H
#define MODULE_H

#include<iostream>
#include<unordered_map>

using namespace std;
class Module{

    string moduleId;
    string moduleName;
    string durationInMonths;
    int fees;
    string tentativeStartDate;   
    

    public: 
    static unordered_map<string,Module> allModules;
    Module(){}
    Module(string moduleId,string moduleName,int durationInMonths,int fees,string tentativeStartDate){
        this->moduleId = moduleId;
        this->moduleName = moduleName;
        this->durationInMonths = durationInMonths;
        this->fees = fees;
        this->tentativeStartDate = tentativeStartDate;
    }
    static void displayModuleWithId(string id);
    static string addModule(Module m);
    static void displayModule(Module m);
    static void displayAllModules();
    static string updateModule(Module m);
    static string deleteModule(Module m);
    string getModuleId();
};

#endif