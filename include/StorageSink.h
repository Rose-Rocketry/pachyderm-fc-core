#ifndef STORAGE_SINK_H
#define STORAGE_SINK_H

#include "DataSink.h"

namespace pachy {
    class StorageSink: public DataSink {
        public:
            virtual bool open(const char* path) = 0;
            virtual bool close() = 0;
    };
}

#endif