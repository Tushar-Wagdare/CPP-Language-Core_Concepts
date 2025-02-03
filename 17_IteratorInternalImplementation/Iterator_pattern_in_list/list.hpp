#ifndef _LIST_HPP
#define _LIST_HPP

// standard headers
#include <iostream>
#include <cstdlib>
#include <cassert> 

// list constants
const int SUCCESS              = 0;
const int FAIL                 = 1;
const int LIST_INVALID_DATA    = 2;
const int LIST_EMPTY           = 4;

// list typedefs
typedef int data_t;
typedef int status_t;
typedef unsigned int len_t;





// list layout
namespace ttw
{
    // node layout
    class node
    {
        friend class list;
        friend std::ostream& operator<<(std::ostream& os, const list& list_object);

        private:
            data_t data;
            node* prev;
            node* next;

            node(data_t _data = 0);
    };
    
    class list
    {
        friend std::ostream& operator<<(std::ostream& os, const list& list_object);

        private:
            node* head_node;
        
            static void generic_insert(node* p_start, node* p_mid, node* p_end);
            static void generic_delete(node* p_delete_node);
            node* search_node(data_t e_data) const;

        public:
            class iterator;
            list();
            ~list();
            status_t insert_start(data_t data);
            status_t insert_end(data_t data);
            status_t insert_after(data_t e_data, data_t data);
            status_t insert_before(data_t e_data, data_t data);

            status_t get_start(data_t* p_data);
            status_t get_end(data_t* p_data);
            len_t get_elements(void);

            status_t pop_start(data_t* p_data);
            status_t pop_end(data_t* p_data);

            status_t remove_start(void);
            status_t remove_end(void);
            status_t remove_data(data_t r_data);

            bool is_list_empty(void);
            bool find(data_t f_data);

            void* xmalloc(size_t size_in_bytes);

            iterator begin() const; 
            iterator end() const; 

            class iterator
            {
                private: 
                    node* current_node; 
                public: 
                    iterator(node* _node); 
                    iterator& operator++(); 
                    iterator operator++(int); 
                    iterator& operator--(); 
                    iterator operator--(int); 
                    int operator*(); 
                    bool operator==(const iterator& rhs); 
                    bool operator!=(const iterator& rhs);
            };
    };
};




#endif  // _LIST_HPP