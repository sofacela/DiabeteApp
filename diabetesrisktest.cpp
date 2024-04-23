
#include "diabetesrisktest.h"
DiabetesRiskTest::DiabetesRiskTest(const QString& gender, const int& age, const float& bodyMaskIndex, const float& waistCircumference, const bool& isOftenVegFr, const bool& isOftenEx, const bool& takeBlPrMed, const bool& wasHighBlGluc, const bool& hasRelatDiab)
{
    this->gender = gender;
    this->age = age;
    this->bodyMaskIndex = bodyMaskIndex;
    this->waistCircumference = waistCircumference;
    this->isOftenVegFr = isOftenVegFr;
    this->isOftenEx = isOftenEx;
    this->takeBlPrMed = takeBlPrMed;
    this->wasHighBlGluc = wasHighBlGluc;
    this->hasRelatDiab = hasRelatDiab;
    counter = 0;
}

int DiabetesRiskTest::calculateScore(){
    this->counter = 0;
    if (this->age < 45){
        this->counter += 0;
    } else if (this->age < 54){
        this->counter += 2;
    } else if (this->age < 64){
        this->counter += 3;
    } else {
        this->counter += 4;
    }
    if (this->bodyMaskIndex < 25){
        this->counter += 0;
    } else if (this->bodyMaskIndex < 30){
        this->counter += 1;
    } else {
        this->counter += 3;
    }
    if (this->gender == "Man"){
        if (this->waistCircumference < 94){
            this->counter += 0;
        } else if (this->waistCircumference < 102){
            this->counter += 3;
        }else{
            this->counter += 4;
        }
    } else {
        if (this->waistCircumference < 80){
            this->counter += 0;
        } else if (this->waistCircumference < 88){
            this->counter += 3;
        }else{
            this->counter += 4;
        }
    }
    if (this->isOftenVegFr == 1){
        this->counter += 0;
    } else{
        this->counter += 1;
    }
    if (this->isOftenEx == 1){
        this->counter += 0;
    } else{
        this->counter += 2;
    }
    if (this->takeBlPrMed == 0){
        this->counter += 0;
    } else{
        this->counter += 2;
    }
    if (this->wasHighBlGluc == 0){
        this->counter += 0;
    } else{
        this->counter += 5;
    }
    if (this->hasRelatDiab == 0){
        this->counter += 0;
    }if (this->hasRelatDiab == 1){
        this->counter += 3;
    }else{
        this->counter += 5;
    }
    return this->counter;
}

QString DiabetesRiskTest::isRiskMessage(){
    QString labelTmp = "";
    if (this->counter < 12){
        labelTmp = "You are in good health and should continue to lead a healthy lifestyle.";
    } else if (this->counter < 14){
        labelTmp = "Maybe you have prediabetes. You should consult with your doctor about how you should change your lifestyle.";

    } else if (this->counter < 20){
        labelTmp = "You may have prediabetes or type 2 diabetes. You might want to check your blood glucose (sugar) levels. You need to change your lifestyle. You may also need medication to lower your blood glucose (sugar) levels.";

    } else{
        labelTmp = "You most likely have type 2 diabetes. You should check the level of glucose (sugar) in the blood and try to normalize it. You will need to change your lifestyle and will also need medication to control your blood glucose (sugar) levels.";
    }
    return labelTmp;
}
