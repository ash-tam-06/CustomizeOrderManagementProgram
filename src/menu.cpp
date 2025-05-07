//
//  menu.cpp
//  CIS25_FirstProject
//
//  Created by William Tissi on 2/14/25.
//

// since we need to propose the menu at least once before the user say he doesn't want to see it anymore, I thought that using do while loop is the best fit because it does an action at least once before checkinng any conditon. And we also need to propose this menu to our user constanly to propose to the user our available feature

// I also created a feedback feature using ternary operator to be creative.
//goal 1: stand out of the from the crowd to be special


// since our menu function use others function, it is important to have their library (import).
#include "../include/menu.hpp"
#include "../include/addOrder.hpp"
#include "../include/displayOrders.hpp"
#include "../include/searchOrder.hpp"
#include "../include/deleteOrder.hpp"
#include "../include/printOrders.hpp"
#include "../include/getValidInt.hpp"

#include <iostream>
using namespace std;



void menuDeclaration::menu() {
    int choice;
    int feedbackResponse;
    int rateExperience;
    do {
        
        // proposing different options that my program have
        cout << "\n===== MENU =====\n";
        cout << "1. Add Order\n";
        cout << "2. Display Orders\n";
        cout << "3. Search Order\n";
        cout << "4. Delete Order\n";
        cout << "5. Print Orders & Total Revenue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        choice = intValidation::getValidInt(1, 6);  // make sure the user doesn't try to crash the program
        
        // depending on the answer, execute a case
        switch (choice) {
            case 1: addOrderDeclaration::addOrder(); break;
            case 2: displayOrderDeclaration::displayOrders(); break;
            case 3: searchOrderDeclaration::searchOrder(); break;
            case 4: deleteOrderDeclaration::deleteOrder(); break;
            case 5: printOrdersDeclaration::printOrders(); break;
            case 6:
                // feedback feature
                cout << "Exiting program...\n"<<endl;
                cout << "Your experience is valuable"<<endl;
                cout << "Do you mind giving us some feedback about your experience with this program?"<<endl;
                cout << "Enter 1 for yes or 2 for no"<<endl;
                feedbackResponse = intValidation::getValidInt(1, 2);
                //now using ternary operator to have some feedback in case the user want to leave feedback
                
                (feedbackResponse == 1)
                    ? (cout << "How would you rate the program on a scale of 0 to 10\n",
                       rateExperience = intValidation::getValidInt(0, 10),
                       cout << "***    Thank you !!!    ***\n"<<endl)
                    : cout << "Okay !!\n";

                break;
        }
    } while (choice != 6);
}
