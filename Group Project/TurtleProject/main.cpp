#include <cmath>
#include "Turtle.cpp"
#include <iostream>
#include <list>
#include <thread>
#include <chrono>

using namespace std;
int isTurtleInRange(int radius, int x, int y, float percent,float startAngle){
	float endAngle = 360/percent + startAngle;
	float polarradius = sqrt(x*x+y*y);
	float Angle = atan2(y, x);

	if (Angle>=startAngle && Angle<=endAngle && polarradius<radius)
		return 1;
	else
		return 0;
}

std::list<Turtle> turtleList;
std::list<Fountain> FountainList;

void updateAndPrintTurtlesStatus(std::list<Turtle>& turtleList, std::list<Fountain>& FountainList, float xMin, float xMax, float yMin, float yMax) {
    
    while (!turtleList.empty()) {
        int turtleIndex = 1;  // For holding turtle Indexes


        //Move all fountains before calculating turtle's positions.
        for(auto it = FountainList.begin(); it != FountainList.end(); ++it){
            Fountain &f = *it;
            f.move();
        }

        for (auto it = turtleList.begin(); it != turtleList.end();) {
            Turtle &t = *it;
            t.move();
            Point p = t.currentLocation();

            bool isInAnyFountainRange = false;

            for (Fountain &f : FountainList) {
                if (isTurtleInRange(f.getRadius(), p.getX() - f.getX(), p.getY() - f.getY(), f.getPercent(), f.getStartAngle())) {
                    std::cout << turtleIndex << ". Kaplumbağa (" << p.getX() << ", " << p.getY() << ") konumunda ve (" << f.getX() << ", " << f.getY() << ") konumundaki fıskiye'nin yarıçapı içinde." << std::endl;
                    isInAnyFountainRange = true;
                }
            }

            if(!isInAnyFountainRange) {
                std::cout << turtleIndex << ". Kaplumbağa (" << p.getX() << ", " << p.getY() << ") konumunda ve hiçbir fıskiye'nin yarıçapı içinde değil." << std::endl;
            }

            if (p.getX() < xMin || p.getX() > xMax || p.getY() < yMin || p.getY() > yMax) {
                std::cout << turtleIndex << ". Kaplumbağa (" << p.getX() << ", " << p.getY() << ") konumunda ve sınırların dışında. Kaldırılıyor." << std::endl;
                it = turtleList.erase(it);
            } else {
                ++it;
            }
            turtleIndex++;
            
        }

        cout << "Wait for 100 ms...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); //Wait for 100 ms
        //The time could be calculated by using time interval but this is simple. The program will sleep
        //for other processes.
    }
    cout << "Finished\n";
}


int main() {
    int n, m;
    float speed = 2;
    int radius = 8, x = 3, y = 4;
    float percent = 1, startAngle = 0;

    // Dikdörtgen sınırlarını kullanıcıdan al
    float a, b;
    std::cout << "Dikdörtgenin genişliğini girin (X değeri): ";
    std::cin >> a;
    std::cout << "Dikdörtgenin yüksekliğini girin (Y değeri): ";
    std::cin >> b;

    // Dikdörtgen sınırlarını hesapla
    float xMin = 0;
    float yMin = 0;
    float xMax = a;
    float yMax = b;


    cout << "Enter the number of turtles: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter the speed, x, y and angle values for the turtle: ";
        cin >> speed >> x >> y>> startAngle;
        Turtle t = Turtle(x, y, speed, startAngle);
        turtleList.push_back(t);
    }

    cout << "Enter the number of Fountains: ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        cout << "Enter the x,y and radius for the Fountain: ";
        cin >> x>> y>>radius ;
        Fountain f = Fountain(x, y, radius, 10, 0);
        FountainList.push_back(f);
    }



updateAndPrintTurtlesStatus(turtleList, FountainList, xMin, xMax, yMin, yMax);



    return 0;
}
