#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberCollection;

class LogOutMemberUI;
class LogOutMember {
private:
	LogOutMemberUI* boundary;
	MemberCollection* memberCollection;

public:
	LogOutMember(ofstream* outfp, ifstream* infp, MemberCollection* memList);
	LogOutMemberUI* getBoundary();
	void checkLogoutMember();
	void memberLogout();



};