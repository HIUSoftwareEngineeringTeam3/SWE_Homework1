#include "LogOutMember.h"
#include "LogOutMemberUI.h"
#include "Member.h"
#include "MemberList.h"


LogOutMember::LogOutMember(ofstream* outfp, ifstream* infp, MemberList* memList) {
	boundary = new LogOutMemberUI(outfp, infp, this);
	memberList = memList;
	boundary->startInterface();
}
void LogOutMember::checkLogoutMember() {
	if (memberList->checkNowLoginMember()==true) {
		memberLogout();
	}
	else {
		boundary->logOutMemberFail();
	}
}
void LogOutMember::memberLogout() {
	boundary->logOutMemberSuccess(memberList->getNowLoginMember()->getMemberID());
	memberList->logOutMember();
}

LogOutMemberUI* LogOutMember::getBoundary() {
	return boundary;
}