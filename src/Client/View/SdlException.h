#ifndef __SDLEXCEPTION_H__
#define __SDLEXCEPTION_H__

#include <exception>
#include <string>

class SdlException : public std::exception {
public:
	explicit SdlException(std::string what, const char* sdlError);

	~SdlException() override = default;

	const char* what() const noexcept override;

private:
	std::string msg;
};

#endif	// __SDLEXCEPTION_H__
