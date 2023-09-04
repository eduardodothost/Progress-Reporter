/*! \file report.h
	\brief Front end to the progress class

   progress.h is used in this class to collect user data and display and generate reports.
    

*/
#pragma once
#ifndef REPORT_H
#define REPORT_H
#include "progress.h"

//!  Our application will enter a while loop within itemReconciliation. 
/*!
  The report class manages our display and input capabilities using itemReconciliation as
   the application endpoint in main.cpp.
*/

class report
{

public:
		//! While Loop.
		 /*! application endpoint that loops using working, workingState, 
		 and workingChoice. We place working as the condition for our loop, and call workingChoice
		 to display and collect the user prompt and input to be used in workingState 
		 with respect to the progress object we use as a parameter*/
	void itemReconciliation();
private:

	//! we control our menu navigation using comtinue_state
	bool continue_state = true;
	std::string choice;
	//!menu flow control
	bool working();
	//! Displays User Menu
	void workingChoice();
	//!calls the appropriate function in progress.cpp based on user input
	void workingState(progress report);
	
};
#endif