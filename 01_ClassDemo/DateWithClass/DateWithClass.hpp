#ifndef  _DATE_HPP
#define  _DATE_HPP

class Date
{
private:
	///Date layout
	int day;
	int month;
	int year;

public:
	///Default constructor
	Date();

	///Parametorized Constroctor
	Date(int init_day, int init_month, int init_year);


	///Getter
	int get_day() const; 
	int get_month() const; 
	int get_year() const; 

	///Setter
	void set_day(int new_day);
	void set_month(int new_month);
	void set_year(int new_year);

	///Representation of standard output device
	void show() const;
};

#endif _DATE_HPP// ! _DATE_HPP







