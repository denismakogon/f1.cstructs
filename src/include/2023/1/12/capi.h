//
//  capi.h
//  src
//
//  Created by Denis Makogon on 28.09.2023.
//

#ifndef _capi_h
#define _capi_h

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(1)

#include "ctypedefs.h"

#include "PacketHeader.h"

// generated with: ls -la | awk '{print "#include " "\""$NF"\""}'
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
#include "PacketMotionExData.h"
#include "ParticipantData.h"
#include "PacketParticipantsData.h"
#include "WeatherForecastSample.h"
#include "PacketSessionData.h"
#include "TyreStintHistoryData.h"
#include "PacketSessionHistoryData.h"
#include "TyreSetData.h"
#include "PacketTyreSetsData.h"


#ifdef __cplusplus
}
#endif

#endif /* _capi_h */
