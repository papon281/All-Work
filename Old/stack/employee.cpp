#include<string>
#include "employee.h"
 Employee::Employee(string name,int id){
    name=name;
    id=id;
 }
 string Employee::get_name(){
    return name;
 }
 int Employee::get_id(){
    return id;
 }
 string Employee::to_string(){
    string name=get_name();
    id=get_id();
    return tostring(name,id);
 }
