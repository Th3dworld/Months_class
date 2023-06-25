//This is the specification file for the months class
#ifndef MONTHS_H
#define MONTHS_H
#include<iostream>
#include<string>
using namespace std;

class Months
{
	//Declare Private attributes 
	private:
		string name;
		int monthNumber;
		string months[12] = { "January", "February", "March", "April", "May", "June", "July",
							 "August", "September", "October", "November", "December" };
	
	//Declare public member functions
	public:
		//Defualt constructor
		Months():Months("January")
		{}

		//Parametized constructor that takes month name as argument
		Months(string nme)
		{
			simplify(nme);
		}

		//Parametized constructor that takes month number as argument
		Months(int monum)
		{
			simplify(monum);
		}

		//Simplify function, overloaded function that will be used more than once made stand alone to reduce code
		void simplify(string nm)
		{
			//Set argument taken as month name
			name = nm;
			//Capitalize first later of month name
			name[0] = toupper(name[0]);
			//Loop through array holding months in order to get month number
			for (int i = 0; i < 12; i++)
			{
				//When month is found assign month number to monthNumber variable
				if (nm == months[i])
					monthNumber = (i + 1);
			}
		}

		void simplify(int monumbr)
		{
			//Assign argument number to month number vriable
			monthNumber = monumbr;
			//Set month name by using month number + 1 as index to the months array
			name = months[monthNumber - 1];
		}




		//Set functions for month name and number
		void set_monthName(string nme)
		{
			simplify(nme);
		}
		void set_monthNumber(int monum)
		{
			simplify(monum);
		}

		//Get functions for month name and number
		string get_monthName()
		{
			return name;
		}
		int get_monthNumber()
		{
			return monthNumber;
		}

		//Overloaded ++ and -- prefix operators
		Months operator++()
		{
			//increment month number
			++monthNumber;
			//Check if month number exceeds possible value
			if(monthNumber > 12)
				//if month number exceeds possible value assign one to it
				monthNumber = 1;
			//Update results
			simplify(monthNumber);
			//Return results
			return *this;
		}

		Months operator--()
		{
			//increment month number
			--monthNumber;
			//Check if month number deceeds possible value
			if (monthNumber < 1)
				//if month number deceeds possible value assign twelve to it
				monthNumber = 12;
			//Update results
			simplify(monthNumber);
			//Return results
			return *this;
		}

		//Overloaded ++ and -- postfix operators
		Months operator++(int)
		{
			//Create temperal object
			Months temp;
			//increment month number
			monthNumber++;
			//Check if month number exceeds possible value
			if (monthNumber > 12)
				//if month number exceeds possible value assign one to it
				monthNumber = 1;
			//Update results
			simplify(monthNumber);
			//Return results
			return temp;
		}

		Months operator--(int)
		{
			//Create temperal object
			Months temp;
			//increment month number
			monthNumber--;
			//Check if month number deceeds possible value
			if (monthNumber < 1)
				//if month number deceeds possible value assign twelve to it
				monthNumber = 12;
			//Update results
			simplify(monthNumber);
			//Return results
			return temp;
		}
	
		//Overloaded >> and << operators
		friend ostream &operator <<(ostream & rtrn, const Months &obj )
		{
			rtrn << "Month number " << obj.monthNumber << " is called " << obj.name << endl;
			return rtrn;
		}

		friend istream& operator >>(istream& rtrn,  Months& obj)
		{
			cout << "Please input month number:";
			rtrn >> obj.monthNumber;
			obj.simplify(obj.monthNumber);
			return rtrn;
		}
};
#endif // !MONTHS_H
