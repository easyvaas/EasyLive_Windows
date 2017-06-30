#pragma once
#include "EVDefs.h"
#include "EVParameter.h"
#include "EVLiveCallBack.h"

// client ���ʵĳ�����;
class CEVLive
{
public:
	CEVLive(){};
	virtual ~CEVLive(){};

	/*-------------------------------------------------------------------------
	// ��ʼ��SDK: App����SDKǰ �����ȵ��ô˽ӿ�;
	//
	// strAppID:		AppID;
	// strAccessKey:	AccessKey;
	// strSecretKey:	SecretKey;
	// strUserData:		�û��Զ�����Ϣ;
	-------------------------------------------------------------------------*/
	virtual void InitSDK(IN char* strAppID, IN char* strAccessKey, IN char* strSecretKey, IN char* strUserData) = 0;

	/*-------------------------------------------------------------------------
	// ��ʼ��Instance(UI��ʾǰ�ȵ���);
	//
	// hMain:  ��������;
	-------------------------------------------------------------------------*/
	virtual void InitInstance(IN HINSTANCE hMain) = 0;

	/*-------------------------------------------------------------------------
	// ����ֱ����Ƶ����;
	//
	// streamPara:  ֱ������;
	-------------------------------------------------------------------------*/
	virtual void SetParameter(IN EVStreamerParameter& streamPara) = 0;

	/*-------------------------------------------------------------------------
	// ��ȡֱ����Ƶ����;
	//
	// streamPara:  ֱ������;
	-------------------------------------------------------------------------*/
	virtual void GetParameter(OUT EVStreamerParameter& streamPara) = 0;

	/*-------------------------------------------------------------------------
	// ��ʼ����Ƶ����;
	//
	// hMain:  �����ھ��;
	// hVideo: ��Ƶ���ھ��;
	// bRemember: �Ƿ�����ϴγ���Դ;
	-------------------------------------------------------------------------*/
	virtual void InitVideoWnd(HWND hMain, HWND hVideo, bool bRemember) = 0;

	/*-------------------------------------------------------------------------
	// ׼������;
	//
	// strLID
	// strKey
	-------------------------------------------------------------------------*/
	virtual void PrepareStream(IN const char* strLID, IN const char* strKey ) = 0;

	/*-------------------------------------------------------------------------
	// ��ʼ����;
	//
	-------------------------------------------------------------------------*/
	virtual void StartStream() = 0;

	/*-------------------------------------------------------------------------
	// ֹͣ����;
	//
	-------------------------------------------------------------------------*/
	virtual void StopStream() = 0;

	/*-------------------------------------------------------------------------
	//	ѡ�г���Դ����;

		SceneItemsState_MoveUp = 0,			// ����;
		SceneItemsState_MoveDown,			// ����;
		SceneItemsState_MoveToTop,			// �ö�;
		SceneItemsState_MoveToBottom,		// �õ�;
		SceneItemsState_MoveToFull,			// ȫ��;
	-------------------------------------------------------------------------*/
	virtual void SetSelItemState(SceneItemsState itemState) = 0;

	/*-------------------------------------------------------------------------
	// ѡ�г���Դ:ɾ��;
	//
	-------------------------------------------------------------------------*/
	virtual void DeleteSelItem() = 0;

	/*-------------------------------------------------------------------------
	// ��ϷԴ: ��ȡ��ϷԴ�б�;
	//
	// pGameOpts: ��ϷԴ����;
	// iCount: ��ϷԴ����;
	-------------------------------------------------------------------------*/
	virtual bool GetGameOptions(OUT GameInfo* pGameOpts, OUT int& iCount) = 0;

	/*-------------------------------------------------------------------------
	// �������;
	//
	// pSceneInfo: ������Ϣ;
	-------------------------------------------------------------------------*/
	virtual bool AddScene(IN SceneInfo* pSceneInfo) = 0;

	/*-------------------------------------------------------------------------
	// �����༭;
	//
	// pSceneInfo: ������Ϣ;
	-------------------------------------------------------------------------*/
	virtual bool ModifyScene(IN SceneInfo* pSceneInfo) = 0;

	/*-------------------------------------------------------------------------
	// ��˷�����: ����;
	//
	-------------------------------------------------------------------------*/
	virtual void SetMicropVolume(float fValue) = 0;

	/*-------------------------------------------------------------------------
	// ��˷�����: ��ȡ;
	//
	-------------------------------------------------------------------------*/
	virtual float GetMicropVolume() = 0;

	/*-------------------------------------------------------------------------
	// ������(����)����:����;
	//
	-------------------------------------------------------------------------*/
	virtual void SetDesktopVolume(float fValue) = 0;

	/*-------------------------------------------------------------------------
	// ������(����)����:��ȡ;
	//
	-------------------------------------------------------------------------*/
	virtual float GetDesktopVolume() = 0;

	/*-------------------------------------------------------------------------
	// ��ȡ���õ���Ƶ�豸�б�;
	//
	// pVideoDev: ��Ƶ�豸����;
	// iDevCount: ��Ƶ�豸����;
	-------------------------------------------------------------------------*/
	virtual bool GetVideoDevices(OUT DevicesInfo* pVideoDev, OUT int& iDevCount) = 0;

