begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"calendar.h"
end_include
begin_constructor
DECL|function|CalendarWidget
name|CalendarWidget
operator|::
name|CalendarWidget
parameter_list|()
block|{
name|createPreviewGroupBox
argument_list|()
expr_stmt|;
name|createGeneralOptionsGroupBox
argument_list|()
expr_stmt|;
name|createDatesGroupBox
argument_list|()
expr_stmt|;
name|createTextFormatsGroupBox
argument_list|()
expr_stmt|;
name|QGridLayout
modifier|*
name|layout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|previewGroupBox
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|generalOptionsGroupBox
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|datesGroupBox
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|textFormatsGroupBox
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|setSizeConstraint
argument_list|(
name|QLayout
operator|::
name|SetFixedSize
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|previewLayout
operator|->
name|setRowMinimumHeight
argument_list|(
literal|0
argument_list|,
name|calendar
operator|->
name|sizeHint
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|previewLayout
operator|->
name|setColumnMinimumWidth
argument_list|(
literal|0
argument_list|,
name|calendar
operator|->
name|sizeHint
argument_list|()
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Calendar Widget"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|localeChanged
name|void
name|CalendarWidget
operator|::
name|localeChanged
parameter_list|(
name|QLocale
name|locale
parameter_list|)
block|{
name|calendar
operator|->
name|setLocale
argument_list|(
name|locale
argument_list|)
expr_stmt|;
name|firstDayCombo
operator|->
name|setCurrentIndex
argument_list|(
name|locale
operator|.
name|firstDayOfWeek
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
name|updateWeekendDays
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|firstDayChanged
name|void
name|CalendarWidget
operator|::
name|firstDayChanged
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|calendar
operator|->
name|setFirstDayOfWeek
argument_list|(
name|Qt
operator|::
name|DayOfWeek
argument_list|(
name|firstDayCombo
operator|->
name|itemData
argument_list|(
name|index
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|selectionModeChanged
name|void
name|CalendarWidget
operator|::
name|selectionModeChanged
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|calendar
operator|->
name|setSelectionMode
argument_list|(
name|QCalendarWidget
operator|::
name|SelectionMode
argument_list|(
name|selectionModeCombo
operator|->
name|itemData
argument_list|(
name|index
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|horizontalHeaderChanged
name|void
name|CalendarWidget
operator|::
name|horizontalHeaderChanged
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|calendar
operator|->
name|setHorizontalHeaderFormat
argument_list|(
name|QCalendarWidget
operator|::
name|HorizontalHeaderFormat
argument_list|(
name|horizontalHeaderCombo
operator|->
name|itemData
argument_list|(
name|index
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|verticalHeaderChanged
name|void
name|CalendarWidget
operator|::
name|verticalHeaderChanged
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|calendar
operator|->
name|setVerticalHeaderFormat
argument_list|(
name|QCalendarWidget
operator|::
name|VerticalHeaderFormat
argument_list|(
name|verticalHeaderCombo
operator|->
name|itemData
argument_list|(
name|index
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|selectedDateChanged
name|void
name|CalendarWidget
operator|::
name|selectedDateChanged
parameter_list|()
block|{
name|currentDateEdit
operator|->
name|setDate
argument_list|(
name|calendar
operator|->
name|selectedDate
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|minimumDateChanged
name|void
name|CalendarWidget
operator|::
name|minimumDateChanged
parameter_list|(
specifier|const
name|QDate
modifier|&
name|date
parameter_list|)
block|{
name|calendar
operator|->
name|setMinimumDate
argument_list|(
name|date
argument_list|)
expr_stmt|;
name|maximumDateEdit
operator|->
name|setDate
argument_list|(
name|calendar
operator|->
name|maximumDate
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|maximumDateChanged
name|void
name|CalendarWidget
operator|::
name|maximumDateChanged
parameter_list|(
specifier|const
name|QDate
modifier|&
name|date
parameter_list|)
block|{
name|calendar
operator|->
name|setMaximumDate
argument_list|(
name|date
argument_list|)
expr_stmt|;
name|minimumDateEdit
operator|->
name|setDate
argument_list|(
name|calendar
operator|->
name|minimumDate
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isWeekendDay
name|bool
name|CalendarWidget
operator|::
name|isWeekendDay
parameter_list|(
name|Qt
operator|::
name|DayOfWeek
name|day
parameter_list|)
block|{
name|QList
argument_list|<
name|Qt
operator|::
name|DayOfWeek
argument_list|>
name|week
init|=
name|calendar
operator|->
name|locale
argument_list|()
operator|.
name|weekdays
argument_list|()
decl_stmt|;
return|return
operator|!
name|week
operator|.
name|contains
argument_list|(
name|day
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|updateWeekendDays
name|void
name|CalendarWidget
operator|::
name|updateWeekendDays
parameter_list|()
block|{
name|QTextCharFormat
name|weekFormat
decl_stmt|,
name|weekendFormat
decl_stmt|;
name|weekFormat
operator|.
name|setForeground
argument_list|(
name|qvariant_cast
argument_list|<
name|QColor
argument_list|>
argument_list|(
name|weekdayColorCombo
operator|->
name|itemData
argument_list|(
name|weekdayColorCombo
operator|->
name|currentIndex
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|weekendFormat
operator|.
name|setForeground
argument_list|(
name|qvariant_cast
argument_list|<
name|QColor
argument_list|>
argument_list|(
name|weekendColorCombo
operator|->
name|itemData
argument_list|(
name|weekendColorCombo
operator|->
name|currentIndex
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|calendar
operator|->
name|setWeekdayTextFormat
argument_list|(
name|Qt
operator|::
name|Monday
argument_list|,
name|isWeekendDay
argument_list|(
name|Qt
operator|::
name|Monday
argument_list|)
condition|?
name|weekendFormat
else|:
name|weekFormat
argument_list|)
expr_stmt|;
name|calendar
operator|->
name|setWeekdayTextFormat
argument_list|(
name|Qt
operator|::
name|Tuesday
argument_list|,
name|isWeekendDay
argument_list|(
name|Qt
operator|::
name|Tuesday
argument_list|)
condition|?
name|weekendFormat
else|:
name|weekFormat
argument_list|)
expr_stmt|;
name|calendar
operator|->
name|setWeekdayTextFormat
argument_list|(
name|Qt
operator|::
name|Wednesday
argument_list|,
name|isWeekendDay
argument_list|(
name|Qt
operator|::
name|Wednesday
argument_list|)
condition|?
name|weekendFormat
else|:
name|weekFormat
argument_list|)
expr_stmt|;
name|calendar
operator|->
name|setWeekdayTextFormat
argument_list|(
name|Qt
operator|::
name|Thursday
argument_list|,
name|isWeekendDay
argument_list|(
name|Qt
operator|::
name|Thursday
argument_list|)
condition|?
name|weekendFormat
else|:
name|weekFormat
argument_list|)
expr_stmt|;
name|calendar
operator|->
name|setWeekdayTextFormat
argument_list|(
name|Qt
operator|::
name|Friday
argument_list|,
name|isWeekendDay
argument_list|(
name|Qt
operator|::
name|Friday
argument_list|)
condition|?
name|weekendFormat
else|:
name|weekFormat
argument_list|)
expr_stmt|;
name|calendar
operator|->
name|setWeekdayTextFormat
argument_list|(
name|Qt
operator|::
name|Saturday
argument_list|,
name|isWeekendDay
argument_list|(
name|Qt
operator|::
name|Saturday
argument_list|)
condition|?
name|weekendFormat
else|:
name|weekFormat
argument_list|)
expr_stmt|;
name|calendar
operator|->
name|setWeekdayTextFormat
argument_list|(
name|Qt
operator|::
name|Sunday
argument_list|,
name|isWeekendDay
argument_list|(
name|Qt
operator|::
name|Sunday
argument_list|)
condition|?
name|weekendFormat
else|:
name|weekFormat
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|weekdayFormatChanged
name|void
name|CalendarWidget
operator|::
name|weekdayFormatChanged
parameter_list|()
block|{
name|updateWeekendDays
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|weekendFormatChanged
name|void
name|CalendarWidget
operator|::
name|weekendFormatChanged
parameter_list|()
block|{
name|updateWeekendDays
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|reformatHeaders
name|void
name|CalendarWidget
operator|::
name|reformatHeaders
parameter_list|()
block|{
name|QString
name|text
init|=
name|headerTextFormatCombo
operator|->
name|currentText
argument_list|()
decl_stmt|;
name|QTextCharFormat
name|format
decl_stmt|;
if|if
condition|(
name|text
operator|==
name|tr
argument_list|(
literal|"Bold"
argument_list|)
condition|)
block|{
name|format
operator|.
name|setFontWeight
argument_list|(
name|QFont
operator|::
name|Bold
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|text
operator|==
name|tr
argument_list|(
literal|"Italic"
argument_list|)
condition|)
block|{
name|format
operator|.
name|setFontItalic
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|text
operator|==
name|tr
argument_list|(
literal|"Green"
argument_list|)
condition|)
block|{
name|format
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|green
argument_list|)
expr_stmt|;
block|}
name|calendar
operator|->
name|setHeaderTextFormat
argument_list|(
name|format
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|reformatCalendarPage
name|void
name|CalendarWidget
operator|::
name|reformatCalendarPage
parameter_list|()
block|{
if|if
condition|(
name|firstFridayCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
block|{
name|QDate
name|firstFriday
argument_list|(
name|calendar
operator|->
name|yearShown
argument_list|()
argument_list|,
name|calendar
operator|->
name|monthShown
argument_list|()
argument_list|,
literal|1
argument_list|)
decl_stmt|;
while|while
condition|(
name|firstFriday
operator|.
name|dayOfWeek
argument_list|()
operator|!=
name|Qt
operator|::
name|Friday
condition|)
name|firstFriday
operator|=
name|firstFriday
operator|.
name|addDays
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QTextCharFormat
name|firstFridayFormat
decl_stmt|;
name|firstFridayFormat
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|calendar
operator|->
name|setDateTextFormat
argument_list|(
name|firstFriday
argument_list|,
name|firstFridayFormat
argument_list|)
expr_stmt|;
block|}
comment|//May First in Red takes precedence
if|if
condition|(
name|mayFirstCheckBox
operator|->
name|isChecked
argument_list|()
condition|)
block|{
specifier|const
name|QDate
name|mayFirst
argument_list|(
name|calendar
operator|->
name|yearShown
argument_list|()
argument_list|,
literal|5
argument_list|,
literal|1
argument_list|)
decl_stmt|;
name|QTextCharFormat
name|mayFirstFormat
decl_stmt|;
name|mayFirstFormat
operator|.
name|setForeground
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|calendar
operator|->
name|setDateTextFormat
argument_list|(
name|mayFirst
argument_list|,
name|mayFirstFormat
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|createPreviewGroupBox
name|void
name|CalendarWidget
operator|::
name|createPreviewGroupBox
parameter_list|()
block|{
name|previewGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Preview"
argument_list|)
argument_list|)
expr_stmt|;
name|calendar
operator|=
operator|new
name|QCalendarWidget
expr_stmt|;
name|calendar
operator|->
name|setMinimumDate
argument_list|(
name|QDate
argument_list|(
literal|1900
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|calendar
operator|->
name|setMaximumDate
argument_list|(
name|QDate
argument_list|(
literal|3000
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|calendar
operator|->
name|setGridVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|calendar
argument_list|,
name|SIGNAL
argument_list|(
name|currentPageChanged
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|reformatCalendarPage
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|previewLayout
operator|=
operator|new
name|QGridLayout
expr_stmt|;
name|previewLayout
operator|->
name|addWidget
argument_list|(
name|calendar
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|Qt
operator|::
name|AlignCenter
argument_list|)
expr_stmt|;
name|previewGroupBox
operator|->
name|setLayout
argument_list|(
name|previewLayout
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createGeneralOptionsGroupBox
name|void
name|CalendarWidget
operator|::
name|createGeneralOptionsGroupBox
parameter_list|()
block|{
name|generalOptionsGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"General Options"
argument_list|)
argument_list|)
expr_stmt|;
name|firstDayCombo
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|firstDayCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Monday"
argument_list|)
argument_list|,
name|Qt
operator|::
name|Monday
argument_list|)
expr_stmt|;
name|firstDayCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Tuesday"
argument_list|)
argument_list|,
name|Qt
operator|::
name|Tuesday
argument_list|)
expr_stmt|;
name|firstDayCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Wednesday"
argument_list|)
argument_list|,
name|Qt
operator|::
name|Wednesday
argument_list|)
expr_stmt|;
name|firstDayCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Thursday"
argument_list|)
argument_list|,
name|Qt
operator|::
name|Thursday
argument_list|)
expr_stmt|;
name|firstDayCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Friday"
argument_list|)
argument_list|,
name|Qt
operator|::
name|Friday
argument_list|)
expr_stmt|;
name|firstDayCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Saturday"
argument_list|)
argument_list|,
name|Qt
operator|::
name|Saturday
argument_list|)
expr_stmt|;
name|firstDayCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Sunday"
argument_list|)
argument_list|,
name|Qt
operator|::
name|Sunday
argument_list|)
expr_stmt|;
name|firstDayLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Wee&k starts on:"
argument_list|)
argument_list|)
expr_stmt|;
name|firstDayLabel
operator|->
name|setBuddy
argument_list|(
name|firstDayCombo
argument_list|)
expr_stmt|;
name|selectionModeCombo
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|selectionModeCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Single selection"
argument_list|)
argument_list|,
name|QCalendarWidget
operator|::
name|SingleSelection
argument_list|)
expr_stmt|;
name|selectionModeCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"None"
argument_list|)
argument_list|,
name|QCalendarWidget
operator|::
name|NoSelection
argument_list|)
expr_stmt|;
name|selectionModeLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Selection mode:"
argument_list|)
argument_list|)
expr_stmt|;
name|selectionModeLabel
operator|->
name|setBuddy
argument_list|(
name|selectionModeCombo
argument_list|)
expr_stmt|;
name|gridCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"&Grid"
argument_list|)
argument_list|)
expr_stmt|;
name|gridCheckBox
operator|->
name|setChecked
argument_list|(
name|calendar
operator|->
name|isGridVisible
argument_list|()
argument_list|)
expr_stmt|;
name|navigationCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"&Navigation bar"
argument_list|)
argument_list|)
expr_stmt|;
name|navigationCheckBox
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|horizontalHeaderCombo
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|horizontalHeaderCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Single letter day names"
argument_list|)
argument_list|,
name|QCalendarWidget
operator|::
name|SingleLetterDayNames
argument_list|)
expr_stmt|;
name|horizontalHeaderCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Short day names"
argument_list|)
argument_list|,
name|QCalendarWidget
operator|::
name|ShortDayNames
argument_list|)
expr_stmt|;
name|horizontalHeaderCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"None"
argument_list|)
argument_list|,
name|QCalendarWidget
operator|::
name|NoHorizontalHeader
argument_list|)
expr_stmt|;
name|horizontalHeaderCombo
operator|->
name|setCurrentIndex
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|horizontalHeaderLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Horizontal header:"
argument_list|)
argument_list|)
expr_stmt|;
name|horizontalHeaderLabel
operator|->
name|setBuddy
argument_list|(
name|horizontalHeaderCombo
argument_list|)
expr_stmt|;
name|verticalHeaderCombo
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|verticalHeaderCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"ISO week numbers"
argument_list|)
argument_list|,
name|QCalendarWidget
operator|::
name|ISOWeekNumbers
argument_list|)
expr_stmt|;
name|verticalHeaderCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"None"
argument_list|)
argument_list|,
name|QCalendarWidget
operator|::
name|NoVerticalHeader
argument_list|)
expr_stmt|;
name|verticalHeaderLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Vertical header:"
argument_list|)
argument_list|)
expr_stmt|;
name|verticalHeaderLabel
operator|->
name|setBuddy
argument_list|(
name|verticalHeaderCombo
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|firstDayCombo
argument_list|,
name|SIGNAL
argument_list|(
name|currentIndexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|firstDayChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|selectionModeCombo
argument_list|,
name|SIGNAL
argument_list|(
name|currentIndexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|selectionModeChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|gridCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|calendar
argument_list|,
name|SLOT
argument_list|(
name|setGridVisible
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|navigationCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|calendar
argument_list|,
name|SLOT
argument_list|(
name|setNavigationBarVisible
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|horizontalHeaderCombo
argument_list|,
name|SIGNAL
argument_list|(
name|currentIndexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|horizontalHeaderChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|verticalHeaderCombo
argument_list|,
name|SIGNAL
argument_list|(
name|currentIndexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|verticalHeaderChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|checkBoxLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|checkBoxLayout
operator|->
name|addWidget
argument_list|(
name|gridCheckBox
argument_list|)
expr_stmt|;
name|checkBoxLayout
operator|->
name|addStretch
argument_list|()
expr_stmt|;
name|checkBoxLayout
operator|->
name|addWidget
argument_list|(
name|navigationCheckBox
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|outerLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|outerLayout
operator|->
name|addWidget
argument_list|(
name|firstDayLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|outerLayout
operator|->
name|addWidget
argument_list|(
name|firstDayCombo
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|outerLayout
operator|->
name|addWidget
argument_list|(
name|selectionModeLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|outerLayout
operator|->
name|addWidget
argument_list|(
name|selectionModeCombo
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|outerLayout
operator|->
name|addLayout
argument_list|(
name|checkBoxLayout
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|outerLayout
operator|->
name|addWidget
argument_list|(
name|horizontalHeaderLabel
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|outerLayout
operator|->
name|addWidget
argument_list|(
name|horizontalHeaderCombo
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|outerLayout
operator|->
name|addWidget
argument_list|(
name|verticalHeaderLabel
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|outerLayout
operator|->
name|addWidget
argument_list|(
name|verticalHeaderCombo
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|generalOptionsGroupBox
operator|->
name|setLayout
argument_list|(
name|outerLayout
argument_list|)
expr_stmt|;
name|firstDayChanged
argument_list|(
name|firstDayCombo
operator|->
name|currentIndex
argument_list|()
argument_list|)
expr_stmt|;
name|selectionModeChanged
argument_list|(
name|selectionModeCombo
operator|->
name|currentIndex
argument_list|()
argument_list|)
expr_stmt|;
name|horizontalHeaderChanged
argument_list|(
name|horizontalHeaderCombo
operator|->
name|currentIndex
argument_list|()
argument_list|)
expr_stmt|;
name|verticalHeaderChanged
argument_list|(
name|verticalHeaderCombo
operator|->
name|currentIndex
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createDatesGroupBox
name|void
name|CalendarWidget
operator|::
name|createDatesGroupBox
parameter_list|()
block|{
name|datesGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Dates"
argument_list|)
argument_list|)
expr_stmt|;
name|minimumDateEdit
operator|=
operator|new
name|QDateEdit
expr_stmt|;
name|minimumDateEdit
operator|->
name|setDisplayFormat
argument_list|(
literal|"MMM d yyyy"
argument_list|)
expr_stmt|;
name|minimumDateEdit
operator|->
name|setDateRange
argument_list|(
name|calendar
operator|->
name|minimumDate
argument_list|()
argument_list|,
name|calendar
operator|->
name|maximumDate
argument_list|()
argument_list|)
expr_stmt|;
name|minimumDateEdit
operator|->
name|setDate
argument_list|(
name|calendar
operator|->
name|minimumDate
argument_list|()
argument_list|)
expr_stmt|;
name|minimumDateLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Minimum Date:"
argument_list|)
argument_list|)
expr_stmt|;
name|minimumDateLabel
operator|->
name|setBuddy
argument_list|(
name|minimumDateEdit
argument_list|)
expr_stmt|;
name|currentDateEdit
operator|=
operator|new
name|QDateEdit
expr_stmt|;
name|currentDateEdit
operator|->
name|setDisplayFormat
argument_list|(
literal|"MMM d yyyy"
argument_list|)
expr_stmt|;
name|currentDateEdit
operator|->
name|setDate
argument_list|(
name|calendar
operator|->
name|selectedDate
argument_list|()
argument_list|)
expr_stmt|;
name|currentDateEdit
operator|->
name|setDateRange
argument_list|(
name|calendar
operator|->
name|minimumDate
argument_list|()
argument_list|,
name|calendar
operator|->
name|maximumDate
argument_list|()
argument_list|)
expr_stmt|;
name|currentDateLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Current Date:"
argument_list|)
argument_list|)
expr_stmt|;
name|currentDateLabel
operator|->
name|setBuddy
argument_list|(
name|currentDateEdit
argument_list|)
expr_stmt|;
name|maximumDateEdit
operator|=
operator|new
name|QDateEdit
expr_stmt|;
name|maximumDateEdit
operator|->
name|setDisplayFormat
argument_list|(
literal|"MMM d yyyy"
argument_list|)
expr_stmt|;
name|maximumDateEdit
operator|->
name|setDateRange
argument_list|(
name|calendar
operator|->
name|minimumDate
argument_list|()
argument_list|,
name|calendar
operator|->
name|maximumDate
argument_list|()
argument_list|)
expr_stmt|;
name|maximumDateEdit
operator|->
name|setDate
argument_list|(
name|calendar
operator|->
name|maximumDate
argument_list|()
argument_list|)
expr_stmt|;
name|maximumDateLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Ma&ximum Date:"
argument_list|)
argument_list|)
expr_stmt|;
name|maximumDateLabel
operator|->
name|setBuddy
argument_list|(
name|maximumDateEdit
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|currentDateEdit
argument_list|,
name|SIGNAL
argument_list|(
name|dateChanged
argument_list|(
name|QDate
argument_list|)
argument_list|)
argument_list|,
name|calendar
argument_list|,
name|SLOT
argument_list|(
name|setSelectedDate
argument_list|(
name|QDate
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|calendar
argument_list|,
name|SIGNAL
argument_list|(
name|selectionChanged
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|selectedDateChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|minimumDateEdit
argument_list|,
name|SIGNAL
argument_list|(
name|dateChanged
argument_list|(
name|QDate
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|minimumDateChanged
argument_list|(
name|QDate
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|maximumDateEdit
argument_list|,
name|SIGNAL
argument_list|(
name|dateChanged
argument_list|(
name|QDate
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|maximumDateChanged
argument_list|(
name|QDate
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|dateBoxLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|dateBoxLayout
operator|->
name|addWidget
argument_list|(
name|currentDateLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|dateBoxLayout
operator|->
name|addWidget
argument_list|(
name|currentDateEdit
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|dateBoxLayout
operator|->
name|addWidget
argument_list|(
name|minimumDateLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|dateBoxLayout
operator|->
name|addWidget
argument_list|(
name|minimumDateEdit
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|dateBoxLayout
operator|->
name|addWidget
argument_list|(
name|maximumDateLabel
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|dateBoxLayout
operator|->
name|addWidget
argument_list|(
name|maximumDateEdit
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|dateBoxLayout
operator|->
name|setRowStretch
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|datesGroupBox
operator|->
name|setLayout
argument_list|(
name|dateBoxLayout
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createTextFormatsGroupBox
name|void
name|CalendarWidget
operator|::
name|createTextFormatsGroupBox
parameter_list|()
block|{
name|textFormatsGroupBox
operator|=
operator|new
name|QGroupBox
argument_list|(
name|tr
argument_list|(
literal|"Text Formats"
argument_list|)
argument_list|)
expr_stmt|;
name|weekdayColorCombo
operator|=
name|createColorComboBox
argument_list|()
expr_stmt|;
name|weekdayColorCombo
operator|->
name|setCurrentIndex
argument_list|(
name|weekdayColorCombo
operator|->
name|findText
argument_list|(
name|tr
argument_list|(
literal|"Black"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|weekdayColorLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Weekday color:"
argument_list|)
argument_list|)
expr_stmt|;
name|weekdayColorLabel
operator|->
name|setBuddy
argument_list|(
name|weekdayColorCombo
argument_list|)
expr_stmt|;
name|weekendColorCombo
operator|=
name|createColorComboBox
argument_list|()
expr_stmt|;
name|weekendColorCombo
operator|->
name|setCurrentIndex
argument_list|(
name|weekendColorCombo
operator|->
name|findText
argument_list|(
name|tr
argument_list|(
literal|"Red"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|weekendColorLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Week&end color:"
argument_list|)
argument_list|)
expr_stmt|;
name|weekendColorLabel
operator|->
name|setBuddy
argument_list|(
name|weekendColorCombo
argument_list|)
expr_stmt|;
name|headerTextFormatCombo
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|headerTextFormatCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Bold"
argument_list|)
argument_list|)
expr_stmt|;
name|headerTextFormatCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Italic"
argument_list|)
argument_list|)
expr_stmt|;
name|headerTextFormatCombo
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Plain"
argument_list|)
argument_list|)
expr_stmt|;
name|headerTextFormatLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Header text:"
argument_list|)
argument_list|)
expr_stmt|;
name|headerTextFormatLabel
operator|->
name|setBuddy
argument_list|(
name|headerTextFormatCombo
argument_list|)
expr_stmt|;
name|firstFridayCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"&First Friday in blue"
argument_list|)
argument_list|)
expr_stmt|;
name|mayFirstCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"May&1 in red"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|weekdayColorCombo
argument_list|,
name|SIGNAL
argument_list|(
name|currentIndexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|weekdayFormatChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|weekendColorCombo
argument_list|,
name|SIGNAL
argument_list|(
name|currentIndexChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|weekendFormatChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|headerTextFormatCombo
argument_list|,
name|SIGNAL
argument_list|(
name|currentIndexChanged
argument_list|(
name|QString
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|reformatHeaders
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|firstFridayCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|reformatCalendarPage
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|mayFirstCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|reformatCalendarPage
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QHBoxLayout
modifier|*
name|checkBoxLayout
init|=
operator|new
name|QHBoxLayout
decl_stmt|;
name|checkBoxLayout
operator|->
name|addWidget
argument_list|(
name|firstFridayCheckBox
argument_list|)
expr_stmt|;
name|checkBoxLayout
operator|->
name|addStretch
argument_list|()
expr_stmt|;
name|checkBoxLayout
operator|->
name|addWidget
argument_list|(
name|mayFirstCheckBox
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|outerLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|outerLayout
operator|->
name|addWidget
argument_list|(
name|weekdayColorLabel
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|outerLayout
operator|->
name|addWidget
argument_list|(
name|weekdayColorCombo
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|outerLayout
operator|->
name|addWidget
argument_list|(
name|weekendColorLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|outerLayout
operator|->
name|addWidget
argument_list|(
name|weekendColorCombo
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|outerLayout
operator|->
name|addWidget
argument_list|(
name|headerTextFormatLabel
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|outerLayout
operator|->
name|addWidget
argument_list|(
name|headerTextFormatCombo
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|outerLayout
operator|->
name|addLayout
argument_list|(
name|checkBoxLayout
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|textFormatsGroupBox
operator|->
name|setLayout
argument_list|(
name|outerLayout
argument_list|)
expr_stmt|;
name|weekdayFormatChanged
argument_list|()
expr_stmt|;
name|weekendFormatChanged
argument_list|()
expr_stmt|;
name|reformatHeaders
argument_list|()
expr_stmt|;
name|reformatCalendarPage
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createColorComboBox
name|QComboBox
modifier|*
name|CalendarWidget
operator|::
name|createColorComboBox
parameter_list|()
block|{
name|QComboBox
modifier|*
name|comboBox
init|=
operator|new
name|QComboBox
decl_stmt|;
name|comboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Red"
argument_list|)
argument_list|,
name|Qt
operator|::
name|red
argument_list|)
expr_stmt|;
name|comboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Blue"
argument_list|)
argument_list|,
name|Qt
operator|::
name|blue
argument_list|)
expr_stmt|;
name|comboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Black"
argument_list|)
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|comboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Magenta"
argument_list|)
argument_list|,
name|Qt
operator|::
name|magenta
argument_list|)
expr_stmt|;
return|return
name|comboBox
return|;
block|}
end_function
end_unit
