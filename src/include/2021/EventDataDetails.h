// The event details packet is different for each type of event.
// Make sure only the correct type is interpreted.
struct FastestLap
{
    uint8    vehicleIdx;                        // Vehicle index of car achieving fastest lap
    float    lapTime;                           // Lap time is in seconds
};

struct Retirement
{
    uint8   vehicleIdx;                         // Vehicle index of car retiring
};

struct TeamMateInPits
{
    uint8   vehicleIdx;                         // Vehicle index of team mate
};

struct RaceWinner
{
    uint8   vehicleIdx;                         // Vehicle index of the race winner
};

struct Penalty
{
    uint8 penaltyType;                          // Penalty type – see Appendices
    uint8 infringementType;                     // Infringement type – see Appendices
    uint8 vehicleIdx;                           // Vehicle index of the car the penalty is applied to
    uint8 otherVehicleIdx;                      // Vehicle index of the other car involved
    uint8 time;                                 // Time gained, or time spent doing action in seconds
    uint8 lapNum;                               // Lap the penalty occurred on
    uint8 placesGained;                         // Number of places gained by this
};

struct SpeedTrap
{
    uint8 vehicleIdx;                           // Vehicle index of the vehicle triggering speed trap
    float speed;                                // Top speed achieved in kilometres per hour
    uint8 isOverallFastestInSession;            // Overall fastest speed in session = 1, otherwise 0
    uint8 isDriverFastestInSession;             // Fastest speed for driver in session = 1, otherwise 0
    uint8 fastestVehicleIdxInSession;           // Vehicle index of the vehicle that is the fastest
                                                // in this session
    float fastestSpeedInSession;                // Speed of the vehicle that is the fastest
                                                // in this session
};

struct StartLIghts
{
    uint8 numLights;                            // Number of lights showing
};

struct DriveThroughPenaltyServed
{
    uint8 vehicleIdx;                           // Vehicle index of the vehicle serving drive through
};

struct StopGoPenaltyServed
{
    uint8 vehicleIdx;                           // Vehicle index of the vehicle serving stop go
};

struct Flashback
{
    uint32 flashbackFrameIdentifier;            // Frame identifier flashed back to
    float flashbackSessionTime;                 // Session time flashed back to
};

struct Buttons
{
    uint32         m_buttonStatus;              // Bit flags specifying which buttons are being pressed
                                                // currently - see appendices
};

union EventDataDetails
{
    struct FastestLap m_fastestLap;
    struct Retirement m_retirement;
    struct TeamMateInPits m_teamMateInPits;
    struct RaceWinner m_raceWinner;
    struct Penalty m_penalty;
    struct SpeedTrap m_speedTrap;
    struct StartLIghts m_startLIghts;
    struct DriveThroughPenaltyServed m_driveThroughPenaltyServed;
    struct StopGoPenaltyServed m_stopGoPenaltyServed;
    struct Flashback m_flashback;
    struct Buttons m_buttons;
};
