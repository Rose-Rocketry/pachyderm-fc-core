#ifndef PACHYDERM_DATASINK_H
#define PACHYDERM_DATASINK_H

#include <cstddef>

namespace pachy {
    class DataSink {
        public:
            virtual std::size_t buf_avail() = 0;
            virtual void write(const char* data, size_t size) = 0;

            // Writes object in native byte representation. Extremely fast, but
            // may be difficult to parse on systems that are not the original
            // format. Notably, trying to write a type that contains a pointer
            // anywhere in its structure will probably not work, as it will just
            // dump the pointer address into flash.
            template <class TYPE>
            inline void write_obj(const TYPE& obj) {
                write((char*) &obj, sizeof(TYPE));
            }

            virtual void printf(const char* format, ...);
    };
}

#endif