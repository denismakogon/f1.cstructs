struct PacketFinalClassificationData
{
    struct PacketHeader             m_header;                   // Header

    uint8                           m_numCars;                  // Number of cars in the final classification
    struct FinalClassificationData  m_classificationData[22];
};
