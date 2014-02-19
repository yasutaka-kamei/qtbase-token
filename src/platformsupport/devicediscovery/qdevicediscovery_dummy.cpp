begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdevicediscovery_p.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|create
name|QDeviceDiscovery
modifier|*
name|QDeviceDiscovery
operator|::
name|create
parameter_list|(
name|QDeviceTypes
name|types
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
block|{
return|return
operator|new
name|QDeviceDiscovery
argument_list|(
name|types
argument_list|,
name|parent
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|QDeviceDiscovery
name|QDeviceDiscovery
operator|::
name|QDeviceDiscovery
parameter_list|(
name|QDeviceTypes
name|types
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_types
argument_list|(
name|types
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QDeviceDiscovery
name|QDeviceDiscovery
operator|::
name|~
name|QDeviceDiscovery
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|scanConnectedDevices
name|QStringList
name|QDeviceDiscovery
operator|::
name|scanConnectedDevices
parameter_list|()
block|{
return|return
name|QStringList
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|checkDeviceType
name|bool
name|QDeviceDiscovery
operator|::
name|checkDeviceType
parameter_list|(
specifier|const
name|QString
modifier|&
name|device
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|device
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
