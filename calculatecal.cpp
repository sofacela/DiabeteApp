
#include "calculatecal.h"

CalculateCal::CalculateCal(const int& age, const QString& gender, const float& weight, const float& height, const float& activity)
{
    this->age = age;
    this->gender = gender;
    this->weight = weight;
    this->height = height;
    this->activity = activity;
}

float CalculateCal::getCaloriesMifflin()
{
    if (gender == "Male"){
        return (10 * weight + 6.25 * height - 5 * age + 5) * activity;
    } else {
        return (10 * weight + 6.25 * height - 5 * age - 161) * activity;
    }
}

float CalculateCal::getCaloriesHarris()
{
    if (gender == "Male"){
        return 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age);
    } else {
        return 447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age);
    }
}

float CalculateCal::convertTokJ(const float& kcal)
{
    return kcal * 4.184;
}

