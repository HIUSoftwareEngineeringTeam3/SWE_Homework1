#include "MemberCollection.h"
#include "ProductCollection.h"
#include "Member.h";

vector<Member*>* MemberCollection::getMemberVector() {
	return &memberVector;
}

void MemberCollection::addNewMember(Member* member) {
	memberVector.push_back(member);
}

bool MemberCollection::checkNowLoginMember() {
	if (nowLoginMember == nullptr) {
		return false;
	}
	else {
		return true;
	}
}

void MemberCollection::loginMember(string id, string pwd) {
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

Member* MemberCollection::getNowLoginMember() {
	return nowLoginMember;
}

void MemberCollection::removeMember() {
	auto secessionMember = find(memberVector.begin(), memberVector.end(), nowLoginMember);
	if (secessionMember != memberVector.end())
	{
		memberVector.erase(secessionMember);
		nowLoginMember = NULL;
	}
}

void MemberCollection::logOutMember() {
	nowLoginMember = NULL;
}

int MemberCollection::checkValidID_PW(string id, string pwd) {
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