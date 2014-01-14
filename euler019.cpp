#include <iostream>
#include <vector>

bool IsLeapYear(int year)
{
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int main()
{
	int count = 0;

	std::vector<int> daysinmonth = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int daystr = 1;
	int day = 1;
	int month = 1;
	int year = 1900;

	while (year < 2001) {
		/* Check (previous) valid date */
		if (year > 1900 && daystr == 0 && day == 1) count++;

		/* Increase date */
		day++;
		daystr++;

		/* Make sure it's still valid, adjust if necessary */
		if (daystr > 6) daystr = 0;

		if (day > daysinmonth[month - 1] ||
			(!IsLeapYear(year) && month == 2 && day > 28)) {
			day = 1;
			month++;
		}

		if (month > 12) {
			month = 1;
			year++;
		}
	}
	std::cout << "Number of Sundays: " << count << std::endl;
}