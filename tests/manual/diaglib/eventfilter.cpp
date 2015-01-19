begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"eventfilter.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QMouseEvent>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTextStream>
end_include
begin_if
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_WIDGETS_LIB
argument_list|)
end_if
begin_define
DECL|macro|HAVE_APPLICATION
define|#
directive|define
name|HAVE_APPLICATION
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_GUI_LIB
argument_list|)
end_if
begin_define
DECL|macro|HAVE_GUI_APPLICATION
define|#
directive|define
name|HAVE_GUI_APPLICATION
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_comment
comment|// Qt 5
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_GUI_LIB
argument_list|)
end_if
begin_define
DECL|macro|HAVE_APPLICATION
define|#
directive|define
name|HAVE_APPLICATION
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_APPLICATION
end_ifdef
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QWidget>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GUI_APPLICATION
end_ifdef
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_namespace
DECL|namespace|QtDiag
namespace|namespace
name|QtDiag
block|{
DECL|function|EventFilter
name|EventFilter
operator|::
name|EventFilter
parameter_list|(
name|EventCategories
name|eventCategories
parameter_list|,
name|QObject
modifier|*
name|p
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|p
argument_list|)
block|{
name|init
argument_list|(
name|eventCategories
argument_list|)
expr_stmt|;
block|}
DECL|function|EventFilter
name|EventFilter
operator|::
name|EventFilter
parameter_list|(
name|QObject
modifier|*
name|p
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|p
argument_list|)
block|{
name|init
argument_list|(
name|EventCategories
argument_list|(
literal|0xFFFFFFF
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|function|init
name|void
name|EventFilter
operator|::
name|init
parameter_list|(
name|EventCategories
name|eventCategories
parameter_list|)
block|{
name|m_objectTypes
operator|=
name|OtherType
operator||
name|QWidgetType
operator||
name|QWindowType
expr_stmt|;
if|if
condition|(
name|eventCategories
operator|&
name|MouseEvents
condition|)
block|{
name|m_eventTypes
operator|<<
name|QEvent
operator|::
name|MouseButtonPress
operator|<<
name|QEvent
operator|::
name|MouseButtonRelease
operator|<<
name|QEvent
operator|::
name|MouseButtonDblClick
operator|<<
name|QEvent
operator|::
name|NonClientAreaMouseButtonPress
operator|<<
name|QEvent
operator|::
name|NonClientAreaMouseButtonRelease
operator|<<
name|QEvent
operator|::
name|NonClientAreaMouseButtonDblClick
operator|<<
name|QEvent
operator|::
name|Wheel
operator|<<
name|QEvent
operator|::
name|Enter
operator|<<
name|QEvent
operator|::
name|Leave
expr_stmt|;
block|}
if|if
condition|(
name|eventCategories
operator|&
name|MouseMoveEvents
condition|)
name|m_eventTypes
operator|<<
name|QEvent
operator|::
name|MouseMove
operator|<<
name|QEvent
operator|::
name|NonClientAreaMouseMove
expr_stmt|;
if|if
condition|(
name|eventCategories
operator|&
name|TouchEvents
condition|)
block|{
name|m_eventTypes
operator|<<
name|QEvent
operator|::
name|TouchBegin
operator|<<
name|QEvent
operator|::
name|TouchUpdate
operator|<<
name|QEvent
operator|::
name|TouchEnd
expr_stmt|;
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
name|m_eventTypes
operator|<<
name|QEvent
operator|::
name|TouchCancel
expr_stmt|;
endif|#
directive|endif
block|}
if|if
condition|(
name|eventCategories
operator|&
name|TabletEvents
condition|)
block|{
name|m_eventTypes
operator|<<
name|QEvent
operator|::
name|TabletEnterProximity
operator|<<
name|QEvent
operator|::
name|TabletLeaveProximity
operator|<<
name|QEvent
operator|::
name|TabletMove
operator|<<
name|QEvent
operator|::
name|TabletPress
operator|<<
name|QEvent
operator|::
name|TabletRelease
expr_stmt|;
block|}
if|if
condition|(
name|eventCategories
operator|&
name|DragAndDropEvents
condition|)
block|{
name|m_eventTypes
operator|<<
name|QEvent
operator|::
name|DragEnter
operator|<<
name|QEvent
operator|::
name|DragMove
operator|<<
name|QEvent
operator|::
name|DragLeave
operator|<<
name|QEvent
operator|::
name|Drop
operator|<<
name|QEvent
operator|::
name|DragResponse
expr_stmt|;
block|}
if|if
condition|(
name|eventCategories
operator|&
name|KeyEvents
condition|)
block|{
name|m_eventTypes
operator|<<
name|QEvent
operator|::
name|KeyPress
operator|<<
name|QEvent
operator|::
name|KeyRelease
operator|<<
name|QEvent
operator|::
name|ShortcutOverride
operator|<<
name|QEvent
operator|::
name|Shortcut
expr_stmt|;
block|}
if|if
condition|(
name|eventCategories
operator|&
name|FocusEvents
condition|)
block|{
name|m_eventTypes
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
operator|<<
name|QEvent
operator|::
name|FocusAboutToChange
endif|#
directive|endif
operator|<<
name|QEvent
operator|::
name|FocusIn
operator|<<
name|QEvent
operator|::
name|FocusOut
expr_stmt|;
block|}
if|if
condition|(
name|eventCategories
operator|&
name|GeometryEvents
condition|)
name|m_eventTypes
operator|<<
name|QEvent
operator|::
name|Move
operator|<<
name|QEvent
operator|::
name|Resize
expr_stmt|;
if|if
condition|(
name|eventCategories
operator|&
name|PaintEvents
condition|)
block|{
name|m_eventTypes
operator|<<
name|QEvent
operator|::
name|UpdateRequest
operator|<<
name|QEvent
operator|::
name|Paint
operator|<<
name|QEvent
operator|::
name|Show
operator|<<
name|QEvent
operator|::
name|Hide
expr_stmt|;
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
name|m_eventTypes
operator|<<
name|QEvent
operator|::
name|Expose
expr_stmt|;
endif|#
directive|endif
block|}
if|if
condition|(
name|eventCategories
operator|&
name|StateChangeEvents
condition|)
block|{
name|m_eventTypes
operator|<<
name|QEvent
operator|::
name|WindowStateChange
operator|<<
name|QEvent
operator|::
name|WindowBlocked
operator|<<
name|QEvent
operator|::
name|WindowUnblocked
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
operator|<<
name|QEvent
operator|::
name|ApplicationStateChange
endif|#
directive|endif
operator|<<
name|QEvent
operator|::
name|ApplicationActivate
operator|<<
name|QEvent
operator|::
name|ApplicationDeactivate
expr_stmt|;
block|}
if|if
condition|(
name|eventCategories
operator|&
name|TimerEvents
condition|)
name|m_eventTypes
operator|<<
name|QEvent
operator|::
name|Timer
operator|<<
name|QEvent
operator|::
name|ZeroTimerEvent
expr_stmt|;
if|if
condition|(
name|eventCategories
operator|&
name|ObjectEvents
condition|)
block|{
name|m_eventTypes
operator|<<
name|QEvent
operator|::
name|ChildAdded
operator|<<
name|QEvent
operator|::
name|ChildPolished
operator|<<
name|QEvent
operator|::
name|ChildRemoved
operator|<<
name|QEvent
operator|::
name|Create
operator|<<
name|QEvent
operator|::
name|Destroy
expr_stmt|;
block|}
if|if
condition|(
name|eventCategories
operator|&
name|InputMethodEvents
condition|)
block|{
name|m_eventTypes
operator|<<
name|QEvent
operator|::
name|InputMethod
expr_stmt|;
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
name|m_eventTypes
operator|<<
name|QEvent
operator|::
name|InputMethodQuery
expr_stmt|;
endif|#
directive|endif
block|}
block|}
DECL|function|matchesType
specifier|static
specifier|inline
name|bool
name|matchesType
parameter_list|(
specifier|const
name|QObject
modifier|*
name|o
parameter_list|,
name|EventFilter
operator|::
name|ObjectTypes
name|types
parameter_list|)
block|{
if|if
condition|(
name|o
operator|->
name|isWidgetType
argument_list|()
condition|)
return|return
name|types
operator|&
name|EventFilter
operator|::
name|QWidgetType
return|;
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
if|if
condition|(
name|o
operator|->
name|isWindowType
argument_list|()
condition|)
return|return
name|types
operator|&
name|EventFilter
operator|::
name|QWindowType
return|;
endif|#
directive|endif
return|return
name|types
operator|&
name|EventFilter
operator|::
name|OtherType
return|;
block|}
DECL|function|formatObject
specifier|static
name|void
name|formatObject
parameter_list|(
specifier|const
name|QObject
modifier|*
name|o
parameter_list|,
name|QDebug
name|debug
parameter_list|)
block|{
if|if
condition|(
name|o
condition|)
block|{
name|debug
operator|<<
name|o
operator|->
name|metaObject
argument_list|()
operator|->
name|className
argument_list|()
expr_stmt|;
specifier|const
name|QString
name|on
init|=
name|o
operator|->
name|objectName
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|on
operator|.
name|isEmpty
argument_list|()
condition|)
name|debug
operator|<<
literal|'/'
operator|<<
name|on
expr_stmt|;
block|}
else|else
block|{
name|debug
operator|<<
literal|"null"
expr_stmt|;
block|}
block|}
DECL|function|formatApplicationState
specifier|static
name|void
name|formatApplicationState
parameter_list|(
name|QDebug
name|debug
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|HAVE_APPLICATION
argument_list|)
if|if
condition|(
specifier|const
name|QWidget
modifier|*
name|mw
init|=
name|QApplication
operator|::
name|activeModalWidget
argument_list|()
condition|)
block|{
name|debug
operator|<<
literal|"\n  QApplication::activeModalWidget = "
expr_stmt|;
name|formatObject
argument_list|(
name|mw
argument_list|,
name|debug
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
specifier|const
name|QWidget
modifier|*
name|pw
init|=
name|QApplication
operator|::
name|activePopupWidget
argument_list|()
condition|)
block|{
name|debug
operator|<<
literal|"\n  QApplication::activePopupWidget = "
expr_stmt|;
name|formatObject
argument_list|(
name|pw
argument_list|,
name|debug
argument_list|)
expr_stmt|;
block|}
name|debug
operator|<<
literal|"\n  QApplication::activeWindow      = "
expr_stmt|;
name|formatObject
argument_list|(
name|QApplication
operator|::
name|activeWindow
argument_list|()
argument_list|,
name|debug
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// HAVE_APPLICATION
if|#
directive|if
name|defined
argument_list|(
name|HAVE_GUI_APPLICATION
argument_list|)
if|if
condition|(
specifier|const
name|QWindow
modifier|*
name|mw
init|=
name|QGuiApplication
operator|::
name|modalWindow
argument_list|()
condition|)
block|{
name|debug
operator|<<
literal|"\n  QGuiApplication::modalWindow    = "
expr_stmt|;
name|formatObject
argument_list|(
name|mw
argument_list|,
name|debug
argument_list|)
expr_stmt|;
block|}
name|debug
operator|<<
literal|"\n  QGuiApplication::focusWindow    = "
expr_stmt|;
name|formatObject
argument_list|(
name|QGuiApplication
operator|::
name|focusWindow
argument_list|()
argument_list|,
name|debug
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// HAVE_GUI_APPLICATION
block|}
DECL|function|eventFilter
name|bool
name|EventFilter
operator|::
name|eventFilter
parameter_list|(
name|QObject
modifier|*
name|o
parameter_list|,
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
specifier|static
name|int
name|n
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|matchesType
argument_list|(
name|o
argument_list|,
name|m_objectTypes
argument_list|)
operator|&&
name|m_eventTypes
operator|.
name|contains
argument_list|(
name|e
operator|->
name|type
argument_list|()
argument_list|)
condition|)
block|{
name|QDebug
name|debug
init|=
name|qDebug
argument_list|()
operator|.
name|nospace
argument_list|()
decl_stmt|;
name|debug
operator|<<
literal|'#'
operator|<<
name|n
operator|++
operator|<<
literal|' '
expr_stmt|;
name|formatObject
argument_list|(
name|o
argument_list|,
name|debug
argument_list|)
expr_stmt|;
name|debug
operator|<<
literal|' '
operator|<<
name|e
expr_stmt|;
switch|switch
condition|(
name|e
operator|->
name|type
argument_list|()
condition|)
block|{
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
case|case
name|QEvent
operator|::
name|FocusAboutToChange
case|:
endif|#
directive|endif
case|case
name|QEvent
operator|::
name|FocusIn
case|:
name|formatApplicationState
argument_list|(
name|debug
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
return|return
literal|false
return|;
block|}
block|}
end_namespace
begin_comment
comment|// namespace QtDiag
end_comment
end_unit
