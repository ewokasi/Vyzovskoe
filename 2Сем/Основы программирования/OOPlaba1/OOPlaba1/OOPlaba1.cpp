
#include <iostream>

class radiator
{
public:

    void set(float g, float m, float s);

    float get_gradus();
    float get_minutes();
    float get_seconds();
    float to_radians();
   
private:
    const float pi = 3.14;
    const float rad = pi / 180;
    float gradus;
    float minutes;
    float seconds;

};

void radiator::set(float g, float m, float s) {
    gradus = g;
    minutes = m;
    seconds = s;
}

float radiator:: to_radians()
{
        float angle = gradus + minutes / 60 + seconds / 60 / 60;
        return angle * rad;
}

float radiator::get_gradus()
{
    return gradus;
}

float radiator::get_minutes()
{
    return minutes;
}

float radiator::get_seconds()
{
    return seconds;
}


int main()
{
    system("color f1");
    radiator test;

    float grad = 30;
    float min = 10;
    float sec = 59;

    std::cout << "Input: " << grad << ", " << min << ", " << sec << std::endl;
    test.set(grad, min, sec);

    std::cout << "result: ";
    std::cout << test.to_radians();
}
