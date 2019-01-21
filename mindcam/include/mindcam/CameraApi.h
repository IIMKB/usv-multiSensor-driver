#ifndef _MVCAMAPI_H_
#define _MVCAMAPI_H_

#define MVSDK_API

#ifdef __cplusplus
 extern "C" {
 #endif


#include "CameraDefine.h"
#include "CameraStatus.h"



/******************************************************/
// ������   : CameraSdkInit
// �������� : ���SDK��ʼ�����ڵ����κ�SDK�����ӿ�ǰ������
//        �ȵ��øýӿڽ��г�ʼ�����ú�����������������
//        �ڼ�ֻ��Ҫ����һ�Ρ�
// ����     : iLanguageSel ����ѡ��SDK�ڲ���ʾ��Ϣ�ͽ��������,
//               0:��ʾӢ��,1:��ʾ���ġ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus     CameraSdkInit(int     iLanguageSel);


/******************************************************/
// ������   : CameraUSBDeviceInit
// �������� :
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraUSBDeviceInit();

/******************************************************/
// ������   : CameraUSBDeviceUninit
// �������� :
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraUSBDeviceUninit();


/******************************************************/
// ������   : CameraEnumerateDevice
// �������� : ö���豸���������豸�б��ڵ���CameraInit
//        ֮ǰ��������øú���������豸����Ϣ��
// ����     : pCameraList    �豸�б�����ָ�롣
//             piNums        �豸�ĸ���ָ�룬����ʱ����pCameraList
//                            �����Ԫ�ظ�������������ʱ������ʵ���ҵ����豸������
//              ע�⣬piNumsָ���ֵ�����ʼ�����Ҳ�����pCameraList����Ԫ�ظ�����
//              �����п�������ڴ������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraEnumerateDevice(
    tSdkCameraDevInfo* pCameraList,
    INT*               piNums
);

/******************************************************/
// ������   : CameraIdleStateDevice
// �������� : ��ǰϵͳ��δʹ�õ������Ϣ��
// ����     : pCameraList    �豸�б�����ָ�롣
//             piNums        �豸�ĸ���ָ�룬����ʱ����pCameraList
//                            �����Ԫ�ظ�������������ʱ������ʵ���ҵ����豸������
//              ע�⣬piNumsָ���ֵ�����ʼ�����Ҳ�����pCameraList����Ԫ�ظ�����
//              �����п�������ڴ������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraIdleStateDevice(
    tSdkCameraDevInfo* pCameraList,
    INT*               piNums
);


/******************************************************/
// ������ 	: CameraEnumerateDeviceEx
// ��������	: ö���豸���������豸�б��ڵ���CameraInitEx
//			  ֮ǰ��������øú���ö���豸��
// ����	     :
// ����ֵ     : �����豸������0��ʾ�ޡ�
/******************************************************/
MVSDK_API INT  CameraEnumerateDeviceEx(
);


/******************************************************/
// ������   : CameraIsOpened
// �������� : ����豸�Ƿ��Ѿ�������Ӧ�ó���򿪡��ڵ���CameraInit
//        ֮ǰ������ʹ�øú������м�⣬����Ѿ����򿪣�����
//        CameraInit�᷵���豸�Ѿ����򿪵Ĵ����롣
// ����     : pCameraList �豸��ö����Ϣ�ṹ��ָ�룬��CameraEnumerateDevice��á�
//            pOpened       �豸��״ָ̬�룬�����豸�Ƿ񱻴򿪵�״̬��TRUEΪ�򿪣�FALSEΪ���С�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraIsOpened(
  tSdkCameraDevInfo*  pCameraList,
  BOOL*               pOpened
);


/******************************************************/
// ������   : CameraInit
// �������� : �����ʼ������ʼ���ɹ��󣬲��ܵ����κ�����
//        �����صĲ����ӿڡ�
// ����     : pCameraInfo    ��������豸������Ϣ����CameraEnumerateDevice
//               ������á�
//            iParamLoadMode  �����ʼ��ʱʹ�õĲ������ط�ʽ��-1��ʾʹ���ϴ��˳�ʱ�Ĳ������ط�ʽ��
//            emTeam         ��ʼ��ʱʹ�õĲ����顣-1��ʾ�����ϴ��˳�ʱ�Ĳ����顣
//            pCameraHandle  ����ľ��ָ�룬��ʼ���ɹ��󣬸�ָ��
//               ���ظ��������Ч������ڵ����������
//               ��صĲ����ӿ�ʱ������Ҫ����þ������Ҫ
//               ���ڶ����֮������֡�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraInit(
    tSdkCameraDevInfo*  pCameraInfo,
    int                 emParamLoadMode,
    int                 emTeam,
    CameraHandle*       pCameraHandle
);

/******************************************************/
// ������ 	: CameraInitEx
// ��������	: �����ʼ������ʼ���ɹ��󣬲��ܵ����κ�����
//			  �����صĲ����ӿڡ�
// ����	    : iDeviceIndex    ����������ţ�CameraEnumerateDeviceEx�������������
//            iParamLoadMode  �����ʼ��ʱʹ�õĲ������ط�ʽ��-1��ʾʹ���ϴ��˳�ʱ�Ĳ������ط�ʽ��
//            emTeam         ��ʼ��ʱʹ�õĲ����顣-1��ʾ�����ϴ��˳�ʱ�Ĳ����顣
//            pCameraHandle  ����ľ��ָ�룬��ʼ���ɹ��󣬸�ָ��
//							 ���ظ��������Ч������ڵ����������
//							 ��صĲ����ӿ�ʱ������Ҫ����þ������Ҫ
//							 ���ڶ����֮������֡�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraInitEx(
    int             iDeviceIndex,
    int             iParamLoadMode,
    int             emTeam,
    CameraHandle*   pCameraHandle
);


/******************************************************/
// ������   : CameraSetCallbackFunction
// �������� : ����ͼ�񲶻�Ļص��������������µ�ͼ������֡ʱ��
//        pCallBack��ָ��Ļص������ͻᱻ���á�
// ����     : hCamera ����ľ������CameraInit������á�
//            pCallBack �ص�����ָ�롣
//            pContext  �ص������ĸ��Ӳ������ڻص�����������ʱ
//            �ø��Ӳ����ᱻ���룬����ΪNULL��������
//            ������ʱЯ��������Ϣ��
//            pCallbackOld  ���ڱ��浱ǰ�Ļص�����������ΪNULL��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetCallbackFunction(
    CameraHandle        hCamera,
    CAMERA_SNAP_PROC    pCallBack,
    PVOID               pContext,
    CAMERA_SNAP_PROC*   pCallbackOld
);

/******************************************************/
// ������   : CameraUnInit
// �������� : �������ʼ�����ͷ���Դ��
// ����     : hCamera ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraUnInit(
    CameraHandle hCamera
);

/******************************************************/
// ������   : CameraGetInformation
// �������� : ��������������Ϣ
// ����     : hCamera ����ľ������CameraInit������á�
//            pbuffer ָ�����������Ϣָ���ָ�롣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetInformation(
    CameraHandle    hCamera,
    char**          pbuffer
);

/******************************************************/
// ������   : CameraImageProcess
// �������� : ����õ����ԭʼ���ͼ�����ݽ��д������ӱ��Ͷȡ�
//        ��ɫ�����У��������ȴ���Ч�������õ�RGB888
//        ��ʽ��ͼ�����ݡ�
// ����     : hCamera  ����ľ������CameraInit������á�
//            pbyIn    ����ͼ�����ݵĻ�������ַ������ΪNULL��
//            pbyOut   �����ͼ������Ļ�������ַ������ΪNULL��
//            pFrInfo  ����ͼ���֡ͷ��Ϣ��������ɺ�֡ͷ��Ϣ
//             �е�ͼ���ʽuiMediaType����֮�ı䡣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraImageProcess(
    CameraHandle        hCamera,
    BYTE*               pbyIn,
    BYTE*               pbyOut,
    tSdkFrameHead*      pFrInfo
);

/******************************************************/
// ������   : CameraDisplayInit
// �������� : ��ʼ��SDK�ڲ�����ʾģ�顣�ڵ���CameraDisplayRGB24
//        ǰ�����ȵ��øú�����ʼ����������ڶ��ο����У�
//        ʹ���Լ��ķ�ʽ����ͼ����ʾ(������CameraDisplayRGB24)��
//        ����Ҫ���ñ�������
// ����     : hCamera   ����ľ������CameraInit������á�
//            hWndDisplay ��ʾ���ڵľ����һ��Ϊ���ڵ�m_hWnd��Ա��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraDisplayInit(
    CameraHandle    hCamera,
    HWND            hWndDisplay
);

/******************************************************/
// ������   : CameraDisplayRGB24
// �������� : ��ʾͼ�񡣱�����ù�CameraDisplayInit����
//        ��ʼ�����ܵ��ñ�������
// ����     : hCamera  ����ľ������CameraInit������á�
//            pbyRGB24 ͼ������ݻ�������RGB888��ʽ��
//            pFrInfo  ͼ���֡ͷ��Ϣ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraDisplayRGB24(
    CameraHandle        hCamera,
    BYTE*               pbyRGB24,
    tSdkFrameHead*      pFrInfo
);

/******************************************************/
// ������   : CameraSetDisplayMode
// �������� : ������ʾ��ģʽ��������ù�CameraDisplayInit
//        ���г�ʼ�����ܵ��ñ�������
// ����     : hCamera  ����ľ������CameraInit������á�
//            iMode    ��ʾģʽ��DISPLAYMODE_SCALE����
//             DISPLAYMODE_REAL,����μ�CameraDefine.h
//             ��emSdkDisplayMode�Ķ��塣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetDisplayMode(
    CameraHandle    hCamera,
    INT             iMode
);

/******************************************************/
// ������   : CameraSetDisplayOffset
// �������� : ������ʾ����ʼƫ��ֵ��������ʾģʽΪDISPLAYMODE_REAL
//        ʱ��Ч��������ʾ�ؼ��Ĵ�СΪ320X240����ͼ���
//        �ĳߴ�Ϊ640X480����ô��iOffsetX = 160,iOffsetY = 120ʱ
//        ��ʾ���������ͼ��ľ���320X240��λ�á�������ù�
//        CameraDisplayInit���г�ʼ�����ܵ��ñ�������
// ����     : hCamera   ����ľ������CameraInit������á�
//            iOffsetX  ƫ�Ƶ�X���ꡣ
//            iOffsetY  ƫ�Ƶ�Y���ꡣ
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetDisplayOffset(
    CameraHandle    hCamera,
    int             iOffsetX,
    int             iOffsetY
);

/******************************************************/
// ������   : CameraSetDisplaySize
// �������� : ������ʾ�ؼ��ĳߴ硣������ù�
//        CameraDisplayInit���г�ʼ�����ܵ��ñ�������
// ����     : hCamera   ����ľ������CameraInit������á�
//            iWidth    ���
//            iHeight   �߶�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetDisplaySize(
    CameraHandle    hCamera,
    INT             iWidth,
    INT             iHeight
);

/******************************************************/
// ������   : CameraGetImageBuffer
// �������� : ���һ֡ͼ�����ݡ�Ϊ�����Ч�ʣ�SDK��ͼ��ץȡʱ�������㿽�����ƣ�
//        CameraGetImageBufferʵ�ʻ�����ں��е�һ����������ַ��
//        �ú����ɹ����ú󣬱������CameraReleaseImageBuffer�ͷ���
//        CameraGetImageBuffer�õ��Ļ�����,�Ա����ں˼���ʹ��
//        �û�������
// ����     : hCamera   ����ľ������CameraInit������á�
//            pFrameInfo  ͼ���֡ͷ��Ϣָ�롣
//            pbyBuffer   ָ��ͼ������ݵĻ�����ָ�롣����
//              �������㿽�����������Ч�ʣ����
//              ����ʹ����һ��ָ��ָ���ָ�롣
//            UINT wTimes ץȡͼ��ĳ�ʱʱ�䡣��λ���롣��
//              wTimesʱ���ڻ�δ���ͼ����ú���
//              �᷵�س�ʱ��Ϣ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetImageBuffer(
    CameraHandle        hCamera,
    tSdkFrameHead*      pFrameInfo,
    BYTE**              pbyBuffer,
    UINT                wTimes
);

