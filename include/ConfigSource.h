#ifndef CONFIGSOURCE_H
#define CONFIGSOURCE_H

#include <cstddef>

namespace pachy {
    class ConfigSource {
        public:
            virtual bool open(const char* filename) = 0;
            virtual bool read(const char* section, const char* header, char* buf, size_t len) = 0;
    };
}

#endif