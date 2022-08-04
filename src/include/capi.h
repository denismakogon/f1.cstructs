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

#include "2022/PacketHeader.h"
#include "2022/CarDamageData.h"
#include "2022/CarMotionData.h"
#include "2022/CarSetupData.h"
#include "2022/CarStatusData.h"
#include "2022/CarTelemetryData.h"
#include "2022/EventDataDetails.h"
#include "2022/FinalClassificationData.h"
#include "2022/LapData.h"
#include "2022/LapHistoryData.h"
#include "2022/LobbyInfoData.h"
#include "2022/MarshalZone.h"
#include "2022/PacketCarDamageData.h"
#include "2022/PacketCarSetupData.h"
#include "2022/PacketCarStatusData.h"
#include "2022/PacketCarTelemetryData.h"
#include "2022/PacketEventData.h"
#include "2022/PacketFinalClassificationData.h"
#include "2022/PacketLapData.h"
#include "2022/PacketLobbyInfoData.h"
#include "2022/PacketMotionData.h"
#include "2022/ParticipantData.h"
#include "2022/PacketParticipantsData.h"
#include "2022/WeatherForecastSample.h"
#include "2022/PacketSessionData.h"
#include "2022/TyreStintHistoryData.h"
#include "2022/PacketSessionHistoryData.h"

#ifdef __cplusplus
}
#endif

#endif /* capi_h */
