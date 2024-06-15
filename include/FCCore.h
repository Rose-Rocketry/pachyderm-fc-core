#ifndef PACHYDERM_FCCORE_H
#define PACHYDERM_FCCORE_H

#include "DataSink.h"
#include "FlashDevice.h"
#include "FlashSink.h"
#include "ConfigSource.h"

namespace pachy {
    class FCCore {
        private:
            DataSink* telem;
            FlashDevice* flash;
            ConfigSource* config;
            FlashSink log;
        public:
            FCCore(DataSink* telem_sink, FlashDevice* flash_dev, ConfigSource* conf);
            void begin();
            void step();
    };
}

#endif