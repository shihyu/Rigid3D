#ifndef RIGID3D_EXCEPTION_HPP_
#define RIGID3D_EXCEPTION_HPP_

#include <exception>
#include <string>

namespace Rigid3D {

using std::string;

    class Rigid3DException : public std::exception {
    public:
        Rigid3DException(const string & message)
            : errorMessage(message) { }

        ~Rigid3DException() noexcept { }

        const char * what() const noexcept {
            return errorMessage.c_str();
        }

    private:
        string errorMessage;
    };

}

#endif /* RIGID3D_EXCEPTION_HPP_ */
