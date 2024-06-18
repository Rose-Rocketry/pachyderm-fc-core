#ifndef PACHYDERM_FCCORE_H
#define PACHYDERM_FCCORE_H

#include "DataSink.h"
#include "FlashDevice.h"
#include "FlashSink.h"
#include "ConfigSource.h"
#include "StorageSink.h"
#include "DataPacket.h"
#include "static_queue.h"

namespace pachy {
    class FCCore {
        private:
            // Interface devices
            DataSink* debug;
            DataSink* telem;
            FlashDevice* flash;
            ConfigSource* config;
            StorageSink* file;
            FlashSink log;

            size_t flash_start;
            static_queue<DataPacket, 16384/packet_size> flash_queue;
        public:
            FCCore(DataSink* debug_sink,
                   DataSink* telem_sink,
                   FlashDevice* flash_dev,
                   ConfigSource* conf,
                   StorageSink* fs);
            void begin();
            void step();
    };
}

#endif