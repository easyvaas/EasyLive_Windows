#pragma once
#include <windows.h>
#include <vector>
#include <map>
#include "EVDefs.h"

#define EV_WINDOW_CLASS         TEXT("EasyVideoWindowClass")
#define EV_VIDEO_CLASS			TEXT("EV_VIDEO_CLASS")

#define MONITOR_CAPTURE			"MonitorCaptureSource"
#define WINDOW_CAPTURE			"WindowCaptureSource"
#define DEVICE_CAPTURE			"DeviceCapture"
#define BITMAP_IMAGESOURCE		"BitmapImageSource"
#define GRAPHICS_CAPTURE		"GraphicsCapture"
#define TEXT_SOURCE				"TextSource"

#define MAX_GAMEOPTS_COUNT		100

enum
{
	OBS_REQUESTSTOP = WM_USER + 1,
	OBS_CALLHOTKEY,
	OBS_RECONNECT,
	OBS_SETSCENE,
	OBS_SETSOURCEORDER,
	OBS_SETSOURCERENDER,
	OBS_UPDATESTATUSBAR,
	OBS_NOTIFICATIONAREA,
	OBS_NETWORK_FAILED,
	OBS_CONFIGURE_STREAM_BUTTONS,

	WM_VEDIOWND_LBUTTONDOWN,					// ��Ƶ��ʾ����-ldown;
	WM_VEDIOWND_RBUTTONDOWN,					// ��Ƶ��ʾ����-lup;
	WM_VEDIOWND_LBUTTONUP,						// ��Ƶ��ʾ����-rdown;
	WM_VEDIOWND_RBUTTONUP,						// ��Ƶ��ʾ����-rup;

	WM_GRAPHNOTIFY = WM_USER + 1200,			// dshow��Ƶ�ɼ���Ϣ;
	WM_RTMP_CONSTRAINED_UNCOMFORTABLE,			// ֱ������������΢;
	WM_RTMP_CONSTRAINED_DIFFICULT,				// ֱ��������������;
	WM_RTMP_CONSTRAINED_ABORT,					// ֱ�����������ر�;
	WM_RTMP_CONSTRAINED_SMOOTH,					// ֱ������ͨ��;
	WM_RTMP_TIME_DIFF_50_200,					// ֱ�����绺���ӳ� < 200ms;
	WM_RTMP_TIME_DIFF_1S_2S,					// ֱ�����绺���ӳ� > 1s;
	WM_RTMP_TIME_DIFF_2S_4S,					// ֱ�����绺���ӳ� > 2s;
	WM_RTMP_TIME_DIFF_4S_9S,					// ֱ�����绺���ӳ� > 4s;
	WM_RTMP_TIME_DIFF_9S_15S,					// ֱ�����绺���ӳ� > 9s;
	WM_RTMP_TIME_DIFF_15S_30S,					// ֱ�����绺���ӳ� > 15s;
	WM_RTMP_TIME_DIFF_30S_MAX,					// ֱ�����绺���ӳ� > 30s;
};

class SceneInfo
{
public:
	SceneInfo(){};
	virtual ~SceneInfo(){};
};

class GameInfo : public SceneInfo
{
// ��ϷԴ��Ϣ;
public:
	GameInfo()
	{
		strcpy_s(strTitle, "");
		strcpy_s(strClass, "");
		strcpy_s(strExePath, "");
		strcpy_s(strExeFile, "");
	}
	char	strTitle[255];				// ���ڱ���;
	char	strClass[255];				// ��������;
	HWND	hWnd;						// ���ھ��;
	char	strExePath[255];			// ����·��;
	char	strExeFile[255];			// �����ļ�;
};

class MonitorsInfo : public SceneInfo
{
	// ������Ϣ;
public:
	RECT rectMonitors;
};

