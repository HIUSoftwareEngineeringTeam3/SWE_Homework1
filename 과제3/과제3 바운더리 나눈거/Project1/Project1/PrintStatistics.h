#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberList;

class PrintStatisticsUI;
class PrintStatistics {
private:
	PrintStatisticsUI* boundary;
	MemberList* memberList;

public:
	PrintStatistics(ofstream* outfp, ifstream* infp, MemberList* memList);
	void showStatistics();
	PrintStatisticsUI* getBoundary();



};