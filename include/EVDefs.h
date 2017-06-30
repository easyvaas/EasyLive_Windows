#pragma once

#define MAX_GAMEOPTS_COUNT	100

enum LIVESUPPORT
{
	LIVE_RTMP_PUSHE = 1,
	LIVE_RTMP_PULLE = 2,
	LIVE_HTTP_FLVE = 3,
	LIVE_HTTP_HLSE = 4
};

enum VODSUPPORT
{
	VOD_HTTP_MP4E = 1,
	VOD_HTTP_TSE = 2,
	VOD_HTTP_FLVE = 3,
	VOD_HTTP_HLSE = 4,
};

enum PROTOTYPE
{
	UNKNOWN_PROTOE = -1,
	HTTP302E = 0,
	HTTP200E = 1,
	HTTP200JSONE = 2,
};

enum SceneItemsState
{
	SceneItemsState_MoveUp = 0,			// ����;
	SceneItemsState_MoveDown,			// ����;
	SceneItemsState_MoveToTop,			// �ö�;
	SceneItemsState_MoveToBottom,		// �õ�;
	SceneItemsState_MoveToFull,			// ȫ��;
};

namespace MessageError
{
	#define EV_NETWORK_ERROR_TIMEOUT			( -1001 )	// ������������ӳ�ʱ
	#define EV_NETWORK_ERROR_INVALID_URL		( -1002 )	// ���������url��ַ����
	#define EV_NETWORK_ERROR_NOT_CONNECT		( -1003 )	// ���������δ����
	#define EV_NETWORK_ERROR_UNKNOWN			( -1101 )	// δ֪�������
	#define EV_MESSAGE_ERROR_SDK_INIT			( -2001 )	// sdkδ��ʼ�����ʼ�����ɹ�
	#define EV_MESSAGE_ERROR_INTERNAL_SERVER	( -3001 )	// ��Ϣ�������ڲ�����
	#define EV_MESSAGE_ERROR_PERMISSION_DENIED	( -3002 )	// û��Ȩ��
	#define EV_MESSAGE_ERROR_JOIN_TOPIC			( -3003 )	// ����topicʧ��
	#define EV_MESSAGE_ERROR_SEND				( -3004 )	// ����ʧ��
	#define EV_MESSAGE_ERROR_SHUTUPED			( -3005 )	// ������
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum EV_RENDER_MODE_TYPE
{
	EV_RENDER_MODE_HIDDEN = 1,
	EV_RENDER_MODE_FIT = 2,
	EV_RENDER_MODE_ADAPTIVE = 3,
};

struct EVVideoCanvas
{
	void* view;
	int renderMode;
	unsigned int uid;
	void *priv; // private data (underlying video engine denotes it)

	EVVideoCanvas()
		: view(NULL)
		, renderMode(EV_RENDER_MODE_HIDDEN)
		, uid(0)
		, priv(NULL)
	{}

