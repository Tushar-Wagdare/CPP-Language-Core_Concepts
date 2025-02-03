#include "list.hpp"

int main(void){
    int data; 
    status_t status; 
    
    ttw::list* pList = new ttw::list; 
    std::cout << *pList;
    
    status = pList->get_start(&data); 
    assert(status == LIST_EMPTY); 

    status = pList->get_end(&data); 
    assert(status == LIST_EMPTY); 

    status = pList->pop_start(&data); 
    assert(status == LIST_EMPTY); 

    status = pList->pop_end(&data); 
    assert(status == LIST_EMPTY); 

    status = pList->remove_start(); 
    assert(status == LIST_EMPTY); 

    status = pList->remove_end(); 
    assert(status == LIST_EMPTY); 

    assert(pList->get_elements() == 0); 
    assert(pList->is_list_empty() == true); 
    
    status = pList->insert_end(200); 
    assert(status == SUCCESS); 
    std::cout << *pList;

    status = pList->insert_after(200, 300); 
    assert(status == SUCCESS); 
    std::cout << *pList; 

    for(data = 1500; data <= 9500; data = data + 1000){
        status = pList->insert_end(data); 
        assert(status == SUCCESS); 
    }

    for(data = 550; data <= 950; data += 100){
        status = pList->insert_start(data); 
        assert(status == SUCCESS); 
    }

    std::cout << "after repeated calls to insert_after and insert_before" << std::endl; 
    std::cout << *pList; 

    std::cout << "Navigating list through iterator" << std::endl; 
    for(
        ttw::list::iterator iter = pList->begin(); 
        iter != pList->end(); 
        ++iter
    )
        std::cout << "*iter:" << *iter << std::endl; 

    status = pList->insert_after(-100, 300); 
    assert(status == LIST_INVALID_DATA); 

    status = pList->insert_before(-300, 1000); 
    assert(status == LIST_INVALID_DATA); 

    status = pList->get_start(&data); 
    assert(status == SUCCESS); 
    std::cout << "start_data:" << data << std::endl; 

    status = pList->get_end(&data); 
    assert(status == SUCCESS); 
    std::cout << "end_data:" << data << std::endl; 

    status = pList->pop_start(&data); 
    assert(status == SUCCESS); 
    std::cout << "start_data:" << data << std::endl; 
    std::cout << "after pList->pop_start(&data):" << *pList; 

    status = pList->pop_end(&data); 
    assert(status == SUCCESS); 
    std::cout << "start_data:" << data << std::endl; 
    std::cout << "after pList->pop_end(&data):" << *pList; 

    status = pList->remove_start(); 
    assert(status == SUCCESS); 
    std::cout << "after pList->remove_start(&data):" << *pList; 

    status = pList->remove_end(); 
    assert(status == SUCCESS); 
    std::cout << "after pList->remove_end(&data):" << *pList; 

    status = pList->remove_data(5500); 
    assert(status == SUCCESS); 
    std::cout << "after pList->remove_data(5500):"  << *pList; 

    status = pList->remove_data(-500); 
    assert(status == LIST_INVALID_DATA); 

    if(pList->is_list_empty() == false)
        std::cout << "List is not empty" << std::endl; 

    std::cout << "Length:" << pList->get_elements() << std::endl; 

    delete pList; 
    pList = 0; 

    std::cout << "List destroyed successfully" << std::endl; 
    std::cout << "List unit testing: all ok" << std::endl; 

    return EXIT_SUCCESS; 
}

