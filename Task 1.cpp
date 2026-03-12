#include <iostream>
using namespace std;

class shape{
    public:
    virtual float area() = 0;

        
};
class circle: public shape{
    private:
    float radious;

    public:
    circle(float r){
        radious = r;   
    }

    float area(){
        return 3.14 * radious * radious;
    }
};
class rectangle: public shape{
    private:
    float lenght;
    float width;
    
    public:
    rectangle(float l , float w){
        lenght = l;
        width = w;
    }
    float area(){
        return lenght * width;
    }
};
int main(){
    circle c(5);

    rectangle r(4, 6);

    cout << "Area of circle " << c.area() << endl;
    cout << "Area of rectangle " << r.area() << endl;

    return 0;
}
