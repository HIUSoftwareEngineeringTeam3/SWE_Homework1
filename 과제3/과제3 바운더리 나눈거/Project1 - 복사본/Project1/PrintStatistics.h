#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberCollection;

class PrintStatisticsUI;
class PrintStatistics {
private:
	PrintStatisticsUI* boundary;
	MemberCollection* memberCollection;

public:
	PrintStatistics(ofstream* outfp, ifstream* infp, MemberCollection* memList);
	void showStatistics();
	PrintStatisticsUI* getBoundary();



};