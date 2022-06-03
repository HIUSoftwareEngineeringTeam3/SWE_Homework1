#include "RemoveMember.h"
#include "RemoveMemberUI.h"
#include "MemberCollection.h"

RemoveMember::RemoveMember(ofstream* outfp, ifstream* infp, MemberCollection* memList) {
	boundary = new RemoveMemberUI(outfp, infp, this);
	memberCollection = memList;
	boundary->startInterface();
	
}

RemoveMemberUI* RemoveMember::getBoundary() {
	return boundary;
}


void RemoveMember::removeMember() {
	if (memberCollection->checkNowLoginMember() == false) {
		boundary->removeMemberFail();
	}
	else {
		boundary->removeMemberSuccess(memberCollection->getNowLoginMember());
		memberCollection->removeMember();
	}

}