//
//  deleteOrder.hpp
//  CIS25_FirstProject
//
//  Created by William Tissi on 2/14/25.
//

#ifndef deleteOrder_hpp
#define deleteOrder_hpp

#include <stdio.h>
#include <string>
// sometime, we dont want to full our system and we decided to delete some really old orders or in the case that we has a false order
namespace deleteOrderDeclaration{
    void deleteOrder();
    std::string toLowerCase(const std::string &str);
}
#endif /* deleteOrder_hpp */
