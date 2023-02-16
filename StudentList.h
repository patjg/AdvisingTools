#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <iomanip>


class StudentList {
public:

	void buildStudentList(std::string, char, char);
	void printStudentList();
	void setColumnHeaders();


private:

	std::map <int, std::map <int, std::string> > studentlist;
	std::map <int, std::string> columnHeaders;

};