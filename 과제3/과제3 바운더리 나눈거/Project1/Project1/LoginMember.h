#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberList;

class LoginMemberUI;
class LoginMember {
private:
	LoginMemberUI* boundary;
	MemberList* memberList;
public:
	LoginMember(ofstream* outfp, ifstream* infp, MemberList* memList);
	LoginMemberUI* getBoundary();
	void checkID_PW(string id, string pwd);

};