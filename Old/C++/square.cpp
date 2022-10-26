#include<iostream>
using namespace std;
//Class Square
class Square{
    protected:
        double side=1.0;//Initialize the side of square
    public:
        //Method for calculate the area of square
        double calcVal(void){
            //return value
            return side*side;
        }
};
//Class cube derived Class square
class Cube: public Square{
    public:
        //Access the protected member value of square
        void getSide(double num){
            //Get the value side
            side=num;
        }
        //Method for get square area
        double square_area(){
            return Square::calcVal();
        }
        //Method for calculate the volume of cube
        double calcVal(void){
            return side*Square::calcVal();
        }
};
int main(){
    //Create cube object
    Cube cube;
    double num;
    //Input the value of side
    cin>>num;
    //Set the value of side
    cube.getSide(num);
    //call the method to get square area using cube class constructor and print
    cout<<"Area of square is "<<cube.square_area()<<endl;
     //call the method to get cube value using cube class constructor and print
    cout<<"Volume of cube is "<<cube.calcVal()<<endl;
    return 0;
}
