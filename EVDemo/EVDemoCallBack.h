#pragma once
#include "EVLiveCallBack.h"

enum
{
	WM_INITSDK_CALLBACK = WM_USER + 1300,		// ��ʼ��SDK;
	WM_INITINSTANCE_CALLBACK,					// ��ʼ��Instance;
	WM_INITVIDEOWND_CALLBACK,					// ��ʼ����Ƶ����;
	WM_PREPARESTREAM_CALLBACK,					// ׼������;

	WM_ADDGAME_CALLBACK,						// �����ϷԴ;
	WM_MODIFYGAME_CALLBACK,						// �༭��ϷԴ;
	WM_ADDMONITOR_CALLBACK,						// ��ӽ���;
	WM_ADDTEXT_CALLBACK,						// ����ı�Դ;
	WM_MODIFYTEXT_CALLBACK,						// �༭�ı�Դ;
	WM_ADDIMAGE_CALLBACK,						// ���ͼƬԴ;
	WM_MODIFYIMAGE_CALLBACK,					// �༭ͼƬԴ;
	WM_ADDCAMERA_CALLBACK,						// �������ͷ;
	WM_MODIFYCAMERA_CALLBACK,					// �༭����ͷ;

	WM_MESSAGE_CONNECT = WM_USER + 1400,		// ��Ϣϵͳ����;
	WM_MESSAGE_DISCONNECT,						// ��Ϣϵͳ�Ͽ�;

	WM_STREAM_STOP = WM_USER + 1500
};

class CEVDemoCallBack : public CEVLiveCallBack
{
public:
	CEVDemoCallBack();
	virtual ~CEVDemoCallBack();

public:

	// ��ʼ��SDK--�ص�;
	virtual void InitSDK_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

	// ��ʼ��OBS--�ص�;
	virtual void InitInstance_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

	// ����ֱ����Ƶ����--�ص�;
	virtual void SetParameter_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

	// ��ȡֱ����Ƶ����--�ص�;
	virtual void GetParameter_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

	// ��ʼ����Ƶ����--�ص�;
	virtual void InitVideoWnd_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

	// ׼������--�ص�;
	// ʧ��ʱ,���ش�����Ϣ; �ɹ�ʱ,����������ַ;
	virtual void PrepareStream_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

	// ��ʼ����--�ص�;
	virtual void StartStream_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

	// ֹͣ����--�ص�;
	virtual void StopStream_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

	//	ѡ�г���Դ����--�ص�;
	virtual void SetSelItemState_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

	// ѡ�г���Դɾ��--�ص�;
	virtual void DeleteSelItem_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

	// ��ϷԴ: ��ȡ��ϷԴ�б�--�ص�;
	virtual void GetGameOptions_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

	// �������--�ص�;
	virtual void AddScene_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

	// �����༭--�ص�;
	virtual void ModifyScene_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

	// ��˷�����: ����--�ص�;
	virtual void SetMicropVolume_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

	// ��˷�����: ��ȡ--�ص�;
	virtual void GetMicropVolume_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

	// ������(����)����:����--�ص�;
	virtual void SetDesktopVolume_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

	// ������(����)����:��ȡ--�ص�;
	virtual void GetDesktopVolume_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

	// ��ȡ���õ���Ƶ�豸�б�--�ص�;
	virtual void GetVideoDevices_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

	// ��ȡ���õ���Ƶ�豸�б�--�ص�;
	virtual void GetAudioDevices_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

	// ��ȡѡ�еĳ���Դ����--�ص�;
	virtual void GetSelSceneClass_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

	// ��ȡѡ�еĳ���Դ��Ϣ--�ص�;
	virtual void GetSelSceneInfo_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ����ص�;

	virtual void onJoinChannelSuccess(const char* channel, unsigned int uid, int elapsed);
	virtual void onRejoinChannelSuccess(const char* channel, unsigned int uid, int elapsed);
	virtual void onWarning(int warn, const char* msg);
	virtual void onError(int err, const char* msg);
	virtual void onAudioQuality(unsigned int uid, int quality, unsigned short delay, unsigned short lost);
	virtual void onAudioVolumeIndication(const EVAudioVolumeInfo* speakers, unsigned int speakerNumber, int totalVolume);

	virtual void onLeaveChannel(const EVRtcStats& stat);
	virtual void onRtcStats(const EVRtcStats& stat);
	virtual void onMediaEngineEvent(int evt);

	virtual void onAudioDeviceStateChanged(const char* deviceId, int deviceType, int deviceState);
	virtual void onVideoDeviceStateChanged(const char* deviceId, int deviceType, int deviceState);

	virtual void onLastmileQuality(int quality);
	virtual void onFirstLocalVideoFrame(int width, int height, int elapsed);
	virtual void onFirstRemoteVideoDecoded(unsigned int uid, int width, int height, int elapsed);
	virtual void onFirstRemoteVideoFrame(unsigned int uid, int width, int height, int elapsed);
	virtual void onUserJoined(unsigned int uid, int elapsed);
	virtual void onUserOffline(unsigned int uid, EV_USER_OFFLINE_REASON_TYPE reason);
	virtual void onUserMuteAudio(unsigned int uid, bool muted);
	virtual void onUserMuteVideo(unsigned int uid, bool muted);
	virtual void onApiCallExecuted(const char* api, int error);

	virtual void onLocalVideoStats(const EVLocalVideoStats& stats);
	virtual void onRemoteVideoStats(const EVRemoteVideoStats& stats);
	virtual void onCameraReady();
	virtual void onVideoStopped();
	virtual void onConnectionLost();
	virtual void onConnectionInterrupted();

	virtual void onUserEnableVideo(unsigned int uid, bool enabled);

	virtual void onStartRecordingService(int error);
	virtual void onStopRecordingService(int error);
	virtual void onRefreshRecordingServiceStatus(int status);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// EVMessage

	virtual void onGetMessageServer(const char * serverIp, int serverPort, const char * handShakeKey);
	virtual void onConnectError(const char * errorInfo);
	virtual void onConnected();

	// ����topic�ɹ���content����Ϊjson�ַ���������˽�����ݡ��û��б���Ϣ���û��б�����Ա�б������б������б�;
	virtual void onJoinOK(const char * topic, const char ** users, int userNum,
		const char ** privateInfo, int privateInfoNum,
		const char ** managers, int managersNum,
		const char ** shutups, int shutupsNum,
		const char ** kickusers, int kickusersNum);
	// �뿪topic�ɹ���content����Ϊjson�ַ���������˽�����ݡ��û��б���Ϣ���û��б�����Ա�б������б������б�;
	virtual void onLeaveOK(const char * content, const char * topic);

	// messageΪjson��ʽ�ַ�����type�������ۿ�������ϵͳ��Ϣ�������Ļ��ֱ��״̬��������µ�;
	virtual void onNewMessage(const char * message, const char * topic, const char * userData, const char * userId);
	// �¼����û��б�;
	virtual void onUserJoin(char ** users, int num);
	// �뿪�û����б�;
	virtual void onUserLeave(char ** users, int num);
	// ������;
	virtual void onLikeCount(int likeCount);
	// ������;
	virtual void onCommentCount(int likeCount);
	// ������;
	virtual void onRiceRoll(int riceCount);
	// ���ڹۿ���;
	virtual void onWatchingCount(int watchingCount);
	// �ѹۿ���;
	virtual void onWatchedCount(int watchedCount);
	// �����б��������б�;
	virtual void onError(int errCode);
};