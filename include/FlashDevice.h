#ifndef PACHYDERM_FLASHDEVICE_H
#define PACHYDERM_FLASHDEVICE_H

#include <cstddef>

namespace pachy {
    class FlashDevice {
        public:
            static constexpr std::size_t ERASE_SIZE = 1<<16; // 64K page erase
            static constexpr std::size_t FLASH_SIZE = 1<<25; // 32M (128Mbit) total size
            virtual bool read(size_t addr, char* buffer, size_t size) = 0;
            virtual bool write(size_t addr, const char* data, size_t size) = 0;
            virtual bool erase(size_t addr) = 0;
    };
}

#endif