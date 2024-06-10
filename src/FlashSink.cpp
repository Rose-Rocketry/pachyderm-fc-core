#include "FlashSink.h"

#include <random>
#include <limits>

namespace pachy {
    FlashSink::FlashSink(FlashDevice* flash_dev):
        flash(flash_dev) {}

    size_t FlashSink::init() {
        static_assert(RAND_MAX >= flash->FLASH_SIZE / flash->ERASE_SIZE);
        // usually using C-style rand() is bad form, but here it makes sense
        // because we don't want our slow MCU to get bogged down with more
        // complex RNG
        write_addr = (std::rand() * flash->ERASE_SIZE) % flash->FLASH_SIZE;
        erase_addr = write_addr;
        flash->erase(erase_addr);
        erase_addr += flash->ERASE_SIZE;
        flash->erase(erase_addr);
        return write_addr;
    }

    std::size_t FlashSink::buf_avail() {
        return (erase_addr + flash->FLASH_SIZE - write_addr) % flash->FLASH_SIZE;
    }

    void FlashSink::write(const char* data, size_t size) {
        // Always keep one erase page ahead of the cursor free
        if(buf_avail() < flash->ERASE_SIZE) {
            erase_addr += flash->ERASE_SIZE;
            erase_addr %= flash->FLASH_SIZE;
            flash->erase(erase_addr);
        }
        flash->write(write_addr, data, size);
        write_addr += size;
    }
}