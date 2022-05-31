

// 헤더 선언
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Product.h"
// 상수 선언
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"




// 함수 선언
void doTask();
void join();
void login();
void programExit();
void registerProduct();
void evaluateSatisfaction();
void printStatistics();

// 변수 선언
vector<Member*> memberVector;
Member* nowLoginMember = NULL;
Product* nowSelectedProduct;
ifstream in_fp;
ofstream out_fp;
int main()
{ // 파일 입출력을 위한 초기화
	in_fp.open(INPUT_FILE_NAME);
	out_fp.open(OUTPUT_FILE_NAME);
	Member memberFpTaker(&out_fp);
	Product productFpTaker(&out_fp);


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

		// 메뉴 구분 및 해당 연산 수행
		switch (menu_level_1)
		{
		case 1:
			switch (menu_level_2)
			{
			case 1:
				//회원가입
				join();
				break;
			case 2:
				//회원탈퇴
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
				break;
			case 3:
				//판매 완료 상품 조회
				inquirySoldProductList();
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
void join()
{
	string name, ssn, id, pwd;
	in_fp >> name >> ssn >> id >> pwd;
	out_fp << "1.1. 회원가입\n> ";
	for (int i = 0; i < memberVector.size(); i++)
	{
		if (id == memberVector[i]->getMemberID())
		{
			out_fp << "중복된 아이디입니다.\n\n";
			return;
		}
	}
	Member* nowMember = new Member(name, ssn, id, pwd);
	memberVector.push_back(nowMember);
	out_fp << name << " " << ssn << " " << id << " " << pwd << "\n\n";
}

void secession()
{
	out_fp << "1.2. 회원탈퇴\n> ";
	auto secessionMember = find(memberVector.begin(), memberVector.end(), nowLoginMember);
	if (secessionMember != memberVector.end())
	{
		out_fp << nowLoginMember->getMemberID();
		memberVector.erase(secessionMember);
		nowLoginMember = NULL;
	}
	out_fp << "\n\n";
}

void login()
{
	string id, pwd;
	in_fp >> id >> pwd;
	out_fp << "2.1. 로그인\n> ";
	if (nowLoginMember == NULL)
	{
		for (int i = 0; i < memberVector.size(); i++)
		{
			if (id == memberVector[i]->getMemberID())
			{
				if (pwd == memberVector[i]->getMemberPWD())
				{
					nowLoginMember = memberVector[i];
					out_fp << id << " " << pwd << "\n\n";
					return;
				}
				else
				{
					out_fp << "비밀번호가 틀렸습니다.\n\n";
					return;
				}
			}
		}
		out_fp << "유효하지 않은 아이디입니다.\n\n";
	}
	else
	{
		out_fp << "이미 로그인 중입니다.\n\n";
	}
}

void logout()
{
	out_fp << "2.2. 로그아웃\n> ";
	if (nowLoginMember == NULL)
	{
		out_fp << "로그인중이 아닙니다.\n\n";
	}
	else
	{
		out_fp << nowLoginMember->getMemberID();
	}
	nowLoginMember = NULL;
	out_fp << "\n\n";
}

void myProductList()
{
	out_fp << "3.2. 등록 상품 조회\n";
	nowLoginMember->myProductList();
}

void boughtProductList()
{
	out_fp << "4.3. 상품 구매 내역 조회\n";
	nowLoginMember->boughtProductList();
}

void registerProduct()
{
	string productName, companyName;
	int price, quantity;
	in_fp >> productName >> companyName >> price >> quantity;
	nowLoginMember->registerProduct(productName, companyName, price, quantity);
}

void evaluateSatisfaction()
{
	int evaluateNum;
	in_fp >> evaluateNum;
	nowSelectedProduct->evaluateSatisfaction(evaluateNum);
}

void printStatistics()
{
	nowLoginMember->printSelledProductStatistics();
}

void programExit()
{

}

void inquirySoldProductList()
{
	nowLoginMember->inquirySoldProductList();
}

void searchProductDetail()
{
	string productName;
	in_fp >> productName;

	nowLoginMember->searchProductDetail(productName);
}

void purchaseProduct()
{
	nowLoginMember->purchaseProduct();
}