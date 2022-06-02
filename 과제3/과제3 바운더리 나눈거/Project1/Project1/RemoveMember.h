#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Member;
class MemberList;

class RemoveMemberUI;
class RemoveMember {
private:
	RemoveMemberUI* boundary;
	MemberList* memberList;

public:
	RemoveMember(ofstream* outfp, ifstream* infp, MemberList* memList);
	RemoveMemberUI* getBoundary();
	void removeMember();


};