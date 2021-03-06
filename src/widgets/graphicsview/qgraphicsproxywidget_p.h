begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRAPHICSPROXYWIDGET_P_H
end_ifndef
begin_define
DECL|macro|QGRAPHICSPROXYWIDGET_P_H
define|#
directive|define
name|QGRAPHICSPROXYWIDGET_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
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
file|"qgraphicsproxywidget.h"
end_include
begin_include
include|#
directive|include
file|"private/qgraphicswidget_p.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_GRAPHICSVIEW
argument_list|)
end_if
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_AUTOTEST_EXPORT
name|QGraphicsProxyWidgetPrivate
range|:
name|public
name|QGraphicsWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QGraphicsProxyWidget
argument_list|)
name|public
operator|:
name|QGraphicsProxyWidgetPrivate
argument_list|()
block|;
operator|~
name|QGraphicsProxyWidgetPrivate
argument_list|()
block|;
name|void
name|init
argument_list|()
block|;
name|void
name|sendWidgetMouseEvent
argument_list|(
name|QGraphicsSceneMouseEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|sendWidgetMouseEvent
argument_list|(
name|QGraphicsSceneHoverEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|sendWidgetKeyEvent
argument_list|(
name|QKeyEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|setWidget_helper
argument_list|(
argument|QWidget *widget
argument_list|,
argument|bool autoShow
argument_list|)
block|;
name|QWidget
operator|*
name|findFocusChild
argument_list|(
argument|QWidget *child
argument_list|,
argument|bool next
argument_list|)
specifier|const
block|;
name|void
name|removeSubFocusHelper
argument_list|(
argument|QWidget *widget
argument_list|,
argument|Qt::FocusReason reason
argument_list|)
block|;
name|void
name|_q_removeWidgetSlot
argument_list|()
block|;
name|void
name|embedSubWindow
argument_list|(
name|QWidget
operator|*
argument_list|)
block|;
name|void
name|unembedSubWindow
argument_list|(
name|QWidget
operator|*
argument_list|)
block|;
name|bool
name|isProxyWidget
argument_list|()
specifier|const
block|;
name|QPointer
operator|<
name|QWidget
operator|>
name|widget
block|;
name|QPointer
operator|<
name|QWidget
operator|>
name|lastWidgetUnderMouse
block|;
name|QPointer
operator|<
name|QWidget
operator|>
name|embeddedMouseGrabber
block|;
name|QWidget
operator|*
name|dragDropWidget
block|;
name|Qt
operator|::
name|DropAction
name|lastDropAction
block|;
name|void
name|updateWidgetGeometryFromProxy
argument_list|()
block|;
name|void
name|updateProxyGeometryFromWidget
argument_list|()
block|;
name|void
name|updateProxyInputMethodAcceptanceFromWidget
argument_list|()
block|;
name|QPointF
name|mapToReceiver
argument_list|(
argument|const QPointF&pos
argument_list|,
argument|const QWidget *receiver
argument_list|)
specifier|const
block|;      enum
name|ChangeMode
block|{
name|NoMode
block|,
name|ProxyToWidgetMode
block|,
name|WidgetToProxyMode
block|}
block|;
name|quint32
name|posChangeMode
operator|:
literal|2
block|;
name|quint32
name|sizeChangeMode
operator|:
literal|2
block|;
name|quint32
name|visibleChangeMode
operator|:
literal|2
block|;
name|quint32
name|enabledChangeMode
operator|:
literal|2
block|;
name|quint32
name|styleChangeMode
operator|:
literal|2
block|;
name|quint32
name|paletteChangeMode
operator|:
literal|2
block|;
name|quint32
name|tooltipChangeMode
operator|:
literal|2
block|;
name|quint32
name|focusFromWidgetToProxy
operator|:
literal|1
block|;
name|quint32
name|proxyIsGivingFocus
operator|:
literal|1
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
end_unit
