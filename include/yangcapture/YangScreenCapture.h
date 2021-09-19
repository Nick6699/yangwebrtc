/*
 * YangScreenCaptureLinux.h
 *
 *  Created on: 2020年8月30日
 *      Author: yang
 */

#ifndef INCLUDE_YANGCAPTURE_YANGSCREENCAPTURE_H_
#define INCLUDE_YANGCAPTURE_YANGSCREENCAPTURE_H_

#include "yangutil/buffer/YangVideoBuffer.h"
#include "yangutil/sys/YangThread.h"
#include "YangScreenCaptureHandleI.h"

class YangScreenCapture :public YangThread{
public:
	YangScreenCapture();
	virtual ~YangScreenCapture();

	int32_t m_isStart;

public:
	virtual void setScreenHandle(YangScreenCaptureHandleI *)=0;
	virtual void setInterval(int32_t pinterval)=0;
	virtual int32_t init()=0;
	virtual void setCaptureStart()=0;
	virtual void setCaptureStop()=0;
	virtual void setOutVideoBuffer(YangVideoBuffer *pbuf)=0;

	virtual int32_t getVideoCaptureState()=0;
	void stop();
protected:
    void run();
    virtual void startLoop()=0;
    virtual  void stopLoop()=0;



};

#endif /* INCLUDE_YANGCAPTURE_YANGSCREENCAPTURE_H_ */