	EVVideoCanvas(void* v, int m, unsigned int u)
		: view(v)
		, renderMode(m)
		, uid(u)
		, priv(NULL)
	{}
};

enum EV_CHANNEL_PROFILE_TYPE
{
	EV_CHANNEL_PROFILE_COMMUNICATION = 0,
	EV_CHANNEL_PROFILE_LIVE_BROADCASTING = 1,
};

enum EV_CLIENT_ROLE_TYPE
{
	EV_CLIENT_ROLE_BROADCASTER = 1,
	EV_CLIENT_ROLE_AUDIENCE = 2,
};

enum EV_VIDEO_PROFILE_TYPE
{
												// res       fps  kbps
	EV_VIDEO_PROFILE_120P		= 0,			// 160x120   15   65
	EV_VIDEO_PROFILE_120P_3		= 2,			// 120x120   15   50
	EV_VIDEO_PROFILE_180P		= 10,			// 320x180   15   140
	EV_VIDEO_PROFILE_180P_3		= 12,			// 180x180   15   100
	EV_VIDEO_PROFILE_180P_4		= 13,			// 240x180   15   120
	EV_VIDEO_PROFILE_240P		= 20,			// 320x240   15   200
	EV_VIDEO_PROFILE_240P_3		= 22,			// 240x240   15   140
	EV_VIDEO_PROFILE_240P_4		= 23,			// 424x240   15   220
	EV_VIDEO_PROFILE_360P		= 30,			// 640x360   15   400
	EV_VIDEO_PROFILE_360P_3		= 32,			// 360x360   15   260
	EV_VIDEO_PROFILE_360P_4		= 33,			// 640x360   30   600
	EV_VIDEO_PROFILE_360P_6		= 35,			// 360x360   30   400
	EV_VIDEO_PROFILE_360P_7		= 36,			// 480x360   15   320
	EV_VIDEO_PROFILE_360P_8		= 37,			// 480x360   30   490
	EV_VIDEO_PROFILE_360P_9		= 38,			// 640x360   15   800
	EV_VIDEO_PROFILE_480P		= 40,			// 640x480   15   500
	EV_VIDEO_PROFILE_480P_3		= 42,			// 480x480   15   400
	EV_VIDEO_PROFILE_480P_4		= 43,			// 640x480   30   750
	EV_VIDEO_PROFILE_480P_6		= 45,			// 480x480   30   600
	EV_VIDEO_PROFILE_480P_8		= 47,			// 848x480   15   610
	EV_VIDEO_PROFILE_480P_9		= 48,			// 848x480   30   930
	EV_VIDEO_PROFILE_720P		= 50,			// 1280x720  15   1130
	EV_VIDEO_PROFILE_720P_3		= 52,			// 1280x720  30   1710
	EV_VIDEO_PROFILE_720P_5		= 54,			// 960x720   15   910
	EV_VIDEO_PROFILE_720P_6		= 55,			// 960x720   30   1380
	EV_VIDEO_PROFILE_1080P		= 60,			// 1920x1080 15   2080
	EV_VIDEO_PROFILE_1080P_3	= 62,			// 1920x1080 30   3150
	EV_VIDEO_PROFILE_1080P_5	= 64,			// 1920x1080 60   4780
	EV_VIDEO_PROFILE_1440P		= 66,			// 2560x1440 30   4850
	EV_VIDEO_PROFILE_1440P_2	= 67,			// 2560x1440 60   7350
	EV_VIDEO_PROFILE_4K			= 70,			// 3840x2160 30   8910
	EV_VIDEO_PROFILE_4K_3		= 72,			// 3840x2160 60   13500
	EV_VIDEO_PROFILE_DEFAULT	= EV_VIDEO_PROFILE_360P,
};

struct EVAudioVolumeInfo
{
	unsigned int uid;
	unsigned int volume; // [0,255]
};

struct EVRtcStats
{
	unsigned int duration;
	unsigned int txBytes;
	unsigned int rxBytes;
	unsigned short txKBitRate;
	unsigned short rxKBitRate;

	unsigned short rxAudioKBitRate;
	unsigned short txAudioKBitRate;

	unsigned short rxVideoKBitRate;
	unsigned short txVideoKBitRate;
	unsigned int users;
	double cpuAppUsage;
	double cpuTotalUsage;
};

enum EV_USER_OFFLINE_REASON_TYPE
{
	EV_USER_OFFLINE_QUIT = 0,
	EV_USER_OFFLINE_DROPPED = 1,
};

struct EVLocalVideoStats
{
	int sentBitrate;
	int sentFrameRate;
};

enum EV_REMOTE_VIDEO_STREAM_TYPE
{
	EV_REMOTE_VIDEO_STREAM_UNKNOWN = -1,
	EV_REMOTE_VIDEO_STREAM_HIGH		= 0,
	EV_REMOTE_VIDEO_STREAM_LOW		= 1,
	EV_REMOTE_VIDEO_STREAM_MEDIUM	= 2,
};

struct EVRemoteVideoStats
{
	unsigned short uid;
	int delay;
	int width;
	int height;
	int receivedBitrate;
	int receivedFrameRate;
	EV_REMOTE_VIDEO_STREAM_TYPE rxStreamType;
};
