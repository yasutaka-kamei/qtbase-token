begin_unit
begin_include
include|#
directive|include
file|<QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QRect>
end_include
begin_include
include|#
directive|include
file|<QScreen>
end_include
begin_include
include|#
directive|include
file|"paintedwindow.h"
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|QGuiApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QScreen
modifier|*
name|screen
init|=
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
decl_stmt|;
name|QRect
name|screenGeometry
init|=
name|screen
operator|->
name|availableGeometry
argument_list|()
decl_stmt|;
name|QSurfaceFormat
name|format
decl_stmt|;
name|format
operator|.
name|setDepthBufferSize
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|format
operator|.
name|setSamples
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|QPoint
name|center
init|=
name|screenGeometry
operator|.
name|center
argument_list|()
decl_stmt|;
name|QRect
name|windowRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|640
argument_list|,
literal|480
argument_list|)
decl_stmt|;
name|PaintedWindow
name|window
decl_stmt|;
name|window
operator|.
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|center
operator|-
name|windowRect
operator|.
name|center
argument_list|()
argument_list|,
name|windowRect
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|window
operator|.
name|show
argument_list|()
expr_stmt|;
name|app
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
end_function
end_unit
