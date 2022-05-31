

// ��� ����
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Product.h"
// ��� ����
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"




// �Լ� ����
void doTask();
void join();
void login();
void programExit();
void registerProduct();
void evaluateSatisfaction();
void printStatistics();

// ���� ����
vector<Member*> memberVector;
Member* nowLoginMember = NULL;
Product* nowSelectedProduct;
ifstream in_fp;
ofstream out_fp;
int main()
{ // ���� ������� ���� �ʱ�ȭ
	in_fp.open(INPUT_FILE_NAME);
	out_fp.open(OUTPUT_FILE_NAME);
	Member memberFpTaker(&out_fp);
	Product productFpTaker(&out_fp);


	doTask();
	return 0;
}

void doTask()
{ // �޴� �Ľ��� ���� level ������ ���� ����
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;

	while (!is_program_exit)
	{ // �Է����Ͽ��� �޴� ���� 2���� �б�
		in_fp >> menu_level_1 >> menu_level_2;

		// �޴� ���� �� �ش� ���� ����
		switch (menu_level_1)
		{
		case 1:
			switch (menu_level_2)
			{
			case 1:
				//ȸ������
				join();
				break;
			case 2:
				//ȸ��Ż��
				break;
			}
			break;
		case 2:
			switch (menu_level_2)
			{
			case 1:
				//�α���
				login();
				break;
			case 2:
				//�α׾ƿ�
				break;
			}
			break;
		case 3:
			switch (menu_level_2)
			{
			case 1:
				//�Ǹ� �Ƿ� ���
				registerProduct();
				break;
			case 2:
				//��� ��ǰ ��ȸ
				break;
			case 3:
				//�Ǹ� �Ϸ� ��ǰ ��ȸ
				inquirySoldProductList();
				break;
			}
			break;
		case 4:
			switch (menu_level_2)
			{
			case 1:
				//��ǰ ���� �˻�
				searchProductDetail();
				break;
			case 2:
				//��ǰ ����
				purchaseProduct();
				break;
			case 3:
				//��ǰ ���� ���� ��ȸ
				break;
			case 4:
				//��ǰ ���Ÿ����� ��
				evaluateSatisfaction();
				break;

			}
			break;
		case 5:
			switch (menu_level_2)
			{
			case 1:
				//�Ǹ� ��ǰ ���
				printStatistics();
				break;
			}
			break;
		case 6:
			switch (menu_level_2)
			{
			case 1: // "6.1. ���ᡰ �޴� �κ�
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
	out_fp << "1.1. ȸ������\n> ";
	for (int i = 0; i < memberVector.size(); i++)
	{
		if (id == memberVector[i]->getMemberID())
		{
			out_fp << "�ߺ��� ���̵��Դϴ�.\n\n";
			return;
		}
	}
	Member* nowMember = new Member(name, ssn, id, pwd);
	memberVector.push_back(nowMember);
	out_fp << name << " " << ssn << " " << id << " " << pwd << "\n\n";
}

void secession()
{
	out_fp << "1.2. ȸ��Ż��\n> ";
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
	out_fp << "2.1. �α���\n> ";
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
					out_fp << "��й�ȣ�� Ʋ�Ƚ��ϴ�.\n\n";
					return;
				}
			}
		}
		out_fp << "��ȿ���� ���� ���̵��Դϴ�.\n\n";
	}
	else
	{
		out_fp << "�̹� �α��� ���Դϴ�.\n\n";
	}
}

void logout()
{
	out_fp << "2.2. �α׾ƿ�\n> ";
	if (nowLoginMember == NULL)
	{
		out_fp << "�α������� �ƴմϴ�.\n\n";
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
	out_fp << "3.2. ��� ��ǰ ��ȸ\n";
	nowLoginMember->myProductList();
}

void boughtProductList()
{
	out_fp << "4.3. ��ǰ ���� ���� ��ȸ\n";
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