begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QAPPLICATION_H
end_ifndef
begin_define
DECL|macro|QAPPLICATION_H
define|#
directive|define
name|QAPPLICATION_H
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
file|<QtCore/qpoint.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsize.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qcursor.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_INCLUDE_COMPAT
end_ifdef
begin_include
include|#
directive|include
file|<QtWidgets/qdesktopwidget.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtGui/qguiapplication.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QSessionManager
name|class
name|QSessionManager
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDesktopWidget
name|class
name|QDesktopWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyle
name|class
name|QStyle
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEventLoop
name|class
name|QEventLoop
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIcon
name|class
name|QIcon
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|QList
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|QList
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QLocale
name|class
name|QLocale
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformNativeInterface
name|class
name|QPlatformNativeInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QApplication
name|class
name|QApplication
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QApplicationPrivate
name|class
name|QApplicationPrivate
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
value|(static_cast<QApplication *>(QCoreApplication::instance()))
end_define
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QApplication
range|:
name|public
name|QGuiApplication
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QIcon windowIcon READ windowIcon WRITE setWindowIcon
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int cursorFlashTime READ cursorFlashTime WRITE setCursorFlashTime
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int doubleClickInterval  READ doubleClickInterval WRITE setDoubleClickInterval
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int keyboardInputInterval READ keyboardInputInterval WRITE setKeyboardInputInterval
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|Q_PROPERTY
argument_list|(
argument|int wheelScrollLines  READ wheelScrollLines WRITE setWheelScrollLines
argument_list|)
endif|#
directive|endif
name|Q_PROPERTY
argument_list|(
argument|QSize globalStrut READ globalStrut WRITE setGlobalStrut
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int startDragTime  READ startDragTime WRITE setStartDragTime
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int startDragDistance  READ startDragDistance WRITE setStartDragDistance
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_STYLE_STYLESHEET
name|Q_PROPERTY
argument_list|(
argument|QString styleSheet READ styleSheet WRITE setStyleSheet
argument_list|)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_WINCE
name|Q_PROPERTY
argument_list|(
argument|int autoMaximizeThreshold READ autoMaximizeThreshold WRITE setAutoMaximizeThreshold
argument_list|)
endif|#
directive|endif
name|Q_PROPERTY
argument_list|(
argument|bool autoSipEnabled READ autoSipEnabled WRITE setAutoSipEnabled
argument_list|)
name|public
operator|:
ifndef|#
directive|ifndef
name|qdoc
name|QApplication
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
name|QT_DEPRECATED
name|QApplication
argument_list|(
argument|int&argc
argument_list|,
argument|char **argv
argument_list|,
argument|bool GUIenabled
argument_list|,
argument|int = ApplicationFlags
argument_list|)
block|;
name|QApplication
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
name|Type
argument_list|,
name|int
operator|=
name|ApplicationFlags
argument_list|)
block|;
endif|#
directive|endif
name|virtual
operator|~
name|QApplication
argument_list|()
block|;
specifier|static
name|Type
name|type
argument_list|()
block|;
specifier|static
name|QStyle
operator|*
name|style
argument_list|()
block|;
specifier|static
name|void
name|setStyle
argument_list|(
name|QStyle
operator|*
argument_list|)
block|;
specifier|static
name|QStyle
operator|*
name|setStyle
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
block|;     enum
name|ColorSpec
block|{
name|NormalColor
operator|=
literal|0
block|,
name|CustomColor
operator|=
literal|1
block|,
name|ManyColor
operator|=
literal|2
block|}
block|;
specifier|static
name|int
name|colorSpec
argument_list|()
block|;
specifier|static
name|void
name|setColorSpec
argument_list|(
name|int
argument_list|)
block|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
specifier|static
specifier|inline
name|void
name|setGraphicsSystem
argument_list|(
argument|const QString&
argument_list|)
block|{}
endif|#
directive|endif
name|using
name|QGuiApplication
operator|::
name|palette
block|;
specifier|static
name|QPalette
name|palette
argument_list|(
specifier|const
name|QWidget
operator|*
argument_list|)
block|;
specifier|static
name|QPalette
name|palette
argument_list|(
specifier|const
name|char
operator|*
name|className
argument_list|)
block|;
specifier|static
name|void
name|setPalette
argument_list|(
specifier|const
name|QPalette
operator|&
argument_list|,
specifier|const
name|char
operator|*
name|className
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|QFont
name|font
argument_list|()
block|;
specifier|static
name|QFont
name|font
argument_list|(
specifier|const
name|QWidget
operator|*
argument_list|)
block|;
specifier|static
name|QFont
name|font
argument_list|(
specifier|const
name|char
operator|*
name|className
argument_list|)
block|;
specifier|static
name|void
name|setFont
argument_list|(
specifier|const
name|QFont
operator|&
argument_list|,
specifier|const
name|char
operator|*
name|className
operator|=
literal|0
argument_list|)
block|;
specifier|static
name|QFontMetrics
name|fontMetrics
argument_list|()
block|;
specifier|static
name|void
name|setWindowIcon
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|)
block|;
specifier|static
name|QIcon
name|windowIcon
argument_list|()
block|;
specifier|static
name|QWidgetList
name|allWidgets
argument_list|()
block|;
specifier|static
name|QWidgetList
name|topLevelWidgets
argument_list|()
block|;
specifier|static
name|QDesktopWidget
operator|*
name|desktop
argument_list|()
block|;
specifier|static
name|QWidget
operator|*
name|activePopupWidget
argument_list|()
block|;
specifier|static
name|QWidget
operator|*
name|activeModalWidget
argument_list|()
block|;
specifier|static
name|QWidget
operator|*
name|focusWidget
argument_list|()
block|;
specifier|static
name|QWidget
operator|*
name|activeWindow
argument_list|()
block|;
specifier|static
name|void
name|setActiveWindow
argument_list|(
name|QWidget
operator|*
name|act
argument_list|)
block|;
specifier|static
name|QWidget
operator|*
name|widgetAt
argument_list|(
specifier|const
name|QPoint
operator|&
name|p
argument_list|)
block|;
specifier|static
specifier|inline
name|QWidget
operator|*
name|widgetAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
block|{
return|return
name|widgetAt
argument_list|(
name|QPoint
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|QWidget
operator|*
name|topLevelAt
argument_list|(
specifier|const
name|QPoint
operator|&
name|p
argument_list|)
block|;
specifier|static
specifier|inline
name|QWidget
operator|*
name|topLevelAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
block|{
return|return
name|topLevelAt
argument_list|(
name|QPoint
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
return|;
block|}
name|QT_DEPRECATED
specifier|static
name|void
name|syncX
argument_list|()
block|;
specifier|static
name|void
name|beep
argument_list|()
block|;
specifier|static
name|void
name|alert
argument_list|(
argument|QWidget *widget
argument_list|,
argument|int duration =
literal|0
argument_list|)
block|;
specifier|static
name|void
name|setCursorFlashTime
argument_list|(
name|int
argument_list|)
block|;
specifier|static
name|int
name|cursorFlashTime
argument_list|()
block|;
specifier|static
name|void
name|setDoubleClickInterval
argument_list|(
name|int
argument_list|)
block|;
specifier|static
name|int
name|doubleClickInterval
argument_list|()
block|;
specifier|static
name|void
name|setKeyboardInputInterval
argument_list|(
name|int
argument_list|)
block|;
specifier|static
name|int
name|keyboardInputInterval
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
specifier|static
name|void
name|setWheelScrollLines
argument_list|(
name|int
argument_list|)
block|;
specifier|static
name|int
name|wheelScrollLines
argument_list|()
block|;
endif|#
directive|endif
specifier|static
name|void
name|setGlobalStrut
argument_list|(
specifier|const
name|QSize
operator|&
argument_list|)
block|;
specifier|static
name|QSize
name|globalStrut
argument_list|()
block|;
specifier|static
name|void
name|setStartDragTime
argument_list|(
argument|int ms
argument_list|)
block|;
specifier|static
name|int
name|startDragTime
argument_list|()
block|;
specifier|static
name|void
name|setStartDragDistance
argument_list|(
argument|int l
argument_list|)
block|;
specifier|static
name|int
name|startDragDistance
argument_list|()
block|;
specifier|static
name|bool
name|isEffectEnabled
argument_list|(
name|Qt
operator|::
name|UIEffect
argument_list|)
block|;
specifier|static
name|void
name|setEffectEnabled
argument_list|(
argument|Qt::UIEffect
argument_list|,
argument|bool enable = true
argument_list|)
block|;
specifier|static
name|QPlatformNativeInterface
operator|*
name|platformNativeInterface
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_SESSIONMANAGER
comment|// session management
name|bool
name|isSessionRestored
argument_list|()
specifier|const
block|;
name|QString
name|sessionId
argument_list|()
specifier|const
block|;
name|QString
name|sessionKey
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|commitData
argument_list|(
name|QSessionManager
operator|&
name|sm
argument_list|)
block|;
name|virtual
name|void
name|saveState
argument_list|(
name|QSessionManager
operator|&
name|sm
argument_list|)
block|;
endif|#
directive|endif
name|QT_DEPRECATED
specifier|static
name|QLocale
name|keyboardInputLocale
argument_list|()
block|;
name|QT_DEPRECATED
specifier|static
name|Qt
operator|::
name|LayoutDirection
name|keyboardInputDirection
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
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
specifier|static
name|Q_DECL_DEPRECATED
name|void
name|setKeypadNavigationEnabled
argument_list|(
name|bool
argument_list|)
block|;
specifier|static
name|bool
name|keypadNavigationEnabled
argument_list|()
block|;
specifier|static
name|void
name|setNavigationMode
argument_list|(
argument|Qt::NavigationMode mode
argument_list|)
block|;
specifier|static
name|Qt
operator|::
name|NavigationMode
name|navigationMode
argument_list|()
block|;
endif|#
directive|endif
name|Q_SIGNALS
operator|:
name|void
name|focusChanged
argument_list|(
name|QWidget
operator|*
name|old
argument_list|,
name|QWidget
operator|*
name|now
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_SESSIONMANAGER
name|void
name|commitDataRequest
argument_list|(
name|QSessionManager
operator|&
name|sessionManager
argument_list|)
block|;
name|void
name|saveStateRequest
argument_list|(
name|QSessionManager
operator|&
name|sessionManager
argument_list|)
block|;
endif|#
directive|endif
name|public
operator|:
name|QString
name|styleSheet
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
ifndef|#
directive|ifndef
name|QT_NO_STYLE_STYLESHEET
name|void
name|setStyleSheet
argument_list|(
specifier|const
name|QString
operator|&
name|sheet
argument_list|)
block|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_WINCE
name|void
name|setAutoMaximizeThreshold
argument_list|(
argument|const int threshold
argument_list|)
block|;
name|int
name|autoMaximizeThreshold
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|void
name|setAutoSipEnabled
argument_list|(
argument|const bool enabled
argument_list|)
block|;
name|bool
name|autoSipEnabled
argument_list|()
specifier|const
block|;
specifier|static
name|void
name|closeAllWindows
argument_list|()
block|;
specifier|static
name|void
name|aboutQt
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
if|#
directive|if
name|defined
argument_list|(
name|Q_INTERNAL_QAPP_SRC
argument_list|)
operator|||
name|defined
argument_list|(
name|qdoc
argument_list|)
name|QApplication
argument_list|(
name|int
operator|&
name|argc
argument_list|,
name|char
operator|*
operator|*
name|argv
argument_list|)
block|;
name|QT_DEPRECATED
name|QApplication
argument_list|(
argument|int&argc
argument_list|,
argument|char **argv
argument_list|,
argument|bool GUIenabled
argument_list|)
block|;
name|QApplication
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
name|Type
argument_list|)
block|;
endif|#
directive|endif
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QApplication
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QApplication
argument_list|)
name|friend
name|class
name|QGraphicsWidget
block|;
name|friend
name|class
name|QGraphicsItem
block|;
name|friend
name|class
name|QGraphicsScene
block|;
name|friend
name|class
name|QGraphicsScenePrivate
block|;
name|friend
name|class
name|QWidget
block|;
name|friend
name|class
name|QWidgetPrivate
block|;
name|friend
name|class
name|QWidgetWindow
block|;
name|friend
name|class
name|QETWidget
block|;
name|friend
name|class
name|Q3AccelManager
block|;
name|friend
name|class
name|QTranslator
block|;
name|friend
name|class
name|QWidgetAnimator
block|;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|friend
name|class
name|QShortcut
block|;
name|friend
name|class
name|QLineEdit
block|;
name|friend
name|class
name|QWidgetTextControl
block|;
endif|#
directive|endif
name|friend
name|class
name|QAction
block|;
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
name|friend
name|class
name|QGestureManager
block|;
endif|#
directive|endif
block|}
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
comment|// QAPPLICATION_H
end_comment
end_unit
