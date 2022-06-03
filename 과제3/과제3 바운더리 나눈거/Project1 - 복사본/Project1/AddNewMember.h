#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberCollection;
class AddNewMemberUI;


class AddNewMember {
private:
	AddNewMemberUI* boundary;
	MemberCollection* memberCollection;
	string memberName, memberSsn, memberID, memberPWD;
	bool checkMemberID(string name, string ssn, string id, string pwd);
public:
	AddNewMember(ofstream* outfp, ifstream* infp,MemberCollection* memList);
	AddNewMemberUI* getBoundary();
	void addNewMember(string name, string ssn, string id, string pwd);
	
};