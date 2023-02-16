#include "StudentList.h"

using namespace std;

int main() {

	string response;
	char rangeBegin;
	char rangeEnd;
	cout << "Please enter the filepath for a tab- or comma- separated file of student data: ";
	cin >> response;

	cout << "Please enter the letter which your caseload begins with. If you manage the entire student list, type A: ";
	cin >> rangeBegin;

	cout << "Please enter the letter which your caseload ends with. If you manage the entire student list, type Z: ";
	cin >> rangeEnd;

	StudentList MySL;
	MySL.buildStudentList(response, rangeBegin, rangeEnd);

	MySL.printStudentList();

	MySL.setColumnHeaders();


}