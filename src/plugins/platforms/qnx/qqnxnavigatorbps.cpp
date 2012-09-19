begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2012 Research In Motion ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxnavigatorbps.h"
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<bps/navigator.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QQnxNavigatorBps
name|QQnxNavigatorBps
operator|::
name|QQnxNavigatorBps
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QQnxAbstractNavigator
argument_list|(
name|parent
argument_list|)
block|{
name|bps_initialize
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QQnxNavigatorBps
name|QQnxNavigatorBps
operator|::
name|~
name|QQnxNavigatorBps
parameter_list|()
block|{
name|bps_shutdown
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|requestInvokeUrl
name|bool
name|QQnxNavigatorBps
operator|::
name|requestInvokeUrl
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|encodedUrl
parameter_list|)
block|{
name|char
modifier|*
name|error
init|=
literal|0
decl_stmt|;
name|int
name|ret
init|=
name|navigator_invoke
argument_list|(
name|encodedUrl
argument_list|,
operator|&
name|error
argument_list|)
decl_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"error="
operator|<<
name|error
expr_stmt|;
name|bps_free
argument_list|(
name|error
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|ret
operator|==
name|BPS_SUCCESS
operator|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
