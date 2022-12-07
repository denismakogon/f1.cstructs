struct PacketParticipantsData
{
    struct PacketHeader    m_header;            // Header

    uint8           m_numActiveCars;    // Number of active cars in the data – should match number of
                                         // cars on HUD
    struct ParticipantData m_participants[22];
};
