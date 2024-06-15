#include "FCCore.h"
#include <cstdio>
#include <cstring>

namespace pachy {
    FCCore::FCCore(DataSink* telem_sink,
                   FlashDevice* flash_dev,
                   ConfigSource* conf,
                   StorageSink* fs):
        telem(telem_sink),
        flash(flash_dev),
        config(conf),
        file(fs),
        log(flash) {}

    void FCCore::begin() {
        flash_start = log.init();

        char buf[256];
        std::snprintf(buf, 256, "%lx", flash_start);
        file->open("flash_addr.txt");
        file->write(buf, strlen(buf));
        file->close();

        char fissure[] = "I realized, the moment I fell into the fissure, that the book would not be destroyed as I had planned. It continued falling into that starry expanse of which I had only a fleeting glimpse. I have tried to speculate where it might have landed, but I must admit, however— such conjecture is futile. Still, the question of whose hands might someday hold my Myst book are unsettling to me. I know that my apprehensions might never be allayed, and so I close, realizing that perhaps, the ending has not yet been written.";
        log.write(fissure, strlen(fissure));
    }

    void FCCore::step() {

    }
}