class WindowsInfo : public SceneInfo
{
	// ������Ϣ;
public:
	WindowsInfo()
	{
		strcpy_s(strTitle, "");
		strcpy_s(strClass, "");
		strcpy_s(strExePath, "");
		strcpy_s(strExeFile, "");
	}
	WindowsInfo(const GameInfo& infoGame)
	{
		strcpy_s(strTitle, infoGame.strTitle);
		strcpy_s(strClass, infoGame.strClass);
		strcpy_s(strExePath, infoGame.strExePath);
		strcpy_s(strExeFile, infoGame.strExeFile);
		hWnd = infoGame.hWnd;
	}
	char	strTitle[255];				// ���ڱ���;
	char	strClass[255];				// ��������;
	HWND	hWnd;						// ���ھ��;
	char	strExePath[255];			// ����·��;
	char	strExeFile[255];			// �����ļ�;

	//int		i
};

class TextInfo : public SceneInfo
{// �ı�Դ��Ϣ;
public:
	TextInfo()
	{
		strcpy_s(strContent, "");
		strcpy_s(strFontName, "΢���ź�");
		dwFontColor = 0xFF000000;
		iBold = 0;
		iItalic = 0;
		iUnderLine = 0;
		iVer = 0;
		iScrollSpeed = 0;

		iOutLineUsed = 0;
		dwOutLineColor = 0xFF000000;
		iOutLineSize = 0;
		iOutlineOpacity = 100;
	}

	char strContent[1000];		// �ı�����;
	char strFontName[100];		// �ı�����;
	DWORD dwFontColor;			// �ı���ɫ;
	int iBold;					// ����;
	int iItalic;				// б��;
	int iUnderLine;				// �»���;
	int iVer;					// ��ֱ��ʾ;
	int iScrollSpeed;			// �ı������ٶ�;

	int iOutLineUsed;			// �ı���߿�����;
	DWORD dwOutLineColor;		// �ı���߿���ɫ;
	int iOutLineSize;			// �ı���߿���;
	int iOutlineOpacity;		// �ı���߿�͸����;
};

class CameraInfo : public SceneInfo
{// ����ͷ��Ϣ;
public:
	CameraInfo()
	{
		iWidth = 1280;
		iHeight = 720;
		iFlipType = 0;

		iCustomSet = 0;
		iFps = 25;
		strcpy_s(strOutForm, "I420");
	}

	char strVideoName[255];		//	��Ƶ�豸����;
	char strVideoID[255];		//	��Ƶ�豸ID;
	char strAudioName[255];		//	��Ƶ�豸����;
	char strAudioID[255];		//	��Ƶ�豸ID;
	int iWidth;					//	�ֱ���-x;
	int iHeight;				//	�ֱ���-y;
	int iFlipType;				//	��ת����;

	int iCustomSet;				//	�Զ�������;
	int iFps;					//	֡��;
	char strOutForm[100];		//	�����ʽ;
};

class ImageInfo : public SceneInfo
{// ͼƬԴ��Ϣ;
public:
	ImageInfo()
	{
		iAlpha = 0;
	}

	char strPath[255];			// ͼƬ·��;
	int iAlpha;					// ͼƬ��͸����;
};

// ��Ƶ������;
class EVStreamerParameter
{
public:
	EVStreamerParameter()
	{
		frameRate = 15;
		maxVideoBitrate = 500;
		videoResolutionWidth = 1920;
		videoResolutionHeight = 1080;
		iFrameInterval = 75;
	}

	int frameRate;					// ����֡��fps��Ĭ��15
	int maxVideoBitrate;			// ��Ƶ��ʼ�����ʣ�Ĭ��500kbps
	int videoResolutionWidth;		// ��Ƶ����ֱ��ʣ�Ĭ��Ϊ1280���ɶ���Ϊö�ٻ���(0-360x640, 1-540x960, 2-720x1280)
	int videoResolutionHeight;		// ��Ƶ����ֱ��ʣ�Ĭ��Ϊ720���ɶ���Ϊö�ٻ���(0-360x640, 1-540x960, 2-720x1280)
	int iFrameInterval;				// i֡���
};

enum EFlipType
{
	// ��ת����;
	FLIPTYPE_NONE = 0x0000,		// �����޷�ת;
	FLIPTYPE_HOR = 0x0001,		// ˮƽ��ת;
	FLIPTYPE_VER = 0x0002		// ��ֱ��ת;
};

class DevicesInfo
{
public:
	DevicesInfo()
	{
		strcpy_s(strDevName, "");
		strcpy_s(strDevID, "");
	}
	char strDevName[255];
	char strDevID[255];
};