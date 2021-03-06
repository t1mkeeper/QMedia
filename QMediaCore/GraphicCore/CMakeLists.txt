set(GRAPHIC_CORE_HEADER
        GraphicCore/base/Macros.h
        GraphicCore/base/ColorTypes.h
        GraphicCore/base/Image.h

        GraphicCore/math/Vec2.h
        GraphicCore/math/Vec2.inl
        GraphicCore/math/Vec3.h
        GraphicCore/math/Vec3.inl
        GraphicCore/math/Vec4.h
        GraphicCore/math/Vec4.inl
        GraphicCore/math/CCAffineTransform.h
        GraphicCore/math/CCGeometry.h
        GraphicCore/math/CCMath.h
        GraphicCore/math/CCMathBase.h
        GraphicCore/math/Mat4.h
        GraphicCore/math/Mat4.inl
        GraphicCore/math/MathUtil.h
        GraphicCore/math/MathUtil.inl
        GraphicCore/math/Quaternion.h
        GraphicCore/math/Quaternion.inl

        GraphicCore/opengl/shaders/ccShaders.h
        GraphicCore/opengl/Drawable2D.h
        GraphicCore/opengl/GLMacros.h
        GraphicCore/opengl/GLEngine.h
        GraphicCore/opengl/Texture2D.h
        GraphicCore/opengl/ShaderProgram.h
        GraphicCore/opengl/FrameBuffer.h

        GraphicCore/GcScene.h
        GraphicCore/GcNode.h
        GraphicCore/GcAnimaNode.h
        GraphicCore/GcRenderNode.h
        GraphicCore/GcDuplicateNode.h
        GraphicCore/GcLayer.h
        GraphicCore/GcFilter.h
    )

set(GRAPHIC_CORE_SRC

        GraphicCore/base/ColorTypes.cpp
        GraphicCore/base/Image.cpp

        GraphicCore/math/Vec2.cpp
        GraphicCore/math/Vec3.cpp
        GraphicCore/math/Vec4.cpp
        GraphicCore/math/CCAffineTransform.cpp
        GraphicCore/math/CCGeometry.cpp
        GraphicCore/math/Mat4.cpp
        GraphicCore/math/MathUtil.cpp
        GraphicCore/math/Quaternion.cpp

        GraphicCore/opengl/shaders/ccShaders.cpp
        GraphicCore/opengl/Drawable2D.cpp
        GraphicCore/opengl/GLEngine.cpp
        GraphicCore/opengl/Texture2D.cpp
        GraphicCore/opengl/ShaderProgram.cpp
        GraphicCore/opengl/FrameBuffer.cpp

        GraphicCore/GcScene.cpp
        GraphicCore/GcNode.cpp
        GraphicCore/GcAnimaNode.cpp
        GraphicCore/GcRenderNode.cpp
        GraphicCore/GcDuplicateNode.cpp
        GraphicCore/GcLayer.cpp
        GraphicCore/GcFilter.cpp
    )
