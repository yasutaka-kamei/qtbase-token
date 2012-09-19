begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDATETIMEEDIT_H
end_ifndef
begin_define
DECL|macro|QDATETIMEEDIT_H
define|#
directive|define
name|QDATETIMEEDIT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qdatetime.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qabstractspinbox.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_DATETIMEEDIT
DECL|variable|QDateTimeEditPrivate
name|class
name|QDateTimeEditPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStyleOptionSpinBox
name|class
name|QStyleOptionSpinBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QCalendarWidget
name|class
name|QCalendarWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QDateTimeEdit
range|:
name|public
name|QAbstractSpinBox
block|{
name|Q_OBJECT
name|Q_ENUMS
argument_list|(
argument|Section
argument_list|)
name|Q_FLAGS
argument_list|(
argument|Sections
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QDateTime dateTime READ dateTime WRITE setDateTime NOTIFY dateTimeChanged USER true
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QDate date READ date WRITE setDate NOTIFY dateChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QTime time READ time WRITE setTime NOTIFY timeChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QDateTime maximumDateTime READ maximumDateTime WRITE setMaximumDateTime RESET clearMaximumDateTime
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QDateTime minimumDateTime READ minimumDateTime WRITE setMinimumDateTime RESET clearMinimumDateTime
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QDate maximumDate READ maximumDate WRITE setMaximumDate RESET clearMaximumDate
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QDate minimumDate READ minimumDate WRITE setMinimumDate RESET clearMinimumDate
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QTime maximumTime READ maximumTime WRITE setMaximumTime RESET clearMaximumTime
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QTime minimumTime READ minimumTime WRITE setMinimumTime RESET clearMinimumTime
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Section currentSection READ currentSection WRITE setCurrentSection
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Sections displayedSections READ displayedSections
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString displayFormat READ displayFormat WRITE setDisplayFormat
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool calendarPopup READ calendarPopup WRITE setCalendarPopup
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int currentSectionIndex READ currentSectionIndex WRITE setCurrentSectionIndex
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int sectionCount READ sectionCount
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::TimeSpec timeSpec READ timeSpec WRITE setTimeSpec
argument_list|)
name|public
operator|:
expr|enum
name|Section
block|{
name|NoSection
operator|=
literal|0x0000
block|,
name|AmPmSection
operator|=
literal|0x0001
block|,
name|MSecSection
operator|=
literal|0x0002
block|,
name|SecondSection
operator|=
literal|0x0004
block|,
name|MinuteSection
operator|=
literal|0x0008
block|,
name|HourSection
operator|=
literal|0x0010
block|,
name|DaySection
operator|=
literal|0x0100
block|,
name|MonthSection
operator|=
literal|0x0200
block|,
name|YearSection
operator|=
literal|0x0400
block|,
name|TimeSections_Mask
operator|=
name|AmPmSection
operator||
name|MSecSection
operator||
name|SecondSection
operator||
name|MinuteSection
operator||
name|HourSection
block|,
name|DateSections_Mask
operator|=
name|DaySection
operator||
name|MonthSection
operator||
name|YearSection
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|Sections
argument_list|,
argument|Section
argument_list|)
name|explicit
name|QDateTimeEdit
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QDateTimeEdit
argument_list|(
specifier|const
name|QDateTime
operator|&
name|dt
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QDateTimeEdit
argument_list|(
specifier|const
name|QDate
operator|&
name|d
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|explicit
name|QDateTimeEdit
argument_list|(
specifier|const
name|QTime
operator|&
name|t
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QDateTime
name|dateTime
argument_list|()
specifier|const
block|;
name|QDate
name|date
argument_list|()
specifier|const
block|;
name|QTime
name|time
argument_list|()
specifier|const
block|;
name|QDateTime
name|minimumDateTime
argument_list|()
specifier|const
block|;
name|void
name|clearMinimumDateTime
argument_list|()
block|;
name|void
name|setMinimumDateTime
argument_list|(
specifier|const
name|QDateTime
operator|&
name|dt
argument_list|)
block|;
name|QDateTime
name|maximumDateTime
argument_list|()
specifier|const
block|;
name|void
name|clearMaximumDateTime
argument_list|()
block|;
name|void
name|setMaximumDateTime
argument_list|(
specifier|const
name|QDateTime
operator|&
name|dt
argument_list|)
block|;
name|void
name|setDateTimeRange
argument_list|(
specifier|const
name|QDateTime
operator|&
name|min
argument_list|,
specifier|const
name|QDateTime
operator|&
name|max
argument_list|)
block|;
name|QDate
name|minimumDate
argument_list|()
specifier|const
block|;
name|void
name|setMinimumDate
argument_list|(
specifier|const
name|QDate
operator|&
name|min
argument_list|)
block|;
name|void
name|clearMinimumDate
argument_list|()
block|;
name|QDate
name|maximumDate
argument_list|()
specifier|const
block|;
name|void
name|setMaximumDate
argument_list|(
specifier|const
name|QDate
operator|&
name|max
argument_list|)
block|;
name|void
name|clearMaximumDate
argument_list|()
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
name|QTime
name|minimumTime
argument_list|()
specifier|const
block|;
name|void
name|setMinimumTime
argument_list|(
specifier|const
name|QTime
operator|&
name|min
argument_list|)
block|;
name|void
name|clearMinimumTime
argument_list|()
block|;
name|QTime
name|maximumTime
argument_list|()
specifier|const
block|;
name|void
name|setMaximumTime
argument_list|(
specifier|const
name|QTime
operator|&
name|max
argument_list|)
block|;
name|void
name|clearMaximumTime
argument_list|()
block|;
name|void
name|setTimeRange
argument_list|(
specifier|const
name|QTime
operator|&
name|min
argument_list|,
specifier|const
name|QTime
operator|&
name|max
argument_list|)
block|;
name|Sections
name|displayedSections
argument_list|()
specifier|const
block|;
name|Section
name|currentSection
argument_list|()
specifier|const
block|;
name|Section
name|sectionAt
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|void
name|setCurrentSection
argument_list|(
argument|Section section
argument_list|)
block|;
name|int
name|currentSectionIndex
argument_list|()
specifier|const
block|;
name|void
name|setCurrentSectionIndex
argument_list|(
argument|int index
argument_list|)
block|;
name|QCalendarWidget
operator|*
name|calendarWidget
argument_list|()
specifier|const
block|;
name|void
name|setCalendarWidget
argument_list|(
name|QCalendarWidget
operator|*
name|calendarWidget
argument_list|)
block|;
name|int
name|sectionCount
argument_list|()
specifier|const
block|;
name|void
name|setSelectedSection
argument_list|(
argument|Section section
argument_list|)
block|;
name|QString
name|sectionText
argument_list|(
argument|Section section
argument_list|)
specifier|const
block|;
name|QString
name|displayFormat
argument_list|()
specifier|const
block|;
name|void
name|setDisplayFormat
argument_list|(
specifier|const
name|QString
operator|&
name|format
argument_list|)
block|;
name|bool
name|calendarPopup
argument_list|()
specifier|const
block|;
name|void
name|setCalendarPopup
argument_list|(
argument|bool enable
argument_list|)
block|;
name|Qt
operator|::
name|TimeSpec
name|timeSpec
argument_list|()
specifier|const
block|;
name|void
name|setTimeSpec
argument_list|(
argument|Qt::TimeSpec spec
argument_list|)
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|clear
argument_list|()
block|;
name|virtual
name|void
name|stepBy
argument_list|(
argument|int steps
argument_list|)
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|dateTimeChanged
argument_list|(
specifier|const
name|QDateTime
operator|&
name|dateTime
argument_list|)
block|;
name|void
name|timeChanged
argument_list|(
specifier|const
name|QTime
operator|&
name|time
argument_list|)
block|;
name|void
name|dateChanged
argument_list|(
specifier|const
name|QDate
operator|&
name|date
argument_list|)
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setDateTime
argument_list|(
specifier|const
name|QDateTime
operator|&
name|dateTime
argument_list|)
block|;
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
name|setTime
argument_list|(
specifier|const
name|QTime
operator|&
name|time
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|void
name|keyPressEvent
argument_list|(
name|QKeyEvent
operator|*
name|event
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
name|virtual
name|void
name|wheelEvent
argument_list|(
name|QWheelEvent
operator|*
name|event
argument_list|)
block|;
endif|#
directive|endif
name|virtual
name|void
name|focusInEvent
argument_list|(
name|QFocusEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|bool
name|focusNextPrevChild
argument_list|(
argument|bool next
argument_list|)
block|;
name|virtual
name|QValidator
operator|::
name|State
name|validate
argument_list|(
argument|QString&input
argument_list|,
argument|int&pos
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|fixup
argument_list|(
argument|QString&input
argument_list|)
specifier|const
block|;
name|virtual
name|QDateTime
name|dateTimeFromText
argument_list|(
argument|const QString&text
argument_list|)
specifier|const
block|;
name|virtual
name|QString
name|textFromDateTime
argument_list|(
argument|const QDateTime&dt
argument_list|)
specifier|const
block|;
name|virtual
name|StepEnabled
name|stepEnabled
argument_list|()
specifier|const
block|;
name|virtual
name|void
name|mousePressEvent
argument_list|(
name|QMouseEvent
operator|*
name|event
argument_list|)
block|;
name|virtual
name|void
name|paintEvent
argument_list|(
name|QPaintEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|initStyleOption
argument_list|(
argument|QStyleOptionSpinBox *option
argument_list|)
specifier|const
block|;
name|QDateTimeEdit
argument_list|(
argument|const QVariant&val
argument_list|,
argument|QVariant::Type parserType
argument_list|,
argument|QWidget *parent =
literal|0
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QDateTimeEdit
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QDateTimeEdit
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_resetButton()
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QTimeEdit
range|:
name|public
name|QDateTimeEdit
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QTime time READ time WRITE setTime NOTIFY userTimeChanged USER true
argument_list|)
name|public
operator|:
name|QTimeEdit
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QTimeEdit
argument_list|(
specifier|const
name|QTime
operator|&
name|time
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|userTimeChanged
argument_list|(
specifier|const
name|QTime
operator|&
name|time
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QDateEdit
range|:
name|public
name|QDateTimeEdit
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|QDate date READ date WRITE setDate NOTIFY userDateChanged USER true
argument_list|)
name|public
operator|:
name|QDateEdit
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QDateEdit
argument_list|(
specifier|const
name|QDate
operator|&
name|date
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|userDateChanged
argument_list|(
specifier|const
name|QDate
operator|&
name|date
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QDateTimeEdit::Sections
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DATETIMEEDIT
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
comment|// QDATETIMEEDIT_H
end_comment
end_unit
