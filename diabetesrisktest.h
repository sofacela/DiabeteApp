
#ifndef DIABETESRISKTEST_H
#define DIABETESRISKTEST_H


#include <QLabel>
#include <QMessageBox>

class DiabetesRiskTest
{
public:
    DiabetesRiskTest(const QString& gender, const int& age, const float& bodyMaskIndex, const float& waistCircumference, const bool& isOftenVegFr, const bool& isOftenEx, const bool& takeBlPrMed, const bool& wasHighBlGluc, const bool& hasRelatDiab);
    int calculateScore();
    QString isRiskMessage();
private:
    QString gender;
    int age;
    float bodyMaskIndex;
    float waistCircumference;
    bool isOftenVegFr;
    bool isOftenEx;
    bool takeBlPrMed;
    bool wasHighBlGluc;
    int hasRelatDiab;
    int counter;
};

#endif // DIABETESRISKTEST_H
