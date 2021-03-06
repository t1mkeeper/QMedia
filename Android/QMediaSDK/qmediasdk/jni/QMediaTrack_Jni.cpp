//
// Created by spring on 2020/5/20.
//

#include <EffectEditor/MediaTrackImpl.h>
#include "JniUtils.h"
#include "j4a_generate/j4a_generate.h"
#include "MediaSourceAdapter.h"

#define NATIVE_FUNCTION(retT, name)\
extern "C" JNIEXPORT retT JNICALL Java_com_qmedia_qmediasdk_QTrack_QMediaTrack_##name

NATIVE_FUNCTION(jlong, native_1create)(JNIEnv *env, jobject thiz, jobject jsource)
{
    MediaSourceRef sourceRef = MediaSourceRef(new MediaSourceAdapter(jsource));
    MediaTrackRef* track_ptr = new MediaTrackRef(new MediaTrackImpl(sourceRef));

    return reinterpret_cast<jlong>(track_ptr);

}

NATIVE_FUNCTION(jboolean , native_1prepare)(JNIEnv *env, jobject thiz)
{
    MediaTrackRef * track_ptr = reinterpret_cast<MediaTrackRef *>(JniUtils::getObjectPtr(env, thiz));
    if (track_ptr) {
        return (*track_ptr)->prepare();
    }
    return false;
}

NATIVE_FUNCTION(jboolean , native_1setTimeTo)(JNIEnv *env, jobject thiz, jlong jmSec)
{
    MediaTrackRef * track_ptr = reinterpret_cast<MediaTrackRef *>(JniUtils::getObjectPtr(env, thiz));
    if (track_ptr) {
        return (*track_ptr)->setPositionTo(jmSec);
    }
    return false;
}

NATIVE_FUNCTION(void , native_1stopMedia)(JNIEnv *env, jobject thiz)
{
    MediaTrackRef * track_ptr = reinterpret_cast<MediaTrackRef *>(JniUtils::getObjectPtr(env, thiz));
    if (track_ptr) {
        (*track_ptr)->stopMedia();
    }
}

NATIVE_FUNCTION(jboolean , native_1isPrepare)(JNIEnv *env, jobject thiz)
{
    MediaTrackRef * track_ptr = reinterpret_cast<MediaTrackRef *>(JniUtils::getObjectPtr(env, thiz));
    if (track_ptr) {
        return (*track_ptr)->isPrepare();
    }
    return false;
}

NATIVE_FUNCTION(jfloat , native_1getPlaySpeed)(JNIEnv *env, jobject thiz)
{
    MediaTrackRef * track_ptr = reinterpret_cast<MediaTrackRef *>(JniUtils::getObjectPtr(env, thiz));
    if (track_ptr) {
        return (*track_ptr)->getPlaySpeed();
    }
    return 0.f;
}

NATIVE_FUNCTION(jlong , native_1getSourceDuration)(JNIEnv *env, jobject thiz)
{
    MediaTrackRef * track_ptr = reinterpret_cast<MediaTrackRef *>(JniUtils::getObjectPtr(env, thiz));
    if (track_ptr) {
        return (*track_ptr)->getMediaDuration();
    }
    return 0;
}

NATIVE_FUNCTION(jobject , native_1getDisplayRange)(JNIEnv *env, jobject thiz)
{
    MediaTrackRef * track_ptr = reinterpret_cast<MediaTrackRef *>(JniUtils::getObjectPtr(env, thiz));
    if (track_ptr) {
        Range<int64_t > range = (*track_ptr)->getDisplayTrackRange();
        return J4AC_com_qmedia_qmediasdk_QCommon_QRange__QRange(env, range._start, range._end);
    }
    return nullptr;
}

NATIVE_FUNCTION(void , native_1setDisplayRange)(JNIEnv *env, jobject thiz, jobject jrange)
{
    MediaTrackRef * track_ptr = reinterpret_cast<MediaTrackRef *>(JniUtils::getObjectPtr(env, thiz));
    if (track_ptr) {
        Range<int64_t > range = {J4AC_com_qmedia_qmediasdk_QCommon_QRange__start__get(env, jrange),
                                 J4AC_com_qmedia_qmediasdk_QCommon_QRange__end__get(env, jrange)};
        (*track_ptr)->setDisplayTrackRange(range);
    }
}

NATIVE_FUNCTION(jobject , native_1getSourceRange)(JNIEnv *env, jobject thiz)
{
    MediaTrackRef * track_ptr = reinterpret_cast<MediaTrackRef *>(JniUtils::getObjectPtr(env, thiz));
    if (track_ptr) {
        Range<int64_t > range = (*track_ptr)->getSourceRange();
        return J4AC_com_qmedia_qmediasdk_QCommon_QRange__QRange(env, range._start, range._end);
    }
    return nullptr;
}

NATIVE_FUNCTION(void , native_1setSourceRange)(JNIEnv *env, jobject thiz, jobject jrange)
{
    MediaTrackRef * track_ptr = reinterpret_cast<MediaTrackRef *>(JniUtils::getObjectPtr(env, thiz));
    if (track_ptr) {
        Range<int64_t > range = {J4AC_com_qmedia_qmediasdk_QCommon_QRange__start__get(env, jrange),
                                 J4AC_com_qmedia_qmediasdk_QCommon_QRange__end__get(env, jrange)};
        (*track_ptr)->setSourceRange(range);
    }
}

NATIVE_FUNCTION(jfloat , native_1getTimeScale)(JNIEnv *env, jobject thiz)
{
    MediaTrackRef * track_ptr = reinterpret_cast<MediaTrackRef *>(JniUtils::getObjectPtr(env, thiz));
    if (track_ptr) {
        return (*track_ptr)->getTimeScale();
    }
    return 0.f;
}

NATIVE_FUNCTION(void , native_1setTimeScale)(JNIEnv *env, jobject thiz, jfloat jtimeScale)
{
    MediaTrackRef * track_ptr = reinterpret_cast<MediaTrackRef *>(JniUtils::getObjectPtr(env, thiz));
    if (track_ptr) {
        (*track_ptr)->setTimeScale(jtimeScale);
    }
}

NATIVE_FUNCTION(jint , native_1getRepeatTimes)(JNIEnv *env, jobject thiz)
{
    MediaTrackRef * track_ptr = reinterpret_cast<MediaTrackRef *>(JniUtils::getObjectPtr(env, thiz));
    if (track_ptr) {
        return (*track_ptr)->getRepeatTimes();
    }
    return 0;
}

NATIVE_FUNCTION(void , native_1setRepeatTimes)(JNIEnv *env, jobject thiz, jint jrepeatTimes)
{
    MediaTrackRef * track_ptr = reinterpret_cast<MediaTrackRef *>(JniUtils::getObjectPtr(env, thiz));
    if (track_ptr) {
        (*track_ptr)->setRepeatTimes(jrepeatTimes);
    }
}

NATIVE_FUNCTION(void , native_1release)(JNIEnv *env, jobject thiz)
{
    MediaTrackRef * track_ptr = reinterpret_cast<MediaTrackRef *>(JniUtils::getObjectPtr(env, thiz));
    if (track_ptr) {
        delete track_ptr;
    }
    JniUtils::setObjectPtr(env, thiz, 0);
}




