//
//  IOSFastTextureDrawable.m
//  QMediaSDK
//
//  Created by spring on 20/05/2017.
//  Copyright © 2017 QMedia. All rights reserved.
//

#import "IOSFastTextureDrawable.h"
#include "GraphicCore/opengl/Drawable2D.h"
#include "GraphicCore/opengl/ShaderProgram.h"

USING_GRAPHICCORE

#define SHADER_STRING(A)  #A

const std::string kGPUImageVertexShaderString = SHADER_STRING
(
 attribute vec4 position;
 attribute vec4 inputTextureCoordinate;
 
 varying vec2 textureCoordinate;
 
 void main()
 {
     gl_Position = position;
     textureCoordinate = inputTextureCoordinate.xy;
 }
);

const std::string kGPUImagePassthroughFragmentShaderString = SHADER_STRING
(
 varying highp vec2 textureCoordinate;
 
 uniform sampler2D inputImageTexture;
 
 void main()
 {
     gl_FragColor = texture2D(inputImageTexture, textureCoordinate);
 }
);

const std::string kGPUImageColorSwizzlingFragmentShaderString = SHADER_STRING
(
 varying highp vec2 textureCoordinate;
 
 uniform sampler2D inputImageTexture;
 
 void main()
 {
     gl_FragColor = texture2D(inputImageTexture, textureCoordinate).bgra;
 }
);


static GLfloat clearColor[4];
static int prev_view_port[4];
static GLint prev_fbo;

@implementation IOSFastTextureDrawable {
    IOSFastTexture* _iosTexture;
    GLuint _glFbId;
    GraphicCore::ShaderProgram _shaderProgram;
}

- (instancetype)initWithTexture:(IOSFastTexture*)iosTexture
{
    if (self = [super init]) {
        _iosTexture = iosTexture;
        if (!_shaderProgram.createProgram(kGPUImageVertexShaderString.c_str(), kGPUImagePassthroughFragmentShaderString.c_str())) {
            return nil;
        }
        if (_shaderProgram.use()) {
            _shaderProgram.addVertexAttribOption("position", VertexAttrib::VERTEX2);
            _shaderProgram.addVertexAttribOption("inputTextureCoordinate", VertexAttrib::TEXCOORD);
            _shaderProgram.addUniformOption("inputImageTexture", Uniform::TEXTURE);
        }
        
        glGenFramebuffers(1, &_glFbId);
        glBindFramebuffer(GL_FRAMEBUFFER, _glFbId);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(_iosTexture.glTexTarget, _iosTexture.glTexid);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _iosTexture.glTexid, 0);
        const int status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
        if (status != GL_FRAMEBUFFER_COMPLETE)
        {
            NSAssert(NO,@"glCheckFramebufferStatus: %d", status);
        }
        
    }
    return self;
}
- (void)dealloc
{
    
}

- (bool)useAsFrameBuffer
{
    bool bRet = true;
    if (_glFbId) {
        glBindFramebuffer(GL_FRAMEBUFFER, _glFbId);
//        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _iosTexture.glTexid, 0);
        const int status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
        if (status != GL_FRAMEBUFFER_COMPLETE)
        {
            NSAssert(NO,@"glCheckFramebufferStatus: %d", status);
            bRet = false;
        }
        glViewport(0, 0, _iosTexture.width, _iosTexture.height);
    }
    return bRet;
}

- (void)releaseFb
{
    if (_glFbId) {
        glDeleteFramebuffers(1, &_glFbId);
        _glFbId = 0;
    }
    _shaderProgram.releaseProgram();
}

- (IOSFastTexture*)texture{
    return _iosTexture;
}
- (GLuint)glFbId{
    return _glFbId;
}

- (bool)draw:(QFilpMode)filpMode{
    _shaderProgram.setUniformValue("inputImageTexture", (int)_iosTexture.glTexid);
    _shaderProgram.setVertexAttribValue("position", 8, Drawable2D::RECTANGLE_COORDS);
    if (filpMode == QFilpModeH) {
        _shaderProgram.setVertexAttribValue("inputTextureCoordinate", 8, Drawable2D::RECTANGLE_TEX_COORDS_FLIPH);
    }else if (filpMode == QFilpModeV)
        _shaderProgram.setVertexAttribValue("inputTextureCoordinate", 8, Drawable2D::RECTANGLE_TEX_COORDS_FLIPV);
    else
        _shaderProgram.setVertexAttribValue("inputTextureCoordinate", 8, Drawable2D::RECTANGLE_TEX_COORDS);
    
    return _shaderProgram.drawRect() == 0;
}

+ (void)savePrevStatus
{
    glGetFloatv(GL_COLOR_CLEAR_VALUE, clearColor);
    glGetIntegerv(GL_VIEWPORT,prev_view_port);
    glGetIntegerv(GL_FRAMEBUFFER_BINDING, &prev_fbo);
}
+ (void)loadPrevStatus
{
    glBindFramebuffer(GL_FRAMEBUFFER, prev_fbo);
    glViewport(prev_view_port[0], prev_view_port[1], prev_view_port[2], prev_view_port[3]);
    glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
}

@end
