begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTOUCHDEVICE_P_H
end_ifndef
begin_define
DECL|macro|QTOUCHDEVICE_P_H
define|#
directive|define
name|QTOUCHDEVICE_P_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtouchdevice.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
name|class
name|QTouchDevicePrivate
decl_stmt|{ public:     QTouchDevicePrivate(
end_function
begin_expr_stmt
unit|)         :
name|type
argument_list|(
name|QTouchDevice
operator|::
name|TouchScreen
argument_list|)
operator|,
name|caps
argument_list|(
argument|QTouchDevice::Position
argument_list|)
block|{ }
name|QTouchDevice
operator|::
name|DeviceType
name|type
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QTouchDevice
operator|::
name|Capabilities
name|caps
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QString
name|name
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|void
name|registerDevice
parameter_list|(
name|QTouchDevice
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|isRegistered
parameter_list|(
name|QTouchDevice
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTOUCHDEVICE_P_H
end_comment
end_unit
