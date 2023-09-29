struct PacketMotionData
{
    struct PacketHeader    m_header;               	// Header

    struct CarMotionData   m_carMotionData[22];    	// Data for all cars on track
};
