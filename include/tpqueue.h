// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
  struct ITEM {
    T data;
    ITEM *next;
  };

 private:
  ITEM *nach;
  ITEM *kon;
  ITEM *create(T data) {
    ITEM *t = new ITEM;
    t->data = data;
    t->next = nullptr;
    return t;
  }

 public:
  TPQueue() : nach(nullptr), kon(nullptr) {}
  ~TPQueue() {
    while (nach) pop();
  }
  T pop() {
    ITEM *count = nach->next;
    T data = nach->data;
    delete nach;
    nach = count;
    return data;
  }

  void push(const T &data) {
    if (kon && nach) {
      ITEM *count = nach;
      if (count->data.prior < data.prior) {
        count = create(data);
        count->next = nach;
        nach = count;
      } else {
        while (count->next) {
          if (temp->next->data.prior < data.prior) {
            ITEM *t = create(data);
            t->next = count->next;
            count->next = t;
            break;
          } else {
            count = count->next;
          }
        }
      }
      if (!count->next) {
        kon->next = create(data);
        kon = kon->next;
      }
    } else {
      nach = create(data);
      kon = nach;
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
