#ifndef PACHYDERM_DATASINK_H
#define PACHYDERM_DATASINK_H

#include <cstddef>

namespace pachy {
    class DataSink {
        public:
            virtual std::size_t buf_avail() = 0;
            virtual void write(const char* data, size_t size) = 0;
    };
}

#endif