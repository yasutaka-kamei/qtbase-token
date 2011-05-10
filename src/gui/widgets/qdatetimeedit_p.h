begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDATETIMEEDIT_P_H
end_ifndef
begin_define
DECL|macro|QDATETIMEEDIT_P_H
define|#
directive|define
name|QDATETIMEEDIT_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
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
file|"QtGui/qcombobox.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qcalendarwidget.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qspinbox.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qtoolbutton.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qmenu.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qlabel.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qdatetimeedit.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/private/qabstractspinbox_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/private/qdatetime_p.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATETIMEEDIT
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QCalendarPopup
name|class
name|QCalendarPopup
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractSpinBoxPrivate
name|class
name|QDateTimeEditPrivate
range|:
name|public
name|QAbstractSpinBoxPrivate
decl_stmt|,
name|public
name|QDateTimeParser
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QDateTimeEdit
argument_list|)
name|public
label|:
name|QDateTimeEditPrivate
argument_list|()
expr_stmt|;
name|void
name|init
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|var
parameter_list|)
function_decl|;
name|void
name|readLocaleSettings
parameter_list|()
function_decl|;
name|void
name|emitSignals
parameter_list|(
name|EmitPolicy
name|ep
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|old
parameter_list|)
function_decl|;
name|QString
name|textFromValue
argument_list|(
specifier|const
name|QVariant
operator|&
name|f
argument_list|)
decl|const
decl_stmt|;
name|QVariant
name|valueFromText
argument_list|(
specifier|const
name|QString
operator|&
name|f
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|_q_editorCursorPositionChanged
parameter_list|(
name|int
name|oldpos
parameter_list|,
name|int
name|newpos
parameter_list|)
function_decl|;
name|virtual
name|void
name|interpret
parameter_list|(
name|EmitPolicy
name|ep
parameter_list|)
function_decl|;
name|virtual
name|void
name|clearCache
argument_list|()
specifier|const
expr_stmt|;
name|QDateTime
name|validateAndInterpret
argument_list|(
name|QString
operator|&
name|input
argument_list|,
name|int
operator|&
argument_list|,
name|QValidator
operator|::
name|State
operator|&
name|state
argument_list|,
name|bool
name|fixup
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|void
name|clearSection
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
name|virtual
name|QString
name|displayText
argument_list|()
specifier|const
block|{
return|return
name|edit
operator|->
name|text
argument_list|()
return|;
block|}
comment|// this is from QDateTimeParser
name|int
name|absoluteIndex
argument_list|(
name|QDateTimeEdit
operator|::
name|Section
name|s
argument_list|,
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|int
name|absoluteIndex
argument_list|(
specifier|const
name|SectionNode
operator|&
name|s
argument_list|)
decl|const
decl_stmt|;
name|void
name|updateEdit
parameter_list|()
function_decl|;
name|QDateTime
name|stepBy
argument_list|(
name|int
name|index
argument_list|,
name|int
name|steps
argument_list|,
name|bool
name|test
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|int
name|sectionAt
argument_list|(
name|int
name|pos
argument_list|)
decl|const
decl_stmt|;
name|int
name|closestSection
argument_list|(
name|int
name|index
argument_list|,
name|bool
name|forward
argument_list|)
decl|const
decl_stmt|;
name|int
name|nextPrevSection
argument_list|(
name|int
name|index
argument_list|,
name|bool
name|forward
argument_list|)
decl|const
decl_stmt|;
name|void
name|setSelected
parameter_list|(
name|int
name|index
parameter_list|,
name|bool
name|forward
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|updateCache
argument_list|(
specifier|const
name|QVariant
operator|&
name|val
argument_list|,
specifier|const
name|QString
operator|&
name|str
argument_list|)
decl|const
decl_stmt|;
name|void
name|updateTimeSpec
parameter_list|()
function_decl|;
name|virtual
name|QDateTime
name|getMinimum
argument_list|()
specifier|const
block|{
return|return
name|minimum
operator|.
name|toDateTime
argument_list|()
return|;
block|}
name|virtual
name|QDateTime
name|getMaximum
argument_list|()
specifier|const
block|{
return|return
name|maximum
operator|.
name|toDateTime
argument_list|()
return|;
block|}
name|virtual
name|QLocale
name|locale
argument_list|()
specifier|const
block|{
return|return
name|q_func
argument_list|()
operator|->
name|locale
argument_list|()
return|;
block|}
name|QString
name|valueToText
argument_list|(
specifier|const
name|QVariant
operator|&
name|var
argument_list|)
decl|const
block|{
return|return
name|textFromValue
argument_list|(
name|var
argument_list|)
return|;
block|}
name|QString
name|getAmPmText
argument_list|(
name|AmPm
name|ap
argument_list|,
name|Case
name|cs
argument_list|)
decl|const
decl_stmt|;
name|int
name|cursorPosition
argument_list|()
specifier|const
block|{
return|return
name|edit
operator|?
name|edit
operator|->
name|cursorPosition
argument_list|()
operator|:
operator|-
literal|1
return|;
block|}
name|virtual
name|QStyle
operator|::
name|SubControl
name|newHoverControl
argument_list|(
specifier|const
name|QPoint
operator|&
name|pos
argument_list|)
expr_stmt|;
name|virtual
name|void
name|updateEditFieldGeometry
parameter_list|()
function_decl|;
name|virtual
name|QVariant
name|getZeroVariant
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|void
name|setRange
parameter_list|(
specifier|const
name|QVariant
modifier|&
name|min
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|max
parameter_list|)
function_decl|;
name|void
name|_q_resetButton
parameter_list|()
function_decl|;
name|void
name|updateArrow
argument_list|(
name|QStyle
operator|::
name|StateFlag
name|state
argument_list|)
decl_stmt|;
name|bool
name|calendarPopupEnabled
argument_list|()
specifier|const
expr_stmt|;
name|void
name|syncCalendarWidget
parameter_list|()
function_decl|;
name|bool
name|isSeparatorKey
argument_list|(
specifier|const
name|QKeyEvent
operator|*
name|k
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|QDateTimeEdit
operator|::
name|Sections
name|convertSections
argument_list|(
argument|QDateTimeParser::Sections s
argument_list|)
expr_stmt|;
specifier|static
name|QDateTimeEdit
operator|::
name|Section
name|convertToPublic
argument_list|(
argument|QDateTimeParser::Section s
argument_list|)
expr_stmt|;
name|void
name|initCalendarPopup
parameter_list|(
name|QCalendarWidget
modifier|*
name|cw
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|positionCalendarPopup
parameter_list|()
function_decl|;
name|QDateTimeEdit
operator|::
name|Sections
name|sections
expr_stmt|;
name|mutable
name|bool
name|cacheGuard
decl_stmt|;
name|QString
name|defaultDateFormat
decl_stmt|,
name|defaultTimeFormat
decl_stmt|,
name|defaultDateTimeFormat
decl_stmt|,
name|unreversedFormat
decl_stmt|;
name|mutable
name|QVariant
name|conflictGuard
decl_stmt|;
name|bool
name|hasHadFocus
decl_stmt|,
name|formatExplicitlySet
decl_stmt|,
name|calendarPopup
decl_stmt|;
name|QStyle
operator|::
name|StateFlag
name|arrowState
expr_stmt|;
name|QCalendarPopup
modifier|*
name|monthCalendar
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|bool
name|focusOnButton
decl_stmt|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QCalendarPopup
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|QCalendarPopup
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|,
name|QCalendarWidget
operator|*
name|cw
operator|=
literal|0
argument_list|)
block|;
name|QDate
name|selectedDate
argument_list|()
block|{
return|return
name|verifyCalendarInstance
argument_list|()
operator|->
name|selectedDate
argument_list|()
return|;
block|}
name|void
name|setDate
argument_list|(
specifier|const
name|QDate
operator|&
name|date
argument_list|)
block|;
name|void
name|setDateRange
argument_list|(
specifier|const
name|QDate
operator|&
name|min
argument_list|,
specifier|const
name|QDate
operator|&
name|max
argument_list|)
block|;
name|void
name|setFirstDayOfWeek
argument_list|(
argument|Qt::DayOfWeek dow
argument_list|)
block|{
name|verifyCalendarInstance
argument_list|()
operator|->
name|setFirstDayOfWeek
argument_list|(
name|dow
argument_list|)
block|; }
name|QCalendarWidget
operator|*
name|calendarWidget
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|QCalendarPopup
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|verifyCalendarInstance
argument_list|()
return|;
block|}
name|void
name|setCalendarWidget
argument_list|(
name|QCalendarWidget
operator|*
name|cw
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|activated
argument_list|(
specifier|const
name|QDate
operator|&
name|date
argument_list|)
block|;
name|void
name|newDateSelected
argument_list|(
specifier|const
name|QDate
operator|&
name|newDate
argument_list|)
block|;
name|void
name|hidingCalendar
argument_list|(
specifier|const
name|QDate
operator|&
name|oldDate
argument_list|)
block|;
name|void
name|resetButton
argument_list|()
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|dateSelected
argument_list|(
specifier|const
name|QDate
operator|&
name|date
argument_list|)
block|;
name|void
name|dateSelectionChanged
argument_list|()
block|;
name|protected
operator|:
name|void
name|hideEvent
argument_list|(
name|QHideEvent
operator|*
argument_list|)
block|;
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
name|e
argument_list|)
block|;
name|void
name|mouseReleaseEvent
argument_list|(
name|QMouseEvent
operator|*
argument_list|)
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|private
operator|:
name|QCalendarWidget
operator|*
name|verifyCalendarInstance
argument_list|()
block|;
name|QWeakPointer
operator|<
name|QCalendarWidget
operator|>
name|calendar
block|;
name|QDate
name|oldDate
block|;
name|bool
name|dateChanged
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
begin_comment
comment|// QT_NO_DATETIMEEDIT
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDATETIMEEDIT_P_H
end_comment
end_unit
