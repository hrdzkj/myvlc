// myvlc.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdio.h>  
#include <stdlib.h>  
#include <windows.h>  
#include <vlc\vlc.h>  

//#pragma comment(lib, "libvlc.lib")
//#pragma comment(lib, "libvlccore.lib")


int main() {

	libvlc_instance_t * inst;
	libvlc_media_player_t *mp;
	libvlc_media_t *m;

	inst = libvlc_new(0, NULL);//load the vlc engine  

	//m = libvlc_media_new_path(inst, VIDEO_PATH);//create a new item; xxx_path  
	m = libvlc_media_new_location(inst, "rtsp://184.72.239.149/vod/mp4://BigBuckBunny_175k.mov");
	mp = libvlc_media_player_new_from_media(m);//create a media player playing environment  
	libvlc_media_release(m);//no need to keey the media now  

	libvlc_media_player_play(mp);//play the media_player  
	Sleep(100 * 1000);//let it play a bit  

	libvlc_media_player_stop(mp);//stop playing  
	libvlc_media_player_release(mp);//free the media_player  
	libvlc_release(inst);

	return 0;
}