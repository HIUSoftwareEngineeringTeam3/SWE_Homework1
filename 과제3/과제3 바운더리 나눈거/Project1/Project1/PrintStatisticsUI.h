#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberCollection;

class PrintStatistics;
class PrintStatisticsUI {
private:
	PrintStatistics* control;
	ofstream* out_fp;
	ifstream* in_fp;
public:
	PrintStatisticsUI(ofstream* outfp, ifstream* infp, PrintStatistics* controlClass);
	void printStatisticsButton();
	void startInterface();
	void loginFailed();
	void printStatisticsFailed();
	void printStatisticsSuccess(string productName, int price, float averageSatisfaction);
	void endOfLine();


};