/******************************************************/
// ������ 	: CameraGetImageBufferEx
// ��������	: ���һ֡ͼ�����ݡ��ýӿڻ�õ�ͼ���Ǿ���������RGB��ʽ���ú������ú�
//			  ����Ҫ���� CameraReleaseImageBuffer �ͷţ�Ҳ��Ҫ����free֮��ĺ����ͷ�
//              ���ͷŸú������ص�ͼ�����ݻ�������
// ����	    : hCamera	  ����ľ������CameraInit������á�
//            piWidth    ����ָ�룬����ͼ��Ŀ��
//            piHeight   ����ָ�룬����ͼ��ĸ߶�
//            UINT wTimes ץȡͼ��ĳ�ʱʱ�䡣��λ���롣��
//						  wTimesʱ���ڻ�δ���ͼ����ú���
//						  �᷵�س�ʱ��Ϣ��
// ����ֵ   : �ɹ�ʱ������RGB���ݻ��������׵�ַ;
//            ���򷵻�0��
/******************************************************/
MVSDK_API unsigned char*  CameraGetImageBufferEx(
    CameraHandle        hCamera,
    INT*                piWidth,
    INT*                piHeight,
    UINT                wTimes
);


/******************************************************/
// ������   : CameraSnapToBuffer
// �������� : ץ��һ��ͼ�񵽻������С���������ץ��ģʽ������
//        �Զ��л���ץ��ģʽ�ķֱ��ʽ���ͼ�񲶻�Ȼ��
//        ���񵽵����ݱ��浽�������С�
//        �ú����ɹ����ú󣬱������CameraReleaseImageBuffer
//        �ͷ���CameraSnapToBuffer�õ��Ļ�������������ο�
//        CameraGetImageBuffer�����Ĺ����������֡�
// ����     : hCamera   ����ľ������CameraInit������á�
//            pFrameInfo  ָ�룬����ͼ���֡ͷ��Ϣ��
//            pbyBuffer   ָ��ָ���ָ�룬��������ͼ�񻺳����ĵ�ַ��
//            uWaitTimeMs ��ʱʱ�䣬��λ���롣�ڸ�ʱ���ڣ������Ȼû��
//              �ɹ���������ݣ��򷵻س�ʱ��Ϣ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSnapToBuffer(
    CameraHandle        hCamera,
    tSdkFrameHead*      pFrameInfo,
    BYTE**              pbyBuffer,
    UINT                uWaitTimeMs
);

/******************************************************/
// ������   : CameraReleaseImageBuffer
// �������� : �ͷ���CameraGetImageBuffer��õĻ�������
// ����     : hCamera   ����ľ������CameraInit������á�
//            pbyBuffer   ��CameraGetImageBuffer��õĻ�������ַ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraReleaseImageBuffer(
    CameraHandle    hCamera,
    BYTE*           pbyBuffer
);

/******************************************************/
// ������   : CameraPlay
// �������� : ��SDK���빤��ģʽ����ʼ��������������͵�ͼ��
//        ���ݡ������ǰ����Ǵ���ģʽ������Ҫ���յ�
//        ����֡�Ժ�Ż����ͼ��
// ����     : hCamera   ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraPlay(
    CameraHandle hCamera
);

/******************************************************/
// ������   : CameraPause
// �������� : ��SDK������ͣģʽ�����������������ͼ�����ݣ�
//        ͬʱҲ�ᷢ�������������ͣ������ͷŴ������
//        ��ͣģʽ�£����Զ�����Ĳ����������ã���������Ч��
// ����     : hCamera   ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraPause(
    CameraHandle hCamera
);

/******************************************************/
// ������   : CameraStop
// �������� : ��SDK����ֹͣ״̬��һ���Ƿ���ʼ��ʱ���øú�����
//        �ú��������ã������ٶ�����Ĳ����������á�
// ����     : hCamera   ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraStop(
    CameraHandle hCamera
);

/******************************************************/
// ������   : CameraInitRecord
// �������� : ��ʼ��һ��¼��
// ����     : hCamera   ����ľ������CameraInit������á�
//            iFormat   ¼��ĸ�ʽ����ǰֻ֧�ֲ�ѹ����MSCV���ַ�ʽ��
//              0:��ѹ����1:MSCV��ʽѹ����
//            pcSavePath  ¼���ļ������·����
//            b2GLimit    ���ΪTRUE,���ļ�����2Gʱ�Զ��ָ
//            dwQuality   ¼����������ӣ�Խ��������Խ�á���Χ1��100.
//            iFrameRate  ¼���֡�ʡ������趨�ı�ʵ�ʲɼ�֡�ʴ�
//              �����Ͳ���©֡��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraInitRecord(
    CameraHandle    hCamera,
    int             iFormat,
    char*           pcSavePath,
    BOOL            b2GLimit,
    DWORD           dwQuality,
    int             iFrameRate
);

/******************************************************/
// ������   : CameraStopRecord
// �������� : ��������¼�񡣵�CameraInitRecord�󣬿���ͨ���ú���
//        ������һ��¼�񣬲�����ļ����������
// ����     : hCamera   ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraStopRecord(
    CameraHandle    hCamera
);

/******************************************************/
// ������   : CameraPushFrame
// �������� : ��һ֡���ݴ���¼�����С��������CameraInitRecord
//        ���ܵ��øú�����CameraStopRecord���ú󣬲����ٵ���
//        �ú������������ǵ�֡ͷ��Ϣ��Я����ͼ��ɼ���ʱ���
//        ��Ϣ�����¼����Ծ�׼��ʱ��ͬ����������֡�ʲ��ȶ�
//        ��Ӱ�졣
// ����     : hCamera     ����ľ������CameraInit������á�
//            pbyImageBuffer    ͼ������ݻ�������������RGB��ʽ��
//            pFrInfo           ͼ���֡ͷ��Ϣ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraPushFrame(
    CameraHandle    hCamera,
    BYTE*           pbyImageBuffer,
    tSdkFrameHead*  pFrInfo
);

/******************************************************/
// ������   : CameraSaveImage
// �������� : ��ͼ�񻺳��������ݱ����ͼƬ�ļ���
// ����     : hCamera    ����ľ������CameraInit������á�
//            lpszFileName   ͼƬ�����ļ�����·����
//            pbyImageBuffer ͼ������ݻ�������
//            pFrInfo        ͼ���֡ͷ��Ϣ��
//            byFileType     ͼ�񱣴�ĸ�ʽ��ȡֵ��Χ�μ�CameraDefine.h
//               ��emSdkFileType�����Ͷ��塣Ŀǰ֧��
//               BMP��JPG��PNG��RAW���ָ�ʽ������RAW��ʾ
//               ��������ԭʼ���ݣ�����RAW��ʽ�ļ�Ҫ��
//               pbyImageBuffer��pFrInfo����CameraGetImageBuffer
//               ��õ����ݣ�����δ��CameraImageProcessת��
//               ��BMP��ʽ����֮�����Ҫ�����BMP��JPG����
//               PNG��ʽ����pbyImageBuffer��pFrInfo����
//               CameraImageProcess������RGB��ʽ���ݡ�
//                 �����÷����Բο�Advanced�����̡�
//            byQuality      ͼ�񱣴���������ӣ���������ΪJPG��ʽ
//                 ʱ�ò�����Ч����Χ1��100�������ʽ
//                           ����д��0��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSaveImage(
    CameraHandle    hCamera,
    char*           lpszFileName,
    BYTE*           pbyImageBuffer,
    tSdkFrameHead*  pFrInfo,
    BYTE            byFileType,
    BYTE            byQuality
);

/******************************************************/
// ������   : CameraGetImageResolution
// �������� : ��õ�ǰԤ���ķֱ��ʡ�
// ����     : hCamera    ����ľ������CameraInit������á�
//            psCurVideoSize �ṹ��ָ�룬���ڷ��ص�ǰ�ķֱ��ʡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetImageResolution(
    CameraHandle            hCamera,
    tSdkImageResolution*    psCurVideoSize
);

/******************************************************/
// ������   : CameraSetImageResolution
// �������� : ����Ԥ���ķֱ��ʡ�
// ����     : hCamera      ����ľ������CameraInit������á�
//            pImageResolution �ṹ��ָ�룬���ڷ��ص�ǰ�ķֱ��ʡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetImageResolution(
    CameraHandle            hCamera,
    tSdkImageResolution*    pImageResolution
);

/******************************************************/
// ������   : CameraGetMediaType
// �������� : ��������ǰ���ԭʼ���ݵĸ�ʽ�����š�
// ����     : hCamera   ����ľ������CameraInit������á�
//            piMediaType   ָ�룬���ڷ��ص�ǰ��ʽ���͵������š�
//              ��CameraGetCapability�����������ԣ�
//              ��tSdkCameraCapbility�ṹ���е�pMediaTypeDesc
//              ��Ա�У����������ʽ���������֧�ֵĸ�ʽ��
//              piMediaType��ָ��������ţ����Ǹ�����������š�
//              pMediaTypeDesc[*piMediaType].iMediaType���ʾ��ǰ��ʽ��
//              ���롣�ñ�����μ�CameraDefine.h��[ͼ���ʽ����]���֡�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetMediaType(
    CameraHandle    hCamera,
    INT*            piMediaType
);

/******************************************************/
// ������   : CameraSetMediaType
// �������� : ������������ԭʼ���ݸ�ʽ��
// ����     : hCamera   ����ľ������CameraInit������á�
//            iMediaType  ��CameraGetCapability�����������ԣ�
//              ��tSdkCameraCapbility�ṹ���е�pMediaTypeDesc
//              ��Ա�У����������ʽ���������֧�ֵĸ�ʽ��
//              iMediaType���Ǹ�����������š�
//              pMediaTypeDesc[iMediaType].iMediaType���ʾ��ǰ��ʽ��
//              ���롣�ñ�����μ�CameraDefine.h��[ͼ���ʽ����]���֡�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetMediaType(
    CameraHandle    hCamera,
    INT             iMediaType
);

/******************************************************/
// ������   : CameraSetAeState
// �������� : ��������ع��ģʽ���Զ������ֶ���
// ����     : hCamera   ����ľ������CameraInit������á�
//            bAeState    TRUE��ʹ���Զ��ع⣻FALSE��ֹͣ�Զ��ع⡣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetAeState(
    CameraHandle    hCamera,
    BOOL            bAeState
);

/******************************************************/
// ������   : CameraGetAeState
// �������� : ��������ǰ���ع�ģʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            pAeState   ָ�룬���ڷ����Զ��ع��ʹ��״̬��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetAeState(
    CameraHandle    hCamera,
    BOOL*           pAeState
);

/******************************************************/
// ������   : CameraSetSharpness
// �������� : ����ͼ��Ĵ�����񻯲�����
// ����     : hCamera  ����ľ������CameraInit������á�
//            iSharpness �񻯲�������Χ��CameraGetCapability
//               ��ã�һ����[0,100]��0��ʾ�ر��񻯴���
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetSharpness(
    CameraHandle    hCamera,
    int             iSharpness
);

/******************************************************/
// ������   : CameraGetSharpness
// �������� : ��ȡ��ǰ���趨ֵ��
// ����     : hCamera   ����ľ������CameraInit������á�
//            piSharpness ָ�룬���ص�ǰ�趨���񻯵��趨ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetSharpness(
    CameraHandle    hCamera,
    int*            piSharpness
);

/******************************************************/
// ������   : CameraSetLutMode
// �������� : ��������Ĳ��任ģʽLUTģʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            emLutMode  LUTMODE_PARAM_GEN ��ʾ��٤��ͶԱȶȲ�����̬����LUT��
//             LUTMODE_PRESET    ��ʾʹ��Ԥ���LUT��
//             LUTMODE_USER_DEF  ��ʾʹ���û��Զ���LUT��
//             LUTMODE_PARAM_GEN�Ķ���ο�CameraDefine.h��emSdkLutMode���͡�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetLutMode(
    CameraHandle    hCamera,
    int             emLutMode
);

/******************************************************/
// ������   : CameraGetLutMode
// �������� : �������Ĳ��任ģʽLUTģʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            pemLutMode ָ�룬���ص�ǰLUTģʽ��������CameraSetLutMode
//             ��emLutMode������ͬ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetLutMode(
    CameraHandle    hCamera,
    int*            pemLutMode
);

/******************************************************/
// ������   : CameraSelectLutPreset
// �������� : ѡ��Ԥ��LUTģʽ�µ�LUT��������ʹ��CameraSetLutMode
//        ��LUTģʽ����ΪԤ��ģʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            iSel     ��������š���ĸ�����CameraGetCapability
//             ��á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSelectLutPreset(
    CameraHandle    hCamera,
    int             iSel
);

