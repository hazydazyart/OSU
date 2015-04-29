
#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include<string>
#include "employee.h"

class HourlyEmployee : public Employee {

public:
	HourlyEmployee();
	HourlyEmployee(const string& theName, const string& theSsn,
				double theWageRate, double theHours);
	void setRate(double newWageRate);
	double getRate() const;
	void setHours(double hoursWorked);
	double getHours() const;
	void printCheck();

protected:
	double wageRate;
	double hours;
};

#endif // HOURLYEMPLOYEE_H
