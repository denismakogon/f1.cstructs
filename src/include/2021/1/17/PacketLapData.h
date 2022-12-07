struct PacketLapData
{
    struct PacketHeader    m_header;              // Header

    struct LapData         m_lapData[22];         // Lap data for all cars on track
};
