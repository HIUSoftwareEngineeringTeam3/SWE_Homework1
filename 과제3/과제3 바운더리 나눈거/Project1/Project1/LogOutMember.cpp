#include "LogOutMember.h"
#include "LogOutMemberUI.h"
#include "Member.h"
#include "MemberCollection.h"
#include "ProductCollection.h"


LogOutMember::LogOutMember(ofstream* outfp, ifstream* infp, MemberCollection* memList) {
	boundary = new LogOutMemberUI(outfp, infp, this);
	memberCollection = memList;
	boundary->startInterface();
}
void LogOutMember::checkLogoutMember() {
	if (memberCollection->checkNowLoginMember()==true) {
		memberLogout();
	}
	else {
		boundary->logOutMemberFail();
	}
}
void LogOutMember::memberLogout() {
	boundary->logOutMemberSuccess(memberCollection->getNowLoginMember()->getMemberID());
	memberCollection->logOutMember();
}

LogOutMemberUI* LogOutMember::getBoundary() {
	return boundary;
}