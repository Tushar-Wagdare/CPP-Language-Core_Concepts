#include"list.hpp"
#include<cstdio>
#include<cstdlib>

ttw::node::node(data_t _data)
{
    data = _data;
    next = 0;
    prev = 0;
}

void ttw::list::generic_insert(node* p_start, node* p_mid, node* p_end)
{
    p_mid->next = p_end;
    p_mid->prev = p_start;
    p_start->next = p_mid;
    p_end->prev = p_mid;
}

void ttw::list::generic_delete(node* p_delete_node)
{
    p_delete_node->prev->next = p_delete_node->next;
    p_delete_node->next->prev = p_delete_node->prev;
    
    delete p_delete_node;
}

ttw::node* ttw::list::search_node(data_t e_data) const
{
    for(node* p_run = head_node->next; p_run != head_node; p_run = p_run->next)
    {
        if(p_run->data == e_data)
            return(p_run);
    }

    return(0);
}

ttw::list::list()
{
    head_node = new node(0);
    head_node->prev = head_node;
    head_node->next = head_node;
}

ttw::list::~list()
{
    node* run = 0;
    node* run_next = 0;

    for(run = head_node->next; run != head_node; run = run_next)
    {
        run_next = run->next;
        delete run;
    }

    delete head_node;
}

status_t ttw::list::insert_start(data_t data)
{
    generic_insert(head_node, new node(data), head_node->next);

    return(SUCCESS);
}

status_t ttw::list::insert_end(data_t data)
{
    generic_insert(head_node->prev, new node(data), head_node);

    return(SUCCESS);
}

status_t ttw::list::insert_after(data_t e_data, data_t data)
{
    node* e_node = search_node(e_data);
    if(0 == e_node)
        return(LIST_INVALID_DATA);

    generic_insert(e_node, new node(data), e_node->next);

    return(SUCCESS);
}

status_t ttw::list::insert_before(data_t e_data, data_t data)
{
    node* e_node = search_node(e_data);
    if(0 == e_node)
        return(LIST_INVALID_DATA);

    generic_insert(e_node->prev, new node(data), e_node);

    return(SUCCESS);
}

status_t ttw::list::get_start(data_t* p_data)
{
    if(is_list_empty())
        return(LIST_EMPTY);

    *p_data = head_node->next->data;

    return(SUCCESS);
}

status_t ttw::list::get_end(data_t* p_data)
{
    if(is_list_empty())
        return(LIST_EMPTY);

    *p_data = head_node->prev->data;

    return(SUCCESS);
}

len_t ttw::list::get_elements(void)
{
    unsigned int nr_elements = 0;

    for(node* p_run = head_node->next; p_run != head_node; p_run = p_run->next)
    {
        nr_elements++;
    }

    return(nr_elements);
}

status_t ttw::list::pop_start(data_t* p_data)
{
    if(is_list_empty())
        return(LIST_EMPTY);

    *p_data = head_node->next->data;

    generic_delete(head_node->next);

    return(SUCCESS);
}

status_t ttw::list::pop_end(data_t* p_data)
{
    if(is_list_empty())
        return(LIST_EMPTY);

    *p_data = head_node->prev->data;

    generic_delete(head_node->prev);

    return(SUCCESS);
}

status_t ttw::list::remove_start(void)
{
    if(is_list_empty())
        return(LIST_EMPTY);

    generic_delete(head_node->next);

    return(SUCCESS);
}

status_t ttw::list::remove_end(void)
{
    if(is_list_empty())
        return(LIST_EMPTY);
        
    generic_delete(head_node->prev);

    return(SUCCESS);
}

status_t ttw::list::remove_data(data_t r_data)
{
    if(is_list_empty())
        return(LIST_EMPTY);

    node* e_node = search_node(r_data);
    if(0 == e_node)
        return(LIST_INVALID_DATA);

    generic_delete(e_node);

    return(SUCCESS);
}

bool ttw::list::is_list_empty(void)
{
    return(head_node == head_node->next && head_node == head_node->prev);
}

bool ttw::list::find(data_t f_data)
{
    if(is_list_empty())
        return(LIST_EMPTY);
        
    node* e_node = 0;
    e_node = search_node(f_data);

    return(e_node != 0);
}

std::ostream& ttw::operator<<(std::ostream& os, const ttw::list& list_object)
{
    os << "[START]";

    for(node* run = list_object.head_node->next; run != list_object.head_node; run = run->next)
    {
        os << "<->[" << run->data << "]";
    }

    os << "<->[END]" << std::endl;

    return(os);
}

ttw::list::iterator ttw::list::begin() const
{
    iterator iter(head_node->next);

    return(iter);
} 

ttw::list::iterator ttw::list::end() const
{
    iterator iter(head_node);

    return(iter);
} 
           
ttw::list::iterator::iterator(node* _node)
{
    current_node = _node;
}

ttw::list::iterator& ttw::list::iterator::operator++()
{
    this->current_node = this->current_node->next;

    return(*this);
} 

ttw::list::iterator ttw::list::iterator::operator++(int)
{
    iterator temp(current_node);

    this->current_node = this->current_node->next;

    return(temp);
} 

ttw::list::iterator& ttw::list::iterator::operator--()
{
    this->current_node = this->current_node->prev;

    return(*this);
} 

ttw::list::iterator ttw::list::iterator::operator--(int)
{
    iterator temp(current_node);

    this->current_node = this->current_node->prev;

    return(temp);
} 

int ttw::list::iterator::operator*()
{
    return(current_node->data);
}

bool ttw::list::iterator::operator==(const iterator& rhs)
{
    return(current_node == rhs.current_node);
}

bool ttw::list::iterator::operator!=(const iterator& rhs)
{
    return(current_node != rhs.current_node);
}
                   
           
