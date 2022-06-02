#include "RemoveMember.h"
#include "RemoveMemberUI.h"
#include "MemberList.h"

RemoveMember::RemoveMember(ofstream* outfp, ifstream* infp, MemberList* memList) {
	boundary = new RemoveMemberUI(outfp, infp);
	memberList = memList;
	boundary->startInterface();
	
}

RemoveMemberUI* RemoveMember::getBoundary() {
	return boundary;
}


void RemoveMember::removeMember() {
	if (memberList->checkNowLoginMember() == false) {
		boundary->removeMemberFail();
	}
	else {
		boundary->removeMemberSuccess(memberList->getNowLoginMember());
		memberList->removeMember();
	}

}