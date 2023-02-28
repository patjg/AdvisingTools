#include "StudentList.h"

using namespace std;

int main() {

	string response;
	cout << "Please enter the filepath for a tab- or comma- separated file of student data: ";
	cin >> response;

	StudentList MySL;
	MySL.buildStudentList(response);

	MySL.printStudentList();
}