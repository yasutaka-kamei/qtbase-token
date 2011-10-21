begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGUIAPPLICATION_QPA_H
end_ifndef
begin_define
DECL|macro|QGUIAPPLICATION_QPA_H
define|#
directive|define
name|QGUIAPPLICATION_QPA_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlocale.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpoint.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsize.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QGuiApplicationPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformNativeInterface
name|class
name|QPlatformNativeInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPalette
name|class
name|QPalette
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QScreen
name|class
name|QScreen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleHints
name|class
name|QStyleHints
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QInputPanel
name|class
name|QInputPanel
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|qApp
argument_list|)
end_if
begin_undef
DECL|macro|qApp
undef|#
directive|undef
name|qApp
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|qApp
define|#
directive|define
name|qApp
value|(static_cast<QGuiApplication *>(QCoreApplication::instance()))
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|qGuiApp
argument_list|)
end_if
begin_undef
DECL|macro|qGuiApp
undef|#
directive|undef
name|qGuiApp
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|qGuiApp
define|#
directive|define
name|qGuiApp
value|(static_cast<QGuiApplication *>(QCoreApplication::instance()))
end_define
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QGuiApplication
range|:
name|public
name|QCoreApplication
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|Qt::LayoutDirection layoutDirection READ layoutDirection WRITE setLayoutDirection
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool quitOnLastWindowClosed  READ quitOnLastWindowClosed WRITE setQuitOnLastWindowClosed
argument_list|)
name|public
operator|:
name|QGuiApplication
argument_list|(
name|int
operator|&
name|argc
argument_list|,
name|char
operator|*
operator|*
name|argv
argument_list|,
name|int
operator|=
name|ApplicationFlags
argument_list|)
block|;
name|virtual
operator|~
name|QGuiApplication
argument_list|()
block|;
specifier|static
name|QWindowList
name|topLevelWindows
argument_list|()
block|;
specifier|static
name|QWindow
operator|*
name|topLevelAt
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
block|;
ifdef|#
directive|ifdef
name|QT_DEPRECATED
specifier|static
name|QT_DEPRECATED
name|QWindow
operator|*
name|activeWindow
argument_list|()
block|{
return|return
name|focusWindow
argument_list|()
return|;
block|}
endif|#
directive|endif
specifier|static
name|QWindow
operator|*
name|focusWindow
argument_list|()
block|;
specifier|static
name|QScreen
operator|*
name|primaryScreen
argument_list|()
block|;
specifier|static
name|QList
operator|<
name|QScreen
operator|*
operator|>
name|screens
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
specifier|static
name|QCursor
operator|*
name|overrideCursor
argument_list|()
block|;
specifier|static
name|void
name|setOverrideCursor
argument_list|(
specifier|const
name|QCursor
operator|&
argument_list|)
block|;
specifier|static
name|void
name|changeOverrideCursor
argument_list|(
specifier|const
name|QCursor
operator|&
argument_list|)
block|;
specifier|static
name|void
name|restoreOverrideCursor
argument_list|()
block|;
endif|#
directive|endif
specifier|static
name|QFont
name|font
argument_list|()
block|;
specifier|static
name|void
name|setFont
argument_list|(
specifier|const
name|QFont
operator|&
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
specifier|static
name|QClipboard
operator|*
name|clipboard
argument_list|()
block|;
endif|#
directive|endif
specifier|static
name|QPalette
name|palette
argument_list|()
block|;
specifier|static
name|Qt
operator|::
name|KeyboardModifiers
name|keyboardModifiers
argument_list|()
block|;
specifier|static
name|Qt
operator|::
name|MouseButtons
name|mouseButtons
argument_list|()
block|;
specifier|static
name|void
name|setLayoutDirection
argument_list|(
argument|Qt::LayoutDirection direction
argument_list|)
block|;
specifier|static
name|Qt
operator|::
name|LayoutDirection
name|layoutDirection
argument_list|()
block|;
specifier|static
specifier|inline
name|bool
name|isRightToLeft
argument_list|()
block|{
return|return
name|layoutDirection
argument_list|()
operator|==
name|Qt
operator|::
name|RightToLeft
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isLeftToRight
argument_list|()
block|{
return|return
name|layoutDirection
argument_list|()
operator|==
name|Qt
operator|::
name|LeftToRight
return|;
block|}
comment|// ### move to QInputPanel
specifier|static
name|QLocale
name|keyboardInputLocale
argument_list|()
block|;
specifier|static
name|Qt
operator|::
name|LayoutDirection
name|keyboardInputDirection
argument_list|()
block|;
name|QStyleHints
operator|*
name|styleHints
argument_list|()
specifier|const
block|;
name|QInputPanel
operator|*
name|inputPanel
argument_list|()
specifier|const
block|;
specifier|static
name|QPlatformNativeInterface
operator|*
name|platformNativeInterface
argument_list|()
block|;
specifier|static
name|void
name|setQuitOnLastWindowClosed
argument_list|(
argument|bool quit
argument_list|)
block|;
specifier|static
name|bool
name|quitOnLastWindowClosed
argument_list|()
block|;
specifier|static
name|int
name|exec
argument_list|()
block|;
name|bool
name|notify
argument_list|(
name|QObject
operator|*
argument_list|,
name|QEvent
operator|*
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|fontDatabaseChanged
argument_list|()
block|;
name|void
name|screenAdded
argument_list|(
name|QScreen
operator|*
name|screen
argument_list|)
block|;
name|void
name|lastWindowClosed
argument_list|()
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
name|QEvent
operator|*
argument_list|)
block|;
name|bool
name|compressEvent
argument_list|(
name|QEvent
operator|*
argument_list|,
name|QObject
operator|*
name|receiver
argument_list|,
name|QPostEventList
operator|*
argument_list|)
block|;
name|QGuiApplication
argument_list|(
name|QGuiApplicationPrivate
operator|&
name|p
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QGuiApplication
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGuiApplication
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
name|friend
name|class
name|QGestureManager
block|;
endif|#
directive|endif
name|friend
name|class
name|QFontDatabasePrivate
block|;
name|friend
name|class
name|QPlatformIntegration
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
comment|// QGUIAPPLICATION_QPA_H
end_comment
end_unit
