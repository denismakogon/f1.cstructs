struct PacketLobbyInfoData
{
    struct PacketHeader     m_header;           // Header

    // Packet specific data
    uint8                   m_numPlayers;       // Number of players in the lobby data
    struct LobbyInfoData    m_lobbyPlayers[22];
};
