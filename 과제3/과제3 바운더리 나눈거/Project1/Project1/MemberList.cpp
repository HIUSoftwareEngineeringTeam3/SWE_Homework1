#include "MemberList.h"
#include "Member.h";

vector<Member*>* MemberList::getMemberVector() {
	return &memberVector;
}

void MemberList::addNewMember(Member* member) {
	memberVector.push_back(member);
}

bool MemberList::checkNowLoginMember() {
	if (nowLoginMember == nullptr) {
		return false;
	}
	else {
		return true;
	}
}

void MemberList::loginMember(string id, string pwd) {
	Member* member;

	for (int i = 0; i < memberVector.size(); i++)
	{
		if (id == memberVector[i]->getMemberID())
		{
			if (pwd == memberVector[i]->getMemberPWD())
			{
				nowLoginMember = memberVector[i];
				//cout << id << " " << pwd << "\n\n";
				return;
			}
		}
	}
}

Member* MemberList::getNowLoginMember() {
	return nowLoginMember;
}

void MemberList::removeMember() {
	auto secessionMember = find(memberVector.begin(), memberVector.end(), nowLoginMember);
	if (secessionMember != memberVector.end())
	{
		memberVector.erase(secessionMember);
		nowLoginMember = NULL;
	}
}

void MemberList::logOutMember() {
	nowLoginMember = NULL;
}

int MemberList::checkValidID_PW(string id, string pwd) {
	if (nowLoginMember == NULL)
	{
		for (int i = 0; i < memberVector.size(); i++)
		{
			if (id == memberVector[i]->getMemberID())
			{
				if (pwd == memberVector[i]->getMemberPWD())
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
		}
		return 2;
	}
	else
	{
		return 3;
	}

}