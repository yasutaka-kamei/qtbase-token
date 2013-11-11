begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QIOSWINDOW_H
end_ifndef
begin_define
DECL|macro|QIOSWINDOW_H
define|#
directive|define
name|QIOSWINDOW_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformwindow.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_empty
empty|#import<UIKit/UIKit.h>
end_empty
begin_decl_stmt
DECL|variable|QIOSContext
name|class
name|QIOSContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIOSWindow
name|class
name|QIOSWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIOSWindow
unit|@
name|interface
name|UIView
argument_list|(
name|QIOS
argument_list|)
decl|@
name|property
argument_list|(
name|readonly
argument_list|)
name|QWindow
modifier|*
name|qwindow
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|@
name|end
name|QT_BEGIN_NAMESPACE
expr|@
DECL|variable|QUIView
name|class
name|QUIView
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QIOSWindow
range|:
name|public
name|QPlatformWindow
block|{
name|public
operator|:
name|explicit
name|QIOSWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
operator|~
name|QIOSWindow
argument_list|()
block|;
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|void
name|setWindowState
argument_list|(
argument|Qt::WindowState state
argument_list|)
block|;
name|void
name|setParent
argument_list|(
specifier|const
name|QPlatformWindow
operator|*
name|window
argument_list|)
block|;
name|void
name|handleContentOrientationChange
argument_list|(
argument|Qt::ScreenOrientation orientation
argument_list|)
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|raise
argument_list|()
block|{
name|raiseOrLower
argument_list|(
name|true
argument_list|)
block|; }
name|void
name|lower
argument_list|()
block|{
name|raiseOrLower
argument_list|(
name|false
argument_list|)
block|; }
name|void
name|requestActivateWindow
argument_list|()
block|;
name|qreal
name|devicePixelRatio
argument_list|()
specifier|const
block|;
name|bool
name|setMouseGrabEnabled
argument_list|(
argument|bool grab
argument_list|)
block|{
return|return
name|grab
return|;
block|}
name|bool
name|setKeyboardGrabEnabled
argument_list|(
argument|bool grab
argument_list|)
block|{
return|return
name|grab
return|;
block|}
name|WId
name|winId
argument_list|()
specifier|const
block|{
return|return
name|WId
argument_list|(
name|m_view
argument_list|)
return|;
block|}
block|;
name|private
operator|:
name|QUIView
operator|*
name|m_view
block|;
name|QRect
name|m_normalGeometry
block|;
name|int
name|m_windowLevel
block|;
name|void
name|raiseOrLower
argument_list|(
argument|bool raise
argument_list|)
block|;
name|void
name|updateWindowLevel
argument_list|()
block|;
name|bool
name|blockedByModal
argument_list|()
block|;
specifier|inline
name|Qt
operator|::
name|WindowType
name|windowType
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|Qt
operator|::
name|WindowType
operator|>
operator|(
name|int
argument_list|(
name|window
argument_list|()
operator|->
name|flags
argument_list|()
operator|&
name|Qt
operator|::
name|WindowType_Mask
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|bool
name|windowIsPopup
argument_list|()
block|{
return|return
name|windowType
argument_list|()
operator|&
name|Qt
operator|::
name|Popup
operator|&
operator|~
name|Qt
operator|::
name|Window
return|;
block|}
expr|}
block|;
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QIOSWINDOW_H
end_comment
end_unit
