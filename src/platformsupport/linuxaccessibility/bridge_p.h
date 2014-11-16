begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSPIACCESSIBLEBRIDGE_H
end_ifndef
begin_define
DECL|macro|QSPIACCESSIBLEBRIDGE_H
define|#
directive|define
name|QSPIACCESSIBLEBRIDGE_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtDBus/qdbusconnection.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformaccessibility.h>
end_include
begin_decl_stmt
DECL|variable|DeviceEventControllerAdaptor
name|class
name|DeviceEventControllerAdaptor
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|DBusConnection
name|class
name|DBusConnection
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QSpiDBusCache
name|class
name|QSpiDBusCache
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|AtSpiAdaptor
name|class
name|AtSpiAdaptor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QSpiAccessibleBridge
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QPlatformAccessibility
block|{
name|Q_OBJECT
name|public
range|:
name|QSpiAccessibleBridge
argument_list|()
decl_stmt|;
name|virtual
operator|~
name|QSpiAccessibleBridge
argument_list|()
expr_stmt|;
name|virtual
name|void
name|notifyAccessibilityUpdate
argument_list|(
name|QAccessibleEvent
operator|*
name|event
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QDBusConnection
name|dBusConnection
argument_list|()
specifier|const
expr_stmt|;
name|public
name|Q_SLOTS
range|:
name|void
name|enabledChanged
argument_list|(
argument|bool enabled
argument_list|)
decl_stmt|;
name|private
label|:
name|void
name|initializeConstantMappings
parameter_list|()
function_decl|;
name|void
name|updateStatus
parameter_list|()
function_decl|;
name|QSpiDBusCache
modifier|*
name|cache
decl_stmt|;
name|DeviceEventControllerAdaptor
modifier|*
name|dec
decl_stmt|;
name|AtSpiAdaptor
modifier|*
name|dbusAdaptor
decl_stmt|;
name|DBusConnection
modifier|*
name|dbusConnection
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_ACCESSIBILITY
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
