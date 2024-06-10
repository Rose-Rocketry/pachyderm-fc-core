#ifndef PACHY_FLASHSINK_H
#define PACHY_FLASHSINK_H

#include "DataSink.h"
#include "FlashDevice.h"

namespace pachy {
    class FlashSink: public DataSink {
        private:
            FlashDevice* flash;
            size_t write_addr;
            size_t erase_addr;
        public:
            FlashSink(FlashDevice* flash_dev);
            size_t init();
            virtual std::size_t buf_avail();
            virtual void write(const char* data, size_t size);
    };
}

#endif