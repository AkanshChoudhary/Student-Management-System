#include<iostream>
#include<vector>
#include<unordered_map>
#include "../model/Module.h"


unordered_map<string,Module> Module::allModules;

string Module::addModule(Module m){
    if(m.getModuleId().length()==4){
         Module::allModules[m.getModuleId()]=m;
         return "Success";
    }
    return "Module ID Error" ;
}


void Module::displayModuleWithId(string id){
    Module::displayModule(Module::allModules[id]);
}
void Module::displayModule(Module m){
    cout<<"\nModuleId: "<<m.moduleId<<" Module Name: "<<m.moduleName<<" Duration In Months: "<<m.durationInMonths<<" Fees: "<<m.fees<<" Tentative Date: "<<m.tentativeStartDate;
}

void Module::displayAllModules(){
    for(auto m : Module::allModules){
        displayModule(m.second);
    }
}

string Module::updateModule(Module m){
    if(m.getModuleId().length()==4 && (Module::allModules.find(m.getModuleId())!=Module::allModules.end())){
         Module::allModules[m.getModuleId()]=m;
         return "Success";
    }
    return "Module ID Error" ;
}

string Module::deleteModule(Module m){
    if(Module::allModules.find(m.getModuleId())!=Module::allModules.end()){
        Module::allModules.erase(m.getModuleId());
        return "Success";
    }
    return "ID does not exist Error";
  
}

string Module::getModuleId(){
    return this->moduleId;
}