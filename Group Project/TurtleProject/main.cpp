#include<bits/stdc++.h>
#include "Turtle.cpp"

using namespace std;


void checkPoint(int radius, int x, int y, float percent,
										float startAngle)
{
	// calculate endAngle
	float endAngle = 360/percent + startAngle;

	// Calculate polar co-ordinates
	float polarradius = sqrt(x*x+y*y);
	float Angle = atan(y/x);

	// Check whether polarradius is less then radius of circle
	// or not and Angle is between startAngle and endAngle
	// or not
	if (Angle>=startAngle && Angle<=endAngle && polarradius<radius)
		printf("Point (%d, %d) exist in the circle sector\n", x, y);
	else
		printf("Point (%d, %d) does not exist in the circle sector\n",
															x, y);
}

void init(){

    std::list<Turtle> turtleList;

    // Creating Turtle instances and adding them to the list
    Turtle turtle1(0, 0, 2, 45);
    Turtle turtle2(10, 5, 3, 60);
    Turtle turtle3(1, 1, 1, 30);

    turtleList.push_back(turtle1);
    turtleList.push_back(turtle2);
    turtleList.push_back(turtle3);

    while(!turtleList.empty()){

        for(int i = 0; i < turtleList.size(); i++){
            //turtleList.move();
        }

    }



    Turtle t = Turtle(1,1,1,90);
    t.move();
    Point newPoints = t.currentLocation();
    printf("x: %f, y: %f\n",newPoints.getX(), newPoints.getY());

    Fiskiye f = Fiskiye(0,0,3,10,0);

    checkPoint(f.getRadius(), newPoints.getX(), newPoints.getY(), f.getPercent(), f.getStartAngle());


    //Turtle.move
    //alanıGeçtiMi()Turtle, x,y 
    //Fiskiye.move
    //checkPoint()


}




// Driver code
int main()
{
	int radius = 8, x = 3, y = 4;
	float percent = 12, startAngle = 0;
	//checkPoint(radius, x, y, percent, startAngle);
	init();
    return 0;
}
