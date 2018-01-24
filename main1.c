#define _GLIBCXX_USE_CXX11_ABI 0
#include "FaceTrackAPI.h"
#include "SR.h"
#include <time.h>
#ifndef _MSC_VER
#include <stdlib.h>
#endif
#ifdef _MSC_VER
	#include <windows.h>
#else
	#include <string.h>
#endif
int if_star_init=1;
int if_scene_init=1;
int cas(int type, char * video_file_path);


int cas(int type, char * video_file_path)
{
	size_t buf_len = 10000000;
	char * result_buf = (char *)malloc(sizeof(char) * buf_len);


//	char * filename = "G://TestData//影谱明星人脸//楚乔传第一集.mp4";
	InitConfig iconfig;
	iconfig.gpuid = 0;	
	void *starHandle;
	void *sceneHandle;
	int status ;
	int init_status ;
	StarProcessConfig starProcessConfig;
	starProcessConfig.snapDir = "";
	starProcessConfig.conThre = 0.6;
	SceneProcessConfig sceneProcessConfig;
	sceneProcessConfig.conThre = 0.6;


    if(type==1)
    {
        if(if_star_init==1)
        {
            if(if_scene_init!=1)
            {
                if_scene_init=1;
                sceneReleaseResource(&sceneHandle);
            }
            init_status=starInit(&starHandle, initConfig);
            if_star_init=0;
            memset(result_buf, 0, sizeof(char) * buf_len);
            status=starRecognition(&starHandle,video_file_path,result_buf,&buf_len,starProcessConfig);
        }
        else
        {
            memset(result_buf, 0, sizeof(char) * buf_len);
            status=starRecognition(&starHandle,video_file_path,result_buf,&buf_len,starProcessConfig);
        }
    }
    else if(type==2)
    {
        if(if_scene_init==1)
        {
            if(if_star_init!=1)
            {
                if_star_init=1;
                starReleaseResource(&starHandle);
            }
            init_status=sceneInit(&sceneHandle, initConfig);
            if_scene_init=0;
            memset(result_buf, 0, sizeof(char) * buf_len);
            status=sceneRecognition(&sceneHandle,video_file_path,result_buf,&buf_len,sceneProcessConfig);
        }
        else
        {
            memset(result_buf, 0, sizeof(char) * buf_len);
            status=sceneRecognition(&sceneHandle,video_file_path,result_buf,&buf_len,sceneProcessConfig);
        }
    }



	free(result_buf);
	//cout << result_buf << endl;
	
#ifdef _MSVC_
	system("pause");
#endif


	return 0;
}

int main(){
    cas(1,'/home/cshen/Downloads/cyh5.mp4')
}
