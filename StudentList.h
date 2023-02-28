#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <iomanip>


class StudentList {
public:

	void buildStudentList(std::string, char, char);
	void printStudentList();


private:

	std::vector <std::vector <std::string> > studentlist;


};