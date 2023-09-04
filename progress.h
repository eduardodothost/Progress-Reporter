/*! \file progress.h
	\brief Contains the progress class that handles intake, serialization, and visualization of our data.

	Details.
*/
#pragma once
#ifndef PROGRESS_H
#define PROGRESS_H
#include <iostream>	
#include <unordered_map>	
#include <string>	
#include <windows.h>
#include <exception>
#include <fstream>
//!  Backend for report. 
/*!
  The progress class parses the data that we are working with and helps us visualize it, 
  acting as the backend to the report class
*/
class progress
{

public:
	//! Serializer.
		 /*! Creates an ofstream to save our histogram to disk in a .dat file*/
	void backup_pair();
	//! Saves our data in the form of a frequency table,
	//!  using an unordered map to store word and frequency pairs.
	void check_inventory();
	//! Search function.
		 /*! */
	void lookup();
	//! print function.
		 /*! visualizes our data as it has been set in our unordered map*/
	void printList();
	//! print chart function.
		 /*! Displays a bar chart that shows a green bar for oversold items and
		 red for undersold items. Needs work to adjust bar length to account for larger
		 numbers.*/
	void printChart();
	//! bar chart switch.
		 /*! level() is used to determine wether to use a green or red colored bar.*/
	void level(int& r_span);
	//! resets the console color when not producing a bar.
		 /*! Used after applying level() to be able to switch between writing to the
		 console and writing a bar.*/
	void resetConsole();
private:
	HANDLE  mhConsole;
	const int mRED = 42;
	const int mGREEN = 76;
	const int def = 15;
	std::unordered_map<std::string, int> mItems;
	//! used in level as a green chart
	void overstocked(int& r_span);
	//! red histogram used in level
	void understocked(int& r_span);
	void test();
	bool matchKey(std::string r_str);
	
	
};
#endif