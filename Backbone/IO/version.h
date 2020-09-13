#ifndef VERSION_H
#define VERSION_H

#include "git-version.h"

std::string get_version_all()   {return VERSION_ALL;}
std::string get_version_major() {return VERSION_MAJOR;}
std::string get_version_minor() {return VERSION_MINOR;}
std::string get_version_patch() {return VERSION_PATCH;}

#endif
