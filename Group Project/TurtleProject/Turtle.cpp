#include <math.h>

class Point{
    float x;
    float y;

    public:

        Point(){}

        Point(float x, float y){
            this->x = x;
            this->y = y;
        }

        void setX(float xVal){
            this->x = xVal;
        }
        void setY(float yVal){
            this->y = yVal;
        }
        float getX(){
            return x;
        }

        float getY(){
            return y;
        }
};


class Turtle{

    private:
        Point location;
        int speed;
        int angle;

    public:

        Turtle(float x, float y, int s, int a){
            location.setX(x);
            location.setY(y);
            speed = s;
            angle = a;
        }

        void move(){
            location.setX(location.getX() + (speed * cos(angle * M_PI / 180)));
            location.setY(location.getY() + (speed * sin(angle * M_PI / 180)));
        }

        Point currentLocation(){
            return location;
        }

};

class Fiskiye{

    private:
        Point center;
        int radius;
        int percent; //Baktığı açı
        int startAngle;

    public:

        Fiskiye(float x , float y, int r, int p, int sA){
            center.setX(x);
            center.setY(y);
            this->radius = r;
            this->percent = p;
            this->startAngle = sA;
        }

        int getRadius(){
            return radius;
        }

        float getPercent(){
            return percent;
        }

        float getStartAngle(){
            return startAngle;
        }

        void move(){
            startAngle += percent;
            startAngle = (startAngle % 360);
        }

};