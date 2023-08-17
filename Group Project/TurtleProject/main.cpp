#include<bits/stdc++.h>
#include "Turtle.cpp"

using namespace std;

int isTurtleDead(int x, int y, int turtleX, int turtleY){
    return (turtleX <= 0 || turtleX >= x) || (turtleY <= 0 || turtleY >= y) ? 1 : 0;
}

int isTurtleInRange(int radius, int x, int y, float percent,float startAngle){
	float endAngle = 360/percent + startAngle;
	float polarradius = sqrt(x*x+y*y);
	float Angle = atan(y/x);

	if (Angle>=startAngle && Angle<=endAngle && polarradius<radius)
		return 1;
	else
		return 0;
}

void printLog(char * str, std::ofstream& file){
    //Burada file'a yazı yazdır.
}

//turtleList, fiskiyeList, alan boyutu
void startGame(){
    while(!turtleList.empty()){

        for(int i = 0; i < turtleList.size(); i++){
            turtleList[i].move(); //[] kullanımı yok iterator lazım
            
            //Turtle alan disina cikti mi kontrolü
            if(isTurtleDead(x,y,turtleList[i].getX(), turtleList[i].getY())){
                //O zaman log gir
                printLog();
            }
            

            //Fıskiye foru döndür, onun bilgilerini alıp isTurtleInRange çağır

        }

    }
}

void init(){

    //alan boyutu ne olacak?
    //Kaç kaplumbağa
    //Kaç Fıskiye
    //kullanıcıdan veri al ve listleri öyle oluştur. Alan dışında bi veri girilirse izin verme


    std::list<Turtle> turtleList;
    std::list<Fiskiye> fiskiyeList;

    // Creating Turtle instances and adding them to the list
    Turtle turtle1(0, 0, 2, 45);
    Turtle turtle2(10, 5, 3, 60);
    Turtle turtle3(1, 1, 1, 30);

    turtleList.push_back(turtle1);
    turtleList.push_back(turtle2);
    turtleList.push_back(turtle3);

    Fiskiye fiskiye1(0,0,3,10,0);
    Fiskiye fiskiye2(5,10,3,10,0);
    Fiskiye fiskiye3(8,12,3,10,0);

    fiskiyeList.push_back(fiskiye1);
    fiskiyeList.push_back(fiskiye2);
    fiskiyeList.push_back(fiskiye3);




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
	init();
    return 0;
}
