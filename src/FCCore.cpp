#include "FCCore.h"

#include <cstdio>
#include <cstring>

namespace pachy {
    FCCore::FCCore(DataSink* debug_sink,
                   DataSink* telem_sink,
                   FlashDevice* flash_dev,
                   ConfigSource* conf,
                   StorageSink* fs):
        debug(debug_sink),
        telem(telem_sink),
        flash(flash_dev),
        config(conf),
        file(fs),
        log(flash) {}

    void FCCore::begin() {
        debug->printf("PachydermFC starting\n");
        flash_start = log.init();
        
        debug->printf("Flash starts at %lx\n", flash_start);
        file->open("flash_addr.txt");
        file->printf("%lx", flash_start);
        file->close();
    }

    void FCCore::step() {
        // Any scheduled task we might need to do
        if(false) {
            // ...
        } else if(flash_queue.size() > 0 && log.buf_avail() > sizeof(DataPacket)) {
            DataPacket p;
            flash_queue.pop(&p);
            log.write_obj(p);
        }
    }
}