/******************************************************/
// ������   : CameraGetLutPresetSel
// �������� : ���Ԥ��LUTģʽ�µ�LUT�������š�
// ����     : hCamera  ����ľ������CameraInit������á�
//            piSel      ָ�룬���ر�������š�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetLutPresetSel(
    CameraHandle    hCamera,
    int*            piSel
);

/******************************************************/
// ������   : CameraSetCustomLut
// �������� : �����Զ����LUT��������ʹ��CameraSetLutMode
//        ��LUTģʽ����Ϊ�Զ���ģʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//             iChannel ָ��Ҫ�趨��LUT��ɫͨ������ΪLUT_CHANNEL_ALLʱ��
//                      ����ͨ����LUT����ͬʱ�滻��
//                      �ο�CameraDefine.h��emSdkLutChannel���塣
//            pLut     ָ�룬ָ��LUT��ĵ�ַ��LUT��Ϊ�޷��Ŷ��������飬�����СΪ
//           4096���ֱ������ɫͨ����0��4096(12bit��ɫ����)��Ӧ��ӳ��ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetCustomLut(
    CameraHandle    hCamera,
    int       iChannel,
    USHORT*         pLut
);

/******************************************************/
// ������   : CameraGetCustomLut
// �������� : ��õ�ǰʹ�õ��Զ���LUT��
// ����     : hCamera  ����ľ������CameraInit������á�
//             iChannel ָ��Ҫ��õ�LUT��ɫͨ������ΪLUT_CHANNEL_ALLʱ��
//                      ���غ�ɫͨ����LUT��
//                      �ο�CameraDefine.h��emSdkLutChannel���塣
//            pLut       ָ�룬ָ��LUT��ĵ�ַ��LUT��Ϊ�޷��Ŷ��������飬�����СΪ
//           4096���ֱ������ɫͨ����0��4096(12bit��ɫ����)��Ӧ��ӳ��ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetCustomLut(
    CameraHandle    hCamera,
    int       iChannel,
    USHORT*         pLut
);

/******************************************************/
// ������   : CameraGetCurrentLut
// �������� : ��������ǰ��LUT�����κ�LUTģʽ�¶����Ե���,
//        ����ֱ�۵Ĺ۲�LUT���ߵı仯��
// ����     : hCamera  ����ľ������CameraInit������á�
//             iChannel ָ��Ҫ��õ�LUT��ɫͨ������ΪLUT_CHANNEL_ALLʱ��
//                      ���غ�ɫͨ����LUT��
//                      �ο�CameraDefine.h��emSdkLutChannel���塣
//            pLut       ָ�룬ָ��LUT��ĵ�ַ��LUT��Ϊ�޷��Ŷ��������飬�����СΪ
//           4096���ֱ������ɫͨ����0��4096(12bit��ɫ����)��Ӧ��ӳ��ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetCurrentLut(
    CameraHandle    hCamera,
    int       iChannel,
    USHORT*         pLut
);

/******************************************************/
// ������   : CameraSetWbMode
// �������� : ���������ƽ��ģʽ����Ϊ�ֶ����Զ����ַ�ʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            bAuto      TRUE�����ʾʹ���Զ�ģʽ��
//             FALSE�����ʾʹ���ֶ�ģʽ��ͨ������
//                 CameraSetOnceWB������һ�ΰ�ƽ�⡣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetWbMode(
    CameraHandle    hCamera,
    BOOL            bAuto
);

/******************************************************/
// ������   : CameraGetWbMode
// �������� : ��õ�ǰ�İ�ƽ��ģʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            pbAuto   ָ�룬����TRUE��ʾ�Զ�ģʽ��FALSE
//             Ϊ�ֶ�ģʽ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetWbMode(
    CameraHandle    hCamera,
    BOOL*           pbAuto
);

/******************************************************/
// ������   : CameraSetPresetClrTemp
// �������� : ѡ��ָ��Ԥ��ɫ��ģʽ
// ����     : hCamera  ����ľ������CameraInit������á�
//            iSel Ԥ��ɫ�µ�ģʽ�����ţ���0��ʼ
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetPresetClrTemp(
    CameraHandle    hCamera,
    int             iSel
);

/******************************************************/
// ������   : CameraGetPresetClrTemp
// �������� : ��õ�ǰѡ���Ԥ��ɫ��ģʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            piSel  ָ�룬����ѡ���Ԥ��ɫ��������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetPresetClrTemp(
    CameraHandle    hCamera,
    int*            piSel
);

/******************************************************/
// ������   : CameraSetUserClrTempGain
// �������� : �����Զ���ɫ��ģʽ�µ���������
// ����     : hCamera  ����ľ������CameraInit������á�
//            iRgain  ��ɫ���棬��Χ0��400����ʾ0��4��
//            iGgain  ��ɫ���棬��Χ0��400����ʾ0��4��
//            iBgain  ��ɫ���棬��Χ0��400����ʾ0��4��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetUserClrTempGain(
  CameraHandle  hCamera,
  int       iRgain,
  int       iGgain,
  int       iBgain
);


/******************************************************/
// ������   : CameraGetUserClrTempGain
// �������� : ����Զ���ɫ��ģʽ�µ���������
// ����     : hCamera  ����ľ������CameraInit������á�
//            piRgain  ָ�룬���غ�ɫ���棬��Χ0��400����ʾ0��4��
//            piGgain  ָ�룬������ɫ���棬��Χ0��400����ʾ0��4��
//            piBgain  ָ�룬������ɫ���棬��Χ0��400����ʾ0��4��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetUserClrTempGain(
  CameraHandle  hCamera,
  int*      piRgain,
  int*      piGgain,
  int*      piBgain
);

/******************************************************/
// ������   : CameraSetUserClrTempMatrix
// �������� : �����Զ���ɫ��ģʽ�µ���ɫ����
// ����     : hCamera  ����ľ������CameraInit������á�
//            pMatrix ָ��һ��float[3][3]������׵�ַ
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetUserClrTempMatrix(
  CameraHandle  hCamera,
  float*      pMatrix
);


/******************************************************/
// ������   : CameraGetUserClrTempMatrix
// �������� : ����Զ���ɫ��ģʽ�µ���ɫ����
// ����     : hCamera  ����ľ������CameraInit������á�
//            pMatrix ָ��һ��float[3][3]������׵�ַ
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetUserClrTempMatrix(
  CameraHandle  hCamera,
  float*      pMatrix
);

/******************************************************/
// ������   : CameraSetClrTempMode
// �������� : ���ð�ƽ��ʱʹ�õ�ɫ��ģʽ��
//              ֧�ֵ�ģʽ�����֣��ֱ����Զ���Ԥ����Զ��塣
//              �Զ�ģʽ�£����Զ�ѡ����ʵ�ɫ��ģʽ
//              Ԥ��ģʽ�£���ʹ���û�ָ����ɫ��ģʽ
//              �Զ���ģʽ�£�ʹ���û��Զ����ɫ����������;���
// ����     : hCamera ����ľ������CameraInit������á�
//            iMode ģʽ��ֻ����emSdkClrTmpMode�ж����һ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetClrTempMode(
  CameraHandle  hCamera,
  int       iMode
);

/******************************************************/
// ������   : CameraGetClrTempMode
// �������� : ��ð�ƽ��ʱʹ�õ�ɫ��ģʽ���ο�CameraSetClrTempMode
//              �й����������֡�
// ����     : hCamera ����ľ������CameraInit������á�
//            pimode ָ�룬����ģʽѡ�񣬲ο�emSdkClrTmpMode���Ͷ���
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetClrTempMode(
  CameraHandle  hCamera,
  int*      pimode
);



/******************************************************/
// ������   : CameraSetOnceWB
// �������� : ���ֶ���ƽ��ģʽ�£����øú��������һ�ΰ�ƽ�⡣
//        ��Ч��ʱ��Ϊ���յ���һ֡ͼ������ʱ��
// ����     : hCamera  ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetOnceWB(
    CameraHandle    hCamera
);

/******************************************************/
// ������   : CameraSetOnceBB
// �������� : ִ��һ�κ�ƽ�������
// ����     : hCamera  ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetOnceBB(
    CameraHandle    hCamera
);


/******************************************************/
// ������   : CameraSetAeTarget
// �������� : �趨�Զ��ع������Ŀ��ֵ���趨��Χ��CameraGetCapability
//        ������á�
// ����     : hCamera  ����ľ������CameraInit������á�
//            iAeTarget  ����Ŀ��ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetAeTarget(
    CameraHandle    hCamera,
    int             iAeTarget
);

/******************************************************/
// ������   : CameraGetAeTarget
// �������� : ����Զ��ع������Ŀ��ֵ��
// ����     : hCamera   ����ľ������CameraInit������á�
//            *piAeTarget ָ�룬����Ŀ��ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetAeTarget(
    CameraHandle    hCamera,
    int*            piAeTarget
);


/******************************************************/
// ������   : CameraSetAeExposureRange
// �������� : �趨�Զ��ع�ģʽ���ع�ʱ����ڷ�Χ
// ����     : hCamera  ����ľ������CameraInit������á�
//           fMinExposureTime ��С�ع�ʱ�䣨΢�룩
//			 fMaxExposureTime ����ع�ʱ�䣨΢�룩
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus CameraSetAeExposureRange(
	CameraHandle    hCamera,
	double          fMinExposureTime,
	double			fMaxExposureTime
	);

/******************************************************/
// ������   : CameraGetAeExposureRange
// �������� : ����Զ��ع�ģʽ���ع�ʱ����ڷ�Χ
// ����     : hCamera   ����ľ������CameraInit������á�
//           fMinExposureTime ��С�ع�ʱ�䣨΢�룩
//			 fMaxExposureTime ����ع�ʱ�䣨΢�룩
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus CameraGetAeExposureRange(
	CameraHandle    hCamera,
	double*         fMinExposureTime,
	double*			fMaxExposureTime
	);

/******************************************************/
// ������   : CameraSetAeAnalogGainRange
// �������� : �趨�Զ��ع�ģʽ��������ڷ�Χ
// ����     : hCamera  ����ľ������CameraInit������á�
//           iMinAnalogGain ��С����
//			 iMaxAnalogGain �������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus CameraSetAeAnalogGainRange(
	CameraHandle    hCamera,
	int				iMinAnalogGain,
	int				iMaxAnalogGain
	);

/******************************************************/
// ������   : CameraGetAeAnalogGainRange
// �������� : ����Զ��ع�ģʽ��������ڷ�Χ
// ����     : hCamera   ����ľ������CameraInit������á�
//           iMinAnalogGain ��С����
//			 iMaxAnalogGain �������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus CameraGetAeAnalogGainRange(
	CameraHandle    hCamera,
	int*			iMinAnalogGain,
	int*			iMaxAnalogGain
	);


/******************************************************/
// ������   : CameraSetExposureTime
// �������� : �����ع�ʱ�䡣��λΪ΢�롣����CMOS�����������ع�
//        �ĵ�λ�ǰ�����������ģ���ˣ��ع�ʱ�䲢������΢��
//        ���������ɵ������ǻᰴ��������ȡ�ᡣ�ڵ���
//        �������趨�ع�ʱ��󣬽����ٵ���CameraGetExposureTime
//        �����ʵ���趨��ֵ��
// ����     : hCamera      ����ľ������CameraInit������á�
//            fExposureTime �ع�ʱ�䣬��λ΢�롣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/

MVSDK_API CameraSdkStatus  CameraSetExposureTime(
    CameraHandle    hCamera,
    double          fExposureTime
);

/******************************************************/
// ������   : CameraGetExposureLineTime
// �������� : ���һ�е��ع�ʱ�䡣����CMOS�����������ع�
//        �ĵ�λ�ǰ�����������ģ���ˣ��ع�ʱ�䲢������΢��
//        ���������ɵ������ǻᰴ��������ȡ�ᡣ���������
//          ���þ��Ƿ���CMOS����ع�һ�ж�Ӧ��ʱ�䡣
// ����     : hCamera  ����ľ������CameraInit������á�
//            pfLineTime ָ�룬����һ�е��ع�ʱ�䣬��λΪ΢�롣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/

MVSDK_API CameraSdkStatus  CameraGetExposureLineTime(
    CameraHandle    hCamera,
    double*         pfLineTime
);

