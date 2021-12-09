#ifndef DATA_MODEL_H
#define DATA_MODEL_H


struct Value
{
    float min;
    float max;
    float value;
};


struct BrowConfig
{
    Value angle;
    Value thickness;
};


struct EyeConfig
{
    Value pupilRadius;
    BrowConfig topBrow;
    BrowConfig bottomBrow;
};


struct FaceConfig
{
    EyeConfig leftEye;
    EyeConfig rightEye;
};


#endif // DATA_MODEL_H
