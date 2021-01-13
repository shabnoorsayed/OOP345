// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
//Name: Shabnoor Sayed
//Email: ssayed10@myseneca.ca	
//Date: 11/22/2020
//Workshop 8

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					Product* temp(new Product(desc[i].desc, price[j].price));
					temp->validate();
					priceList += temp;
					delete temp;
				}
			}
		}

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					std::unique_ptr<Product> temp(new Product(desc[i].desc, price[j].price));
					temp->validate();
					priceList += temp;
				}
			}
		}


		return priceList;
	}
}