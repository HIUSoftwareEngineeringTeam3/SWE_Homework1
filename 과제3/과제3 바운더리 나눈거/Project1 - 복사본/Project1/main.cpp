

// 헤더 선언
#include "Product.h"
#include "ProductCollection.h"
#include "Member.h"
#include "MemberCollection.h"

#include "AddNewMember.h"
#include "AddNewMemberUI.h"
#include "RemoveMember.h"
#include "RemoveMemberUI.h"
#include "LoginMember.h"
#include "LoginMemberUI.h"
#include "LogOutMember.h"
#include "LogOutMemberUI.h"
#include "RegisterProduct.h"
#include "RegisterProductUI.h"
#include "InquirySellingProductUI.h"
#include "InquirySellingProduct.h"
#include "InquirySoldProductUI.h"
#include "InquirySoldProduct.h"
#include "ProductSearch.h"
#include "ProductSearchUI.h"
#include "PurchaseProduct.h"
#include "PurchaseProductUI.h"
#include "InquiryBoughtProductUI.h"
#include "InquiryBoughtProduct.h"
#include "EvaluateSatisfaction.h"
#include "EvaluateSatisfactionUI.h"
#include "PrintStatisticsUI.h"
#include "PrintStatistics.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// 상수 선언
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"




// 함수 선언
void doTask();
void addNewMember();
void login();
void logout();
void programExit();
void registerProduct();
void evaluateSatisfaction();
void printStatistics();
void removeMember();
void inquiryProduct();
void boughtProductList();
void programExit();
void inquirySoldProduct();
void searchProductDetail();
void purchaseProduct();
void deleteMemory();

// 변수 선언
//vector<Member*> memberVector;
Member* nowLoginMember;
//Product* nowSelectedProduct;
MemberCollection memberList;
ifstream in_fp;
ofstream out_fp;
int main()
{ // 파일 입출력을 위한 초기화
	in_fp.open(INPUT_FILE_NAME);
	out_fp.open(OUTPUT_FILE_NAME);
	//Member memberFpTaker(&out_fp,&memberVector);
	//Product productFpTaker(&out_fp);

	
	doTask();
	
	return 0;
}


void doTask()
{ // 메뉴 파싱을 위한 level 구분을 위한 변수
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;
	while (!is_program_exit)
	{ // 입력파일에서 메뉴 숫자 2개를 읽기
		in_fp >> menu_level_1 >> menu_level_2;
		//cout << menu_level_1 <<" "<< menu_level_2 << endl;
		

		// 메뉴 구분 및 해당 연산 수행
		switch (menu_level_1)
		{
		case 1:
			switch (menu_level_2)
			{
			case 1:
				//회원가입
				addNewMember();
				break;
			case 2:
				//회원탈퇴
				removeMember();
				break;
			}
			break;
		case 2:
			switch (menu_level_2)
			{
			case 1:
				//로그인
				login();
				break;
			case 2:
				//로그아웃
				logout();
				break;
			}
			break;
		case 3:
			switch (menu_level_2)
			{
			case 1:
				//판매 의류 등록
				registerProduct();
				break;
			case 2:
				//등록 상품 조회
				inquiryProduct();
				break;
			case 3:
				//판매 완료 상품 조회
				inquirySoldProduct();
				break;
			}
			break;
		case 4:
			switch (menu_level_2)
			{
			case 1:
				//상품 정보 검색
				searchProductDetail();
				break;
			case 2:
				//상품 구매
				purchaseProduct();
				break;
			case 3:
				//상품 구매 내역 조회
				boughtProductList();
				break;
			case 4:
				//상품 구매만족도 평가
				evaluateSatisfaction();
				break;

			}
			break;
		case 5:
			switch (menu_level_2)
			{
			case 1:
				//판매 상품 통계
				printStatistics();
				break;
			}
			break;
		case 6:
			switch (menu_level_2)
			{
			case 1: // "6.1. 종료“ 메뉴 부분
				programExit();
				is_program_exit = 1;
				break;
			}
			break;
		}
	}
}


void registerProduct() 
{

	RegisterProduct* registerProduct = new RegisterProduct(&out_fp, &in_fp, &memberList);
	registerProduct->getBoundary()->inputInformation();
	delete registerProduct->getBoundary();
	delete registerProduct;
}

void evaluateSatisfaction() 
{
	EvaluateSatisfaction* evaluate = new EvaluateSatisfaction(&out_fp, &in_fp, &memberList);
	evaluate->getBoundary()->inputScore();
	delete evaluate->getBoundary();
	delete evaluate;

}

void printStatistics() 
{
	PrintStatistics* print = new PrintStatistics(&out_fp, &in_fp, &memberList);
	print->getBoundary()->printStatisticsButton();
	delete print->getBoundary();
	delete print;

}

void addNewMember()
{
	AddNewMember* addingMember = new AddNewMember(&out_fp, &in_fp, &memberList);
	addingMember->getBoundary()->inputInformation();
	delete addingMember->getBoundary();
	delete addingMember;

}

void removeMember()
{
	RemoveMember* removeMember = new RemoveMember(&out_fp, &in_fp, &memberList);
	removeMember->getBoundary()->clickRemoveMember();
	delete removeMember->getBoundary();
	delete removeMember;
}

void login()
{
	LoginMember* loginMember = new LoginMember(&out_fp, &in_fp, &memberList);
	loginMember->getBoundary()->inputID_PW();
	delete loginMember->getBoundary();
	delete loginMember;
}

void logout()
{
	LogOutMember* logoutMember = new LogOutMember(&out_fp, &in_fp, &memberList);
	logoutMember->getBoundary()->clickLogOutMember();
	delete logoutMember->getBoundary();
	delete logoutMember;
}

void inquiryProduct()
{
	InquirySellingProduct* inquiryProduct = new InquirySellingProduct(&out_fp, &in_fp, &memberList);
	inquiryProduct->getBoundary()->clickInquiryProduct();
	delete inquiryProduct->getBoundary();
	delete inquiryProduct;
}

void boughtProductList()
{
	InquiryBoughtProduct* boughtProduct = new InquiryBoughtProduct(&out_fp, &in_fp, &memberList);
	boughtProduct->getBoundary()->clickInquiryBoughtProduct();
	delete boughtProduct->getBoundary();
	delete boughtProduct;
}


void programExit()
{
	//cout << "close" << endl;
	in_fp.close();
	out_fp.close();
	deleteMemory();
}

void inquirySoldProduct()
{
	InquirySoldProduct* inquirySoldProduct  = new InquirySoldProduct(&out_fp, &in_fp, &memberList);
	inquirySoldProduct->getBoundary()->clickInquirySoldProductButton();
	delete inquirySoldProduct->getBoundary();
	delete inquirySoldProduct;
}

void searchProductDetail()
{
	ProductSearch* productSearch = new ProductSearch(&out_fp, &in_fp, &memberList);
	productSearch->getBoundary()->inputProductName();
	delete productSearch->getBoundary();
	delete productSearch;
}

void purchaseProduct()
{
	PurchaseProduct* purchaseControl = new PurchaseProduct(&out_fp, &in_fp, &memberList);
	purchaseControl->getBoundary()->purchaseButton();
	delete purchaseControl->getBoundary();
	delete purchaseControl;
}

void deleteMemory() {
	int memberSize = memberList.getMemberVector()->size();

	for (int i = 0; i < memberSize; i++) {
		Member* member = (*(memberList.getMemberVector()))[i];
		member->deleteMemory();
		delete member;
	}
}

