struct PacketEventData
{
    struct PacketHeader    	m_header;               	// Header
    
    uint8           	m_eventStringCode[4];   	// Event string code, see below
    union EventDataDetails	m_eventDetails;         	// Event details - should be interpreted differently
                                                 // for each type
};