/******************************************************/
// ������   : CameraGetExposureTime
// �������� : ���������ع�ʱ�䡣��μ�CameraSetExposureTime
//        �Ĺ���������
// ����     : hCamera        ����ľ������CameraInit������á�
//            pfExposureTime   ָ�룬���ص�ǰ���ع�ʱ�䣬��λ΢�롣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetExposureTime(
    CameraHandle    hCamera,
    double*         pfExposureTime
);

/******************************************************/
// ������   : CameraSetAnalogGain
// �������� : ���������ͼ��ģ������ֵ����ֵ����CameraGetCapability���
//        ��������Խṹ����sExposeDesc.fAnalogGainStep����
//        �õ�ʵ�ʵ�ͼ���źŷŴ�����
// ����     : hCamera   ����ľ������CameraInit������á�
//            iAnalogGain �趨��ģ������ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetAnalogGain(
    CameraHandle    hCamera,
    INT             iAnalogGain
);

/******************************************************/
// ������   : CameraGetAnalogGain
// �������� : ���ͼ���źŵ�ģ������ֵ���μ�CameraSetAnalogGain
//        ��ϸ˵����
// ����     : hCamera    ����ľ������CameraInit������á�
//            piAnalogGain ָ�룬���ص�ǰ��ģ������ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetAnalogGain(
    CameraHandle    hCamera,
    INT*            piAnalogGain
);

/******************************************************/
// ������   : CameraSetGain
// �������� : ����ͼ����������档�趨��Χ��CameraGetCapability
//        ��õ�������Խṹ����sRgbGainRange��Ա������
//        ʵ�ʵķŴ������趨ֵ/100��
// ����     : hCamera  ����ľ������CameraInit������á�
//            iRGain   ��ɫͨ��������ֵ��
//            iGGain   ��ɫͨ��������ֵ��
//            iBGain   ��ɫͨ��������ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetGain(
    CameraHandle    hCamera,
    int             iRGain,
    int             iGGain,
    int             iBGain
);


/******************************************************/
// ������   : CameraGetGain
// �������� : ���ͼ������������档������μ�CameraSetGain
//        �Ĺ����������֡�
// ����     : hCamera  ����ľ������CameraInit������á�
//            piRGain  ָ�룬���غ�ɫͨ������������ֵ��
//            piGGain    ָ�룬������ɫͨ������������ֵ��
//            piBGain    ָ�룬������ɫͨ������������ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetGain(
    CameraHandle    hCamera,
    int*            piRGain,
    int*            piGGain,
    int*            piBGain
);


/******************************************************/
// ������   : CameraSetGamma
// �������� : �趨LUT��̬����ģʽ�µ�Gammaֵ���趨��ֵ��
//        ���ϱ�����SDK�ڲ�������ֻ�е�������ڶ�̬
//        �������ɵ�LUTģʽʱ���Ż���Ч����ο�CameraSetLutMode
//        �ĺ���˵�����֡�
// ����     : hCamera  ����ľ������CameraInit������á�
//            iGamma     Ҫ�趨��Gammaֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetGamma(
    CameraHandle    hCamera,
    int             iGamma
);

/******************************************************/
// ������   : CameraGetGamma
// �������� : ���LUT��̬����ģʽ�µ�Gammaֵ����ο�CameraSetGamma
//        �����Ĺ���������
// ����     : hCamera  ����ľ������CameraInit������á�
//            piGamma    ָ�룬���ص�ǰ��Gammaֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetGamma(
    CameraHandle    hCamera,
    int*            piGamma
);

/******************************************************/
// ������   : CameraSetContrast
// �������� : �趨LUT��̬����ģʽ�µĶԱȶ�ֵ���趨��ֵ��
//        ���ϱ�����SDK�ڲ�������ֻ�е�������ڶ�̬
//        �������ɵ�LUTģʽʱ���Ż���Ч����ο�CameraSetLutMode
//        �ĺ���˵�����֡�
// ����     : hCamera  ����ľ������CameraInit������á�
//            iContrast  �趨�ĶԱȶ�ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetContrast(
    CameraHandle    hCamera,
    int             iContrast
);

/******************************************************/
// ������   : CameraGetContrast
// �������� : ���LUT��̬����ģʽ�µĶԱȶ�ֵ����ο�
//        CameraSetContrast�����Ĺ���������
// ����     : hCamera  ����ľ������CameraInit������á�
//            piContrast ָ�룬���ص�ǰ�ĶԱȶ�ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetContrast(
    CameraHandle    hCamera,
    int*            piContrast
);

/******************************************************/
// ������   : CameraSetSaturation
// �������� : �趨ͼ����ı��Ͷȡ��Ժڰ������Ч��
//        �趨��Χ��CameraGetCapability��á�100��ʾ
//        ��ʾԭʼɫ�ȣ�����ǿ��
// ����     : hCamera    ����ľ������CameraInit������á�
//            iSaturation  �趨�ı��Ͷ�ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetSaturation(
    CameraHandle    hCamera,
    int             iSaturation
);

/******************************************************/
// ������   : CameraGetSaturation
// �������� : ���ͼ����ı��Ͷȡ�
// ����     : hCamera    ����ľ������CameraInit������á�
//            piSaturation ָ�룬���ص�ǰͼ����ı��Ͷ�ֵ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetSaturation(
    CameraHandle    hCamera,
    int*            piSaturation
);

/******************************************************/
// ������   : CameraSetMonochrome
// �������� : ���ò�ɫתΪ�ڰ׹��ܵ�ʹ�ܡ�
// ����     : hCamera ����ľ������CameraInit������á�
//            bEnable   TRUE����ʾ����ɫͼ��תΪ�ڰס�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetMonochrome(
    CameraHandle    hCamera,
    BOOL            bEnable
);

/******************************************************/
// ������   : CameraGetMonochrome
// �������� : ��ò�ɫת���ڰ׹��ܵ�ʹ��״����
// ����     : hCamera  ����ľ������CameraInit������á�
//            pbEnable   ָ�롣����TRUE��ʾ�����˲�ɫͼ��
//             ת��Ϊ�ڰ�ͼ��Ĺ��ܡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetMonochrome(
    CameraHandle    hCamera,
    BOOL*           pbEnable
);

/******************************************************/
// ������   : CameraSetInverse
// �������� : ���ò�ͼ����ɫ��ת���ܵ�ʹ�ܡ�
// ����     : hCamera  ����ľ������CameraInit������á�
//            bEnable    TRUE����ʾ����ͼ����ɫ��ת���ܣ�
//             ���Ի�����ƽ����Ƭ��Ч����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetInverse(
    CameraHandle    hCamera,
    BOOL            bEnable
);

/******************************************************/
// ������   : CameraGetInverse
// �������� : ���ͼ����ɫ��ת���ܵ�ʹ��״̬��
// ����     : hCamera  ����ľ������CameraInit������á�
//            pbEnable   ָ�룬���ظù���ʹ��״̬��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetInverse(
    CameraHandle    hCamera,
    BOOL*           pbEnable
);

/******************************************************/
// ������   : CameraSetAntiFlick
// �������� : �����Զ��ع�ʱ��Ƶ�����ܵ�ʹ��״̬�������ֶ�
//        �ع�ģʽ����Ч��
// ����     : hCamera  ����ľ������CameraInit������á�
//            bEnable    TRUE��������Ƶ������;FALSE���رոù��ܡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetAntiFlick(
    CameraHandle    hCamera,
    BOOL            bEnable
);

/******************************************************/
// ������   : CameraGetAntiFlick
// �������� : ����Զ��ع�ʱ��Ƶ�����ܵ�ʹ��״̬��
// ����     : hCamera  ����ľ������CameraInit������á�
//            pbEnable   ָ�룬���ظù��ܵ�ʹ��״̬��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetAntiFlick(
    CameraHandle    hCamera,
    BOOL*           pbEnable
);

/******************************************************/
// ������   : CameraGetLightFrequency
// �������� : ����Զ��ع�ʱ����Ƶ����Ƶ��ѡ��
// ����     : hCamera      ����ľ������CameraInit������á�
//            piFrequencySel ָ�룬����ѡ��������š�0:50HZ 1:60HZ
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetLightFrequency(
    CameraHandle    hCamera,
    int*            piFrequencySel
);

/******************************************************/
// ������   : CameraSetLightFrequency
// �������� : �����Զ��ع�ʱ��Ƶ����Ƶ�ʡ�
// ����     : hCamera     ����ľ������CameraInit������á�
//            iFrequencySel 0:50HZ , 1:60HZ
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetLightFrequency(
    CameraHandle    hCamera,
    int             iFrequencySel
);

/******************************************************/
// ������   : CameraSetFrameSpeed
// �������� : �趨������ͼ���֡�ʡ�����ɹ�ѡ���֡��ģʽ��
//        CameraGetCapability��õ���Ϣ�ṹ����iFrameSpeedDesc
//        ��ʾ���֡��ѡ��ģʽ������
// ����     : hCamera   ����ľ������CameraInit������á�
//            iFrameSpeed ѡ���֡��ģʽ�����ţ���Χ��0��
//              CameraGetCapability��õ���Ϣ�ṹ����iFrameSpeedDesc - 1
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetFrameSpeed(
    CameraHandle    hCamera,
    int             iFrameSpeed
);

/******************************************************/
// ������   : CameraGetFrameSpeed
// �������� : ���������ͼ���֡��ѡ�������š������÷��ο�
//        CameraSetFrameSpeed�����Ĺ����������֡�
// ����     : hCamera    ����ľ������CameraInit������á�
//            piFrameSpeed ָ�룬����ѡ���֡��ģʽ�����š�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetFrameSpeed(
    CameraHandle    hCamera,
    int*            piFrameSpeed
);


/******************************************************/
// ������   : CameraSetParameterMode
// �������� : �趨������ȡ��Ŀ�����
// ����     : hCamera  ����ľ������CameraInit������á�
//            iMode  ������ȡ�Ķ��󡣲ο�CameraDefine.h
//          ��emSdkParameterMode�����Ͷ��塣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetParameterMode(
    CameraHandle    hCamera,
    int             iMode
);

/******************************************************/
// ������   : CameraGetParameterMode
// �������� :
// ����     : hCamera  ����ľ������CameraInit������á�
//            int* piTarget
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetParameterMode(
    CameraHandle    hCamera,
    int*            piTarget
);

/******************************************************/
// ������   : CameraSetParameterMask
// �������� : ���ò�����ȡ�����롣�������غͱ���ʱ����ݸ�
//        ��������������ģ��������Ƿ���ػ��߱��档
// ����     : hCamera ����ľ������CameraInit������á�
//            uMask     ���롣�ο�CameraDefine.h��PROP_SHEET_INDEX
//            ���Ͷ��塣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetParameterMask(
    CameraHandle    hCamera,
    UINT            uMask
);

/******************************************************/
// ������   : CameraSaveParameter
// �������� : ���浱ǰ���������ָ���Ĳ������С�����ṩ��A,B,C,D
//        A,B,C,D����ռ������в����ı��档
// ����     : hCamera  ����ľ������CameraInit������á�
//            iTeam      PARAMETER_TEAM_A ���浽A����,
//             PARAMETER_TEAM_B ���浽B����,
//             PARAMETER_TEAM_C ���浽C����,
//             PARAMETER_TEAM_D ���浽D����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSaveParameter(
    CameraHandle    hCamera,
    int             iTeam
);


/******************************************************/
// ������   : CameraSaveParameterToFile
// �������� : ���浱ǰ���������ָ�����ļ��С����ļ����Ը��Ƶ�
//        ��ĵ����Ϲ�����������أ�Ҳ���������������á�
// ����     : hCamera  ����ľ������CameraInit������á�
//            sFileName  �����ļ�������·����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSaveParameterToFile(
  CameraHandle  hCamera,
  char*       sFileName
);


/******************************************************/
// ������   : CameraReadParameterFromFile
// �������� : ��PC��ָ���Ĳ����ļ��м��ز������ҹ�˾�������
//        ������PC��Ϊ.config��׺���ļ���λ�ڰ�װ�µ�
//        Camera\Configs�ļ����С�
// ����     : hCamera  ����ľ������CameraInit������á�
//            *sFileName �����ļ�������·����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraReadParameterFromFile(
    CameraHandle    hCamera,
    char*           sFileName
);

/******************************************************/
// ������   : CameraLoadParameter
// �������� : ����ָ����Ĳ���������С�
// ����     : hCamera  ����ľ������CameraInit������á�
//            iTeam    PARAMETER_TEAM_A ����A�����,
//             PARAMETER_TEAM_B ����B�����,
//             PARAMETER_TEAM_C ����C�����,
//             PARAMETER_TEAM_D ����D�����,
//             PARAMETER_TEAM_DEFAULT ����Ĭ�ϲ�����
//             ���Ͷ���ο�CameraDefine.h��emSdkParameterTeam����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraLoadParameter(
    CameraHandle    hCamera,
    int             iTeam
);

