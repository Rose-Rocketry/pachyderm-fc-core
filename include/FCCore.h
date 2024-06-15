#ifndef PACHYDERM_FCCORE_H
#define PACHYDERM_FCCORE_H

#include "DataSink.h"
#include "FlashDevice.h"
#include "FlashSink.h"
#include "ConfigSource.h"
#include "StorageSink.h"

namespace pachy {
    class FCCore {
        private:
            // Interface devices
            DataSink* telem;
            FlashDevice* flash;
            ConfigSource* config;
            StorageSink* file;
            FlashSink log;

            size_t flash_start;
        public:
            FCCore(DataSink* telem_sink,
                   FlashDevice* flash_dev,
                   ConfigSource* conf,
                   StorageSink* fs);
            void begin();
            void step();
    };
}

#endif