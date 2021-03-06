begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB) ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopenglfunctions_es2.h"
end_include
begin_include
include|#
directive|include
file|"qopenglcontext.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QOpenGLFunctions_ES2     \inmodule QtGui     \since 5.1     \wrapper     \brief The QOpenGLFunctions_ES2 class provides all functions for OpenGL ES 2      This class is a wrapper for OpenGL ES 2 functions. See reference pages on     \l {http://www.khronos.org/opengles/sdk/docs/man/}{khronos.org} for     function documentation.      \sa QAbstractOpenGLFunctions */
end_comment
begin_constructor
DECL|function|QOpenGLFunctions_ES2
name|QOpenGLFunctions_ES2
operator|::
name|QOpenGLFunctions_ES2
parameter_list|()
member_init_list|:
name|QAbstractOpenGLFunctions
argument_list|()
member_init_list|,
name|d_es2
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QOpenGLFunctions_ES2
name|QOpenGLFunctions_ES2
operator|::
name|~
name|QOpenGLFunctions_ES2
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|initializeOpenGLFunctions
name|bool
name|QOpenGLFunctions_ES2
operator|::
name|initializeOpenGLFunctions
parameter_list|()
block|{
if|if
condition|(
name|isInitialized
argument_list|()
condition|)
return|return
literal|true
return|;
name|QOpenGLContext
modifier|*
name|context
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
decl_stmt|;
comment|// If owned by a context object make sure it is current.
comment|// Also check that current context is compatible
if|if
condition|(
operator|(
operator|(
name|owningContext
argument_list|()
operator|&&
name|owningContext
argument_list|()
operator|==
name|context
operator|)
operator|||
operator|!
name|owningContext
argument_list|()
operator|)
operator|&&
name|QOpenGLFunctions_ES2
operator|::
name|isContextCompatible
argument_list|(
name|context
argument_list|)
condition|)
block|{
comment|// Nothing to do, just flag that we are initialized
name|QAbstractOpenGLFunctions
operator|::
name|initializeOpenGLFunctions
argument_list|()
expr_stmt|;
block|}
return|return
name|isInitialized
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|isContextCompatible
name|bool
name|QOpenGLFunctions_ES2
operator|::
name|isContextCompatible
parameter_list|(
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|QSurfaceFormat
name|f
init|=
name|context
operator|->
name|format
argument_list|()
decl_stmt|;
specifier|const
name|QPair
argument_list|<
name|int
argument_list|,
name|int
argument_list|>
name|v
init|=
name|qMakePair
argument_list|(
name|f
operator|.
name|majorVersion
argument_list|()
argument_list|,
name|f
operator|.
name|minorVersion
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|v
operator|<
name|qMakePair
argument_list|(
literal|2
argument_list|,
literal|0
argument_list|)
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|f
operator|.
name|renderableType
argument_list|()
operator|!=
name|QSurfaceFormat
operator|::
name|OpenGLES
condition|)
return|return
literal|false
return|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|versionProfile
name|QOpenGLVersionProfile
name|QOpenGLFunctions_ES2
operator|::
name|versionProfile
parameter_list|()
block|{
name|QOpenGLVersionProfile
name|v
decl_stmt|;
return|return
name|v
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
