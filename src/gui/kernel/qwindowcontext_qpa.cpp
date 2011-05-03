begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformglcontext_qpa.h"
end_include
begin_include
include|#
directive|include
file|"qwindowcontext_qpa.h"
end_include
begin_include
include|#
directive|include
file|"qwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QThreadStorage>
end_include
begin_include
include|#
directive|include
file|<QtCore/QThread>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_class
DECL|class|QWindowThreadContext
class|class
name|QWindowThreadContext
block|{
public|public:
DECL|function|~QWindowThreadContext
name|~
name|QWindowThreadContext
parameter_list|()
block|{
if|if
condition|(
name|context
condition|)
name|context
operator|->
name|doneCurrent
argument_list|()
expr_stmt|;
block|}
DECL|member|context
name|QWindowContext
modifier|*
name|context
decl_stmt|;
block|}
class|;
end_class
begin_decl_stmt
DECL|variable|qwindow_context_storage
specifier|static
name|QThreadStorage
argument_list|<
name|QWindowThreadContext
modifier|*
argument_list|>
name|qwindow_context_storage
decl_stmt|;
end_decl_stmt
begin_class
DECL|class|QWindowContextPrivate
class|class
name|QWindowContextPrivate
block|{
public|public:
DECL|function|QWindowContextPrivate
name|QWindowContextPrivate
parameter_list|()
member_init_list|:
name|qGLContextHandle
argument_list|(
literal|0
argument_list|)
block|{     }
DECL|function|~QWindowContextPrivate
specifier|virtual
name|~
name|QWindowContextPrivate
parameter_list|()
block|{
comment|//do not delete the QGLContext handle here as it is deleted in
comment|//QWidgetPrivate::deleteTLSysExtra()
block|}
DECL|member|qGLContextHandle
name|void
modifier|*
name|qGLContextHandle
decl_stmt|;
DECL|member|qGLContextDeleteFunction
name|void
function_decl|(
modifier|*
name|qGLContextDeleteFunction
function_decl|)
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
DECL|member|platformGLContext
name|QPlatformGLContext
modifier|*
name|platformGLContext
decl_stmt|;
DECL|member|staticSharedContext
specifier|static
name|QWindowContext
modifier|*
name|staticSharedContext
decl_stmt|;
specifier|static
name|void
name|setCurrentContext
parameter_list|(
name|QWindowContext
modifier|*
name|context
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_decl_stmt
DECL|member|staticSharedContext
name|QWindowContext
modifier|*
name|QWindowContextPrivate
operator|::
name|staticSharedContext
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|setCurrentContext
name|void
name|QWindowContextPrivate
operator|::
name|setCurrentContext
parameter_list|(
name|QWindowContext
modifier|*
name|context
parameter_list|)
block|{
name|QWindowThreadContext
modifier|*
name|threadContext
init|=
name|qwindow_context_storage
operator|.
name|localData
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|threadContext
condition|)
block|{
if|if
condition|(
operator|!
name|QThread
operator|::
name|currentThread
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"No QTLS available. currentContext wont work"
argument_list|)
expr_stmt|;
return|return;
block|}
name|threadContext
operator|=
operator|new
name|QWindowThreadContext
expr_stmt|;
name|qwindow_context_storage
operator|.
name|setLocalData
argument_list|(
name|threadContext
argument_list|)
expr_stmt|;
block|}
name|threadContext
operator|->
name|context
operator|=
name|context
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the last context which called makeCurrent. This function is thread aware. */
end_comment
begin_function
DECL|function|currentContext
name|QWindowContext
modifier|*
name|QWindowContext
operator|::
name|currentContext
parameter_list|()
block|{
name|QWindowThreadContext
modifier|*
name|threadContext
init|=
name|qwindow_context_storage
operator|.
name|localData
argument_list|()
decl_stmt|;
if|if
condition|(
name|threadContext
condition|)
block|{
return|return
name|threadContext
operator|->
name|context
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|handle
name|QPlatformGLContext
modifier|*
name|QWindowContext
operator|::
name|handle
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindowContext
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|platformGLContext
return|;
block|}
end_function
begin_comment
comment|/*!     All subclasses needs to specify the platformWindow. It can be a null window. */
end_comment
begin_constructor
DECL|function|QWindowContext
name|QWindowContext
operator|::
name|QWindowContext
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QWindowContextPrivate
argument_list|()
argument_list|)
block|{
name|Q_D
argument_list|(
name|QWindowContext
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|window
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|window
operator|->
name|handle
argument_list|()
condition|)
name|window
operator|->
name|create
argument_list|()
expr_stmt|;
name|d
operator|->
name|platformGLContext
operator|=
name|window
operator|->
name|handle
argument_list|()
operator|->
name|glContext
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!   If this is the current context for the thread, doneCurrent is called */
end_comment
begin_destructor
DECL|function|~QWindowContext
name|QWindowContext
operator|::
name|~
name|QWindowContext
parameter_list|()
block|{
if|if
condition|(
name|QWindowContext
operator|::
name|currentContext
argument_list|()
operator|==
name|this
condition|)
block|{
name|doneCurrent
argument_list|()
expr_stmt|;
block|}
block|}
end_destructor
begin_comment
comment|/*!     Reimplement in subclass to do makeCurrent on native GL context */
end_comment
begin_function
DECL|function|makeCurrent
name|void
name|QWindowContext
operator|::
name|makeCurrent
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWindowContext
argument_list|)
expr_stmt|;
name|QWindowContextPrivate
operator|::
name|setCurrentContext
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|d
operator|->
name|platformGLContext
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Reimplement in subclass to release current context.     Typically this is calling makeCurrent with 0 "surface" */
end_comment
begin_function
DECL|function|doneCurrent
name|void
name|QWindowContext
operator|::
name|doneCurrent
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWindowContext
argument_list|)
expr_stmt|;
name|d
operator|->
name|platformGLContext
operator|->
name|doneCurrent
argument_list|()
expr_stmt|;
name|QWindowContextPrivate
operator|::
name|setCurrentContext
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|swapBuffers
name|void
name|QWindowContext
operator|::
name|swapBuffers
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWindowContext
argument_list|)
expr_stmt|;
name|d
operator|->
name|platformGLContext
operator|->
name|swapBuffers
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
DECL|function|getProcAddress
name|void
argument_list|(
argument|*QWindowContext::getProcAddress(const QByteArray&procName)
argument_list|)
end_macro
begin_expr_stmt
DECL|function|getProcAddress
operator|(
operator|)
block|{
name|Q_D
argument_list|(
name|QWindowContext
argument_list|)
block|;
name|void
operator|*
name|result
operator|=
name|d
operator|->
name|platformGLContext
operator|->
name|getProcAddress
argument_list|(
name|QString
operator|::
name|fromAscii
argument_list|(
name|procName
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|)
block|;
return|return
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
name|result
return|;
block|}
end_expr_stmt
begin_comment
comment|/*   internal: Needs to have a pointer to qGLContext. But since this is in QtGui we cant   have any type information. */
end_comment
begin_function
DECL|function|qGLContextHandle
name|void
modifier|*
name|QWindowContext
operator|::
name|qGLContextHandle
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindowContext
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|qGLContextHandle
return|;
block|}
end_function
begin_function
DECL|function|setQGLContextHandle
name|void
name|QWindowContext
operator|::
name|setQGLContextHandle
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
name|void
function_decl|(
modifier|*
name|qGLContextDeleteFunction
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWindowContext
argument_list|)
expr_stmt|;
name|d
operator|->
name|qGLContextHandle
operator|=
name|handle
expr_stmt|;
name|d
operator|->
name|qGLContextDeleteFunction
operator|=
name|qGLContextDeleteFunction
expr_stmt|;
block|}
end_function
begin_function
DECL|function|deleteQGLContext
name|void
name|QWindowContext
operator|::
name|deleteQGLContext
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWindowContext
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|qGLContextDeleteFunction
operator|&&
name|d
operator|->
name|qGLContextHandle
condition|)
block|{
name|d
operator|->
name|qGLContextDeleteFunction
argument_list|(
name|d
operator|->
name|qGLContextHandle
argument_list|)
expr_stmt|;
name|d
operator|->
name|qGLContextDeleteFunction
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|qGLContextHandle
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
end_unit
