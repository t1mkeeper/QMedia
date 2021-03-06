/*
 * Copyright (C) 2015 Zhang Rui <bbcallen@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * https://github.com/Bilibili/jni4android
 * This file is automatically generated by jni4android, do not modify.
 */

#ifndef J4A__com_qmedia_qmediasdk_QSource_QMediaSource__H
#define J4A__com_qmedia_qmediasdk_QSource_QMediaSource__H

#include "j4a/j4a_base.h"

void J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__setVideoTarget(JNIEnv *env, jobject thiz, jobject videoTarget);
void J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__setVideoTarget__catchAll(JNIEnv *env, jobject thiz, jobject videoTarget);
void J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__setAudioTarget(JNIEnv *env, jobject thiz, jobject audioTarget);
void J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__setAudioTarget__catchAll(JNIEnv *env, jobject thiz, jobject audioTarget);
jobject J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__getVideoTarget(JNIEnv *env, jobject thiz);
jobject J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__getVideoTarget__catchAll(JNIEnv *env, jobject thiz);
jobject J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__getVideoTarget__asGlobalRef__catchAll(JNIEnv *env, jobject thiz);
jobject J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__getAudioTarget(JNIEnv *env, jobject thiz);
jobject J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__getAudioTarget__catchAll(JNIEnv *env, jobject thiz);
jobject J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__getAudioTarget__asGlobalRef__catchAll(JNIEnv *env, jobject thiz);
jobject J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__getVideoDescribe(JNIEnv *env, jobject thiz);
jobject J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__getVideoDescribe__catchAll(JNIEnv *env, jobject thiz);
jobject J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__getVideoDescribe__asGlobalRef__catchAll(JNIEnv *env, jobject thiz);
jobject J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__getAudioDescribe(JNIEnv *env, jobject thiz);
jobject J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__getAudioDescribe__catchAll(JNIEnv *env, jobject thiz);
jobject J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__getAudioDescribe__asGlobalRef__catchAll(JNIEnv *env, jobject thiz);
jboolean J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__load(JNIEnv *env, jobject thiz);
jboolean J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__load__catchAll(JNIEnv *env, jobject thiz);
jboolean J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__unload(JNIEnv *env, jobject thiz);
jboolean J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__unload__catchAll(JNIEnv *env, jobject thiz);
jboolean J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__isInit(JNIEnv *env, jobject thiz);
jboolean J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__isInit__catchAll(JNIEnv *env, jobject thiz);
jboolean J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__start(JNIEnv *env, jobject thiz, jlong startMSec, jlong endMSec);
jboolean J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__start__catchAll(JNIEnv *env, jobject thiz, jlong startMSec, jlong endMSec);
void J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__stop(JNIEnv *env, jobject thiz);
void J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__stop__catchAll(JNIEnv *env, jobject thiz);
jboolean J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__seekTo(JNIEnv *env, jobject thiz, jlong mSec);
jboolean J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__seekTo__catchAll(JNIEnv *env, jobject thiz, jlong mSec);
jboolean J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__isEOF(JNIEnv *env, jobject thiz);
jboolean J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__isEOF__catchAll(JNIEnv *env, jobject thiz);
jboolean J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__isStarted(JNIEnv *env, jobject thiz);
jboolean J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__isStarted__catchAll(JNIEnv *env, jobject thiz);
jlong J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__getMediaDuration(JNIEnv *env, jobject thiz);
jlong J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__getMediaDuration__catchAll(JNIEnv *env, jobject thiz);
jobject J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__readNextVideoFrame(JNIEnv *env, jobject thiz);
jobject J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__readNextVideoFrame__catchAll(JNIEnv *env, jobject thiz);
jobject J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__readNextVideoFrame__asGlobalRef__catchAll(JNIEnv *env, jobject thiz);
jobject J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__readNextAudioFrame(JNIEnv *env, jobject thiz);
jobject J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__readNextAudioFrame__catchAll(JNIEnv *env, jobject thiz);
jobject J4AC_com_qmedia_qmediasdk_QSource_QMediaSource__readNextAudioFrame__asGlobalRef__catchAll(JNIEnv *env, jobject thiz);
int J4A_loadClass__J4AC_com_qmedia_qmediasdk_QSource_QMediaSource(JNIEnv *env);

#endif//J4A__com_qmedia_qmediasdk_QSource_QMediaSource__H
