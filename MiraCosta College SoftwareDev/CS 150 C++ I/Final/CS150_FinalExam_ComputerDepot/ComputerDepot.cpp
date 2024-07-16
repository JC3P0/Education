#include <iostream>
#include <cstdlib>

using namespace std;


int main(int argc, char* argv[])
{
	cout
		<< "*************************************************************************\n"
		<< "**                 Welcome to the Computer Depot                       **\n"
		<< "*************************************************************************\n"
		<< "** Please enter choice :                                               **\n"
		<< "** 1) Add computer to inventory                                        **\n"
		<< "** 2) Display entire inventory                                         **\n"
		<< "** 3) Quit                                                             **\n"
		<< "*************************************************************************\n";


	// Choice 1
	cout << "Enter 1 for Computer or 2 for Laptop >> ";
	cout << "Enter make               >> ";
	cout << "Enter model              >> ";
	cout << "Enter price              >> $";

	cout << "Enter battery life (hrs) >> ";
	cout << "Enter weight (lbs)       >> ";


	// Choice 2
	cout
		<< "*************************************************************************\n"
		<< "**                          Entire Inventory                           **\n"
		<< "*************************************************************************\n"
		<< "| Id # | Make       | Model    | Price  | Battery (hrs) | Weight (lbs)  |\n"
		<< "*************************************************************************\n";



	system("PAUSE");
	return EXIT_SUCCESS;
}
