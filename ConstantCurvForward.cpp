#include <iostream>
#include<vector>
#include<math.h>
#include "ConstantCurvForward.h"


//forward kinematic using the constant curvature assumption
float* ForwardKin(vector<float> TendonAngle, vector<float> TendonCurv, vector<float> TendonLenght) {

    float PosX = 0;
    float PosY = 0;
    float PosZ = 0;
    float YRotationDegree;
    float ZRotationDegree;


    for (int i = TendonAngle.size() - 1; i > 1; i--) {
        
        //Translation
        if (TendonCurv[i] == 0) {

            PosZ = PosZ + TendonLenght[i];

        }
        else {
            PosX = PosX + (cos(TendonAngle[i]) / TendonCurv[i]) * (1 - cos(TendonCurv[i] * TendonLenght[i]));
            PosY = PosY + (sin(TendonAngle[i]) / TendonCurv[i]) * (1 - cos(TendonCurv[i] * TendonLenght[i]));
            PosZ = PosZ + sin(TendonCurv[i] * TendonLenght[i]) / TendonCurv[i];
        }


        //RotationY

        YRotationDegree = TendonLenght[i - 1] * TendonCurv[i - 1];
        PosX = PosX * cos(YRotationDegree) + PosZ * sin(YRotationDegree);
        PosZ = PosX * -sin(YRotationDegree) + PosZ * cos(YRotationDegree);


        //RotationZ
        
        //ZRotationDegree = TendonAngle[i - 1] + TendonAngle[i - 2];
        ZRotationDegree = TendonAngle[i - 1];
        PosX = PosX * cos(ZRotationDegree) + PosY * -sin(ZRotationDegree);
        PosY = PosX * sin(ZRotationDegree) + PosY * cos(ZRotationDegree);

    }

    //Last 2 Translations and Rotations

    if (TendonAngle.size() > 1) {
        cout << " second last\n";
        if (TendonCurv[1] == 0) {

            PosZ = PosZ + TendonLenght[1];

        }
        else {

            PosX = PosX + (cos(TendonAngle[1]) / TendonCurv[1]) * (1 - cos(TendonCurv[1] * TendonLenght[1]));
            PosY = PosY + (sin(TendonAngle[1]) / TendonCurv[1]) * (1 - cos(TendonCurv[1] * TendonLenght[1]));
            PosZ = PosZ + sin(TendonCurv[1] * TendonLenght[1]) / TendonCurv[1];

        }


        YRotationDegree = TendonLenght[0] * TendonCurv[0];
        PosX = PosX * cos(YRotationDegree) + PosZ * sin(YRotationDegree);
        PosZ = PosX * -sin(YRotationDegree) + PosZ * cos(YRotationDegree);

        ZRotationDegree = TendonAngle[0];
        PosX = PosX * cos(ZRotationDegree) + PosY * -sin(ZRotationDegree);
        PosY = PosX * sin(ZRotationDegree) + PosY * cos(ZRotationDegree);

    }
    cout << " last tendon\n";
    if (TendonCurv[0] == 0) {

        PosZ = PosZ + TendonLenght[0];

    }
    else {

        PosX = PosX + (cos(TendonAngle[0]) / TendonCurv[0]) * (1 - cos(TendonCurv[0] * TendonLenght[0]));
        PosY = PosY + (sin(TendonAngle[0]) / TendonCurv[0]) * (1 - cos(TendonCurv[0] * TendonLenght[0]));
        PosZ = PosZ + sin(TendonCurv[0] * TendonLenght[0]) / TendonCurv[0];

    }

    static float Position[3];
    Position[0] = PosX;
    Position[1] = PosY;
    Position[2] = PosZ;

    return Position;
}
