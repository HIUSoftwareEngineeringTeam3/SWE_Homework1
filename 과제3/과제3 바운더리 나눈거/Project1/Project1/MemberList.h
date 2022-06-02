#pragma once
#include <vector>
using namespace std;

class Member;
class MemberList {
private:
	vector<Member*> memberVector;
	Member* nowLoginMember;
public:
	void addNewMember(Member* member);
	vector<Member*>* getMemberVector();
	bool checkNowLoginMember();
	Member* getNowLoginMember();
	void loginMember(string id, string pwd);
	void removeMember();
	void logOutMember();
	int checkValidID_PW(string id, string pwd);
};