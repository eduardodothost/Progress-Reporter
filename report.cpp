// read from CS210_Project_Three_Input_File.txt
#include "report.h"

bool report::working() {
	return report::continue_state;
};

void report::workingState(progress r_report) {
	if (choice.compare("4") == 0) {
		report::continue_state = false;
	} else if (choice.compare("3") == 0) {
		r_report.printChart();
	} else if (choice.compare("2") == 0) {
		r_report.printList();
	} else if (choice.compare("1") == 0) {
		r_report.lookup();
	}
};

void report::workingChoice() {

	std::cout << std::endl << "Inventory Report Options";
	std::cout << std::endl << "1. Search List";
	std::cout << std::endl << "2. Print List";
	std::cout << std::endl << "3. Print Chart";
	std::cout << std::endl << "4. Exit";
	std::cout << std::endl;
	std::cin >> report::choice;
};

void report::itemReconciliation() {
	progress report;
	report.check_inventory();
	report.backup_pair();
	while (working()) {
		workingChoice();
		workingState(report);
	}

};


