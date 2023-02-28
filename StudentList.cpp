#include "StudentList.h"

using namespace std;

void StudentList::buildStudentList(string filepath) 
{

	//declare variables to be used locally in class
	ifstream inputstream;
	string tmpstring;
	vector <string> tmpvec;
	

	/*conditional to check for txt file, which is currently the only usable filetype

	string fileExtension;

	for (string::reverse_iterator ritr = filepath.rbegin(); *ritr != '.'; ritr++)
	{
		fileExtension.push_back(*ritr);
	}


	if (fileExtension != "txt") {
		char createCopy;
		cout << "Filepath indicates a non-txt file. A txt file copy will be created on your file. Type Y to create a file copy or N to stop the program: ";
		cin >> createCopy; 

		if (createCopy == 'Y' || createCopy == 'y')
		{
			ofstream outputstream;
			inputstream.open(filepath);

			//create name of new file
			int i = filepath.find_last_of('.');
			
			for (int j = -1; j != '.'; j--)
			{
				filepath.pop_back();
			}

			string outputfp = filepath.insert(i, "COPY.txt");
			cout << "New file name is: " << outputfp << endl;
			
			outputstream.open(outputfp);

			string line;
			while (getline(inputstream, line))
			{
				outputstream << line << '\n';
			}


		}
		else
		{
			exit(0);
		}
	}
	*/
	try 
	{
		inputstream.open(filepath);
	}
	catch (...)
	{
		cout << "There was an error while attempting to open the file. This can be due to \nthe input stream being occupied. Would you like to clear the input stream?\n";
	}

	//extract from the standard input stream to string filecontents
	if (inputstream.is_open()) {
		cout << "File was opened." << endl;
		while (!inputstream.eof()) { 
			char character = inputstream.get();

			if (character != '\t' && character != ',' && character != '\n')
			{
				tmpstring.push_back(character);
			}
			else if (character == '\t' || character == ',')
			{
				tmpvec.push_back(tmpstring);
				column++;
				tmpstring.clear();
			}
			else if (character == '\n')
			{	
				studentlist.push_back(tmpvec);
				row++;
				column = 1;
				tmpvec.clear();
			}
			
		}
		inputstream.close();
	}


//Print Student List Function

void StudentList::printStudentList() {

	for (auto const & itr : studentlist)
	{
		for (auto const& itr1->itr.begin())
		{
			cout << left << *itr1 << '\t';
		}
		cout << endl;
	}
}


//member function to define column titles manually, probably will call within build list function

void StudentList::setColumnHeaders() {

	int colnum{ 1 };
	string colname{};
	char response;
	map <int, string> tmpcolumns;

	cout << "This function allows you to manually name columns or replace existing column names. Would you like to do this manually?\nType Y to enter column names manually or anything else to cancel: ";
	cin >> response;

	if (response == 'Y' || response == 'y')
	{
		cout << "Please enter column names when prompted, you can type Done to stop entering column titles." << "\n\n";
		getline(cin, colname);

		while (colname != "Done" && colname != "done" && colname != "DONE")
		{
			cout << "Column " << colnum << " Name: ";
			getline(cin, colname);

			if (colname != "Done" && colname != "done" && colname != "DONE")
			{
				tmpcolumns[colnum] = colname;
				colnum++;
			}
		}
	}
	else
	{
		return;
	}

	cout << "Please check if your column names are accurate: " << endl;
	for (auto& itr : tmpcolumns)
	{
		cout << "Column " << itr.first << ": " << itr.second << '\n';
	}

	cout << "Are you columns correctly named? Type Y to accept changes: ";
	char correct;
	cin >> correct;

	if (correct == 'Y' || correct == 'y')
	{
		columnHeaders = tmpcolumns;
	}
	else
	{
		return;
	}
}

