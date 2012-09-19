begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QACCESSIBLEBRIDGE_H
end_ifndef
begin_define
DECL|macro|QACCESSIBLEBRIDGE_H
define|#
directive|define
name|QACCESSIBLEBRIDGE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qplugin.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfactoryinterface.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
DECL|variable|QAccessibleInterface
name|class
name|QAccessibleInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleEvent
name|class
name|QAccessibleEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAccessibleBridge
block|{
name|public
label|:
name|virtual
operator|~
name|QAccessibleBridge
argument_list|()
block|{}
name|virtual
name|void
name|setRootObject
argument_list|(
name|QAccessibleInterface
operator|*
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|notifyAccessibilityUpdate
parameter_list|(
name|QAccessibleEvent
modifier|*
name|event
parameter_list|)
init|=
literal|0
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_define
DECL|macro|QAccessibleBridgeFactoryInterface_iid
define|#
directive|define
name|QAccessibleBridgeFactoryInterface_iid
value|"org.qt-project.Qt.QAccessibleBridgeFactoryInterface"
end_define
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QAccessibleBridgePlugin
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QAccessibleBridgePlugin
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QAccessibleBridgePlugin
argument_list|()
block|;
name|virtual
name|QAccessibleBridge
operator|*
name|create
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
operator|=
literal|0
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ACCESSIBILITY
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QACCESSIBLEBRIDGE_H
end_comment
end_unit
