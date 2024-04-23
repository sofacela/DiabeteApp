
#ifndef CALCULATECAL_H
#define CALCULATECAL_H

#include <QString>


class CalculateCal
{
public:
    CalculateCal(const int& age, const QString& gender, const float& weight, const float& height, const float& activity);
    float getCaloriesMifflin();
    float getCaloriesHarris();
    float convertTokJ(const float& kcal);
private:
    int age;
    QString gender;
    float weight;
    float height;
    float activity;

};

#endif // CALCULATECAL_H
