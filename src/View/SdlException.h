#ifndef WINDOW_SDLEXCEPTION_H
#define WINDOW_SDLEXCEPTION_H

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

#endif //WINDOW_SDLEXCEPTION_H
