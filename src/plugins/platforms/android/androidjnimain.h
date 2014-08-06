begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 BogDan Vatra<bogdan@kde.org> ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ANDROID_APP_H
end_ifndef
begin_define
DECL|macro|ANDROID_APP_H
define|#
directive|define
name|ANDROID_APP_H
end_define
begin_include
include|#
directive|include
file|<android/log.h>
end_include
begin_include
include|#
directive|include
file|<jni.h>
end_include
begin_include
include|#
directive|include
file|<android/asset_manager.h>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QRect
name|class
name|QRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPoint
name|class
name|QPoint
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QThread
name|class
name|QThread
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAndroidPlatformIntegration
name|class
name|QAndroidPlatformIntegration
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWidget
name|class
name|QWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QString
name|class
name|QString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|AndroidSurfaceClient
name|class
name|AndroidSurfaceClient
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|namespace
name|QtAndroid
block|{
name|QAndroidPlatformIntegration
modifier|*
name|androidPlatformIntegration
parameter_list|()
function_decl|;
name|void
name|setAndroidPlatformIntegration
parameter_list|(
name|QAndroidPlatformIntegration
modifier|*
name|androidPlatformIntegration
parameter_list|)
function_decl|;
name|void
name|setQtThread
parameter_list|(
name|QThread
modifier|*
name|thread
parameter_list|)
function_decl|;
name|int
name|createSurface
parameter_list|(
name|AndroidSurfaceClient
modifier|*
name|client
parameter_list|,
specifier|const
name|QRect
modifier|&
name|geometry
parameter_list|,
name|bool
name|onTop
parameter_list|,
name|int
name|imageDepth
parameter_list|)
function_decl|;
name|int
name|insertNativeView
parameter_list|(
name|jobject
name|view
parameter_list|,
specifier|const
name|QRect
modifier|&
name|geometry
parameter_list|)
function_decl|;
name|void
name|setSurfaceGeometry
parameter_list|(
name|int
name|surfaceId
parameter_list|,
specifier|const
name|QRect
modifier|&
name|geometry
parameter_list|)
function_decl|;
name|void
name|destroySurface
parameter_list|(
name|int
name|surfaceId
parameter_list|)
function_decl|;
name|QWindow
modifier|*
name|topLevelWindowAt
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|globalPos
parameter_list|)
function_decl|;
name|int
name|desktopWidthPixels
parameter_list|()
function_decl|;
name|int
name|desktopHeightPixels
parameter_list|()
function_decl|;
name|double
name|scaledDensity
parameter_list|()
function_decl|;
name|JavaVM
modifier|*
name|javaVM
parameter_list|()
function_decl|;
name|AAssetManager
modifier|*
name|assetManager
parameter_list|()
function_decl|;
name|jclass
name|applicationClass
parameter_list|()
function_decl|;
name|jobject
name|activity
parameter_list|()
function_decl|;
name|void
name|setApplicationActive
parameter_list|()
function_decl|;
name|void
name|showStatusBar
parameter_list|()
function_decl|;
name|void
name|hideStatusBar
parameter_list|()
function_decl|;
name|jobject
name|createBitmap
parameter_list|(
name|QImage
name|img
parameter_list|,
name|JNIEnv
modifier|*
name|env
init|=
literal|0
parameter_list|)
function_decl|;
name|jobject
name|createBitmap
argument_list|(
name|int
name|width
argument_list|,
name|int
name|height
argument_list|,
name|QImage
operator|::
name|Format
name|format
argument_list|,
name|JNIEnv
operator|*
name|env
argument_list|)
decl_stmt|;
name|jobject
name|createBitmapDrawable
parameter_list|(
name|jobject
name|bitmap
parameter_list|,
name|JNIEnv
modifier|*
name|env
init|=
literal|0
parameter_list|)
function_decl|;
struct|struct
name|AttachedJNIEnv
block|{
name|AttachedJNIEnv
argument_list|()
block|{
name|attached
operator|=
name|false
expr_stmt|;
if|if
condition|(
name|QtAndroid
operator|::
name|javaVM
argument_list|()
operator|->
name|GetEnv
argument_list|(
operator|(
name|void
operator|*
operator|*
operator|)
operator|&
name|jniEnv
argument_list|,
name|JNI_VERSION_1_6
argument_list|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|QtAndroid
operator|::
name|javaVM
argument_list|()
operator|->
name|AttachCurrentThread
argument_list|(
operator|&
name|jniEnv
argument_list|,
name|NULL
argument_list|)
operator|<
literal|0
condition|)
block|{
name|__android_log_print
argument_list|(
name|ANDROID_LOG_ERROR
argument_list|,
literal|"Qt"
argument_list|,
literal|"AttachCurrentThread failed"
argument_list|)
expr_stmt|;
name|jniEnv
operator|=
name|Q_NULLPTR
expr_stmt|;
return|return;
block|}
name|attached
operator|=
name|true
expr_stmt|;
block|}
block|}
operator|~
name|AttachedJNIEnv
argument_list|()
block|{
if|if
condition|(
name|attached
condition|)
name|QtAndroid
operator|::
name|javaVM
argument_list|()
operator|->
name|DetachCurrentThread
argument_list|()
expr_stmt|;
block|}
name|bool
name|attached
decl_stmt|;
name|JNIEnv
modifier|*
name|jniEnv
decl_stmt|;
block|}
struct|;
specifier|const
name|char
modifier|*
name|classErrorMsgFmt
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|methodErrorMsgFmt
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|qtTagText
parameter_list|()
function_decl|;
name|QString
name|deviceName
parameter_list|()
function_decl|;
name|bool
name|blockEventLoopsWhenSuspended
parameter_list|()
function_decl|;
block|}
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ANDROID_APP_H
end_comment
end_unit
