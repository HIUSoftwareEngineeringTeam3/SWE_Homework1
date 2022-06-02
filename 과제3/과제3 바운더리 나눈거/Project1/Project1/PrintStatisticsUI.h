#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberList;

class PrintStatistics;
class PrintStatisticsUI {
private:
	PrintStatistics* control;
	ofstream* out_fp;
	ifstream* in_fp;
public:
	PrintStatisticsUI(ofstream* outfp, ifstream* infp);
	void startInterface();
	void loginFailed();
	void inquirySoldOutProductFailed();
	void inquirySoldOutProductSuccess(string productName, string companyName, int price, int quantity, float averageSatisfaction);
	void endOfLine();


};