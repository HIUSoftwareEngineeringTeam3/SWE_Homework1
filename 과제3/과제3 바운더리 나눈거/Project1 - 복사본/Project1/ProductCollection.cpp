#include "Member.h"
#include "Product.h"
#include "MemberCollection.h"
#include "ProductCollection.h"

void ProductCollection::pushProduct(Product* product) {
	productVector.push_back(product);
}
void ProductCollection::eraseProdcut(Product* product) {

	auto erasingProduct = find(productVector.begin(), productVector.end(), product);
	if (erasingProduct != productVector.end())
	{
		productVector.erase(erasingProduct);
	}
}

void ProductCollection::deleteMemory() {
	for (int i = 0; i < productVector.size(); i++) {
		delete productVector[i];
	}
}

vector<Product*>* ProductCollection::getProductVector() {
	return &productVector;
}