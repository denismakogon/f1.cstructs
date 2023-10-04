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
#include "CarMotionData.h"
#include "CarStatusData.h"
#include "EventDataDetails.h"
#include "LapData.h"
#include "LapHistoryData.h"
#include "LobbyInfoData.h"
#include "ParticipantData.h"
#include "TyreSetData.h"
#include "MarshalZone.h"
#include "WeatherForecastSample.h"

#include "PacketCarStatusData.h"
#include "PacketEventData.h"
#include "PacketLapData.h"
#include "PacketLobbyInfoData.h"
#include "PacketMotionData.h"
#include "PacketMotionExData.h"
#include "PacketParticipantsData.h"
#include "PacketSessionData.h"
#include "PacketTyreSetsData.h"
#include "PacketCarDamageData.h"
#include "PacketCarSetupData.h"
#include "PacketCarTelemetryData.h"
#include "PacketFinalClassificationData.h"
#include "PacketSessionHistoryData.h"

#ifdef __cplusplus
}
#endif

#endif /* _capi_h */
