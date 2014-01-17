begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2014 BlackBerry Limited. All rights reserved. ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|"qqnxintegration.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|qScreenCheckError
name|void
name|qScreenCheckError
parameter_list|(
name|int
name|rc
parameter_list|,
specifier|const
name|char
modifier|*
name|funcInfo
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|,
name|bool
name|critical
parameter_list|)
block|{
if|if
condition|(
operator|!
name|rc
operator|&&
operator|(
name|QQnxIntegration
operator|::
name|options
argument_list|()
operator|&
name|QQnxIntegration
operator|::
name|AlwaysFlushScreenContext
operator|)
operator|&&
name|QQnxIntegration
operator|::
name|screenContext
argument_list|()
operator|!=
literal|0
condition|)
block|{
name|rc
operator|=
name|screen_flush_context
argument_list|(
name|QQnxIntegration
operator|::
name|screenContext
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|rc
condition|)
block|{
if|if
condition|(
name|critical
condition|)
name|qCritical
argument_list|(
literal|"%s - Screen: %s - Error: %s (%i)"
argument_list|,
name|funcInfo
argument_list|,
name|message
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|,
name|errno
argument_list|)
expr_stmt|;
else|else
name|qWarning
argument_list|(
literal|"%s - Screen: %s - Error: %s (%i)"
argument_list|,
name|funcInfo
argument_list|,
name|message
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|,
name|errno
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
