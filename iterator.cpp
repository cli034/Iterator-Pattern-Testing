#include "iterator.h"


void OperatorIterator::first()
{
    current_ptr = this->self_ptr->get_left();    
}

void OperatorIterator::next()
{
    if (current_ptr == this->self_ptr->get_left())
    {
        current_ptr = this->self_ptr->get_right();
    }
    else
    {
        current_ptr = NULL;
    }
}

bool OperatorIterator::is_done()
{
    if(current_ptr == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Base* OperatorIterator::current()
{
    return current_ptr;
}

//=====================================================
void UnaryIterator::first()
{
    current_ptr = this->self_ptr->get_left();    
}

void UnaryIterator::next()
{

    current_ptr = NULL;
}

bool UnaryIterator::is_done()
{
    if(current_ptr == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Base* UnaryIterator::current()
{
    return current_ptr;
}

//==================================================

void NullIterator::first()
{
}

void NullIterator::next()
{
}

bool NullIterator::is_done()
{
    return true;
}

Base* NullIterator::current()
{
    return NULL;
}
 //=====================================================
 
void PreOrderIterator::first()
{
    Iterator* it = self_ptr->create_iterator();
    if(it)
    {
        it->first();
        while(!iterator.empty())
        {
            iterator.pop();
        }
        this->iterator.push(it);
    }
}

void PreOrderIterator::next()
{
    Iterator* it = iterator.top()->current()->create_iterator();
    it->first();
    this->iterator.push(it);
    while(iterator.top()->is_done() && iterator.size() > 1)
    {
        iterator.pop();
        if (!iterator.empty())
        {
            iterator.top()->next();
        }
    }
}

bool PreOrderIterator::is_done()
{
    if(iterator.top()->is_done() && iterator.size() == 1)
    {
        return true;
    }
    return false;
}

Base* PreOrderIterator::current()
{
    if(!this->iterator.empty())
    {
        return iterator.top()->current();
    }
    return NULL;
}
