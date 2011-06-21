begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOW_QPA_P_H
end_ifndef
begin_define
DECL|macro|QWINDOW_QPA_P_H
define|#
directive|define
name|QWINDOW_QPA_P_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qobject_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|function|QT_MODULE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
DECL|macro|QWINDOWSIZE_MAX
define|#
directive|define
name|QWINDOWSIZE_MAX
value|((1<<24)-1)
name|class
name|Q_GUI_EXPORT
name|QWindowPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|public
operator|:
name|QWindowPrivate
argument_list|()
operator|:
name|QObjectPrivate
argument_list|()
block|,
name|windowFlags
argument_list|(
name|Qt
operator|::
name|Window
argument_list|)
block|,
name|parentWindow
argument_list|(
literal|0
argument_list|)
block|,
name|platformWindow
argument_list|(
literal|0
argument_list|)
block|,
name|visible
argument_list|(
name|false
argument_list|)
block|,
name|windowState
argument_list|(
name|Qt
operator|::
name|WindowNoState
argument_list|)
block|,
name|maximumSize
argument_list|(
name|QWINDOWSIZE_MAX
argument_list|,
name|QWINDOWSIZE_MAX
argument_list|)
block|,
name|modality
argument_list|(
name|Qt
operator|::
name|NonModal
argument_list|)
block|,
name|transientParent
argument_list|(
literal|0
argument_list|)
block|{
name|isWindow
operator|=
name|true
block|;     }
operator|~
name|QWindowPrivate
argument_list|()
block|{     }
name|Qt
operator|::
name|WindowFlags
name|windowFlags
block|;
name|QWindow
operator|*
name|parentWindow
block|;
name|QPlatformWindow
operator|*
name|platformWindow
block|;
name|bool
name|visible
block|;
name|QSurfaceFormat
name|requestedFormat
block|;
name|QString
name|windowTitle
block|;
name|QRect
name|geometry
block|;
name|Qt
operator|::
name|WindowState
name|windowState
block|;
name|QSize
name|minimumSize
block|;
name|QSize
name|maximumSize
block|;
name|QSize
name|baseSize
block|;
name|QSize
name|sizeIncrement
block|;
name|Qt
operator|::
name|WindowModality
name|modality
block|;
name|QPointer
operator|<
name|QWindow
operator|>
name|transientParent
block|; }
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
comment|// QWINDOW_QPA_P_H
end_comment
end_unit
