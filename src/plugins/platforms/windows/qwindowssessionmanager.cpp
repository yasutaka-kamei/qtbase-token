begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Samuel Gaist<samuel.gaist@edeltech.ch> ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowssessionmanager.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QWindowsSessionManager
name|QWindowsSessionManager
operator|::
name|QWindowsSessionManager
parameter_list|(
specifier|const
name|QString
modifier|&
name|id
parameter_list|,
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
member_init_list|:
name|QPlatformSessionManager
argument_list|(
name|id
argument_list|,
name|key
argument_list|)
member_init_list|,
name|m_isActive
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_blockUserInput
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_canceled
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QWindowsSessionManager
name|QWindowsSessionManager
operator|::
name|~
name|QWindowsSessionManager
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|allowsInteraction
name|bool
name|QWindowsSessionManager
operator|::
name|allowsInteraction
parameter_list|()
block|{
name|m_blockUserInput
operator|=
literal|false
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|allowsErrorInteraction
name|bool
name|QWindowsSessionManager
operator|::
name|allowsErrorInteraction
parameter_list|()
block|{
name|m_blockUserInput
operator|=
literal|false
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|blocksInteraction
name|void
name|QWindowsSessionManager
operator|::
name|blocksInteraction
parameter_list|()
block|{
name|m_blockUserInput
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isInterractionBlocked
name|bool
name|QWindowsSessionManager
operator|::
name|isInterractionBlocked
parameter_list|()
specifier|const
block|{
return|return
name|m_blockUserInput
return|;
block|}
end_function
begin_function
DECL|function|release
name|void
name|QWindowsSessionManager
operator|::
name|release
parameter_list|()
block|{
if|if
condition|(
name|m_isActive
condition|)
name|m_blockUserInput
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cancel
name|void
name|QWindowsSessionManager
operator|::
name|cancel
parameter_list|()
block|{
name|m_canceled
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clearCancellation
name|void
name|QWindowsSessionManager
operator|::
name|clearCancellation
parameter_list|()
block|{
name|m_canceled
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_function
DECL|function|wasCanceled
name|bool
name|QWindowsSessionManager
operator|::
name|wasCanceled
parameter_list|()
specifier|const
block|{
return|return
name|m_canceled
return|;
block|}
end_function
begin_function
DECL|function|setActive
name|void
name|QWindowsSessionManager
operator|::
name|setActive
parameter_list|(
name|bool
name|active
parameter_list|)
block|{
name|m_isActive
operator|=
name|active
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isActive
name|bool
name|QWindowsSessionManager
operator|::
name|isActive
parameter_list|()
specifier|const
block|{
return|return
name|m_isActive
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
