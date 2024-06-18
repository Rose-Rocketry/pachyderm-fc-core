#ifndef DATAPACKET_H
#define DATAPACKET_H

#include <cstdint>
#include "VectorMath.h"

namespace pachy {
    static constexpr size_t packet_size = 128;

    enum class FlightState : uint8_t {
        ERROR,
        READY,
        BOOST,
        COAST,
        DESCENT,
        LANDING
    };

    // This should be exactly 128 bytes
    struct __attribute__((packed)) DataPacket {
        // Measured values
        uint32_t time;
        VectorF accel;
        
        float altitude;
        VectorF higAccel;
        
        uint8_t battVoltage;
        uint8_t temp; // reported in 5ths of a degree C
        uint8_t pyroCont;
        uint8_t placeholder;
        VectorF gyro;

        uint8_t placeholder_sensors[16];

        // Calculated values
        FlightState state;
        uint8_t placeholder_controllaw;
        uint16_t placeholder_pyrostate;
        VectorF vel;
        
        QuatF orientation;

        uint8_t placeholder_calcs[32];
    };

    static_assert(sizeof(DataPacket) <= packet_size, "DataPacket is too large");
}

#endif