/******************************************************/
// ������   : CameraGetCurrentParameterGroup
// �������� : ��õ�ǰѡ��Ĳ����顣
// ����     : hCamera  ����ľ������CameraInit������á�
//            piTeam     ָ�룬���ص�ǰѡ��Ĳ����顣����ֵ
//             �ο�CameraLoadParameter��iTeam������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetCurrentParameterGroup(
    CameraHandle    hCamera,
    int*            piTeam
);

/******************************************************/
// ������   : CameraSetTransPackLen
// �������� : �����������ͼ�����ݵķְ���С��
//        Ŀǰ��SDK�汾�У��ýӿڽ���GIGE�ӿ������Ч��
//        �����������紫��ķְ���С������֧�־�֡��������
//        ���ǽ���ѡ��8K�ķְ���С��������Ч�Ľ��ʹ���
//        ��ռ�õ�CPU����ʱ�䡣
// ����     : hCamera  ����ľ������CameraInit������á�
//            iPackSel   �ְ�����ѡ��������š��ְ����ȿ���
//             ���������Խṹ����pPackLenDesc��Ա������
//             iPackLenDesc��Ա���ʾ����ѡ�ķְ�ģʽ������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetTransPackLen(
    CameraHandle    hCamera,
    INT             iPackSel
);

/******************************************************/
// ������   : CameraGetTransPackLen
// �������� : ��������ǰ����ְ���С��ѡ�������š�
// ����     : hCamera  ����ľ������CameraInit������á�
//            piPackSel  ָ�룬���ص�ǰѡ��ķְ���С�����š�
//             �μ�CameraSetTransPackLen��iPackSel��
//             ˵����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetTransPackLen(
    CameraHandle    hCamera,
    INT*            piPackSel
);

/******************************************************/
// ������   : CameraIsAeWinVisible
// �������� : ����Զ��ع�ο����ڵ���ʾ״̬��
// ����     : hCamera    ����ľ������CameraInit������á�
//            pbIsVisible  ָ�룬����TRUE�����ʾ��ǰ���ڻ�
//               ��������ͼ�������ϡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraIsAeWinVisible(
    CameraHandle    hCamera,
    BOOL*           pbIsVisible
);

/******************************************************/
// ������   : CameraSetAeWinVisible
// �������� : �����Զ��ع�ο����ڵ���ʾ״̬�������ô���״̬
//        Ϊ��ʾ������CameraImageOverlay���ܹ�������λ��
//        �Ծ��εķ�ʽ������ͼ���ϡ�
// ����     : hCamera   ����ľ������CameraInit������á�
//            bIsVisible  TRUE������Ϊ��ʾ��FALSE������ʾ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetAeWinVisible(
    CameraHandle    hCamera,
    BOOL            bIsVisible
);

/******************************************************/
// ������   : CameraGetAeWindow
// �������� : ����Զ��ع�ο����ڵ�λ�á�
// ����     : hCamera  ����ľ������CameraInit������á�
//            piHOff     ָ�룬���ش���λ�����ϽǺ�����ֵ��
//            piVOff     ָ�룬���ش���λ�����Ͻ�������ֵ��
//            piWidth    ָ�룬���ش��ڵĿ�ȡ�
//            piHeight   ָ�룬���ش��ڵĸ߶ȡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetAeWindow(
    CameraHandle    hCamera,
    INT*            piHOff,
    INT*            piVOff,
    INT*            piWidth,
    INT*            piHeight
);

/******************************************************/
// ������   : CameraSetAeWindow
// �������� : �����Զ��ع�Ĳο����ڡ�
// ����     : hCamera  ����ľ������CameraInit������á�
//            iHOff    �������Ͻǵĺ�����
//            iVOff      �������Ͻǵ�������
//            iWidth     ���ڵĿ��
//            iHeight    ���ڵĸ߶�
//        ���iHOff��iVOff��iWidth��iHeightȫ��Ϊ0����
//        ��������Ϊÿ���ֱ����µľ���1/2��С����������
//        �ֱ��ʵı仯������仯�����iHOff��iVOff��iWidth��iHeight
//        �������Ĵ���λ�÷�Χ�����˵�ǰ�ֱ��ʷ�Χ�ڣ�
//          ���Զ�ʹ�þ���1/2��С���ڡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetAeWindow(
    CameraHandle    hCamera,
    int             iHOff,
    int             iVOff,
    int             iWidth,
    int             iHeight
);

/******************************************************/
// ������   : CameraSetMirror
// �������� : ����ͼ������������������Ϊˮƽ�ʹ�ֱ��������
// ����     : hCamera  ����ľ������CameraInit������á�
//            iDir     ��ʾ����ķ���0����ʾˮƽ����1����ʾ��ֱ����
//            bEnable  TRUE��ʹ�ܾ���;FALSE����ֹ����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetMirror(
    CameraHandle    hCamera,
    int             iDir,
    BOOL            bEnable
);

/******************************************************/
// ������   : CameraGetMirror
// �������� : ���ͼ��ľ���״̬��
// ����     : hCamera  ����ľ������CameraInit������á�
//            iDir     ��ʾҪ��õľ�����
//             0����ʾˮƽ����1����ʾ��ֱ����
//            pbEnable   ָ�룬����TRUE�����ʾiDir��ָ�ķ���
//             ����ʹ�ܡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetMirror(
    CameraHandle    hCamera,
    int             iDir,
    BOOL*           pbEnable
);

/******************************************************/
// ������   : CameraGetWbWindow
// �������� : ��ð�ƽ��ο����ڵ�λ�á�
// ����     : hCamera  ����ľ������CameraInit������á�
//            PiHOff   ָ�룬���زο����ڵ����ϽǺ����� ��
//            PiVOff     ָ�룬���زο����ڵ����Ͻ������� ��
//            PiWidth    ָ�룬���زο����ڵĿ�ȡ�
//            PiHeight   ָ�룬���زο����ڵĸ߶ȡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetWbWindow(
    CameraHandle    hCamera,
    INT*            PiHOff,
    INT*            PiVOff,
    INT*            PiWidth,
    INT*            PiHeight
);

/******************************************************/
// ������   : CameraSetWbWindow
// �������� : ���ð�ƽ��ο����ڵ�λ�á�
// ����     : hCamera ����ľ������CameraInit������á�
//            iHOff   �ο����ڵ����ϽǺ����ꡣ
//            iVOff     �ο����ڵ����Ͻ������ꡣ
//            iWidth    �ο����ڵĿ�ȡ�
//            iHeight   �ο����ڵĸ߶ȡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetWbWindow(
    CameraHandle    hCamera,
    INT             iHOff,
    INT             iVOff,
    INT             iWidth,
    INT             iHeight
);

/******************************************************/
// ������   : CameraIsWbWinVisible
// �������� : ��ð�ƽ�ⴰ�ڵ���ʾ״̬��
// ����     : hCamera  ����ľ������CameraInit������á�
//            pbShow   ָ�룬����TRUE�����ʾ�����ǿɼ��ġ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraIsWbWinVisible(
    CameraHandle    hCamera,
    BOOL*           pbShow
);

/******************************************************/
// ������   : CameraSetWbWinVisible
// �������� : ���ð�ƽ�ⴰ�ڵ���ʾ״̬��
// ����     : hCamera  ����ľ������CameraInit������á�
//            bShow      TRUE�����ʾ����Ϊ�ɼ����ڵ���
//             CameraImageOverlay��ͼ�������Ͻ��Ծ���
//             �ķ�ʽ���Ӱ�ƽ��ο����ڵ�λ�á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetWbWinVisible(
    CameraHandle    hCamera,
    BOOL            bShow
);

/******************************************************/
// ������   : CameraImageOverlay
// �������� : �������ͼ�������ϵ���ʮ���ߡ���ƽ��ο����ڡ�
//        �Զ��ع�ο����ڵ�ͼ�Ρ�ֻ������Ϊ�ɼ�״̬��
//        ʮ���ߺͲο����ڲ��ܱ������ϡ�
//        ע�⣬�ú���������ͼ�������RGB��ʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            pRgbBuffer ͼ�����ݻ�������
//            pFrInfo    ͼ���֡ͷ��Ϣ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraImageOverlay(
    CameraHandle    hCamera,
    BYTE*           pRgbBuffer,
    tSdkFrameHead*  pFrInfo
);

/******************************************************/
// ������   : CameraSetCrossLine
// �������� : ����ָ��ʮ���ߵĲ�����
// ����     : hCamera  ����ľ������CameraInit������á�
//            iLine    ��ʾҪ���õڼ���ʮ���ߵ�״̬����ΧΪ[0,8]����9����
//            x          ʮ��������λ�õĺ�����ֵ��
//            y      ʮ��������λ�õ�������ֵ��
//            uColor     ʮ���ߵ���ɫ����ʽΪ(R|(G<<8)|(B<<16))
//            bVisible   ʮ���ߵ���ʾ״̬��TRUE����ʾ��ʾ��
//             ֻ������Ϊ��ʾ״̬��ʮ���ߣ��ڵ���
//             CameraImageOverlay��Żᱻ���ӵ�ͼ���ϡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetCrossLine(
    CameraHandle    hCamera,
    int             iLine,
    INT             x,
    INT             y,
    UINT            uColor,
    BOOL            bVisible
);

/******************************************************/
// ������   : CameraGetCrossLine
// �������� : ���ָ��ʮ���ߵ�״̬��
// ����     : hCamera  ����ľ������CameraInit������á�
//            iLine    ��ʾҪ��ȡ�ĵڼ���ʮ���ߵ�״̬����ΧΪ[0,8]����9����
//            px     ָ�룬���ظ�ʮ��������λ�õĺ����ꡣ
//            py     ָ�룬���ظ�ʮ��������λ�õĺ����ꡣ
//            pcolor     ָ�룬���ظ�ʮ���ߵ���ɫ����ʽΪ(R|(G<<8)|(B<<16))��
//            pbVisible  ָ�룬����TRUE�����ʾ��ʮ���߿ɼ���
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetCrossLine(
    CameraHandle    hCamera,
    INT             iLine,
    INT*            px,
    INT*            py,
    UINT*           pcolor,
    BOOL*           pbVisible
);

/******************************************************/
// ������   : CameraGetCapability
// �������� : �����������������ṹ�塣�ýṹ���а��������
//        �����õĸ��ֲ����ķ�Χ��Ϣ����������غ����Ĳ���
//        ���أ�Ҳ�����ڶ�̬������������ý��档
// ����     : hCamera   ����ľ������CameraInit������á�
//            pCameraInfo ָ�룬���ظ�������������Ľṹ�塣
//                        tSdkCameraCapbility��CameraDefine.h�ж��塣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetCapability(
    CameraHandle            hCamera,
    tSdkCameraCapbility*    pCameraInfo
);

/******************************************************/
// ������   : CameraGetCapabilityEx
// �������� : �����������������ṹ�塣�ýṹ���а��������
//        �����õĸ��ֲ����ķ�Χ��Ϣ����������غ����Ĳ���
//        ���أ�Ҳ�����ڶ�̬������������ý��档
// ����     : sDeviceModel    ������ͺţ���ɨ���б��л�ȡ
//            pCameraInfo ָ�룬���ظ�������������Ľṹ�塣
//                        tSdkCameraCapbility��CameraDefine.h�ж��塣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetCapabilityEx(
    char*                   sDeviceModel,
    tSdkCameraCapbility*    pCameraInfo,
    PVOID                   hCameraHandle
);


/******************************************************/
// ������   : CameraWriteSN
// �������� : ������������кš��ҹ�˾������кŷ�Ϊ3����
//        0�������ҹ�˾�Զ����������кţ�����ʱ�Ѿ�
//        �趨�ã�1����2���������ο���ʹ�á�ÿ������
//        �ų��ȶ���32���ֽڡ�
// ����     : hCamera  ����ľ������CameraInit������á�
//            pbySN    ���кŵĻ�������
//            iLevel   Ҫ�趨�����кż���ֻ����1����2��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraWriteSN(
    CameraHandle    hCamera,
    BYTE*           pbySN,
    INT             iLevel
);

