//
// Created by rattus on 26.05.2021.
//

#include "cell.h"

Status Cell::get_status() {
    return status;
}

void Cell::reverse() {
    if (status == Dead)
        status = Alive;
    else
        status = Dead;
}

void Cell::set_next_status(Status next) {
    next_status = next;
}

void Cell::update() {
    status = next_status;
}

void Cell::set_status(Status new_status) {
    this->status = new_status;
}
