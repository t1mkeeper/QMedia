//
// Created by spring on 2020/5/19.
//

#ifndef QMEDIASDK_MEDIADESCRIBE_JNI_H
#define QMEDIASDK_MEDIADESCRIBE_JNI_H

#include "JniUtils.h"
#include "MediaCore/mediadef/MediaComm.h"

#define QAUDIODESCRIBE_CLASSPATH "com/qmedia/qmediasdk/QSource/QAudioDescribe"
#define QVIDEODESCRIBE_CLASSPATH "com/qmedia/qmediasdk/QSource/QVideoDescribe"

class MediaDescribe_jni {
public:
    static jobject VideoDescribeToJava(JNIEnv* env, VideoDescribe videoDescribe);
    static jobject AudioDescribeToJava(JNIEnv* env, AudioDescribe audioDescribe);

    static VideoDescribe JavaToVideoDescribe(JNIEnv* env, jobject jvideoDescribe);
    static AudioDescribe JavaToAudioDescribe(JNIEnv* env, jobject jaudioDescribe);
};


#endif //QMEDIASDK_MEDIADESCRIBE_JNI_H
