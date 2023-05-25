

#include <iostream>
#include<vector>
#include<math.h>
#include "ConstantCurvForward.h"

using namespace std;

int main()
{
    cout << "enter Tendon Number\n";
    int numberTendons;
    cin >> numberTendons;

    float currAngle;
    float currCurv;
    float currLength;

    vector<float> TendonAngle;
    vector<float> TendonCurv;
    vector<float> TendonLenght;

    for (int i = 0; i < numberTendons; i++) {
        cout << "enter Tendon Angle, Curv for Tendon and Length of Tendon" << i << "\n";
        cin >> currAngle;
        cin >> currCurv;
        cin >> currLength;

        TendonAngle.push_back(currAngle);
        TendonCurv.push_back(currCurv);
        TendonLenght.push_back(currLength);


    }


    float* Position;

    Position = ForwardKin(TendonAngle, TendonCurv, TendonLenght);

    cout << Position[0] << "\n";
    cout << Position[1] << "\n";
    cout << Position[2] << "\n";





}