/******************************************************/
// ������   : CameraReadSN
// �������� : ��ȡ���ָ����������кš����кŵĶ�����ο�
//          CameraWriteSN�����Ĺ����������֡�
// ����     : hCamera  ����ľ������CameraInit������á�
//            pbySN    ���кŵĻ�������
//            iLevel     Ҫ��ȡ�����кż���ֻ����1��2��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraReadSN(
    CameraHandle        hCamera,
    BYTE*               pbySN,
    INT                 iLevel
);
/******************************************************/
// ������   : CameraSetTriggerDelayTime
// �������� : ����Ӳ������ģʽ�µĴ�����ʱʱ�䣬��λ΢�롣
//        ��Ӳ�����ź����ٺ󣬾���ָ������ʱ���ٿ�ʼ�ɼ�
//        ͼ�񡣽������ͺŵ����֧�ָù��ܡ�������鿴
//        ��Ʒ˵���顣
// ����     : hCamera    ����ľ������CameraInit������á�
//            uDelayTimeUs Ӳ������ʱ����λ΢�롣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetTriggerDelayTime(
    CameraHandle    hCamera,
    UINT            uDelayTimeUs
);

/******************************************************/
// ������   : CameraGetTriggerDelayTime
// �������� : ��õ�ǰ�趨��Ӳ������ʱʱ�䡣
// ����     : hCamera     ����ľ������CameraInit������á�
//            puDelayTimeUs ָ�룬������ʱʱ�䣬��λ΢�롣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetTriggerDelayTime(
    CameraHandle    hCamera,
    UINT*           puDelayTimeUs
);

/******************************************************/
// ������   : CameraSetTriggerCount
// �������� : ���ô���ģʽ�µĴ���֡���������������Ӳ������
//        ģʽ����Ч��Ĭ��Ϊ1֡����һ�δ����źŲɼ�һ֡ͼ��
// ����     : hCamera ����ľ������CameraInit������á�
//            iCount    һ�δ����ɼ���֡����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetTriggerCount(
    CameraHandle    hCamera,
    INT             iCount
);

/******************************************************/
// ������   : CameraGetTriggerCount
// �������� : ���һ�δ�����֡����
// ����     : hCamera  ����ľ������CameraInit������á�
//            INT* piCount
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetTriggerCount(
    CameraHandle    hCamera,
    INT*            piCount
);

/******************************************************/
// ������   : CameraSoftTrigger
// �������� : ִ��һ��������ִ�к󣬻ᴥ����CameraSetTriggerCount
//          ָ����֡����
// ����     : hCamera  ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSoftTrigger(
    CameraHandle    hCamera
);

/******************************************************/
// ������   : CameraSetTriggerMode
// �������� : ��������Ĵ���ģʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            iModeSel   ģʽѡ�������š����趨��ģʽ��
//             CameraGetCapability������ȡ����ο�
//               CameraDefine.h��tSdkCameraCapbility�Ķ��塣
//             һ�������0��ʾ�����ɼ�ģʽ��1��ʾ
//             �������ģʽ��2��ʾӲ������ģʽ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetTriggerMode(
    CameraHandle    hCamera,
    int             iModeSel
);

/******************************************************/
// ������   : CameraGetTriggerMode
// �������� : �������Ĵ���ģʽ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            piModeSel  ָ�룬���ص�ǰѡ����������ģʽ�������š�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetTriggerMode(
    CameraHandle    hCamera,
    INT*            piModeSel
);

/******************************************************/
// ������ 	: CameraSetStrobeMode
// ��������	: ����IO���Ŷ����ϵ�STROBE�źš����źſ���������ƿ��ƣ�Ҳ�������ⲿ��е���ſ��ơ�
// ����	    : hCamera ����ľ������CameraInit������á�
//             iMode   ��ΪSTROBE_SYNC_WITH_TRIG_AUTO      �ʹ����ź�ͬ������������������ع�ʱ���Զ�����STROBE�źš�
//                                                         ��ʱ����Ч���Կ�����(CameraSetStrobePolarity)��
//                     ��ΪSTROBE_SYNC_WITH_TRIG_MANUALʱ���ʹ����ź�ͬ����������STROBE��ʱָ����ʱ���(CameraSetStrobeDelayTime)��
//                                                         �ٳ���ָ��ʱ�������(CameraSetStrobePulseWidth)��
//                                                         ��Ч���Կ�����(CameraSetStrobePolarity)��
//                     ��ΪSTROBE_ALWAYS_HIGHʱ��STROBE�źź�Ϊ��,������������
//                     ��ΪSTROBE_ALWAYS_LOWʱ��STROBE�źź�Ϊ��,������������
//
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus   CameraSetStrobeMode(
    CameraHandle    hCamera,
    INT             iMode
);

/******************************************************/
// ������ 	: CameraGetStrobeMode
// ��������	: ���ߵ�ǰSTROBE�ź����õ�ģʽ��
// ����	    : hCamera ����ľ������CameraInit������á�
//             piMode  ָ�룬����STROBE_SYNC_WITH_TRIG_AUTO,STROBE_SYNC_WITH_TRIG_MANUAL��STROBE_ALWAYS_HIGH����STROBE_ALWAYS_LOW��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus   CameraGetStrobeMode(
    CameraHandle    hCamera,
    INT*            piMode
);

/******************************************************/
// ������ 	: CameraSetStrobeDelayTime
// ��������	: ��STROBE�źŴ���STROBE_SYNC_WITH_TRIGʱ��ͨ���ú�����������Դ����ź���ʱʱ�䡣
// ����	    : hCamera       ����ľ������CameraInit������á�
//             uDelayTimeUs  ��Դ����źŵ���ʱʱ�䣬��λΪus������Ϊ0��������Ϊ������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus   CameraSetStrobeDelayTime(
    CameraHandle    hCamera,
    UINT            uDelayTimeUs
);

/******************************************************/
// ������ 	: CameraGetStrobeDelayTime
// ��������	: ��STROBE�źŴ���STROBE_SYNC_WITH_TRIGʱ��ͨ���ú����������Դ����ź���ʱʱ�䡣
// ����	    : hCamera           ����ľ������CameraInit������á�
//             upDelayTimeUs     ָ�룬������ʱʱ�䣬��λus��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus   CameraGetStrobeDelayTime(
    CameraHandle    hCamera,
    UINT*           upDelayTimeUs
);

/******************************************************/
// ������ 	: CameraSetStrobePulseWidth
// ��������	: ��STROBE�źŴ���STROBE_SYNC_WITH_TRIGʱ��ͨ���ú��������������ȡ�
// ����	    : hCamera       ����ľ������CameraInit������á�
//             uTimeUs       ����Ŀ�ȣ���λΪʱ��us��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus   CameraSetStrobePulseWidth(
    CameraHandle    hCamera,
    UINT            uTimeUs
);

/******************************************************/
// ������ 	: CameraGetStrobePulseWidth
// ��������	: ��STROBE�źŴ���STROBE_SYNC_WITH_TRIGʱ��ͨ���ú�������������ȡ�
// ����	    : hCamera   ����ľ������CameraInit������á�
//             upTimeUs  ָ�룬���������ȡ���λΪʱ��us��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus   CameraGetStrobePulseWidth(
    CameraHandle    hCamera,
    UINT*           upTimeUs
);

/******************************************************/
// ������ 	: CameraSetStrobePolarity
// ��������	: ��STROBE�źŴ���STROBE_SYNC_WITH_TRIGʱ��ͨ���ú�����������Ч��ƽ�ļ��ԡ�Ĭ��Ϊ����Ч���������źŵ���ʱ��STROBE�źű����ߡ�
// ����	    : hCamera   ����ľ������CameraInit������á�
//             iPolarity STROBE�źŵļ��ԣ�0Ϊ�͵�ƽ��Ч��1Ϊ�ߵ�ƽ��Ч��Ĭ��Ϊ�ߵ�ƽ��Ч��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus   CameraSetStrobePolarity(
    CameraHandle    hCamera,
    INT             uPolarity
);

/******************************************************/
// ������ 	: CameraGetStrobePolarity
// ��������	: ��������ǰSTROBE�źŵ���Ч���ԡ�Ĭ��Ϊ�ߵ�ƽ��Ч��
// ����	    : hCamera       ����ľ������CameraInit������á�
//             ipPolarity    ָ�룬����STROBE�źŵ�ǰ����Ч���ԡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus   CameraGetStrobePolarity(
    CameraHandle    hCamera,
    INT*            upPolarity
);

/******************************************************/
// ������ 	: CameraSetExtTrigSignalType
// ��������	: ��������ⴥ���źŵ����ࡣ�ϱ��ء��±��ء����߸ߡ��͵�ƽ��ʽ��
// ����	    : hCamera   ����ľ������CameraInit������á�
//             iType     �ⴥ���ź����࣬����ֵ�ο�CameraDefine.h��
//                       emExtTrigSignal���Ͷ��塣

// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus   CameraSetExtTrigSignalType(
    CameraHandle    hCamera,
    INT             iType
);

/******************************************************/
// ������ 	: CameraGetExtTrigSignalType
// ��������	: ��������ǰ�ⴥ���źŵ����ࡣ
// ����	    : hCamera   ����ľ������CameraInit������á�
//             ipType    ָ�룬�����ⴥ���ź����࣬����ֵ�ο�CameraDefine.h��
//                       emExtTrigSignal���Ͷ��塣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus   CameraGetExtTrigSignalType(
    CameraHandle    hCamera,
    INT*            ipType
);

/******************************************************/
// ������ 	: CameraSetExtTrigShutterType
// ��������	: �����ⴥ��ģʽ�£�������ŵķ�ʽ��Ĭ��Ϊ��׼���ŷ�ʽ��
//              ���ֹ������ŵ�CMOS���֧��GRR��ʽ��
// ����	    : hCamera   ����ľ������CameraInit������á�
//             iType     �ⴥ�����ŷ�ʽ���ο�CameraDefine.h��emExtTrigShutterMode���͡�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus   CameraSetExtTrigShutterType(
    CameraHandle    hCamera,
    INT             iType
);

/******************************************************/
// ������ 	: CameraSetExtTrigShutterType
// ��������	: ����ⴥ��ģʽ�£�������ŵķ�ʽ��Ĭ��Ϊ��׼���ŷ�ʽ��
//              ���ֹ������ŵ�CMOS���֧��GRR��ʽ��
// ����	    : hCamera   ����ľ������CameraInit������á�
//             ipType    ָ�룬���ص�ǰ�趨���ⴥ�����ŷ�ʽ������ֵ�ο�
//                       CameraDefine.h��emExtTrigShutterMode���͡�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus   CameraGetExtTrigShutterType(
    CameraHandle    hCamera,
    INT*            ipType
);

/******************************************************/
// ������ 	: CameraSetExtTrigDelayTime
// ��������	: �����ⴥ���ź���ʱʱ�䣬Ĭ��Ϊ0����λΪ΢�롣
//              �����õ�ֵuDelayTimeUs��Ϊ0ʱ��������յ��ⴥ���źź󣬽���ʱuDelayTimeUs��΢����ٽ���ͼ�񲶻�
// ����	    : hCamera       ����ľ������CameraInit������á�
//             uDelayTimeUs  ��ʱʱ�䣬��λΪ΢�룬Ĭ��Ϊ0.
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus   CameraSetExtTrigDelayTime(
    CameraHandle    hCamera,
    UINT            uDelayTimeUs
);

/******************************************************/
// ������ 	: CameraGetExtTrigDelayTime
// ��������	: ������õ��ⴥ���ź���ʱʱ�䣬Ĭ��Ϊ0����λΪ΢�롣
// ����	    : hCamera   ����ľ������CameraInit������á�
//            UINT* upDelayTimeUs
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus   CameraGetExtTrigDelayTime(
    CameraHandle    hCamera,
    UINT*           upDelayTimeUs
);

/******************************************************/
// ������ 	: CameraSetExtTrigJitterTime
// ��������	: ��������ⴥ���źŵ�����ʱ�䡣Ĭ��Ϊ0����λΪ΢�롣
// ����	    : hCamera   ����ľ������CameraInit������á�
//            UINT uTimeUs
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus   CameraSetExtTrigJitterTime(
    CameraHandle    hCamera,
    UINT            uTimeUs
);

/******************************************************/
// ������ 	: CameraGetExtTrigJitterTime
// ��������	: ������õ�����ⴥ������ʱ�䣬Ĭ��Ϊ0.��λΪ΢��
// ����	    : hCamera   ����ľ������CameraInit������á�
//            UINT* upTimeUs
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus   CameraGetExtTrigJitterTime(
    CameraHandle    hCamera,
    UINT*           upTimeUs
);

