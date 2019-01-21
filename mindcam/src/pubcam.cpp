#include<ros/ros.h>//ros standard lib header file
#include<iostream>//C++ standard io lib file

/*
cv_bridge include CvBridge lib
*/
#include<cv_bridge/cv_bridge.h>
/*
the encoding function of ROS image format 
*/
#include<sensor_msgs/image_encodings.h>
/*
image_transport header file is used to publish and subscribe image msg on topic of ros system
*/
#include<image_transport/image_transport.h>

//OpenCV2 standard header file
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include <CameraApi.h>
//camera SDK  API header file

unsigned char * g_pRgbBuffer[2];

int main(int argc,char **argv)
{
    //-----------------------------------------------------ros-----------------------------------------------------
    ros::init(argc, argv, "pubcam");
    ros::NodeHandle n;
    //-----------------------------------------------------ros-----------------------------------------------------
    int                     iCameraCounts=2;
    //-----------------------------------------------------ros-----------------------------------------------------
    //2 创建ROS中图像的发布者
    image_transport::ImageTransport it( n ); 
    image_transport::Publisher pubcam1 = it.advertise( "mindcamera/image1", 1 );
    image_transport::Publisher pubcam0 = it.advertise( "mindcamera/image0", 1 );
    //-----------------------------------------------------ros-----------------------------------------------------
    
    int                     iStatus[iCameraCounts]={-1,-1};
    // int                     iStatus=-1;       //---------------------------------single camera
    // tSdkCameraDevInfo       tCameraEnumList;  //---------------------------------single camera
    // int                     hCamera;          //---------------------------------single camera
    tSdkCameraDevInfo       tCameraEnumList[iCameraCounts];
    int                     hCamera[iCameraCounts]={-1,-1};
    tSdkCameraCapbility     tCapability[iCameraCounts];      //设备描述信息
    tSdkFrameHead           sFrameInfo[iCameraCounts];
    BYTE*			        pbyBuffer[iCameraCounts];
    int                     iDisplayFrames = 10000;
    IplImage *iplImage[iCameraCounts] = {NULL,NULL};
    int                     channel=3;

    CameraSdkInit(1);

    //枚举设备，并建立设备列表
    // iStatus = CameraEnumerateDevice(&tCameraEnumList,&iCameraCounts); //---------------------------------single camera
    iStatus[1] = CameraEnumerateDevice(tCameraEnumList,&iCameraCounts);
	printf("state = %d\n", iStatus[1]);

	printf("count = %d\n", iCameraCounts);
    //没有连接设备
    if(iCameraCounts==0){
        return -1;
    }

    //相机初始化。初始化成功后，才能调用任何其他相机相关的操作接口
    //CameraInit(
    //     tSdkCameraDevInfo* pCameraInfo,
    //     int                emParamLoadMode, -1 means that load by lastly Mode
    //     int                emTeam,           -1 means that load lastly paramTeam
    //     CameraHandle*      pCameraHandle,
    //);
    printf("new!!!!!!!!!!!!!!!!!!!!!\n");
    for(int i=0;i<=1;i++){
        iStatus[i] = CameraInit(&tCameraEnumList[i],-1,-1,&hCamera[i]);
        printf("state[%d] = %d\n", i,iStatus[i]);
        if(iStatus[i]!=CAMERA_STATUS_SUCCESS){
            return -1;
        }

        // iStatus[1] = CameraInit(&tCameraEnumList[1],-1,-1,&hCamera[1]);

        // //初始化失败
        // printf("state[1] = %d\n", iStatus[1]);
        // if(iStatus[1]!=CAMERA_STATUS_SUCCESS){
        //     return -1;
        // }

        //获得相机的特性描述结构体。该结构体中包含了相机可设置的各种参数的范围信息。决定了相关函数的参数
        CameraGetCapability(hCamera[i],&tCapability[i]);
        // CameraGetCapability(hCamera[1],&tCapability[1]);

        //
        g_pRgbBuffer[i] = (unsigned char*)malloc(tCapability[i].sResolutionRange.iHeightMax*tCapability[i].sResolutionRange.iWidthMax*3);
        // g_pRgbBuffer[1] = (unsigned char*)malloc(tCapability[1].sResolutionRange.iHeightMax*tCapability[1].sResolutionRange.iWidthMax*3);
        //g_readBuf = (unsigned char*)malloc(tCapability.sResolutionRange.iHeightMax*tCapability.sResolutionRange.iWidthMax*3);
        // 3 means 3 color channel???

        /*让SDK进入工作模式，开始接收来自相机发送的图像
        数据。如果当前相机是触发模式，则需要接收到
        触发帧以后才会更新图像。    */
        CameraPlay(hCamera[i]);
        // CameraPlay(hCamera[1]);

        /*其他的相机参数设置
        例如 CameraSetExposureTime   CameraGetExposureTime  设置/读取曝光时间
            CameraSetImageResolution  CameraGetImageResolution 设置/读取分辨率
            CameraSetGamma、CameraSetConrast、CameraSetGain等设置图像伽马、对比度、RGB数字增益等等。
            更多的参数的设置方法，，清参考MindVision_Demo。本例程只是为了演示如何将SDK中获取的图像，转成OpenCV的图像格式,以便调用OpenCV的图像处理函数进行后续开发
        */

        //bool bMonoSensor; Is this camera a black&white camera? Yes,then the function about color couldn't use
        
        if(tCapability[i].sIspCapacity.bMonoSensor){
            channel=1;
            CameraSetIspOutFormat(hCamera[i],CAMERA_MEDIA_TYPE_MONO8);
        }else{
            channel=3;
            CameraSetIspOutFormat(hCamera[i],CAMERA_MEDIA_TYPE_BGR8);
        }

    
    }
    

    
    cv::Mat Iimag[iCameraCounts];
    

    //----------------------------------------------break while----------------------------------------------
    //CameraGetImageBuffer  get 1 frame Image Data

    // if(CameraGetImageBuffer(hCamera,&sFrameInfo,&pbyBuffer,1000) == CAMERA_STATUS_SUCCESS)
	// 	{
	// 	    CameraImageProcess(hCamera, pbyBuffer, g_pRgbBuffer,&sFrameInfo);
	// 	    if (iplImage)
    //         {
    //             cvReleaseImageHeader(&iplImage);
    //         }
    //         iplImage = cvCreateImageHeader(cvSize(sFrameInfo.iWidth,sFrameInfo.iHeight),IPL_DEPTH_8U,channel);
    //         cvSetData(iplImage,g_pRgbBuffer,sFrameInfo.iWidth*channel);//此处只是设置指针，无图像块数据拷贝，不需担心转换效率
    //         //以下两种方式都可以显示图像或者处理图像
    //         #if 0
    //         cvShowImage("OpenCV Demo",iplImage);
    //         #else
    //         Iimag = cv::cvarrToMat(iplImage);//这里只是进行指针转换，将IplImage转换成Mat类型
    //         // imshow("OpenCV Demo",Iimag);
    //         //-----------------------------------------------------ros-----------------------------------------------------
    //         //3 cv:: Mat to ros::img
    //         sensor_msgs::ImagePtr msg;
    //         // ros::Rate loop_rate(5);
    //         while(n.ok()){
    //             msg = cv_bridge::CvImage(std_msgs::Header() , "bgr8", Iimag).toImageMsg();
    //             pubcam.publish(msg);

    //             // if(!Iimag.empty()){
    //             //     msg = cv_bridge::CvImage(std_msgs::Header() , "bgr8", Iimag).toImageMsg();
    //             //     pubcam.publish(msg);
    //             // }
    //             // ros::spinOnce();
    //             // loop_rate.sleep();
    //         }
    //         //-----------------------------------------------------ros-----------------------------------------------------
            
    //         #endif

    //         // cv::waitKey(5);

    //         //在成功调用CameraGetImageBuffer后，必须调用CameraReleaseImageBuffer来释放获得的buffer。
	// 		//否则再次调用CameraGetImageBuffer时，程序将被挂起一直阻塞，直到其他线程中调用CameraReleaseImageBuffer来释放了buffer
	// 		CameraReleaseImageBuffer(hCamera,pbyBuffer);

	// 	}

    //----------------------------------------------break while----------------------------------------------
    
    //循环显示1000帧图像
    while(iDisplayFrames--)
    {
        for(int i=0;i<=1;i++){
            // int i=1;
            if(CameraGetImageBuffer(hCamera[i],&sFrameInfo[i],&pbyBuffer[i],1000) == CAMERA_STATUS_SUCCESS)
            {
                CameraImageProcess(hCamera[i], pbyBuffer[i], g_pRgbBuffer[i],&sFrameInfo[i]);
                if (iplImage[i])
                {
                    cvReleaseImageHeader(&iplImage[i]);
                }
                iplImage[i] = cvCreateImageHeader(cvSize(sFrameInfo[i].iWidth,sFrameInfo[i].iHeight),IPL_DEPTH_8U,channel);
                cvSetData(iplImage[i],g_pRgbBuffer[i],sFrameInfo[i].iWidth*channel);//此处只是设置指针，无图像块数据拷贝，不需担心转换效率
                //以下两种方式都可以显示图像或者处理图像
                #if 0
                cvShowImage("OpenCV Demo",iplImage);
                #else
                Iimag[i] = cv::cvarrToMat(iplImage[i]);//这里只是进行指针转换，将IplImage转换成Mat类型
                // imshow("OpenCV Demo",Iimag);
                //-----------------------------------------------------ros-----------------------------------------------------
                //3 cv:: Mat to ros::img
                sensor_msgs::ImagePtr msg;
                // ros::Rate loop_rate(5);
                //while(n.ok()){

                if(!Iimag[i].empty()){
                    msg = cv_bridge::CvImage(std_msgs::Header() , "bgr8", Iimag[i]).toImageMsg();
                    if(i==0){
                        pubcam0.publish(msg);
                    }
                    else{
                        pubcam1.publish(msg);
                    }
                    
                }
                    // ros::spinOnce();
                    // loop_rate.sleep();
                //}
                //-----------------------------------------------------ros-----------------------------------------------------
                
                #endif

                cv::waitKey(5);

                //在成功调用CameraGetImageBuffer后，必须调用CameraReleaseImageBuffer来释放获得的buffer。
                //否则再次调用CameraGetImageBuffer时，程序将被挂起一直阻塞，直到其他线程中调用CameraReleaseImageBuffer来释放了buffer
                
                CameraReleaseImageBuffer(hCamera[i],pbyBuffer[i]);

            }
        }

    }

    
    for(int i=0;i<=1;i++){
        CameraUnInit(hCamera[i]);
        //注意，现反初始化后再free
        free(g_pRgbBuffer[i]);
    }
    


    return 0;

}