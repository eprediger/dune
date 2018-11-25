// ****************************************************************************
// Descripcion: 
//	Clase creada para realizar el manejo de excepciones dentro del programa
// ****************************************************************************
#ifndef __CUSTOM_EXCEPTION__
#define __CUSTOM_EXCEPTION__

#include <exception>

#define BUF_LEN 256
#define DEFAULT_ERR_CODE 1

class CustomException : public std::exception {
protected:
	char msg_error[BUF_LEN];
	int error_code;

public:
	CustomException(const char* fmt, ...) noexcept;

	CustomException(const int errnumb, const char * fmt, ...) noexcept;

	virtual const char *what() const noexcept;

	int getErrorCode() const;
};

#endif	// __CUSTOM_EXCEPTION__
