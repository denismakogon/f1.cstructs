#pragma pack(1)

#include "ctypedefs.h"

struct BasePacketHeader {
    uint16    m_packetFormat;            // 20XX
    uint8     m_gameYear;                // Game year - last two digits e.g. 23
    uint8     m_gameMajorVersion;        // Game major version - "X.00"
    uint8     m_gameMinorVersion;        // Game minor version - "1.XX"
    uint8     m_packetVersion;           // Version of this packet type, all start from 1
};
