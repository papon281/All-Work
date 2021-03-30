#ifndef __EMPLOYEE__
#define __EMPLOYEE__
class Employee{
    std::string name; // name of the employee
    int id; // id of the employee
    public:
        Employee(); // empty constructor
        Employee(std::string _name,int _id); // parameterized constructor
        std::string getName(); // getters for name
        int getId(); // getter for id
        std::string toString(); // toString() method
};

Employee::Employee(){ }

Employee::Employee(std::string _name,int _id){
    name = _name;
    id = _id;
 }
 
std::string Employee::getName(){
    return name;
}
int Employee::getId(){
    return id;
}
std::string Employee::toString(){
    return  name +" " + std::to_string(id);
}
#endif //__EMPLOYEE__
