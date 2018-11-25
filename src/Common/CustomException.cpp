#include "CustomException.h"

#include <errno.h>
#include <cstdio>
#include <cstdarg>
#include <cstring>

CustomException::CustomException(const char * fmt, ...) noexcept {
	error_code = DEFAULT_ERR_CODE;
	va_list args;
	va_start(args, fmt);
	int s = vsnprintf(msg_error, BUF_LEN, fmt, args);
	va_end(args);
	strncpy(msg_error + s, "\n", BUF_LEN - s);
	msg_error[BUF_LEN - 1] = 0;
}

CustomException::CustomException(const int errnumb,
                                 const char * fmt, ...) noexcept {
	error_code = errnumb;
	va_list args;
	va_start(args, fmt);
	int s = vsnprintf(msg_error, BUF_LEN, fmt, args);
	va_end(args);
	strncpy(msg_error + s, "\n", BUF_LEN - s);
	msg_error[BUF_LEN - 1] = 0;
}

const char* CustomException::what() const noexcept {
	return this->msg_error;
}

int CustomException::getErrorCode() const {
	return this->error_code;
}