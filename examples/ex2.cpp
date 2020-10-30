#include <iostream>
using namespace std;
typedef enum {Sun = 0, Mon, Tue, Wed, Thu, Fri, Sat} DayType;
class Days {
	private: 
		DayType day;
	public:
		Days() { day = Sun; } // constructor without parameter
		Days(DayType d) { day = d; } // constructor with parameter
		DayType getDay(void) { return day; }
		void setDay(DayType d) { if (d >= Sun && d <= Sat) this->day = d; }
		void display() {
			switch(day) {
				case Sun: cout << "Sun" << endl; break;	
				case Mon: cout << "Mon" << endl; break;
				case Tue: cout << "Tue" << endl; break;
				case Wed: cout << "Wed" << endl; break;
				case Thu: cout << "Thu" << endl; break;
				case Fri: cout << "Fri" << endl; break;
				case Sat: cout << "Sat" << endl; break;
				default: cout << "Incorrect day" << endl;
			}
		}

		// Overload prefix ++ operator to add one to Days object: ++days.
		Days operator++() {
			Days days(day); // Save the original value
			switch (this->day) {
				case Sun: this->day = Mon; break;
				case Mon: this->day = Tue; break;
				case Tue: this->day = Wed; break;
				case Wed: this->day = Thu; break;
				case Thu: this->day = Fri; break;
				case Fri: this->day = Sat; break;
				case Sat: this->day = Sun; break;
				default: cout << "Incorrect day" << endl;
			}
			days.day = this->day;
			return days;
		}	

		// Overload postfix ++ operator to add one to Days object: days++.
		Days operator++(int) {
			Days days(day); // Save the original value
			switch (this->day) {
				case Sun: this->day = Mon; break;
				case Mon: this->day = Tue; break;
				case Tue: this->day = Wed; break;
				case Wed: this->day = Thu; break;
				case Thu: this->day = Fri; break;
				case Fri: this->day = Sat; break;
				case Sat: this->day = Sun; break;
				default: cout << "Incorrect day" << endl;
			} // The value in the this object has been changed
			// days.day = this->day;
			return days; // return the value before it changes.
		}
};

int main() {
	Days day1(Mon), day2, day3;
	day2.setDay(Sat); day3.setDay(Sun);
	cout << "The days before ++ operations" << endl;
	day1.display(); day2.display(); day3.display();
	++day1; ++day2; ++day3;
	cout << "The days after prefix ++ operations" << endl;
	day1.display();
	day2.display();
	day3.display();
	day1++; day2++; day3++;
	cout << "The days after postfix ++ operations" << endl;
	day1.display();
	day2.display();
	day3.display();
	return 0;
}