/******************************************************/
// ������ 	: CameraGetExtTrigCapability
// ��������	: �������ⴥ������������
// ����	    : hCamera           ����ľ������CameraInit������á�
//             puCapabilityMask  ָ�룬���ظ�����ⴥ���������룬����ο�CameraDefine.h��
//                               EXT_TRIG_MASK_ ��ͷ�ĺ궨�塣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus   CameraGetExtTrigCapability(
    CameraHandle    hCamera,
    UINT*           puCapabilityMask
);


/******************************************************/
// ������   : CameraGetResolutionForSnap
// �������� : ���ץ��ģʽ�µķֱ���ѡ�������š�
// ����     : hCamera        ����ľ������CameraInit������á�
//            pImageResolution ָ�룬����ץ��ģʽ�ķֱ��ʡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetResolutionForSnap(
    CameraHandle            hCamera,
    tSdkImageResolution*    pImageResolution
);

/******************************************************/
// ������   : CameraSetResolutionForSnap
// �������� : ����ץ��ģʽ��������ͼ��ķֱ��ʡ�
// ����     : hCamera       ����ľ������CameraInit������á�
//            pImageResolution ���pImageResolution->iWidth
//                 �� pImageResolution->iHeight��Ϊ0��
//                         ���ʾ�趨Ϊ���浱ǰԤ���ֱ��ʡ�ץ
//                         �µ���ͼ��ķֱ��ʻ�͵�ǰ�趨��
//                 Ԥ���ֱ���һ����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetResolutionForSnap(
    CameraHandle            hCamera,
    tSdkImageResolution*    pImageResolution
);

/******************************************************/
// ������   : CameraCustomizeResolution
// �������� : �򿪷ֱ����Զ�����壬��ͨ�����ӻ��ķ�ʽ
//        ������һ���Զ���ֱ��ʡ�
// ����     : hCamera    ����ľ������CameraInit������á�
//            pImageCustom ָ�룬�����Զ���ķֱ��ʡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraCustomizeResolution(
    CameraHandle            hCamera,
    tSdkImageResolution*    pImageCustom
);

/******************************************************/
// ������   : CameraCustomizeReferWin
// �������� : �򿪲ο������Զ�����塣��ͨ�����ӻ��ķ�ʽ��
//        ���һ���Զ��崰�ڵ�λ�á�һ�������Զ����ƽ��
//        ���Զ��ع�Ĳο����ڡ�
// ����     : hCamera  ����ľ������CameraInit������á�
//            iWinType   Ҫ���ɵĲο����ڵ���;��0,�Զ��ع�ο����ڣ�
//             1,��ƽ��ο����ڡ�
//            hParent    ���øú����Ĵ��ڵľ��������ΪNULL��
//            piHOff     ָ�룬�����Զ��崰�ڵ����ϽǺ����ꡣ
//            piVOff     ָ�룬�����Զ��崰�ڵ����Ͻ������ꡣ
//            piWidth    ָ�룬�����Զ��崰�ڵĿ�ȡ�
//            piHeight   ָ�룬�����Զ��崰�ڵĸ߶ȡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraCustomizeReferWin(
    CameraHandle    hCamera,
    INT             iWinType,
    HWND            hParent,
    INT*            piHOff,
    INT*            piVOff,
    INT*            piWidth,
    INT*            piHeight
);

/******************************************************/
// ������   : CameraShowSettingPage
// �������� : ��������������ô�����ʾ״̬�������ȵ���CameraCreateSettingPage
//        �ɹ���������������ô��ں󣬲��ܵ��ñ���������
//        ��ʾ��
// ����     : hCamera  ����ľ������CameraInit������á�
//            bShow    TRUE����ʾ;FALSE�����ء�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraShowSettingPage(
    CameraHandle    hCamera,
    BOOL            bShow
);

/******************************************************/
// ������   : CameraCreateSettingPage
// �������� : ������������������ô��ڡ����øú�����SDK�ڲ���
//        ������������������ô��ڣ�ʡȥ�������¿������
//        ���ý����ʱ�䡣ǿ�ҽ���ʹ����ʹ�øú�����
//        SDKΪ�����������ô��ڡ�
// ����     : hCamera     ����ľ������CameraInit������á�
//            hParent       Ӧ�ó��������ڵľ��������ΪNULL��
//            pWinText      �ַ���ָ�룬������ʾ�ı�������
//            pCallbackFunc ������Ϣ�Ļص�����������Ӧ���¼�����ʱ��
//              pCallbackFunc��ָ��ĺ����ᱻ���ã�
//              �����л��˲���֮��Ĳ���ʱ��pCallbackFunc
//              ���ص�ʱ������ڲ�����ָ������Ϣ���͡�
//              �������Է������Լ������Ľ�����������ɵ�UI
//              ֮�����ͬ�����ò�������ΪNULL��
//            pCallbackCtx  �ص������ĸ��Ӳ���������ΪNULL��pCallbackCtx
//              ����pCallbackFunc���ص�ʱ����Ϊ����֮һ���롣
//              ������ʹ�øò�������һЩ�����жϡ�
//            uReserved     Ԥ������������Ϊ0��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraCreateSettingPage(
    CameraHandle            hCamera,
    HWND                    hParent,
    char*                   pWinText,
    CAMERA_PAGE_MSG_PROC    pCallbackFunc,
    PVOID                   pCallbackCtx,
    UINT                    uReserved
);

/******************************************************/
// ������   : CameraCreateSettingPageEx
// �������� : ������������������ô��ڡ����øú�����SDK�ڲ���
//        ������������������ô��ڣ�ʡȥ�������¿������
//        ���ý����ʱ�䡣ǿ�ҽ���ʹ����ʹ�øú�����
//        SDKΪ�����������ô��ڡ�
// ����     : hCamera     ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraCreateSettingPageEx(
    CameraHandle            hCamera
);


/******************************************************/
// ������   : CameraSetActiveSettingSubPage
// �������� : ����������ô��ڵļ���ҳ�档������ô����ж��
//        ��ҳ�湹�ɣ��ú��������趨��ǰ��һ����ҳ��
//        Ϊ����״̬����ʾ����ǰ�ˡ�
// ����     : hCamera  ����ľ������CameraInit������á�
//            index      ��ҳ��������š��ο�CameraDefine.h��
//             PROP_SHEET_INDEX�Ķ��塣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetActiveSettingSubPage(
    CameraHandle    hCamera,
    INT             index
);

/******************************************************/
// ������   : CameraSpecialControl
// �������� : ���һЩ�������������õĽӿڣ����ο���ʱһ�㲻��Ҫ
//        ���á�
// ����     : hCamera  ����ľ������CameraInit������á�
//            dwCtrlCode �����롣
//            dwParam    �������룬��ͬ��dwCtrlCodeʱ�����岻ͬ��
//            lpData     ���Ӳ�������ͬ��dwCtrlCodeʱ�����岻ͬ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSpecialControl(
    CameraHandle    hCamera,
    DWORD           dwCtrlCode,
    DWORD           dwParam,
    LPVOID          lpData
);

/******************************************************/
// ������   : CameraGetFrameStatistic
// �������� : ����������֡�ʵ�ͳ����Ϣ����������֡�Ͷ�֡�������
// ����     : hCamera        ����ľ������CameraInit������á�
//            psFrameStatistic ָ�룬����ͳ����Ϣ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetFrameStatistic(
    CameraHandle            hCamera,
    tSdkFrameStatistic*     psFrameStatistic
);

/******************************************************/
// ������   : CameraSetNoiseFilter
// �������� : ����ͼ����ģ���ʹ��״̬��
// ����     : hCamera ����ľ������CameraInit������á�
//            bEnable   TRUE��ʹ�ܣ�FALSE����ֹ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetNoiseFilter(
    CameraHandle    hCamera,
    BOOL            bEnable
);

/******************************************************/
// ������   : CameraGetNoiseFilterState
// �������� : ���ͼ����ģ���ʹ��״̬��
// ����     : hCamera  ����ľ������CameraInit������á�
//            *pEnable   ָ�룬����״̬��TRUE��Ϊʹ�ܡ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetNoiseFilterState(
    CameraHandle    hCamera,
    BOOL*           pEnable
);

/******************************************************/
// ������   : CameraRstTimeStamp
// �������� : ��λͼ��ɼ���ʱ�������0��ʼ��
// ����     : CameraHandle hCamera
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraRstTimeStamp(
    CameraHandle    hCamera
);

/******************************************************/
// ������   : CameraSaveUserData
// �������� : ���û��Զ�������ݱ��浽����ķ����Դ洢���С�
//              ÿ���ͺŵ��������֧�ֵ��û���������󳤶Ȳ�һ����
//              ���Դ��豸�����������л�ȡ�ó�����Ϣ��
// ����     : hCamera    ����ľ������CameraInit������á�
//            uStartAddr  ��ʼ��ַ����0��ʼ��
//            pbData      ���ݻ�����ָ��
//            ilen        д�����ݵĳ��ȣ�ilen + uStartAddr����
//                        С���û�����󳤶�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSaveUserData(
    CameraHandle    hCamera,
    UINT            uStartAddr,
    BYTE            *pbData,
    int             ilen
);

/******************************************************/
// ������   : CameraLoadUserData
// �������� : ������ķ����Դ洢���ж�ȡ�û��Զ�������ݡ�
//              ÿ���ͺŵ��������֧�ֵ��û���������󳤶Ȳ�һ����
//              ���Դ��豸�����������л�ȡ�ó�����Ϣ��
// ����     : hCamera    ����ľ������CameraInit������á�
//            uStartAddr  ��ʼ��ַ����0��ʼ��
//            pbData      ���ݻ�����ָ�룬���ض��������ݡ�
//            ilen        ��ȡ���ݵĳ��ȣ�ilen + uStartAddr����
//                        С���û�����󳤶�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraLoadUserData(
    CameraHandle    hCamera,
    UINT            uStartAddr,
    BYTE            *pbData,
    int             ilen
);

/******************************************************/
// ������   : CameraGetFriendlyName
// �������� : ��ȡ�û��Զ�����豸�ǳơ�
// ����     : hCamera    ����ľ������CameraInit������á�
//            pName      ָ�룬����ָ��0��β���ַ�����
//             �豸�ǳƲ�����32���ֽڣ���˸�ָ��
//             ָ��Ļ�����������ڵ���32���ֽڿռ䡣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetFriendlyName(
  CameraHandle  hCamera,
  char*     pName
);

/******************************************************/
// ������   : CameraSetFriendlyName
// �������� : �����û��Զ�����豸�ǳơ�
// ����     : hCamera    ����ľ������CameraInit������á�
//            pName      ָ�룬ָ��0��β���ַ�����
//             �豸�ǳƲ�����32���ֽڣ���˸�ָ��
//             ָ���ַ�������С�ڵ���32���ֽڿռ䡣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetFriendlyName(
  CameraHandle  hCamera,
  char*       pName
);

/******************************************************/
// ������   : CameraSdkGetVersionString
// �������� :
// ����     : pVersionString ָ�룬����SDK�汾�ַ�����
//                            ��ָ��ָ��Ļ�������С�������
//                            32���ֽ�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSdkGetVersionString(
  char*       pVersionString
);

/******************************************************/
// ������   : CameraCheckFwUpdate
// �������� : ���̼��汾���Ƿ���Ҫ������
// ����     : hCamera ����ľ������CameraInit������á�
//            pNeedUpdate ָ�룬���ع̼����״̬��TRUE��ʾ��Ҫ����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraCheckFwUpdate(
  CameraHandle  hCamera,
  BOOL*     pNeedUpdate
);

/******************************************************/
// ������   : CameraGetFirmwareVision
// �������� : ��ù̼��汾���ַ���
// ����     : hCamera ����ľ������CameraInit������á�
//            pVersion ����ָ��һ������32�ֽڵĻ�������
//                      ���ع̼��İ汾�ַ�����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetFirmwareVersion(
  CameraHandle  hCamera,
  char*     pVersion
);

/******************************************************/
// ������   : CameraGetEnumInfo
// �������� : ���ָ���豸��ö����Ϣ
// ����     : hCamera ����ľ������CameraInit������á�
//            pCameraInfo ָ�룬�����豸��ö����Ϣ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetEnumInfo(
  CameraHandle    hCamera,
  tSdkCameraDevInfo*  pCameraInfo
);

