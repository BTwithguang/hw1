#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::push_back(const std::string& val){
  if(size_ == 0){
    Item* newItem = new Item;
    newItem->val[0] = val;
    newItem->last = 1;
    head_ = newItem;
    tail_ = newItem;
    size_ = 1;
    return;
  }
  if(tail_->last < ARRSIZE){
  
 tail_->val[tail_->last]=val;
tail_->last++;
size_++;
return;
  }
  Item* newItem = new Item;
  newItem->prev = tail_;
  newItem->next = nullptr;
  tail_->next = newItem;
  newItem->val[0] = val;
  newItem->last = 1;
  newItem->first = 0;
  tail_ = newItem;
  size_++;
}
std::string const& ULListStr::back() const{
  if(empty()){
    throw std::invalid_argument("empty");
  }
  return tail_->val[tail_->last-1];
}
void ULListStr::push_front(const std::string& val){
  if(size_ == 0){
    Item* newItem =new Item;
    newItem->first = ARRSIZE-1;
    newItem->last = ARRSIZE;
    newItem->val[newItem->first] = val;
    head_ = newItem;
    tail_ = newItem;
    size_ = 1;
    return;}
    if(head_->first>0){
      head_->first--;
      head_->val[head_->first] = val;
      size_++;
      return;
    }
    Item* newItem = new Item;
    newItem->first = ARRSIZE-1;
    newItem->last = ARRSIZE;
    newItem->val[newItem->first] = val;
    newItem->next = head_;
    head_->prev = newItem;
    head_ = newItem;
    size_++;
  }
  void ULListStr::pop_back(){
    if(size_==0){
      return;
    }
    tail_->last--;
    size_--;
    if(tail_->first == tail_->last){
      Item* old=tail_;
      tail_ = tail_->prev;
    
    if(tail_ == nullptr){
      head_ = nullptr;
    
    }
    else{
      tail_->next = nullptr;
    }
    delete old;
  }}
  void ULListStr::pop_front(){
    if(size_==0){
      return;
    }
    head_->first++;
    size_--;
    if(head_->first == head_->last){
      Item* old=head_;
      head_ = head_->next;
      if(head_ == nullptr){
        tail_ = nullptr;
      }
      else{
        head_->prev = nullptr;
      }
      delete old;
    }
  }
  std::string const& ULListStr::front() const{
    if(empty()){
      throw std::invalid_argument("empty");
    }
    return head_->val[head_->first];
  }
  std::string* ULListStr::getValAtLoc(size_t loc) const{
    if(loc >= size_){
      return nullptr;
    }
    Item* current = head_;
    size_t remaining = loc;
    while(current != nullptr){
      size_t itemSize = current->last-current->first;
      if(remaining<itemSize){
        return &(current->val[current->first+remaining]);
      }
      remaining = remaining-itemSize;
      current = current->next;
    }
    return nullptr;
  }

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}


std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
