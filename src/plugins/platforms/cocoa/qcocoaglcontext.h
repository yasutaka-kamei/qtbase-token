begin_unit
begin_ifndef
ifndef|#
directive|ifndef
name|QCOCOAGLCONTEXT_H
end_ifndef
begin_define
DECL|macro|QCOCOAGLCONTEXT_H
define|#
directive|define
name|QCOCOAGLCONTEXT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/QWeakPointer>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<Cocoa/Cocoa.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QCocoaGLContext
range|:
name|public
name|QPlatformGLContext
block|{
name|public
operator|:
name|QCocoaGLContext
argument_list|(
specifier|const
name|QSurfaceFormat
operator|&
name|format
argument_list|,
name|QPlatformGLContext
operator|*
name|share
argument_list|)
block|;
name|QSurfaceFormat
name|format
argument_list|()
specifier|const
block|;
name|void
name|swapBuffers
argument_list|(
name|QPlatformSurface
operator|*
name|surface
argument_list|)
block|;
name|bool
name|makeCurrent
argument_list|(
name|QPlatformSurface
operator|*
name|surface
argument_list|)
block|;
name|void
name|doneCurrent
argument_list|()
block|;
name|void
argument_list|(
operator|*
name|getProcAddress
argument_list|(
specifier|const
name|QByteArray
operator|&
name|procName
argument_list|)
argument_list|)
argument_list|()
block|;
name|void
name|update
argument_list|()
block|;
specifier|static
name|NSOpenGLPixelFormat
operator|*
name|createNSOpenGLPixelFormat
argument_list|()
block|;
name|NSOpenGLContext
operator|*
name|nsOpenGLContext
argument_list|()
specifier|const
block|;
name|private
operator|:
name|void
name|setActiveWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|NSOpenGLContext
operator|*
name|m_context
block|;
name|QSurfaceFormat
name|m_format
block|;
name|QWeakPointer
operator|<
name|QWindow
operator|>
name|m_currentWindow
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOCOAGLCONTEXT_H
end_comment
end_unit
