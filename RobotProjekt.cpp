

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
    
    if (numberTendons < 1) {
        cout << "0 CordX\n";
        cout << "0 CordY\n";
        cout << "0 CordZ\n";
        return 0;
    }

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

    cout << Position[0] << "XCord\n";
    cout << Position[1] << "YCord\n";
    cout << Position[2] << "ZCord\n";





}







