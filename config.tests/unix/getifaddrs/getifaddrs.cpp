begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the config.tests of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/* Sample program for configure to test for if_nametoindex support on target platforms. */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__hpux
argument_list|)
end_if
begin_define
DECL|macro|_HPUX_SOURCE
define|#
directive|define
name|_HPUX_SOURCE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/socket.h>
end_include
begin_include
include|#
directive|include
file|<net/if.h>
end_include
begin_include
include|#
directive|include
file|<ifaddrs.h>
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
name|ifaddrs
modifier|*
name|list
decl_stmt|;
name|getifaddrs
argument_list|(
operator|&
name|list
argument_list|)
expr_stmt|;
name|freeifaddrs
argument_list|(
name|list
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
end_unit
