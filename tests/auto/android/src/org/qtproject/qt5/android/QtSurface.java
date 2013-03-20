begin_unit
begin_comment
comment|/*     Copyright (c) 2012, BogDan Vatra<bogdan@kde.org>     Contact: http://www.qt-project.org/legal      Redistribution and use in source and binary forms, with or without     modification, are permitted provided that the following conditions     are met:      1. Redistributions of source code must retain the above copyright     notice, this list of conditions and the following disclaimer.     2. Redistributions in binary form must reproduce the above copyright     notice, this list of conditions and the following disclaimer in the     documentation and/or other materials provided with the distribution.      THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES     OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.     IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,     INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT     NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY     THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF     THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
end_comment
begin_package
DECL|package|org.qtproject.qt5.android
package|package
name|org
operator|.
name|qtproject
operator|.
name|qt5
operator|.
name|android
package|;
end_package
begin_import
import|import
name|android
operator|.
name|app
operator|.
name|Activity
import|;
end_import
begin_import
import|import
name|android
operator|.
name|content
operator|.
name|Context
import|;
end_import
begin_import
import|import
name|android
operator|.
name|graphics
operator|.
name|Bitmap
import|;
end_import
begin_import
import|import
name|android
operator|.
name|graphics
operator|.
name|Canvas
import|;
end_import
begin_import
import|import
name|android
operator|.
name|graphics
operator|.
name|PixelFormat
import|;
end_import
begin_import
import|import
name|android
operator|.
name|graphics
operator|.
name|Rect
import|;
end_import
begin_import
import|import
name|android
operator|.
name|util
operator|.
name|DisplayMetrics
import|;
end_import
begin_import
import|import
name|android
operator|.
name|util
operator|.
name|Log
import|;
end_import
begin_import
import|import
name|android
operator|.
name|view
operator|.
name|MotionEvent
import|;
end_import
begin_import
import|import
name|android
operator|.
name|view
operator|.
name|SurfaceHolder
import|;
end_import
begin_import
import|import
name|android
operator|.
name|view
operator|.
name|SurfaceView
import|;
end_import
begin_class
DECL|class|QtSurface
specifier|public
class|class
name|QtSurface
extends|extends
name|SurfaceView
implements|implements
name|SurfaceHolder
operator|.
name|Callback
block|{
DECL|field|m_bitmap
specifier|private
name|Bitmap
name|m_bitmap
init|=
literal|null
decl_stmt|;
DECL|field|m_started
specifier|private
name|boolean
name|m_started
init|=
literal|false
decl_stmt|;
DECL|field|m_usesGL
specifier|private
name|boolean
name|m_usesGL
init|=
literal|false
decl_stmt|;
DECL|method|QtSurface
specifier|public
name|QtSurface
parameter_list|(
name|Context
name|context
parameter_list|,
name|int
name|id
parameter_list|)
block|{
name|super
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|setFocusable
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|getHolder
argument_list|()
operator|.
name|addCallback
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|getHolder
argument_list|()
operator|.
name|setType
argument_list|(
name|SurfaceHolder
operator|.
name|SURFACE_TYPE_GPU
argument_list|)
expr_stmt|;
name|setId
argument_list|(
name|id
argument_list|)
expr_stmt|;
block|}
DECL|method|applicationStarted
specifier|public
name|void
name|applicationStarted
parameter_list|(
name|boolean
name|usesGL
parameter_list|)
block|{
name|m_started
operator|=
literal|true
expr_stmt|;
name|m_usesGL
operator|=
name|usesGL
expr_stmt|;
if|if
condition|(
name|getWidth
argument_list|()
operator|<
literal|1
operator|||
name|getHeight
argument_list|()
operator|<
literal|1
condition|)
return|return;
if|if
condition|(
name|m_usesGL
condition|)
block|{
name|QtNative
operator|.
name|setSurface
argument_list|(
name|getHolder
argument_list|()
operator|.
name|getSurface
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QtNative
operator|.
name|lockSurface
argument_list|()
expr_stmt|;
name|QtNative
operator|.
name|setSurface
argument_list|(
literal|null
argument_list|)
expr_stmt|;
name|m_bitmap
operator|=
name|Bitmap
operator|.
name|createBitmap
argument_list|(
name|getWidth
argument_list|()
argument_list|,
name|getHeight
argument_list|()
argument_list|,
name|Bitmap
operator|.
name|Config
operator|.
name|RGB_565
argument_list|)
expr_stmt|;
name|QtNative
operator|.
name|setSurface
argument_list|(
name|m_bitmap
argument_list|)
expr_stmt|;
name|QtNative
operator|.
name|unlockSurface
argument_list|()
expr_stmt|;
block|}
block|}
annotation|@
name|Override
DECL|method|surfaceCreated
specifier|public
name|void
name|surfaceCreated
parameter_list|(
name|SurfaceHolder
name|holder
parameter_list|)
block|{
name|DisplayMetrics
name|metrics
init|=
operator|new
name|DisplayMetrics
argument_list|()
decl_stmt|;
operator|(
operator|(
name|Activity
operator|)
name|getContext
argument_list|()
operator|)
operator|.
name|getWindowManager
argument_list|()
operator|.
name|getDefaultDisplay
argument_list|()
operator|.
name|getMetrics
argument_list|(
name|metrics
argument_list|)
expr_stmt|;
name|QtNative
operator|.
name|setApplicationDisplayMetrics
argument_list|(
name|metrics
operator|.
name|widthPixels
argument_list|,
name|metrics
operator|.
name|heightPixels
argument_list|,
name|getWidth
argument_list|()
argument_list|,
name|getHeight
argument_list|()
argument_list|,
name|metrics
operator|.
name|xdpi
argument_list|,
name|metrics
operator|.
name|ydpi
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_usesGL
condition|)
name|holder
operator|.
name|setFormat
argument_list|(
name|PixelFormat
operator|.
name|RGBA_8888
argument_list|)
expr_stmt|;
else|else
name|holder
operator|.
name|setFormat
argument_list|(
name|PixelFormat
operator|.
name|RGB_565
argument_list|)
expr_stmt|;
block|}
annotation|@
name|Override
DECL|method|surfaceChanged
specifier|public
name|void
name|surfaceChanged
parameter_list|(
name|SurfaceHolder
name|holder
parameter_list|,
name|int
name|format
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|Log
operator|.
name|i
argument_list|(
name|QtNative
operator|.
name|QtTAG
argument_list|,
literal|"surfaceChanged: "
operator|+
name|width
operator|+
literal|","
operator|+
name|height
argument_list|)
expr_stmt|;
if|if
condition|(
name|width
operator|<
literal|1
operator|||
name|height
operator|<
literal|1
condition|)
return|return;
name|DisplayMetrics
name|metrics
init|=
operator|new
name|DisplayMetrics
argument_list|()
decl_stmt|;
operator|(
operator|(
name|Activity
operator|)
name|getContext
argument_list|()
operator|)
operator|.
name|getWindowManager
argument_list|()
operator|.
name|getDefaultDisplay
argument_list|()
operator|.
name|getMetrics
argument_list|(
name|metrics
argument_list|)
expr_stmt|;
name|QtNative
operator|.
name|setApplicationDisplayMetrics
argument_list|(
name|metrics
operator|.
name|widthPixels
argument_list|,
name|metrics
operator|.
name|heightPixels
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|metrics
operator|.
name|xdpi
argument_list|,
name|metrics
operator|.
name|ydpi
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_started
condition|)
return|return;
if|if
condition|(
name|m_usesGL
condition|)
block|{
name|QtNative
operator|.
name|setSurface
argument_list|(
name|holder
operator|.
name|getSurface
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QtNative
operator|.
name|lockSurface
argument_list|()
expr_stmt|;
name|QtNative
operator|.
name|setSurface
argument_list|(
literal|null
argument_list|)
expr_stmt|;
name|m_bitmap
operator|=
name|Bitmap
operator|.
name|createBitmap
argument_list|(
name|width
argument_list|,
name|height
argument_list|,
name|Bitmap
operator|.
name|Config
operator|.
name|RGB_565
argument_list|)
expr_stmt|;
name|QtNative
operator|.
name|setSurface
argument_list|(
name|m_bitmap
argument_list|)
expr_stmt|;
name|QtNative
operator|.
name|unlockSurface
argument_list|()
expr_stmt|;
name|QtNative
operator|.
name|updateWindow
argument_list|()
expr_stmt|;
block|}
block|}
annotation|@
name|Override
DECL|method|surfaceDestroyed
specifier|public
name|void
name|surfaceDestroyed
parameter_list|(
name|SurfaceHolder
name|holder
parameter_list|)
block|{
name|Log
operator|.
name|i
argument_list|(
name|QtNative
operator|.
name|QtTAG
argument_list|,
literal|"surfaceDestroyed "
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_usesGL
condition|)
block|{
name|QtNative
operator|.
name|destroySurface
argument_list|()
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|m_started
condition|)
return|return;
name|QtNative
operator|.
name|lockSurface
argument_list|()
expr_stmt|;
name|QtNative
operator|.
name|setSurface
argument_list|(
literal|null
argument_list|)
expr_stmt|;
name|QtNative
operator|.
name|unlockSurface
argument_list|()
expr_stmt|;
block|}
block|}
DECL|method|drawBitmap
specifier|public
name|void
name|drawBitmap
parameter_list|(
name|Rect
name|rect
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_started
condition|)
return|return;
name|QtNative
operator|.
name|lockSurface
argument_list|()
expr_stmt|;
if|if
condition|(
literal|null
operator|!=
name|m_bitmap
condition|)
block|{
try|try
block|{
name|Canvas
name|cv
init|=
name|getHolder
argument_list|()
operator|.
name|lockCanvas
argument_list|(
name|rect
argument_list|)
decl_stmt|;
name|cv
operator|.
name|drawBitmap
argument_list|(
name|m_bitmap
argument_list|,
name|rect
argument_list|,
name|rect
argument_list|,
literal|null
argument_list|)
expr_stmt|;
name|getHolder
argument_list|()
operator|.
name|unlockCanvasAndPost
argument_list|(
name|cv
argument_list|)
expr_stmt|;
block|}
catch|catch
parameter_list|(
name|Exception
name|e
parameter_list|)
block|{
name|Log
operator|.
name|e
argument_list|(
name|QtNative
operator|.
name|QtTAG
argument_list|,
literal|"Can't create main activity"
argument_list|,
name|e
argument_list|)
expr_stmt|;
block|}
block|}
name|QtNative
operator|.
name|unlockSurface
argument_list|()
expr_stmt|;
block|}
annotation|@
name|Override
DECL|method|onTouchEvent
specifier|public
name|boolean
name|onTouchEvent
parameter_list|(
name|MotionEvent
name|event
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_started
condition|)
return|return
literal|false
return|;
name|QtNative
operator|.
name|sendTouchEvent
argument_list|(
name|event
argument_list|,
name|getId
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
annotation|@
name|Override
DECL|method|onTrackballEvent
specifier|public
name|boolean
name|onTrackballEvent
parameter_list|(
name|MotionEvent
name|event
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_started
condition|)
return|return
literal|false
return|;
name|QtNative
operator|.
name|sendTrackballEvent
argument_list|(
name|event
argument_list|,
name|getId
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
block|}
end_class
end_unit
