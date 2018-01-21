/************************************************************
* Version: FaceTrack_code_v0.0.0.171030
* CopyRight: ?????????????????????
* UpdateDate: 20171030
* Content:
************************************************************/

#ifndef FACETRACKAPI_H_
#define FACETRACKAPI_H_

#ifdef _MSC_VER
#ifdef FACETRACK_EXPORTS
#define FACETRACK_API __declspec(dllexport)
#else
#define FACETRACK_API __declspec(dllimport)
#endif
#else
#define FACETRACK_API __attribute__ ((visibility ("default")))
#include <stdlib.h>
#endif


#ifdef __cplusplus
extern "C"
{
#endif


/*************************************************************************
* FUNCTION: starRecognition
* PURPOSE: ???
* PARAM:
[in] filePathName		- ????
[in] resultBuf			- ???? ????? ????????
[in] bufLen				- in?????? out????????
[in] conThre			- ???? ??????????null
* RETURN:	handle
* NOTES:
*************************************************************************/
FACETRACK_API int starRecognitionEx(char * filePathName, char * resultBuf, size_t * bufLen, float conThre, const char* snapDir);

#ifdef SAVE_PIC
#define starRecognition(filePathName, resultBuf, bufLen, conThre) \
	starRecognitionEx(filePathName, resultBuf, bufLen, conThre, "pic")
#else
#define starRecognition(filePathName, resultBuf, bufLen, conThre) \
	starRecognitionEx(filePathName, resultBuf, bufLen, conThre,  NULL)
#endif



#ifdef __cplusplus
};
#endif

#endif

