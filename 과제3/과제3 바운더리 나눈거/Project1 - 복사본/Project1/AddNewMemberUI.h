#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberCollection;
class AddNewMember;



class AddNewMemberUI {
private:
	AddNewMember* control;
	ofstream* out_fp;
	ifstream* in_fp;
	string name, ssn, id, pwd;
public:
	AddNewMemberUI(ofstream* outfp, ifstream* infp, AddNewMember* controlClass);
	void startInterface();
	void inputInformation();
	void addMemberSuccess(string name, string ssn, string id, string pwd);
	void memberCheckFailPrint();
	



};