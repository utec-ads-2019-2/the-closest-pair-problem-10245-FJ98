#include <bits/stdc++.h>

double distanceD(std::vector< std::pair<double,double> >);

int main(){
    std::pair<double, double> points;
    std::vector< std::pair<double,double> > pointsVector;
    int input = 0;
    while (std::cin >> input, input != 0) {
        double minDistance = 0;
        double xCoordinate = 0, yCoordinate = 0;

        for (int i = 0; i < input; ++i) {
            std::cin >> xCoordinate >> yCoordinate;

            points.first = xCoordinate;
            points.second = yCoordinate;
            pointsVector.push_back(points);

            std::sort(pointsVector.begin(), pointsVector.end());

        }
        minDistance = distanceD(pointsVector);

        if (minDistance < 10000) {
            std::cout << minDistance << std::endl;
        } else{
            std::cout << "INFINITY" << std::endl;
        }
        pointsVector.clear();

    }

    return 0;
}

double distanceD(std::vector< std::pair<double,double> > pointsVector){
    std::vector<double> distances;
    double distance = 0, minDistance = 0;

    for (int i = 1; i < pointsVector.size(); ++i) {
        distance = std::sqrt( std::pow(pointsVector[i].first - pointsVector[i-1].first, 2)
                              + std::pow(pointsVector[i].second - pointsVector[i - 1].second , 2) );

        distances.push_back(distance);

    }
    minDistance = *std::min_element(distances.begin(), distances.end());

    return minDistance;
}
