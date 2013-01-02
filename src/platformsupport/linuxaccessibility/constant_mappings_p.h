begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*  * This file contains AT-SPI constants and mappings between QAccessible  * and AT-SPI constants such as 'role' and 'state' enumerations.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|Q_SPI_CONSTANT_MAPPINGS_H
end_ifndef
begin_define
DECL|macro|Q_SPI_CONSTANT_MAPPINGS_H
define|#
directive|define
name|Q_SPI_CONSTANT_MAPPINGS_H
end_define
begin_include
include|#
directive|include
file|"struct_marshallers_p.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QAccessible>
end_include
begin_include
include|#
directive|include
file|<atspi/atspi-constants.h>
end_include
begin_comment
comment|// interface names from at-spi2-core/atspi/atspi-misc-private.h
end_comment
begin_define
DECL|macro|ATSPI_DBUS_NAME_REGISTRY
define|#
directive|define
name|ATSPI_DBUS_NAME_REGISTRY
value|"org.a11y.atspi.Registry"
end_define
begin_define
DECL|macro|ATSPI_DBUS_PATH_REGISTRY
define|#
directive|define
name|ATSPI_DBUS_PATH_REGISTRY
value|"/org/a11y/atspi/registry"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_REGISTRY
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_REGISTRY
value|"org.a11y.atspi.Registry"
end_define
begin_define
DECL|macro|ATSPI_DBUS_PATH_ROOT
define|#
directive|define
name|ATSPI_DBUS_PATH_ROOT
value|"/org/a11y/atspi/accessible/root"
end_define
begin_define
DECL|macro|ATSPI_DBUS_PATH_DEC
define|#
directive|define
name|ATSPI_DBUS_PATH_DEC
value|"/org/a11y/atspi/registry/deviceeventcontroller"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_DEC
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_DEC
value|"org.a11y.atspi.DeviceEventController"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_DEVICE_EVENT_LISTENER
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_DEVICE_EVENT_LISTENER
value|"org.a11y.atspi.DeviceEventListener"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_CACHE
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_CACHE
value|"org.a11y.atspi.Cache"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_ACCESSIBLE
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_ACCESSIBLE
value|"org.a11y.atspi.Accessible"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_ACTION
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_ACTION
value|"org.a11y.atspi.Action"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_APPLICATION
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_APPLICATION
value|"org.a11y.atspi.Application"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_COLLECTION
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_COLLECTION
value|"org.a11y.atspi.Collection"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_COMPONENT
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_COMPONENT
value|"org.a11y.atspi.Component"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_DOCUMENT
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_DOCUMENT
value|"org.a11y.atspi.Document"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_EDITABLE_TEXT
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_EDITABLE_TEXT
value|"org.a11y.atspi.EditableText"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_EVENT_KEYBOARD
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_EVENT_KEYBOARD
value|"org.a11y.atspi.Event.Keyboard"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_EVENT_MOUSE
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_EVENT_MOUSE
value|"org.a11y.atspi.Event.Mouse"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_EVENT_OBJECT
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_EVENT_OBJECT
value|"org.a11y.atspi.Event.Object"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_HYPERLINK
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_HYPERLINK
value|"org.a11y.atspi.Hyperlink"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_HYPERTEXT
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_HYPERTEXT
value|"org.a11y.atspi.Hypertext"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_IMAGE
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_IMAGE
value|"org.a11y.atspi.Image"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_SELECTION
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_SELECTION
value|"org.a11y.atspi.Selection"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_TABLE
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_TABLE
value|"org.a11y.atspi.Table"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_TEXT
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_TEXT
value|"org.a11y.atspi.Text"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_VALUE
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_VALUE
value|"org.a11y.atspi.Value"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_SOCKET
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_SOCKET
value|"org.a11y.atspi.Socket"
end_define
begin_comment
comment|// missing from at-spi2-core:
end_comment
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_EVENT_WINDOW
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_EVENT_WINDOW
value|"org.a11y.atspi.Event.Window"
end_define
begin_define
DECL|macro|ATSPI_DBUS_INTERFACE_EVENT_FOCUS
define|#
directive|define
name|ATSPI_DBUS_INTERFACE_EVENT_FOCUS
value|"org.a11y.atspi.Event.Focus"
end_define
begin_define
DECL|macro|QSPI_OBJECT_PATH_ACCESSIBLE
define|#
directive|define
name|QSPI_OBJECT_PATH_ACCESSIBLE
value|"/org/a11y/atspi/accessible"
end_define
begin_define
DECL|macro|QSPI_OBJECT_PATH_PREFIX
define|#
directive|define
name|QSPI_OBJECT_PATH_PREFIX
value|"/org/a11y/atspi/accessible/"
end_define
begin_define
DECL|macro|QSPI_OBJECT_PATH_ROOT
define|#
directive|define
name|QSPI_OBJECT_PATH_ROOT
value|QSPI_OBJECT_PATH_PREFIX "root"
end_define
begin_define
DECL|macro|QSPI_REGISTRY_NAME
define|#
directive|define
name|QSPI_REGISTRY_NAME
value|"org.a11y.atspi.Registry"
end_define
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
expr|struct
DECL|struct|RoleNames
name|RoleNames
block|{
DECL|function|RoleNames
name|RoleNames
argument_list|()
block|{}
DECL|function|RoleNames
name|RoleNames
argument_list|(
argument|AtspiRole r
argument_list|,
argument|const QString& n
argument_list|,
argument|const QString& ln
argument_list|)
operator|:
name|m_spiRole
argument_list|(
name|r
argument_list|)
block|,
name|m_name
argument_list|(
name|n
argument_list|)
block|,
name|m_localizedName
argument_list|(
argument|ln
argument_list|)
block|{}
DECL|function|spiRole
name|AtspiRole
name|spiRole
argument_list|()
specifier|const
block|{
return|return
name|m_spiRole
return|;
block|}
DECL|function|name
name|QString
name|name
argument_list|()
specifier|const
block|{
return|return
name|m_name
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|localizedName
name|QString
name|localizedName
argument_list|()
specifier|const
block|{
return|return
name|m_localizedName
return|;
block|}
end_expr_stmt
begin_label
DECL|member|private
name|private
label|:
end_label
begin_decl_stmt
name|AtspiRole
name|m_spiRole
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|m_name
name|QString
name|m_name
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|m_localizedName
name|QString
name|m_localizedName
decl_stmt|;
end_decl_stmt
begin_extern
unit|};
extern|extern QHash<QAccessible::Role
operator|,
extern|RoleNames> qSpiRoleMapping;
end_extern
begin_extern
extern|extern QHash<int
operator|,
extern|AtspiStateType> qSpiStateMapping;
end_extern
begin_function
DECL|function|setSpiStateBit
specifier|inline
name|void
name|setSpiStateBit
parameter_list|(
name|quint64
modifier|*
name|state
parameter_list|,
name|AtspiStateType
name|spiState
parameter_list|)
block|{
operator|*
name|state
operator||=
name|quint64
argument_list|(
literal|1
argument_list|)
operator|<<
name|spiState
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unsetSpiStateBit
specifier|inline
name|void
name|unsetSpiStateBit
parameter_list|(
name|quint64
modifier|*
name|state
parameter_list|,
name|AtspiStateType
name|spiState
parameter_list|)
block|{
operator|*
name|state
operator|&=
operator|~
operator|(
name|quint64
argument_list|(
literal|1
argument_list|)
operator|<<
name|spiState
operator|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
name|quint64
name|spiStatesFromQState
argument_list|(
name|QAccessible
operator|::
name|State
name|state
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QSpiUIntList
name|spiStateSetFromSpiStates
parameter_list|(
name|quint64
name|states
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|AtspiRelationType
name|qAccessibleRelationToAtSpiRelation
argument_list|(
name|QAccessible
operator|::
name|Relation
name|relation
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Q_SPI_CONSTANT_MAPPINGS_H */
end_comment
end_unit
