#ifndef CH_TWODAYPACKAGE_H
#define CH_TWODATPACKAGE_H
#include"CH_Package.h"
#include <iostream>
using namespace std;
class TwoDayPackage : public Package
{
public:
	TwoDayPackage(const char *, const char*,                              //construction
		const char*, const char*, int,
		const char *, const char*,
		const char*, const char*, int, double, double, double);
	~TwoDayPackage();                                                      //desturction
	virtual double calculateCost()const;                                 //calculate price
	virtual void print()const;                                             //print necessary information
	virtual void printPrice()const;                                        //print unit price
	virtual void setPrice(double);                                        //set price
 	virtual void setFlatFee_Ounce(double);                                //set flat fee
	virtual double getFlatFee_Ounce()const;                              // get flat fee
private:
	double FlatFee_Ounce;
};
#endif // 
