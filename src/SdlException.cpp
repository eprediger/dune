//
// Created by emiliano on 24/10/18.
//

#include "SdlException.h"

#include <string>

SdlException::SdlException(std::string what, const char* sdlError) :
    std::exception(),
    msg(std::move(what)) {
    this->msg.append("\n SDL_ERROR: ").append(sdlError);
}

//SdlException::~SdlException() {}

const char* SdlException::what() const noexcept {
    return this->msg.c_str();
}