	/*-------------------------------------------------------------------------
	// ��ȡ���õ���Ƶ�豸�б�;
	//
	// pVideoDev: ��Ƶ�豸����;
	// iDevCount: ��Ƶ�豸����;
	-------------------------------------------------------------------------*/
	virtual bool GetAudioDevices(OUT DevicesInfo* pVideoDev, OUT int& iDevCount) = 0;

	/*-------------------------------------------------------------------------
	// ��ȡѡ�еĳ���Դ����;
	//
	// pClass: ����Դ����;
	-------------------------------------------------------------------------*/
	virtual bool GetSelSceneClass(OUT char* pClass) = 0;

	/*-------------------------------------------------------------------------
	// ��ȡѡ�еĳ���Դ��Ϣ;
	//
	// pScene: ����Դ��Ϣ;
	-------------------------------------------------------------------------*/
	virtual bool GetSelSceneInfo(OUT SceneInfo* pScene) = 0;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// EVAgora

	// ����Ƶ��(������Ƶ����ʹ��);
	virtual int JoinChannel(const char* lpChannelName, const char* info) = 0;

	// �뿪Ƶ��(������Ƶ����ʹ��);
	virtual int LeaveChannel() = 0;

	// ;
	virtual int renewChannelKey(const char* channelKey) = 0;

	// initialize the engine
	//virtual int initialize(const RtcEngineContext& context) = 0;

	// get the pointer of the device manager object.
	//virtual int queryInterface(INTERFACE_ID_TYPE iid, void** inter) = 0;

	// get the version information of the SDK
	//virtual const char* getVersion(int* build) = 0;

	// get the version information of the SDK
	//virtual const char* getErrorDescription(int code) = 0;

	virtual int SetChannelProfile(EV_CHANNEL_PROFILE_TYPE profile) = 0;
	virtual int SetClientRole(EV_CLIENT_ROLE_TYPE role, const char* permissionKey) = 0;

	virtual int SetVideoProfile(EV_VIDEO_PROFILE_TYPE profile, bool swapWidthAndHeight) = 0;

	// start the echo testing, if every thing goes well you can hear your echo from the server
	//virtual int startEchoTest() = 0;

	// stop the echo testing
	//virtual int stopEchoTest() = 0;

	// start/stop the network testing
	virtual int EnableLastmileTest(bool bEnable) = 0;

	// enable/disable local and remote video showing
	virtual int EnableVideo(bool bEnable) = 0;

	// enable/disable local and remote video showing
	virtual int EnableDauleStream(bool bEnable) = 0;

	// SetRemoteStreamType;
	virtual int SetRemoteStreamType(UINT nUID, EV_REMOTE_VIDEO_STREAM_TYPE nType) = 0;

	// start the local video previewing
	virtual int StartPreview() = 0;

	// StartScreenCapture
	virtual int StartScreenCapture(HWND hCaptureWnd) = 0;

	// stop the local video previewing
	virtual int StopPreview() = 0;

	// set the remote video canvas
	virtual int SetupRemoteVideo(const EVVideoCanvas& canvas) = 0;

	// set the local video canvas
	virtual int SetupLocalVideo(const EVVideoCanvas& canvas) = 0;

	// get self call id in the current channel
	//virtual int getCallId(char* callId) = 0;

	//virtual int rate(const char* callId, int rating, const char* description) = 0;
	//virtual int complain(const char* callId, const char* description) = 0;

	// register a packet observer while the packet arrived or ready to be sent, the observer can touch the packet data
	//virtual int registerPacketObserver(IPacketObserver* observer) = 0;

	// Specify encryption mode of AES encryption algorithm.
	//virtual int setEncryptionMode(const char* encryptionMode) = 0;

	// Specify encryption secret enables built-in encryption function. Leaving channel will clear the secret specified in last channel;
	//virtual int setEncryptionSecret(const char* secret) = 0;

	//virtual int createDataStream(int* streamId, bool reliable, bool ordered) = 0;
	//virtual int sendStreamMessage(int streamId, const char* data, size_t length) = 0;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// EVMessage

	virtual void Connect() = 0;
	virtual void Close() = 0;
	virtual void JoinTopic(char ** topicList, int topicNum) = 0;
	virtual void LeaveTopic(char ** topicList, int topicNum) = 0;
	virtual void Send(char * topic, char * msg, char * jsonString) = 0;
	virtual void AddLikeCount(char * topic, int count) = 0;
	virtual void SendMsgToUsers(char * topic, char * message, char ** userlist, int userNum) = 0;
	virtual void SetManager(char * topic, char * userdata, int period) = 0;
	virtual void DelManager(char * topic, char * userdata) = 0;
	virtual void SetShutup(char * topic, char * userdata, int period) = 0;
	virtual void DelShutup(char * topic, char * userdata) = 0;
	virtual void SetKickUser(char * topic, char * userdata, int period) = 0;
	virtual void DelKickUser(char * topic, char * userdata) = 0;
};

class EVLIVE_API CEVLiveFactory
{
public:
	// ����ʱ,��Ҫ���ݻص��ӿ�;
	static void CreateInstance(CEVLiveCallBack* pCallBack);

	// ��ȡ m_pInstance;
	static CEVLive* GetInstance();

	// �ͷ� m_pInstance;
	static void ReleaseInstance();

private:
	static CEVLive* m_pInstance;
};

#define AfxGetEVLive	CEVLiveFactory::GetInstance

// �ⲿ����ʾ���� AfxGetEVLive()->StartStream();