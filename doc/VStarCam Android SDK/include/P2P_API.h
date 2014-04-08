
#include "P2P_API_Define.h"
#include "P2P_API_ERR.h"

#ifndef _P2P_API_H_
#define _P2P_API_H_

#ifdef WIN32_STATIC
#define P2P_API 
#else

#if WIN32_DLL
#ifndef P2P_API_EXPORT
#define P2P_API __declspec(dllimport)
#else
#define P2P_API __declspec(dllexport)
#endif
#endif

#endif

#if ANDROID_LIB || IOS_LIB
#define P2P_API
#endif

#ifdef __cplusplus
extern "C"
{
#endif

    P2P_API long P2PAPI_InitialWithServer(char *svr);
    P2P_API long P2PAPI_Initial();
    P2P_API long P2PAPI_DeInitial();
    P2P_API long P2PAPI_GetAPIVersion();
    P2P_API long P2PAPI_CreateInstance(long *nHandle);
    P2P_API long P2PAPI_DestroyInstance(long nHandle);
    P2P_API long P2PAPI_DestroyAllInstance();
    P2P_API long P2PAPI_Connect(long nHandle, char *uid, char *user, char *pwd);
    P2P_API long P2PAPI_Close(long nHandle);
    P2P_API long P2PAPI_CloseAll();
    P2P_API long P2PAPI_StartVideo(long nHandle);
    P2P_API long P2PAPI_StopVideo(long nHandle);
    P2P_API long P2PAPI_StartAudio(long nHandle);
    P2P_API long P2PAPI_StopAudio(long nHandle);
    P2P_API long P2PAPI_StartTalk(long nHandle);
    P2P_API long P2PAPI_StopTalk(long nHandle);
    P2P_API long P2PAPI_TalkData(long nHandle, char *pData, int len);
    P2P_API long P2PAPI_SendMessage(long nHandle, int type, char *msg, int len);
    P2P_API long P2PAPI_SetAVDataCallBack(long nHandle, AVDataCallback AVCallback, void *pParam);
    P2P_API long P2PAPI_SetMessageCallBack(long nHandle, MessageCallback MsgCallback, void *pParam);
    P2P_API long P2PAPI_SetPlaybackAVDataCallBack(long nHandle, AVDataCallback AVCallback, void *pParam);

#ifdef __cplusplus
}
#endif


#endif