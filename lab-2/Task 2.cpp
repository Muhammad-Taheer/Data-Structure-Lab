#include <iostream>
using namespace std;

class employe{
    public:
    virtual float calculatesalary() = 0;

};
class fullemployetime : public employe{
    private:
    float salary;

    public:
    fullemployetime(float s){
        salary = s;
    }
    float  calculatesalary(){
        return salary;
    }
};
class partemployetime : public employe{
    private:
    float hours;
    float rate;

    public:
    partemployetime(float h, float r){
        hours = h;
        rate = r;
    }
    float calcuatesalary(){
        return hours * rate;
    }
};
int main(){
    fullemployetime emp1(500);
    partemployetime emp2(20, 500);

    cout << "Full Time Employee Salary: " << emp1.calculatesalary() << endl;
    cout << "Part Time Employee Salary: " << emp2.calculatesalary() << endl;

    return 0;

}
