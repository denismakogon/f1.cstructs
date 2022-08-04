#ifndef capi_h
#define capi_h

#include <stdlib.h>

typedef char int8;
typedef unsigned char uint8;
typedef short int16;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef long int64;
typedef unsigned long uint64;

#ifdef __cplusplus
extern "C" {
#endif

#include "PacketHeader.h"
#include "CarDamageData.h"
#include "CarMotionData.h"
#include "CarSetupData.h"
#include "CarStatusData.h"
#include "CarTelemetryData.h"
#include "EventDataDetails.h"
#include "FinalClassificationData.h"
#include "LapData.h"
#include "LapHistoryData.h"
#include "LobbyInfoData.h"
#include "MarshalZone.h"
#include "PacketCarDamageData.h"
#include "PacketCarSetupData.h"
#include "PacketCarStatusData.h"
#include "PacketCarTelemetryData.h"
#include "PacketEventData.h"
#include "PacketFinalClassificationData.h"
#include "PacketLapData.h"
#include "PacketLobbyInfoData.h"
#include "PacketMotionData.h"
#include "ParticipantData.h"
#include "PacketParticipantsData.h"
#include "WeatherForecastSample.h"
#include "PacketSessionData.h"
#include "TyreStintHistoryData.h"
#include "PacketSessionHistoryData.h"

#ifdef __cplusplus
}
#endif

#endif /* capi_h */
