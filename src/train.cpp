

// Copyright 2021 Artyom Lavrov


#include "train.h"


Cage::Cage(bool _lamp)
    : lamp(_lamp), left(nullptr), right(nullptr) {
}

void Cage::on() {
  lamp = true;
}

void Cage::off() {
  lamp = false;
}

bool Cage::isLight() const {
  return lamp;
}

Train::Train()
    : begin(nullptr), end(nullptr) {
}

void Train::AddCage(Cage* _cage) {
    if (nullptr == begin) {
        _cage->right = _cage;
        _cage->left = _cage;
        begin = _cage;
        end = _cage;
    } else {
        end->left = _cage;
        _cage->right = end;
        _cage->left = begin;
        begin->right = _cage;
        end = _cage;
    }
}

void Train::CreateCages(unsigned int _length) {
  for (unsigned int i = 0; i < _length; i++) {
      AddCage(new Cage(std::rand() % 2));
  }
}

unsigned int Train::CountLength() {
  Cage* a = begin;
  begin->on();

    for (unsigned int step = 1; ; step++) {
        for (unsigned int i = 0; i < step; i++) {
            a = a->left;
            a->off();
        }
        for (unsigned int i = 0; i < step; i++) {
            a = a->right;
        }
        if (!a->isLight())
            return step;
    }
}

void Train::Print() {
    Cage* b = begin;

    for (unsigned int step = 1; ; step++) {
        std::cout << "Cage number " << step 
            << ",lamp-" << (b->isLight() ? "on\n" : "off\n");
        b = b->left;
        if (b == begin)
            return;
    }
}

