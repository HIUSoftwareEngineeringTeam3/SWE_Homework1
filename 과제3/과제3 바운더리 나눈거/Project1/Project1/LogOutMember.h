#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberList;

class LogOutMemberUI;
class LogOutMember {
private:
	LogOutMemberUI* boundary;
	MemberList* memberList;

public:
	LogOutMember(ofstream* outfp, ifstream* infp, MemberList* memList);
	LogOutMemberUI* getBoundary();
	void checkLogoutMember();
	void memberLogout();



};