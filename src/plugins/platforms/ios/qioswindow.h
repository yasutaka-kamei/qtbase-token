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
begin_macro
unit|@
DECL|variable|viewController
name|property
argument_list|(
argument|readonly
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|viewController
name|UIViewController
modifier|*
name|viewController
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|viewController
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
DECL|variable|QObject
name|class
name|QIOSWindow
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QPlatformWindow
block|{
name|Q_OBJECT
name|public
range|:
name|explicit
name|QIOSWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
decl_stmt|;
operator|~
name|QIOSWindow
argument_list|()
expr_stmt|;
name|void
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
name|void
name|setWindowState
argument_list|(
name|Qt
operator|::
name|WindowState
name|state
argument_list|)
decl_stmt|;
name|void
name|setParent
parameter_list|(
specifier|const
name|QPlatformWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|void
name|handleContentOrientationChange
argument_list|(
name|Qt
operator|::
name|ScreenOrientation
name|orientation
argument_list|)
decl_stmt|;
name|void
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
function_decl|;
name|void
name|raise
parameter_list|()
block|{
name|raiseOrLower
argument_list|(
name|true
argument_list|)
expr_stmt|;
block|}
name|void
name|lower
parameter_list|()
block|{
name|raiseOrLower
argument_list|(
name|false
argument_list|)
expr_stmt|;
block|}
name|void
name|requestActivateWindow
parameter_list|()
function_decl|;
name|qreal
name|devicePixelRatio
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|setMouseGrabEnabled
parameter_list|(
name|bool
name|grab
parameter_list|)
block|{
return|return
name|grab
return|;
block|}
name|bool
name|setKeyboardGrabEnabled
parameter_list|(
name|bool
name|grab
parameter_list|)
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
empty_stmt|;
name|QIOSWindow
operator|*
name|topLevelWindow
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|void
name|applyGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
function_decl|;
name|QUIView
modifier|*
name|m_view
decl_stmt|;
name|QRect
name|m_normalGeometry
decl_stmt|;
name|int
name|m_windowLevel
decl_stmt|;
name|void
name|raiseOrLower
parameter_list|(
name|bool
name|raise
parameter_list|)
function_decl|;
name|void
name|updateWindowLevel
parameter_list|()
function_decl|;
name|bool
name|blockedByModal
parameter_list|()
function_decl|;
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
parameter_list|()
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
name|friend
name|class
name|QIOSScreen
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
comment|// QIOSWINDOW_H
end_comment
end_unit
