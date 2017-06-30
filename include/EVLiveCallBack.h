#pragma once
#include <windows.h>
#include "EVDefs.h"

#ifdef EVLIVE_EXPORTS
#define EVLIVE_API __declspec(dllexport)
#else
#define EVLIVE_API __declspec(dllimport)
#endif

class EVLIVE_API CEVLiveCallBack
{
public:
	CEVLiveCallBack();
	virtual ~CEVLiveCallBack();

	// ��ʼ��SDK--�ص�;
	virtual void InitSDK_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// ��ʼ��Instance--�ص�;
	virtual void InitInstance_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// ����ֱ����Ƶ����--�ص�;
	virtual void SetParameter_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// ��ȡֱ����Ƶ����--�ص�;
	virtual void GetParameter_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// ��ʼ����Ƶ����--�ص�;
	virtual void InitVideoWnd_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// ׼������--�ص�;
	// ʧ��ʱ,���ش�����Ϣ; �ɹ�ʱ,����������ַ;
	virtual void PrepareStream_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// ��ʼ����--�ص�;
	virtual void StartStream_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// ֹͣ����--�ص�;
	virtual void StopStream_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	//	ѡ�г���Դ����--�ص�;
	virtual void SetSelItemState_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// ѡ�г���Դɾ��--�ص�;
	virtual void DeleteSelItem_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// ��ϷԴ: ��ȡ��ϷԴ�б�--�ص�;
	virtual void GetGameOptions_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// �������--�ص�;
	virtual void AddScene_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// �����༭--�ص�;
	virtual void ModifyScene_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// ��˷�����: ����--�ص�;
	virtual void SetMicropVolume_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// ��˷�����: ��ȡ--�ص�;
	virtual void GetMicropVolume_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// ������(����)����:����--�ص�;
	virtual void SetDesktopVolume_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// ������(����)����:��ȡ--�ص�;
	virtual void GetDesktopVolume_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// ��ȡ���õ���Ƶ�豸�б�--�ص�;
	virtual void GetVideoDevices_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// ��ȡ���õ���Ƶ�豸�б�--�ص�;
	virtual void GetAudioDevices_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// ��ȡѡ�еĳ���Դ����--�ص�;
	virtual void GetSelSceneClass_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

	// ��ȡѡ�еĳ���Դ��Ϣ--�ص�;
	virtual void GetSelSceneInfo_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo) = 0;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ����ص�;

	virtual void onJoinChannelSuccess(const char* channel, unsigned int uid, int elapsed) = 0;
	virtual void onRejoinChannelSuccess(const char* channel, unsigned int uid, int elapsed) = 0;
	virtual void onWarning(int warn, const char* msg) = 0;
	virtual void onError(int err, const char* msg) = 0;
	virtual void onAudioQuality(unsigned int uid, int quality, unsigned short delay, unsigned short lost) = 0;
	virtual void onAudioVolumeIndication(const EVAudioVolumeInfo* speakers, unsigned int speakerNumber, int totalVolume) = 0;

	virtual void onLeaveChannel(const EVRtcStats& stat) = 0;
	virtual void onRtcStats(const EVRtcStats& stat) = 0;
	virtual void onMediaEngineEvent(int evt) = 0;

	virtual void onAudioDeviceStateChanged(const char* deviceId, int deviceType, int deviceState) = 0;
	virtual void onVideoDeviceStateChanged(const char* deviceId, int deviceType, int deviceState) = 0;

	virtual void onLastmileQuality(int quality) = 0;
	virtual void onFirstLocalVideoFrame(int width, int height, int elapsed) = 0;
	virtual void onFirstRemoteVideoDecoded(unsigned int uid, int width, int height, int elapsed) = 0;
	virtual void onFirstRemoteVideoFrame(unsigned int uid, int width, int height, int elapsed) = 0;
	virtual void onUserJoined(unsigned int uid, int elapsed) = 0;
	virtual void onUserOffline(unsigned int uid, EV_USER_OFFLINE_REASON_TYPE reason) = 0;
	virtual void onUserMuteAudio(unsigned int uid, bool muted) = 0;
	virtual void onUserMuteVideo(unsigned int uid, bool muted) = 0;
	virtual void onApiCallExecuted(const char* api, int error) = 0;

	virtual void onLocalVideoStats(const EVLocalVideoStats& stats) = 0;
	virtual void onRemoteVideoStats(const EVRemoteVideoStats& stats) = 0;
	virtual void onCameraReady() = 0;
	virtual void onVideoStopped() = 0;
	virtual void onConnectionLost() = 0;
	virtual void onConnectionInterrupted() = 0;

	virtual void onUserEnableVideo(unsigned int uid, bool enabled) = 0;

	virtual void onStartRecordingService(int error) = 0;
	virtual void onStopRecordingService(int error) = 0;
	virtual void onRefreshRecordingServiceStatus(int status) = 0;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// EVMessage

	virtual void onGetMessageServer(const char * serverIp, int serverPort, const char * handShakeKey) = 0;
	virtual void onConnectError(const char * errorInfo) = 0;
	virtual void onConnected() = 0;

	// ����topic�ɹ���content����Ϊjson�ַ���������˽�����ݡ��û��б���Ϣ���û��б�����Ա�б������б������б�;
	virtual void onJoinOK(const char * topic, const char ** users, int userNum,
		const char ** privateInfo, int privateInfoNum,
		const char ** managers, int managersNum,
		const char ** shutups, int shutupsNum,
		const char ** kickusers, int kickusersNum) = 0; 
	// �뿪topic�ɹ���content����Ϊjson�ַ���������˽�����ݡ��û��б���Ϣ���û��б�����Ա�б������б������б�;
	virtual void onLeaveOK(const char * content, const char * topic) = 0; 

	// messageΪjson��ʽ�ַ�����type�������ۿ�������ϵͳ��Ϣ�������Ļ��ֱ��״̬��������µ�;
	virtual void onNewMessage(const char * message, const char * topic, const char * userData, const char * userId) = 0;
	// �¼����û��б�;
	virtual void onUserJoin(char ** users, int num) = 0;
	// �뿪�û����б�;
	virtual void onUserLeave(char ** users, int num) = 0;
	// ������;
	virtual void onLikeCount(int likeCount) = 0;
	// ������;
	virtual void onCommentCount(int likeCount) = 0;
	// ������;
	virtual void onRiceRoll(int riceCount) = 0;
	// ���ڹۿ���;
	virtual void onWatchingCount(int watchingCount) = 0;
	// �ѹۿ���;
	virtual void onWatchedCount(int watchedCount) = 0; 
	// �����б��������б�;
	virtual void onError(int errCode) = 0;			
};