/******************************************************/
// ������   : CameraGetInerfaceVersion
// �������� : ���ָ���豸�ӿڵİ汾
// ����     : hCamera ����ľ������CameraInit������á�
//            pVersion ָ��һ������32�ֽڵĻ����������ؽӿڰ汾�ַ�����
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetInerfaceVersion(
  CameraHandle    hCamera,
  char*       pVersion
);

/******************************************************/
// ������   : CameraSetIOState
// �������� : ����ָ��IO�ĵ�ƽ״̬��IOΪ�����IO�����
//              Ԥ���ɱ�����IO�ĸ�����tSdkCameraCapbility��
//              iOutputIoCounts������
// ����     : hCamera ����ľ������CameraInit������á�
//            iOutputIOIndex IO�������ţ���0��ʼ��
//            uState Ҫ�趨��״̬��1Ϊ�ߣ�0Ϊ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetIOState(
  CameraHandle    hCamera,
  INT         iOutputIOIndex,
  UINT        uState
);

/******************************************************/
// ������   : CameraGetIOState
// �������� : ����ָ��IO�ĵ�ƽ״̬��IOΪ������IO�����
//              Ԥ���ɱ�����IO�ĸ�����tSdkCameraCapbility��
//              iInputIoCounts������
// ����     : hCamera ����ľ������CameraInit������á�
//            iInputIOIndex IO�������ţ���0��ʼ��
//            puState ָ�룬����IO״̬,1Ϊ�ߣ�0Ϊ��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetIOState(
  CameraHandle    hCamera,
  INT         iInputIOIndex,
  UINT*         puState
);



/******************************************************/
// ������   : CameraSetInPutIOMode
// �������� : ��������IO��ģʽ�����
//              Ԥ���ɱ�����IO�ĸ�����tSdkCameraCapbility��
//              iInputIoCounts������
// ����     : hCamera ����ľ������CameraInit������á�
//            iInputIOIndex IO�������ţ���0��ʼ��
//            iMode IOģʽ,�ο�CameraDefine.h��emCameraGPIOMode
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetInPutIOMode(
	CameraHandle    hCamera,
	INT         iInputIOIndex,
	INT			iMode
	);

/******************************************************/
// ������   : CameraSetOutPutIOMode
// �������� : �������IO��ģʽ�����
//              Ԥ���ɱ�����IO�ĸ�����tSdkCameraCapbility��
//              iOutputIoCounts������
// ����     : hCamera ����ľ������CameraInit������á�
//            iOutputIOIndex IO�������ţ���0��ʼ��
//            iMode IOģʽ,�ο�CameraDefine.h��emCameraGPIOMode
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetOutPutIOMode(
	CameraHandle    hCamera,
	INT         iOutputIOIndex,
	INT			iMode
	);

/******************************************************/
// ������   : CameraSetOutPutPWM
// �������� : ����PWM������Ĳ��������
//              Ԥ���ɱ�����IO�ĸ�����tSdkCameraCapbility��
//              iOutputIoCounts������
// ����     : hCamera ����ľ������CameraInit������á�
//            iOutputIOIndex IO�������ţ���0��ʼ��
//            iCycle PWM�����ڣ���λ(us)
//			  uDuty  ռ�ñȣ�ȡֵ1%~99%
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetOutPutPWM(
	CameraHandle    hCamera,
	INT         iOutputIOIndex,
	UINT		iCycle,
	UINT		uDuty
	);


/******************************************************/
// ������   : CameraSetAeAlgorithm
// �������� : �����Զ��ع�ʱѡ����㷨����ͬ���㷨������
//        ��ͬ�ĳ�����
// ����     : hCamera       ����ľ������CameraInit������á�
//            iIspProcessor   ѡ��ִ�и��㷨�Ķ��󣬲ο�CameraDefine.h
//                emSdkIspProcessor�Ķ���
//            iAeAlgorithmSel   Ҫѡ����㷨��š���0��ʼ�����ֵ��tSdkCameraCapbility
//                ��iAeAlmSwDesc��iAeAlmHdDesc������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetAeAlgorithm(
    CameraHandle    hCamera,
    INT             iIspProcessor,
    INT             iAeAlgorithmSel
);

/******************************************************/
// ������   : CameraGetAeAlgorithm
// �������� : ��õ�ǰ�Զ��ع���ѡ����㷨
// ����     : hCamera       ����ľ������CameraInit������á�
//            iIspProcessor   ѡ��ִ�и��㷨�Ķ��󣬲ο�CameraDefine.h
//                emSdkIspProcessor�Ķ���
//            piAeAlgorithmSel  ���ص�ǰѡ����㷨��š���0��ʼ�����ֵ��tSdkCameraCapbility
//                ��iAeAlmSwDesc��iAeAlmHdDesc������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetAeAlgorithm(
    CameraHandle    hCamera,
    INT             iIspProcessor,
    INT*            piAlgorithmSel
);

/******************************************************/
// ������   : CameraSetBayerDecAlgorithm
// �������� : ����Bayer����ת��ɫ���㷨��
// ����     : hCamera       ����ľ������CameraInit������á�
//            iIspProcessor   ѡ��ִ�и��㷨�Ķ��󣬲ο�CameraDefine.h
//                emSdkIspProcessor�Ķ���
//            iAlgorithmSel     Ҫѡ����㷨��š���0��ʼ�����ֵ��tSdkCameraCapbility
//                ��iBayerDecAlmSwDesc��iBayerDecAlmHdDesc������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetBayerDecAlgorithm(
    CameraHandle    hCamera,
    INT             iIspProcessor,
    INT             iAlgorithmSel
);

/******************************************************/
// ������   : CameraGetBayerDecAlgorithm
// �������� : ���Bayer����ת��ɫ��ѡ����㷨��
// ����     : hCamera       ����ľ������CameraInit������á�
//            iIspProcessor   ѡ��ִ�и��㷨�Ķ��󣬲ο�CameraDefine.h
//                emSdkIspProcessor�Ķ���
//            piAlgorithmSel    ���ص�ǰѡ����㷨��š���0��ʼ�����ֵ��tSdkCameraCapbility
//                ��iBayerDecAlmSwDesc��iBayerDecAlmHdDesc������
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetBayerDecAlgorithm(
    CameraHandle    hCamera,
    INT             iIspProcessor,
    INT*            piAlgorithmSel
);

/******************************************************/
// ������   : CameraSetIspProcessor
// �������� : ����ͼ����Ԫ���㷨ִ�ж�����PC�˻��������
//        ��ִ���㷨�����������ִ��ʱ���ή��PC�˵�CPUռ���ʡ�
// ����     : hCamera   ����ľ������CameraInit������á�
//            iIspProcessor �ο�CameraDefine.h��
//              emSdkIspProcessor�Ķ��塣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetIspProcessor(
    CameraHandle    hCamera,
    INT             iIspProcessor
);

/******************************************************/
// ������   : CameraGetIspProcessor
// �������� : ���ͼ����Ԫ���㷨ִ�ж���
// ����     : hCamera    ����ľ������CameraInit������á�
//            piIspProcessor ����ѡ��Ķ��󣬷���ֵ�ο�CameraDefine.h��
//               emSdkIspProcessor�Ķ��塣
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetIspProcessor(
    CameraHandle    hCamera,
    INT*            piIspProcessor
);

/******************************************************/
// ������   : CameraSetBlackLevel
// �������� : ����ͼ��ĺڵ�ƽ��׼��Ĭ��ֵΪ0
// ����     : hCamera   ����ľ������CameraInit������á�
//            iBlackLevel Ҫ�趨�ĵ�ƽֵ����ΧΪ0��255��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetBlackLevel(
  CameraHandle    hCamera,
  INT         iBlackLevel
);

/******************************************************/
// ������   : CameraGetBlackLevel
// �������� : ���ͼ��ĺڵ�ƽ��׼��Ĭ��ֵΪ0
// ����     : hCamera    ����ľ������CameraInit������á�
//            piBlackLevel ���ص�ǰ�ĺڵ�ƽֵ����ΧΪ0��255��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetBlackLevel(
  CameraHandle    hCamera,
  INT*        piBlackLevel
);

/******************************************************/
// ������   : CameraSetWhiteLevel
// �������� : ����ͼ��İ׵�ƽ��׼��Ĭ��ֵΪ255
// ����     : hCamera   ����ľ������CameraInit������á�
//            iWhiteLevel Ҫ�趨�ĵ�ƽֵ����ΧΪ0��255��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetWhiteLevel(
  CameraHandle    hCamera,
  INT         iWhiteLevel
);

/******************************************************/
// ������   : CameraGetWhiteLevel
// �������� : ���ͼ��İ׵�ƽ��׼��Ĭ��ֵΪ255
// ����     : hCamera    ����ľ������CameraInit������á�
//            piWhiteLevel ���ص�ǰ�İ׵�ƽֵ����ΧΪ0��255��
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetWhiteLevel(
  CameraHandle    hCamera,
  INT*        piWhiteLevel
);

/******************************************************/
// ������ 	: CameraSetIspOutFormat
// ��������	: ����CameraGetImageBuffer������ͼ����������ʽ��֧��
//              CAMERA_MEDIA_TYPE_MONO8��CAMERA_MEDIA_TYPE_RGB8
//              (��CameraDefine.h�ж���)���֣��ֱ��Ӧ8λ�Ҷ�ͼ���24λ��ɫͼ��
// ����	    : hCamera		����ľ������CameraInit������á�
//             uFormat	Ҫ�趨��ʽ��CAMERA_MEDIA_TYPE_MONO8����CAMERA_MEDIA_TYPE_RGB8
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraSetIspOutFormat(
    CameraHandle    hCamera,
    UINT            uFormat
);

/******************************************************/
// ������ 	: CameraGetIspOutFormat
// ��������	: ���ͼ����������ʽ��Ŀǰֻ֧��
//              CAMERA_MEDIA_TYPE_MONO8��CAMERA_MEDIA_TYPE_RGB8
//              (��CameraDefine.h�ж���)���֣������Ĳ����᷵�ش���
// ����	    : hCamera		����ľ������CameraInit������á�
//             puFormat	���ص�ǰ�趨�ĸ�ʽ��CAMERA_MEDIA_TYPE_MONO8����CAMERA_MEDIA_TYPE_RGB8
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraGetIspOutFormat(
    CameraHandle    hCamera,
    UINT*           puFormat
);

/******************************************************/
// ������ 	: CameraGetErrorString
// ��������	: ��ô������Ӧ�������ַ���
// ����	    : iStatusCode		�����롣(������CameraStatus.h��)
// ����ֵ   : �ɹ�ʱ�����ش������Ӧ���ַ����׵�ַ;
//            ���򷵻�NULL��
/******************************************************/
MVSDK_API char*  CameraGetErrorString(
    CameraSdkStatus     iStatusCode
);


/******************************************************/
// ������ 	: CameraReConnect
// ��������	: ���������豸������USB�豸������ߺ�����
// ����	    : hCamera	   ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus CameraReConnect(
    CameraHandle    hCamera
);


/******************************************************/
// ������ 	: CameraConnectTest
// ��������	: �������������״̬�����ڼ������Ƿ����
// ����	    : hCamera	   ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus CameraConnectTest(
    CameraHandle    hCamera
);

/******************************************************/
// ������   : CameraCommonCall
// �������� : �����һЩ���⹦�ܵ��ã����ο���ʱһ�㲻��Ҫ���á�
// ����     : hCamera   ����ľ������CameraInit������á�
//            pszCall   ���ܼ�����
//            pszResult ���ý������ͬ��pszCallʱ�����岻ͬ��
//            uResultBufSize pszResultָ��Ļ��������ֽڴ�С
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0);
//            ���򷵻ط�0ֵ�Ĵ�����,��ο�CameraStatus.h
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus  CameraCommonCall(
	CameraHandle    hCamera,
	char const*		pszCall,
	char*			pszResult,
	UINT			uResultBufSize
);

/******************************************************/
// ������ 	: GetEyeCount
// ��������	: ��ȡ��Ŀ��������
// ����	    : hCamera	   ����ľ������CameraInit������á�
// ����ֵ   : �ɹ�ʱ������CAMERA_STATUS_SUCCESS (0)����ʾ�������״̬����;
//            ���򷵻� CAMERA_STATUS_TIME_OUT(-22)
//            �д�����Ķ��塣
/******************************************************/
MVSDK_API CameraSdkStatus GetEyeCount(
CameraHandle hCamera, 
int *eyecount
);

#ifdef __cplusplus
}
#endif
#endif

